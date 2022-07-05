/*
 * Tablero.h
 *
 *  Created on: Jun 1, 2022
 *      Author: juli
 */

#ifndef TABLERO_H_
#define TABLERO_H_
#include "Lista.h"
#include "Casillero.h"
#include "Enums.h"
class Casillero;
class Ficha;

class Jugador;
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
	 * elimina un jugador
	 */
	void eliminarJugador(Jugador* jugador, Lista<Jugador*>* jugadores);

	/*pre:
	 * pos: imprime el mapa
	 */
	void imprimirMapa();

	/*
	 * devuelve los casilleros
	 */

	Lista<Lista<Lista<Casillero *> *> *> * getCasilleros();

	/*
	 * devuelve una lista con los casilleros vecinos
	 */
	Lista<Casillero*>* obtenerCasillerosVecinos(int x, int y, int z);

	int getXMaximo();

	/*
	 * devuelve el y maximo
	 */
	int getYMaximo();

	/*
	 * devuelv el z maximo
	 */
	int getZMaximo();

	/*
	 * muestra el tablero
	 */
	void mostrarTablero();

	/*
	 * destructor;
	 */
	virtual~ Tablero();
};




#endif /* TABLERO_H_ */
