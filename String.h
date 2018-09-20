#ifndef MYSTRING_H
#define MYSTRING_H

#include <iostream>
using namespace std;
class String
{
    char*    data;    
    int length;  

public:
    String ( );
    String (char c);
    String (const char* c);
    String (const String& s);
    ~String ( );
    int len ( ) const;
    String index ();
    friend ostream& operator<< (ostream& so, const String& s);
    char  operator[] (int j) const;
    char& operator[] (int j);
    String& operator= (const String& s);
    String& operator+= (const String& s);
    friend String operator+ (const String& lhs, const String& rhs);
    friend String operator+ (const String& lhs, char          rhs);
    friend String operator+ (const String& lhs, const char*   rhs);
    friend String operator+ (char          lhs, const String& rhs);
    friend String operator+ (const char*   lhs, const String& rhs);
};

#endif // MYSTRING_H
