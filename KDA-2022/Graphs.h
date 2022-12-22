#include "FST.h"

#define FST_UINT	\
				5, \
				FST::NODE(1, FST::RELATION('u', 1)), \
				FST::NODE(1, FST::RELATION('i', 2)), \
				FST::NODE(1, FST::RELATION('n', 3)), \
				FST::NODE(1, FST::RELATION('t', 4)), \
				FST::NODE() \

#define FST_STR		\
				4, \
				FST::NODE(1, FST::RELATION('s', 1)), \
				FST::NODE(1, FST::RELATION('t', 2)), \
				FST::NODE(1, FST::RELATION('r', 3)), \
				FST::NODE() \

#define FST_OP	 \
				2, \
				FST::NODE(10,\
				FST::RELATION('+', 1), \
				FST::RELATION('-', 1), \
				FST::RELATION('*', 1), \
				FST::RELATION('/', 1), \
				FST::RELATION('>', 1), \
				FST::RELATION('<', 1), \
				FST::RELATION('~', 1), \
				FST::RELATION('!', 1), \
				FST::RELATION('^', 1), \
				FST::RELATION('_', 1)), \
				FST::NODE() \


#define FST_MORE	\
				2, \
				FST::NODE(1, FST::RELATION('>', 1)),\
				FST::NODE()\


#define FST_LESS	\
				2, \
				FST::NODE(1, FST::RELATION('<', 1)),\
				FST::NODE()\


#define FST_EQMORE	\
				2, \
				FST::NODE(1, FST::RELATION('^', 1)),\
				FST::NODE()\


#define FST_EQLESS	\
				2, \
				FST::NODE(1, FST::RELATION(':', 1)),\
				FST::NODE()\


#define FST_EQUALS	\
				2, \
				FST::NODE(1, FST::RELATION('&', 1)),\
				FST::NODE()\


#define FST_NEQUALS	\
				2, \
				FST::NODE(1, FST::RELATION('!', 1)),\
				FST::NODE()\


#define FST_EQ		\
				2, \
				FST::NODE(1,\
				FST::RELATION('=', 1)), \
				FST::NODE() \


#define FST_IF		\
				3, \
				FST::NODE(1, FST::RELATION('i', 1)), \
				FST::NODE(1, FST::RELATION('f', 2)), \
				FST::NODE() \


#define FST_ELSE	\
				5, \
				FST::NODE(1, FST::RELATION('e', 1)), \
				FST::NODE(1, FST::RELATION('l', 2)), \
				FST::NODE(1, FST::RELATION('s', 3)), \
				FST::NODE(1, FST::RELATION('e', 4)), \
				FST::NODE() \

#define FST_DATE	\
				5, \
				FST::NODE(1, FST::RELATION('D', 1)), \
				FST::NODE(1, FST::RELATION('a', 2)), \
				FST::NODE(1, FST::RELATION('t', 3)), \
				FST::NODE(1, FST::RELATION('e', 4)), \
				FST::NODE() \

#define FST_TIME	\
				5, \
				FST::NODE(1, FST::RELATION('T', 1)), \
				FST::NODE(1, FST::RELATION('i', 2)), \
				FST::NODE(1, FST::RELATION('m', 3)), \
				FST::NODE(1, FST::RELATION('e', 4)), \
				FST::NODE() \


