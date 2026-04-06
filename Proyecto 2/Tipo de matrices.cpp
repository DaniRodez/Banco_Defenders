/*
---------------------------------------
Nombre: Daniel Plascencia Rodríguez
Codigo: 222262246
Fecha: 08/03/2026
Programa: Tipo de matrices 
----------------------------------------
*/

#include <iostream>
#include <cstdlib> // Para srand o rand
//#include <ctime>  // Para time

using namespace std;

// Declaracion de funciones
void llenarMatriz(int** matriz, int filas, int columnas);
void determinarTipoMatriz(int** matriz, int filas, int columnas);

int main() {
    int filas;
    int columnas;
    int** matriz; // Puntero para la matriz dinamica
    int opcionmatriz; // Variable para saber que metodo de llenado de matriz se va a usar
    char opcion; // Variable para saber si quiere repetir

    srand(time(0)); // Inicializar aleatorios

    do {
        cout << "-----------------------------------------------" << endl;
        cout << "Bienvenido al analizador de tipo de Matrices" << endl;
        cout << "-----------------------------------------------" << endl;
        cout << "Ingrese las dimensiones de la matriz:" << endl;
        cout << endl;

        cout << "Ingrese el numero de filas: ";
        cin >> filas;

        cout << "Ingrese el numero de columnas: ";
        cin >> columnas;

        // Crear matriz dinamica
        matriz = new int*[filas];
        for (int i = 0; i < filas; i++) {
            matriz[i] = new int[columnas];
        }

        cout << endl;
        cout << "Metodo de llenado:" << endl;
        cout << "1. Aleatorio (0 y 1)" << endl;
        cout << "2. Manual" << endl;
        cout << endl;
        cout << "Ingrese una opcion: ";
        cin >> opcionmatriz;

        switch (opcionmatriz) {
            case 1:
                llenarMatriz(matriz, filas, columnas);
                break;

            case 2:
                cout << endl;
                cout << "Ingrese valores (solo 0 o 1):" << endl;
                
                for (int i = 0; i < filas; i++) {
                    for (int j = 0; j < columnas; j++) {
                        do {
                            cout << "Elemento [" << i << "][" << j << "]: ";
                            cin >> matriz[i][j];
                        } while (matriz[i][j] != 0 && matriz[i][j] != 1); // Validar que solo se ingresen 0 o 1
                    }
                }
                break; 

            default:
                cout << "Opcion no valida, saliendo del programa." << endl;
                return 1; // Salir del programa si la opcion no es valida
        }

        // Mostrar matriz
        cout << endl;
        cout << "La matriz es:" << endl;
        for (int i = 0; i < filas; i++) {
            for (int j = 0; j < columnas; j++) {
                cout << matriz[i][j] << " ";
            }
            cout << endl;
        }

        // Determinar tipo
        determinarTipoMatriz(matriz, filas, columnas);

        cout << endl;
        cout << "Desea repetir? (s/n): ";
        cin >> opcion;
        cout << endl;

        //reseter numeros aleatorios
        srand(time(0)); // Reiniciar semilla para nuevos numeros aleatorios

        //limpiar matriz
        for (int i = 0; i < filas; i++) {
            delete[] matriz[i];
        }
        matriz = nullptr; // Evitar acceso a memoria liberada

    } while (opcion == 's' || opcion == 'S');

    return 0;
}

// Llenar matriz aleatoria
void llenarMatriz(int** matriz, int filas, int columnas) {
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            matriz[i][j] = rand() % 2; // Generar 0 o 1 aleatoriamente
        }
    }
}

// Determinar tipo de matriz
void determinarTipoMatriz(int** matriz, int filas, int columnas) {

    bool reflexiva = true; // Variable para verificar si la matriz es reflexiva
    bool simetrica = true; // Variable para verificar si la matriz es simetrica
    bool transitiva = true; // Variable para verificar si la matriz es transitiva

    // Reflexiva
    for (int i = 0; i < filas; i++) { // Verificar que los elementos en la diagonal sean 1
        if (matriz[i][i] != 1) {
            reflexiva = false;
            break;
        }
    }

    // Simetrica
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) { // Comparar elemento [i][j] con [j][i]
            if (matriz[i][j] != matriz[j][i]) {
                simetrica = false;
                break;
            }
        }
        if (!simetrica) break;
    }

    // Transitiva
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) { // Si hay una relacion entre i y j, verificar si hay una relacion entre j y k para todos los k
            if (matriz[i][j] == 1) {
                for (int k = 0; k < columnas; k++) {
                    if (matriz[j][k] == 1 && matriz[i][k] != 1) {
                        transitiva = false;
                        break;
                    }
                }
            }
            if (!transitiva) break; // Si ya se determinó que no es transitiva, salir del ciclo para evitar verificaciones innecesarias
        }
        if (!transitiva) break; // Si ya se determinó que no es transitiva, salir del ciclo para evitar verificaciones innecesarias
    }

    // Resultados de la matriz
    cout << "\nResultados:\n";

    if (reflexiva) cout << "Es reflexiva\n";
    else cout << "No es reflexiva\n";

    if (simetrica) cout << "Es simetrica\n";
    else cout << "No es simetrica\n";

    if (transitiva) cout << "Es transitiva\n";
    else cout << "No es transitiva\n";

    cout << endl;
    // Tipo especial
    if (reflexiva && simetrica && transitiva) {
        cout << "Es una relacion de equivalencia\n";
    }
    else if (reflexiva && transitiva && !simetrica) {
        cout << "Es una relacion de orden parcial\n";
    }
    else {
        cout << "No es equivalencia ni orden parcial\n";
    }
}