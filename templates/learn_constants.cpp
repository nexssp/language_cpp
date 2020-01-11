#include <iostream> //needed to print something on console

//Source: https://www.tutorialspoint.com/cplusplus/cpp_constants_literals.htm
int main() //every C++ program has to have main function
{
const char c = 'y'; //definition of object c and initialization with value of character (y)
//Constants refer to fixed values that the program may not alter and they are called literals.
//We cannot change their values later on:For example:
//c = 'z'; //it's not allowed

//Constants can be of any of the basic data types and can be divided into:

//Integer Numerals:
const int n = -100;
const unsigned int un = 100;

//Floating-Point Numerals:
const double pi1 = 3.14159265359;
const float pi2 = 3.14159265359;

// Characters:
const char c1 = 'f';
const wchar_t c2 = 'v'; //wide character

//Strings:
const std::string mystring = "Hello";

//Boolean Values:
const bool isempty = true;

//or even compound types such as:
//Arrays:
const char myarray[10] = {'H','E','L','L','O'};
std::cout << myarray << std::endl; //printing content

//There are two keywords used to define and initialize constants variables:
//1. const used in above examples
//2. constexpr: used from C++11 standard
//The difference between those two is that first one(const) can be use to initialize variable while program is running
//For example:
int foo;
std::cout << "Provide value: ";
std::cin >> foo; // user provides value (while program is working!)
const int bar1  = foo;  //that's fine result object bar has got the same value as foo

//constexpr int bar2 = foo;   //but that's is not permitted
//Reason is the constexpr specifier declares that it is possible to evaluate the value of the function or variable at compile time.
//It wasn't in the case above because the value of object foo was assigned while program is running
//so we cannot use object foo(in this case) to assign to object with constexpr keyword
//We need to do it this way:
constexpr int foo1 = 999;
constexpr int bar2 = foo1;

//Again, constants are treated just like regular variables except that their values cannot be modified after their definition.

}

