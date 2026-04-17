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
#include <cstdlib>// para system("cls") 
#include <ctime>// para generar palabras aleatorias
#include <windows.h>// para sonidos y colores

using namespace std;

// VARIABLES DEL JUEGO
    string letrasAdivinadas = "";
    int intentosRestantes = 6;
    bool gano = false;

// PROTOTIPOS
void jugarAhorcado();
string seleccionarPalabra();
void mostrarEstadoJuego(string palabra, string letrasAdivinadas, int intentosRestantes);
void mostrarAhorcado(int intentosRestantes);
void limpiarPantalla();

int main() {
    
    char game;
    do {
        jugarAhorcado();

        cout << "Quieres jugar otra ronda? (s/n): ";
        cin >> game;
        system("cls"); // limpiar pantalla para la siguiente ronda
    } while (game == 's' || game == 'S');

    return 0;
}

void jugarAhorcado() {
    int mode;
    string word;

    system("color 0F"); // resetear color
    cout << "----------------------------------" << endl;
    cout << "Bienvenido al juego del ahorcado!" << endl;
    cout << "----------------------------------" << endl;

    // elegir modo
    do {
        cout << "1. Contra la maquina" << endl;
        cout << "2. Contra un amigo" << endl;
        cout << "Ingresa el numero del modo: ";
        cin >> mode;
    } while (mode != 1 && mode != 2);

    // seleccionar palabra
    if (mode == 1) {
        srand(time(0));
        word = seleccionarPalabra();// seleccionar palabra aleatoria
    } else {
        cout << "Ingresa la palabra: ";
        cin >> word;
        // convertir a minusculas
        for (char& c : word) {
            c = tolower(c);
        }
    }

    
    // CICLO PRINCIPAL
    while (intentosRestantes > 0 && !gano) {

        limpiarPantalla(); // limpiar pantalla para mostrar el progreso actualizado
        
        mostrarAhorcado(intentosRestantes); // mostrar dibujo del ahorcado
        mostrarEstadoJuego(word, letrasAdivinadas, intentosRestantes);// mostrar progreso del juego

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
        system("color 2F"); // cambiar color de fondo a verde
        cout << "\nGanaste! La palabra era: " << word << endl;
        Beep(1200, 200); // sonido agudo de victoria
        gano = false; // resetear para la siguiente ronda
        word = "";
        letrasAdivinadas = "";
        intentosRestantes = 6;

    } else {
        system("color 4F"); // cambiar color de fondo a rojo
        cout << "\nPerdiste. La palabra era: " << word << endl;
        Beep(400, 300); // sonido grave de derrota
        word = "";
        gano = false; // resetear para la siguiente ronda
        letrasAdivinadas = "";
        intentosRestantes = 6;
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
        cout << "  +---+\n";
        cout << "  |   |\n";
        cout << "      |\n";
        cout << "      |\n";
        cout << "      |\n";
    }
    else if (intentosRestantes == 5) {
        cout << "  +---+\n";
        cout << "  |   |\n";
        cout << "  O   |\n";
        cout << "      |\n";
        cout << "      |\n";
    }
    else if (intentosRestantes == 4) {
        cout << "  +---+\n";
        cout << "  |   |\n";
        cout << "  O   |\n";
        cout << "  |   |\n";
        cout << "      |\n";
    }
    else if (intentosRestantes == 3) {
        cout << "  +---+\n";
        cout << "  |   |\n";
        cout << "  O   |\n";
        cout << " /|   |\n";
        cout << "      |\n";
    }
    else if (intentosRestantes == 2) {
        cout << "  +---+\n";
        cout << "  |   |\n";
        cout << "  O   |\n";
        cout << " /|\\  |\n";
        cout << "      |\n";
    }
    else if (intentosRestantes == 1) {
        cout << "  +---+\n";
        cout << "  |   |\n";
        cout << "  O   |\n";
        cout << " /|\\  |\n";
        cout << " /    |\n";
    }
    else {
        system("color 4F"); // cambiar color de fondo a rojo
        cout << "\033[41m";
        cout << "  +---+\n";
        cout << "  |   |\n";
        cout << "  O   |\n";
        cout << " /|\\  |\n";
        cout << " / \\  |\n";
        cout << "Game Over!";
    }
}

//funcion para limpiar pantalla
void limpiarPantalla() {
    system("cls");
}