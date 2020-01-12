//Source:https://www.tutorialspoint.com/cplusplus/cpp_if_else_statement.htm
#include <iostream>


int main()
{
///An if statement can be followed by an optional else statement, which executes when the boolean expression is false.

//Syntax:
//The syntax of an if...else statement in C++ is:

//if(boolean_expression)
//{
//  statement(s) will execute if the boolean expression is true
//}
//else
//{
  // statement(s) will execute if the boolean expression is false
//}

//when the boolean expression evaluates to true, then the if block of code will be executed,
//otherwise else block of code will be executed.

//For example:

bool isgameover = true; // for this exercise we assign value of true to the bool type variable called isgameover

if(isgameover == true) //checking if true
    {
       std::cout << "Game over!";
    }
else // optional
    {
       std::cout << "Game is NOT over!";
    }
std::cout << std::endl;

/// if else if   else - condition statement
//Similar to An if statement but can be followed by an optional else if...else statement,
//which is very usefull to test various conditions using single if...else if statement.

//When using if , else if , else statements there are few points to keep in mind.
//An if can have zero or one else's and it must come after any else if's.
//An if can have zero to many else if's and they must come before the else.

//Once an else if succeeds, none of he remaining else if's or else's will be tested.

//Syntax in example:

std::string  robotmovement = "left"; //value is "left" in this case

if(robotmovement == "stop")
    {
        std::cout << "Robot is stopping..";
    }
else if(robotmovement == "right")
    {
        std::cout << "Robot is moving right..";
    }
else if(robotmovement == "left")
    {
        std::cout << "Robot is moving left..";
    }
else //if none of the above  met
    {
        std::cout << "Unknown Command!";
    }

}

