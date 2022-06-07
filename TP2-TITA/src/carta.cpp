#include "Ficha.h"
#include "carta.h"


    Carta::Carta(TipoDeCarta tipo){
        switch (tipo)
        {
        case Avion:
            //Condición de que avión esté en el aire
            for(int i = 0; i = 2; i++){
                this->ataqueAvionOBarco(unsigned int x, unsigned int y, unsigned int z);
            }
            break;
        case Barco:
            //Condición de que barco esté en agua
            for(int i = 0; i = 2; i++){
                this->ataqueAvionOBarco(unsigned int x, unsigned int y, unsigned int z);
            }       
            this->ataqueMisil();
            break;
        case Misil:
            this->ataqueMisil();
            break;
        case Teletransportarse:
            this->teletrasportarse();
            break;
        case saltearElTurno:
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
        //Creería que así está bien la implementación para el misil, no entendí bien la verdad
        if (this->tablero->getCasillero(x, y, z)->getFicha() == NULL){
            this->tablero->getCasillero(x, y, z)->setEstado(Inactivo);
            this->casillero->getVecino(x, y, z)->setEstado(Inactivo);
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

    void Carta::teletrasportarse(){

    };

    void Carta::saltearTurno(){

    };

    void Carta::agregarSoldado(){

    };