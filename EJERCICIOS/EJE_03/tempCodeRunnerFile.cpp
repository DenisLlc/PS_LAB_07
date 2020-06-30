#include <iostream>
#include <string>

using namespace std;

bool isValidInt(string);

int main(){
    //EJEMPLO DE EXCEPCION POR ASIGNACION DE MEMORIA INSUFICIENTE
    //CON EL OPERADOR NEW
    cout << "EJEMPLO DE EXCEPCION POR ASIGNACION DE MEMORIA INSUFICIENTE (bad_alloc)" << endl;
    int n;
    cout << "Ingresa cantidad de registros: "; cin >> n;
    try{
        //Supongamos que la memoria tiene un limite de 100000 elementos si sobrepasa
        //ese limite lanzamos la excepcion bad_alloc
        if(n > 100000) throw bad_alloc();
        //En caso este dentro del limite el array se crea normalmente
        int* myarray = new int[n];
        cout << "Array creado correctamente!" << endl;
    }catch (bad_alloc& ba){
        cerr << "ERROR: memoria insuficiente" << endl;
    }

    cout << "\n" << endl;

    //EJEMPLO DE EXCEPCION POR INGRESO DE TIPO DE DATO INCORRECTO
    cout<<"EJEMPLO DE EXCEPCION POR TIPOS DE DATOS INCORRECTOS (logic_error)"<<endl;
    //Usaremos un string para el ingreso de datos
    string num;
    //Usamos trycatch
    try{
        //Ignoramos lo que esta en el buffer 
        cin.ignore();
        //Pedimos al usuario que ingrese algo
        cout<<"Ingresa un numero: "; getline(std::cin, num);
        //Validamos si es un entero con nuestra funcion personalizada
        if(!isValidInt(num)) throw num; //Lanzamos excepcion si no es un numero
        cout<<"Tipo de dato correcto!"<<endl;
    }catch(string e){
        //Capturamos el error y mostramos un mensaje
        cerr<<"ERROR: El valor ingresado "<<e<<" no es un entero"<<endl;
    }

    return EXIT_SUCCESS;
}

//Funcion para validar que ingreso un entero
bool isValidInt(string e){
    //Variable auxiliar para determinar desde donde empezar a analizar
    int inicio = 0;
    //Comprobamos que no este vacia
    if(e.length() == 0) return 0;
    //Comprobamos si el primer digito es + o - 
    if(e[0]=='+' || e[0]=='-'){
        inicio = 1; //Cambiamos inicio a 1
        if(e.length() == 1) return 0; //Si solo tiene un signo retornamos false
    }

    //Iteramos hasta llegar al final comprobando que todo sea un digito
    for(int i=inicio; i<e.length();i++)
        if(!isdigit(e[i])) return 0; //Si uno no es un digito retornamos false
    return 1; //Si no encontro algun error retornamos true
}