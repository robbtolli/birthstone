/******************************************************************************
*	 Birthstone is a programming language and interpreter written by           *
*   Robb Tolliver for his Senior Project at BYU-Idaho (Fall 2010).            *
*                                                                             *
*   Copyright (C) 2010 by Robert Tolliver                                     *
*   Robb.Tolli@gmail.com                                                      *
*                                                                             *
*   Birthstone is free software: you can redistribute it and/or modify        *
*   it under the terms of the GNU General Public License as published by      *
*   the Free Software Foundation, either version 3 of the License, or         *
*   (at your option) any later version.                                       *
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
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include "parser.h"
using namespace std;


int main(int argc, char **argv)
{
	string filename;
	bool interactive = true;
	if (argc > 1)
	{
		ifstream input(argv[1]);
		if (input.good())
			Parser(input).run();
		else
		{
			cerr << "error: could not read input file. " << endl;
		}
		input.close();
	}
	else // interactive mode
	{
		string str;
		stringstream input;
		Parser parser(input);
		cout << "Birthstone interactive interpreter" << endl;
		cout << "(build " << __DATE__ << ' ' << __TIME__ ;
		#ifdef BS_DEBUG
			cout << " DEBUG";
		#endif // BS_DEBUG
		cout << ")"<< endl;
		do
		{
			cout << "bs> ";
			getline(cin, str);
			input.clear(); // clear flags including ios::eof
			input.str(str);
		} while (parser.run());
	}

	
	return 0;
}
