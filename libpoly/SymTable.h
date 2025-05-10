#ifndef __POLY_SYMTABLE_H__
#define __POLY_SYMTABLE_H__

#include <string>

class CSymTable
{
    public:
	CSymTable(int aTok, std::string aStr);
	virtual ~CSymTable();

	double		dVal;
	int		token;
	std::string	strlex;
};

#endif
//martysama0134's ec11de26810c4b4081710343a364aa44
