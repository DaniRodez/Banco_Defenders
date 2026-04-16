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
#include <srandom>

using namespace std;

void jugarAhorcado();
string seleccionarPalabra();
void mostrarEstadoJuego(string palabra, string letrasAdivinadas, int intentosRestantes);
void mostrarAhorcado(int intentosRestantes);

int main() {
    char game;
    do {
        jugarAhorcado();


        // Repetir el juego
        cout << "¿Quieres jugar otra ronda? (s/n): ";
        cin >> game;
    } while (game == 's' || game == 'S');
}

void jugarAhorcado(int mode, string word) {
    cout << "----------------------------------" << endl;
    cout << "¡Bienvenido al juego del ahorcado!" << endl;
    cout << "----------------------------------" << endl;
    cout << endl;
    cout << "\033[1;34mEscoje el modo de juego:\033[0m" << endl;
    cout << "1. Contra la máquina" << endl;
    cout << "2. Contra un amigo" << endl;
    cout << "Ingresa el número del modo de juego: ";
    cin >> mode;
    if (mode == 1) {
        cout << "Has elegido jugar contra la máquina." << endl;
        
        srandom(time(0));//generar un numero aleatorio para seleccionar una palabra de una lista predefinida
        word = seleccionarPalabra();

    } else if (mode == 2) {
        cout << "Has elegido jugar contra un amigo." << endl;
        cout << "Por favor, ingresa la palabra a adivinar: ";
        cin >> word;
        
    } else {
        cout << "Opción no válida. Por favor, elige 1 o 2: " << endl;
        cin >> mode; // Volver a pedir la opción
    }

}

//funcion para seleccionar una palabra aleatoria de una lista predefinida
string seleccionarPalabra() {
    string palabras[] = {"programacion", "ahorcado", "computadora", "desarrollo", "juego"};
    int numPalabras = sizeof(palabras) / sizeof(palabras[0]);
    int indice = random() % numPalabras;
    return palabras[indice];
}

//funcion para mostrar el estado del juego, incluyendo la palabra oculta, las letras adivinadas y el número de intentos restantes
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
    cout << "Letras adivinadas: " << letrasAdivinadas << endl;
    cout << "Intentos restantes: " << intentosRestantes << endl;
}

//funcion para mostrar el ahorcado en función del número de intentos restantes
void mostrarAhorcado(int intentosRestantes) {
    switch (intentosRestantes) {
        if (intentosRestantes == 6) {
            cout << "  +---+" << endl;
            cout << "  |   |" << endl;
            cout << "      |" << endl;}
        else if (intentosRestantes == 5) {
            cout << "  +---+" << endl;
            cout << "  |   |" << endl;
            cout << "  O   |" << endl;
            cout << "      |" << endl;
        }
        else if (intentosRestantes == 4) {
            cout << "  +---+" << endl;
            cout << "  |   |" << endl;
            cout << "  O   |" << endl;
            cout << "  |   |" << endl;
            cout << "      |" << endl;
        }
        else if (intentosRestantes == 3) {
            cout << "  +---+" << endl;
            cout << "  |   |" << endl;
            cout << "  O   |" << endl;
            cout << " /|   |" << endl;
            cout << "      |" << endl;
        }
        else if (intentosRestantes == 2) {
            cout << "  +---+" << endl;
            cout << "  |   |" << endl;
            cout << "  O   |" << endl;
            cout << " /|\\  |" << endl;
            cout << "      |" << endl;
        }
        else if (intentosRestantes == 1) {
            cout << "  +---+" << endl;
            cout << "  |   |" << endl;
            cout << "  O   |" << endl;
            cout << " /|\\  |" << endl;
            cout << " /    |" << endl;
        }
        else if (intentosRestantes == 0) {
            cout << "\033[41m"; // fondo rojo
            cout << "  +---+" << endl;
            cout << "  |   |" << endl;
            cout << "  O   |" << endl;
            cout << " /|\\  |" << endl;
            cout << " / \\  |" << endl;
            cout << "Game Over!" << endl;
        }
    }
}
