#include <stdio.h>
#include <conio.h>
#include  <stdlib.h>
#include <iostream>
#include <cstring>

using namespace std;

const int MaxEstudiantes = 3;

char nombre[MaxEstudiantes][50];
float notas[MaxEstudiantes];
char telefono[MaxEstudiantes][15];
char direccion[MaxEstudiantes][100];
int indice = 0;

void consultar() {
    char nombreBuscado[50];
    bool encontrado = false;

    cout << "Digite el nombre del estudiante: ";
    cin >> nombreBuscado;

    for (int i = 0; i < indice; i++) {
        if (strcmp(nombre[i], nombreBuscado) == 0) {
            cout << "Nota: " << notas[i] << "\nTelefono: " << telefono[i] << "\nDireccion: " << direccion[i] << endl;
            encontrado = true;
            break;
        }
    }

    if (!encontrado) {
        cout << "Estudiante no encontrado.\n";
    }
}

void ingresar() {
    if (indice >= MaxEstudiantes) {
        cout << "Capacidad maxima alcanzada.\n";
        return;
    }

    char seguir;
    do {
        cout << "Digite el nombre: ";
        cin >> nombre[indice];
        cout << "Digite la nota: ";
        cin >> notas[indice];
        cout << "Digite el telefono: ";
        cin >> telefono[indice];
        cout << "Digite la direccion: ";
        cin.ignore();
        cin.getline(direccion[indice], 100);

        indice++;
        if (indice >= MaxEstudiantes) break;

        cout << "¿Desea continuar? (s/n): ";
        cin >> seguir;

    } while (seguir == 's' || seguir == 'S');
}

void modificar() {
    char nombreBuscado[50];
    bool encontrado = false;

    cout << "Digite el nombre del estudiante a modificar: ";
    cin >> nombreBuscado;

    for (int i = 0; i < indice; i++) {
        if (strcmp(nombre[i], nombreBuscado) == 0) {
            cout << "Digite la nueva nota: ";
            cin >> notas[i];
            cout << "Digite el nuevo telefono: ";
            cin >> telefono[i];
            cout << "Digite la nueva direccion: ";
            cin.ignore();
            cin.getline(direccion[i], 100);

            encontrado = true;
            cout << "Datos actualizados.\n";
            break;
        }
    }

    if (!encontrado) {
        cout << "Estudiante no encontrado.\n";
    }
}

void borrar() {
    char nombreBuscado[50];
    bool encontrado = false;

    cout << "Digite el nombre del estudiante a borrar: ";
    cin >> nombreBuscado;

    for (int i = 0; i < indice; i++) {
        if (strcmp(nombre[i], nombreBuscado) == 0) {
            for (int j = i; j < indice - 1; j++) {
                strcpy(nombre[j], nombre[j + 1]);
                notas[j] = notas[j + 1];
                strcpy(telefono[j], telefono[j + 1]);
                strcpy(direccion[j], direccion[j + 1]);
            }
            indice--;
            encontrado = true;
            cout << "Estudiante eliminado.\n";
            break;
        }
    }

    if (!encontrado) {
        cout << "Estudiante no encontrado.\n";
    }
}

void reporte() {
    cout << "\nNombre       Nota    Telefono      Direccion\n";
    cout << "---------------------------------------------\n";
    for (int i = 0; i < indice; i++) {
        cout << nombre[i] << "        " << notas[i] << "    " << telefono[i] << "    " << direccion[i] << endl;
    }
    cout << "\n";
}

void menu() {
    int opcion = 0;
    do {
        cout << "\n1- Ingresar Estudiantes\n";
        cout << "2- Consultar Estudiantes\n";
        cout << "3- Modificar Estudiantes\n";
        cout << "4- Borrar Estudiantes\n";
        cout << "5- Reporte Estudiantes\n";
        cout << "6- Salir\n";
        cout << "Digite una opcion: ";
        cin >> opcion;

        switch (opcion) {
            case 1: ingresar(); break;
            case 2: consultar(); break;
            case 3: modificar(); break;
            case 4: borrar(); break;
            case 5: reporte(); break;
            case 6: cout << "Saliendo...\n"; break;
            default: cout << "Opcion no valida.\n"; break;
        }
    } while (opcion != 6);
}

int main() {
    menu();
    return 0;
}

