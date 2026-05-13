
#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

struct CuotaAmortizacion {
    int mes;
    double saldoInicial;
    double cuotaBase;
    double interes;
    double amortizacion;
    double seguroVida;
    double pagoTotal;
    double saldoFinal;
};

vector<CuotaAmortizacion> generarTablaAmortizacion(
    double montoPrestamo,
    double tasaMensual,      // Ejemplo: 0.01075 = 1.075%
    int numeroMeses,
    double seguroPorcentaje  // Ejemplo: 0.01 = 1%
) {
    vector<CuotaAmortizacion> tabla;

    // Fórmula del sistema francés:
    // Cuota = P * i / (1 - (1 + i)^-n)
    double cuotaBase =
        (montoPrestamo * tasaMensual) /
        (1.0 - pow(1.0 + tasaMensual, -numeroMeses));

    // En el Excel el seguro es fijo y se calcula sobre el monto inicial
    double seguroVida = montoPrestamo * seguroPorcentaje;

    double saldo = montoPrestamo;

    for (int mes = 1; mes <= numeroMeses; mes++) {
        CuotaAmortizacion cuota;

        cuota.mes = mes;
        cuota.saldoInicial = saldo;
        cuota.cuotaBase = cuotaBase;
        cuota.interes = saldo * tasaMensual;
        cuota.amortizacion = cuota.cuotaBase - cuota.interes;
        cuota.seguroVida = seguroVida;
        cuota.pagoTotal = cuota.cuotaBase + cuota.seguroVida;
        cuota.saldoFinal = cuota.saldoInicial - cuota.amortizacion;

        // Corrección por redondeo en la última cuota
        if (mes == numeroMeses && fabs(cuota.saldoFinal) < 0.01) {
            cuota.saldoFinal = 0.0;
        }

        tabla.push_back(cuota);
        saldo = cuota.saldoFinal;
    }

    return tabla;
}


//Ejemplo de uso:

int main() {
    double monto = 385000.0;
    double tasaMensual = 0.01075;   // 1.075%
    int plazo = 12;
    double seguro = 0.01;           // 1%

    vector<CuotaAmortizacion> tabla =
        generarTablaAmortizacion(monto, tasaMensual, plazo, seguro);

    for (const auto& c : tabla) {
        cout << c.mes << " "
             << c.saldoInicial << " "
             << c.cuotaBase << " "
             << c.interes << " "
             << c.amortizacion << " "
             << c.seguroVida << " "
             << c.pagoTotal << " "
             << c.saldoFinal << endl;
    }

    getchar();
    getchar();
    return 0;
}



