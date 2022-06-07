/*
 * PosicionarJugadores.h
 *
 *  Created on: Jun 7, 2022
 *      Author: juli
 */

#ifndef POSICIONARJUGADORES_H_
#define POSICIONARJUGADORES_H_
#include "Lista.h"
#include "Casillero.h"

class PosicionarJugadores {
private:
	Lista<Jugador*>* jugadores;
public:
	/*
	 * pre: -
	 * pos: posicionar a
	 */
	PosicionarJugadores(Lista<Jugador*>);

};



#endif /* POSICIONARJUGADORES_H_ */
