#include <iostream>
#include <ctime>

using namespace std;

bool bisiesto(int anio) {
    return (anio % 4 == 0 && anio % 100 != 0) || (anio % 400 == 0);
}

bool fecha_valida(int dia, int mes, int anio) {
    if (mes < 1 || mes > 12)
        return false;

    int dias_mes[] = {31,28,31,30,31,30,31,31,30,31,30,31};

    if (bisiesto(anio))
        dias_mes[1] = 29;

    return dia >= 1 && dia <= dias_mes[mes - 1];
}

int calcular_edad(int dia, int mes, int anio) {
    time_t t = time(0);
    tm* hoy = localtime(&t);

    int edad = (hoy->tm_year + 1900) - anio;

    if ((hoy->tm_mon + 1 < mes) ||
        ((hoy->tm_mon + 1 == mes) && (hoy->tm_mday < dia))) {
        edad--;
    }

    return edad;
}

int main() {
    int dia, mes, anio;

    cout << "Ingrese dia de nacimiento: ";
    cin >> dia;

    cout << "Ingrese mes de nacimiento: ";
    cin >> mes;

    cout << "Ingrese año de nacimiento: ";
    cin >> anio;

    if (fecha_valida(dia, mes, anio)) {
        cout << "Edad: " << calcular_edad(dia, mes, anio) << " años" << endl;
    } else {
        cout << "Fecha invalida" << endl;
    }

    return 0;
}