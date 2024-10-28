#include <iostream>
using namespace std;
class Nodo{
    private:
        string dato;
        Nodo *izquierda;
        Nodo *derecha;
    public:
        Nodo();
        Nodo(Nodo *izquierda,string dato,Nodo *derecha){
        dato= dato;
        *izquierda= *izquierda;
        *derecha= *derecha;
        }
};

int main(){
    Nodo *INES= new Nodo(nullptr,"INES",nullptr);
    Nodo *CARLOS= new Nodo(nullptr,"CARLOS",nullptr);
    Nodo *JUANA= new Nodo(INES,"JUANA",CARLOS);
    Nodo *FELISA= new Nodo(nullptr,"FELISA",nullptr);
    Nodo *SOFIA= new Nodo(nullptr,"SOFIA",nullptr);
    Nodo *TOMAS= new Nodo(nullptr,"TOMAS",nullptr);
    Nodo *PEDRO= new Nodo(SOFIA,"PEDRO",TOMAS);
    Nodo *JOSE= new Nodo(FELISA,"JOSE",PEDRO);
    Nodo *Maria= new Nodo(JUANA,"MARIA",JOSE);
    return 0;
}