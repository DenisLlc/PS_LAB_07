#include <iostream>
#include <math.h>
#include "No_raices_reales.h"
#include "Primer_coeficiente_cero.h"

using namespace std;

int main(){
    double a,b,c;
    double r1,r2;
    
    try{
        cout << "[ax^2 + bx + c]" <<endl;
        cout << "Ingrese coeficiente del termino cuadratico(a) : "; cin >> a;
        if(a == 0) throw Primer_coeficiente_cero();
        cout << "Ingrese coeficiente del termino lineal(b): "; cin >> b;
        cout << "Ingrese termino independiente(c): "; cin >> c;

        double dis = pow(b,2)-(4*a*c);
        if(dis < 0) throw No_raices_reales();
        r1 = ((b*-1)+sqrt(dis))/(2*a);
        r2 = ((b*-1)-sqrt(dis))/(2*a);

        cout << "X1 = " << r1 << endl;
        cout << "X2 = " << r2 << endl;
    }catch(Primer_coeficiente_cero &pcc){
        cout<<"ERROR: " << pcc.what() << endl;
    }catch(No_raices_reales &nre){
        cout << "ERROR: " << nre.what() << endl;
    }

    return EXIT_SUCCESS;
}