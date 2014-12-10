#ifndef LISTA_H
#define LISTA_H

#include <iostream>
#include "Nodo.h"
using namespace std;


template <typename Tipo>
class Lista
{
public:
    Nodo<Tipo>* inicio;

    Lista()
    {
        inicio = NULL;
    }

    void imprimir()
    {
        for(Nodo<Tipo>* temp = inicio;
            temp!=NULL;
            temp = temp->sig)
        {
            cout<<temp->num<<endl;
        }
    }

    void agregarAlInicio(Tipo valor_nuevo)
    {
        Nodo<Tipo> *nuevo = new Nodo<Tipo>(valor_nuevo);

        if(inicio == NULL)
        {
            inicio = nuevo;
        }else
        {
            nuevo->sig = inicio;
            inicio = nuevo;
        }
    }

    void agregarAlFinal(Tipo valor_nuevo)
    {
        Nodo<Tipo> *nuevo = new Nodo<Tipo>(valor_nuevo);

        if(inicio == NULL)
        {
            inicio = nuevo;
        }else
        {
            Nodo<Tipo>*temp = inicio;
            while(temp->sig!=NULL)
            {
                temp=temp->sig;
            }
            temp->sig = nuevo;
        }
    }

    void borrar(Tipo valor_a_borrar)
    {
        if(inicio->num == valor_a_borrar)
        {
            Nodo<Tipo>* borrar = inicio;
            inicio = inicio->sig;
            delete borrar;
        }else
        {
            Nodo<Tipo>* temp = inicio;
            while(temp->sig->num!=valor_a_borrar)
            {
                temp=temp->sig;
                if(temp->sig==NULL)
                    return;
            }
            Nodo<Tipo>* borrar = temp->sig;
            temp->sig = temp->sig->sig;
            delete temp->sig;
        }
    }

    //Devuelve true si la lista esta vacia, de lo contrario devuelve false
    bool estaVacia()
    {
        //creamos un if con la condicion de que si inicio es igual a NULL que es un valor nulo o mejor dicho sin valor devuelva true
    if(inicio==NULL)
        {
        return true;
        }
        //de lo contrario devuelve false
        else
        {
        return false;
        }
    }

    //Devuelve el valor almacenado en el primer nodo de la lista
    Tipo obtenerPrimerValor()
    {
        //obtener el primer valor siempre es as acsesible, vasta con apuntar a el puntero de la lista en ese caso asi
        return inicio->valor;
    }

    //Devuelve el valor almacenado en el ultimo nodo de la lista
    Tipo obtenerUltimoValor()
    {
        //creamos un nodo con valor nulo en este caso le llame x
        Nodo<Tipo>*x = NULL;
        //creamos un ciclo que recora toda la lista desde el inicio hasta que se nulo en este caso el ultimo quedara guardado en la variable
        for(x = inicio; x->sig!=NULL; x = x->sig)
        {
        }
        //devolvemos el nodo x con el ultimo valor
        return x->valor;
    }

    //Devuelve el valor mayor almacenado en la lista
    Tipo obtenerMayor()
    {
        //creamos dos nodos uno  igual a inicio
        Nodo<Tipo>*x = inicio;
        Nodo<Tipo>*mayor;
        //creamos un ciclo while que termine cuando el calor almasenaco en el nodo sea nulo
        while(x!=NULL)
        {
        //aqui usamos el otro nodo en el cico que correra dentro de el while si mayor es menor que x
            if(mayor<x)
            {
                //mayor sera igual a x
                mayor = x;
            }
            // asi vmos avansando en los valores de x
            x=x->sig;
        }
        //aqui devolvemos el valor de mayor donde quedo almacenado el mayor fichero de la lista
    return mayor->valor;
    }

};
#endif // LISTA_H
