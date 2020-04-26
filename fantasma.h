#ifndef FANTASMA_H
#define FANTASMA_H

#include "juego.h"

class Fantasma : public Juego{
public:
    pair<int,int> posF;
    Fantasma(); // Se inicia en posicion aleatoria
};

#endif // FANTASMA_H
