/*
---------------------------------------
Nombre: Daniel Plascencia Rodríguez
Codigo: 222262246
Fecha: 09/02/2026
Programa: No power
----------------------------------------
*/

#include <iostream>
using namespace std;

int main() {
    int lim, suma = 0;
    
    cout << "Ingresa un numero: ";
    cin >> lim;
    
   // Ciclo desde 1 hasta lim
    for (int i = 0; i <= lim; i++) {
        suma = suma + (i * i);
        cout << (i * i) << " " << endl;
    }

    // suma de los cuadrados
    cout << "La suma de los cuadrados es: " << suma << endl;
    
    return 0;
}