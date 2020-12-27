/***********************
Class String
***********************/
#include<iostream>
#include<cstring>
#include<vector>
using namespace std;
class Mystring
{
    friend istream &operator>>(istream &is,const Mystring & str);//implementing as global f
    friend ostream &operator<<(ostream &os,const Mystring & str);
private:
     static int count_ ;
     char* s;
     size_t size;
public :
    void get_count()
    {
        cout<< "Number of string declared : " << count_ <<endl;
    }
    Mystring();//no_args constructor
    Mystring(char * str);// parameterized constructor
    Mystring(const Mystring & rhs);//copy constructor
    Mystring( Mystring &&source);//Move constructor
    Mystring operator+(const Mystring & rhs);//Overloaded addition operator
    Mystring& operator++();//overloaded uniary operator(Pre-increment operator)
    Mystring operator++(int);//overloading the uniary (post - increment operator)
    Mystring&operator=(const Mystring &rhs);//copy assignment
    Mystring&operator=(Mystring &&rhs);//Move assignment
    bool operator==(const Mystring & rhs);//equality
    bool operator<(const Mystring & rhs);//less than
    bool operator>(const Mystring & rhs);//greater than
    Mystring&operator+=(const Mystring & rhs);//increment operator
    Mystring operator*(int x);//String multiplier
    Mystring& operator*=(int x);
    size_t lenght();//return the size of the string
    ~Mystring();//destructor
};
int Mystring :: count_ = 0;
//n0-args constructor
Mystring :: Mystring() : Mystring{nullptr} {
    //cout << "No-args constructor called " << endl;
}
// parameterized constructor
Mystring :: Mystring(char * str) : s{nullptr} {
    //cout << "Argumented constructor called" << endl;
    count_ ++;
    if(str == nullptr){
        size = 0;

        s = new char [size + 1];
        *s = '\0';
    }
    else{
        size = strlen(str) ;
        s = new char [size + 1];
        strcpy(s,str);
    }
}
//copy constructor
Mystring::Mystring(const Mystring & rhs)  : s{nullptr} {
   // cout << "Copy Constructor called" << endl;
    size = rhs.size;
    s = new char [size + 1];
    strcpy(s,rhs.s);
}
//Move Constructor
Mystring :: Mystring ( Mystring &&source) : s(source.s), size(source.size) {
    source.s = nullptr;
    //cout << "Move Constructor called" << endl;
}
//Copy Assignment
Mystring &Mystring::operator=(const Mystring &rhs) {
    //cout << "Using Copy assignment" << endl;
    if (this == &rhs)
        return *this;
    delete [] this->s;
    size  = rhs.size;
    s = new char[size + 1];
    strcpy(this->s, rhs.s);
    return *this;
}
//Move assignment operator
Mystring &Mystring::operator=(Mystring &&rhs) {
    //std::cout << "Using move assignment" << std::endl;
    if (this == &rhs)
        return *this;
    delete [] s;
    size = rhs.size;
    s = rhs.s;
    rhs.s = nullptr;
    return *this;
}
//overloaded equality operator
bool Mystring::operator==(const Mystring & rhs) {
    return(strcmp(this->s,rhs.s) == 0);
}
//overloaded greater then operator
bool Mystring::operator<(const Mystring & rhs) {
    return(strcmp(this->s,rhs.s) < 0);
}
//overloading the less than operator
bool Mystring::operator>(const Mystring & rhs){
    return(strcmp(this->s,rhs.s) > 0);
}
//overloaded uniarya operator
Mystring& Mystring :: operator++(){
    *this += *this;
    return *this;
}
Mystring Mystring :: operator++(int){
    Mystring temp (*this);
    operator++();
    return temp;
}
//overloaded addition operation for string concatination
Mystring Mystring::operator+(const Mystring &rhs){
    char *buff = new char [strlen(s) + strlen(rhs.s) + 1];
    strcpy(buff,s);
    strcat(buff,rhs.s);
    Mystring temp{buff};
    delete [] buff;
    return temp;
}
//increment string operation of the string
Mystring&Mystring::operator+=(const Mystring & rhs){
    *this = *this + rhs;
    return *this;
}
// String multiplier (i.e increasing the string number of given times)
Mystring Mystring::operator*(int x){
    /*Mystring temp ;
    for(int i = 1;i<x;i++){
       temp = temp + *this;
    }
    return temp;*/
    size_t buff_size = std::strlen(s) * x + 1;
    char *buff = new char[buff_size];
    strcpy(buff, "");
    for (int i =1; i <=x; i++)
        strcat(buff, s);
    Mystring temp{buff};
    delete [] buff;
    return temp;
}
//String increment self assignment
Mystring& Mystring :: operator*=(int x){
    *this = *this * x;
    return *this;
}
//function will return the size of the string that has just made the call
size_t Mystring :: lenght(){
    return size;
}
//overloaded extraction operator implemented as the friend function
ostream &operator<<(ostream &os,const Mystring & str){
    os << str.s;
    return os;
}
 //overloaded insertion operator ----------||----------
 istream &operator>>(istream &is, Mystring & str){
    char *buff = new char [100];
    is >> buff;
    str = Mystring{buff};
    delete [] buff;
    return is;
 }
//Destructor
Mystring :: ~Mystring(){
    count_--;
    delete [] s;
}
int main()
{
    Mystring s1,s2,s3;
    s3.get_count();
    cout<<"Enter two space seperated string : ";
    cin >> s1 >> s2;
    if(s1 == s2){
        cout << "The string " << s1 <<" and string " << s2 << " are equal." <<endl;
    }
    else{
        cout << "The string " << s1 <<" and string " << s2 << " are not-equal." <<endl;
    }
    cout << endl;
    if(s1 < s2) {
        cout << "The string " << s1 << " is shorter than " << s2 << endl;
    }
    else{
        cout << "The string " << s1 << " is longer than " << s2 << endl;
    }
    cout << endl;
    if(s1 > s2) {
        cout << "The string " << s1 << " is longer than " << s2 << endl;
    }
    else{
        cout << "The string " << s1 << " is shorter than " << s2 << endl;
    }
    cout << endl;
    s3 = s1 + s2;
    cout<<"Concatenated string : " << s3 << endl;
    cout << "s1 : " << s1 << endl;
    cout << "s2 : " << s2 << endl;
    s2 *= 3;
    cout << s2 << endl;
    cout << "overloaded unary operator (pre-increment) :  " << ++s2 << endl;
    cout << "Overloaded unary operator (post-increment) : " << s2++ << endl;
    cout << s2 << endl;
    return 0;
}
