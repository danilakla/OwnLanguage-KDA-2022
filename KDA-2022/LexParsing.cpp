#include "LexParsing.h"
#include "FST.h"
#include "Graphs.h"
#include "Split.h"

#define max_word		1000
#define size_word		20
#define DIV				'|'
#define SPACE			' '
#define FST_PLUS		'+'
#define FST_MINUS		'-'
#define FST_STAR		'*'
#define FST_DIRSLASH	'/'
#define FST_MORE		'>'
#define FST_LESS		'<'
#define FST_EQMORE		'^'
#define FST_EQLESS		'_'
#define FST_EQUALS		'~'
#define FST_NEQUALS		'!'
#define EQUAL			'='

using namespace std;

namespace Lex {
	LEX LexParsing(Log::LOG log, In::IN in)
	{
		LEX lex;
		LT::LexTable lextable = LT::Create(LT_MAXSIZE);
		IT::IdTable idtable = IT::Create(IT_MAXSIZE);
		cleanup(in.text, in.size, log);

		char** word = new char* [max_word];
		for (int i = 0; i < max_word; i++)
			word[i] = new char[size_word] {NULL};

		do
		{
			word = splitText(in.text, in.size);
		} while (word == NULL);

		int indexLex = 0;
		int literalCounter = 1;
		int line = 1;
		int position = 0;
		bool findMain = false;
		int mainCounter = 0;
		bool findDeclaration = false;
		bool findType = false;
		bool findProc = false;
		int is_cycle = 0;
		bool findArray = 0;
		int countSize = 0;
		bool findPropery=0;
		bool printCheck = 0;

		std::stack<std::string> functions;
		char* bufprefix = new char[10] { "" };
		char* L = new char[2] { "L" };
		char* bufL = new char[IT_STR_MAXSIZE];
		char* nameLiteral = new char[10] { "" };
		char* charclit = new char[10] { "" };

		bool findFunc = false;
		bool findParm = false;
		IT::Entry entryIT;

		for (int i = 0; word[i] != NULL; i++, indexLex++)
		{
			if (strlen(word[i]) > 72) {
				throw ERROR_THROW_IN(211, line, position);

			}
			bool findSameID = false;
			position += strlen(word[i]);
			if (FST::execute(FST::FST(word[i], FST_VAR)))
			{
				LT::Entry entryLT = WriteEntry(entryLT, LEX_VAR, LT_TI_NULLIDX, line);
				LT::Add(lextable, entryLT);
				findDeclaration = true;
				findPropery = true;
				countSize++;
			}

			else if (FST::execute(FST::FST(word[i], FST_UINT)))
			{
				LT::Entry entryLT;

				if (entryIT.size != 0) {
					entryLT = WriteEntry(entryLT, LEX_UINTARRAY, LT_TI_NULLIDX, line);
					entryIT.iddatatype = IT::UINTARRAY;

				}
				else {

					entryLT = WriteEntry(entryLT, LEX_UINT, LT_TI_NULLIDX, line);
					entryIT.iddatatype = IT::UINT;
					countSize++;

				}
				LT::Add(lextable, entryLT);
				findType = true;
			}
			else if (FST::execute(FST::FST(word[i], FST_STR)))
			{
				LT::Entry entryLT = WriteEntry(entryLT, LEX_STR, LT_TI_NULLIDX, line);
				LT::Add(lextable, entryLT);
				findType = true;
				entryIT.iddatatype = IT::STR;
				strcpy(entryIT.value.vstr.str, "");
			}
			else if (FST::execute(FST::FST(word[i], FST_FUNC)))
			{
				
				LT::Entry entryLT = WriteEntry(entryLT, LEX_FUNCTION, LT_TI_NULLIDX, line);
				LT::Add(lextable, entryLT);
				
				findFunc = true;
			}
			else if (FST::execute(FST::FST(word[i], FST_RET)))
			{
				LT::Entry entryLT = WriteEntry(entryLT, LEX_RET, LT_TI_NULLIDX, line);
				LT::Add(lextable, entryLT);
			}
			else if (FST::execute(FST::FST(word[i], FST_PRINT)))
			{
				printCheck = true;
				LT::Entry entryLT = WriteEntry(entryLT, LEX_PRINT, LT_TI_NULLIDX, line);
				LT::Add(lextable, entryLT);
			}
			else if (FST::execute(FST::FST(word[i], FST_MAIN)))
			{
				strcpy(entryIT.id, word[i]);
				entryIT.idxfirstLE = indexLex;
				entryIT.idtype = IT::F;
				entryIT.iddatatype = IT::UINT;
				IT::Add(idtable, entryIT);
				entryIT = {};

				LT::Entry entryLT = WriteEntry(entryLT, LEX_MAIN, IT::IsId(idtable, word[i]), line);
				LT::Add(lextable, entryLT);
				functions.push(word[i]);
				findMain = true;
				mainCounter++;
			}
			else if ((FST::execute(FST::FST(word[i], FST_DATE)) || FST::execute(FST::FST(word[i], FST_TIME)))) {
				if (int idx = IT::IsId(idtable, word[i]) == IT_NULLIDX) {
					entryIT.idtype = IT::F;
					entryIT.iddatatype = IT::STR;
					entryIT.idxfirstLE = indexLex;
					strcpy(entryIT.id, word[i]);
					IT::Add(idtable, entryIT);
					entryIT = {};
				}

				LT::Entry entryLT = WriteEntry(entryLT, LEX_ID, IT::IsId(idtable, word[i]), line);
				LT::Add(lextable, entryLT);
			}
			else if (FST::execute(FST::FST(word[i], FST_IF)))
			{
				LT::Entry entryLT = WriteEntry(entryLT, LEX_IF, LT_TI_NULLIDX, line);
				LT::Add(lextable, entryLT);
				is_cycle++;
			}
			else if (FST::execute(FST::FST(word[i], FST_ELSE)))
			{
				LT::Entry entryLT = WriteEntry(entryLT, LEX_ELSE, LT_TI_NULLIDX, line);
				LT::Add(lextable, entryLT);
				is_cycle++;
			}
			else if (FST::execute(FST::FST(word[i], FST_INTLIT)))
			{
				int value = atoi((char*)word[i]);
				
				if (value< 0) {
					Log::WriteError(log, Error::geterrorin(207, line, position));

					throw ERROR_THROW(207);

				}
				if (findArray && countSize == 2
					
					) { //ARRAY
					if (value <= 0) {
						Log::WriteError(log, Error::geterrorin(207, line, position));

						throw ERROR_THROW(207);
					}
					entryIT.size = value;
					findArray = false;
					countSize = 0;
					continue;
				}

				for (int k = 0; k < idtable.size; k++) {
					if (idtable.table[k].value.vuint == value &&
						idtable.table[k].idtype == IT::L &&
						idtable.table[k].iddatatype == IT::UINT)
					{
						LT::Entry entryLT = WriteEntry(entryLT, LEX_LITERAL, k, line);
						LT::Add(lextable, entryLT);
						findSameID = true;
						break;
					}
				}

				if (findSameID) continue;
				entryIT.idtype = IT::L;
				entryIT.iddatatype = IT::UINT;
				entryIT.value.vuint = value;
				entryIT.idxfirstLE = indexLex;
				_itoa_s(literalCounter++, charclit, sizeof(char) * 10, 10);
				strcpy(bufL, L);
				word[i] = strcat(bufL, charclit);
				strcpy(entryIT.id, word[i]);
				IT::Add(idtable, entryIT);
				entryIT = {};

				LT::Entry entryLT = WriteEntry(entryLT, LEX_LITERAL, IT::IsId(idtable, word[i]), line);
				LT::Add(lextable, entryLT);
			}
			else if (FST::execute(FST::FST(word[i], FST_NUMBER8)))
			{
				char* numBuf = new char;
				int j = 0;
				for (int k = 2; k < strlen(word[i]); k++, j++)
				{
					numBuf[j] = word[i][k];
				}
				numBuf[j + 1] = '\0';
				int value = strtol(numBuf, NULL, 8);

				for (int k = 0; k < idtable.size; k++)
				{
					if (idtable.table[k].value.vuint == value &&
						idtable.table[k].idtype == IT::L &&
						idtable.table[k].iddatatype == IT::UINT)
					{
						LT::Entry entryLT = WriteEntry(entryLT, LEX_LITERAL, k, line);
						LT::Add(lextable, entryLT);
						findSameID = true;
						break;
					}
				}

				if (findSameID) continue;
				entryIT.idtype = IT::L;
				entryIT.iddatatype = IT::UINT;
				entryIT.value.vuint = value;
				entryIT.idxfirstLE = indexLex;
				_itoa_s(literalCounter++, charclit, sizeof(char) * 10, 10);
				strcpy(bufL, L);
				word[i] = strcat(bufL, charclit);
				strcpy(entryIT.id, word[i]);
				IT::Add(idtable, entryIT);
				entryIT = {};

				LT::Entry entryLT = WriteEntry(entryLT, LEX_LITERAL, IT::IsId(idtable, word[i]), line);
				LT::Add(lextable, entryLT);
			}
			else if (FST::execute(FST::FST(word[i], FST_STRLIT)))
			{
				int length = strlen(word[i]);
				for (int k = 0; k < length; k++)
					word[i][k] = word[i][k + 1];
				word[i][length - 2] = 0;

				for (int k = 0; k < idtable.size; k++) {
					if (!(strcmp(idtable.table[k].value.vstr.str, word[i])))
					{
						findSameID = true;
						LT::Entry entryLT = WriteEntry(entryLT, LEX_LITERAL, k, line);
						LT::Add(lextable, entryLT);
						break;
					}
				}
				if (findSameID) continue;

				strcpy(entryIT.value.vstr.str, word[i]);
				entryIT.value.vstr.len = length - 2;
				entryIT.idtype = IT::L;
				entryIT.iddatatype = IT::STR;
				entryIT.idxfirstLE = indexLex;

				_itoa_s(literalCounter++, charclit, sizeof(char) * 10, 10);
				strcpy(bufL, L);
				nameLiteral = strcat(bufL, (char*)charclit);
				strcpy(entryIT.id, nameLiteral);
				IT::Add(idtable, entryIT);
				entryIT = {};

				int k = 0;
				for (k = 0; k < idtable.size; k++)
				{
					if (!(strcmp(idtable.table[k].value.vstr.str, word[i])))
						break;
				}
				LT::Entry entryLT = WriteEntry(entryLT, LEX_LITERAL, k, line);
				LT::Add(lextable, entryLT);
			}
			else if (FST::execute(FST::FST(word[i], FST_ID)))
			{
				if (strlen(word[i]) > 7) {
					throw ERROR_THROW_IN(210, line, position);

				}
				if (findArray&& countSize == 2) {
					Log::WriteError(log, Error::geterrorin(211, line, position));

					throw ERROR_THROW(211);

				}
				if (findParm)
					entryIT.idtype = IT::P;
				else if (findFunc)
				{
					entryIT.idtype = IT::F;
					functions.push(word[i]);
				}
				else
				{
					
					entryIT.idtype = IT::V;
					int idx = IT::IsId(idtable, word[i]);
					if (idx != IT_NULLIDX) {
						LT::Entry entryLT = WriteEntry(entryLT, LEX_ID, idx, line);
						LT::Add(lextable, entryLT);
						entryIT = { };
						continue;
					}
					if (entryIT.iddatatype == IT::UINT)
						entryIT.value.vuint = IT_INT_DEFAULT;
					else if (entryIT.iddatatype == IT::STR)
					{
						entryIT.value.vstr.len = 0;
						memset(entryIT.value.vstr.str, IT_STR_DEFAULT, sizeof(char));
					}
				}

				entryIT.idxfirstLE = indexLex;
				if (entryIT.idtype != IT::F && !functions.empty())
				{
					strcpy(bufprefix, functions.top().c_str());
					word[i] = strcat(bufprefix, word[i]);
				}
				if (!findPropery && IT::IsId(idtable, word[i]) == IT_NULLIDX&&!findFunc) {

					Log::WriteError(log, Error::geterrorin(209, line, position));
					throw ERROR_THROW(209);

				}
				strcpy(entryIT.id, word[i]);
				int idx = IT::IsId(idtable, word[i]);
				if (idx == IT_NULLIDX)
					IT::Add(idtable, entryIT);
				LT::Entry entryLT = WriteEntry(entryLT, LEX_ID, IT::IsId(idtable, word[i]), line);
				LT::Add(lextable, entryLT);
				entryIT = { };
				
			}
			else if (FST::execute(FST::FST(word[i], FST_OP)))
			{
				strcpy(entryIT.id, word[i]);
				entryIT.idxfirstLE = indexLex;
				entryIT.idtype = IT::OP;
				if (IT::IsId(idtable, word[i]) == IT_NULLIDX)
					IT::Add(idtable, entryIT);
				entryIT = { };

				LT::Entry entryLT = WriteEntry(entryLT, LEX_OPERATOR, IT::IsId(idtable, word[i]), line);
				switch (word[i][0])
				{
				case FST_MORE:
					entryLT.priority = 0;
					entryLT.op = LT::operations::OMORE;
					break;
				case FST_LESS:
					entryLT.priority = 0;
					entryLT.op = LT::operations::OLESS;
					break;
				case FST_EQUALS:
					entryLT.priority = 0;
					entryLT.op = LT::operations::OEQUALS;
					break;
				case FST_EQMORE:
					entryLT.priority = 0;
					entryLT.op = LT::operations::OMOREEQ;
					break;
				case FST_EQLESS:
					entryLT.priority = 0;
					entryLT.op = LT::operations::OLESSEQ;
					break;
				case FST_NEQUALS:
					entryLT.priority = 0;
					entryLT.op = LT::operations::ONOTEQUALS;
					break;
				case FST_PLUS:
					entryLT.priority = 2;
					entryLT.op = LT::operations::OPLUS;
					break;
				case FST_MINUS:
					entryLT.priority = 2;
					entryLT.op = LT::operations::OMINUS;
					/*if (lextable.table[i - 2].lexema == '=') {
						throw ERROR_THROW(222);

					}*/
					break;
				case FST_DIRSLASH:
					entryLT.priority = 3;
					entryLT.op = LT::operations::ODIV;
					break;
				case FST_STAR:
					entryLT.priority = 3;
					entryLT.op = LT::operations::OMUL;
					break;
				}
				LT::Add(lextable, entryLT);
			}
			else if (FST::execute(FST::FST(word[i], FST_SEMICOLON)))
			{
				countSize = 0;
				printCheck = 0;
				if (findDeclaration && findFunc && findType)
					functions.pop();
				LT::Entry entryLT = WriteEntry(entryLT, LEX_SEMICOLON, LT_TI_NULLIDX, line);
				LT::Add(lextable, entryLT);
				findArray=findDeclaration = findFunc = findType = findParm = false;
				entryIT = { };
			}
			else if (FST::execute(FST::FST(word[i], FST_COMMA)))
			{
				LT::Entry entryLT = WriteEntry(entryLT, LEX_COMMA, LT_TI_NULLIDX, line);
				entryLT.priority = 1;
				LT::Add(lextable, entryLT);
			}
			else if (FST::execute(FST::FST(word[i], FST_LEFTBRACE)))
			{
				countSize = 0;
				findType = findDeclaration = findFunc = findParm = findProc = false;
				LT::Entry entryLT = WriteEntry(entryLT, LEX_LEFTBRACE, LT_TI_NULLIDX, line);
				LT::Add(lextable, entryLT);
			}
			else if (FST::execute(FST::FST(word[i], FST_BRACELET)))
			{
				if (!functions.empty() && is_cycle == 0)
					functions.pop();
				else if (is_cycle != 0) is_cycle--;
				LT::Entry entryLT = WriteEntry(entryLT, LEX_BRACELET, LT_TI_NULLIDX, line);

				LT::Add(lextable, entryLT);
			}

			else if (FST::execute(FST::FST(word[i], FST_LEFTHESIS)))
			{
				LT::Entry entryLT = WriteEntry(entryLT, LEX_LEFTHESIS, LT_TI_NULLIDX, line);
				entryLT.priority = 0;
				LT::Add(lextable, entryLT);
				if (findFunc || findProc)
					findParm = true;
			}
			else if (FST::execute(FST::FST(word[i], FST_RIGHTHESIS)))
			{
				LT::Entry entryLT = WriteEntry(entryLT, LEX_RIGHTHESIS, LT_TI_NULLIDX, line);
				entryLT.priority = 0;
				findParm = false;
				LT::Add(lextable, entryLT);
			}
			else if (FST::execute(FST::FST(word[i], FST_LEFTSQ))) //ARRAY
			{
				if (!FST::execute(FST::FST(word[i + 1], FST_INTLIT))) {
					Log::WriteError(log, Error::geterrorin(208, line, position));

					throw ERROR_THROW(208);
				}

				if (findDeclaration && !findType&& FST::execute(FST::FST(word[i + 1], FST_RIGHTSQ))) {
					Log::WriteError(log, Error::geterrorin(208, line, position));

					throw ERROR_THROW(208);
				
				}
				countSize++;
				LT::Entry entryLT = WriteEntry(entryLT, LEX_LEFTSQ, LT_TI_NULLIDX, line);
				entryLT.priority = 0;
				LT::Add(lextable, entryLT);

				findArray = true;

			}
			else if (FST::execute(FST::FST(word[i], FST_RIGHTSQ))) //ARRAY
			{
				LT::Entry entryLT = WriteEntry(entryLT, LEX_RIGHTSQ, LT_TI_NULLIDX, line);
				entryLT.priority = 0;
				countSize = 0;
				LT::Add(lextable, entryLT);
				
			}
			else if (FST::execute(FST::FST(word[i], FST_EQ)))
			{
				LT::Entry entryLT = WriteEntry(entryLT, LEX_EQUAL, LT_TI_NULLIDX, line);
				LT::Add(lextable, entryLT);
				findPropery = false;
			}
			else if (word[i][0] == DIV)
			{
				line++;
				position = 0;
				indexLex--;
			}
			else
			{
				if (strlen(word[i]) >7) {
					throw ERROR_THROW_IN(210, line, position);

				}
				else {
					throw ERROR_THROW_IN(205, line, position);

				}
			}
		}

		if (!findMain) throw ERROR_THROW(302);
		if (mainCounter > 1) throw ERROR_THROW(301);

		lex.idtable = idtable;
		lex.lextable = lextable;
		return lex;
	}
	void Synchronization(Lex::LEX& lex) {
		bool* is_changed = new bool[lex.idtable.size] { false };
		for (int i = 0; i < lex.lextable.size; i++)
		{
			if (lex.lextable.table[i].idxTI != -1 && !is_changed[lex.lextable.table[i].idxTI])
			{
				lex.idtable.table[lex.lextable.table[i].idxTI].idxfirstLE = i;
				is_changed[lex.lextable.table[i].idxTI] = true;
			}
		}
		delete[] is_changed;
	}
	
}




