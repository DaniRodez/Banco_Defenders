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
void admin();

int main() {

    // Verificar si el archivo existe
    ifstream verificar(Nombre_Archivo);

    // Si el archivo no existe, se crea con encabezado
    if (!verificar.good()) {

        ofstream archivo(Nombre_Archivo);

        archivo << "Usuario,Contrasenia,RFC,Saldo,Adeudo,Plazo" << endl;

        archivo.close();
    }

    verificar.close();

    int opcion;

    do {

        opcion = menuPrincipal();

        switch (opcion) {

        case 1:
            system("cls"); // Limpiar pantalla
            registrarUsuario();
            break;

        case 2:
            system("cls"); // Limpiar pantalla
            consultarSaldo();
            break;

        case 3:
            system("cls"); // Limpiar pantalla
            cout << "Modulo de adeudos en construccion." << endl;
            system("pause");
            break;

        case 4:
            system("cls"); // Limpiar pantalla
            realizarPrestamo();
            break;

        case 5:
            system("cls"); // Limpiar pantalla
            cout << "Modulo de transferencias en construccion." << endl;
            system("pause");
            break;

        case 6:
            system("cls"); // Limpiar pantalla
            cout << "Saliendo del sistema..." << endl;
            system("pause");
            break;

        case 99:
            system("cls"); // Limpiar pantalla
            admin();
            break;

        default:
            system("cls"); // Limpiar pantalla
        }

    } while (opcion != 6);

    return 0;
}

// Funcion para llamar al menu principal

int menuPrincipal() {

    int opcion;

    system("cls"); // Limpiar pantalla
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
    cout << endl;
    cout << "1- Registrar usuario" << endl;
    cout << "2- Consultar saldo" << endl;
    cout << "3- Consultar y/o pagar adeudos" << endl;
    cout << "4- Cotizar y/o realizar prestamo" << endl;
    cout << "5- Realizar transferencia" << endl;
    cout << "6- Salir" << endl;

    cout << "\nSeleccione una opcion: ";
    cin >> opcion;

    return opcion;
}

// Funcion para registrar un nuevo usuario

void registrarUsuario() {

    string username, password, rfc;
    cout << "===============================" << endl;
    cout << "Seleccionaste registrar usuario" << endl;
    cout << "===============================" << endl;

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
                << "0,"
                << "0,"
                << "0"
                << endl;

        archivo.close();

        cout << "Usuario registrado correctamente." << endl;
            system("pause");

    } else {

        cout << "Error al abrir el archivo." << endl;
         system("pause");
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

    string username, password;
    string linea;

    cout << "===============================" << endl;
    cout<< "Seleccionaste consultar saldo" << endl;
    cout << "===============================" << endl;

    cout << "Ingrese el nombre de usuario: " << endl;
    cin >> username;

    cout << "Ingrese la contrasenia: " << endl;
    cin >> password;

    ifstream archivo(Nombre_Archivo);

    bool encontrado = false;

    // Saltar encabezado
    getline(archivo, linea);

    while (getline(archivo, linea)) {

        stringstream stream(linea);

        string usuario, contrasenia, rfc, saldo, adeudo, plazo, mensualidad;

        getline(stream, usuario, ',');
        getline(stream, contrasenia, ',');
        getline(stream, rfc, ',');
        getline(stream, saldo, ',');
        getline(stream, adeudo, ',');
        getline(stream, plazo, ',');
        getline(stream, mensualidad, ','); // Leer mensualidad
        
        // Verificar credenciales
        if (usuario == username && contrasenia == password) {

            cout << "Saldo actual: $" << saldo << endl;
            /*cout << "Adeudo actual: $" << adeudo << endl;
            cout << "Plazo: " << plazo << " dias" << endl;*/

            encontrado = true;

            system("pause");

            break;
        }
    }

    if (!encontrado) {

        cout << "Contrasenia y/o usuario incorrectos." << endl;
         system("pause");
    }

    archivo.close();
}

