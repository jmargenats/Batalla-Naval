
#include <iostream>
#include<string>
#include "Ficha.h"
#include "carta.h"


    Carta::Carta(TipoDeCarta tipo){
        switch (tipo)
        {
        case AtaquerAvion:
            //Condición de que avión esté en el aire
            for(int i = 0; i < 2; i++){
                this->ataqueAvionOBarco(unsigned int x, unsigned int y, unsigned int z);
            }
            break;
        case AtaqueBarco:
            //Condición de que barco esté en agua
            for(int i = 0; i < 2; i++){
                this->ataqueAvionOBarco(unsigned int x, unsigned int y, unsigned int z);
            }       
            this->ataqueMisil();
            break;
        case Misil:
            this->ataqueMisil();
            break;
        case TeletransportarSoldado:
            this->teletransportarse();
            break;
        case SaltearElTurno:
            this->saltearTurno();
            break;
        }
    };
    // obtener(i)->getNumeroDeSoldados() < 1
    void Carta::ataqueAvionOBarco(unsigned int x, unsigned int y, unsigned int z){
        if (this->tablero->getCasillero(x, y, z)->getFicha() == NULL){
			this->tablero->getCasillero(x, y, z)->setEstado(Inactivo);
		} else { // Debería ser una función porque se repite varias veces, también hay que tener en cuenta que podría haber armamento (que se eliminaría)
			this->tablero->getCasillero(x, y, z)->getFicha()->getJugador()->restarSoldado();
			for(unsigned int i = 1; i <= this->jugadores->contarElementos(); i++){
				if(this->jugadores->obtener(i)->getNumeroDeSoldados() < 1){
					if(this->jugadores->obtener(i)->getNumeroDeJugador() == batallaCampal->getNumeroDeJUgadores()){
						this->jugadores->remover(i);
					}
				}
			}
		}
    };

    void Carta::ataqueMisil(unsigned int x, unsigned int y, unsigned int z){
        if (this->tablero->getCasillero(x, y, z)->getFicha() == NULL){
            this->tablero->getCasillero(x, y, z)->setEstado(Inactivo); // ataca la posición
            this->tablero->obtenerCasillerosVecinos(x, y, z)->iniciarCursor(); // ataca a los casilleros alrededor
			while(this->tablero->obtenerCasillerosVecinos(x, y, z)->avanzarCursor()){
				Casillero* casilleroVecino = this->tablero->obtenerCasillerosVecinos(x, y, z)->obtenerCursor();
				casilleroVecino->setEstado(Inactivo);
			}
			
        } else { // Debería ser una función porque se repite varias veces, también hay que tener en cuenta que podría haber armamento (que se eliminaría)
			this->tablero->getCasillero(x, y, z)->getFicha()->getJugador()->restarSoldado();
			for(unsigned int i = 1; i <= this->jugadores->contarElementos(); i++){
				if(this->jugadores->obtener(i)->getNumeroDeSoldados() < 1){
					if(this->jugadores->obtener(i)->getNumeroDeJugador() == batallaCampal->getNumeroDeJUgadores()){
						this->jugadores->remover(i);
					}
				}
			}
		}
    };

//que la carta sea para transportar un soldado
//arreglar lo que se pide
void Carta::teletransportarse(){
	int xAntiguo, yAntiguo, xNuevo, yNuevo;
	std::cout <<  "Elija un soldado para transportar, e ingrese sus coordenadas" << std::endl;
	this->jugadorActual->imprimirTableroPersonal();
	std::cout <<  "Ingrese la fila" << std::endl;
	std:: cin >> xAntiguo;
	std::cout <<  "Ingrese la columna" << std::endl;
	std::cin << yAntiguo;
	std::cout <<  "Ingrese la fila nueva" << std::endl;
	std:: cin >> xNuevo;
	std::cout <<  "Ingrese la columna nueva" << std::endl;
	std::cin << yNuevo;
	Ficha* ficha = NULL;
	this->tablero->getCasillero(xAntiguo, yAntiguo, 1)->setFicha(ficha);
	this->tablero->colocarFicha(xNuevo, yNuevo, 1, Soldado, this->jugadorActual, tablero, jugadores);
};

void Carta::saltearTurno(){
	this->jugadores->avanzarCursor();
};


void Carta::agregarSoldado(){
	unsigned int x, y;
	std::cout << "Ingrese la fila" << std::endl;
	std::cin >> x;
	std::cout << "Ingrese la columna" << std::endl;
	std::cin >> y;
	this->tablero->colocarFicha(x, y, 1, Soldado, this->jugadorActual, tablero, jugadores);
};
