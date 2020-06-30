#include <iostream>
#include <math.h>

//Nuestras clases
#include "InputException.h"
#include "OutputException.h"
#include "ProcessorException.h"

using namespace std;

int main(){

    //Probar InputException: Lo lanzaremos si nuestro numero no
    //esta en el rango establecido por el programa 1-9
    int n;
    cout<<"Ingresa un numero entre 1 y 9: ";
    try{
        cin>>n;
        if(n < 1 || n > 9) throw InputException();
        cout<<"Numero "<<n<<" guardado con exito"<<endl;
    }catch(InputException &ie){
        cout<<ie.message<<endl;
    }

    //Probar ProcessorException: Para comprobar que no se intente
    //Sacar la raiz cuadrada de un numero negativo
    int n2;
    cout<<"Ingresa el numero para sacar la raiz: ";
    try{
        cin>>n2;
        if(n2 < 0) throw ProcessorException();
        cout<<"La raiz cuadrada de "<<n2<<" es "<<sqrt(n2)<<endl;
    }catch(ProcessorException &pe){
        cout<<pe.message<<endl;
    }


    //ProbarOutputException: simularemos limitar la cantidad de lineas a imprimir
    //a un maximo de 10 y minimo 1
    int n3;
    cout<<"Ingresa la cantidad de lineas a imprimir: ";
    try{
        cin>>n3;
        if(n3 < 1 || n3 > 10) throw OutputException();
        for(int i=0;i<n3;i++)
            cout<<"Linea "<<i+1<<endl;
    }catch(OutputException &oe){
        cout<<oe.message<<endl;
    }
    return EXIT_SUCCESS;
}