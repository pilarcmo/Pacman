#include "movAleat.h"

//Funcion movimiento (aleatorio - fantasmas)
//Añadir condicion de la posicion de otro fantasma: tampoco se mueva si ya esta ocupado
pair<int,int> randomMov(Juego juego1,int col, int row,pair<int,int> f1, pair<int,int> f2, pair<int,int> f3){
  
        int valor = rand() % 4 +1;
        switch (valor) {
        case 1: // Mov izq
            if (juego1.isBlocked(row,col-1)==false && juego1.isBlockedF(row,col-1,f1,f2,f3)==false)
                col = col-1;
            break;
        case 2: // Mov dcha
            if (juego1.isBlocked(row,col+1)==false && juego1.isBlockedF(row,col+1,f1,f2,f3)==false)
                col = col+1;
            break;
        case 3: // Mov up
            if (juego1.isBlocked(row-1,col)==false && juego1.isBlockedF(row-1,col,f1,f2,f3)==false)
                row = row-1;
            break;
        case 4: // Mov down
            if (juego1.isBlocked(row+1,col)==false && juego1.isBlockedF(row+1,col,f1,f2,f3)==false)
                row = row+1;
            break;
        }
        pair<int,int> posicion(col,row);   
        
    return posicion;
}
