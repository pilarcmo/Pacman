#ifndef FRUTAS_H
#define FRUTAS_H

#include "juego.h"

class Frutas: public Juego
{
public:
    pair<int,int> posFr;
    Frutas();
    int existeFruta(pair<int,int> posPM);
};

#endif // FRUTAS_H
