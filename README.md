Week 4 Problem Set
==================

Generic printing function
-------------------------

Write a (templated) function that takes in an std::vector containing any type, and
then loops over it and prints all the contents, with each element of the vector
on its own line.


Overloading the stream insertion operator
-----------------------------------------

In C++, you can overload the stream insertion operator (`<<`). You can do
this by writing a function that takes in two arguments, one being the output
stream object, and the second argument being what is going to be inserted. In
this case, the first argument is a generic `std::ostream` (output stream)
object, and the second is what you want to print.

We will cover streams in a little more detail in Week 5. However, we will just
say now that `std::cout` is a type of `std::ostream`. Therefore, by overloading
this operator we can say `std::cout << vec`.

The function should return the `std::ostream` object that was passed in. This
is what allows chaining calls to the operator `<<`. Of course, this function
can be templated!


    std::ostream & operator<<(std::ostream & os, ...)
    {
        return os;
    }



