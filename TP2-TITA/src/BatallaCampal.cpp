/*
 * BatallaCampal.cpp
 *
 *  Created on: Jun 1, 2022
 *      Author: juli
 */
#include "BatallaCampal.h"
#include<iostream>
#include <string>
#include <iostream>

using namespace std;

BatallaCampal :: BatallaCampal(unsigned int x, unsigned int y, unsigned int z, unsigned int numeroDeJugadores, unsigned int cantidadDeSoldados){
	if(x < 1 || y < 1 || z < 1 || numeroDeJugadores < 1){
		throw "Los valores ingresados no son validos";
	}
	this->xMaximo = x;
	this->yMaximo = y;
	this->zMaximo = z;
	this->cantidadDeSoldados= cantidadDeSoldados;
	this->numeroDeJugadores = numeroDeJugadores;
	this->jugadores = new Lista<Jugador*>;
	this->setJugadores();
	this->tablero = new Tablero(x , y, z);
	this->cartasDisponibles = new Lista<TipoDeCarta>;
	for(int i = 0; i < 6; i++){
		this->getCartasDisponibles()->agregar(this->ObtenerCarta(i));
	}
}


unsigned int BatallaCampal :: getXMaximo(){
	return this->xMaximo;
}


unsigned int BatallaCampal :: getYMaximo(){
	return this->yMaximo;
}


unsigned int BatallaCampal :: getZMaximo(){
	return this->zMaximo;
}


unsigned int BatallaCampal :: getNumeroDeJUgadores(){
	return this->numeroDeJugadores;
}

Lista<TipoDeCarta>* BatallaCampal :: getCartasDisponibles(){
	return this->cartasDisponibles;
}

void BatallaCampal :: setJugadores(){
	for(unsigned int i = 1; i <= this->getNumeroDeJUgadores(); i++){
		Jugador* jugadorNuevo = new Jugador(i, tablero);
		this->jugadores->agregar(jugadorNuevo);
	}
}

/*
 * pre: -
 * pos: devuelve true si la longitud de la lista de jugadores es mayor a 1
 */
bool BatallaCampal :: seguirJugando(){
	bool devolver = false;
	if(this->jugadores->contarElementos() > 1){
		devolver = true;
	}
	return devolver;
}

TipoDeCarta BatallaCampal :: ObtenerCarta(int numero){
	if(numero < 0 || numero > 5){
		throw "El numero ingresado no es valido";
	}

	//AgregarBarco, AgregarAvion, Misil, TeletransportarSoldado, SaltearElTurno, AgregarSoldado
	switch(numero){
	case 0: return AgregarBarco; break;
	case 1: return AgregarAvion; break;
	case 2: return Misil; break;
	case 3: return TeletransportarSoldado; break;
	case 4: return SaltearElTurno; break;
	default: return AgregarSoldado; break;
	}
}

bool BatallaCampal :: validarNumeroDeJugador(unsigned int numero){
	bool devolver  = false;
	for (unsigned int i = 1; i <= this->jugadores->contarElementos(); i++){
		if (this->jugadores->obtener(i)->getNumeroDeJugador() == numero){
			devolver = true;
		}
	}
	return devolver;
}

void  BatallaCampal :: atacar (unsigned int x, unsigned int  y, unsigned int z, TipoDeFicha tipo, unsigned int numeroDeJugador){
	if (this->validarNumeroDeJugador(numeroDeJugador) == false){
		throw "el numero del jugador ingresado no es valido";
	}
	if(x < 1 || y < 1 || z < 1){
		throw "Los valores de las posiciones son muy chicos";
	}
	if(x > this->getXMaximo() || y > this->getYMaximo() || z > this->getZMaximo()){
		throw "Los numeros ingresados son muy chicos"; //muy grandes no será?
	}

	//en caso de soldado
	if (tipo == Soldado){
		if (this->tablero->getCasillero(x, y, z)->getFicha() == NULL){
			this->tablero->getCasillero(x, y, z)->setEstado(Inactivo);
		} else {
			this->tablero->getCasillero(x, y, z)->getFicha()->getJugador()->restarSoldado();
			for(unsigned int i = 1; i <= this->jugadores->contarElementos(); i++){
				if(this->jugadores->obtener(i)->getNumeroDeSoldados() < 1){
					if(this->jugadores->obtener(i)->getNumeroDeJugador() == numeroDeJugador){
						this->jugadores->remover(i);
					}
				}
			}
		}
	}
}

void BatallaCampal :: iniciarSoldados(){
	this->jugadores->iniciarCursor();
	unsigned int x, y;
	while(this->jugadores->avanzarCursor()){
		for(unsigned int i = 1; i<=this->cantidadDeSoldados; i++){
			std::cout << "el jugador numero" << this->jugadores->obtenerCursor()->getNumeroDeJugador() << "debe ingresar sus" << this->cantidadDeSoldados << "soldados" << std::endl;
			std::cout << "Ingrese la fila"<<std::endl;
			std::cin >> x;
			std::cout << "Ingrese la columna" << std::endl;
			std::cin >> y;
			this->tablero->colocarFicha(x, y, 1, Soldado, this->jugadores->obtenerCursor(), tablero, jugadores);
		}
	}
}

void BatallaCampal :: jugarCarta( Jugador* jugador){
	int carta;
//BatallaCampal* batallaCampal,Casillero* casillero
	cout << "Ingrese cual carta quiere jugar (utilice numeros del 1 al " << jugador->getListaDeCartas()->contarElementos() <<")" <<endl;
	cin >> carta;
	Carta* jugarCarta = new Carta(this->ObtenerCarta(carta), this->tablero, this->jugadores, jugador);
	delete jugarCarta;
}

void BatallaCampal :: turno(){
	int carta = 0; // decide que carta se reparte
	int decision; //para las decisiones del usuario
	while(this->seguirJugando()){
		this->jugadores->iniciarCursor();
		while (this->jugadores->avanzarCursor()){
			Jugador* jugador = this->jugadores->obtenerCursor();
			//cuando llega al final de la lista de cartas vuelve al inicio
			if(carta > 5){
				carta = 0;
			}
			//se reparte la carta al jugador
			jugador->agregarCarta(this->ObtenerCarta(carta));
			cout << "se le ha agregado una carta, sus cartas disponibles son:" << endl;
			jugador->imprimeListaDeCartas();
			cout << "Si desea usar una carta aprete '1', de lo contrario aprete '2'";
			cin >> decision;
			if(decision == 1){
				this->jugarCarta(jugador);
			}
			cout << "sus fichas son: " << endl;
			jugador->imprimirTableroPersonal();
			cout << "Si desea mover alguna fiche, presione 1, de lo contrario, presione 2" << endl;
			cin >> decision;
			if (decision == 1){
				jugador->atacar(posicionEnX, posicionEnY, posicionEnZ, TipoDeFicha, numeroDEJugador)
			}

			//elegir con que ficha quiere atacar (avion, soldado, barco)
			//mover la ficha
		}
	}
}

BatallaCampal ::~ BatallaCampal(){

}




