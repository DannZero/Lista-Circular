#include "Nodo.h"

class ListaCircular
{
public:
	ListaCircular();
	ListaCircular(int dato);
	bool isEmpty();
	void show();
	//Add y pop
	void addInicio(int dato);
	void addFinal(int dato);
	void addAt(int dato, int ref);
	int popInicio();
	int popFinal();
	int popAt(int ref);
	//Busqueda
	Nodo *hasElement(int dato);
	//Getters y setters
	Nodo *getH();
	Nodo *getT();
	void setH(Nodo *h);
	void setT(Nodo *T);

private:
	Nodo *h;
	Nodo *t;
};