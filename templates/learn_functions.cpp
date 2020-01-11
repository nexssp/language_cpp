//Source:http://www.cplusplus.com/doc/tutorial/functions/
#include <iostream> //needed to print something on console
void fun_area_of_circle(int radius)
{
    std::cout << "Area of circle: " << 3.1415 * radius * radius;
    return;
}
void addition(int &h) // h is reference of type int object, reference = "nickname"
{
     h = h + 100;
}

int main() //every C++ program has to have main function
{
//Functions allow to structure programs in segments of code to perform individual tasks.
//In C++, a function is a group of statements that is given a name, and which can be called from some point of the program.
//The most common syntax to define a function is:
//  type name ( parameter1, parameter2, ...) { statements }
//Where:
//- type is the type of the value returned by the function.
//- name is the identifier by which the function can be called.
//- parameters (as many as needed): Each parameter consists of a type followed by an identifier.
//- statements is the function's body. It is a block of statements surrounded by braces { } that specify what the function actually does.

//Let's have a look at an example:
//void fun_area_of_circle(int radius) // radius is a parameter of the function
//{
//    std::cout << " Area of circle: " << 3.1415 * radius * radius;
//}

//NOTE:
//The definition of function has to be done outside of any  function(we are in the main function now)
//So function is taken in comments to compile program//Original value var would not changed !!
//Due to we are now in the main function so function's definition is at the beginning of the file after header files
int rad;
std::cout << "Provide radius value: ";
std::cin  >> rad;
fun_area_of_circle(rad);// calling function fun_area_of_circle(rad is argument of the  function call)
//The difference between parameters and arguments is:
//-parameters are in function definition or declaration
//-arguments are in function call


//You can pass arguments by reference or value
//Passing by reference means the called functions' parameter will be the same as the callers' passed argument
//(not the value, but the identity - the variable itself)

//For example:
//lets define variable
int var = 10;

std::cout << std::endl << std::endl << "Object var contains value: " << var << std::endl;
//definition of function below:
//void addition(int &h) // h is reference of type int object, reference = "nickname"
//{
//    h = h + 100;
//}
//NOTE:
//The definition of function has to be done outside of any  function(we are in the main function now)
//So function is taken in comments to compile program
//We are now in the main function so function's definition is at the beginning of the file after header files

addition(var);

std::cout << std::endl << "After passing to function object var changed \nnow contains value: " << var << std::endl;

//if parameter of the addition function was passed by value(without &) as below:
//Original value var would not changed !!
//void addition(int h) // h is objectof type int object NOT reference
//{
//    h = h + 100;
//}

}


