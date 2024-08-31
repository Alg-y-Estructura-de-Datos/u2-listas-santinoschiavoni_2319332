/*
Implementar una función que intercambie los elementos entre 2 listas de números enteros
que recibe como parámetros. Si los tamaños de las listas son distintos, igual debe cambiar los
datos y cambiarían los tamaños de cada lista. Ejemplo sea lista1= 15->1->8->35->40->25->12 y
lista2= 3->4->912->45->66 al ejecutar la función quedarían lista1= 3->4->912->45->66 y
lista2=15->1->8->35->40->25->12.
*/

#include <iostream>
#include "Lista/Lista.h"
using namespace std;

void intercambiar(Lista<int> &lista1, int &tamanio1,Lista<int> &lista2, int &tamanio2){
    Lista<int> aux;
    int tamanioAux = tamanio1;

    for(int i=0; i<tamanio1; i++){
        aux.insertarUltimo(lista1.getDato(i)); // Inserto el valor en la lista auxiliar
    }

    lista1.vaciar();
    tamanio1 = 0;

    for(int i=0; i<tamanio2; i++){
        lista1.insertarUltimo(lista2.getDato(i)); // Inserto el valor en la lista 1
        tamanio1++;
    }

    lista2.vaciar();
    tamanio2 = 0;

    for(int i=0; i<tamanioAux; i++){
        lista2.insertarUltimo(aux.getDato(i)); // Inserto el valor en la lista 2
        tamanio2++;
    }
}

void printLista1(Lista<int> &lista1) {
    int tamanio = lista1.getTamanio(); // Averiguo tamaño de la lista

    for(int i = 0; i < tamanio; i++) {
        cout << lista1.getDato(i) << "->";
    }
    cout << "NULL" << endl;
}

void printLista2(Lista<int> &lista2) {
    int tamanio = lista2.getTamanio(); // Averiguo tamaño de la lista

    for(int i = 0; i < tamanio; i++) {
        cout << lista2.getDato(i) << "->";
    }
    cout << "NULL" << endl;
}

int main() {
    Lista<int> lista1;
    Lista<int> lista2;
    int tamanio1,tamanio2,num;

    cout << "Ingrese tamaño de la lista 1 \n";
    cin >> tamanio1;

    for(int i=0; i<tamanio1; i++){
        cout << "Ingrese el valor de la lista 1 en la posicion " << i << "\n";
        cin >> num;
        lista1.insertarUltimo(num); // Inserto el valor en la lista
    }

    cout << "Ingrese tamaño de la lista 2 \n";
    cin >> tamanio2;

    for(int i=0; i<tamanio2; i++){
        cout << "Ingrese el valor de la lista 2 en la posicion " << i << "\n";
        cin >> num;
        lista2.insertarUltimo(num); // Inserto el valor en la lista
    }

    intercambiar(lista1,tamanio1,lista2,tamanio2);

    cout << "******LISTA 1********* \n ";
    printLista1(lista1);

    cout << "******LISTA 2********* \n ";
    printLista2(lista2);
    return 0;
}
