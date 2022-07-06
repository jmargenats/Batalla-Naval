
#include <iostream>
#include<string>
#include"Tablero.h"
#include "carta.h"


 Carta::Carta(TipoDeCarta tipo, Tablero* tablero, Lista<Jugador*>* jugadores, Jugador * jugadorActual){
	 this->tablero = tablero;
	 this->jugadores = jugadores;
	 this->jugadorActual = jugadorActual;

	 int x, y, z = 0;
	switch (tipo)
	{
	case AtaquerAvion:
		//Condición de que avión esté en el aire
            this->ataqueAvion();
		break;
	case AtaqueBarco:
		std::cout <<  "Ingrese la fila a atacar" << std::endl;
		std:: cin >> x;
		std::cout <<  "Ingrese la columna a atacar" << std::endl;
		std:: cin >> y;
		std::cout <<  "Ingrese la altura" << std::endl;
		std:: cin >> z;
		this->ataqueMisil(x, y, z);
		break;
	case Misil:
		std::cout <<  "Ingrese la fila a atacar" << std::endl;
		std:: cin >> x;
		std::cout <<  "Ingrese la columna a atacar" << std::endl;
		std:: cin >> y;
		std::cout <<  "Ingrese la altura" << std::endl;
		std:: cin >> z;
        this->ataqueMisil(x, y, z);
		break;
	case TeletransportarSoldado:
		this->teletransportarse();
		break;
	case SaltearElTurno:
		this->saltearTurno();
		break;

	default:
		break;
	}
};
// obtener(i)->getNumeroDeSoldados() < 1
void Carta::ataqueAvion(){
	this->jugadorActual->atacar(jugadores);
	this->jugadorActual->atacar(jugadores);
};

void Carta::ataqueMisil(unsigned int x, unsigned int y, unsigned int z){
	if(!(tablero->verificarValoresIngresados(x, y, z))){
		throw "posicion no valida";
	}
	if (this->tablero->getCasillero(x, y, z)->getFicha() != NULL) { // Debería ser una función porque se repite varias veces, también hay que tener en cuenta que podría haber armamento (que se eliminaría)
		Ficha* ficha = this->tablero->getCasillero(x, y, z)->getFicha();
		if(ficha->getTipo() == Soldado){
			this->jugadorActual->restarSoldado();
			if(this->jugadorActual->getNumeroDeSoldados() < 1){
				this->tablero->eliminarJugador(this->jugadorActual, jugadores);
			}
		} else if (ficha->getTipo()==Avion){
			this->jugadorActual->restarAvion();
		} else {
			this->jugadorActual->restarBarco();
		}
		delete ficha;
	}
	this->tablero->getCasillero(x, y, z)->setEstado(Inactivo);

	this->tablero->obtenerCasillerosVecinos(x, y, z)->iniciarCursor(); // ataca a los casilleros alrededor
		while(this->tablero->obtenerCasillerosVecinos(x, y, z)->avanzarCursor()){
			Casillero* casilleroVecino = this->tablero->obtenerCasillerosVecinos(x, y, z)->obtenerCursor();
			if(casilleroVecino->getFicha()==NULL){
			casilleroVecino->setEstado(Inactivo);
			} else {
				Ficha* ficha = this->tablero->getCasillero(x, y, z)->getFicha();
				if(ficha->getTipo() == Soldado){
					this->jugadorActual->restarSoldado();
					if(this->jugadorActual->getNumeroDeSoldados() < 1){
						this->tablero->eliminarJugador(this->jugadorActual, jugadores);
					}
				} else if (ficha->getTipo()==Avion){
					this->jugadorActual->restarAvion();
				} else {
					this->jugadorActual->restarBarco();
				}
				casilleroVecino->setEstado(Inactivo);
				delete ficha;
			}
	}
};

void Carta::teletransportarse(){
	int xAntiguo, yAntiguo, xNuevo, yNuevo;
	std::cout <<  "Elija un soldado para transportar, e ingrese sus coordenadas" << std::endl;
	this->jugadorActual->imprimirTableroPersonal();
	std::cout <<  "Ingrese la fila" << std::endl;
	std:: cin >> xAntiguo;
	std::cout <<  "Ingrese la columna" << std::endl;
	std::cin >> yAntiguo;
	std::cout <<  "Ingrese la fila nueva" << std::endl;
	std:: cin >> xNuevo;
	std::cout <<  "Ingrese la columna nueva" << std::endl;
	std::cin >> yNuevo;
	if(this->tablero->getCasillero(xAntiguo, yAntiguo, 1)->getFicha()==NULL){
		throw "El casillero ingresado esta vacio";
	}
	if(this->tablero->getCasillero(xAntiguo, yAntiguo, 1)->getFicha()->getTipo()!=Soldado){
		throw "El casillero no tiene un soldado";
	}
	if(!(tablero->verificarValoresIngresados(xNuevo, yNuevo, 1))){
			throw "posicion no valida";
	}
	Ficha* ficha = NULL;
	this->tablero->getCasillero(xAntiguo, yAntiguo, 1)->setFicha(ficha);
	this->tablero->colocarFicha(xNuevo, yNuevo, 1, Soldado, this->jugadorActual, tablero, jugadores);
};

void Carta::saltearTurno(){
	this->jugadores->avanzarCursor();
};

void Carta::agregarSoldado(){
	unsigned int x, y;
	std::cout << "Inrese la fila" << std::endl;
	std::cin >> x;
	std::cout << "Inrese la columna" << std::endl;
	std::cin >> y;
	if(!(tablero->verificarValoresIngresados(x, y, 1))){
			throw "posicion no valida";
	}
	this->tablero->colocarFicha(x, y, 1, Soldado, this->jugadorActual, tablero, jugadores);
};
