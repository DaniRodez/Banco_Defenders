/*
---------------------------------------
Nombre: Daniel Plascencia Rodríguez
Codigo: 222262246
Fecha: 14/02/2026
Programa: Multiplos de 3 y 5
----------------------------------------
*/

#include <iostream>
using namespace std;

bool entradaInvalida(int limite);

int main() {

    char opcion;  // Variable para saber si quiere repetir

do {
int limite;
int sumatres = 0;
int sumacinco = 0;

    cout << "\n----- PROGRAMA PARA VER Y SUMAR LOS MULTIPLOS DE 3 Y 5 -----\n";
    cout << "Ingresa un numero en el rango de 0 a 1000: ";
    cin >> limite;

    bool entradaInvalida(int limite);

    if (entradaInvalida(limite)) {
        cout << "Entrada invalida." << endl;
        cout << "Por favor, ingresa un numero en el rango de 0 a 1000: ";
        cin >> limite;
    }

cout << "Los multiplos de 3 son: " << endl;
    
for (int i = 0; i <= limite; i++) {
        if (i % 3 == 0) {
            cout << i << " ";
            sumatres += i;
        }
    }
    
cout << "\nLos multiplos de 5 son: " << endl;

for (int i = 0; i <= limite; i++) {
        if (i % 5 == 0) {
            cout << i << " ";
            sumacinco += i;
        }
    }    

cout << ". \nLa suma total  de los multiplos de 3 es: " << sumatres << endl;
cout << "La suma total  de los multiplos de 5 es: " << sumacinco << endl;

    // Pregunta para repetir
        cout << "\nDesea repetir el proceso? (s/n): ";
        cin >> opcion;

    } while (opcion == 's' || opcion == 'S');

    cout << "Programa finalizado." << endl;

    return 0;
}

/* FUNCION PARA VALIDAR NÚMEROS */
#include <iostream> 
#include <limits>

using namespace std; 
bool entradaInvalida(int limite) { 
  if (cin.fail() || limite < 0 || limite > 1000){ 
 cin.clear();
cin.ignore(numeric_limits<streamsize>::max(), '\n');
// cout << "Error: Por favor, ingresa un numero valido." << endl; 
  return true; // Sí, la entrada es inválida 
 }
 
return false; // No, la entrada es correcta

}