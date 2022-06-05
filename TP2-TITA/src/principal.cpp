#include <iostream>
#include <string>
#include "Casillero.h"
#include "Ficha.h"
#include"Lista.h"
#include "Tablero.h"
using namespace std;


int main (){

	Tablero tablero(3,3,3);
	Jugador *jugador = new Jugador(1, "Gustavo");
	Ficha *ficha = new Ficha(Soldado, jugador, 1);
	tablero.setFicha(1, 2, 2, ficha);

	tablero.imprimirMapa();

/*
	ListaX* longitud = new ListaX();

	for(int i = 0; i < 5; i++){
		Casillero* casillero = new Casillero(i, 1, 1, Tierra);
		longitud->agregar(casillero);
	}
	delete longitud;
	*/

	/*
	Casillero* casillero = new Casillero(1,2,2,Agua);
	NodoX* longitud = new NodoX(casillero);

	cout<<longitud->getCasillero()->getPosicionEnX()<<endl;
	delete casillero;
	delete longitud;
	 */

	//ni idea como usar templates
	//Lista<Casillero*> lista;



	/*
	Jugador *jugador = new Jugador(1, "Gustavo");
	Ficha *ficha = new Ficha(Soldado, jugador);
	Casillero* casillero = new Casillero(1,2,2,Agua);
	casillero->setFicha(ficha);
	cout<<casillero->getFicha()->getJugador()->getNombreDeJugador()<<endl;
	delete jugador;
	delete ficha;
	delete casillero;
	*/

	/*
	cout<<ficha->getJugador()->getNombreDeJugador()<<endl;
	cout<<ficha->getJugador()->getNumeroDeJugador()<<endl;
	*/

	/*
	Casillero * casillero = new Casillero(1,2,2,Agua);
	cout << casillero->getEstado() << endl;
	cout << casillero->getPosicionEnY() << endl;
	cout << casillero->getTipo() << endl;
	delete casillero;
	 */
	return 0;
}



