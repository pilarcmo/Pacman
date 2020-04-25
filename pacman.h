#ifndef PACMAN_H
#define PACMAN_H

#include "juego.h"
#include "fantasma.h"

class Pacman : public Juego{
public:
    pair<int,int> posPM;
    Pacman();
    //~Pacman();
    int chequeaVida(pair<int,int> pospm, pair <int,int> posf);
};
#endif // PACMAN_H
