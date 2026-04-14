/*
---------------------------------------
Nombre: Daniel Plascencia Rodríguez
Codigo: 222262246
Fecha: 06/04/2026
Programa: Conversor de bases numericas
----------------------------------------
*/

#include <iostream>
#include <string>
#include <cctype>

using namespace std;

// Declaracion de funciones
int aDecimal(string num, int base);
string desdeDecimal(int num, int base);

int main() {
    int opcion;
    int opcionint;
    char continuar;

    string numero;

    do {
        cout << "-----------------------------------------------" << endl;
        cout << "Bienvenido al conversor de bases numericas" << endl;
        cout << "-----------------------------------------------" << endl;

        cout << "Ingrese el numero que desea convertir: " << endl;
        cin >> numero;
        cout << endl;

        cout << "Ingrese la base de origen: " << endl;
        cout << endl;
        cout << "1. Binario" << endl;
        cout << "2. Octal" << endl;
        cout << "3. Decimal" << endl;
        cout << "4. Hexadecimal" << endl;
        cin >> opcionint;
        cout << endl;
        
        cout << "Ingrese la base destino: " << endl;
        cout << endl;
        cout << "1. Binario" << endl;
        cout << "2. Octal" << endl;
        cout << "3. Decimal" << endl;
        cout << "4. Hexadecimal" << endl;
        cin >> opcion;

        int baseOrigen, baseDestino;

        switch (opcionint) {
            case 1: baseOrigen = 2; break;
            case 2: baseOrigen = 8; break;
            case 3: baseOrigen = 10; break;
            case 4: baseOrigen = 16; break;
            default:
                cout << "Base de origen invalida" << endl;
                return 1;
        }

        switch (opcion) {
            case 1: baseDestino = 2; break;

            case 2: baseDestino = 8; break;
            
            case 3: baseDestino = 10; break;

            case 4: baseDestino = 16; break;

            default:
                cout << "Base destino invalida" << endl;
                return 1;
        }

        int decimal = aDecimal(numero, baseOrigen);
        string resultado = desdeDecimal(decimal, baseDestino);

        cout << endl;
        cout << "Resultado: " << resultado << endl;

        cout << endl;
        cout << "Desea continuar? (s/n): ";
        cin >> continuar;
        cout << endl;

    } while (continuar == 's' || continuar == 'S');

    return 0;
}

// Convertir a decimal desde cualquier base
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

// Convertir desde decimal a cualquier base
string desdeDecimal(int num, int base) {
    if (num == 0) return "0";

    string resultado = "";

    while (num > 0) {
        int residuo = num % base;

        if (residuo < 10)
            resultado = char(residuo + '0') + resultado;
        else
            resultado = char(residuo - 10 + 'A') + resultado;

        num /= base;
    }

    return resultado;
}