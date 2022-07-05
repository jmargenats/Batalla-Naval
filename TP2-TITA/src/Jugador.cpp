/*
 * Jugador.cpp
 *
 *  Created on: Jun 1, 2022
 *      Author: juli
 */


#include <iostream>
using namespace std;
#include "Jugador.h"


Jugador :: Jugador(unsigned int numero, Tablero* tablero){//, std::string nombre){
	if (numero < 1){
		throw "El numero de jugador no es valido";
	}
	//if(nombre == ""){
	//	throw "El nombre ingreasdo no es valido";
	//}
	this->numeroDeJugador = numero;
	//this->nombreDeJugador = nombre;

	this->listaDeCartas = new Lista<TipoDeCarta>;

	this->numeroDeSoldados = 0;

	this->tablero = tablero;

	this->cantidadDeAviones = 0;

	this->cantidadDeBarcos = 0;

}
Jugador ::  ~Jugador(){

}

unsigned int Jugador :: getNumeroDeJugador(){
	return this->numeroDeJugador;
}

unsigned int Jugador :: getNumeroDeSoldados(){
	return this->numeroDeSoldados;
}

//std::string Jugador :: getNombreDeJugador(){
//	return this->nombreDeJugador;
//}

void Jugador :: imprimeListaDeCartas (){
	this->listaDeCartas->iniciarCursor();
	std:: cout << "Tus cartas son:"<< endl;
	int contador = 1;
	while(this->listaDeCartas->avanzarCursor()){
		cout << contador<< " :";
		TipoDeCarta carta = this->listaDeCartas->obtenerCursor();
		if(carta == AtaquerAvion){
			std::cout << " |Ataque de Avion| " << std::endl;
		}
		else if(carta == AtaqueBarco){
			std::cout << " |Ataque de Barco| " << std::endl;
		}
		else if(carta == Misil){
			std::cout << " |Misil| " << std::endl;
		}
		else if(carta == TeletransportarSoldado){
			std::cout << " |Teletransportar Soldado| " << std::endl;
		}
		else if(carta == SaltearElTurno){
			std::cout << " |Saltear El Turno| " << std::endl;
		}
		else if(carta == AgregarSoldado){
			std::cout << " |Agregar Soldado| " << std::endl;
		}
		cout<<endl;
	}
}

Lista<TipoDeCarta> * Jugador :: getListaDeCartas(){
	return this->listaDeCartas;
}

void Jugador :: agregarCarta(TipoDeCarta tipo){
	this->getListaDeCartas()->agregar(tipo);
}

void Jugador :: eliminarCarta(TipoDeCarta tipo){
	if(!cartaEnLista(tipo)){
		throw "La carta no se encuentra en su posecion";
	}
	this->listaDeCartas->iniciarCursor();
	unsigned int posicion = 0; //revisa la posicion para eliminar la carta
	unsigned int cantidad = 0;
	while(this->listaDeCartas->avanzarCursor()){
		if (this->listaDeCartas->obtenerCursor() == tipo && cantidad < 1){ //solo elimina la primer paracicion de la carta
			this->listaDeCartas->remover(posicion);
			cantidad++;
		}
		posicion++;
	}
}

bool Jugador :: cartaEnLista(TipoDeCarta tipo){
	this->listaDeCartas->iniciarCursor();
	while(this->listaDeCartas->avanzarCursor()){
		if (this->listaDeCartas->obtenerCursor() == tipo){
			return true;
		}
	}
	return false;
}



