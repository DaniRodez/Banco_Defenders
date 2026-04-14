/*
---------------------------------------
Nombre: Daniel Plascencia Rodríguez
Codigo: 222262246
Fecha: 04/03/2026
Programa: Administrador de matrices
----------------------------------------
*/

#include <iostream>
#include <cstdlib> // Para srand y rand
#include <ctime>   // Para time

using namespace std;

int main() {
int filas;
int columnas;
int** matriz = new int*[filas]; // Crear un arreglo de punteros para las filas
int opcionmatriz; // Variable para saber qué metodo de llenado de matriz se va a usar
char opcion; // Variable para saber si quiere repetir

do {

    cout << "---------------------------------------" << endl;
    cout << "Bienvenido al Administrador de Matrices" << endl;
    cout << "---------------------------------------" << endl;
    cout << "Ingrese las dimensiones de la matriz:" << endl;
    cout << endl;

    cout << "Ingrese el número de filas: ";
    cin >> filas;
    
    cout << "Ingrese el número de columnas: ";
    cin >> columnas;
    cout << endl;

    // Crear las columnas para cada fila
    for (int i = 0; i < filas; i++) {
        matriz[i] = new int[columnas];
    }

    // Llenar la matriz con datos
    cout << "¿Que desea hacer?" << endl;
    cout << "1. Llenar manualmente" << endl;
    cout << "2. Llenar con números aleatorios" << endl;
    cout << "3. Ver el estado actual de la matriz" << endl;
    cout << "4. Salir" << endl;
    cout << endl;
    cout << "Ingrese su opción (1 - 4): ";
    cin >> opcionmatriz;
    cout << endl;
    

    if (opcionmatriz == 1) {
        cout << "Ingrese los elementos de la matriz:" << endl;
        for (int i = 0; i < filas; i++) {
            for (int j = 0; j < columnas; j++) {
                cout << "Elemento [" << i << "][" << j << "]: ";
                cin >> matriz[i][j];
                
            }
            
        }
        // Mostrar la matriz
                cout << endl;
                cout << "La matriz es:" << endl;
                for (int i = 0; i < filas; i++) {
                for (int j = 0; j < columnas; j++) {
                cout << matriz[i][j] << " ";
                }
                cout << endl;
              }
    } 
    else if (opcionmatriz == 2) {
        srand(time(0)); // Semilla para números aleatorios
        for (int i = 0; i < filas; i++) {
            for (int j = 0; j < columnas; j++) {
                matriz[i][j] = rand() % 100; // Números aleatorios entre 0 y 99
                
           }
        }
        cout << "Matriz llenada con números aleatorios." << endl;  
        // Mostrar la matriz
                cout << endl;
                cout << "La matriz es:" << endl;
                for (int i = 0; i < filas; i++) {
                for (int j = 0; j < columnas; j++) {
                cout << matriz[i][j] << " ";
                }
                cout << endl;
              }
    } 
    else if (opcionmatriz == 3) {
        cout << "Estado actual de la matriz:" << endl;
        for (int i = 0; i < filas; i++) {
            for (int j = 0; j < columnas; j++) {
                cout << matriz[i][j] << " ";
            }
            cout << endl;
        }
    } 
    else if (opcionmatriz == 4) {
        cout << "Saliendo del programa..." << endl;
        break; // Salir del bucle
    } 
    
    else {
        cout << "Opción inválida." << endl;
    } 
    // Pregunta para repetir
        cout << "\nDesea repetir el proceso? (s/n): ";
        cin >> opcion;
        cout << endl;
}while (opcion == 's' || opcion == 'S');

    cout << "Programa finalizado." << endl;

    return 0;
}