//Función para el modulo de administracion y mostrar los datos de los usuarios registrados (opcion secreta 99)
void admin() {

    ifstream archivo(Nombre_Archivo);

    if (archivo.is_open()) {

        string linea;

        // Saltar encabezado
        getline(archivo, linea);

        cout << "=================================" << endl;
        cout << "Datos de los usuarios registrados:" << endl;
        cout << "=================================" << endl;

        while (getline(archivo, linea)) {

            stringstream stream(linea);
            string usuario, contrasenia, rfc, saldo, adeudo, plazo, mensualidad;
            char delimitador = ',';

            getline(stream, usuario, ',');
            getline(stream, contrasenia, ',');
            getline(stream, rfc, ',');
            getline(stream, saldo, ',');
            getline(stream, adeudo, ',');
            getline(stream, plazo, ',');
            getline(stream, mensualidad, ','); // Leer mensualidad

            cout << "Usuario: " << usuario << endl;
            cout << "RFC: " << rfc << endl;
            cout << "Saldo: $" << saldo << endl;
            cout << "Adeudo: $" << adeudo << endl;
            cout << "Plazo: " << plazo << " dias" << endl;
            cout << "Mensualidad: $" << mensualidad << endl;
            cout << "---------------------------------" << endl;
        }
         system("pause");
        archivo.close();
    } else {

        cout << "Error al abrir el archivo." << endl;
         system("pause");
    }
}

// Funcion para realizar un prestamo y calcular pago mensual
void realizarPrestamo() {

    string username, password;
    string linea;

    double montoPrestamo, interesMensual, pagoMensual;
    int anios, meses;

    cout << "===============================" << endl;
    cout << "Seleccionaste realizar prestamo" << endl;
    cout << "===============================" << endl;

    cout << "Ingrese el nombre de usuario: ";
    cin >> username;

    cout << "Ingrese la contrasenia: ";
    cin >> password;

    ifstream archivo(Nombre_Archivo);

    ofstream temp("Temp.csv");

    bool encontrado = false;

    // Copiar encabezado
    getline(archivo, linea);
    temp << linea << endl;

    while (getline(archivo, linea)) {

        stringstream stream(linea);

        string usuario, contrasenia, rfc, saldo, adeudo, plazo, mensualidad;

        getline(stream, usuario, ',');
        getline(stream, contrasenia, ',');
        getline(stream, rfc, ',');
        getline(stream, saldo, ',');
        getline(stream, adeudo, ',');
        getline(stream, plazo, ',');
        getline(stream, mensualidad, ','); // Leer mensualidad

        if (usuario == username && contrasenia == password) {

            encontrado = true;

            cout << "Ingrese el monto del prestamo: ";
            cin >> montoPrestamo;

            cout << "Ingrese el plazo en anios (1-6 anios): ";
            cin >> anios;

            meses = anios * 12;

            // Interes mensual del 12.9%
            interesMensual = (12.9 / meses) / 100;

            // Pago mensual = capital mensual + interes
            pagoMensual = (montoPrestamo / meses) + ((montoPrestamo * interesMensual));

            cout << "\nPago mensual: $" << pagoMensual << endl;

            // Actualizar adeudo y plazo
            adeudo = to_string(montoPrestamo);
            plazo = to_string(meses);
            mensualidad = to_string(pagoMensual);
            cout << "Prestamo realizado correctamente." << endl;
        }

        // Guardar datos actualizados
        temp << usuario << ","
             << contrasenia << ","
             << rfc << ","
             << saldo << ","
             << adeudo << ","
             << plazo << ","
             << mensualidad
             << endl;
    }

    archivo.close();
    temp.close();

    remove(Nombre_Archivo);
    rename("Temp.csv", Nombre_Archivo);

    if (!encontrado) {

        cout << "Usuario o contrasenia incorrectos." << endl;
    }

    system("pause");
}