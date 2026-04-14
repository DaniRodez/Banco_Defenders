#include <iostream>
#include <fstream>
using namespace std;

int main() {
    // Ruta del archivo original (cambiala si es necesario)
    string rutaEntrada = "C:\\Users\\Daniel\\Downloads\\Fisica_Universitaria.pdf";

    ifstream entrada(rutaEntrada, ios::binary);

    // Verificamos que el archivo exista
    /*if (!entrada) {
        cout << "Error al abrir el archivo." << endl;
        return 1;
    }*/

    // Tamaño del bloque: 10 MB
    const int TAM = 10 * 1024 * 1024;

    char* buffer = new char[TAM]; // memoria dinamica

    int contador = 0;

    while (!entrada.eof()) {
        // Leer bloque
        entrada.read(buffer, TAM);

        // Cantidad real leida
        streamsize leidos = entrada.gcount();

        if (leidos == 0) break;

        // Nombre del archivo de salida
        string nombreSalida = "C:\\Users\\TU_USUARIO\\Downloads\\parte_" + to_string(contador) + ".bin";

        ofstream salida(nombreSalida, ios::binary);

        // Escribir bloque
        salida.write(buffer, leidos);

        salida.close();

        cout << "Parte " << contador << " creada (" << leidos << " bytes)" << endl;

        contador++;
    }

    // Liberar memoria
    delete[] buffer;

    entrada.close();

    cout << "Proceso terminado." << endl;

    return 0;
}