/*
 * Tablero.h
 *
 *  Created on: Jun 1, 2022
 *      Author: juli
 */

#ifndef TABLERO_H_
#define TABLERO_H_
#include"Lista.h

class Tablero{
private:
	Lista<Lista<Lista<Casillero *> *> *> * casilleros;
	unsigned int xMaximo; // largo
	unsigned int yMaximo; // profundidad
	unsigned int zMaximo; //altura
public:
	/*
	 *pre: x, y, y z deben ser mayores a 0
	 *pos: inicializa el tablero con los casilleros con su correspondiente casillero.
	 */
	Tablero(unsigned int xMaximo, unsigned int yMaximo, unsigned int zMaximo);
	virtual~ Tablero();
};



#endif /* TABLERO_H_ */