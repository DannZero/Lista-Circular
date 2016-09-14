#include <iostream>
#include "ListaCircular.h"
using namespace std;

int main()
{
    int opc;
    do
    {
        cout << "1. addInicio" << endl;
        cout << "2. addFinal" << endl;
        cout << "3. addAt" << endl;
        cout << "4. removeInicio" << endl;
        cout << "5. removeFinal" << endl;
        cout << "6. removeAt" << endl;
        cout << "7. show" << endl << endl;
        cout << "0. Salir del Programa..." << endl;
        cin >> opc;
        switch (opc)
        {
        case 1:
            //
            break;
        case 2:
            //
            break;
        case 3:
            //
            break;
        case 4:
            //
            break;
        case 5:
            //
            break;
        case 6:
            //
            break;
        case 7;
            //
            break;
        case 0:
            break;
        default:
            cout << "Opcion invalida." << endl;
        }
    } while (opc != 0);
    return 0;
}