#define FST_ID 3,	\
	FST::NODE(106,	\
	FST::RELATION('a', 1), FST::RELATION('b', 1), FST::RELATION('c', 1), FST::RELATION('d', 1), FST::RELATION('e', 1), FST::RELATION('f', 1),\
	FST::RELATION('g', 1), FST::RELATION('h', 1), FST::RELATION('i', 1), FST::RELATION('j', 1), FST::RELATION('k', 1), FST::RELATION('l', 1),\
	FST::RELATION('m', 1), FST::RELATION('n', 1), FST::RELATION('o', 1), FST::RELATION('p', 1), FST::RELATION('q', 1), FST::RELATION('r', 1),\
	FST::RELATION('s', 1), FST::RELATION('t', 1), FST::RELATION('u', 1), FST::RELATION('v', 1), FST::RELATION('w', 1), FST::RELATION('x', 1),\
	FST::RELATION('y', 1), FST::RELATION('z', 1),\
	FST::RELATION('A', 1), FST::RELATION('B', 1), FST::RELATION('C', 1), FST::RELATION('D', 1), FST::RELATION('E', 1), FST::RELATION('F', 1),\
	FST::RELATION('G', 1), FST::RELATION('H', 1), FST::RELATION('I', 1), FST::RELATION('J', 1), FST::RELATION('K', 1), FST::RELATION('L', 1),\
	FST::RELATION('M', 1), FST::RELATION('N', 1), FST::RELATION('O', 1), FST::RELATION('P', 1), FST::RELATION('Q', 1), FST::RELATION('R', 1),\
	FST::RELATION('S', 1), FST::RELATION('T', 1), FST::RELATION('U', 1), FST::RELATION('V', 1), FST::RELATION('W', 1), FST::RELATION('X', 1),\
	FST::RELATION('Y', 1), FST::RELATION('Z', 1), FST::RELATION('_', 1),\
	FST::RELATION('a', 2), FST::RELATION('b', 2), FST::RELATION('c', 2), FST::RELATION('d', 2), FST::RELATION('e', 2), FST::RELATION('f', 2),\
	FST::RELATION('g', 2), FST::RELATION('h', 2), FST::RELATION('i', 2), FST::RELATION('j', 2), FST::RELATION('k', 2), FST::RELATION('l', 2),\
	FST::RELATION('m', 2), FST::RELATION('n', 2), FST::RELATION('o', 2), FST::RELATION('p', 2), FST::RELATION('q', 2), FST::RELATION('r', 2),\
	FST::RELATION('s', 2), FST::RELATION('t', 2), FST::RELATION('u', 2), FST::RELATION('v', 2), FST::RELATION('w', 2), FST::RELATION('x', 2),\
	FST::RELATION('y', 2), FST::RELATION('z', 2),\
	FST::RELATION('A', 2), FST::RELATION('B', 2), FST::RELATION('C', 2), FST::RELATION('D', 2), FST::RELATION('E', 2), FST::RELATION('F', 2),\
	FST::RELATION('G', 2), FST::RELATION('H', 2), FST::RELATION('I', 2), FST::RELATION('J', 2), FST::RELATION('K', 2), FST::RELATION('L', 2),\
	FST::RELATION('M', 2), FST::RELATION('N', 2), FST::RELATION('O', 2), FST::RELATION('P', 2), FST::RELATION('Q', 2), FST::RELATION('R', 2),\
	FST::RELATION('S', 2), FST::RELATION('T', 2), FST::RELATION('U', 2), FST::RELATION('V', 2), FST::RELATION('W', 2), FST::RELATION('X', 2),\
	FST::RELATION('Y', 2), FST::RELATION('Z', 2), FST::RELATION('_', 2)),\
	FST::NODE(126,  \
	FST::RELATION('a', 1), FST::RELATION('b', 1), FST::RELATION('c', 1), FST::RELATION('d', 1), FST::RELATION('e', 1), FST::RELATION('f', 1),\
	FST::RELATION('g', 1), FST::RELATION('h', 1), FST::RELATION('i', 1), FST::RELATION('j', 1), FST::RELATION('k', 1), FST::RELATION('l', 1),\
	FST::RELATION('m', 1), FST::RELATION('n', 1), FST::RELATION('o', 1), FST::RELATION('p', 1), FST::RELATION('q', 1), FST::RELATION('r', 1),\
	FST::RELATION('s', 1), FST::RELATION('t', 1), FST::RELATION('u', 1), FST::RELATION('v', 1), FST::RELATION('w', 1), FST::RELATION('x', 1),\
	FST::RELATION('y', 1), FST::RELATION('z', 1),\
	FST::RELATION('A', 1), FST::RELATION('B', 1), FST::RELATION('C', 1), FST::RELATION('D', 1), FST::RELATION('E', 1), FST::RELATION('F', 1),\
	FST::RELATION('G', 1), FST::RELATION('H', 1), FST::RELATION('I', 1), FST::RELATION('J', 1), FST::RELATION('K', 1), FST::RELATION('L', 1),\
	FST::RELATION('M', 1), FST::RELATION('N', 1), FST::RELATION('O', 1), FST::RELATION('P', 1), FST::RELATION('Q', 1), FST::RELATION('R', 1),\
	FST::RELATION('S', 1), FST::RELATION('T', 1), FST::RELATION('U', 1), FST::RELATION('V', 1), FST::RELATION('W', 1), FST::RELATION('X', 1),\
	FST::RELATION('Y', 1), FST::RELATION('Z', 1), FST::RELATION('_', 1), \
	FST::RELATION('0', 1), FST::RELATION('1', 1), FST::RELATION('2', 1), FST::RELATION('3', 1), FST::RELATION('4', 1), FST::RELATION('5', 1),\
    FST::RELATION('6', 1), FST::RELATION('7', 1), FST::RELATION('8', 1), FST::RELATION('9', 1), \
    \
	FST::RELATION('a', 2), FST::RELATION('b', 2), FST::RELATION('c', 2), FST::RELATION('d', 2), FST::RELATION('e', 2), FST::RELATION('f', 2),\
	FST::RELATION('g', 2), FST::RELATION('h', 2), FST::RELATION('i', 2), FST::RELATION('j', 2), FST::RELATION('k', 2), FST::RELATION('l', 2),\
	FST::RELATION('m', 2), FST::RELATION('n', 2), FST::RELATION('o', 2), FST::RELATION('p', 2), FST::RELATION('q', 2), FST::RELATION('r', 2),\
	FST::RELATION('s', 2), FST::RELATION('t', 2), FST::RELATION('u', 2), FST::RELATION('v', 2), FST::RELATION('w', 2), FST::RELATION('x', 2),\
	FST::RELATION('y', 2), FST::RELATION('z', 2),\
	FST::RELATION('A', 2), FST::RELATION('B', 2), FST::RELATION('C', 2), FST::RELATION('D', 2), FST::RELATION('E', 2), FST::RELATION('F', 2),\
	FST::RELATION('G', 2), FST::RELATION('H', 2), FST::RELATION('I', 2), FST::RELATION('J', 2), FST::RELATION('K', 2), FST::RELATION('L', 2),\
	FST::RELATION('M', 2), FST::RELATION('N', 2), FST::RELATION('O', 2), FST::RELATION('P', 2), FST::RELATION('Q', 2), FST::RELATION('R', 2),\
	FST::RELATION('S', 2), FST::RELATION('T', 2), FST::RELATION('U', 2), FST::RELATION('V', 2), FST::RELATION('W', 2), FST::RELATION('X', 2),\
	FST::RELATION('Y', 2), FST::RELATION('Z', 2), FST::RELATION('_', 2), \
	FST::RELATION('0', 2), FST::RELATION('1', 2), FST::RELATION('2', 2), FST::RELATION('3', 2), FST::RELATION('4', 2), FST::RELATION('5', 2),\
    FST::RELATION('6', 2), FST::RELATION('7', 2), FST::RELATION('8', 2), FST::RELATION('9', 2)),\
	FST::NODE()

