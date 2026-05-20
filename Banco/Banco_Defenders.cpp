/*
---------------------------------------
Nombre: Daniel Plascencia Rodríguez
Codigo: 222262246
Fecha: 16/05/2026
Programa: Banco Defenders
----------------------------------------
*/

#include <iostream>
#include <fstream> // Libreria para manejo de archivos
#include <sstream> // Libreria para manejo de strings y conversiones
#include <cmath> // Libreria para operaciones matematicas (pow)
#include <vector> // Libreria para vectores y realizar operaciones en depositos

using namespace std;

// Archivos
#define Nombre_Archivo "Data.csv"
#define Historial_Archivo "Historial.csv"

// Funciones
bool usuarioExiste(string username);
int menuPrincipal();
void registrarUsuario();
void consultarSaldo();
//void consultarAdeudos();
void pagarAdeudos();
//void cotizarPrestamo();
void realizarPrestamo();
void admin();
void realizarDeposito();
void verHistorialCompleto();
void guardarTransaccion(string usuario, string tipo, int monto);

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

    ifstream verificarHistorial(Historial_Archivo);

    if (!verificarHistorial.good()) {

        ofstream historial(Historial_Archivo);

        historial << "Usuario,Tipo,Monto" << endl;

        historial.close();
    }

    verificarHistorial.close();

    int opcion;

    do {

        system("cls"); // Limpiar pantalla

        opcion = menuPrincipal(); // Mostrar menu y obtener opcion

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
            pagarAdeudos();
            break;

        case 4:
            system("cls"); // Limpiar pantalla
            realizarPrestamo();
            break;

        case 5:
            system("cls"); // Limpiar pantalla
            realizarDeposito();
            break;

        case 6:
            system("cls"); // Limpiar pantalla
            cout << "Saliendo del sistema..." << endl;
            system("pause"); // Pausa para mostrar mensaje antes de salir y leer mensaje
            break;

        case 99:
            system("cls"); // Limpiar pantalla
            admin();
            verHistorialCompleto();
            break;

        default:
            system("cls"); // Limpiar pantalla si ingresa una opcion no valida
            cout << "Opcion no valida. Intente de nuevo." << endl;
            system("pause");
        }

    } while (opcion != 6);

    return 0;
}

// Funcion para llamar al menu principal
//******************************************

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
    cout << endl;
    cout << "1- Registrar usuario" << endl;
    cout << "2- Consultar saldo" << endl;
    cout << "3- Pagar adeudos" << endl;
    cout << "4- Realizar prestamo" << endl;
    cout << "5- Realizar deposito" << endl;
    cout << "6- Salir" << endl;

    cout << "Seleccione una opcion: " << endl;
    cin >> opcion;

    return opcion;
}

// Funcion para registrar un nuevo usuario
//*****************************************

void registrarUsuario() {

    string username, password, rfc;
    cout << "===============================" << endl;
    cout << "Seleccionaste registrar usuario" << endl;
    cout << "===============================" << endl;

    cout << "Ingrese un nombre de usuario: " << endl;
    cin >> username;

    // Verificar si ya existe
    while (usuarioExiste(username)) {

        cout << "El usuario ya existe." << endl;
        cout << "Ingrese otro nombre: " << endl;
        cin >> username;
    }

    cout << "Ingrese una contrasenia: " << endl;
    cin >> password;

    cout << "Ingrese su RFC: " << endl;
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
//************************************************

bool usuarioExiste(string username) {

    ifstream archivo(Nombre_Archivo); // Abrir archivo para lectura

    string linea;

    while (getline(archivo, linea)) {

        stringstream stream(linea);

        string usuarioArchivo; // Variable para almacenar el nombre de usuario leído del archivo

        getline(stream, usuarioArchivo, ','); // Leer los nombres de usuario en el csv y comparar con el ingresado

        if (usuarioArchivo == username) {

            archivo.close();
            return true;
        }
    }

    archivo.close();
    return false;
}

// Funcion para consultar el saldo de un usuario
//************************************************

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

    bool encontrado = false; // Variable para indicar si se encontró el usuario

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
        
        // Si el usuario y contrasenia coinciden mostrar saldo
        if (usuario == username && contrasenia == password) {

            cout << "Saldo actual: $" << saldo << endl;

            encontrado = true;

            system("pause");

            break;
        }
    }

    // Si no se encontró el usuario, mostrar mensaje de error
    if (!encontrado) {
        cout << "Contrasenia y/o usuario incorrectos." << endl;
         system("pause");
    }

    archivo.close();
}

