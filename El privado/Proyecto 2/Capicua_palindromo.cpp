/*
---------------------------------------
Nombre: Daniel Plascencia Rodríguez
Codigo: 222262246
Fecha: 25/02/2026
Programa: Capicúa y palíndromo
----------------------------------------
*/

#include <iostream>
#include <string>

using namespace std;

int main() {
    string entrada;
    char opcion;  // Variable para saber si quiere repetir

do {
    cout << "\n----- PROGRAMA PARA SABER SI ES UN PALINDROMO O CAPICUA -----\n";
    cout << "Ingrese un dato: ";
    cin >> entrada;

    // 1. Determinar si es numero o palabra
    bool esNumero = true;
    for (int i = 0; i < entrada.length(); i++) {
        if (entrada[i] < '0' || entrada[i] > '9') {
            esNumero = false;
        }
    }

    // 2. Normalizar (Si es palabra, pasar todo a minusculas manualmente)
    if (!esNumero) {
        for (int i = 0; i < entrada.length(); i++) {
            
            // Si el caracter es Mayuscula (A-Z), sumamos 32 para volverlo minuscula
            if (entrada[i] >= 'A' && entrada[i] <= 'Z') {
                entrada[i] = entrada[i] + 32;
            }
        }
    }

    // 3. Algoritmo de Simetria 
    bool esSimetrico = true;
    int inicio = 0;
    int fin = entrada.length() - 1;

    while (inicio < fin) {
        if (entrada[inicio] != entrada[fin]) {
            esSimetrico = false;
            break;
        }
        inicio++;
        fin--;
    }

    // 4. Resultado final
    if (esNumero) {
        if (esSimetrico) cout << "Es un numero Capicua." << endl;
        else cout << "Es un numero, pero NO es Capicua." << endl;
    } else {
        if (esSimetrico) cout << "Es una palabra Palindromo." << endl;
        else cout << "Es una palabra, pero NO es Palindromo." << endl;
    }

   cin.ignore(); // Limpiar el buffer de cadena

   // Pregunta para repetir
        cout << "\nDesea repetir el proceso? (s/n): ";
        cin >> opcion;

    } while (opcion == 's' || opcion == 'S');

    cout << "Programa finalizado." << endl;

    return 0;
}