

#include <iostream>
#include <string>
using namespace std;
#include "BatallaCampal.h"

int main (){


	unsigned int x, y, z, numeroJugadores, cantidadSoldados;
	cout << "Bienvenido a la Batalla Campal" << endl;
	cout << "Ingrese la cantidad de columnas" << endl;
	cin >> x;
	cout << "Ingrese la cantidad de filas" << endl;
	cin >> y;
	cout << "Ingrese la cantidad de niveles" << endl;
	cin >> z;
	cout << "Ingrese la cantidad de jugadores" << endl;
	cin >> numeroJugadores;
	cout << "Ingrese la cantidad de soldados" << endl;
	cin >> cantidadSoldados;

	BatallaCampal* juego = new BatallaCampal(x,y,z,numeroJugadores,cantidadSoldados);

	//BatallaCampal* juego = new BatallaCampal(10,10,10,2,1);
	delete juego;

	return 0;
}



