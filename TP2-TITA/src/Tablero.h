/*
 * Tablero.h
 *
 *  Created on: Jun 1, 2022
 *      Author: juli
 */

#ifndef TABLERO_H_
#define TABLERO_H_
#include "Casillero.h"
#include "ColocarFicha.h"
#include"Lista.h"

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

	/*
	 * pre: la x, y y z no deben ser menores a 1 ni mayores al sus respectivos maximos
	 * pos: devuelve un puntero al casillero correspondiente.
	 */
	Casillero* getCasillero(unsigned int x, unsigned int y, unsigned int z);

	/*
	 * pre: la x, y y z no deben ser menores a 1 ni mayores al sus respectivos maximos
	 * pos: en la casilla correspondiente la ficha indicada
	 */
	void setFicha(unsigned int x, unsigned int y, unsigned int z, Ficha* ficha);

	/*
	 * pre: -
	 * pos: devuelve true si los valores ingresados estan dentro del rango correcto
	 */
	bool verificarValoresIngresados(unsigned int x, unsigned int y, unsigned int z);

	/*
	 * pre: los valores ingresados se deben verificar
	 * pos: coloca la ficha en el tablero
	 */
	void colocarFicha(unsigned int x, unsigned int y, unsigned int z, TipoDeFicha tipo,Jugador* jugador, Tablero* tablero, Lista<Jugador*>* jugadores);

	/*
	 *pre: -
	 *pos: devuelve NULL si no encuentra la ficha en el tablero y devuelve la ficha en cuestion
	 */
	Ficha* encotrarFichaEspecifica(unsigned int numeroDeFicha, TipoDeFicha tipo, unsigned int numeroDeJugador);

	/*pre:
	 * pos: imprime el mapa
	 */
	void imprimirMapa();

	virtual~ Tablero();
};

void mostrarTablero();


#endif /* TABLERO_H_ */
