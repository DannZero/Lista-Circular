/**
 *	Autor: Daniel Ponce de León Súchil
 */

#include "Nodo.h"

class ListaCircular
{
public:
	ListaCircular();
	ListaCircular(int dato);
	bool isEmpty();
	bool vaciar();
	void show();
	//Add y pop
	void addInicio(int dato);
	void addFinal(int dato);
	void addAt(int dato, int ref);
	int popInicio();
	int popFinal();
	int popAt(int ref);
	//Busqueda
	Nodo *getElement(int dato);
	//Getters y setters
	Nodo *getH();
	Nodo *getT();

private:
	Nodo *h;
	Nodo *t;
};