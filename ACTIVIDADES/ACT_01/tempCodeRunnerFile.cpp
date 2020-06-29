#include <iostream>
#include <cstdlib>
#include <exception>
using namespace std;

void myPause();

class div_cero : public exception{
    public:
        const char* what() const throw(){
            return "Error: división por cero...";
        }
};

int main(int argc, char* argv[])
{
    double N, D;
    cout << "Probando división" << endl;
    cout << "Ingrese el numerador :";
    cin >> N;
    cin.clear();
    cout << "Ingrese el denominador :";
    cin >> D;
    cin.clear();
    try {
        if (D == 0) throw div_cero();
        cout << N << " / " << D << " = " << N / D << endl;
    }
    catch (exception& e) {
        cout << e.what() << endl;
    }
    myPause();
    return 0;
}

void myPause(){
    cout<<"Presionar tecla..."<<endl;
    getchar();
}