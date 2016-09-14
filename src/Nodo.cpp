/**
 *	Autor: Daniel Ponce de León Súchil
 */

#include "Nodo.h"

Nodo::Nodo(int dato)
{
	this->dato = dato;
	this->next = NULL;
}

Nodo::Nodo(int dato, Nodo *next)
{
	this->dato = dato;
	this->next = next;
}

int Nodo::getDato()
{
	return this->dato;
}

Nodo *Nodo::getNext()
{
	return this->next;
}

void Nodo::setDato(int dato)
{
	this->dato = dato;
}

void Nodo::setNext(Nodo *next)
{
	this->next = next;
}