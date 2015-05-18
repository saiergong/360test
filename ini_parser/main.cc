#include "ini_parser.h"

#include <string.h>
#include <assert.h>

void test1()
{
    const char* ini_text= "a=1\nb=2\n"; 
    qh::INIParser parser;
    if (!parser.Parse(ini_text, strlen(ini_text), "\n", "=")) {
        assert(false);
    }

    const std::string& a = parser.Get("a", NULL);
    assert(a == "1");

    std::string b = parser.Get("b", NULL);
    assert(b == "2");

    const std::string& c = parser.Get("c", NULL);
    assert(c == "");
}

void test2()
{
    const char* ini_text= "a=1||b=2||c=3"; 
    qh::INIParser parser;
    if (!parser.Parse(ini_text, strlen(ini_text), "||", "=")) {
        assert(false);
    }

    const std::string& a = parser.Get("a", NULL);
    assert(a == "1");

    std::string b = parser.Get("b", NULL);
    assert(b == "2");

    const std::string& c = parser.Get("c", NULL);
    assert(c == "3");
}

void test3()
{
    const char* ini_text= "||||a:1||b:2||||c:3||||||"; 
    qh::INIParser parser;
    if (!parser.Parse(ini_text, strlen(ini_text), "||", ":")) {
        assert(false);
    }

    const std::string& a = parser.Get("a", NULL);
    assert(a == "1");

    std::string b = parser.Get("b", NULL);
    assert(b == "2");

    const std::string& c = parser.Get("c", NULL);
    assert(c == "3");
}

void test4()
{
    const char* ini_text= "a=1\nb=2\na=2\n"; 
    qh::INIParser parser;
    if (!parser.Parse(ini_text, strlen(ini_text), "\n", "=")) {
        assert(false);
    }

    const std::string& a = parser.Get("a", NULL);
    assert(a == "2");

    std::string b = parser.Get("b", NULL);
    assert(b == "2");

    const std::string& c = parser.Get("c", NULL);
    assert(c == "");
}

void test5()
{
    const char* ini_text= "b=1\nb=2\n"; 
    qh::INIParser parser;
    if (!parser.Parse(ini_text, strlen(ini_text), "\n", "=")) {
        assert(false);
    }

    const std::string& a = parser.Get("a", NULL);
    assert(a == "");

    std::string b = parser.Get("b", NULL);
    assert(b == "2");

    const std::string& c = parser.Get("c", NULL);
    assert(c == "");
}

void test6()
{
    const char* ini_text= "\n\na=1\nb=2\nc=2\na=2\n=\b=\n"; 
    qh::INIParser parser;
    if (!parser.Parse(ini_text, strlen(ini_text), "\n", "=")) {
        assert(false);
    }

    const std::string& a = parser.Get("a", NULL);
    assert(a == "2");

    std::string b = parser.Get("b", NULL);
    assert(b == "2");

    const std::string& c = parser.Get("c", NULL);
    assert(c == "2");
}

void unittest10(){
    const char* file = "unittest10.txt";
    qh::INIParser parser;
    if(!parser.Parse(file))
	assert(false);

    const std::string &a = parser.Get("a", NULL);
    assert(a == "1");

    const std::string &b = parser.Get("b", NULL);
    assert(b == "2");

    const std::string &c = parser.Get("c", NULL);
    assert(c == "");	
}

void unittest9(){
    const char* file = "unittest9.txt";
    qh::INIParser parser;
    if(!parser.Parse(file))
	assert(false);

    const std::string &a = parser.Get("my", NULL);
    assert(a == "swq");

    const std::string &b = parser.Get("hello", NULL);
    assert(b == "");

    const std::string &c = parser.Get("c", NULL);
    assert(c == "");	
}

void unittest1(){
    const char* file = "unittest1.txt";
    qh::INIParser parser;
    if(!parser.Parse(file))
	assert(false);

    const std::string &a = parser.Get("a", NULL);
    assert(a == "1");

    const std::string &b = parser.Get("b", NULL);
    assert(b == "");

    const std::string &c = parser.Get("c", NULL);
    assert(c == "2");	
}


void unittest2(){
    const char* file = "unittest2.txt";
    qh::INIParser parser;
    if(!parser.Parse(file))
	assert(false);

    const std::string &a = parser.Get("a", NULL);
    assert(a == "");

    const std::string &b = parser.Get("b", NULL);
    assert(b == "1");

    const std::string &c = parser.Get("c", NULL);
    assert(c == "2");	
}


void unittest3(){
    const char* file = "unittest3.txt";
    qh::INIParser parser;
    if(!parser.Parse(file))
	assert(false);

    const std::string &a = parser.Get("a", NULL);
    assert(a == "1");

    const std::string &b = parser.Get("b", NULL);
    assert(b == "");

    const std::string &c = parser.Get("c", NULL);
    assert(c == "");	
}

void unittest4(){
    const char* file = "unittest4.txt";
    qh::INIParser parser;
    if(!parser.Parse(file))
	assert(false);

    const std::string &a = parser.Get("a", NULL);
    assert(a == "");

    const std::string &b = parser.Get("b", NULL);
    assert(b == "");

    const std::string &c = parser.Get("c", NULL);
    assert(c == "");	
}

