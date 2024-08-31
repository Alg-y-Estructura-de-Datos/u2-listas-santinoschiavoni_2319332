/*
Sistema de Monitor Publicitario Circular
Desarrolla un programa para gestionar un monitor publicitario que debe mostrar frases de
anuncios de manera circular. Para lograr esto, implementarás una solución utilizando una lista
circular simplemente enlazada.
Requisitos:
1. Frases de Anuncios:
○ Cada frase de anuncio será un texto simple que el monitor debe mostrar por
vez.
2. Mostrar Circularmente:
○ Las frases deben mostrarse en un formato circular, es decir, una vez que se ha
mostrado la última frase, el monitor debe volver a mostrar la primera y así
infinitamente.
3. Implementación:
○ Utiliza una lista circular simplemente enlazada para gestionar el almacenamiento
y la visualización de las frases. La lista circular debe permitir el recorrido
continuo de los elementos.
4. Operaciones Básicas:
○ Agregar Frases: Capacidad para añadir nuevas frases a la lista circular.
○ Eliminar Frases: Capacidad para eliminar frases específicas de la lista.
○ Mostrar Frases: Implementa una función para mostrar las frases en el monitor
de manera continua, recorriendo circularmente la lista e infinitamente.
*/

using namespace std;
#include <iostream>
#include <string>
#include "Lista/CircList.h"
#include <thread>
#include <chrono>

template <typename T>
void mostrarFrasesCircular(CircList<T>& lista) {
    if (lista.esVacia()) {
        cout << "No hay frases para mostrar." << endl;
        return;
    }

    int pos = 0; // Empezamos desde la posición 0

    while (true) { // Bucle infinito para mostrar las frases circularmente
        cout << lista.getDato(pos) << endl; // Mostrar el dato en la posición actual
        pos = (pos + 1) % lista.getTamanio(); // Avanzar a la siguiente posición, circularmente

        // Introducir un retraso de 1 segundo
        this_thread::sleep_for(chrono::seconds(1)); // Retraso de 1 segundo
    }
}

void menu(){
    cout << "1. Agregar Frase" << endl;
    cout << "2. Eliminar Frase" << endl;
    cout << "3. Mostrar Frases" << endl;
    cout << "4. Salir" << endl;
}

int main(){
    CircList<string> lista;
    string frase;
    int opcion, cant_frases = 0;
    menu();
    do{
        cout << "Ingrese una opcion: ";
        cin >> opcion;
        switch(opcion){
            case 1:
                cout << "Maximo: 5 frases" << endl;
                for(int i = 0; i < 5; i++){
                    cout << "Ingrese la frase: " << i+1 << endl;
                    cin.ignore();
                    getline(cin,frase,'\n');
                    lista.insertarUltimo(frase);
                    cant_frases++;
                }

            break;
            case 2:
                cout << "Ingrese la frase que deseas elimnar" << endl;
                getline(cin,frase,'\n');
                lista.eliminarPorValor(frase);
            break;
            case 3:
            cout << "---------------------------------------" <<endl;
                mostrarFrasesCircular(lista);
            break;
            case 4:
                cout << "Saliendo..." << endl;
        }
    }while(opcion != 4);
}