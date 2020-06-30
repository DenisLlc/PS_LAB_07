#include <iostream>
#include <exception>

using namespace std;

class Primer_coeficiente_cero: public exception{
    public:
        const char* what() const throw(){
            return "Primer coeficiente cero..";
        }
};