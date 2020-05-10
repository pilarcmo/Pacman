#ifndef FRUTAS_H
#define FRUTAS_H

#include "juego.h"

class Frutas: public Juego
{
public:
    pair<int,int> posFr;
    Frutas();
    int existeFruta(pair<int,int> posPM); // Comprueba si el pacman ha encontrado una fruta
};

#endif // FRUTAS_H
