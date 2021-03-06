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
#include <string>
#include <memory>
#include <stack>
#include <list>
#include "symbol.h"
#include "lexer.h"
// #include "object.h"

/******************************************************************************
* Birthstone parser.
******************************************************************************/
class Parser
{
	public:
		Parser(std::istream &input);
		bool run();
		
	protected:
		const Token &getNext();
		std::string toStr  (Token t);
		double      toNum  (Token t);
		bool        toBool (Token t);
		Token &lookup(Token id);
		Token deleteVar(Token id);

		bool accept(Symbol sym);
		bool expect(Symbol sym);
		bool error(std::string msg);
			
		bool code();

		bool defFunc();
		bool print();
		bool read();
		bool deleteCmd();
		bool breakStmt() throw(Symbol);
		bool contStmt() throw(Symbol);
		
		bool ifCond();
		bool elifCond(bool &ignore);
		bool elseCond(bool ignore);

		bool loop();
// 		void forLoop();
// 		void forInLoop();
// 		void whileLoop();
// 		void doWhileLoop();
// 		void loopBody(SavedTokenStream cmds);

		bool block(bool createScope = true);
		bool stmt();
		
		Token asgnmt();
		Token orOp();
		Token andOp();
		Token comp();
		Token sum();
		Token product();
		Token unary();
		Token factor();

		Token call(const Token &funcName);


		
	private:

		Lexer mLexer;
		Token mToken;
		typedef std::map<std::string,Token> SymTbl;
		std::list<SymTbl> mSymTbls;
		std::stack<SavedTokenStream> mTknStreams;
		SavedTokenStream *mSave; // save tokens?
		bool mExec; // execute (true) or ignore (false) commands?
		bool mBreak;
		bool mCont;
		bool mRet;
		Token mRetVal;
};






#endif // not defined BS_PARSER_H