#define FST_FUNC	\
				5, \
				FST::NODE(1, FST::RELATION('f', 1)), \
				FST::NODE(1, FST::RELATION('u', 2)), \
				FST::NODE(1, FST::RELATION('n', 3)), \
				FST::NODE(1, FST::RELATION('c', 4)), \
				FST::NODE() \


#define FST_VAR		\
				4, \
				FST::NODE(1, FST::RELATION('v', 1)), \
				FST::NODE(1, FST::RELATION('a', 2)), \
				FST::NODE(1, FST::RELATION('r', 3)), \
				FST::NODE() \


#define FST_MAIN	\
				5, \
				FST::NODE(1, FST::RELATION('m', 1)), \
				FST::NODE(1, FST::RELATION('a', 2)), \
				FST::NODE(1, FST::RELATION('i', 3)), \
				FST::NODE(1, FST::RELATION('n', 4)), \
				FST::NODE() \

#define FST_PRINT	\
				6, \
				FST::NODE(1, FST::RELATION('p', 1)), \
				FST::NODE(1, FST::RELATION('r', 2)), \
				FST::NODE(1, FST::RELATION('i', 3)), \
				FST::NODE(1, FST::RELATION('n', 4)), \
				FST::NODE(1, FST::RELATION('t', 5)), \
				FST::NODE() \


#define FST_RET		\
				4, \
				FST::NODE(1, FST::RELATION('r', 1)), \
				FST::NODE(1, FST::RELATION('e', 2)), \
				FST::NODE(1, FST::RELATION('t', 3)), \
				FST::NODE() \


#define FST_SEMICOLON	\
				2, \
				FST::NODE(1, FST::RELATION(';',1)), \
				FST::NODE() \


