/*
---------------------------------------
Nombre: Daniel Plascencia Rodríguez
Codigo: 222262246
Fecha: 22/04/2026
Programa: Los autos
----------------------------------------
*/

#include <iostream>
#include <string>

using namespace std;

struct auto1 {
    string marca;
    string modelo;
    string motor;
    string poder;
    string transmision;
};

int main() {
    auto1 auto1, auto2, auto3;
    cout << "---------------------------------------" << endl;
    cout << "Bienvenido a la base de datos de autos!" << endl; 
    cout << "---------------------------------------" << endl;
    cout << endl;

    cout << "----------------------------" << endl;
    cout << "Ingresa los datos del auto 1" << endl;
    cout << "----------------------------" << endl;
    cout << "Marca: " << endl;
    cin >> auto1.marca;
    cout << "Modelo: " << endl;
    cin >> auto1.modelo;
    cout << "Motor" << endl;
    cin >> auto1.motor;
    cout << "Caballos de fuerza del motor: " << endl;
    cin >> auto1.poder;
    cout << "Tipo de transmision: " << endl;
    cin >> auto1.transmision;
    cout << endl;
    
    cout << "----------------------------" << endl;
    cout << "Ingresa los datos del auto 2" << endl;
    cout << "----------------------------" << endl;
    cout << "Marca: " << endl;
    cin >> auto2.marca;
    cout << "Modelo: " << endl;
    cin >> auto2.modelo;
    cout << "Motor" << endl;
    cin >> auto2.motor;
    cout << "Caballos de fuerza del motor: " << endl;
    cin >> auto2.poder;
    cout << "Tipo de transmision: " << endl;
    cin >> auto2.transmision;
    cout << endl;
    
    cout << "----------------------------" << endl;
    cout << "Ingresa los datos del auto 3" << endl;
    cout << "----------------------------" << endl;
    cout << "Marca: " << endl;
    cin >> auto3.marca;
    cout << "Modelo: " << endl;
    cin >> auto3.modelo;
    cout << "Motor" << endl;
    cin >> auto3.motor;
    cout << "Caballos de fuerza del motor: " << endl;
    cin >> auto3.poder;
    cout << "Tipo de transmision: " << endl;
    cin >> auto3.transmision;
    cout << endl;

    system("cls"); // limpiar pantalla para mostrar los datos ingresados

cout << "----------------------------" << endl;    
cout << "Datos del auto 1" << endl;
cout << "----------------------------" << endl;
cout << "Marca: " << auto1.marca << endl;
cout << "Modelo: " << auto1.modelo << endl;
cout << "Motor: " << auto1.motor << endl;
cout << "Caballos de fuerza del motor: " << auto1.poder << endl;
cout << "Tipo de transmision: " << auto1.transmision << endl;
cout << endl;

cout << "----------------------------" << endl;
cout << "Datos del auto 2" << endl;
cout << "----------------------------" << endl;
cout << "Marca: " << auto2.marca << endl;
cout << "Modelo: " << auto2.modelo << endl;
cout << "Motor: " << auto2.motor << endl;
cout << "Caballos de fuerza del motor: " << auto2.poder << endl;
cout << "Tipo de transmision: " << auto2.transmision << endl;
cout << endl;

cout << "----------------------------" << endl;
cout << "Datos del auto 3" << endl;
cout << "----------------------------" << endl;
cout << "Marca: " << auto3.marca << endl;
cout << "Modelo: " << auto3.modelo << endl;
cout << "Motor: " << auto3.motor << endl;
cout << "Caballos de fuerza del motor: " << auto3.poder << endl;
cout << "Tipo de transmision: " << auto3.transmision << endl;
cout << endl;

cout << "Fin del programa" << endl;
cout << "Presione Enter para salir..." << endl;

    getchar(); // Esperar a que el usuario presione Enter antes de salir
    getchar(); // El otro para que cierre
    return 0;
}