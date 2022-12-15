#pragma once
#pragma warning(disable : 4996)
#include "Main.h"
#include "Error.h"
#include <fstream>
#include "Parm.h"
#include "In.h"
#include "LT.h"
#include "IT.h"
#define TEMPSIZE 100


namespace Log
{
	struct LOG
	{
		wchar_t logfile[PARM_MAX_SIZE];
		std::ofstream* stream;						
	};

	static const LOG INITLOG = { L"", NULL };		
	LOG	 getlog(wchar_t logfile[]);					
	void WriteLine(LOG log, const wchar_t* c, ...); 
	void WriteLine(LOG log, const char* c, ...);	
	void WriteLog(LOG log);							
	void WriteParm(LOG log, Parm::PARM parm);		
	void WriteIn(LOG log, In::IN in);				
	void WriteError(LOG log, Error::ERROR error);	
	void Close(LOG log);							
	void WriteLex(LOG log, LT::LexTable lex, Parm::PARM parm);
	void WriteIT(LOG log, IT::IdTable idt, Parm::PARM parm);
	void WriteLexTableLog(LT::LexTable& lextable, std::ostream& out);
}
