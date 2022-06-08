/*
 * Jugador.h
 *
 *  Created on: Jun 1, 2022
 *      Author: juli
 */

#ifndef JUGADOR_H_
#define JUGADOR_H_

#include <string>
#include "Casillero.h"

class Jugador {
private:
	unsigned int numeroDeJugador;
	//std::string nombreDeJugador;
	unsigned int numeroDeSoldados;

public:
	/*
	 * pre: el unmero debe ser mayor o giual a 1
	 * 		el nombre debe ser diferente a vacio
	 * pos: se crea el jugador
	 */
	Jugador(unsigned int numero); //std::string nombre);

	/*
	 * pos: destruye el jugador
	 */
	virtual ~Jugador();

	/*
	 * pos: devuelve el numero del jugador
	 */
	unsigned int getNumeroDeJugador();

	unsigned int getNumeroDeSoldados();
	/*
	 * pos: devuelve el nombre del jugador
	 */
	//std::string getNombreDeJugador();

	/*
	 *
	*/
	//*Carta sacarCarta(); -> No existe ningún TDA Carta

	/*
	 * pre: La posición seleccionada para el ataque deberá ser valida
	   post: Si hay un soldado o armamento se elimina, la casilla quedará inactiva haya soldado o no
	*/
	void atacar(Casillero* posicionEnX, Casillero* posicionEnY, Casillero* posicionEnZ, Ficha* TipoDeFicha, unsigned int numeroDEJugador);


	/*
	 * pre: el numero de soldados debe ser mayor a 0
	 * pos: resta un soldado al contador de soldados
	 */
	void restarSoldado();

	void sumarSoldado();

	void moverSoldadoOArmamento(Casillero* posicionEnX, Casillero* posicionEnY, Casillero* posicionEnZ, Casillero* nuevaPosicionEnX, Casillero* nuevaPosicionEnY, Casillero* nuevaPosicionEnZ);

	/*
	 * pre: Recibe posiciones validas
	   post: Valida que el movimiento a realizar sea horizontal, vertical o diagonal
	*/
	bool validarMovimiento(Casillero* x, Casillero* y, Casillero* z, Casillero* xNueva, Casillero* yNueva, Casillero* zNueva);
};



#endif /* JUGADOR_H_ */
