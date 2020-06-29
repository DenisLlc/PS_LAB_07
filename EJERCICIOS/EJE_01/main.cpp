#include <iostream>
#include <cstdlib>
#include <exception>
using namespace std;

double division(double num1, double num2);
void myPause();

class div_cero : public exception{
    public:
        const char* what() const throw(){
            return "Error: división por cero...";
        }
};

int main(int argc, char* argv[]){
    double N, D;
    cout << "Probando división" << endl;
    cout << "Ingrese el numerador :";
    cin >> N;
    cin.clear();
    cout << "Ingrese el denominador :";
    cin >> D;
    
    try{
        if (D == 0) throw div_cero();
        cout << N << " / " << D << " = " << division(N, D) << endl;
    }
    catch (exception& e) {
        cout << e.what() << endl;
    }

    cin.clear();
    myPause();
    return 0;
 }

double division(double num1, double num2){
    double res;
    res = num1/num2;
    return res;
}

void myPause(){
    cout<<"Presionar tecla..."<<endl;
    getchar();
}