#include <iostream>
#include <string>
#include <windows.h>

using namespace std;

struct Nodo {
    string nombre;
    string carne;
    Nodo *siguiente = NULL;
}*primero, *ultimo;

void InsertarNodo(string, string);
bool Buscar(string);
void Eliminar(string);
void Mostrar();

int main(){
    primero = NULL;
    ultimo = NULL;
    string name = "";
    string id = "";
	int opcion;
	do {
        system("cls");
        cout << "**********************************************************************************\n";
        cout << "* UNIVERSIDAD DE SAN CARLOS DE GUATEMALA                                         *\n";
        cout << "* FACULTAD DE INGENIERIA                                                         *\n";
        cout << "* ESTRUCTURA DE DATOS                                                            *\n";
        cout << "* TAREA 1                                                                        *\n";
        cout << "* ELDER OBDULIO CALDERON NAVARIJO                                                *\n";
        cout << "* 201701095                                                                      *\n";
        cout << "*                                                                                *\n";
        cout << "*                                                                                *\n";
        cout << "* MENU                                                                           *\n";
        cout << "* 1. Insertar                                                                    *\n";
        cout << "* 2. Buscar                                                                      *\n";
        cout << "* 3. Eliminar                                                                    *\n";
        cout << "* 4. Mostrar                                                                     *\n";
        cout << "* 5. Salir                                                                       *\n";
        cout << "**********************************************************************************\n";
        cout << "" << endl;
        cout << "Ingrese un digito del menu" << endl;
        cin >> opcion;
		switch (opcion) {
		case 1:
        {
            //Insertar nuevos datos de estudiante
            system("cls");
            cout << "Ingrese el nombre del estudiante"<<endl;
            cin >> name;
            cout << endl << endl << "Ingrese el carne del estudiante" << endl;
            cin >> id;
            InsertarNodo(name, id);
			break;
        }
        case 2:
        {
            system("cls");
            cout << "*********Buscar********** " << endl << endl;
            cout << "Ingrese el numero de carne: ";
            cin >> id;
            if (Buscar(id)) {
                cout << endl << "El carne esta registrado"<<endl << endl;
            }
            else {
                cout << endl << "El carne no esta registrado"<<endl << endl;
            }
            system("pause");
            break;
        }
        case 3:
        {
            system("cls");
            cout << "*********Eliminar********** " << endl << endl;
            cout << "Ingrese el numero de carne: ";
            cin >> id;
            if (Buscar(id)) {
                Eliminar(id);
                cout << endl << "El carne ha sido eliminado" << endl << endl;
                system("pause");
            }
            else {
                cout << endl << "El carne no esta registrado" << endl << endl;
            }
            
            break;
        }
        case 4:
        {
            Mostrar();
            break;
        }
        case 5:
        {
            system("cls");
            cout << "--->Saliendo" << endl;
            exit(0);
            break;
        }
		};
	} while (opcion!=5);
	
return 0;
}

void InsertarNodo(string nombre, string carne) {
    Nodo *nuevo = new Nodo();
    nuevo->nombre = nombre;
    nuevo->carne = carne;
    
    if (primero==NULL) {
        primero = nuevo;
    }
    else {
        ultimo->siguiente = nuevo;
    }
    ultimo = nuevo;
}

bool Buscar(string carne) {
    Nodo* nuevo = new Nodo();
    nuevo = primero;
    while (nuevo!=NULL) {
        if (nuevo->carne==carne) {
            return true;
            break;
        }
        nuevo = nuevo->siguiente;
    }
    return false;
}

void Eliminar(string carne) {
    Nodo* aux1 = new Nodo();
    Nodo* aux2 = new Nodo();
    aux1 = primero;

    while (aux1!=NULL) {
        if (aux1->carne==carne) {
            if (aux1==primero) {
                primero = primero->siguiente;
            }
            else {
                aux2->siguiente = aux1->siguiente;
                delete(aux1);
                break;
            }
        }
        aux2 = aux1;
        aux1 = aux1->siguiente;
    }
}

void Mostrar() {
    system("cls");
    Nodo* nuevo = new Nodo();
    nuevo = primero;

    if (nuevo==NULL) {
        cout << endl << "No hay datos de estudiantes ingresados"<<endl<<endl;
        system("pause");
    }
    else {
        cout << endl << "Estudiantes registrados:" << endl;
        while (nuevo != NULL) {
            cout << "[" << nuevo->nombre << " | " << nuevo->carne << "]" << " ---> ";
            nuevo = nuevo->siguiente;
        }
    }
    cout <<"NULL"<< endl << endl;
    delete(nuevo);
    system("pause");
}