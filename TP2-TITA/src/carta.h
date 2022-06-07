#ifndef CARTA_H_
#define CARTA_H_

#include "Ficha.h"
#include "Tablero.h"
#include "BatallaCampal.h"
#include "Casillero.h"
#include <string>

enum TipoDeCarta {
	Barco, Avion, Misil, Teletransportarse, saltearElTurno, agregarSoldado
};

class Carta{
    private:
        TipoDeCarta tipo;
        Tablero* tablero; 
        Lista<Jugador*>* jugadores;
        BatallaCampal* batallaCampal;
        Casillero* casillero;

    public:
        Carta(TipoDeCarta tipo);
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
        void teletrasportarse();

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