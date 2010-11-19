/******************************************************************************
*   Copyright (C) 2010 by Robert Tolliver                                     *
*   Robb.Tolli@gmail.com                                                      *
*                                                                             *
*                                                                             *
*   This is free software: you can redistribute it and/or modify              *
*   it under the terms of the GNU General Public License as published by      *
*   the Free Software Foundation, either version 3 of the License, or         *
*  (at your option) any later version.                                        *
*                                                                             *
*   This is distributed in the hope that it will be useful,                   *
*   but WITHOUT ANY WARRANTY; without even the implied warranty of            *
*   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the             *
*   GNU General Public License for more details.                              *
*                                                                             *
*   You should have received a copy of the GNU General Public License         *
*   along with this file.  If not, see <http://www.gnu.org/licenses/>.        *
*                                                                             *
******************************************************************************/
#ifndef COPY_COUNTER_HPP
#define COPY_COUNTER_HPP
class CopyCounter
{
public:
	unsigned int currentCount() { return *curCnt;   }
	unsigned int totalCount()   { return *totalCnt; }
protected:
	CopyCounter()
	{
		curCnt = new unsigned int(1);
		totalCnt = new unsigned int(1);
	}
	
	CopyCounter(const CopyCounter &counter)
 	: curCnt(counter.curCnt), totalCnt(counter.totalCnt)
	{
		++(*curCnt);
		++(*totalCnt);
	}
	
	~CopyCounter()
	{
		--(*curCnt);
		if (*curCnt == 0)
		{
			delete curCnt;
			delete totalCnt;
		}
	}
private:
	unsigned int *curCnt;
	unsigned int *totalCnt;

};
#endif
