/*
---------------------------------------
Nombre: Daniel Plascencia Rodríguez
Codigo: 222262246
Fecha: 18/02/2026
Programa: Trayectoria de Collatz
----------------------------------------
*/

#include <iostream>
#include <chrono>

using namespace std;
using namespace chrono;

bool entradaInvalida(int numero);
void calcularCollatz(int numero);

int main(){ 
    
    int numero;
    char opcion;  // Variable para saber si quiere repetir

do {
    cout << "\n----- PROGRAMA PARA VER LA TRAYECTORIA DE COLLATZ -----\n";
    cout << "Ingrese un numero entero positivo: ";
    cin >> numero;

    while (entradaInvalida(numero)) {
        cout << "Error: Por favor, ingresa un numero valido (0-1000): ";
        cin >> numero;
    }

auto inicio = high_resolution_clock::now(); //Guardamos el tiempo inicial

    /*cout << "La trayectoria de Collatz es: " << numero << " ";
    
    while (numero != 1) {
        
        if (numero % 2 == 0) {
            numero = numero / 2;
            cout << numero << " ";
            contador++;
        } 
        else {
            numero = 3 * numero + 1;
            cout << numero << " ";
            contador++;
        }
    }*/
   
   calcularCollatz(numero);

    auto fin = high_resolution_clock::now();//Guardamos el tiempo final
    auto duracion = duration_cast<milliseconds>(fin - inicio);//Calculamos la diferencia de tiempo
    cout << "Tiempo de ejecución: " << duracion.count() << " milisegundos." << endl;//Mostramos el tiempo de ejecución

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
bool entradaInvalida(int numero) { 
  if (cin.fail() || numero < 0 || numero > 1000){ 
 cin.clear();
cin.ignore(numeric_limits<streamsize>::max(), '\n');
// cout << "Error: Por favor, ingresa un numero valido." << endl; 
  return true; // Sí, la entrada es inválida 
 }
 
return false; // No, la entrada es correcta

}

/* FUNCION PARA CALCULAR EL COLLATZ */
#include <iostream> 

using namespace std; 

void calcularCollatz(int numero) {
     int contador = 0;

    cout << "La trayectoria de Collatz es: " << numero << " ";
    
    while (numero != 1) {
        
        if (numero % 2 == 0) {
            numero = numero / 2;
            cout << numero << " ";
            contador++;
        } 
        else {
            numero = 3 * numero + 1;
            cout << numero << " ";
            contador++;
        }
    }
    cout << "\nEl proceso se realizó un total de " << contador << " veces." << endl;
}