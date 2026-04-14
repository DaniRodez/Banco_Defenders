/*
---------------------------------------
Nombre: Daniel Plascencia Rodríguez
Codigo: 222262246
Fecha: 08/03/2026
Programa: Operador de matrices
----------------------------------------
*/

#include <iostream>
#include <cstdlib> // Para srand y rand
#include <ctime>   // Para time
using namespace std;

int main() {
    int filas;
    int columnas;
    int** matriz; // Puntero para la matriz dinámica
    int opcionmatriz; // Variable para saber qué metodo de llenado de matriz se va a usar
    char opcion; // Variable para saber si quiere repetir
    int multiplicacion = 1; // Variables para almacenar las operaciones de la matriz
    int divisor; // Variable para almacenar el divisor en la división escalar

do {
    cout << "---------------------------------------" << endl;
    cout << "Bienvenido al Operador de Matrices" << endl;
    cout << "---------------------------------------" << endl;
    cout << "Ingrese las dimensiones de la matriz:" << endl;
    cout << endl;

    cout << "Ingrese el número de filas: ";
    cin >> filas;
    
    cout << "Ingrese el número de columnas: ";
    cin >> columnas;
    cout << endl;

    matriz = new int*[filas];

    for (int i = 0; i < filas; i++) {
    matriz[i] = new int[columnas];
}

    // Llenar la matriz con datos
    cout << "¿Que desea hacer?" << endl;
    cout << "1. Llenar manualmente" << endl;
    cout << "2. Llenar con números aleatorios" << endl;
    cout << "3. Salir" << endl;
    cout << endl;
    cout << "Ingrese su opción (1 - 3): ";
    cin >> opcionmatriz;
    cout << endl;

    cout << "Ingrese un número para dividir la matriz: ";
    cin >> divisor;
    cout << endl;

    if (opcionmatriz == 1) {
        cout << "Ingrese los elementos de la matriz:" << endl;
        for (int i = 0; i < filas; i++) {
            for (int j = 0; j < columnas; j++) {
                cout << "Elemento [" << i << "][" << j << "]: ";
                cin >> matriz[i][j];
            }
            cout << endl;
        }
        
    } else if (opcionmatriz == 2) {
        srand(time(0)); // Inicializar la semilla para números aleatorios
        for (int i = 0; i < filas; i++) {
            for (int j = 0; j < columnas; j++) {
                matriz[i][j] = rand() % 100; // Generar un número aleatorio entre 0 y 99
            }
        }

    } else if (opcionmatriz == 3) {
        break;
    } else {
        cout << "Opción no válida." << endl;
    }

    // Mostrar la matriz
    cout << "La matriz es:" << endl;
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            cout << matriz[i][j] << " ";
        }
        cout << endl;
    }
    
  //Suma de matriz
  cout << endl;
  cout << "La suma de la matriz es:" << endl;
  //cout << matriz[0][0] << ", " << matriz[0][1] << ", " << matriz[0][2] << ", " << endl; // Imprimir los elementos de la primera fila
    for (int i = 0; i < filas - 1; i++) {
        for (int j = 0; j < columnas; j++) {
            cout << matriz[i][j] + matriz[i+1][j] << ", "; // Sumar el elemento actual con el siguiente elemento en la misma columna
        }
        cout << endl;
    }
    cout << "?, "<< " ?," << " ?," << endl; // Imprimir signos de interrogación para indicar que no se puede sumar con un elemento siguiente
    
  //Resta de matriz
  cout << endl;
  cout << "La resta de la matriz es:" << endl;
  //cout << matriz[0][0] << ", " << matriz[0][1] << ", " << matriz[0][2] << ", " << endl; // Imprimir los elementos de la primera fila
    for (int i = 0; i < filas - 1; i++) {
        for (int j = 0; j < columnas; j++) {
            cout << matriz[i][j] - matriz[i+1][j] << ", "; // Restar el elemento actual con el siguiente elemento en la misma columna
        }
        cout << endl;
    }
    cout << "?, "<< " ?," << " ?," << endl; // Imprimir signos de interrogación para indicar que no se puede sumar con un elemento siguiente
    cout << endl;

    //multiplicacion fila por columna
    cout << "La multiplicación de la matriz es:" << endl;
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            multiplicacion *= matriz[i][j]; // Multiplicar el elemento actual a la variable multiplicacion
            cout << multiplicacion << ", "; // Imprimir el resultado de la multiplicación
        }
        cout << endl;
    }

    // Division escalar de la matriz
    if (divisor != 0) {
        cout << endl;
        cout << "La división escalar de la matriz por " << divisor << " es:" << endl;
        for (int i = 0; i < filas; i++) {
            for (int j = 0; j < columnas; j++) {
                cout << static_cast<double>(matriz[i][j]) / divisor << ", "; // Dividir cada elemento por el divisor
            }
            cout << endl;
        }
    } else {
        cout << "No se puede dividir por cero." << endl;
    }

    cout << endl;
    cout << "¿Desea realizar otra operación? (s/n): ";
    cin >> opcion;
    cout << endl;
} while (opcion == 's' || opcion == 'S');

// Liberar la memoria asignada para la matriz
for (int i = 0; i < filas; i++) {
    delete[] matriz[i];
}
delete[] matriz;

return 0;
}