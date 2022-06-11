/*
 * Jugador.cpp
 *
 *  Created on: Jun 1, 2022
 *      Author: juli
 */

#include "Jugador.h"
#include "Tablero.h"
#include "Ficha.h"
#include <iostream>
using namespace std;

Jugador :: Jugador(unsigned int numero, Tablero* tablero){//, std::string nombre){
	if (numero < 1){
		throw "El numero de jugador no es valido";
	}
	//if(nombre == ""){
	//	throw "El nombre ingreasdo no es valido";
	//}
	this->numeroDeJugador = numero;
	//this->nombreDeJugador = nombre;

	this->listaDeCartas = new Lista<Carta*>;

	this->numeroDeSoldados = 0;

	this->tablero = tablero;

	this->listaDeFichas = new Lista<TipoDeFicha>;


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

//ver con nuevos cambios de AtacarAvion, AtacarBarco
void Jugador :: imprimeListaDeCartas (){
	this->listaDeCartas->iniciarCursor();
	std:: cout << "Tus cartas son:";
	while(this->listaDeCartas->avanzarCursor()){
		TipoDeCarta carta = this->listaDeCartas->obtenerCursor()->obtenerCarta();
		if(carta == AtaquerAvion){
			std::cout << " |Agregar Avion| " << std::endl;
		}
		else if(carta == AtaqueBarco){
			std::cout << " |Agregar Barco| " << std::endl;
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
	}
}

Lista<Carta*> * Jugador :: getListaDeCartas(){
	return this->listaDeCartas;
}

void Jugador :: agregarCarta(Carta* tipo){
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
		if (this->listaDeCartas->obtenerCursor()->obtenerCarta() == tipo && cantidad < 1){ //solo elimina la primer paracicion de la carta
			this->listaDeCartas->remover(posicion);
			cantidad++;
		}
		posicion++;
	}
}

bool Jugador :: cartaEnLista(TipoDeCarta tipo){
	this->listaDeCartas->iniciarCursor();
	while(this->listaDeCartas->avanzarCursor()){
		if (this->listaDeCartas->obtenerCursor()->obtenerCarta() == tipo){
			return true;
		}
	}
	return false;
}

void Jugador :: atacar(Lista<Jugador*>* jugadores){
	int x, y, z;
	cout << "Elija la posicion de la ficha con la que quiere atacar" << endl;
	std::cout << "Inrese la fila" << std::endl;
	std::cin >> x;
	std::cout << "Inrese la columna" << std::endl;
	std::cin >> y;
	std::cout << "Inrese la altura" << std::endl;
	std::cin >> z;
	//verifica que el numero este dentro del tablero
	if(x < 1 || y < 1 || z < 1){
		throw "los valores ingresados son muy vajos";
	}
	if(x > this->tablero->getXMaximo() || z > this->tablero->getYMaximo() || z > this->tablero->getZMaximo()){
		throw "Los numeros ingresados son muy altos";
	}
	if(this->tablero->getCasillero(x, y, z)->getFicha() == NULL){
		throw "No hay ninguna ficha en ese casilelro";
	}
	if(this->tablero->getCasillero(x, y, z)->getFicha()->getJugador()->getNumeroDeJugador() != this->getNumeroDeJugador()){
		throw "La ficha no le pertenece";
	}
	// fin verificaciones
	int decision;
	cout << "Elija si quiere atacar con un soldado (1) un Avion(2) o un Barco (3)" << endl;
	cin >> decision;
	if(decision == 1 && this->fichaDentroDeLista(Soldado)){
		cout << "Ingrese su ataque" << endl;
		this->atacarNormal(jugadores);
	}
	if(decision == 2 && this->fichaDentroDeLista(Avion)){
		cout << "Ingrese su primer ataque" << endl;
		this->atacarNormal(jugadores);
		cout << "Ingrese su segundo ataque" << endl;
		this->atacarNormal(jugadores);
	}
	if(decision == 3 && this->fichaDentroDeLista(Barco)){
		cout << "Ingrese su primer ataque" << endl;
		this->atacarNormal(jugadores);
		cout << "Ingrese su segundo ataque" << endl;
		this->atacarNormal(jugadores);
	}



}


void Jugador :: atacarNormal(Lista<Jugador*>* jugadores){
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
		 if( casillero->getFicha()->getTipo()==Soldado){ // Debería ser una función porque se repite varias veces, también hay que tener en cuenta que podría haber armamento (que se eliminaría)
			ficha->getJugador()->restarSoldado();
			if (ficha->getJugador()->getNumeroDeSoldados() < 1){
				jugadores->iniciarCursor();
				unsigned int posicion = 1;
				while(jugadores->avanzarCursor()){
					if (jugadores->obtenerCursor()->getNumeroDeJugador() == ficha->getJugador()->getNumeroDeJugador()){
						jugadores->remover(posicion);
						jugadores->iniciarCursor(); // para que no hayan errores en caso de ser le ultimo jugador
					}
					posicion++;
				}
			}
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
				if (casillero->getFicha()->getTipo() == Soldado &&
					casillero->getFicha()->getJugador()->getNumeroDeJugador() == this->getNumeroDeJugador()){
					std:: cout << "|" << " Soldado"<<"|";
				} else if (casillero->getFicha()->getTipo() == Avion &&
						   casillero->getFicha()->getJugador()->getNumeroDeJugador() == this->getNumeroDeJugador()) {
					std:: cout << "|" << "  Barco "<<"|";
				}else if (casillero->getFicha()->getTipo() == Barco &&
						  casillero->getFicha()->getJugador()->getNumeroDeJugador() == this->getNumeroDeJugador()){
					std:: cout << "|" << "  Avion "<<"|";
				} else if(casillero->getEstado() == Inactivo){
					std:: cout << "|" << "Inactivo"<<"|";
				} else{
					std:: cout << "|" << "  Vacio "<<"|";
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

Lista<TipoDeFicha>* Jugador :: getListaDeFichas(){
	return this->listaDeFichas;
}

void Jugador :: imprimirListaDeFichas(){
	this->getListaDeFichas()->iniciarCursor();
	cout << "Sus fichas son: " << endl;
	while(this->listaDeFichas->avanzarCursor()){
		TipoDeFicha tipo = this->listaDeFichas->obtenerCursor();
		if(tipo == Avion){
			cout << "| Avion |" << endl;
		}
		else if(tipo == Barco){
			cout << "| Barco |" << endl;
		}
		else if(tipo == Avion){
			cout << "|Soldado|" << endl;
		}
	}
}

void Jugador :: agregarFicha(TipoDeFicha tipo){
	this->getListaDeFichas()->agregar(tipo);
}

void Jugador :: eliminarFicha(TipoDeFicha tipo){
	this->listaDeFichas->iniciarCursor();
	int posicion = 0;
	int cantidad = 0;
	while(this->listaDeFichas->avanzarCursor()){
		TipoDeFicha tipoActual = this->listaDeFichas->obtenerCursor();
		if(tipoActual == tipo && cantidad < 1){
			this->getListaDeFichas()->remover(posicion);
			cantidad++;
		}
		posicion++;
	}

}

bool Jugador :: fichaDentroDeLista(TipoDeFicha tipo){
	this->listaDeFichas->iniciarCursor();

	while(this->listaDeFichas->avanzarCursor()){
		TipoDeFicha tipoActual = this->listaDeFichas->obtenerCursor();
		if(tipoActual == tipo){
			return true;
		}

	}
	return false;
}


//verificar el tema de casillero
/*
bool Jugador::validarMovimiento(Casillero* x, Casillero* y, Casillero* z, Casillero* xNueva, Casillero* yNueva, Casillero* zNueva){
	int movimientoEnX = xNueva->getPosicionEnX() - x->getPosicionEnX();
    int movimientoEnY = yNueva->getPosicionEnX() - y->getPosicionEnX();
	int movimientoEnZ = zNueva->getPosicionEnX() - z->getPosicionEnX();
    if (movimientoEnX < 0) {movimientoEnX = movimientoEnX * (-1);}
    if (movimientoEnY < 0) {movimientoEnY = movimientoEnY * (-1);}
	if (movimientoEnZ < 0) {movimientoEnZ = movimientoEnZ * (-1);}

    return (movimientoEnX == 0 || movimientoEnY == 0 || movimientoEnZ == 0 ||
		    movimientoEnX == movimientoEnY || movimientoEnX == movimientoEnZ ||
		    movimientoEnY == movimientoEnZ);
};
*/


