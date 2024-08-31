/*
Implementar una función que recibe una lista de números enteros y un número entero “n” y
que modifique la lista borrando todos los elementos de la lista que tengan el número “n”.
Imprimir la lista antes de hacer el llamado a la función y luego del llamado a la función para
mostrar que la lista original cambió. ej: lista: 1->2->3->4->5->3->7->8->3->10 con n=3 debe
pasar con la función a 1->2->4->5->7->8.
*/

#include <iostream>
#include "Lista/Lista.h"
using namespace std;

void borrarNumero(Lista<int> &lista, int n) {
    int tamanio = lista.getTamanio(); // Averiguo tamaño de la lista
    for(int i=0;i<tamanio;i++){
        if(lista.getDato(i) == n){
            lista.remover(i);
            i--; // Para que no se saltee el siguiente elemento
            tamanio--; // Para reducir el tamaño de la lista
        }
    }
}

void printLista(Lista<int> &lista) {
    int tamanio = lista.getTamanio(); // Averiguo tamaño de la lista

    for(int i = 0; i < tamanio; i++) {
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
        lista.insertarUltimo(d); // Inserto el valor en la lista
    }

    cout << "Ingrese el numero que quieres borrar \n";
    cin >> p;

    borrarNumero(lista,p);
    printLista(lista);
    
    return 0;
}
