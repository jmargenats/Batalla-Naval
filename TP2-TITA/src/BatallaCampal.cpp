/*
 * BatallaCampal.cpp
 *
 *  Created on: Jun 1, 2022
 *      Author: juli
 */

#include<iostream>
#include <string>
#include <iostream>
#include "BatallaCampal.h"
#include "Enums.h"

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
	this->tablero = new Tablero(x , y, z);
	this->cartasDisponibles = new Lista<TipoDeCarta>;
	for(int i = 0; i < 6; i++){
		this->getCartasDisponibles()->agregar(this->ObtenerCarta(i));
	}
	this->setJugadores();
	this->iniciarSoldados();
	this->turno();
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
	case 0: return AtaqueBarco; break;
	case 1: return AtaquerAvion; break;
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

void BatallaCampal :: iniciarSoldados(){
	this->tablero->imprimirMapa();
	this->jugadores->iniciarCursor();
	unsigned int x, y, z;
	while(this->jugadores->avanzarCursor()){
		for(unsigned int i = 1; i<=this->cantidadDeSoldados; i++){
			std::cout << "el jugador numero " << this->jugadores->obtenerCursor()->getNumeroDeJugador() << " debe ingresar sus " << this->cantidadDeSoldados << " soldados." << std::endl;
			std::cout << "Ingrese la fila"<<std::endl;
			std::cin >> x;
			std::cout << "Ingrese la columna" << std::endl;
			std::cin >> y;
			this->tablero->colocarFicha(x, y, 1, Soldado, this->jugadores->obtenerCursor(), tablero, jugadores);
		}
		std::cout << "Ingrese sus 2 aviones" << this->cantidadDeSoldados << " soldados." << std::endl;
		for(unsigned int i = 1; i<=2; i++){
			std::cout << "Ingrese la fila"<<std::endl;
			std::cin >> x;
			std::cout << "Ingrese la columna" << std::endl;
			std::cin >> y;
			std::cout << "Ingrese la altura" << std::endl;
			std::cin >> z;
			this->tablero->colocarFicha(x, y, z, Avion, this->jugadores->obtenerCursor(), tablero, jugadores);
		}
		std::cout << "Ingrese sus 2 barcos" << this->cantidadDeSoldados << " soldados." << std::endl;
		for(unsigned int i = 1; i<=this->cantidadDeSoldados; i++){
			std::cout << "el jugador numero " << this->jugadores->obtenerCursor()->getNumeroDeJugador() << " debe ingresar sus " << this->cantidadDeSoldados << " soldados." << std::endl;
			std::cout << "Ingrese la fila"<<std::endl;
			std::cin >> x;
			std::cout << "Ingrese la columna" << std::endl;
			std::cin >> y;
			this->tablero->colocarFicha(x, y, 1, Barco, this->jugadores->obtenerCursor(), tablero, jugadores);
		}


	}
}

void BatallaCampal :: jugarCarta( Jugador* jugador){
	int carta;
//BatallaCampal* batallaCampal,Casillero* casillero
	cout << "ingrese el numero correspondiente a la opcion de la carta"<< endl;
	cin >> carta;
	TipoDeCarta tipo = jugador->getListaDeCartas()->obtener(carta);
	if(tipo ==AtaqueBarco && jugador->getCantidadDeBarcos() < 1){
		throw "No tiene barcos";
	}
	if(tipo ==AtaquerAvion && jugador->getCantidadDeAviones() < 1){
		throw "No tiene Aviones";
	}
	//TipoDeCarta tipo, Tablero* tablero, Lista<Jugador*>* jugadores, Jugador * jugadorActual
	Carta* cartaActual = new Carta(tipo, this->tablero, this->jugadores, jugador);
	delete cartaActual;
}

void BatallaCampal :: moverSoldadoOArmamento(Jugador* jugador){
	int x, y , z, xNuevo, yNuevo, zNuevo;

	cout << "Ingrese las coordenadas del soldado o armamento que desea mover" << endl;
	cout << "Ingrese la fila" << endl;
	cin >> x;
	cout << "Ingrese la columna" << endl;
	cin >> y;
	cout << "Ingrese la altura" << endl;
	cin >> z;

	cout << "Ingrese las corrdenadas a donde se quiere mover" << endl;
	cout << "Ingrese la fila" << endl;
	cin >> xNuevo;
	cout << "Ingrese la columna" << endl;
	cin >> yNuevo;
	cout << "Ingrese la altura" << endl;
	cin >> zNuevo;
	if(jugador->validarMovimiento(x, y, z, xNuevo, yNuevo, zNuevo)){
		this->tablero->colocarFicha(xNuevo, yNuevo, zNuevo, Soldado, jugador, this->tablero, this->jugadores);
	}

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
			cout << "Si desea recibir una carta, precione 1, de lo contrario, presione 2" << endl;
			cin >> decision;
			if(decision == 1){
				//se reparte la carta al jugador
				jugador->agregarCarta(this->ObtenerCarta(carta));
				carta++;
			}

			cout << "se le ha agregado una carta, sus cartas disponibles son:" << endl;
			jugador->imprimeListaDeCartas();
			cout << "Si desea usar una carta aprete '1', de lo contrario aprete '2'";
			cin >> decision;

			if(decision == 1){
				this->jugarCarta(jugador);
			}

			cout << "Si desea atacar, presione 1, de lo contrario, presione 2" << endl;
			cin >> decision;
			if (decision == 1){
				jugador->atacar(this->jugadores);
			}
			cout << "Si desea atacar, presione 1, de lo contrario, presione 2" << endl;
			cin >> decision;

			if(decision == 1){
				this->moverSoldadoOArmamento(jugador);
			}

		}
	}
}

BatallaCampal ::~ BatallaCampal(){

}




