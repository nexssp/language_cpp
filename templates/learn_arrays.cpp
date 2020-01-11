#include <iostream> //needed to print something on console
#include <vector>

//Source: http://www.cplusplus.com/doc/tutorial/arrays/
int main() //every C++ program has to have main function
{
//List of operators that enable creating compound types in C++

///[] - ARRAY OF OBJECTS
//For example:
int a[100]; //a is an array of 100 objects (each is int type)
// What is the type of array? Answer: array to store elements each int type
//a is NOT int type

//An array is a series of elements of the same type placed in contiguous memory locations
//that can be individually referenced by adding an index to a unique identifier.
//For example, an array containing 5 integer values of type int called foo could be represented as:
int foo[5];
//These elements are numbered from 0 to 4, being 0 the first and 4 the last;
//In C++, the first element in an array is always numbered with a zero (not a one), no matter its length.
//Like a regular variable, an array must be declared before it is used. A typical declaration for an array in C++ is:
// type name [elements];
//where type is a valid type (such as int, float...),
// name is a valid identifier and the elements field (which is always enclosed in square brackets []),
// specifies the length of the array in terms of the number of elements.
//NOTE: The elements field within square brackets [], representing the number of elements in the array, must be a constant expression,
//since arrays are blocks of static memory whose size must be determined at compile time (before the program runs).

//Initializing arrays
//By default, regular arrays of local scope (for example, those declared within a function) are left uninitialized.
//This means that none of its elements are set to any particular value;
//their contents are undetermined at the point the array is declared.
//But the elements in an array can be explicitly initialized to specific values when it is declared,
// by enclosing those initial values in braces {}. For example:
int foo1 [5] = {16, 2, 77, 40, 12071 };
//in C++ we counting  from 0, so we last element has got 4 index(in this case foo1[4]
std::cout << foo1[0] << std::endl;// prints first element of the array,
//The number of values between braces {} shall not be greater than the number of elements in the array.
//For example, in the example above, foo1 was declared having 5 elements (as specified by the number enclosed in square brackets, []),
// and the braces {} contained exactly 5 values, one for each element.
//If declared with less, the remaining elements are set to their default values (which for fundamental types, means they are filled with zeroes). For example:
int bar [5] = { 10, 20, 30 };
//When an initialization of values is provided for an array, C++ allows the possibility of leaving the square brackets empty [].
//In this case, the compiler will assume automatically a size for the array that matches the number of values included between the braces {}:
int foo2 [] = { 16, 2, 77, 40, 12071 };
//After this declaration, array foo2 would be 5 int long, since we have provided 5 initialization values.
//Finally, the evolution of C++ has led to the adoption of universal initialization also for arrays.
//Therefore, there is no longer need for the equal sign between the declaration and the initializer.
// Both these statements are equivalent:
int foo3[] = { 10, 20, 30 };
int foo4[] { 10, 20, 30 };

///VECTORS
//Source: http://www.cplusplus.com/reference/vector/vector/
//Some says vectors are modern alternatives to the arrays.
//Defining vectors (you need to include header file <vector> )
std::vector<int>myvector; // this is empty vector
myvector.push_back(1);//first element added
myvector.push_back(2);//second element added
//the result is we have vectors of two elements first contains value of 1, second contains value of 2
std::cout << "First element of myvector contains: " << myvector[0] << std::endl;
std::cout << "Second element of myvector contains  : " << myvector[1] << std::endl;
//Vectors are sequence containers representing arrays that can change in size.
std::cout << "Current myvector size: " << myvector.size() << std::endl;
myvector.pop_back(); //removes last element
std::cout << "Current myvector size: " << myvector.size() << std::endl;
//Unlike arrays, their size can change dynamically, with their storage being handled automatically by the container.
//Internally, vectors use a dynamically allocated array to store their elements.
//This array may need to be reallocated in order to grow in size when new elements are inserted,
//which implies allocating a new array and moving all elements to it.
//This is a relatively expensive task in terms of processing time,
//and thus, vectors do not reallocate each time an element is added to the container.
//Instead, vector containers may allocate some extra storage to accommodate for possible growth,
//and thus the container may have an actual capacity greater than the storage strictly needed to contain its elements (i.e., its size).
std::cout << "Current myvector capacity: " << myvector.capacity() << std::endl; //capcity is greater then size
//Easy to understand:  capacity tells us how big is container but size tells us how many elements are in the container
//capacity is related to the container
//size is related to container's content(what's inside)

//Therefore, compared to arrays, vectors consume more memory in exchange
//for the ability to manage storage and grow dynamically in an efficient way.
//Compared to the other dynamic sequence containers (deques, lists and forward_lists),
//vectors are very efficient accessing its elements (just like arrays) and relatively efficient adding or removing elements from its end.
//This is very important due to C++ is used to make high performance apps such as AAA games.

}

