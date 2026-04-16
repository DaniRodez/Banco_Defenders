/*
---------------------------------------
Nombre: Daniel Plascencia Rodríguez
Codigo: 222262246
Fecha: 09/04/2026
Programa: Torres de Hanoi
----------------------------------------
*/

#include <iostream>

using namespace std;

// Prototipo de la funcion
void hanoi(int n, char origen, char auxiliar, char destino, int &contador);

int main() {
    int n;
    char continuar;

    do {
        int contador = 0;

        // Validacion del numero de discos
        do {
            cout << "--------------------------------------------------------------" << endl;
            cout << "Bienvenido al solucionador del problema de las Torres de Hanoi" << endl;
            cout << "--------------------------------------------------------------" << endl;

            cout << "Ingrese el numero de discos (3 - 7): ";
            cin >> n;
            cout << endl;
                if (n < 3 || n > 7) {
                    system("cls"); // Limpiar pantalla 
                    cout << "Numero invalido. Por favor ingrese un numero entre 3 y 7." << endl;
                    cout << endl;
                }
        } while (n < 3 || n > 7);

           cout << "Lista de movimientos:" << endl;

           // Llamada a la funcion
           hanoi(n, 'A', 'B', 'C', contador);

        // Mostrar total de movimientos
        cout << "\nTotal de movimientos: " << contador << endl;

        // Preguntar si quiere repetir
        cout << "\nDesea intentar con otro numero de discos? (s/n): ";
        cin >> continuar;
        system("cls"); // Limpiar pantalla para la siguiente ejecucion

    } while (continuar == 's' || continuar == 'S');

    cout << "Programa finalizado." << endl;
    printf("\nPresiona Enter para salir...");

    getchar(); // Esperar a que el usuario presione Enter antes de cerrar la consola
    getchar(); 

    return 0;
}

// Funcion para resolver el problema de las Torres de Hanoi
void hanoi(int n, char origen, char auxiliar, char destino, int &contador) {

    // Caso base
    if (n == 1) {
        contador++;
        cout << "Movimiento " << contador << ": Mover disco 1 de "
             << origen << " a " << destino << endl;
        return;
    }

    // Paso 1
    hanoi(n - 1, origen, destino, auxiliar, contador);

    // Paso 2
    contador++;
    cout << "Movimiento " << contador << ": Mover disco " << n
         << " de " << origen << " a " << destino << endl;

    // Paso 3
    hanoi(n - 1, auxiliar, origen, destino, contador);
}