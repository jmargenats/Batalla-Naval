/*
 * ListaX.h
 *
 *  Created on: Jun 2, 2022
 *      Author: juli
 */

#ifndef LISTAX_H_
#define LISTAX_H_
#include "Nodo.h"

template <class T>

class Lista{
private:
	Nodo<T>* primero;
	int longitud;
	Nodo<T>* cursor;
public:
	/*
	 * pre:la longitud final no puede ser menor a 1
	 * pos: construye una lista con una longitud 0 (no apunta a ningun nodo) y los punteros apuntando a NULL
	 */
	Lista(int longitudFinal, T puntero){
		if(longitud <1){
			throw "La longitud ingresada no es valida";
		}
		this->primero=NULL;
		this->longitud=0;
		this->cursor=NULL;
		for(int i = 1; i<=longitudFinal;i++){
			this->agregarFinal(puntero);
		}
	}

	/*
	 * pre: la longitud no debe ser menor a 1
	 * pos: se agrega el puntero al final de la lista
	 * 		si el puntero al primero es NULL, ahora apunta al casillero ingresado
	 * 		le agrega uno a la longitud
	 *
	 */
	void agregarFinal(T puntero){
		if(this->longitud < 0){
			throw "La longitud ingresada no es valida";
		}
		if (this->longitud == 0){
			Nodo<T>* nodo = new Nodo<T>(puntero);
			this->primero=nodo;
		}
		else if(this->longitud == 1){
			Nodo<T>* nodo = new Nodo<T>(puntero);
			nodo->setAnterior(this->primero);
			this->primero->setSiguiente(nodo);
		}
		else{
			if(cursor!=NULL){
				this->reiniciarCursor();
			}
			for(int i = 0; i < this->longitud; i++){
				this->avanzarCursor();
			}
			Nodo<T>* nodo = new Nodo<T>(puntero);
			nodo->setAnterior(this->cursor);
			this->cursor->setSiguiente(nodo);
			this->reiniciarCursor();
		}
		this->longitud++;
	}

	/*
	 * pre: -
	 * pos: reinicia el cursor en NULL
	 */
	void reiniciarCursor(){
		this->cursor=NULL;
	}

	/*
	 * pre: el cursor no puede estar apuntadno al final de la lista
	 * 		la lista no puede estar vacia
	 * pos: avanza el cursor un casillero
	 */
	void avanzarCursor(){
		//errores
		if(this->cursor!=NULL){
			if(cursor->getSiguiente()==NULL){
				throw "El cursor ya esta al final de la lista";
			}
		}

		if(this->listaVacia()){
			throw "La lista esta vacia";
		}

		//codigo
		if(cursor == NULL){
			this->cursor = this->primero;
		} else {
			this->cursor =this->cursor->getSiguiente();
		}
	}

	/*
	 * pre: el cursor no puede estar apuntando al principio de la lista
	 * 		la lsita debe tener un nodo
	 * pos: mueve el cursor hacia atras.
	 */
	void retrocederCursor(){
		//errores
		if(this->cursor!=NULL){
			if(cursor->getAnterior()==NULL){
				throw "El cursor ya esta al final de la lista";
			}
		}

		if(this->listaVacia()){
			throw "La lista esta vacia";
		}

		if(cursor == NULL){ //apunta al ultimo
			this->cursor = this->primero;
			for (int i = 1; i < this->longitud; i++){
				this->cursor =this->cursor->getSiguiente();
			}
		} else {
			this->cursor =this->cursor->getAnterior();
		}
	}

	/*
	 * pre: el numero ingresadono debe ser mayor a la longitud de la lista, ni menor a 1s
	 * 		la lista tiene que tener una longitud mayor a 0
	 * pre: coloca el cursor en dicho lugar de la lista x
	 */
	void colocarCursor(int pos){
		if(pos > this->longitud || pos < 1){
			throw "La posicion ingresada no es valida";
		}
		if(this->longitud==0){
			throw "La lista no esta iniciada";
		}
		if(cursor!=NULL){
			this->reiniciarCursor();
		}
		for(int i = 0; i < pos; i++){
			this->avanzarCursor();
		}
	}

	/*
	 * pre: -
	 * pos: devuelve true si la lista esta vacia
	 */
	bool listaVacia(){
		return (this->longitud==0);
	}

	/*
	 * pre: -
	 * pos: devuelve la longitud de la lista
	 */
	int getLongitud(){
		return this->longitud;
	}

	/*
	 * pre: la lista no debe estar vacia
	 * 		el cursor no debe ser nulo
	 * pos: devuevle el casillero hacia el cual apunta el nodo
	 */
	T* getPuntero(){
		return this->cursor->getPuntero();
	}

	/*
	 * pre: -
	 * pos: devuelve el cursor
	 */
	Nodo<T>* getCursor(){
		return this->cursor;
	}

	/*
	 * destructor ?
	 */
	virtual ~Lista(){
		this->reiniciarCursor();
		if(this->primero){
			Nodo<T>* aux = this->primero;
			while(aux){
				this->primero=this->primero->getSiguiente();
				delete aux;
				aux = this->primero;
			}
		}
	}

};




#endif /* LISTAX_H_ */