//Función para el modulo de administracion y mostrar los datos de los usuarios registrados (opcion secreta 99)
//************************************************************************************************************
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

            // Leer cada campo separado por comas desde el archivo csv
            getline(stream, usuario, ',');
            getline(stream, contrasenia, ',');
            getline(stream, rfc, ',');
            getline(stream, saldo, ',');
            getline(stream, adeudo, ',');
            getline(stream, plazo, ',');
            getline(stream, mensualidad, ',');

            cout << "---------------------------------" << endl;
            cout << "Usuario: " << usuario << endl;
            cout << "RFC: " << rfc << endl;
            cout << "Saldo: $" << saldo << endl;
            cout << "Adeudo: $" << adeudo << endl;
            cout << "Plazo: " << plazo << " dias" << endl;
            cout << "Mensualidad: $" << mensualidad << endl;
            
        }
        archivo.close();
    } else {

        cout << "Error al abrir el archivo." << endl;
         system("pause");
    }
}

// Funcion para realizar un prestamo y calcular pago mensual
//**********************************************************

void realizarPrestamo() {

    string username, password;
    string linea;

    double montoPrestamo;
    double interesMensual;
    double cuotaBase;
    double seguroVida;
    double pagoMensual;
    double saldoRestante;

    int anios, meses;

    cout << "===============================" << endl;
    cout << "Seleccionaste realizar prestamo" << endl;
    cout << "===============================" << endl;

    cout << "Ingrese el nombre de usuario: " << endl;
    cin >> username;

    cout << "Ingrese la contrasenia: " << endl;
    cin >> password;

    ifstream archivo(Nombre_Archivo);

    ofstream temp("Temp.csv"); // Crear archivo temporal para actualizar datos sin perder informacion

    bool encontrado = false;

    getline(archivo, linea);// Copiar encabezado al nuevo archivo temporal
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
        getline(stream, mensualidad, ','); 

        if (usuario == username && contrasenia == password) {

            encontrado = true;

            cout << "Ingrese el monto del prestamo: ";
            cin >> montoPrestamo;

            cout << "Ingrese el plazo en anios (1-6 anios): ";
            cin >> anios;

            meses = anios * 12;

            // Interes mensual basado en 12.9 anual
            interesMensual = (12.9 / meses) / 100;

            // Formula de cuota base (amortizacion)
            cuotaBase = (montoPrestamo * interesMensual) / (1 - pow(1 + interesMensual, -meses));

            // Seguro de vida 1%
            seguroVida = montoPrestamo * 0.01;

            // Pago mensual total
            pagoMensual = cuotaBase + seguroVida;

            // Saldo restante
            saldoRestante = montoPrestamo;

            cout << "===============================" << endl;
            cout << "Cuota base: $" << cuotaBase << endl;
            cout << "Seguro de vida: $" << seguroVida << endl;
            cout << "Pago mensual total: $" << pagoMensual << endl;
            cout << "===============================" << endl;

            // Guardar transaccion en historial
            guardarTransaccion(username, "Prestamo", montoPrestamo);

            // Guardar adeudo actualizado
            adeudo = to_string(saldoRestante);

            // Guardar plazo
            plazo = to_string(meses);

            // Guardar mensualidad
            mensualidad = to_string(pagoMensual);

            cout << "Prestamo realizado correctamente." << endl;
        }

        // Actualizar archivo csv con nuevo adeudo, plazo y mensualidad
        temp << usuario << ","
             << contrasenia << ","
             << rfc << ","
             << saldo << ","
             << adeudo << ","
             << plazo << ","
             << mensualidad
             << endl;
    } 
    
    // Cerrar ambos archivos antes de eliminar el original y renombrar el temporal
    archivo.close();
    temp.close(); 
    

    remove(Nombre_Archivo); // Eliminar archivo original
    rename("Temp.csv", Nombre_Archivo); // Renombrar archivo temporal con el nombre del original para mantener los cambios

    if (!encontrado) {
        cout << "Usuario o contrasenia incorrectos." << endl;
    }

    system("pause");
}

