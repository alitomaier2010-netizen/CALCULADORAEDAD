from datetime import date

def bisiesto(anio):
    return (anio % 4 == 0 and anio % 100 != 0) or (anio % 400 == 0)

def fecha_valida(dia, mes, anio):
    if mes < 1 or mes > 12:
        return False

    dias_mes = [31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31]

    if bisiesto(anio):
        dias_mes[1] = 29

    return 1 <= dia <= dias_mes[mes - 1]

def calcular_edad(dia, mes, anio):
    hoy = date.today()

    edad = hoy.year - anio

    if (hoy.month, hoy.day) < (mes, dia):
        edad -= 1

    return edad

dia = int(input("Ingrese día de nacimiento: "))
mes = int(input("Ingrese mes de nacimiento: "))
anio = int(input("Ingrese año de nacimiento: "))

if fecha_valida(dia, mes, anio):
    edad = calcular_edad(dia, mes, anio)
    print("Edad:", edad, "años")
else:
    print("Fecha inválida")