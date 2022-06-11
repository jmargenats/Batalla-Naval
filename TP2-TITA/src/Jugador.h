/*
 * Jugador.h
 *
 *  Created on: Jun 1, 2022
 *      Author: juli
 */

#ifndef JUGADOR_H_
#define JUGADOR_H_

#include <string>
#include "Ficha.h"
#include "Lista.h"
#include "Casillero.h"
#include"carta.h"
#include <iostream>



class Jugador {
private:
	Lista<TipoDeFicha>* listaDeFichas;
	unsigned int numeroDeJugador;
	//std::string nombreDeJugador;
	unsigned int numeroDeSoldados;
	Lista<Carta*>* listaDeCartas;
	Tablero* tablero;

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
	void agregarCarta(Carta* tipo);

	/*
	 * post: imprime el tablero del jugador
	 */
	void imprimirTableroPersonal();

	/*
	 * post: devuelve la lsita de cartas
	 */
	Lista<Carta*> * getListaDeCartas();

	/*
	 * pre: la carta debe estar en la lsita
	 * post: elimina la carta de la lista de cartas
	 */
	void eliminarCarta(TipoDeCarta tipo);

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

	void atacarNormal(Lista<Jugador*>* jugadores);

	/*
	 * post: devuelve la lista de fichas
	 */

	Lista<TipoDeFicha>* getListaDeFichas();

	void imprimirListaDeFichas();

	void agregarFicha(TipoDeFicha tipo);

	void eliminarFicha(TipoDeFicha tipo);

	bool fichaDentroDeLista(TipoDeFicha tipo);
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
//	void atacar(Casillero* posicionEnX, Casillero* posicionEnY, Casillero* posicionEnZ, Ficha* TipoDeFicha, unsigned int numeroDEJugador);


	/*
	 * pre: el numero de soldados debe ser mayor a 0
	 * pos: resta un soldado al contador de soldados
	 */
	void restarSoldado();

	void sumarSoldado();

//	void moverSoldadoOArmamento(Casillero* posicionEnX, Casillero* posicionEnY, Casillero* posicionEnZ, Casillero* nuevaPosicionEnX, Casillero* nuevaPosicionEnY, Casillero* nuevaPosicionEnZ);

	/*
	 * pre: Recibe posiciones validas
	   post: Valida que el movimiento a realizar sea horizontal, vertical o diagonal
	*/
//	bool validarMovimiento(Casillero* x, Casillero* y, Casillero* z, Casillero* xNueva, Casillero* yNueva, Casillero* zNueva);
};



#endif /* JUGADOR_H_ */