void unittest5(){
    const char* file = "unittest5.txt";
    qh::INIParser parser;
    if(!parser.Parse(file))
	assert(false);

    const std::string &a = parser.Get("abc", NULL);
    assert(a == "123");

    const std::string &b = parser.Get("cde", NULL);
    assert(b == "456");

    const std::string &c = parser.Get("c", NULL);
    assert(c == "");	
}

void unittest6(){
    const char* file = "unittest6.txt";
    qh::INIParser parser;
    if(!parser.Parse(file))
	assert(false);

    const std::string &a = parser.Get("a", NULL);
    assert(a == "");

    const std::string &b = parser.Get("b", NULL);
    assert(b == "");

    const std::string &c = parser.Get("c", NULL);
    assert(c == "");	
}

void unittest7(){
    const char* file = "unittest7.txt";
    qh::INIParser parser;
    if(!parser.Parse(file))
	assert(false);

    const std::string &a = parser.Get("a", NULL);
    assert(a == "");

    const std::string &b = parser.Get("b", NULL);
    assert(b == "1");

    const std::string &c = parser.Get("c", NULL);
    assert(c == "2");	
}

void unittest8(){
    const char* file = "unittest8.txt";
    qh::INIParser parser;
    if(!parser.Parse(file))
	assert(false);

    const std::string &a = parser.Get("a", NULL);
    assert(a == "1");

    const std::string &b = parser.Get("b", NULL);
    assert(b == "2");

    const std::string &c = parser.Get("c", NULL);
    assert(c == "3");	
}


void test7()
{
    const char* ini_text= "a=1\n\n\nb=2\n"; 
    qh::INIParser parser;
    if (!parser.Parse(ini_text, strlen(ini_text), "\n", "=")) {
        assert(false);
    }

    const std::string& a = parser.Get("a", NULL);
    assert(a == "1");

    std::string b = parser.Get("b", NULL);
    assert(b == "2");

    const std::string& c = parser.Get("c", NULL);
    assert(c == "");
}

void test8()
{
    const char* ini_text= "\n\n\na=1\n\n\nb=2\n\n\n\n"; 
    qh::INIParser parser;
    if (!parser.Parse(ini_text, strlen(ini_text), "\n", "=")) {
        assert(false);
    }

    const std::string& a = parser.Get("a", NULL);
    assert(a == "1");

    std::string b = parser.Get("b", NULL);
    assert(b == "2");

    const std::string& c = parser.Get("c", NULL);
    assert(c == "");
}

void test9()
{
    const char* ini_text= "xn\na=1\nfjdkfjd\nb=2\nc=3"; 
    qh::INIParser parser;
    if (!parser.Parse(ini_text, strlen(ini_text), "\n", "=")) {
        assert(false);
    }

    const std::string& a = parser.Get("a", NULL);
    assert(a == "1");

    std::string b = parser.Get("b", NULL);
    assert(b == "2");

    const std::string& c = parser.Get("c", NULL);
    assert(c == "3");
}


void test10()
{
    const char* ini_text= "a=1testb=2testc=3"; 
    qh::INIParser parser;
    if (!parser.Parse(ini_text, strlen(ini_text), "test", "=")) {
        assert(false);
    }

    const std::string& a = parser.Get("a", NULL);
    assert(a == "1");

    std::string b = parser.Get("b", NULL);
    assert(b == "2");

    const std::string& c = parser.Get("c", NULL);
    assert(c == "3");
}


void test11()
{
    const char* ini_text= "a:1testb:2testc:3"; 
    qh::INIParser parser;
    if (!parser.Parse(ini_text, strlen(ini_text), "test", ":")) {
        assert(false);
    }

    const std::string& a = parser.Get("a", NULL);
    assert(a == "1");

    std::string b = parser.Get("b", NULL);
    assert(b == "2");

    const std::string& c = parser.Get("c", NULL);
    assert(c == "3");
}

void test12()
{
    const char* ini_text= "a:testb:2testc:"; 
    qh::INIParser parser;
    if (!parser.Parse(ini_text, strlen(ini_text), "test", ":")) {
        assert(false);
    }

    const std::string& a = parser.Get("a", NULL);
    assert(a == "");

    std::string b = parser.Get("b", NULL);
    assert(b == "2");

    const std::string& c = parser.Get("c", NULL);
    assert(c == "");
}



void test13()
{
    const char* ini_text= ":1testb:2test:"; 
    qh::INIParser parser;
    if (!parser.Parse(ini_text, strlen(ini_text), "test", ":")) {
        assert(false);
    }

    const std::string& a = parser.Get("a", NULL);
    assert(a == "");

    std::string b = parser.Get("b", NULL);
    assert(b == "2");

    const std::string& c = parser.Get("c", NULL);
    assert(c == "");
}



int main(int argc, char* argv[])
{

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
    test11();
    test12();
    test13();


    unittest1();
    unittest2();
    unittest3();
    unittest4();
    unittest5();
    unittest6();
    unittest7();
    unittest8();
    unittest9();
    unittest10();
    return 0;
}


