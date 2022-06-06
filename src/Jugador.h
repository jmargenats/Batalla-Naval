/*
 * Jugador.h
 *
 *  Created on: Jun 1, 2022
 *      Author: juli
 */

#ifndef JUGADOR_H_
#define JUGADOR_H_

#include <string>

class Jugador {
private:
	unsigned int numeroDeJugador;
	std::string nombreDeJugador;

public:
	/*
	 * pre: el unmero debe ser mayor o giual a 1
	 * 		el nombre debe ser diferente a vacio
	 * pos: se crea el jugador
	 */
	Jugador(unsigned int numero, std::string nombre);

	/*
	 * pos: destruye el jugador
	 */
	virtual ~Jugador();

	/*
	 * pos: devuelve el numero del jugador
	 */
	unsigned int getNumeroDeJugador();

	/*
	 * pos: devuelve el nombre del jugador
	 */
	std::string getNombreDeJugador();
};



#endif /* JUGADOR_H_ */
