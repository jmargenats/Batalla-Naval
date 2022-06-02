/*
 * ListaX.h
 *
 *  Created on: Jun 2, 2022
 *      Author: juli
 */

#ifndef LISTAX_H_
#define LISTAX_H_
#include "NodoX.h"

class ListaX{
private:
	NodoX* primero;
	int longitud;
	NodoX* cursor;
public:
	/*
	 * pre:
	 * pos: construye una lista con una longitud 0 (no apunta a ningun nodo) y los punteros apuntando a NULL
	 */
	ListaX();

	/*
	 * pre: el puntero dado no debe estar nulo
	 * pos: se agrega el casillero a la casilla de x, al final de la lista
	 * 		si el puntero al primero es NULL, ahora apunta al casillero ingresado
	 * 		le agrega uno a la longitud
	 *
	 */
	void agregar(Casillero* casillero);

	/*
	 * pre: -
	 * pos: reinicia el cursor en NULL
	 */
	void reiniciarCursor();

	/*
	 * pre: el cursor no puede estar apuntadno al final de la lista
	 * 		la lista no puede estar vacia
	 * pos: avanza el cursor un casillero
	 */
	void avanzarCursor();

	/*
	 * pre: el cursor no puede estar apuntando al principio de la lista
	 * 		la lsita debe tener un nodo
	 * pos: mueve el cursor hacia atras.
	 */
	void retrocederCursor();

	/*
	 * pre: el numero ingresadono debe ser mayor a la longitud de la lista, ni menor a 1s
	 * 		la lista tiene que tener una longitud mayor a 0
	 * pre: coloca el cursor en dicho lugar de la lista x
	 */
	void colocarCursor(int pos);

	/*
	 * pre: -
	 * pos: devuelve true si la lista esta vacia
	 */
	bool listaVacia();

	/*
	 * pre: -
	 * pos: devuelve la longitud de la lista
	 */
	int getLongitud();

	/*
	 * pre: la lista no debe estar vacia
	 * 		el cursor no debe ser nulo
	 * pos: devuevle el casillero hacia el cual apunta el nodo
	 */
	Casillero* getCasillero();

	/*
	 * pre: -
	 * pos: devuelve el cursor
	 */
	NodoX* getCursor();

	/*
	 * destructor ?
	 */
	virtual ~ListaX();

};




#endif /* LISTAX_H_ */
