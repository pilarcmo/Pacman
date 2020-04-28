#include "movimiento.h"

//Funcion movimiento (lectura teclado juego1)
pair<int,int> keyMov(Juego juego1,int row, int col){
    char key;
    if (kbhit()) { //Modifica posicion segun flechas presionadas:
        key=getch();
        switch (key) {
        case IZDA: // Mov izq
            if (juego1.isBlocked(row,col-1)==false)
                col = col-1;
            break;
        case DCHA: // Mov dcha
            if (juego1.isBlocked(row,col+1)==false)
                col = col+1;
            break;
        case ARRIBA: // Mov up
            if (juego1.isBlocked(row-1,col)==false)
                row = row-1;
            break;
        case ABAJO: // Mov down
            if (juego1.isBlocked(row+1,col)==false)
                row = row+1;
            break;
        case ' ': // Salida juego
            juego1.gameover();
            break;
        }
    }
    pair<int,int> posicion(row,col);
    return posicion;
}
