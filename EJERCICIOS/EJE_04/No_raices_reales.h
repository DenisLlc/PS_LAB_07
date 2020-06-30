#include <iostream>
#include <exception>

using namespace std;

class No_raices_reales: public exception{
    public:
        const char* what() const throw(){
            return "No tiene raices reales..";
        }
};