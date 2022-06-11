#ifndef CARTA_H_
#define CARTA_H_

#include "Ficha.h"
#include "Tablero.h"
#include "BatallaCampal.h"
#include "Casillero.h"
#include <string>

enum TipoDeCarta {
	AgregarBarco, AgregarAvion, Misil, TeletransportarSoldado, SaltearElTurno, AgregarSoldado
};
class Jugador;
class Tablero;
class Carta{
    private:
        TipoDeCarta tipo;
        Tablero* tablero; 
        Lista<Jugador*>* jugadores;
        Jugador * jugadorActual;

    public:
        Carta(TipoDeCarta tipo, Tablero* tablero, Lista<Jugador*>* jugadores, Jugador * jugadorActual);

        /*
        * pre:
        * post:
        */
        void ataqueAvionOBarco(unsigned int x, unsigned int y, unsigned int z);

        /*
        * pre:
        * post:
        */
        void ataqueMisil();

        /*
        * pre:
        * post:
        */
        void teletransportarse();
        /*
        * pre:
        * post:
        */
        void saltearTurno();

        /*
        * pre:
        * post:
        */
        void agregarSoldado();
};

#endif
