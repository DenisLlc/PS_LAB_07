#include "ComputerException.h"

class InputException: public ComputerException{
    public:
        string message = "InputException: Error de entrada de datos";
};