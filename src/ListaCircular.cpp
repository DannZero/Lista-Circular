/**
 *	Autor: Daniel Ponce de León Súchil
 */

#include "ListaCircular.h"
using namespace std;

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
	return (this->h == NULL && this->t == NULL);
}

bool ListaCircular::vaciar()
{
	Nodo *aux = h;
	while (!this->t->getNext() == 0)
	{
		h = NULL;
		h = aux->getNext();
	}
}

void ListaCircular::show()
{
	if (this->isEmpty())
	{
		cout << "La lista está vacía." << endl;
		return;
	}
	for (Nodo *aux = this->h ; aux != this->t ; aux = aux->getNext())
	{
		cout << aux->getDato() << endl;
	}
	cout << this->t->getDato() << endl;
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
	if(this->isEmpty())
	{
		this->h = n;
	}
	else
	{
		this->t->setNext(n);
	}
	this->t = n;
	this->t->setNext(h);
}

/**
 *	Agrega el dato en la posición -ref-
 *	(El primer elemento es -lista[0]-)
 *	Si la lista contiene menos elementos que ref,
 *	el dato se agrega al final.
 */
void ListaCircular::addAt(int dato, int ref)
{
	if (!this->isEmpty())
	{
		Nodo *aux = this->h;
		for (int i = 0; i < (ref - 1) ; ++i)
		{
			if (aux->getNext() == this->t || aux->getNext() == this->h)
			{
				cout << "El tamaño de la lista es menor, se agregará al final..." << endl;
				this->addFinal(dato);
				return;
			}
			aux = aux->getNext();
		}
		Nodo *n = new Nodo(dato, aux->getNext());
		aux->setNext(n);
		return;
	}
	cout << "La lista está vacía, se agregará el dato al inicio..." << endl;
	this->addInicio(dato);
}

int ListaCircular::popInicio()
{
	if (this->isEmpty())
	{
		cout << "La lista está vacía." << endl;
		return 0;
	}
	int dato = this->h->getDato();
	this->h = this->h->getNext();
	this->t->setNext(this->h);
	return dato;
}

int ListaCircular::popFinal()
{
	if (this->isEmpty())
	{
		cout << "La lista está vacía." << endl;
		return 0;
	}
	int dato = this->t->getDato();
	if (this->h == this->t)
	{
		this->h == NULL;
		this->t == NULL;
		return dato;
	}
	Nodo *n = this->h;
	while (n->getNext() != this->t)
	{
		n = n->getNext();
	}
	this->t = n;
	this->t->setNext(this->h);
	return dato;
}