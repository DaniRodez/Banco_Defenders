/*
---------------------------------------
Nombre: Daniel Plascencia Rodríguez
Codigo: 222262246
Fecha: 23/04/2026
Programa: El juego de Hanoi
----------------------------------------
*/

#include <iostream>
#include <vector> // para usar vectores como torres
#include <windows.h>// para sonidos y colores
using namespace std;

void mostrarTorres(vector<int> A, vector<int> B, vector<int> C, int n);
bool mover(vector<int> &origen, vector<int> &destino);

int main() {
    int n;
    char opcion;

    do {
        // Validar cantidad de discos
        do {
            system("color 0F"); // resetear color
            cout << "-------------------------------------------" << endl;
            cout << "Bienvenido al juego de las torres de hanoi!" << endl;
            cout << "-------------------------------------------" << endl;
            cout << endl;
            cout << "Con cuantos discos deseas jugar? (3 a 7): ";
            cin >> n;
            system ("cls");// Borrar bienvenida

        } while (n < 3 || n > 7);

        vector<int> A, B, C;

        // Llenar torre A
        for (int i = n; i >= 1; i--) {
            A.push_back(i);
        }

        int movimientos = 0;

        // Juego
        while (C.size() != n) {
            cout << "Has hecho " << movimientos << " movimientos." << endl;
            mostrarTorres(A, B, C, n);

            char origen, destino;
            cout << endl;
            cout << "Mover de (A/B/C): ";
            cin >> origen;
            origen = toupper(origen); // Convertir a mayuscula y evitar errores

            cout << "Hacia (A/B/C): ";
            cin >> destino;
            destino = toupper(destino); // Convertir a mayuscula y evitar errores también

            system("cls"); // Limpiar pantalla para mejor visualización

            vector<int> *torreOrigen;
            vector<int> *torreDestino;

            // Seleccion de torres
            if (origen == 'A') torreOrigen = &A;
            else if (origen == 'B') torreOrigen = &B;
            else torreOrigen = &C;

            if (destino == 'A') torreDestino = &A;
            else if (destino == 'B') torreDestino = &B;
            else torreDestino = &C;

            // Intentar mover
            if (mover(*torreOrigen, *torreDestino)) {
                movimientos++;
            }
        }

        mostrarTorres(A, B, C, n);
        system("color 2F"); // cambiar color de fondo a verde
        cout << endl;
        cout << "Felicitaciones! Has completado el juego." << endl;
        cout << "Ganaste en " << movimientos << " movimientos!" << endl;
        Beep(1200, 200); // sonido agudo de victoria

        cout << "Jugar de nuevo? (s/n): ";
        cin >> opcion;
        system("cls"); // Limpiar pantalla para nueva partida

    } while (opcion == 's' || opcion == 'S');

    system("color 0F"); // resetear color antes de salir
    cout << "Gracias por jugar.\n";
    cout << "Presiona enter para salir..." << endl;
    
    getchar(); // Esperar a que el usuario presione enter
    getchar(); // Esperar a que el usuario presione enter nuevamente para cerrar la consola
    return 0;
}

// Funcion para mostrar las torres
void mostrarTorres(vector<int> A, vector<int> B, vector<int> C, int n) {
    cout << "\nEstado actual:\n";

    for (int i = n - 1; i >= 0; i--) {
        cout << " ";

        if (i < A.size()) cout << A[i];
        else cout << "|";

        cout << "   ";

        if (i < B.size()) cout << B[i];
        else cout << "|";

        cout << "   ";

        if (i < C.size()) cout << C[i];
        else cout << "|";

        cout << endl;
    }

    cout << " A   B   C\n";
}

// Validar si un movimiento es correcto
bool mover(vector<int> &origen, vector<int> &destino) {

    // Si la torre origen esta vacia
    if (origen.empty()) {
        cout << "Movimiento invalido: torre vacia\n";
        return false;
    }

    int disco = origen.back();

    // Si destino esta vacio o el disco es menor
    if (destino.empty() || destino.back() > disco) {
        destino.push_back(disco);
        origen.pop_back();
        return true;
    } else {
        std::cout << "\033[31m" << "Movimiento invalido: disco grande sobre pequenio" << "\033[0m" << std::endl;
        //cout << "Movimiento invalido: disco grande sobre pequenio\n";
        Beep(400, 300); // sonido grave de error
        return false;
    }
}
