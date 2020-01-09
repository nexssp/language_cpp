

//source: http://www.cplusplus.com/doc/tutorial/variables/

// C++ define variable as a portion of memory to store a value.
//Each variable needs a name that identifies it and distinguishes it from the other.
//Each variable needs a type.Type cannot be changed after declaration of variable.

///Basics fundamental types:

 //Character types: They can represent a single character, such as 'A' or '$'.
      //The most basic type is char, which is a one-byte character. Other types are also provided for wider characters.
     char z = 'z'; //creating object of fundamental type char and initializing it value of character "z"

 //Numerical integer types: They can store a whole number value, such as 7 or 1024.
     // They exist in a variety of sizes, and can either be signed or unsigned, depending on whether they support negative values or not.
     int k{};
     k = -100;
     int i = 44; // using initialization

 //Floating-point types: They can represent real values, such as 3.14 or 0.01, with different levels of precision, depending on which of the three floating-point types is used.
    double d = 3.1415;
    float f = 3.1415;

  //Bool type: The bool type can only represent one of two states, true or false.
   bool IsGameOver = false;
   IsGameOver = 1; // or IsGameOver = true;


///DECLARATION OF VARIABLES
 //C++ is a strongly-typed language, and requires every variable to be declared with its type before its first use.
  //This informs the compiler the size to reserve in memory for the variable and how to interpret its value.
   //The syntax to declare a new variable in C++ is straightforward: we simply write the type followed by the variable name (i.e., its identifier).
    //For example:
   int aaa;
   float mynumber;
   //These are two valid declarations of variables.
   //Once declared, the variables aaa and mynumber can be used within the rest of their scope in the program.

//If declaring more than one variable of the same type, they can all be declared in a single statement by separating their identifiers with commas.
  // For example:
  int a, b, c;

///INITIALIZATION OF VARIABLES
 //3 ways:
  int aa = 0;
  int bb{0};
  int cc(0);

///TYPE DEDUCTION: auto and decltype

 //When a new variable is initialized, the compiler can figure out what the type of the variable is automatically by the initializer.
  //For this, it suffices to use auto as the type specifier for the variable:
   int foo = 0;
   auto bar = foo;  // the same as: int bar = foo;
    //Here, bar is declared as having an auto type; therefore, the type of bar is the type of the value used to initialize it: in this case it uses the type of foo, which is int.

//Variables that are not initialized can also make use of type deduction with the decltype specifier:
  int fooo = 0;
  decltype(fooo) dar;  // the same as: int dar;
   //Here, bar is declared as having the same type as fooo.

/// STRINGS
//Fundamental types represent the most basic types handled by the machines where the code may run.
// But one of the major strengths of the C++ language is its rich set of compound types, of which the fundamental types are mere building blocks.
//An example of compound type is the string class.
//Variables of this type are able to store sequences of characters, such as words or sentences. A very useful feature!
//A first difference with fundamental data types is that in order to declare and use objects (variables) of this type,
 //the program needs to include the header where the type is defined within the standard library (header <string>):
//#include<string>

  string mystring;
  mystring = "This is a string";

//Strings can also perform all the other basic operations that fundamental data types can, like being declared without an initial value and change its value during execution:
  mystring = "This is the initial string content";
  mystring = "This is a different string content";




