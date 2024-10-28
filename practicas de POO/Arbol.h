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
    //DESARROLLAR LOS 3 RECORRIDOS EN FORMA ITERATIVA
    
};
