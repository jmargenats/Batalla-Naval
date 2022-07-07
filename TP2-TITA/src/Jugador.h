/*
 * Jugador.h
 *
 *  Created on: Jun 1, 2022
 *      Author: juli
 */

#ifndef JUGADOR_H_
#define JUGADOR_H_

#include <string>
#include <iostream>
#include "carta.h"
#include"Tablero.h"

class Ficha;
class Tablero;
class Jugador {
private:
	unsigned int numeroDeJugador;
	//std::string nombreDeJugador;
	unsigned int numeroDeSoldados;
	Lista<TipoDeCarta>* listaDeCartas;
	Tablero* tablero;
	int cantidadDeBarcos;
	int cantidadDeAviones;

public:
	/*
	 * pre: el unmero debe ser mayor o giual a 1
	 * 		el nombre debe ser diferente a vacio
	 * pos: se crea el jugador
	 */
	Jugador(unsigned int numero, Tablero* tablero); //std::string nombre);

	/*
	 * pos: destruye el jugador
	 */
	virtual ~Jugador();

	/*
	 * pos: devuelve el numero del jugador
	 */
	unsigned int getNumeroDeJugador();

	/*
	 * post: devuelve el numero de soldados
	 */
	unsigned int getNumeroDeSoldados();

	/*
	 * post: imprime las cartas del jugador
	 */
	void imprimeListaDeCartas ();

	/*
	 *
	 * post: agrega la carta a la lista de carta
	 */
	void agregarCarta(TipoDeCarta tipo);

	/*
	 * post: imprime el tablero del jugador
	 */
	void imprimirTableroPersonal();

	/*
	 * post: devuelve la lsita de cartas
	 */
	Lista<TipoDeCarta> * getListaDeCartas();

	/*
	 * pre: la posicion debe ser mayor a 0 y menor al tamanio de la lista
	 * post: elimina la carta de la lista de cartas
	 */
	void eliminarCarta(unsigned int posicion);

	/*
	 * devuelve el tablero
	 */
	Tablero* getTablero();

	/*
	 * post: devuelve true si la carta se encuentra en la lista de cartas
	 */
	bool cartaEnLista(TipoDeCarta tipo);

	/*
	 * post: ataca
	 */
	void atacar(Lista<Jugador*>* jugadores);

	/*
	 * pre: el numero de soldados debe ser mayor a 0
	 * pos: resta un soldado al contador de soldados
	 */
	void restarSoldado();

	/*
	 * post: suma un soldado
	 */
	void sumarSoldado();

	/*
	 * post: obtiene la cantidad de aviones
	 */
	int getCantidadDeAviones();

	/*
	 * post: obtiene la cantidad de barcos
	 */
	int getCantidadDeBarcos();

	/*
	 * post: suma un barco
	 */
	void sumarBarco();

	/*
	 * post: resta un barco
	 */
	void restarBarco();

	/*
	 * post: suma un avion
	 */
	void sumarAvion();

	/*
	 * post: resta un avion
	 */
	void restarAvion();

	/*
	 * post: devuelve true si el movimiento es valido
	 */
	bool validarMovimiento(int x, int y, int z, int xNueva, int yNueva, int zNueva);

};



#endif /* JUGADOR_H_ */
