/*
 * BatallaCampal.h
 *
 *  Created on: Jun 1, 2022
 *      Author: juli
 */

#ifndef BATALLACAMPAL_H_
#define BATALLACAMPAL_H_

#include "Lista.h"
#include "Tablero.h"

class BatallaCampal{
private:
	unsigned int numeroDeJugadores;
	unsigned int yMaximo;
	unsigned int xMaximo;
	unsigned int zMaximo;
	unsigned int cantidadDeSoldados;
	Lista<Jugador*>* jugadores;
	Tablero *tablero;
public:
	/*
	 * pre: todos los atributos ingresados deben ser mayores a 0
	 * pos: asigna los datos
	 */
	BatallaCampal(unsigned int x, unsigned int y, unsigned int z, unsigned int numeroDeJugadores, unsigned int cantidadDeSoldados);

	/*
	 * pre:
	 * pos: devuelve el x maximo;
	 */
	unsigned int getXMaximo();

	/*
	 * pre:
	 * pos: devuelve el y maximo;
	 */
	unsigned int getYMaximo();

	/*
	 * pre:
	 * pos: devuelve el z maximo;
	 */
	unsigned int getZMaximo();

	/*
	 * pre:
	 * pos: edvuelve la cantidad ed jugadores
	 */
	unsigned int getNumeroDeJUgadores();

	/*
	 * pre: -
	 * pos: genera una lista de los jugadores
	 */
	void setJugadores();

	/*
	 * pre: -
	 * pos: devuelve true si la longitud de la lista de jugadores es mayor a 1
	 */
	bool seguirJugando();

	/*
	 * pre: -
	 * pos: devuelve true si el numero del jugador se encuentra entre las opciones.
	 */
	bool validarNumeroDeJugador(unsigned int numero);

	/*
	 * pre: el casillero x, y y z deben estar en los limites del cubo, y el numero de jugador debe estar en la lista
	 * pos: ataca al lugar especifico;
	 *
	 */
	void atacar (unsigned int x, unsigned int y, unsigned int z,TipoDeFicha tipo, unsigned int numeroDeJugador);

	void turno();

	void iniciarSoldados();

	virtual~ BatallaCampal();
};




#endif /* BATALLACAMPAL_H_ */
