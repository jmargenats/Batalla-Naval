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
        * pre: Las posiciones ingresadas deben ser validas
        * post: Realiza un ataque, en caso de haber un soldado o armamento lo elimina y vuelve inactiva la casilla, 
        * en caso contrario solo vuelve inactiva la casilla
        */
        void ataqueAvionOBarco(unsigned int x, unsigned int y, unsigned int z);

        /*
        * pre: Las posiciones ingresadas deben ser validas
        * post: Realiza un ataque, en caso de haber un soldado o armamento lo elimina y vuelve inactiva la casilla, 
        * en caso contrario solo vuelve inactiva la casilla
        */
        void ataqueMisil(unsigned int x, unsigned int y, unsigned int z);
        /*
        * pre: Las posiciones ingresadas deben ser validas
        * post: Permite a un soldado moverse sin la restricción de movimiento horizontal, diagonal o vertical
        */
        void teletransportarse();
        /*
        * pre: -
        * post: Saltea el turno del siguiente jugador
        */
        void saltearTurno();

        /*
        * pre: Las posiciones ingresadas deben ser validas
        * post: Agrega un nuevo soldado
        */
        void agregarSoldado();

        enum TipoDeCarta obtenerCarta();
};

#endif
