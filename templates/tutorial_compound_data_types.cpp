
//Source: http://www.cplusplus.com/doc/tutorial/arrays/
///List of operators that enable creating compound types in C++

 ///[] - ARRAY OF OBJECTS
   //For example:
   int a[100]; // array of 100 objects (each is int type)
    // a is array of int type
      //NOT int type

//An array is a series of elements of the same type placed in contiguous memory locations that can be individually referenced by adding an index to a unique identifier.
//For example, an array containing 5 integer values of type int called foo could be represented as:
    int foo[5];

 //These elements are numbered from 0 to 4, being 0 the first and 4 the last;
 //In C++, the first element in an array is always numbered with a zero (not a one), no matter its length.
 //Like a regular variable, an array must be declared before it is used. A typical declaration for an array in C++ is:
  type name [elements];

//where type is a valid type (such as int, float...), name is a valid identifier and the elements field (which is always enclosed in square brackets []), specifies the length of the array in terms of the number of elements.
//NOTE: The elements field within square brackets [], representing the number of elements in the array, must be a constant expression,
   //since arrays are blocks of static memory whose size must be determined at compile time, before the program runs.

    ///Initializing arrays
//By default, regular arrays of local scope (for example, those declared within a function) are left uninitialized. This means that none of its elements are set to any particular value; their contents are undetermined at the point the array is declared.
//But the elements in an array can be explicitly initialized to specific values when it is declared, by enclosing those initial values in braces {}. For example:

int foo [5] = { 16, 2, 77, 40, 12071 };

//The number of values between braces {} shall not be greater than the number of elements in the array.
//For example, in the example above, foo was declared having 5 elements (as specified by the number enclosed in square brackets, []), and the braces {} contained exactly 5 values, one for each element.
//If declared with less, the remaining elements are set to their default values (which for fundamental types, means they are filled with zeroes). For example:
int bar [5] = { 10, 20, 30 };

//When an initialization of values is provided for an array, C++ allows the possibility of leaving the square brackets empty [].
//In this case, the compiler will assume automatically a size for the array that matches the number of values included between the braces {}:
int foo [] = { 16, 2, 77, 40, 12071 };
//After this declaration, array foo would be 5 int long, since we have provided 5 initialization values.

//Finally, the evolution of C++ has led to the adoption of universal initialization also for arrays.
//Therefore, there is no longer need for the equal sign between the declaration and the initializer.
// Both these statements are equivalent:

int foo[] = { 10, 20, 30 };
int foo[] { 10, 20, 30 };


/// POINTERS


