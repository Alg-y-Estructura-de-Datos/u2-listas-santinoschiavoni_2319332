/*

 Crea un programa que gestione una lista circular
 de contactos. Cada contacto contiene un nombre (cadena de caracteres)
 y un número de teléfono (cadena de caracteres).

Tareas

 1. Agregar Contactos:
○ Usa los métodos de CircList para agregar varios contactos a la lista. Deberás
insertar al menos cinco contactos con nombres y números de teléfono distintos.

2. Mostrar Contactos:
○ Implementa una función que recorra la lista circular y muestre todos los
contactos en orden. Usa el método imprimir() de CircList.

3. Buscar un Contacto por Nombre:
○ Implementa una función que busque un contacto por su nombre. Usa el método
getDato(int pos) para acceder a los datos de los nodos y busca el
contacto en la lista.

4. Eliminar un Contacto por Nombre:
○ Implementa una función que elimine un contacto por su nombre. Deberás usar
los métodos getDato(int pos) y eliminarPorValor(T valor) (supón
que eliminarPorValor está implementado, aunque no esté explícito en el
código proporcionado).

5. Contar Contactos:
○ Usa el método getTamanio() para contar el número de contactos en la lista y
muestra el resultado.

 */

#include <iostream>
#include <string>
#include "Lista/CircList.h"
using namespace std;

// Menu
void menu(){
    cout << "1. Agregar Contactos" << endl;
    cout << "2. Mostrar Contactos" << endl;
    cout << "3. Buscar un Contacto por Nombre" << endl;
    cout << "4. Eliminar un Contacto por Nombre" << endl;
    cout << "5. Contar Contactos" << endl;
    cout << "6. Salir" << endl;
}

// Definición de la clase Contacto aquí
class Contacto {
public:
    string nombre;
    string telefono;

    /*Constructores*/
    Contacto() : nombre(""), telefono("") {}
    Contacto(const string &n, const string &t) : nombre(n), telefono(t) {}

    // Sobrecarga del operador <<
    friend ostream& operator<<(ostream &os, const Contacto &c) {
        os << "Nombre: " << c.nombre << ", Telefono: " << c.telefono;
        return os;
    }

    bool operator==(const Contacto& other) const {
        return nombre == other.nombre;
    }
};

// 2.Funcion mostrar la lista de contactos
void mostrarContactos(CircList<Contacto> &lista){
    if(lista.esVacia()){
        cout << "La lista de contactos esta vacia" << endl;
        return; // Salgo de la función
    }
    lista.imprimir();
}

// 3.Funcion buscar un contacto por nombre
bool buscarContacto(CircList<Contacto> &lista, string &nombre){
    for(int i=0; i<lista.getTamanio(); i++){
        Contacto c = lista.getDato(i);
        if(c.nombre == nombre){
            cout << "Contacto encontrado: " << c << endl;
            return true;
        }
    }
    cout << "Contacto no encontrado" << endl;
    return false;
}

// 4.Funcion eliminar un contacto por nombre
void eliminarContacto(CircList<Contacto> &lista, string &nombre){
    for(int i=0; i<lista.getTamanio(); i++){
        Contacto c = lista.getDato(i);
        if(c.nombre == nombre){
            lista.eliminarPorValor(c);
            cout << "Contacto eliminado: " << c << endl;
            return;
        }
    }
    cout << "Contacto no encontrado" << endl;
}

int main(){
    CircList<Contacto> lista;
    int opcion;
    string n;

    lista.insertarUltimo(Contacto("Juan", "123456"));
    lista.insertarUltimo(Contacto("Pedro", "654321"));
    lista.insertarUltimo(Contacto("Maria", "987654"));
    lista.insertarUltimo(Contacto("Jose", "456789"));
    lista.insertarUltimo(Contacto("Ana", "987654"));

    // Mostrar contactos
    cout << "Lista de contactos:" << endl;
    mostrarContactos(lista);

    // Buscar contacto
    cout << "Ingrese el nombre del contacto a buscar: ";
    getline(cin, n);
    buscarContacto(lista, n);

    // Eliminar contacto
    cout << "Ingrese el nombre del contacto a eliminar: ";
    getline(cin, n);
    eliminarContacto(lista, n);

    // Mostrar contactos
    cout << "Lista de contactos:" << endl;
    mostrarContactos(lista);

    return 0;

}