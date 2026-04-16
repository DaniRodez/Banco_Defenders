/*
---------------------------------------
Nombre: Daniel Plascencia Rodríguez
Codigo: 222262246
Fecha: 10/04/2026
Programa: El ahorcado
----------------------------------------
*/

#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

// PROTOTIPOS
void jugarAhorcado();
string seleccionarPalabra();
void mostrarEstadoJuego(string palabra, string letrasAdivinadas, int intentosRestantes);
void mostrarAhorcado(int intentosRestantes);

int main() {
    char game;
    do {
        jugarAhorcado();

        cout << "¿Quieres jugar otra ronda? (s/n): ";
        cin >> game;
    } while (game == 's' || game == 'S');

    return 0;
}

void jugarAhorcado() {
    int mode;
    string word;

    cout << "----------------------------------" << endl;
    cout << "¡Bienvenido al juego del ahorcado!" << endl;
    cout << "----------------------------------" << endl;

    // elegir modo
    do {
        cout << "1. Contra la máquina" << endl;
        cout << "2. Contra un amigo" << endl;
        cout << "Ingresa el número del modo: ";
        cin >> mode;
    } while (mode != 1 && mode != 2);

    // seleccionar palabra
    if (mode == 1) {
        srand(time(0));
        word = seleccionarPalabra();
    } else {
        cout << "Ingresa la palabra: ";
        cin >> word;
    }

    // VARIABLES DEL JUEGO
    string letrasAdivinadas = "";
    int intentosRestantes = 6;
    bool gano = false;

    // CICLO PRINCIPAL
    while (intentosRestantes > 0 && !gano) {

        mostrarAhorcado(intentosRestantes);
        mostrarEstadoJuego(word, letrasAdivinadas, intentosRestantes);

        char letra;
        cout << "Ingresa una letra: ";
        cin >> letra;

        // verificar si ya la uso
        if (letrasAdivinadas.find(letra) != string::npos) {
            cout << "Ya intentaste esa letra.\n";
            continue;
        }

        letrasAdivinadas += letra;

        // verificar si la letra esta en la palabra
        if (word.find(letra) == string::npos) {
            cout << "Incorrecto!\n";
            intentosRestantes--;
        } else {
            cout << "Correcto!\n";
        }

        // verificar si ya gano
        gano = true;
        for (char c : word) {
            if (letrasAdivinadas.find(c) == string::npos) {
                gano = false;
                break;
            }
        }
    }

    // RESULTADO FINAL
    if (gano) {
        cout << "\n¡Ganaste! La palabra era: " << word << endl;
    } else {
        mostrarAhorcado(0);
        cout << "\nPerdiste. La palabra era: " << word << endl;
    }
}

// palabra aleatoria
string seleccionarPalabra() {
    string palabras[] = {"programacion", "ahorcado", "computadora", "desarrollo", "juego"};
    int numPalabras = sizeof(palabras) / sizeof(palabras[0]);
    int indice = rand() % numPalabras;
    return palabras[indice];
}

// mostrar progreso
void mostrarEstadoJuego(string palabra, string letrasAdivinadas, int intentosRestantes) {
    cout << "Palabra: ";
    for (char letra : palabra) {
        if (letrasAdivinadas.find(letra) != string::npos) {
            cout << letra << " ";
        } else {
            cout << "_ ";
        }
    }
    cout << endl;

    cout << "Letras usadas: " << letrasAdivinadas << endl;
    cout << "Intentos restantes: " << intentosRestantes << endl;
}

// dibujo del ahorcado
void mostrarAhorcado(int intentosRestantes) {

    if (intentosRestantes == 6) {
        cout << "  +---+\n  |   |\n      |\n";
    }
    else if (intentosRestantes == 5) {
        cout << "  +---+\n  |   |\n  O   |\n      |\n";
    }
    else if (intentosRestantes == 4) {
        cout << "  +---+\n  |   |\n  O   |\n  |   |\n      |\n";
    }
    else if (intentosRestantes == 3) {
        cout << "  +---+\n  |   |\n  O   |\n /|   |\n      |\n";
    }
    else if (intentosRestantes == 2) {
        cout << "  +---+\n  |   |\n  O   |\n /|\\  |\n      |\n";
    }
    else if (intentosRestantes == 1) {
        cout << "  +---+\n  |   |\n  O   |\n /|\\  |\n /    |\n";
    }
    else {
        cout << "\033[41m";
        cout << "  +---+\n  |   |\n  O   |\n /|\\  |\n / \\  |\n";
        cout << "Game Over!\n\033[0m";
    }
}