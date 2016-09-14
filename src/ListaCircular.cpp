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
	this->h = NULL;
	this->t = NULL;
}

void ListaCircular::show()
{
	if (this->isEmpty())
	{
		cout << "La lista está vacía." << endl;
		return;
	}
	cout << "[ ";
	for (Nodo *aux = this->h ; aux != this->t ; aux = aux->getNext())
	{
		cout << aux->getDato() << " , ";
	}
	cout << this->t->getDato() << " ]" << endl;
}

void ListaCircular::addInicio(int dato)
{
	Nodo *n = new Nodo(dato, this->h);
	if (this->isEmpty())
	{
		this->t = n;
	}
	this->h = n;
	this->t->setNext(this->h);
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
 *	Agrega el dato en la posición -ref-, recorriendo
 *	todos los posteriores.
 *
 *	El primer elemento es lista[0].
 *
 *	Si la lista contiene menos elementos que ref, el
 *	dato se agrega al final.
 */
void ListaCircular::addAt(int dato, int ref)
{
	if (ref <= 0)
	{
		if (ref < 0)
		{
			cout << "Referencia inválida, agregando al inicio..." << endl;
		}
		addInicio(dato);
		return;
	}
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
	if (this->h == this->t)
	{
		this->h == NULL;
		this->t == NULL;
	}
	else
	{
		this->h = this->h->getNext();
		this->t->setNext(this->h);
	}
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

/**
 *	Regresa el dato en la posición -ref- ,eliminandolo
 *	y recorriendo los posteriores hacia atrás.
 *
 *	El primer elemento es lista[0].
 *
 *	Si -ref- es mayor al tamaño de la lista, no se hace
 *	nada.
 */
int ListaCircular::popAt(int ref)
{
	if (ref <= 0)
	{
		if (ref < 0)
		{
			cout << "Referencia inválida, retirando al inicio..." << endl;
		}
		return popInicio();
	}
	if (this->isEmpty())
	{
		cout << "La lista está vacía." << endl;
		return 0;
	}
	Nodo *n = this->h;
	for (int i = 0 ; i < (ref - 1) ; ++i)
	{
		if (n->getNext() == this->t || n->getNext() == this->h)
			{
				cout << "El tamaño de la lista es menor, se eliminará el último elemento..." << endl;
				return popFinal();
			}
		n = n->getNext();
	}
	int dato = n->getNext()->getDato();
	if (n->getNext() == this->t)
	{
		this->t = n;
		this->t->setNext(this->h);
	}
	else
	{
		n->setNext(n->getNext()->getNext());
	}
	return dato;
}

Nodo *ListaCircular::getElement(int dato)
{
	if (this->isEmpty())
	{
		cout << "La lista está vacía." << endl;
		return NULL;
	}
	Nodo *n = this->h;
	while (n->getDato() != dato && n->getNext() != this->h)
	{
		n = n->getNext();
	}
	if (n->getDato() == dato)
	{
		return n;
	}
	//Si n.dato != dato y n == t, entonces no se encontró
	cout << "No existe el elemento." << endl;
	return NULL;
}

Nodo *ListaCircular::getH()
{
	return this->h;
}

Nodo *ListaCircular::getT()
{
	return this->t;
}