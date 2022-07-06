

#include <iostream>
#include <string>
using namespace std;
#include "BatallaCampal.h"

int main (){
	//unsigned int x, unsigned int y, unsigned int z, unsigned int numeroDeJugadores, unsigned int cantidadDeSoldados
	BatallaCampal* juego = new BatallaCampal(10,10,10,2,2);

	delete juego;

	return 0;
}



