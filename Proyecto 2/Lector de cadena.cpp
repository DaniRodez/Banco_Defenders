/*
---------------------------------------
Nombre: Daniel Plascencia Rodríguez
Codigo: 222262246
Fecha: 18/02/2026
Programa: Lector de cadena de caracteres
----------------------------------------
*/


#include <iostream>
#include <cstring>

using namespace std;

int count_vowels(char* cadena);
int count_consonants(char* cadena);
int count_words(char* cadena);
int count_numbers(char* cadena);
//int repetirProceso();

int main(){ 
    char cadena[100]; // Declaración de la cadena 
    int opcion = 1, op;  // Variable para saber si quiere repetir

    while (opcion == 1) { // Bucle para repetir el proceso
        
    cout << "\n----- PROGRAMA PARA LEER UNA CADENA DE CARACTERES -----\n";
    cout << "Ingrese una cadena de caracteres: ";
    cin.getline(cadena, 100); // Leer la cadena 

    cout << "\nla cantidad de caracteres en la cadena es: " << strlen(cadena) << endl; // Imprimir la longitud de la cadena

    cout << "la cantidad de vocales en la cadena es: " << count_vowels(cadena) << endl; // Contar vocales

    cout << "la cantidad de consonantes en la cadena es: " << count_consonants(cadena) << endl; // Contar consonantes

    cout << "la cantidad de palabras en la cadena es: " << count_words(cadena) << endl; // Contar palabras

    cout << "la cantidad de numeros en la cadena es: " << count_numbers(cadena) << endl; // Contar números
    
    // Pregunta para repetir
        cout << "\nDesea repetir el proceso? (si = 1 /no = 0): ";
        cin >> op;
        opcion = op; // Actualizar la variable de control del bucle

        if (opcion == 1) {
        opcion = 1; // Continuar el bucle 
        cin.ignore(); // Limpiar el buffer de cadena
        } 

        else {
        cout << "Programa finalizado." << endl;
        opcion = 0; // Salir del bucle
        }

    }

    return 0;
}

int count_vowels(char* cadena) {
    int count = 0;
    for (int i = 0; cadena[i] != '\0'; i++) {
        char c = tolower(cadena[i]);
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
            count++;
        }
    }
    return count;
}

int count_consonants(char* cadena) {
    int count = 0;
    for (int i = 0; cadena[i] != '\0'; i++) {
        char c = tolower(cadena[i]);
        if ((c >= 'a' && c <= 'z') && !(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')) {
            count++;
        }
    }
    return count;
}

int count_words(char* cadena) {
    int count = 0;
    bool in_word = false;
    for (int i = 0; cadena[i] != '\0'; i++) {
        if (cadena[i] != ' ') {
            if (!in_word) {
                count++;
                in_word = true;
            }
        } else {
            in_word = false;
        }
    }
    return count;
}

int count_numbers(char* cadena) {
    int count = 0;
    for (int i = 0; cadena[i] != '\0'; i++) {
        if (cadena[i] >= '0' && cadena[i] <= '9') {
            count++;
        }
    }
    return count;
}

/*int repetirProceso() {
    char op, s;
    cout << "\nDesea repetir el proceso? (s/n): ";
    cin >> op;
    if (op == 's' || op == 'S') {
        return '1'; // Retorna '1' para indicar que se desea repetir
    } else {
        cout << "Programa finalizado." << endl;
        return '0'; // Retorna '0' para indicar que no se desea repetir
    }
    return op;
}*/