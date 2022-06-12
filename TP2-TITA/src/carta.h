#ifndef CARTA_H_
#define CARTA_H_


#include <string>
#include "Lista.h"
#include "Enums.h"
#include "BatallaCampal.h"


class Jugador;
class Tablero;
class Carta{
    private:
		Tablero* tablero;
		Lista<Jugador*>* jugadores;
		Jugador * jugadorActual;

    public:
        Carta(TipoDeCarta tipo, Tablero* tablero, Lista<Jugador*>* jugadores, Jugador * jugadorActual);

        /*
        * pre:
        * post:ataca con un avion
        */
        void ataqueAvionOBarco(unsigned int x, unsigned int y, unsigned int z);

        /*
        * pre:
        * post:ataca con un misil
        */
        void ataqueMisil(unsigned int x, unsigned int y, unsigned int z);

        /*
        * pre:
        * post: teletransporta un soldado
        */
        void teletransportarse();
        /*
        * pre:
        * post:saltea un turno
        */
        void saltearTurno();

        /*
        * pre:
        * post: agrega un soldado
        */
        void agregarSoldado();
};

#endif
