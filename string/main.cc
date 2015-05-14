#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "qh_string.h"
#include <assert.h>


void test1(){
	qh::string a;
	qh::string b = a;
	qh::string c(a);
	assert(a.size() == b.size());
	assert(a.size() == c.size());
	assert(b.size() == c.size());
	assert(a.size() == 0);
	assert(a.data() == NULL);
	assert(b.data() == NULL);
	assert(c.data() == NULL);
	assert(a.c_str() == NULL);
	assert(b.c_str() == NULL);
	assert(c.c_str() == NULL);

try
	{
		a[0] = '1';
		assert(a[0] == '1');
		assert(a[0] != b[0]);
		assert(a[0] != c[0]);
	}
catch(...)
	{
		printf("out of range\n");
	}

try
	{
		a[-1] = '1';
	}
catch(...)
	{
		printf("out of range, index is negative\n");
	}

try
	{
		a[1000] = '1';
	}
catch(...)
	{
		printf("out of range, index greater than size\n");
	}
}

void test2(){
	qh::string a("test");
	qh::string b = a;
	qh::string c(a);
	assert(a.size() == b.size());
	assert(a.size() == c.size());
	assert(b.size() == c.size());
	assert(a.size() == 4);
	assert(b.size() == 4);
	assert(c.size() == 4);
	assert(strcmp(a.data(), "test") == 0);
	assert(strcmp(b.data(), "test") == 0);
	assert(strcmp(c.data(), "test") == 0);
	assert(strcmp(a.c_str(), "test") == 0);
	assert(strcmp(b.c_str(), "test") == 0);
	assert(strcmp(c.c_str(), "test") == 0);
try
	{
		a[0] = '1';
		assert(a[0] == '1');
		assert(a[0] != b[0]);
		assert(a[0] != c[0]);
	}
catch(...)
	{
		printf("out of range\n");
	}

try
	{
		a[-1] = '1';
	}
catch(...)
	{
		printf("out of range, index is negative\n");
	}

try
	{
		a[1000] = '1';
	}
catch(...)
	{
		printf("out of range, index greater than size\n");
	}
}
void test3(){
	qh::string a("");
	qh::string b = a;
	qh::string c(a);
	assert(a.size() == b.size());
	assert(a.size() == c.size());
	assert(b.size() == c.size());
	assert(a.size() == 0);
	assert(a.data() == NULL);
	assert(b.data() == NULL);
	assert(c.data() == NULL);
	assert(a.c_str() == NULL);
	assert(b.c_str() == NULL);
	assert(c.c_str() == NULL);

try
	{
		a[0] = '1';
		assert(a[0] == '1');
		assert(a[0] != b[0]);
		assert(a[0] != c[0]);
	}
catch(...)
	{
		printf("out of range\n");
	}

try
	{
		a[-1] = '1';
	}
catch(...)
	{
		printf("out of range, index is negative\n");
	}

try
	{
		a[1000] = '1';
	}
catch(...)
	{
		printf("out of range, index greater than size\n");
	}
}
void test4(){
	qh::string a(NULL);
	qh::string b = a;
	qh::string c(a);
	assert(a.size() == b.size());
	assert(a.size() == c.size());
	assert(b.size() == c.size());
	assert(a.size() == 0);
	assert(a.data() == NULL);
	assert(b.data() == NULL);
	assert(c.data() == NULL);
	assert(a.c_str() == NULL);
	assert(b.c_str() == NULL);
	assert(c.c_str() == NULL);

try
	{
		a[0] = '1';
		assert(a[0] == '1');
		assert(a[0] != b[0]);
		assert(a[0] != c[0]);
	}
catch(...)
	{
		printf("out of range\n");
	}

try
	{
		a[-1] = '1';
	}
catch(...)
	{
		printf("out of range, index is negative\n");
	}

try
	{
		a[1000] = '1';
	}
catch(...)
	{
		printf("out of range, index greater than size\n");
	}
}
void test5(){
	qh::string a("test", 100);
	qh::string b = a;
	qh::string c(a);
	assert(a.size() == b.size());
	assert(a.size() == c.size());
	assert(b.size() == c.size());
	assert(a.size() == 100);
	assert(b.size() == 100);
	assert(c.size() == 100);
	assert(strcmp(a.data(), "test") == 0);
	assert(strcmp(b.data(), "test") == 0);
	assert(strcmp(c.data(), "test") == 0);
	assert(strcmp(a.c_str(), "test") == 0);
	assert(strcmp(b.c_str(), "test") == 0);
	assert(strcmp(c.c_str(), "test") == 0);
try
	{
		a[0] = '1';
		assert(a[0] == '1');
		assert(a[0] != b[0]);
		assert(a[0] != c[0]);
	}
catch(...)
	{
		printf("out of range\n");
	}

try
	{
		a[-1] = '1';
	}
catch(...)
	{
		printf("out of range, index is negative\n");
	}

try
	{
		a[1000] = '1';
	}
catch(...)
	{
		printf("out of range, index greater than size\n");
	}
}
void test6(){
	qh::string a("test", 2);
	qh::string b = a;
	qh::string c(a);
	assert(a.size() == b.size());
	assert(a.size() == c.size());
	assert(b.size() == c.size());
	assert(a.size() == 2);
	assert(b.size() == 2);
	assert(c.size() == 2);
	assert(strcmp(a.data(), "te") == 0);
	assert(strcmp(b.data(), "te") == 0);
	assert(strcmp(c.data(), "te") == 0);
	assert(strcmp(a.c_str(), "te") == 0);
	assert(strcmp(b.c_str(), "te") == 0);
	assert(strcmp(c.c_str(), "te") == 0);
try
	{
		a[0] = '1';
		assert(a[0] == '1');
		assert(a[0] != b[0]);
		assert(a[0] != c[0]);
	}
catch(...)
	{
		printf("out of range\n");
	}

try
	{
		a[-1] = '1';
	}
catch(...)
	{
		printf("out of range, index is negative\n");
	}

try
	{
		a[1000] = '1';
	}
catch(...)
	{
		printf("out of range, index greater than size\n");
	}
}
void test7(){
	qh::string a("test", 4);
	qh::string b = a;
	qh::string c(a);
	assert(a.size() == b.size());
	assert(a.size() == c.size());
	assert(b.size() == c.size());
	assert(a.size() == 4);
	assert(b.size() == 4);
	assert(c.size() == 4);
	assert(strcmp(a.data(), "test") == 0);
	assert(strcmp(b.data(), "test") == 0);
	assert(strcmp(c.data(), "test") == 0);
	assert(strcmp(a.c_str(), "test") == 0);
	assert(strcmp(b.c_str(), "test") == 0);
	assert(strcmp(c.c_str(), "test") == 0);
try
	{
		a[0] = '1';
		assert(a[0] == '1');
		assert(a[0] != b[0]);
		assert(a[0] != c[0]);
	}
catch(...)
	{
		printf("out of range\n");
	}

try
	{
		a[-1] = '1';
	}
catch(...)
	{
		printf("out of range, index is negative\n");
	}

try
	{
		a[1000] = '1';
	}
catch(...)
	{
		printf("out of range, index greater than size\n");
	}
}
void test8(){
	qh::string a("test", 0);
	qh::string b = a;
	qh::string c(a);
	assert(a.size() == b.size());
	assert(a.size() == c.size());
	assert(b.size() == c.size());
	assert(a.size() == 0);
	assert(b.size() == 0);
	assert(c.size() == 0);
	assert(a.data() == NULL);
	assert(b.data() == NULL);
	assert(c.data() == NULL);
	assert(a.c_str() == NULL);
	assert(b.c_str() == NULL);
	assert(c.c_str() == NULL);
try
	{
		a[0] = '1';
		assert(a[0] == '1');
		assert(a[0] != b[0]);
		assert(a[0] != c[0]);
	}
catch(...)
	{
		printf("out of range\n");
	}

try
	{
		a[-1] = '1';
	}
catch(...)
	{
		printf("out of range, index is negative\n");
	}

try
	{
		a[1000] = '1';
	}
catch(...)
	{
		printf("out of range, index greater than size\n");
	}

}
void test9(){
	qh::string a("test");
	qh::string b;
	b = a;
	assert(strcmp(a.data(), b.data()) == 0);
	a[0] = '1';
	assert(strcmp(a.data(), b.data()) != 0);
	assert(a[0] == '1');
	assert(b[0] == 't');
	assert(strcmp(a.data(), "1est") == 0);
	assert(strcmp(b.data(), "test") == 0);
}
void test10(){
	qh::string a("test");
	qh::string b;
	a = b;
	assert(a.data() == NULL);
	assert(b.data() == NULL);
	assert(a.size() == 0);
	assert(b.size() == 0);
	try
	{
		a[0] = '1';
	}
	catch(...)
	{
		printf("out of range\n");
	}

}

int main(int argc, char* argv[])
{

#ifdef WIN32
    system("pause");
#endif
	test1();
	test2();
	test3();
	test4();
	test5();
	test6();
	test7();
	test8();
	test9();
	test10();
	printf("all test OK!\n");
	return 0;
}

