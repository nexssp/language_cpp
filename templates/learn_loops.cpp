//Source:https://en.cppreference.com/w/cpp/language/for
#include <iostream> //needed to print something on console
#include <vector>

int main()
{
///FOR loop
//Executes init-statement once, then executes statement and iteration_expression repeatedly,
//until the value of condition becomes false.
//The test takes place before each iteration.

//Formal syntax:
//for ( init-statement; condition(optional) ; iteration_expression(optional) ) {body}
//For example:
for(int i = 0; i < 10; i++)
{
    std::cout << i << std::endl;
}
std::cout << std::endl;
//While in C++, the scope of the init-statement and the scope of statement are one and the same,
// in C the scope of statement is nested within the scope of init-statement:
//for (int i = 0; i < 10 ; i++ )
//{
//      long i = 1;   // valid C, invalid C++ (same value names in same scope)
//}

///WHILE loop
//Source: https://en.cppreference.com/w/cpp/language/while
//Executes a statement repeatedly, until the value of condition becomes false. The test takes place before each iteration.
//Syntax:
// while ( condition ) {loop body(statement)}
//For example:
int i = 0;
while(i < 10)
{
    std::cout << i << std::endl;
    i++;
}
std::cout << std::endl;
//condition	-	any expression which is contextually convertible to bool
//statement	-	any statement, typically a compound statement, which is the body of the loop


///DO WHILE loop
//Source: https://en.cppreference.com/w/cpp/language/do

//Executes a statement repeatedly, until the value of condition becomes false. The test takes place before each iteration.
//NOTE:statement is always executed at least once, even if expression always yields false!
//If it should not execute in this case, a while or for loop may be used.

//Syntax:
// do {statement} while(condition);
//For example:
int j = 0;
do
{
    std::cout << j << std::endl;
    j++;
}while(j < 10);
std::cout << std::endl;
//condition	-	any expression which is contextually convertible to bool
//statement	-	any statement, typically a compound statement, which is the body of the loop


///Range Based FOR Loop (since C++11)
//Source: https://en.cppreference.com/w/cpp/language/range-for

//Range based for loop executes a for loop over a range.
//Used as a more readable equivalent to the traditional for loop operating over a range of values,
//such as all elements in a container(for example: std::vector).

std::vector<int>myvector;
myvector.push_back(0);
myvector.push_back(1);
myvector.push_back(2);
myvector.push_back(3);
myvector.push_back(4);
myvector.push_back(5);
myvector.push_back(6);
myvector.push_back(7);
myvector.push_back(8);
myvector.push_back(9);

//Syntax:
// for ( range_declaration : range_expression ) loop_statement

//range_declaration	- a declaration of a named variable, whose type is the type of the element of the sequence represented by range_expression.
//range_expression	- any expression that represents a suitable sequence (either an array or an object for which begin and end member functions.
//loop_statement	- any statement, typically a compound statement, which is the body of the loop.
for(int element: myvector)
    {
        std::cout << element << std::endl;
    }

}

