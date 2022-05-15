/*
 * File Name: new_delete.cpp
 * Description:
 * Author: Dan Cao <caodan@linuxtoy.cn>
 * Created Time: 2019-04-22 22:42:27
 *
 *   This program is free software; you can redistribute it and/or modify
 *   it under the terms of the GNU General Public License as published by
 *   the Free Software Foundation; either version 2 of the License, or
 *   (at your option) any later version.
 *
 *   This program is distributed in the hope that it will be useful,
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *   GNU General Public License for more details.
 *
 *   You should have received a copy of the GNU General Public License
 *   along with this program; if not, write to the Free Software
 *   Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 */

#include <cstdlib>
#include <iostream>
using namespace std;

void *operator new(size_t s)
{
	void *p;

	p = malloc(s);	
	printf("new object, size = %d, %p\n", s, p);
	return p;
}

void *operator new[](size_t s)
{
	void *p;

	p = malloc(s);	
	printf("new array,  size = %d %p\n", s, p);
	return p;
}

void operator delete(void *p) noexcept
{
	printf("delete object %p\n", p);

	free(p);
}

void operator delete[](void *p) noexcept
{
	printf("delete array  %p\n", p);

	free(p);
}

int main(int argc, char *argv[])
{
	char *pStr = new char;
	char *pStrArr = new char[128];
	uint64_t *pu64 = new uint64_t;
	uint64_t *pu64Arr = new uint64_t[128];

	delete pStr;
	delete[] pStrArr;
	delete pu64;
	delete[] pu64Arr;

	return 0;
}
