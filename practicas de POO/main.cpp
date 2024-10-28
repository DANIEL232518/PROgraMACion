using namespace std;

#include <iostream>
#include "Nodo.h"
#include "Arbol.h"

int main()
{
    Arbol<int> *ar = new Arbol<int>();

    ar->Insertar(23);
    ar->Insertar(14);
    ar->Insertar(7);
    ar->Insertar(5);
    ar->Insertar(31);
    ar->Insertar(37);
    ar->Insertar(27);

    ar->inOrden();
    cout<<endl;

    ar->postOrden();
    cout<<endl;

    ar->preOrden();
    //cout<<ar->cantNodos();

    return 0;

}