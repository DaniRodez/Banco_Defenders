/*
---------------------------------------
Nombre: Daniel Plascencia Rodríguez
Codigo: 222262246
Fecha: 06/04/2026
Programa: Conversor de bases numéricas
----------------------------------------
*/

#include <iostream>

using namespace std;

int main() {
int opcion;
int numero;
int opcionint;
char continuar;

do {
        cout << "-----------------------------------------------" << endl;
        cout << "Bienvenido al conversor de bases numéricas" << endl;
        cout << "-----------------------------------------------" << endl;
        cout << "Ingrese el numero que desea convertir:" << endl;
        cin >> numero;
        cout << endl;
        cout << "Ingrese el número de opcion en el que esta el numero ingresado:" << endl;
        cout << "1. Binario" << endl;
        cout << "2. Octal" << endl;
        cout << "3. Decimal" << endl;
        cout << "4. Hexadecimal" << endl;
        cin >> opcionint;
        cout << endl;
        cout << "Ingrese el número de opcion al que desea convertir:" << endl;
        cout << "1. Binario" << endl;
        cout << "2. Octal" << endl;
        cout << "3. Decimal" << endl;
        cout << "4. Hexadecimal" << endl;
        cin >> opcion;
        cout << endl;

        switch (opcion) {
            case '1':
                cout << "Opcion 1: Binario" << endl;
                break;
            case '2':
                cout << "Opcion 2: Octal" << endl;
                break;
            case '3':
                cout << "Opcion 3: Decimal" << endl;
                break;
            case '4':
                cout << "Opcion 4: Hexadecimal" << endl;
                break;
            default:
                cout << "Opcion no valida, saliendo del programa." << endl;
                return 1; // Salir del programa si la opcion no es valida
        }//fin switch

        cout << "Desea continuar? (s/n): " << endl;
        cin >> continuar;
        cout << endl;

}while (continuar == 's' || continuar == 'S');//fin do
}//fin main

 //Fucion para convertir a decimal desde cualquier base
int aDecimal(string num, int base) {
    int valor = 0;

    for (char c : num) {
        int digito;

        if (isdigit(c))
            digito = c - '0';
        else
            digito = toupper(c) - 'A' + 10;

        valor = valor * base + digito;
    }

    return valor;
}