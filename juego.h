#ifndef JUEGO_H
#define JUEGO_H

#include <iostream>
#include <cstdlib>
#include <ctime>

// Definicion de tamaño tablero:
#define ROW 21
#define COL 27

using namespace std;

class Juego{
public:
    int puntuacion;
    static int grid[ROW][COL];
    Juego(); //Constructor
    int vidas; //salida?
    int marcadorUp();
    void gameover();
    bool isBlocked(int row, int col); //Comprobar si la celda esta bloqueada
    pair<int,int> randomStart();
    void restaVida();
    int marcadorUp10();
};

#endif // JUEGO_H
