/*
 * Casillero.h
 *
 *  Created on: Jun 1, 2022
 *      Author: juli
 */

#ifndef CASILLERO_H_
#define CASILLERO_H_
#ifndef NULL
#define NULL
#endif
#include "Enums.h"
#include "Ficha.h"

class Ficha;
class Casillero {
private:
	EstadoDeCasillero estado;
	unsigned int posicionEnX;
	unsigned int posicionEnY;
	unsigned int posicionEnZ;
	TipoDeCasillero tipo;
	Casillero* vecinos[3][3][3];
	Ficha * ficha;

public:
	/*
	 *pre: - x, y y z  deben ser mayor o igual a 1
	 *pos: queda seteado el casillero con los valores
	 */
	Casillero(unsigned int x, unsigned int y, unsigned int z, TipoDeCasillero tipo);

	/*
	 *pre: -
	 *pos: elimina el casillero
	 */
	virtual~ Casillero();

	/*
	 * pos: devuelve el estado del casillero
	 */
	EstadoDeCasillero getEstado() const;

	/*
	 * pre: el casillero no puede estar inactivo
	 * pos: setea el estado del casillero
	 */
	void setEstado(EstadoDeCasillero estado);


	/*
	 * pre: -
	 * pos: devuelve la posicion en x
	 */
	unsigned int getPosicionEnX() const;


	/*
	 * pre: -
	 * pos: devuelve la posicion en y
	 */
	unsigned int getPosicionEnY() const;


	/*
	 * pre: -
	 * pos: devuelve la posicion en z
	 */
	unsigned int getPosicionEnZ() const;


	/*
	 * pre: -
	 * pos: devuelve el tipo de casilleto (aire, tierra, agua o general)
	 */
	TipoDeCasillero getTipo() const;

	/*
	 * pos: devuelve a la ficha que hay en ese casillero
	 */
	Ficha* getFicha();

	/*
	 * pre: la ficha no es vacia
	 * pos: La ficha del casillero cambia
	 */
	void setFicha(Ficha*& ficha);

	/*
	 * pre: el casillero debe tener una ficha asignada
	 * pos: vacia el casillero
	 */
	void vaciar();

	/*
	 *
	 */
	void setVecino(Casillero* casillero, int x, int y, int z);

	Casillero* getVecino(int x, int y, int z);


};



#endif /* CASILLERO_H_ */
