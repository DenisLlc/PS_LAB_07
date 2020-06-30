#include "ComputerException.h"

class OutputException: public ComputerException{
    public:
        string message = "OutputException: Error en la salida de datos";
};