#define FST_COMMA	\
				2, \
				FST::NODE(1, FST::RELATION(',',1)), \
				FST::NODE() \

#define FST_LEFTBRACE	\
				2, \
				FST::NODE(1, FST::RELATION('{',1)), \
				FST::NODE() \


#define FST_BRACELET	\
				2, \
				FST::NODE(1, FST::RELATION('}',1)), \
				FST::NODE() \


#define FST_LEFTHESIS	\
				2, \
				FST::NODE(1, FST::RELATION('(',1)), \
				FST::NODE() \

#define FST_RIGHTHESIS	\
				2, \
				FST::NODE(1, FST::RELATION(')',1)), \
				FST::NODE() \


#define FST_LEFTSQ	\
				2, \
				FST::NODE(1, FST::RELATION('[',1)), \
				FST::NODE() \

#define FST_RIGHTSQ	\
				2, \
				FST::NODE(1, FST::RELATION(']',1)), \
				FST::NODE() \

#define FST_PLUS	\
				2, \
				FST::NODE(1, FST::RELATION('+',1)), \
				FST::NODE() \

#define FST_MINUS	\
				2, \
				FST::NODE(1, FST::RELATION('-',1)), \
				FST::NODE() \

#define FST_STAR	\
				2, \
				FST::NODE(1, FST::RELATION('*',1)), \
				FST::NODE() \

#define FST_DIRSLASH	\
				2, \
				FST::NODE(1, FST::RELATION('/',1)), \
				FST::NODE() \

#define FST_INTLIT 2,	\
	FST::NODE(20,	\
	FST::RELATION('1', 0), FST::RELATION('2', 0), FST::RELATION('3', 0), FST::RELATION('4', 0), FST::RELATION('5', 0), FST::RELATION('6', 0),\
	FST::RELATION('7', 0), FST::RELATION('8', 0), FST::RELATION('9', 0), FST::RELATION('0', 0),\
	\
	FST::RELATION('1', 1), FST::RELATION('2', 1), FST::RELATION('3', 1), FST::RELATION('4', 1), FST::RELATION('5', 1), FST::RELATION('6', 1),\
	FST::RELATION('7', 1), FST::RELATION('8', 1), FST::RELATION('9', 1), FST::RELATION('0', 1)),\
	FST::NODE()

#define FST_NUMBER8		\
					4, \
					FST::NODE(1,	FST::RELATION('8', 1)), \
					FST::NODE(1,	FST::RELATION('x', 2)),	\
					FST::NODE(16,	FST::RELATION('1', 2), FST::RELATION('1', 3), \
								FST::RELATION('2', 2), FST::RELATION('2', 3), \
								FST::RELATION('3', 2), FST::RELATION('3', 3), \
								FST::RELATION('4', 2), FST::RELATION('4', 3), \
								FST::RELATION('5', 2), FST::RELATION('5', 3), \
								FST::RELATION('6', 2), FST::RELATION('6', 3), \
								FST::RELATION('7', 2), FST::RELATION('7', 3), \
								FST::RELATION('0', 2), FST::RELATION('0', 3)), \
					FST::NODE()\

