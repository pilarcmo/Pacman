#ifndef OTHERFUNCTIONS_H
#define OTHERFUNCTIONS_H

#include <iostream>
#include <conio.h>
#include <windows.h>
#include "juego.h"
#include "monedas.h"

#define ARRIBA 72
#define ABAJO 80
#define IZDA 75
#define DCHA 77

using namespace std;

pair<int,int> randomMov(Juego juego1,int row, int col);

pair<int,int> keyMov(Juego juego1,int row, int col);

void visualizar(Juego juego1, Monedas moneda, pair<int,int> posPM,pair<int,int> posF,pair<int,int> posFr);

#endif // OTHERFUNCTIONS_H
