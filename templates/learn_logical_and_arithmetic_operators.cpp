
//Source:https://www.geeksforgeeks.org/operators-c-c/
#include <iostream>


int main()
{
///Logical Operators:

//Logical Operators are used to combine two or more conditions/constraints or to complement the evaluation of the original condition in consideration.
// The result of the operation of a logical operator is a boolean value either true or false.

//Relational operators:
//   < , <=	   Relational less than/less than or equal
//   > , >=	   Relational greater than/greater than
//   ==, !=	   Relational is equal to/is not equal to

//Example:
int a = 2, b = 44;
if(a > b)
    {
        std::cout << "a is greater than b";
    }
else if(a < b)
     {
        std::cout << "b is greater than a";
     }
else
    {
        std::cout << "a is equal to b";
    }
std::cout << std::endl;


//Logical AND operator

//Logical AND	represented as ‘&&’ operator in  C++ returns true when both the conditions under consideration are satisfied
int foo1{1};
int foo2{2};
int foo3{3}, foo4{4};
if(foo1 < foo2 && foo3 < foo4)
    {
        std::cout << "Both conditions are satisfied";
    }
std::cout << std::endl;

//Logical OR operator: The ‘||’ operator returns true even if one (or both) of the conditions under consideration is satisfied. Otherwise it returns false.
if(foo1 > foo2 || foo3 > foo4) //only second condition is satisfied in this case
 {
     std::cout << "At least one condition is true";
 }
else
{
    std::cout << "None of the conditions are true";
}
std::cout << std::endl;

//Logical NOT operator: The ‘!’ operator returns true the condition in consideration is not satisfied.
//Otherwise it returns false.
//For example:
bool bb = false;
if(!bb) //if bb is false
    {
        std::cout << "bb is false";
    }
std::cout << std::endl;
//another example using previous variables
if(!(foo1 < foo2 && foo2 > foo3)) //second condition is false so whole condition is not satisfied
{
    std::cout << "At least one condition is false";
}
std::cout << std::endl;


///Arithmetic operators
//Source: https://en.cppreference.com/w/cpp/language/operator_arithmetic
//Source: http://www.informit.com/articles/article.aspx?p=352857&seqNum=4

// C++'s five basic arithmetic operators:

//The '+' operator adds its operands.
int c = 2, d = 4;
int e = c + d;
std::cout <<  e << std::endl;

//The '-' operator subtracts the second operand from the first.
int f = e - 1;
std::cout <<  f << std::endl;

//The '*' operator multiplies its operands.
std::cout << f * c << std::endl;

//The '/' operator divides its first operand by the second.
std::cout << f / c << std::endl;


//The '%' operator finds the modulus of its first operand with respect to the second.
//That is, it produces the remainder of dividing the first by the second.

std::cout << 25 % d << std::endl; // is 1 because value of d = 4 and  goes into 25 six times, with a remainder of 1.
// Both operands must be integer types; using the '%' operator with floating-point values causes a compile-time error.

// operator '%' is often used in loops
for(int i = 0; i < 100 ;i++)
{

    if(i % 11)// if this expression evolves to false(when i = 0, i = 11, i = 22 etc) print new line
        {
           std::cout << '*';
        }
    else
        {
             std::cout << std::endl; //..print new line
        }

}

}

