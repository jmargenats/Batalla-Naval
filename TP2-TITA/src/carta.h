#ifndef CARTA_H_
#define CARTA_H_

#include "Ficha.h"
#include "Tablero.h"
#include "BatallaCampal.h"
#include "Casillero.h"
#include <string>

enum TipoDeCarta {
	AtaqueBarco, AtaquerAvion, Misil, TeletransportarSoldado, SaltearElTurno, AgregarSoldado
};
class Jugador;
class Tablero;
class Carta{
    private:
        TipoDeCarta tipo;
        Tablero* tablero; 
        Lista<Jugador*>* jugadores;
        Jugador * jugadorActual;
        Casillero* casillero;
        BatallaCampal* batallaCampal;

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
