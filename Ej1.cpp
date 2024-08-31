/*
Implementar una función llamada “printLista” que reciba una lista y una posición “p” 
e imprima los elementos de esa lista a partir de la posición “p”. 
No debe modificarse la lista original. 
Ej: listaOriginal: 1->2->3->4->5->6->7->8->9->10 con p=5 Por pantalla se verá: 5->6->7->8->9->10
 */

#include <iostream>
#include "Lista/Lista.h"

using namespace std;

void printLista(Lista<int> &lista, int p) {
    int tamanio = lista.getTamanio(); // Averiguo tamaño de la lista

    // CONTROL DE ERRORES
    if(p >= tamanio || p < 0) {
        cout << "Posicion invalida" << endl;
        return;
    }

    for(int i = p; i < tamanio; i++) {
        cout << lista.getDato(i) << "->";
    }
    cout << "NULL" << endl;
}

int main() {
    Lista<int> lista;
    int n,d,p;

    cout << "Ingrese tamaño de la lista \n";
    cin >> n;

    for(int i=0; i<n; i++){
        cout << "Ingrese el valor de la lista en la posicion " << i << "\n";
        cin >> d;
        lista.insertarUltimo(d);
    }

    cout << "Ingrese la posicion desde donde deseas imprimir la lista \n";
    cin >> p;

    printLista(lista,p);
    return 0;
}

