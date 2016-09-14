#include "ListaCircular.h"

ListaCircular::ListaCircular()
{
	this->h = NULL;
	this->t = NULL;
}

ListaCircular::ListaCircular(int dato)
{
	Nodo *n = new Nodo(dato, n);
	this->h = n;
	this->t = n;
}

bool ListaCircular::isEmpty()
{
	return (this->h == NULL && this->t = NULL);
}

void ListaCircular::addInicio(int dato)
{
	Nodo *n = new Nodo(dato);
	if (this->isEmpty())
	{
		this->t = n;
	}
	this->h = n;
	this->t->setNext(h);
}

void ListaCircular::addFinal(int dato)
{
	Nodo *n = new Nodo(dato);
	if(isEmpty())
	{
		this->h = n;
	}
	else
	{
		this->t = setSig(n);
	}
	this->t = n;
	this->t->setSig(h);
}

/*	Agrega el dato en la posición -ref-
	(El primer elemento es -lista[0]-)
	Si la lista contiene menos elementos que ref,
	el dato se agrega al final.
 */
void ListaCircular::addAt(int dato, int ref)
{
	if (!this.isEmpty())
	{
		Nodo *aux = this->h;
		for (int i = 0; i < (ref - 1) ; ++i)
		{
			if (aux->getNext() == this->t || aux->getNext() == NULL)
			{
				std::cout << "El tamaño de la lista es menor, se agregará al final..." << std:endl;
				ListaCircular::addFinal(dato);
				return;
			}
			aux = aux->getNext();
		}
		Nodo *n = new Nodo(dato, aux->getNext());
		aux->setNext(n);
		return;
	}
	std::cout << "La lista está vacía, se agregará el dato al inicio..." << std::endl;
}