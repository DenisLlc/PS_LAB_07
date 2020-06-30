#include "ComputerException.h"

class ProcessorException: public ComputerException{
    public:
        string message = "ProcessorException: Error en el procesamiento";
};