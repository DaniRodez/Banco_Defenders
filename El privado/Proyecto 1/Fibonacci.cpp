/*
---------------------------------------
Nombre: Daniel Plascencia Rodríguez
Codigo: 222262246
Fecha: 07/02/2026
Programa: Fibonacci
----------------------------------------
*/

#include <iostream>
using namespace std;

int main() {
    int opcion;
    int limite;

    do {
        cout << "\n----- MENU FIBONACCI -----\n";
        cout << "1. Usar ciclo for\n";
        cout << "2. Usar ciclo while\n";
        cout << "3. Usar ciclo do-while\n";
        cout << "4. Salir\n";
        cout << "Elige una opcion: ";
        cin >> opcion;

        if (opcion >= 1 && opcion <= 3) {
            cout << "Ingresa el valor limite: ";
            cin >> limite;

            int a = 0, b = 1, c;

            cout << "Serie Fibonacci: ";

            if (a <= limite)
                cout << a << " ";
            if (b <= limite)
                cout << b << " ";

            // -------- FOR --------
            if (opcion == 1) {
                for (c = a + b; c <= limite; c = a + b) {
                    cout << c << " ";
                    a = b;
                    b = c;
                }
            }

            // -------- WHILE --------
            else if (opcion == 2) {
                c = a + b;
                while (c <= limite) {
                    cout << c << " ";
                    a = b;
                    b = c;
                    c = a + b;
                }
            }

            // -------- DO-WHILE --------
            else if (opcion == 3) {
                c = a + b;
                if (c <= limite) {
                    do {
                        cout << c << " ";
                        a = b;
                        b = c;
                        c = a + b;
                    } while (c <= limite);
                }
            }

            cout << endl;
        }
        else if (opcion == 4) {
            cout << "Programa finalizado\n";
        }
        else {
            cout << "Opcion no valida\n";
        }

    } while (opcion != 4);

    return 0;
}