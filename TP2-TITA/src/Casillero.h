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
#include "Ficha.h"

enum EstadoDeCasillero{
	Vacio, Inactivo, Ocupado
};

enum TipoDeCasillero{
	Tierra, Aire, Agua, General
};

class Casillero {
private:
	EstadoDeCasillero estado;
	unsigned int posicionEnX;
	unsigned int posicionEnY;
	unsigned int posicionEnZ;
	TipoDeCasillero tipo;
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
	Ficha*& getFicha();

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


};



#endif /* CASILLERO_H_ */
