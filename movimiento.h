#ifndef MOVIMIENTO_H
#define MOVIMIENTO_H

#include <iostream>
#include <conio.h>
#include <windows.h>
#include "juego.h"

#define ARRIBA 72
#define ABAJO 80
#define IZDA 75
#define DCHA 77

using namespace std;


pair<int,int> keyMov(Juego juego1,int row, int col);


#endif // MOVIMIENTO_H

