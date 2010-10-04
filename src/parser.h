/******************************************************************************
*   Copyright (C) 2010 by Robert Tolliver                                     *
*   Robb.Tolli@gmail.com                                                      *
*                                                                             *
*   This file is part of Birthstone.                                          *
*                                                                             *
*   Birthstone is free software: you can redistribute it and/or modify        *
*   it under the terms of the GNU General Public License as published by      *
*   the Free Software Foundation, either version 3 of the License, or         *
*  (at your option) any later version.                                        *
*                                                                             *
*   Birthstone is distributed in the hope that it will be useful,             *
*   but WITHOUT ANY WARRANTY; without even the implied warranty of            *
*   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the             *
*   GNU General Public License for more details.                              *
*                                                                             *
*   You should have received a copy of the GNU General Public License         *
*   along with Birthstone.  If not, see <http://www.gnu.org/licenses/>.       *
*                                                                             *
******************************************************************************/
#ifndef BS_PARSER_H
#define BS_PARSER_H
#include <map>
#include <istream>
#include <stack>
#include "symbol.h"
using Sym::Symbol;

class SymTable
{
};

/******************************************************************************
* A Birthstone parser.
******************************************************************************/
class Parser
{
	public:
		Parser(std::istream &input);

		void run();
	private:
		void act(int action);
		void setupTable();
		
		Lexer mLexer;
		static map<Symbol, map<Symbol, int> > sTable; // Parse table
		stack<Symbol> mStack; // Symbol stack
	
};
std::map<Symbol, map<Symbol,int> > Parser::mTable;




#endif // not defined BS_PARSER_H
