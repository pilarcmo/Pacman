#include "juego.h"

Juego::Juego(){
    puntuacion=0;
    salida=0;
    vidas=3;
}

int Juego::marcadorUp(){
    return puntuacion++;
}

int Juego::marcadorUp10(){
    return puntuacion+=10;
}

void Juego::gameover(){
    salida=1;
    cout << "Final del juego" <<endl;
    exit(0);
    return;

}

void Juego::restaVida(){
    vidas--;
    if(vidas==0){Juego::gameover();}
}

bool Juego::isBlocked(int row, int col){
    if(grid[row][col] == 1)
        return (false);
    else
        return (true); //TRUE si la celda esta bloqueada
}

