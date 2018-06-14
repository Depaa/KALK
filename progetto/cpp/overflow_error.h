#ifndef OVERFLOW_ERROR_H
#define OVERFLOW_ERROR_H
//#include<exception>
#include<stdexcept>
#include<iostream>

/*
So, <exception> only defines the class std::exception,
while <stdexcept> defines several classes that inherit from std::exception (e.g., std::logic_error, std::out_of_range).
That is why <stdexcept> includes <exception>.
*/


using std::exception;

class overflow_error : public exception {
    public:
        overflow_error();

        virtual const char* what() const throw();
};

#endif // OVERFLOW_ERROR_H
