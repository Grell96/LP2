#include "String.h"

String::String () 
{
    length = 0;
    data   = new char[0];
}

String::String (char c) 
{
    length = 1;
    data   = new char(c);
}

String::String (const char* c) 
{
    if (c) 
    {
        int n = 0;
        while (c[n] != '\0') n++;
        length = n;
        data   = new char[n];
        for (int j=0; j < n; j++)
            data[j] = c[j];
    } else 
    {
        length = 0;
        data   = new char[0];
    }
}

String::String (const String& s) 
{
    length = s.len();
    data   = new char[length];
    for (int j=0; j < length; j++)
        data[j] = s[j];
}



String::~String ( ) 
{
    delete[] data;
}



int String::len ( ) const 
{
    return length;
}

String String::index() 
{
    String aux;
    int a;
    cout<<endl<<"ingrese indices, y luego -1"<<endl;
    while(1){
        cin>>a;
        if (a<0 or a>=length)break;
        }
    return aux;
}
ostream& operator<< (ostream& os, const String& s) 
{
    if (s.len() > 0) 
    {
        for (int j=0; j < s.len(); j++)
            os << s[j];
    } else os << "";

    return os;
}
char String::operator[] (int j) const 
{
    if (j >= length) throw 1;
    return data[j];
}

char& String::operator[] (int j) 
{
    if (j >= length) throw 1;
    return data[j];
}
String& String::operator= (const String& s) 
{
    if(this == &s) return *this;

    delete data;
    length = s.len();
    data   = new char[length];
    for (int j=0; j < length; j++)
        data[j] = s[j];
    return *this;
}

String operator+ (const String& lhs, const String& rhs) 
{
    return String(lhs)+= rhs;
}

String operator+ (const String& lhs, char rhs) 
{
    return String(lhs) += String(rhs);
}

String operator+ (const String& lhs, const char* rhs) 
{
    return String(lhs) += String(rhs);
}

String operator+ (char lhs, const String& rhs) 
{
    return String(lhs) += rhs;
}
String operator+ (const char* lhs, const String& rhs) 
{
    return String(lhs) += rhs;
}
String& String::operator+= (const String& s) 
{
    int len = length + s.len();
    char*    str = new char[len];

    for (int j=0; j < length; j++)
        str[j] = data[j];

    for (int i=0; i < s.len(); i++)
        str[length+i] = s[i];

    delete data;
    length = len;
    data   = str;
    return *this;    
}




