/*
Gestión de Historial de Navegación en un Navegador
Desarrolla un programa que simule el historial de páginas web visitadas en un navegador
utilizando una lista doblemente enlazada. El programa debe permitir al usuario retroceder y
avanzar entre las páginas visitadas, mostrando sus direcciones en pantalla.
Requisitos:
1. Estructura de Datos:
○ Usa el concepto de una lista doblemente enlazada para mantener el historial de
páginas web visitadas.
○ Cada nodo de la lista debe almacenar la URL de la página web visitada.
2. Funciones del Programa:
○ Añadir Página: Permite agregar una nueva URL al final del historial de
navegación.
○ Mostrar Histórico: Muestra todas las URLs del historial desde la más antigua a la
más reciente.
○ Retroceder: Permite al usuario retroceder a la página web visitada
anteriormente, mostrando la URL en pantalla.
○ Avanzar: Permite al usuario avanzar a la siguiente página web en el historial,
mostrando la URL en pantalla.
3. Interfaz del Usuario:
○ La interfaz debe ser de línea de comandos y debe permitir al usuario ingresar
URLs y navegar a través del historial usando comandos simples.
○ Implementa un menú para que el usuario pueda elegir entre las opciones
disponibles: añadir una página, mostrar el historial, retroceder, avanzar, y salir
del programa.
*/

using namespace std;
#include <iostream>
#include <string>
#include "Lista/ListaDoble.h"
#include <thread>
#include <chrono>

void menu(){
    cout << "1. Anadir Pagina" << endl;
    cout << "2. Mostrar Historico" << endl;
    cout << "3. Retroceder" << endl;
    cout << "4. Avanzar" << endl;
    cout << "5. Salir" << endl;
}
void mostrarPaginaActual(ListaDoble<string>& historial, int& pos){
    if(pos>=0 && pos<historial.getTamanio()){
        cout << "***************************" << endl;
        cout << "Estas en la pagina: " << historial.getDato(pos) << endl;
    } else {
        cout << "No hay páginas visitadas." << endl;
    }
    
}

void avanzar(ListaDoble<string>& historial, int& pos){
    if (pos < historial.getTamanio()-1){
        pos++;
        cout << "Avanzando a: " << historial.getDato(pos) << endl;
    } else {
        cout << "No hay más páginas para avanzar." << endl;
    }  
}

void retroceder(ListaDoble<string>& historial, int& pos){
    if (pos > 0){
        pos--;
        cout << "Retrocediendo a: " << historial.getDato(pos) << endl;
    } else {
        cout << "No hay más páginas para retroceder." << endl;
    }
}



int main(){
    ListaDoble<string> historial;
    int pos = -1;
    string url;
    int opcion = 0;
    do{
        menu();
        cout << "Ingrese una opcion: ";
        cin >> opcion;
        mostrarPaginaActual(historial, pos);
        switch(opcion){
            cout << "" << endl;
            case 1:
                cout << "Ingrese una url: " << endl;
                cin.ignore();
                getline(cin,url,'\n');
                historial.insertarUltimo(url);
                cout << "" << endl;
                pos++;
            break;
            case 2:
                historial.imprimir();
                cout << "" << endl;
            break;
            case 3:
                retroceder(historial, pos);
                cout << "" << endl;
            break;
            case 4:
                avanzar(historial, pos);
                cout << "" << endl;
            break;
            case 5: 
                cout << "Saliendo..." << endl;
            break;
        }
    }while(opcion!=5);
}