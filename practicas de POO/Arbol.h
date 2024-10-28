#include<vector>
template <class T>

class Arbol{
    private:
        Nodo<T> *raiz;
    public:
        Arbol(){
            raiz = NULL;
        }
        void Insertar(T v){
            Nodo<T> *n = new Nodo<T>(v);
            if(raiz == NULL)
                raiz = n;
            else
                Insertar(raiz, n);
        }
        void inOrden(){
            inOrden(raiz);
        }
        void postOrden(){
            postOrden(raiz);
        }
        void preOrden(){
            preOrden(raiz);
        }
        //altura
        int Altura() {
        return AlturaNodo(raiz);
        }
        //cantidad de nodos
        int CantidadNodos(){
            return ContarNodos(raiz);
        }
        //impresion en niveles
        void PorNivel(){
            PorNivel(raiz);
        }
    protected:
        void Insertar(Nodo<T> *r, Nodo<T> *n){
            //! lado izquierdo
            if(  r->retDato() > n->retDato() ){
                if(r->retHijoIzq() == NULL)
                    r->unirConIzq(n);
                else
                    Insertar(r->retHijoIzq(), n);
            }
            //! lado derecho
            if(  r->retDato() < n->retDato() ){
                if(r->retHijoDer() == NULL)
                    r->unirConDer(n);
                else
                    Insertar(r->retHijoDer(), n);
            }
        }
        void inOrden(Nodo<T> *r){
            if(r != NULL)
            {
                inOrden(r->retHijoIzq());
                cout<<r->retDato()<<" ";
                inOrden(r->retHijoDer());
            }
        }

        void postOrden(Nodo<T> *r){
            if(r != NULL)
            {
                postOrden(r->retHijoIzq());
                postOrden(r->retHijoDer());
                cout<<r->retDato()<<" ";
            }
        }
        void preOrden(Nodo<T> *r){
            if(r !=NULL)
            {
              cout<<r->retDato()<<" ";
              preOrden(r->retHijoIzq());
              preOrden(r->retHijoDer());  
            }
        }
        /*DESARROLLAR LA INSERCION DE NODOS EN EL ARBOL DE FORMA ITERATIVA:
        void Insertar(T v){
            Nodo<T> *n=new Nodo<T>(v);
            if(raiz==null){
                raiz=n;
                return;
            }
            Nodo<T>* actual =raiz;
            Nodo<T>* padre= NULL

            while(actual != NULL)
                {
                    padre = actual;
                    if (v<actual->dato){
                        actual=actual->hijoIzq;}
                    else{
                        actual=actual->hijoDer;
                    }
                }
                if (v<padre->dato){
                    padre->hijoIzq =n;
                }else{
                    padre->hijoDer =n;
                }
        }*/
    //altura del arbol
    int AlturaNodo(Nodo<T>* nodo) {
        if (nodo == nullptr) {
            return -1; // Devuelve -1 si el nodo es nulo
        }
        int alturaIzquierda = AlturaNodo(nodo->retHijoIzq());
        int alturaDerecha = AlturaNodo(nodo->retHijoDer());
        return 1 + max(alturaIzquierda, alturaDerecha);
    }
        int ContarNodos(Nodo<T>*nodo){
            if (nodo== NULL){
                return 0;
            }
            return 1 + ContarNodos(nodo->retHijoIzq()) + ContarNodos(nodo->retHijoDer());
        }
        //impresion por niveles
        void PorNivel(Nodo<T>* nodo) {
        if (nodo == nullptr) return;

        vector<Nodo<T>*> nodosPorNivel; // Usar un vector como "cola"
        nodosPorNivel.push_back(nodo); // Comenzar desde la raíz

        int indice = 0; // Indice del siguiente nodo a procesar

        while (indice < nodosPorNivel.size()) {
            Nodo<T>* actual = nodosPorNivel[indice]; // Obtener el nodo actual
            cout << actual->retDato() << " "; // Imprimir el nodo actual

            // Añadir los hijos a la lista
            if (actual->retHijoIzq() != nullptr) {
                nodosPorNivel.push_back(actual->retHijoIzq());
            }
            if (actual->retHijoDer() != nullptr) {
                nodosPorNivel.push_back(actual->retHijoDer());
            }
            indice++;
        }
        }
 };