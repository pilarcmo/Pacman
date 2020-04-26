#include "monedas.h"
Monedas::Monedas(){}

bool Monedas::chequeaMonedas(){
    int aux=0;
    for (int i=0; i<ROW; i++){
        for(int j=0; j<COL; j++){
            if(coins[i][j]==1){aux++;}
        }
    }
    //Si se han comido todas las monedas el juego finaliza
    if(aux==0){
        Juego::gameover();
        return true;
    }else{return false;}
}

int Monedas::existeMoneda(pair<int,int> posPM){
    //Si en la posicion del PM hay una moneda se suma un punto y ese hueco queda vacío
    if(coins[posPM.first][posPM.second]==1){
        Juego::marcadorUp();
        coins[posPM.first][posPM.second]=0;
    }
    return puntuacion;
}

//Esta función sirve para mostrar las monedas que hay en el tablero para la funcion visualizar
bool Monedas::dispMoneda(int i, int j){
    if(coins[i][j]==1){
        return true;
    }else{return false;}
}
