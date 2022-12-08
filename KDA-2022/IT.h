#pragma once
#include "LT.h"
#define ID_MAXSIZE		10
#define IT_MAXSIZE		4096
#define IT_INT_DEFAULT	0x00000000
#define IT_STR_DEFAULT	0x00
#define IT_NULLIDX		0xffffffff
#define IT_STR_MAXSIZE	255

namespace IT
{
	enum IDDATATYPE { UINT = 1, STR = 2, UINTARRAY=3};
	enum IDTYPE { V = 1, F = 2, P = 3, L = 4, OP = 5 };	// ���� ���������������: ����������/�������/��������/�������/��������

	struct Entry	// ������ ������� ���������������
	{
		int			idxfirstLE;		// ������ � ������� ������
		char		id[ID_MAXSIZE];	// ������������� (������������� ��������� �� ID_MAXSIZE)
		IDDATATYPE	iddatatype;		// ��� ������
		IDTYPE		idtype;			// ��� ��������������

		int			numbersystem;	// ������� ���������
		int			parmsamount;	// ��� �������: ���������� ����������

		int			index;					// ������� ��������� 
		char		function[ID_MAXSIZE];	// �������, ������� �����������
		int			size = 0;
		struct		// 
		{
			unsigned int vuint = 0;					// �������� unsigned integer
			struct
			{
				int len;						// ���������� �������� � string
				char str[IT_STR_MAXSIZE - 1]{};	// ������� string
			}vstr;								// �������� string
		}value;		// �������� ��������������
	};

	struct IdTable	// ��������� ������� ���������������
	{
		int			maxsize;		// ������� ������� < TI_MAXSIZE
		int			size;			// ������� ������ ������� ��������������� < maxsize
		Entry* table;			// ������ ����� ������� ���������������
	};

	IdTable Create(					// �������� ������� ���������������
		int size					// �������������� ������� ������� < TI_MAXSIZE
	);

	void Add(
		IdTable& idtable,			// ��������� ������� ���������������
		Entry entry					// ����������� ������ ������� ���������������
	);

	Entry GetEntry(					// ��������� ������ ������� ���������������
		IdTable& idtable,			// ��������� ������� ���������������
		int n						// ����� ���������� ������
	);

	int IsId(						// ������� ������ ������ (���� ��� - TI_NULLIDX)
		IdTable& idtable,			// ��������� ������� ���������������
		char id[ID_MAXSIZE]			// �������������
	);

	void Delete(					// �������� ������� ��������������� (������������ ������) 
		IdTable& idtable			// ��������� ������� ���������������
	);

	void ShowTable(
		IdTable idt,
		std::ostream& stream_out
	);
};