// Funcion para pagar adeudos
//***************************

void pagarAdeudos() {

    string username, password;
    string linea;

    double abono;
    double adeudoActual;
    double nuevoAdeudo;

    int plazoActual;
    int nuevoPlazo;

    cout << "===============================" << endl;
    cout << "Seleccionaste pagar adeudos" << endl;
    cout << "===============================" << endl;

    cout << "Ingrese el nombre de usuario: " << endl;
    cin >> username;

    cout << "Ingrese la contrasenia: " << endl;
    cin >> password;

    ifstream archivo(Nombre_Archivo);

    ofstream temp("Temp.csv");

    bool encontrado = false;

    getline(archivo, linea); // Copiar encabezado
    temp << linea << endl;

    while (getline(archivo, linea)) {

        stringstream stream(linea);

        string usuario, contrasenia, rfc, saldo, adeudo, plazo, mensualidad;

        // Leer cada campo separado por comas desde el archivo csv
        getline(stream, usuario, ',');
        getline(stream, contrasenia, ',');
        getline(stream, rfc, ',');
        getline(stream, saldo, ',');
        getline(stream, adeudo, ',');
        getline(stream, plazo, ',');
        getline(stream, mensualidad, ',');

        if (usuario == username && contrasenia == password) {

            encontrado = true;

            adeudoActual = stod(adeudo); // Convertir adeudo a double para operaciones
            plazoActual = stoi(plazo); // Convertir plazo a int para operaciones

            cout << endl;
            cout << "Adeudo actual: $" << adeudoActual << endl;
            cout << "Plazo restante: " << plazoActual << " meses" << endl;
            cout << "Mensualidad: $" << mensualidad << endl;

            cout << "Ingrese cantidad a abonar: " << endl;
            cin >> abono;

            // Validar abono
            if (abono <= 0) {

                cout << "Cantidad invalida." << endl;

            } else if (abono > adeudoActual) {

                cout << "El abono excede el adeudo." << endl;

            } else {

                nuevoAdeudo = adeudoActual - abono;
                guardarTransaccion(username, "Pago", stoi(adeudo)); // Guardar pago en historial antes de actualizar el adeudo para mantener registro del monto pagado antes de la actualizacion

                // Reducir plazo si existe adeudo
                if (plazoActual > 0) {

                    nuevoPlazo = plazoActual - 1;
                    guardarTransaccion(username, "Pago", stoi(adeudo)); // Guardar pago en historial

                } else {

                    nuevoPlazo = 0;
                    guardarTransaccion(username, "Pago", stoi(adeudo)); // Guardar pago en historial aunque el plazo ya haya terminado para mantener registro de pagos realizados
                }

                adeudo = to_string(nuevoAdeudo);
                plazo = to_string(nuevoPlazo);
                mensualidad = to_string(stod(mensualidad) * (1 - (abono / adeudoActual)));

                cout << endl;
                cout << "===============================" << endl;
                cout << "Abono realizado correctamente." << endl;
                cout << "Nuevo adeudo: $" << nuevoAdeudo << endl;
                cout << "Plazo restante: " << nuevoPlazo << " meses" << endl;
                cout << "Mensualidad: $" << mensualidad << endl;
                cout << "===============================" << endl;

                // Si termina de pagar
                if (nuevoAdeudo <= 0) {

                    adeudo = "0";
                    plazo = "0";

                    cout << endl;
                    cout << "El adeudo ha sido liquidado." << endl;
                    guardarTransaccion(username, "Pago", stoi(adeudo));
                    system("pause");
                }
            }
        }

        // Actualizar archivo CSV
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

    remove(Nombre_Archivo); // Eliminar archivo original
    rename("Temp.csv", Nombre_Archivo); // Renombrar archivo temporal con el nombre del original para mantener los cambios

    if (!encontrado) {
        cout << "Usuario o contrasenia incorrectos." << endl;
    }

    system("pause");
}

//Funcion para realizar transferencias
//************************************

void realizarDeposito() {

    string username, password;
    string linea;

    cout << "===============================" << endl;
    cout << "Seleccionaste realizar deposito" << endl;
    cout << "===============================" << endl;

    cout << "Ingrese el nombre de usuario: " << endl;
    cin >> username;

    cout << "Ingrese la contrasenia: " << endl;
    cin >> password;

    ifstream archivo(Nombre_Archivo);

    vector<string> lineas;

    bool encontrado = false;

    getline(archivo, linea);// Saltar encabezado
    lineas.push_back(linea); // Guardar encabezado en vector para luego reescribir el archivo con los cambios realizados

    while (getline(archivo, linea)) {

        stringstream stream(linea);

        string usuario, contrasenia, rfc, saldo, adeudo, plazo;

        getline(stream, usuario, ',');
        getline(stream, contrasenia, ',');
        getline(stream, rfc, ',');
        getline(stream, saldo, ',');
        getline(stream, adeudo, ',');
        getline(stream, plazo, ',');

        // Verificar usuario
        if (usuario == username && contrasenia == password) {

            encontrado = true;

            int monto;

            cout << "Ingrese el monto a depositar: $" << endl;
            cin >> monto;

            // Validar monto
            if (monto <= 0) {

                cout << "Monto invalido." << endl;
                system("pause");
                archivo.close();
                return;
            }

            // Convertir saldo a entero
            int saldoInt = stoi(saldo);

            // Sumar deposito
            saldoInt += monto;

            // Convertir otra vez a string
            saldo = to_string(saldoInt);

            cout << endl;
            cout << "Deposito realizado correctamente." << endl;
            cout << "Nuevo saldo: $" << saldoInt << endl;
    
                // Guardar transaccion en historial
                guardarTransaccion(username, "Deposito", monto);
            
        }

        // Reconstruir linea
        linea = usuario + "," +
                 contrasenia + "," +
                 rfc + "," +
                 saldo + "," +
                 adeudo + "," +
                 plazo;

        lineas.push_back(linea); // Guardar linea actualizada
    }

    archivo.close();

    ofstream archivoSalida(Nombre_Archivo);// Reescribir TODO el archivo

    for (string l : lineas) {
        archivoSalida << l << endl; // Escribir cada linea del vector en el archivo, incluyendo los cambios realizados
    }

    archivoSalida.close();

    if (!encontrado) {
        cout << "Contrasenia y/o usuario incorrectos." << endl;
    }

    system("pause");
}

// Funcion de historial
//***************************

void verHistorialCompleto() {

    ifstream historial("Historial.csv");

    string linea;

    cout << "============================" << endl;
    cout << " Historial de Transacciones " << endl;
    cout << "============================" << endl;
    
    getline(historial, linea);// Saltar encabezado

    bool vacio = true;

    while (getline(historial, linea)) {

        vacio = false;

        stringstream stream(linea);

        string usuario, tipo, monto;

        getline(stream, usuario, ',');
        getline(stream, tipo, ',');
        getline(stream, monto, ',');

        cout << "----------------------------------" << endl;
        cout << "Usuario: " << usuario << endl;
        cout << "Movimiento: " << tipo << endl;
        cout << "Monto: $" << monto << endl;
    }

    if (vacio) {
        cout << "No hay transacciones registradas." << endl;
    }

    historial.close();
    system("pause");
}

// Funcion para guardar transacciones en el historial
//*******************************************************

void guardarTransaccion(string usuario, string tipo, int monto) {

    ofstream historial("Historial.csv", ios::app);

    if (historial.is_open()) {

        historial << usuario << ","
                  << tipo << ","
                  << monto
                  << endl;

        historial.close();
    }
}