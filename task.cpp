#include <cstring> // string.h for some
#include<iostream>
using std::cout;
class StringBad
{
private:
    char * str;                // pointer to string
    int len;                   // length of string
    static int num_strings;    // number of objects
public:
    StringBad(const char * s); // constructor
    StringBad();               // default constructor
    ~StringBad();              // destructor
    void str_address();
    // friend function
    friend std::ostream & operator<<(std::ostream & os, 
                       const StringBad & st);
};
// initializing static class member
int StringBad::num_strings = 0;

// class methods

// construct StringBad from C string
StringBad::StringBad(const char *s)
{
    len = std::strlen(s);    // set size
    str = new char[len + 1]; // allot storage
    std::strcpy(str, s);     // initialize pointer
    num_strings++;           // set object count
    cout << num_strings << ": \"" << str
         << "\" object created\n"; // For Your Information
}
StringBad::StringBad() // default constructor
{
    len = 4;
    str = new char[4];
    std::strcpy(str, "C++"); // default string
    num_strings++;
    cout << num_strings << ": \"" << str
         << "\" default object created\n"; // FYI
}
StringBad::~StringBad() // necessary destructor
{
    cout << "\"" << str << "\" object deleted, "; // FYI
    --num_strings;                                // required
    cout << num_strings << " left\n";             // FYI
    delete[] str;                                 // required
}
/*std::ostream&   operator<<(std::ostream &os, const StringBad &st)
{
    os << st.str;
    return os;
}*/

void callByReference(StringBad &rsb)
{
    cout << "String passed by reference:\n";
    cout << "    \"" << rsb << "\"\n";
}
void callByValue(StringBad sb)
{
    cout << "String passed by value:\n";
    cout << "    \"" << sb << "\"\n";
}
using std::endl;
void StringBad::str_address()
{
    printf(" str地址为：%X\n",str);
}
int main()
{
    {
        cout << "///////////////////////////"<<endl;
        StringBad headline1("headline1");
        StringBad headline2("headline2");
        StringBad headline3("headline3");
        /*
        cout<<endl<<endl<<"打印"<<endl;
        callByReference(headline1);
        cout << headline1 << endl;
        callByValue(headline2);
        cout << headline2 << endl;
        cout<<"打印"<<endl<<endl<<endl;
        */
        cout<<endl;
        cout<<"headline1";
        headline1.str_address();
        cout<<"headline2";
        headline2.str_address();
        cout<<"headline1";
        headline3.str_address();
        cout<<endl;

        StringBad headline3Copy = headline3;
        cout << "headline3 copy: " << headline3Copy << endl;
        StringBad headline1Copy;
        headline1Copy = headline1;
        cout << "headline1 copy: " << headline1Copy << endl<<endl;

        cout<<"headline1";
        headline1.str_address();
        cout<<"headline2";
        headline2.str_address();
        cout<<"headline3";
        headline3.str_address();
        cout<<"headline3Copy";
        headline3Copy.str_address();
        cout<<"headline1Copy";
        headline1Copy.str_address();

        cout <<endl<< "///////////////////////////\n"<<endl;
    }
    cout<<"main is over"<<endl;
    return 0;
}
