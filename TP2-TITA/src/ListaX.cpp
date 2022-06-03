/*
 * ListaX.cpp
 *
 *  Created on: Jun 2, 2022
 *      Author: juli
 */
/*
#include"ListaX.h"

ListaX :: ListaX(){
	this->primero=NULL;
	this->longitud=0;
	this->cursor=NULL;
}

void ListaX :: agregar(Casillero* casillero){
	if (casillero == NULL){
		throw "El casillero ingresado no es valido";
	}

	if (this->longitud == 0){
		NodoX* nodo = new NodoX(casillero);
		this->primero=nodo;
	}
	else if(this->longitud == 1){
		NodoX* nodo = new NodoX(casillero);
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
		NodoX* nodo = new NodoX(casillero);
		nodo->setAnterior(this->cursor);
		this->cursor->setSiguiente(nodo);
		this->reiniciarCursor();
	}
	this->longitud++;
}

void ListaX :: reiniciarCursor() {
	this->cursor=NULL;
}

void ListaX :: avanzarCursor(){
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

void ListaX :: retrocederCursor(){
	//errores
	if(this->cursor!=NULL){
		if(cursor->getAnterior()==NULL){
			throw "El cursor ya esta al final de la lista";
		}
	}

	if(this->listaVacia()){
		throw "La lista esta vacia";
	}

	//codigo
	if(cursor == NULL){ //apunta al ultimo
		this->cursor = this->primero;
		for (int i = 1; i < this->longitud; i++){
			this->cursor =this->cursor->getSiguiente();
		}
	} else {
		this->cursor =this->cursor->getAnterior();
	}
}

void ListaX :: colocarCursor(int pos){
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

bool ListaX :: listaVacia(){
	return (this->longitud==0);
}

Casillero* ListaX :: getCasillero(){
	return this->cursor->getCasillero();
}

int ListaX :: getLongitud(){
	return this->longitud;
}

NodoX* ListaX :: getCursor(){
	return this->cursor;
}

ListaX :: ~ListaX() {
	this->reiniciarCursor();
	if(this->primero){
		NodoX* aux = this->primero;
		while(aux){
			this->primero=this->primero->getSiguiente();
			delete aux;
			aux = this->primero;
		}
	}
}
*/
