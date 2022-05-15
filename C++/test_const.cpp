/*************************************************************************
  > File Name: test.cpp
  > Description: 
  > Author: CaoDan
  > Mail: caodan@linuxtoy.cn 
  > Created Time: 2016-03-30 08:00:37
 ************************************************************************/

#include <iostream>
using namespace std;

void test_typedef_with_const(void)
{
    char szBuf[128] = "hello";

	using pstring = char *;
    typedef char *pstring;
    const pstring cstr = 0;
    const char *c_str;

    //cstr = szBuf; // Error: cstr is const, can not modify cstr
    c_str = szBuf;

	// pstring 是指向char的指针
	// const pstring 是指向char的常量指针
	// const char * 是指向常量字符的指针
	// 所以cstr的定义与  char * const cstr = 0;  等价, const修饰的是cstr

    const pstring *ps;

	// type of ps:     char* const*
	// type of &c_str: const char**
	// ps = &c_str; // 这个赋值不正确, 需采用下面的语法进行const转换
	ps = const_cast<char* const*>(&c_str);
}

void test_const(void)
{
	int i = 10;
	const int ci = i;

	const int &r1 = i;
	const int &r2 = i * r1;

	cout << "i = " << i << endl;
	cout << "r1 = " << r1 << endl;
	i = 100;
	cout << "r1 = " << r1 << endl;

	double dval = 3.14;
	const int &ri_1 = dval;
	cout << "ri_1 = " << ri_1 << endl;
	dval = 4.2;
	cout << "ri_1 = " << ri_1 << endl;
}

int main(int argc, char *argv[])
{
    //constexpr int i = 0;  // c++11
    
	test_const();

	return 0;
}
