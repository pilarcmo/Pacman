#include "juego.h"

Juego::Juego(){
    puntuacion=0;
    vidas=3;
}

int Juego::marcadorUp(){
    return puntuacion++;
}

int Juego::marcadorUp10(){
    return puntuacion+=10;
}

void Juego::gameover(){
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

pair<int,int> Juego::randomStart(){
    //Posicion aleatoria entre margenes [1 ROW-1, 1 COL-1]
    int posX=1+abs(rand())%(COL-2);
    int posY=1+abs(rand())%(ROW-2);
    
    //Comprobamos si es v�lida y si no cambiamos la posici�n:
    while(Juego::isBlocked(posY,posX)==true){
        int aux1 =-1 + abs(rand())%3, aux2=-1+abs(rand())%3;
        posX=posX+aux1;
        posY=posY+aux2;
    }
        
    pair<int,int>posicion(posX,posY);

 return posicion;
}

int Juego::grid[ROW][COL]={ 
        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
        {0,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,0},
        {0,1,0,1,0,0,0,0,1,1,1,0,0,0,0,1,0,1,0},
        {0,1,0,1,1,1,1,1,1,0,1,1,1,1,1,1,0,1,0},
        {0,1,0,1,0,0,0,1,0,0,0,1,0,0,0,1,0,1,0},
        {0,1,1,1,1,0,1,1,1,1,1,1,1,0,1,1,1,1,0},
        {0,0,0,0,1,0,1,0,0,1,0,0,1,0,1,0,0,0,0},
        {0,0,0,0,1,1,1,0,1,1,1,0,1,1,1,0,0,0,0},
        {0,0,0,0,1,0,1,0,1,1,1,0,1,0,1,0,0,0,0},
        {0,0,0,0,1,0,1,0,0,0,0,0,1,0,1,0,0,0,0},
        {0,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,0},
        {0,1,0,0,1,0,0,0,1,0,1,0,0,0,1,0,0,1,0},
        {0,1,1,0,1,1,1,1,1,1,1,1,1,1,1,0,1,1,0},
        {0,0,1,0,0,1,0,0,0,1,0,0,0,1,0,0,1,0,0},
        {0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0},
        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}
    };
