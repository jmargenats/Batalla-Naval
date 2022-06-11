/*
 * Ficha.h
 *
 *  Created on: Jun 1, 2022
 *      Author: juli
 */

#ifndef FICHA_H_
#define FICHA_H_
#include "Jugador.h"

enum TipoDeFicha{
	Soldado, Barco, Avion
};
class Ficha {
private:
	TipoDeFicha tipo;
	Jugador *jugador;
	//unsigned int numero;

public:
	/*
	* pre:jugador no debe ser vacio
	* pos:se crea la ficha con el tipo y el jugador dado)
	*/
	Ficha (TipoDeFicha tipo, Jugador *jugador);//, unsigned int numero);

	/*
	* pre: -
	* pos: -
	*/
	virtual ~Ficha();

	/*
	* pre: -
	* pos: devuelve el numero de la ficha
	*/
	unsigned int getNumero();

	/*
	* pre: -
	* pos: devuelve el jugador
	*/
	Jugador* getJugador();

	/*
	* pre: -
	* pos: devuelve el tipo de ficha (avion, soldado, etc)
	*/
	TipoDeFicha getTipo();


};



#endif /* FICHA_H_ */
