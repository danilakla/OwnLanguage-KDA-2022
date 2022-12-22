#include "SemParsing.h"
#include <map>

namespace Semantic {
    bool Parse(Lex::LEX lex, Log::LOG log) 
    {
        bool good = true;
        int j = 0;
        int sizeArray;
        std::map<std::string, std::vector<IT::IDDATATYPE>> functions_parm;
        std::string function_id;
        std::vector<IT::IDDATATYPE> parms;
        for (int i = 0; i < lex.lextable.size; i++) 
        {
            
            switch (lex.lextable.table[i].lexema) 
            {

            case LEX_PRINT:
                if (lex.lextable.table[i + 1].idxTI != LT_TI_NULLIDX) {
                    if (lex.idtable.table[lex.lextable.table[i + 1].idxTI].idtype == IT::IDTYPE::F) {
                        good = false;
                        Log::WriteError(log, Error::geterrorin(309, lex.lextable.table[i].sn, -1));
                    }
                }
                if (lex.lextable.table[i + 1].idxTI != LT_TI_NULLIDX) {
                    if (lex.idtable.table[lex.lextable.table[i + 1].idxTI].iddatatype == IT::IDDATATYPE::UINTARRAY) {
                        good = false;
                        Log::WriteError(log, Error::geterrorin(309, lex.lextable.table[i].sn, -1));
                    }
                }
            break;
            case LEX_IF:  
                j = i + 2;
                    for (j; lex.lextable.table[j].lexema != LEX_RIGHTHESIS; j++) {
                        if (lex.lextable.table[j].idxTI != LT_TI_NULLIDX&& lex.lextable.table[j].lexema!= LEX_OPERATOR) {
                            if (lex.idtable.table[lex.lextable.table[j].idxTI].iddatatype != IT::UINT) {
                                good = false;
                                Log::WriteError(log, Error::geterrorin(312, lex.lextable.table[j].sn, -1));
                            }
                        }
                       
                    }

              
                
                continue;
            case LEX_ID:
                j = i + 1;
                std::cout << lex.idtable.table[lex.lextable.table[i].idxTI].iddatatype;
                if (lex.idtable.table[lex.lextable.table[i].idxTI].iddatatype == IT::IDDATATYPE::UINTARRAY &&
                    lex.lextable.table[i - 1].lexema == LEX_UINT)
                {
                    if (lex.idtable.table[lex.lextable.table[i].idxTI].size > 0) {
                        sizeArray = lex.idtable.table[lex.lextable.table[i].idxTI].size;
                    }
                    else
                    {
                        good = false;
                        Log::WriteError(log, Error::geterrorin(316, lex.lextable.table[j].sn, -1));
                    }
                }
                if (lex.idtable.table[lex.lextable.table[i].idxTI].idtype == IT::F &&
                    lex.lextable.table[i - 1].lexema != LEX_FUNCTION&&
                    lex.lextable.table[i - 1].lexema != LEX_PRINT)
                {

                    for (const auto &items : functions_parm) 
                    {
                        if (items.first == lex.idtable.table[lex.lextable.table[i].idxTI].id) 
                        {
                            std::vector<IT::IDDATATYPE> buffer = items.second;
                            while (lex.lextable.table[j].lexema != LEX_RIGHTHESIS) 
                            {
                                if (lex.lextable.table[j].lexema == LEX_ID ||
                                    lex.lextable.table[j].lexema == LEX_LITERAL) 
                                {
                                    if (!buffer.empty()) 
                                    {
                                        if (lex.idtable.table[lex.lextable.table[j].idxTI].iddatatype != buffer[0]) 
                                        {
                                            good = false;
                                            Log::WriteError(log, Error::geterrorin(309, lex.lextable.table[j].sn, -1));
                                        }
                                        buffer.erase(buffer.begin());
                                    } 
                                    else 
                                    {
                                        good = false;
                                        Log::WriteError(log, Error::geterrorin(315, lex.lextable.table[j].sn, -1));
                                    }
                                }
                                j++;
                            }
                            if (!buffer.empty()) 
                            {
                                good = false;
                                Log::WriteError(log, Error::geterrorin(315, lex.lextable.table[j].sn, -1));
                            }
                        }
                    }
                }
                continue;

            case LEX_DIRSLASH:
                if (lex.lextable.table[i].op == LT::ODIV) {
                    if (lex.lextable.table[i + 1].idxTI!= LT_TI_NULLIDX) {
                        if (lex.idtable.table[lex.lextable.table[i + 1].idxTI].value.vuint == 0) {
                            Log::WriteError(log, Error::geterrorin(319, lex.lextable.table[j].sn, -1));
                            good = false;
                        }
                    }
                    else {
                        Log::WriteError(log, Error::geterrorin(310, lex.lextable.table[j].sn, -1));
                        good = false;
                    }
                  
                }
                continue;


            case LEX_EQUAL:
                j = i + 1;

                if (lex.lextable.table[i - 1].idxTI!=LT_TI_NULLIDX) {
                    if (lex.idtable.table[lex.lextable.table[i - 1].idxTI].iddatatype == IT::IDDATATYPE::UINTARRAY &&
                        lex.lextable.table[i - 2].lexema == LEX_UINT) {
                        int t = 0;

                        for (j; lex.lextable.table[j].lexema != LEX_SEMICOLON; j++)
                        {
                            switch (lex.lextable.table[j].lexema)
                            {
                            case LEX_LITERAL:
                                if (lex.idtable.table[lex.lextable.table[j].idxTI].iddatatype != IT::IDDATATYPE::UINT)
                                {
                                    Log::WriteError(log, Error::geterrorin(312, lex.lextable.table[j].sn, -1));
                                    good = false;
                                }
                                t++;
                                continue;
                            case LEX_COMMA:

                                continue;


                            }
                        }

                        if (t != sizeArray) {
                            Log::WriteError(log, Error::geterrorin(317, lex.lextable.table[j].sn, -1));
                            good = false;
                        }
                        sizeArray = 0;
                        break;
                    }
                }

                if (lex.lextable.table[i - 1].lexema ==LEX_RIGHTSQ) {
                    for (j; lex.lextable.table[j].lexema != LEX_SEMICOLON; j++) {
                        if (lex.idtable.table[lex.lextable.table[i - 2].idxTI].value.vuint >= lex.idtable.table[lex.lextable.table[i - 4].idxTI].size ||
                            lex.idtable.table[lex.lextable.table[i - 2].idxTI].value.vuint < 0
                            )
                        {
                            Log::WriteError(log, Error::geterrorin(318, lex.lextable.table[j].sn, -1));
                            good = false;
                        }
                        switch (lex.lextable.table[j].lexema)
                        {
                        case LEX_ID:
                        case LEX_LITERAL:
                            if ((lex.idtable.table[lex.lextable.table[j].idxTI].iddatatype != IT::IDDATATYPE::UINTARRAY &&
                                lex.idtable.table[lex.lextable.table[j].idxTI].iddatatype != IT::IDDATATYPE::UINT
                                ))
                            {
                                Log::WriteError(log, Error::geterrorin(312, lex.lextable.table[j].sn, -1));
                                good = false;
                            }
                            if (lex.idtable.table[lex.lextable.table[j].idxTI].iddatatype == IT::IDDATATYPE::UINTARRAY) {
                                int size = lex.idtable.table[lex.lextable.table[j].idxTI].size;
                                if (lex.idtable.table[lex.lextable.table[j + 2].idxTI].value.vuint >= size || lex.idtable.table[lex.lextable.table[j + 2].idxTI].value.vuint < 0) {
                                    Log::WriteError(log, Error::geterrorin(318, lex.lextable.table[j].sn, -1));
                                    good = false;
                                }
                            }
                            continue;
                        case LEX_LEFTHESIS:
                            if (lex.lextable.table[j - 1].lexema != LEX_OPERATOR &&
                                lex.lextable.table[j - 1].lexema != LEX_LEFTHESIS)
                            {
                                do {
                                    j++;
                                } while (lex.lextable.table[j].lexema != LEX_RIGHTHESIS);
                            }
                            continue;
                        }

                    }
                }

               
                for (j; lex.lextable.table[j].lexema != LEX_SEMICOLON; j++) 
                {
                    switch (lex.lextable.table[j].lexema) 
                    {
                    case LEX_ID:
                    case LEX_LITERAL:
                        if (((lex.idtable.table[lex.lextable.table[j].idxTI].iddatatype !=
                             lex.idtable.table[lex.lextable.table[i - 1].idxTI].iddatatype)&&
                            !(lex.idtable.table[lex.lextable.table[i-1].idxTI].iddatatype==IT::IDDATATYPE::UINT&&
                                lex.idtable.table[lex.lextable.table[j].idxTI].iddatatype==IT::IDDATATYPE::UINTARRAY) ))
                        {
                            Log::WriteError(log, Error::geterrorin(312, lex.lextable.table[j].sn, -1));
                            good = false;
                        }
                        if (lex.idtable.table[lex.lextable.table[j].idxTI].iddatatype == IT::IDDATATYPE::UINTARRAY) {
                            int size=lex.idtable.table[lex.lextable.table[j].idxTI].size;
                            if (lex.lextable.table[j + 1].lexema != LEX_LEFTSQ) {
                                Log::WriteError(log, Error::geterrorin(320, lex.lextable.table[j].sn, -1));
                                good = false;

                                break;
                            }
                            if (lex.idtable.table[lex.lextable.table[j + 2].idxTI].value.vuint >=  size||lex.idtable.table[lex.lextable.table[j + 2].idxTI].value.vuint<0) {
                                Log::WriteError(log, Error::geterrorin(318, lex.lextable.table[j].sn, -1));
                                good = false;
                            }
                        }
                        continue;
                    case LEX_LEFTHESIS:
                        if (lex.lextable.table[j - 1].lexema != LEX_OPERATOR &&
                            lex.lextable.table[j - 1].lexema != LEX_LEFTHESIS) 
                        {
                            do {
                                j++;
                            } while (lex.lextable.table[j].lexema != LEX_RIGHTHESIS);
                        }
                        continue;
                    }
                }
                continue;
            case LEX_FUNCTION:
                for (const auto &items : functions_parm) 
                {
                    if (items.first == lex.idtable.table[lex.lextable.table[i + 1].idxTI].id) 
                    {
                        Log::WriteError(log, Error::geterrorin(307, lex.lextable.table[i + 1].sn, -1));
                        good = false;
                    }
                }
                function_id = lex.idtable.table[lex.lextable.table[i + 1].idxTI].id;
                j = i + 2;
                do 
                {
                    if (lex.lextable.table[j].lexema == LEX_ID ||
                        lex.lextable.table[j].lexema == LEX_LITERAL) 
                    {
                        parms.push_back(lex.idtable.table[lex.lextable.table[j].idxTI].iddatatype);
                    }
                    j++;
                } while (lex.lextable.table[j].lexema != LEX_RIGHTHESIS);
                functions_parm.insert(std::make_pair(function_id, parms));
                parms.clear();
                if (lex.lextable.table[i].lexema == LEX_FUNCTION) 
                {
                    j = i + 1;
                    int type = lex.idtable.table[lex.lextable.table[j].idxTI].iddatatype;
                    do 
                    {
                        j++;
                    } while ((lex.lextable.table[j].lexema != LEX_RET));
                    if (lex.idtable.table[lex.lextable.table[j + 1].idxTI].iddatatype != type) 
                    {
                        Log::WriteError(log, Error::geterrorin(314, lex.lextable.table[j].sn, -1));
                        good = false;
                    }
                }
            }
        }
        return good;
    }
}