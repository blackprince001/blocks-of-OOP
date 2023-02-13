# Notes for Classes and Functions

All examples with code and comments highlighted in the directory `./lessons`

[Link to code Examples for Classes](/lessons/classes.cpp)

[Link to code Examples for Functions](/lessons/functions.cpp)

## Variables

> local and global variables. local variables when initialized, get assigned some random values which unlike the case in global ones are assigned ZEROS.
> so it is better to assign null or ZEROS to your integral initialized or objects. `local` and `function arguments` (if not referenced) are stored on the `stack` while `global` and `static variables` are stored on the `heap` even if the static variable is declared in a local scope.

Scope:
>Variables possess a characteristic called the storage class - `storage class is how long a variable persists in memory or it's lifetime`. The most common storage class is automatic. Local variables have the automatic storage class: they exist only while the function in which they are defined is executing. They are also visible only within that function. Global variables have static storage class: they exist for the life of a program. They are also visible throughout an entire file. This is why it is preferred for you to make your global variables `const`. Static local variables exist for the life of a program but are visible only in their own function.

## Functions

>Functions provide a way to help organize programs, and to reduce program size, by giving a block of code a name and allowing it to be executed from other parts of the program. Function declarations (prototypes) specify what the function looks like, function calls transfer control to the function, and function definitions contain the statements that make up the function. The function declarator is the first line of the definition.

Functions with Arguments:
>Arguments can be sent to functions either by value, where the function works with a copy of the argument, or by reference, where the function works with the original argument in the call- ing program.

Default Arguments:
>If a function uses default arguments, calls to it need not include all the arguments shown in the declaration. Default values supplied by the function are used for the missing arguments.

Typed functions:
>Functions can return only one value. Functions ordinarily return by value, but they can also return by reference, which allows the function call to be used on the left side of an assignment statement. Arguments and return values can be either simple data types or structures. (BY REFERENCE EXPLANATION INSERTED HERE)

Overloading Functions:
>An overloaded function is actually a group of functions with the same name. Which of them is executed when the function is called depends on the type and number of arguments supplied in the call.

The inline Keyword:
>An inline function looks like a normal function in the source file but inserts the function’s code directly into the calling program. Inline functions execute faster but may require more memory than normal functions unless they are very small.

The const Keyword in function arguments:
>A function cannot modify any of its arguments that are given the const modifier. A variable
already defined as const in the calling program must be passed as a const argument.

## Classes and Structs

Class definition:
>A class is a specification or blueprint for a number of objects. Objects consist of both data and functions that operate on that data. In a class definition, the members—whether data or functions— can be private, meaning they can be accessed only by member functions of that class, or public, meaning they can be accessed by any function in the program.

Member functions or Methods:
>A member function is a function that is a member of a class. Member functions have access to an object’s private data, while non-member functions do not.

Constructors & constructor overloading:
>A constructor is a member function, with the same name as its class, that is executed every time an object of the class is created. A constructor has no return type but can take arguments. It is often used to give initial values to object data members. Constructors can be overloaded, so an object can be initialized in different ways. **we cannot use default arguments to make constructors**

Destructor:
>A destructor is a member function with the same name as its class but preceded by a tilde (~). It is called when an object is destroyed. A destructor takes no arguments and has no return value.

Shared attributes of a class with Static:
>In the computer’s memory there is a separate copy of the data members for each object that is created from a class, but there is only one copy of a class’s member functions. You can restrict a data item to a single instance for all objects of a class by making it static.

Modelling the world with OOP:
>One reason to use OOP is the close correspondence between real-world objects and OOP classes. Deciding what objects and classes to use in a program can be complicated. For small programs, trial and error may be sufficient. For large programs, a more systematic approach is usually needed.
