/*
---------------------------------------
Nombre: Daniel Plascencia Rodríguez
Codigo: 222262246
Fecha: 14/02/2026
Programa: Numeros primos
----------------------------------------
*/

#include <iostream>
using namespace std;

bool entradaInvalida(int limite);

int main() {

    char opcion;  // Variable para saber si quiere repetir

do {

    int limite;
    int suma = 0;
    
    cout << "\n----- PROGRAMA PARA VER Y SUMAR LOS NUMEROS PRIMOS -----\n";
    cout << "Ingresa un numero entero positivo: ";
    cin >> limite;

    bool entradaInvalida(int limite);

    if (entradaInvalida(limite)) {
        cout << "Entrada invalida." << endl;
        cout << "Por favor, ingresa un numero entero positivo: ";
        cin >> limite;
    }

    cout << "Los numeros primos son: ";
    
    bool primero = true;  // Para controlar el formato de impresion

    for (int i = 2; i <= limite; i++) {
        
        bool esPrimo = true;  // Suponemos que es primo
        
        // Verificamos si tiene divisores
        for (int d = 2; d < i; d++) {
            if (i % d == 0) {
                esPrimo = false;
                break;  // Si tiene divisor, salimos
            }
        }
        
        if (esPrimo) {
            if (!primero) {
                cout << ", ";
            }
            cout << i;
            suma += i;
            primero = false;
        }
    }

cout << ". \nLa suma total es: " << suma << endl;

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
  if (cin.fail() || limite < 0){ 
 cin.clear();
cin.ignore(numeric_limits<streamsize>::max(), '\n');
// cout << "Error: Por favor, ingresa un numero valido." << endl; 
  return true; // Sí, la entrada es inválida 
 }
 
return false; // No, la entrada es correcta

}
