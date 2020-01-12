
//Source: https://en.cppreference.com/w/cpp/keyword
#include <iostream>
#include <typeinfo> // needed to use typeid
int main()
{
///None of these kaywords below can be used to name your variables, function etc.
//alignas (since C++11)
//alignof (since C++11)
//and
//and_eq
//asm
//atomic_cancel (TM TS)
//atomic_commit (TM TS)
//atomic_noexcept (TM TS)
//auto (since C++11)
//bitand
//bitor
//bool
//break
//case
//catch
//char
//char8_t (since C++20)
//char16_t (since C++11)
//char32_t (since C++11)
//class
//compl
//concept (since C++20)
//const
//consteval (since C++20)
//constexpr (since C++11)
//constinit (since C++20)
//const_cast
//continue
//co_await (since C++20)
//co_return (since C++20)
//co_yield (since C++20)
//decltype (since C++11)
//default(1)
//delete(1)
//do
//double
//dynamic_cast
//else
//enum
//explicit
//export(1)(3)
//extern(1)
//false
//float
//for
//friend
//goto
//if
//inline
//int
//long
//mutable
//namespace
//new
//noexcept (since C++11)
//not
//not_eq
//nullptr (since C++11)
//operator
//or
//or_eq
//private
//protected
//public
//reflexpr (reflection TS)
//register(2)
//reinterpret_cast
//requires (since C++20)
//return
//short
//signed
//sizeof
//static
//static_assert (since C++11)
//static_cast
//struct(1)
//switch
//synchronized (TM TS)
//template
//this
//thread_local (since C++11)
//throw
//true
//try
//typedef
//typeid
//typename
//union
//unsigned
//using
//virtual
//void
//volatile
//wchar_t
//while
//xor
//xor_eq

//example of using 'auto' keyword(detection of type when initializing
auto   pi = 3.1415; // pi is type double because  '3.1415' literal is double used to initialization
std::cout << typeid(pi).name(); //  pi is type double( 'd' stands for double)
}

