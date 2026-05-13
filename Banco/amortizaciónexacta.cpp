#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

struct Amortizacion {
    int mes;
    double saldoInicial;   // Columna B
    double cuotaBase;      // Columna C
    double interes;        // Columna D
    double amortizacion;   // Columna E
    double seguroVida;     // Columna F
    double pagoTotal;      // Columna G
    double saldoFinal;     // Columna H
};

/*
    CÓDIGO GENERADO EXACTAMENTE A PARTIR DEL ARCHIVO Excel "TablaAmortización.xlsx"

    Fórmulas detectadas en el Excel:

    C2 = (B2 * 0.01075) / (1 - (1 + 0.01075)^-12)
    D2 = 0.01075 * B2
    E2 = C2 - D2
    F2 = $B$2 / 100
    G2 = C2 + F2
    H2 = B2 - E2

    Para filas posteriores:
    B(n) = H(n-1)
    C(n) = misma cuota base
    D(n) = 0.01075 * B(n)
    E(n) = C(n) - D(n)
    F(n) = montoInicial / 100
    G(n) = C(n) + F(n)
    H(n) = B(n) - E(n)
*/

vector<Amortizacion> generarTablaExcel(double montoInicial) {
    const double tasaMensual = 0.01075;  // 1.075%
    const int numeroMeses = 12;
    const double seguroVida = montoInicial / 100.0; // 1% del monto inicial

    vector<Amortizacion> tabla;

    // Fórmula EXACTA de la celda C2
    double cuotaBase =
        (montoInicial * tasaMensual) /
        (1.0 - pow(1.0 + tasaMensual, -numeroMeses));

    double saldo = montoInicial;

    for (int mes = 1; mes <= numeroMeses; mes++) {
        Amortizacion fila;

        fila.mes = mes;                     // Columna A
        fila.saldoInicial = saldo;          // Columna B
        fila.cuotaBase = cuotaBase;         // Columna C
        fila.interes = tasaMensual * fila.saldoInicial; // Columna D
        fila.amortizacion = fila.cuotaBase - fila.interes; // Columna E
        fila.seguroVida = seguroVida;       // Columna F
        fila.pagoTotal = fila.cuotaBase + fila.seguroVida; // Columna G
        fila.saldoFinal = fila.saldoInicial - fila.amortizacion; // Columna H

        // Evitar residuos muy pequeños por precisión
        if (fabs(fila.saldoFinal) < 1e-8)
            fila.saldoFinal = 0.0;

        tabla.push_back(fila);

        // La siguiente fila usa H(n)
        saldo = fila.saldoFinal;
    }

    return tabla;
}


//Ejemplo de uso:

int main() {
    double montoInicial = 385000.0;

    vector<Amortizacion> tabla = generarTablaExcel(montoInicial);

    cout << "Mes\tSaldo Inicial\tCuota Base\tInteres\tAmortizacion\tSeguro\tPago Total\tSaldo Final\n";

    for (const auto& fila : tabla) {
        cout << fila.mes << "\t"
             << fila.saldoInicial << "\t"
             << fila.cuotaBase << "\t"
             << fila.interes << "\t"
             << fila.amortizacion << "\t"
             << fila.seguroVida << "\t"
             << fila.pagoTotal << "\t"
             << fila.saldoFinal << "\n";
    }

    getchar();
    getchar();
    return 0;
}
