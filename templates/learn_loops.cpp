//Source:https://en.cppreference.com/w/cpp/language/for
#include <iostream> //needed to print something on console

int main()
///FOR loop
//Executes init-statement once, then executes statement and iteration_expression repeatedly,
//until the value of condition becomes false.
//The test takes place before each iteration.

//formal syntax:
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

}

