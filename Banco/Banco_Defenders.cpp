/*
---------------------------------------
Nombre: Daniel Plascencia Rodríguez
Codigo: 222262246
Fecha: 16/05/2026
Programa: Banco Defenders
----------------------------------------
*/

#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

#define Nombre_Archivo "Data.csv"

// Funciones
bool usuarioExiste(string username);
int menuPrincipal();
void registrarUsuario();
void consultarSaldo();
void consultarAdeudos();
void pagarAdeudos();
void cotizarPrestamo();
void realizarPrestamo();

int main() {

    // Verificar si el archivo existe
    ifstream verificar(Nombre_Archivo);

    // Si el archivo no existe, se crea con encabezado
    if (!verificar.good()) {

        ofstream archivo(Nombre_Archivo);

        archivo << "Usuario,Contrasenia,RFC,Monto,Plazo" << endl;

        archivo.close();
    }

    verificar.close();

    int opcion;

    do {

        opcion = menuPrincipal();

        switch (opcion) {

        case 1:
            registrarUsuario();
            break;

        case 2:
            consultarSaldo();
            break;

        case 3:
            cout << "Modulo de adeudos en construccion.\n";
            break;

        case 4:
            cout << "Modulo de prestamos en construccion.\n";
            break;

        case 5:
            cout << "Saliendo del sistema...\n";
            break;

        default:
            cout << "Opcion invalida.\n";
        }

    } while (opcion != 5);

    return 0;
}

// Funcion para llamar al menu principal

int menuPrincipal() {

    int opcion;

    cout << "==============================================================" << endl;
    cout << "  ____    _    _   _  ____ ___    "<< endl;
    cout << " | __ )  / \\  | \\ | |/ ___/ _ \\ " << endl;
    cout << " |  _ \\ / _ \\ |  \\| | |  | | | | " << endl;
    cout << " | |_) / ___ \\| |\\  | |__| |_| |  " << endl;
    cout << " |____/_/   \\_\\_| \\_|\\____\\___/ " << endl;

    cout << endl;

    cout << "  ____  _____ _____ _____ _   _ ____  _____ ____  ____  " << endl;
    cout << " |  _ \\| ____|  ___| ____| \\ | |  _ \\| ____|  _ \\/ ___| " << endl;
    cout << " | | | |  _| | |_  |  _| |  \\| | | | |  _| | |_) \\___ \\ " << endl;
    cout << " | |_| | |___|  _| | |___| |\\  | |_| | |___|  _ < ___) | " << endl;
    cout << " |____/|_____|_|   |_____|_| \\_|____/|_____|_| \\_\\____/ " << endl;

    cout << "==============================================================" << endl;

    cout << "1- Registrar usuario" << endl;
    cout << "2- Consultar saldo" << endl;
    cout << "3- Consultar y/o pagar adeudos" << endl;
    cout << "4- Cotizar y/o realizar prestamo" << endl;
    cout << "5- Salir" << endl;

    cout << "\nSeleccione una opcion: ";
    cin >> opcion;

    return opcion;
}

// Funcion para registrar un nuevo usuario

void registrarUsuario() {

    string username, password, rfc;

    cout << "\nIngrese un nombre de usuario: ";
    cin >> username;

    // Verificar si ya existe
    while (usuarioExiste(username)) {

        cout << "El usuario ya existe.\n";
        cout << "Ingrese otro nombre: ";
        cin >> username;
    }

    cout << "Ingrese una contrasenia: ";
    cin >> password;

    cout << "Ingrese su RFC: ";
    cin >> rfc;

    // Guardar en archivo
    ofstream archivo(Nombre_Archivo, ios::app);

    if (archivo.is_open()) {

        archivo << username << ","
                << password << ","
                << rfc << ","
                << "0,"
                << "0"
                << endl;

        archivo.close();

        cout << "\nUsuario registrado correctamente.\n";

    } else {

        cout << "Error al abrir el archivo.\n";
    }
}

// Funcion para verificar si un usuario ya existe

bool usuarioExiste(string username) {

    ifstream archivo(Nombre_Archivo);

    string linea;

    while (getline(archivo, linea)) {

        stringstream stream(linea);

        string usuarioArchivo;

        getline(stream, usuarioArchivo, ',');

        if (usuarioArchivo == username) {

            archivo.close();
            return true;
        }
    }

    archivo.close();
    return false;
}

// Funcion para consultar el saldo de un usuario

void consultarSaldo() {

    string username;
    string linea;

    cout << "\nIngrese el nombre de usuario: ";
    cin >> username;

    ifstream archivo(Nombre_Archivo);

    while (getline(archivo, linea)) {

        stringstream stream(linea);

        string usuario, password, rfc, saldo, adeudo;

        getline(stream, usuario, ',');
        getline(stream, password, ',');
        getline(stream, rfc, ',');
        getline(stream, saldo, ',');
        getline(stream, adeudo, ',');

        if (usuario == username) {

            cout << "\nSaldo actual: $" << saldo << endl;

            archivo.close();
            return;
        }
    }

    cout << "Usuario no encontrado.\n";

    archivo.close();
}