#define FST_STRLIT 3,	\
	FST::NODE(1, FST::RELATION('\'', 1)),\
	FST::NODE(154, \
			FST::RELATION('a', 1), FST::RELATION('b', 1), FST::RELATION('c', 1), FST::RELATION('d', 1),\
			FST::RELATION('e', 1), FST::RELATION('f', 1), FST::RELATION('g', 1), FST::RELATION('h', 1),\
			FST::RELATION('i', 1), FST::RELATION('j', 1), FST::RELATION('k', 1), FST::RELATION('l', 1),\
			FST::RELATION('m', 1), FST::RELATION('n', 1), FST::RELATION('o', 1), FST::RELATION('p', 1),\
			FST::RELATION('q', 1), FST::RELATION('r', 1), FST::RELATION('s', 1), FST::RELATION('t', 1),\
			FST::RELATION('u', 1), FST::RELATION('v', 1), FST::RELATION('w', 1), FST::RELATION('x', 1),\
			FST::RELATION('y', 1), FST::RELATION('z', 1),\
			FST::RELATION('A', 1), FST::RELATION('B', 1), FST::RELATION('C', 1), FST::RELATION('D', 1),\
			FST::RELATION('E', 1), FST::RELATION('F', 1), FST::RELATION('G', 1), FST::RELATION('H', 1),\
			FST::RELATION('I', 1), FST::RELATION('J', 1), FST::RELATION('K', 1), FST::RELATION('L', 1),\
			FST::RELATION('M', 1), FST::RELATION('N', 1), FST::RELATION('O', 1), FST::RELATION('P', 1),\
			FST::RELATION('Q', 1), FST::RELATION('R', 1), FST::RELATION('S', 1), FST::RELATION('T', 1),\
			FST::RELATION('U', 1), FST::RELATION('V', 1), FST::RELATION('W', 1), FST::RELATION('X', 1),\
			FST::RELATION('Y', 1), FST::RELATION('Z', 1),\
			FST::RELATION('�', 1), FST::RELATION('�', 1), FST::RELATION('�', 1), FST::RELATION('�', 1),\
			FST::RELATION('�', 1), FST::RELATION('�', 1), FST::RELATION('�', 1), FST::RELATION('�', 1),\
			FST::RELATION('�', 1), FST::RELATION('�', 1), FST::RELATION('�', 1), FST::RELATION('�', 1),\
			FST::RELATION('�', 1), FST::RELATION('�', 1), FST::RELATION('�', 1), FST::RELATION('�', 1),\
			FST::RELATION('�', 1), FST::RELATION('�', 1), FST::RELATION('�', 1), FST::RELATION('�', 1),\
			FST::RELATION('�', 1), FST::RELATION('�', 1), FST::RELATION('�', 1), FST::RELATION('�', 1),\
			FST::RELATION('�', 1), FST::RELATION('�', 1), FST::RELATION('�', 1), FST::RELATION('�', 1),\
			FST::RELATION('�', 1), FST::RELATION('�', 1), FST::RELATION('�', 1), FST::RELATION('�', 1),\
			FST::RELATION('�', 1),\
			FST::RELATION('�', 1), FST::RELATION('�', 1), FST::RELATION('�', 1), FST::RELATION('�', 1),\
			FST::RELATION('�', 1), FST::RELATION('�', 1), FST::RELATION('�', 1), FST::RELATION('�', 1),\
			FST::RELATION('�', 1), FST::RELATION('�', 1), FST::RELATION('�', 1), FST::RELATION('�', 1),\
			FST::RELATION('�', 1), FST::RELATION('�', 1), FST::RELATION('�', 1), FST::RELATION('�', 1),\
			FST::RELATION('�', 1), FST::RELATION('�', 1), FST::RELATION('�', 1), FST::RELATION('�', 1),\
			FST::RELATION('�', 1), FST::RELATION('�', 1), FST::RELATION('�', 1), FST::RELATION('�', 1),\
			FST::RELATION('�', 1), FST::RELATION('�', 1), FST::RELATION('�', 1), FST::RELATION('�', 1),\
			FST::RELATION('�', 1), FST::RELATION('�', 1), FST::RELATION('�', 1), FST::RELATION('�', 1),\
			FST::RELATION('�', 1),\
			FST::RELATION('0', 1), FST::RELATION('1', 1), FST::RELATION('2', 1), FST::RELATION('3', 1),\
			FST::RELATION('4', 1), FST::RELATION('5', 1), FST::RELATION('6', 1), FST::RELATION('7', 1),\
			FST::RELATION('8', 1), FST::RELATION('9', 1),\
			FST::RELATION(' ', 1), FST::RELATION(',', 1), FST::RELATION('.', 1), FST::RELATION(';', 1),\
			FST::RELATION('-', 1), FST::RELATION('+', 1), FST::RELATION('*', 1), FST::RELATION('/', 1),\
			FST::RELATION('=', 1), FST::RELATION(':', 1), FST::RELATION(')', 1), FST::RELATION('(', 1),\
			FST::RELATION('}', 1), FST::RELATION('{', 1), FST::RELATION(']', 1), FST::RELATION('[', 1),\
			FST::RELATION('!', 1), FST::RELATION('?', 1), FST::RELATION('#', 1), FST::RELATION('&', 1),\
			FST::RELATION('>', 1), FST::RELATION('<', 1), FST::RELATION('[', 1), FST::RELATION(']', 1),\
			FST::RELATION('^', 1), \
			FST::RELATION('\'', 2)),\
	FST::NODE()