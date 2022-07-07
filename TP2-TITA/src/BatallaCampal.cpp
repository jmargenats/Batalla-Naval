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
		std::cout << "el jugador numero " << this->jugadores->obtenerCursor()->getNumeroDeJugador() << " debe ingresar sus " << this->cantidadDeSoldados << " soldados." << std::endl;
		for(unsigned int i = 1; i<=this->cantidadDeSoldados; i++){
			std::cout << "soldado " << i << endl;
			std::cout << "Ingrese la columna"<<std::endl;
			std::cin >> x;
			std::cout << "Ingrese la fila" << std::endl;
			std::cin >> y;
			this->tablero->colocarFicha(x, y, 1, Soldado, this->jugadores->obtenerCursor(), tablero, jugadores);
		}
		std::cout << "Ingrese sus 2 aviones" << std::endl;
		for(unsigned int i = 1; i<=2; i++){
			std::cout << "Avion " << i << endl;
			std::cout << "Ingrese la columna"<<std::endl;
			std::cin >> x;
			std::cout << "Ingrese la fila" << std::endl;
			std::cin >> y;
			std::cout << "Ingrese la altura" << std::endl;
			std::cin >> z;
			this->tablero->colocarFicha(x, y, z, Avion, this->jugadores->obtenerCursor(), tablero, jugadores);
		}
		std::cout << "Ingrese sus 2 barcos" << std::endl;
		for(unsigned int i = 1; i<=2; i++){
			std::cout << "Barco " << i << endl;
			std::cout << "Ingrese la columna"<<std::endl;
			std::cin >> x;
			std::cout << "Ingrese la fila" << std::endl;
			std::cin >> y;
			this->tablero->colocarFicha(x, y, 1, Barco, this->jugadores->obtenerCursor(), tablero, jugadores);
		}


	}
}

void BatallaCampal :: jugarCarta( Jugador* jugador){
	int carta;
	cout << "ingrese el numero correspondiente a la opcion de la carta"<< endl;
	cin >> carta;
	TipoDeCarta tipo = jugador->getListaDeCartas()->obtener(carta);
	if(tipo ==AtaqueBarco && jugador->getCantidadDeBarcos() < 1){
		throw "No tiene barcos";
	}
	if(tipo ==AtaquerAvion && jugador->getCantidadDeAviones() < 1){
		throw "No tiene Aviones";
	}
	Carta* cartaActual = new Carta(tipo, this->tablero, this->jugadores, jugador);
	delete cartaActual;
	jugador->eliminarCarta(carta);
}

void BatallaCampal :: arreglarCursor(Jugador* jugador, Lista<Jugador*>* jugadores){
	jugadores->iniciarCursor();
	while(jugadores->avanzarCursor() && jugadores->obtenerCursor() !=jugador){

	}
}

void BatallaCampal :: moverSoldadoOArmamento(Jugador* jugador){

	int x, y , z, xNuevo, yNuevo, zNuevo;

	cout << "Ingrese las coordenadas del soldado o armamento que desea mover" << endl;
	cout << "Ingrese la columna" << endl;
	cin >> x;
	cout << "Ingrese la fila" << endl;
	cin >> y;
	cout << "Ingrese la altura" << endl;
	cin >> z;

	Casillero* casillero = this->tablero->getCasillero(x, y, z);
	if(casillero->getFicha() == NULL){
		throw "Ese casillero esta vacio";
	}
	if(casillero->getFicha()->getJugador()->getNumeroDeJugador() != jugador->getNumeroDeJugador()){
		throw "Ese soldado o armamento no le pertenece";
	}

	cout << "Ingrese las corrdenadas a donde se quiere mover" << endl;
	cout << "Ingrese la columna" << endl;
	cin >> xNuevo;
	cout << "Ingrese la fila" << endl;
	cin >> yNuevo;
	cout << "Ingrese la altura" << endl;
	cin >> zNuevo;
	if(jugador->validarMovimiento(x, y, z, xNuevo, yNuevo, zNuevo)){
		this->tablero->colocarFicha(xNuevo, yNuevo, zNuevo, casillero->getFicha()->getTipo(), jugador, tablero, jugadores);
		Ficha* ficha = NULL;
		this->tablero->getCasillero(x, y, z)->setFicha(ficha);
	}

}

void BatallaCampal :: turno(){
	int carta = 0; // decide que carta se reparte
	unsigned int decision, numeroGanador; //para las decisiones del usuario
	while(this->seguirJugando()){
		this->jugadores->iniciarCursor();
		while (this->jugadores->avanzarCursor() && this->jugadores->contarElementos() > 1){
			Jugador* jugador = this->jugadores->obtenerCursor();
			numeroGanador = jugador->getNumeroDeJugador();
			jugador->imprimirTableroPersonal();
			//cuando llega al final de la lista de cartas vuelve al inicio
			if(carta > 5){
				carta = 0;
			}
			int numero = jugador->getNumeroDeJugador();
			cout << numero << endl;
			cout << "Es el turno del jugador " << jugador->getNumeroDeJugador() << endl << endl;
			cout << "Si desea recibir una carta, presione 1, de lo contrario, presione 2" << endl;
			cin >> decision;
			if(decision == 1){
				//se reparte la carta al jugador
				jugador->agregarCarta(this->ObtenerCarta(carta));
				carta++;
			}

			cout << "se le ha agregado una carta, sus cartas disponibles son:" << endl;
			jugador->imprimeListaDeCartas();
			cout << "Si desea usar una carta presione '1', de lo contrario presione '2'";
			cin >> decision;

			if(decision == 1){
				this->jugarCarta(jugador);
			}

			cout << "Si desea atacar, presione 1, de lo contrario, presione 2" << endl;
			cin >> decision;
			if (decision == 1){
				jugador->atacar(this->jugadores);
			}
			cout << "Si desea moverse, presione 1, de lo contrario, presione 2" << endl;
			cin >> decision;

			if(decision == 1){
				this->moverSoldadoOArmamento(jugador);
			}

			this->arreglarCursor(jugador, jugadores);

		}

	}
	cout << "El ganador es el jugador " << numeroGanador << endl;
}

BatallaCampal ::~ BatallaCampal(){
	delete this->tablero;
	this->jugadores->iniciarCursor();
	Jugador* jugador = jugadores->obtenerCursor();
	for(unsigned int i = 1; i<= jugadores->contarElementos(); i++){
		delete jugador;
	}
	delete this->jugadores;
	delete this->cartasDisponibles;
}




