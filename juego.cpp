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
}

bool Juego::isBlocked(int row, int col){
    pair<int,int> aux(row,col);
    if(grid[row][col] == 1)
        return (false);
    else
        return (true); //TRUE si la celda esta bloqueada
}

bool Juego::isBlockedF(int row, int col,  pair<int,int> f1, pair<int,int> f2, pair<int,int> f3){
    pair<int,int> aux(row,col);
    if(aux.first==f1.first && aux.second==f1.second)
        return (true);
    else if(aux.first==f2.first && aux.second==f2.second)
        return (true);
    else if(aux.first==f3.first && aux.second==f3.second)
        return (true);
    else
        return (false); 
    //TRUE si la celda esta bloqueada
}

pair<int,int> Juego::randomStart(){
    //Posicion aleatoria entre margenes [1 ROW-1, 1 COL-1]
    int posX=1+abs(rand())%(COL-2);
    int posY=1+abs(rand())%(ROW-2);
    
    //Comprobamos si es válida y si no cambiamos la posición:
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
