#ifndef CARTA_H_
#define CARTA_H_

#include "Ficha.h"
#include "Tablero.h"
#include "BatallaCampal.h"
#include "Casillero.h"
#include <string>

enum TipoDeCarta {
	Barco, Avion, Misil, Teletransportarse, SaltearElTurno, AgregarSoldado
};

class Carta{
    private:
        TipoDeCarta tipo;
        Tablero* tablero; 
        Lista<Jugador*>* jugadores;
        BatallaCampal* batallaCampal;
        Casillero* casillero;
        Jugador * jugadorActual;

    public:
        Carta(TipoDeCarta tipo, Tablero* tablero, Lista<Jugador*>* jugadores, Jugador * jugadorActual,BatallaCampal* batallaCampal,Casillero* casillero);
        /*
        * pre:
        * post:
        */
        void ataqueAvionOBarco(unsigned int x, unsigned int y, unsigned int z);

        /*
        * pre:
        * post:
        */
        void ataqueMisil(unsigned int x, unsigned int y, unsigned int z);

        /*
        * pre:
        * post:
        */
        void teletrasportarse(unsigned int xAntiguo, unsigned int yAntiguo, unsigned int zAntiguo, unsigned int xNuevo, unsigned int yNuevo, unsigned int zNuevo);

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