void Jugador :: atacar(Lista<Jugador*>* jugadores){
	int x, y, z;
	cout << "Elija la posicion a la que quiere atacar" << endl;
	std::cout << "Inrese la fila" << std::endl;
	std::cin >> x;
	std::cout << "Inrese la columna" << std::endl;
	std::cin >> y;
	std::cout << "Inrese la altura" << std::endl;
	std::cin >> z;
	Casillero* casillero = this->tablero->getCasillero(x, y, z);
	if (casillero->getFicha() == NULL){
			this->tablero->getCasillero(x, y, z)->setEstado(Inactivo);
	} else{
		 Ficha* ficha = casillero->getFicha();
		 if(casillero->getFicha()->getTipo()==Soldado){
			ficha->getJugador()->restarSoldado();
			if (ficha->getJugador()->getNumeroDeSoldados() < 1){
				this->tablero->eliminarJugador(ficha->getJugador(), jugadores);
			}

		 	 } else  if (ficha->getTipo() == Avion){ // tipo de ficha no es soldado
		 		ficha->getJugador()->restarAvion();

		 	 } else { // si es barco
		 		ficha->getJugador()->restarBarco();

		 	 }

			Ficha* fichaAux = NULL;
			casillero->setFicha(fichaAux);
			casillero->setEstado(Inactivo);
			delete ficha;
	}

}

void Jugador :: imprimirTableroPersonal(){
	Lista<Lista<Lista<Casillero *> *> *> * casilleros = this->tablero->getCasilleros();
	casilleros->iniciarCursor();
	unsigned int nivel = 1;
	while(casilleros->avanzarCursor()){
		std::cout << "nivel:" << nivel <<std::endl;
		Lista<Lista<Casillero*>*>* profundidad = casilleros->obtenerCursor();
		profundidad->iniciarCursor();
		while(profundidad->avanzarCursor()){
			Lista<Casillero*>* largo = profundidad->obtenerCursor();
			largo->iniciarCursor();
			while(largo->avanzarCursor()){
				Casillero* casillero = largo->obtenerCursor();
				if(casillero->getFicha() != NULL){
					if (casillero->getFicha()->getTipo() == Soldado &&
						casillero->getFicha()->getJugador()->getNumeroDeJugador() == this->getNumeroDeJugador()){
						std:: cout << "|" << " Soldado"<<"|";
					} else if (casillero->getFicha()->getTipo() == Avion &&
							   casillero->getFicha()->getJugador()->getNumeroDeJugador() == this->getNumeroDeJugador()) {
						std:: cout << "|" << "  Barco "<<"|";
					}else if (casillero->getFicha()->getTipo() == Barco &&
							  casillero->getFicha()->getJugador()->getNumeroDeJugador() == this->getNumeroDeJugador()){
						std:: cout << "|" << "  Avion "<<"|";
					} else {
						std:: cout << "|" << "  Vacio "<<"|";
					}
					} else{
						if(casillero->getEstado() == Inactivo){
							std:: cout << "|" << "Inactivo"<<"|";
						} else if (casillero->getEstado() == Vacio){
							std:: cout << "|" << "  Vacio "<<"|";
						}
				}
			}
			std::cout<<std::endl;
		}
		nivel++;
		std::cout<<std::endl;
	}

}

void Jugador :: restarSoldado(){
	if(this->numeroDeSoldados < 1){
		throw "El numero de soldados ya es menor a 1";
	}
	this->numeroDeSoldados--;
}

void Jugador :: sumarSoldado(){
	this->numeroDeSoldados++;
}

Tablero* Jugador :: getTablero(){
	return this->tablero;
}

int Jugador :: getCantidadDeAviones(){
	return this->cantidadDeAviones;
}

int Jugador :: getCantidadDeBarcos(){
	return this->cantidadDeBarcos;
}

void Jugador :: sumarBarco(){
	this->cantidadDeBarcos++;
}

void Jugador :: restarBarco(){
	this->cantidadDeBarcos--;
}

void Jugador :: sumarAvion(){
	this->cantidadDeAviones++;
}

void Jugador :: restarAvion(){
	this->cantidadDeAviones--;
}



//verificar el tema de casillero

bool Jugador::validarMovimiento(int x, int y, int z, int xNueva, int yNueva, int zNueva){
	if((xNueva == x || xNueva == x - 1|| xNueva == x + 1) &&
	   (yNueva == y || yNueva == y - 1|| yNueva == y + 1) &&
	   (zNueva == z || zNueva == z - 1|| zNueva == z + 1)){
		return true;
	}
	return false ;


};



