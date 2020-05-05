#include "otherfunctions.h"

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

//Funcion movimiento (aleatorio - fantasmas)
//Añadir condicion de la posicion de otro fantasma: tampoco se mueva si ya esta ocupado
pair<int,int> randomMov(Juego juego1,int row, int col){
        int valor = rand() % 4 +1;
        switch (valor) {
        case 1: // Mov izq
            if (juego1.isBlocked(row,col-1)==false)
                col = col-1;
            break;
        case 2: // Mov dcha
            if (juego1.isBlocked(row,col+1)==false)
                col = col+1;
            break;
        case 3: // Mov up
            if (juego1.isBlocked(row-1,col)==false)
                row = row-1;
            break;
        case 4: // Mov down
            if (juego1.isBlocked(row+1,col)==false)
                row = row+1;
            break;
        }
    pair<int,int> posicion(row,col);

    return posicion;
}

//Muestra posiciones del PM, del F, de la fruta y las monedas, además de la puntuación y las vidas restantes
void visualizar(Juego juego1, Monedas moneda, pair<int,int> posPM,pair<int,int> posF,pair<int,int> posFr){
    system("cls");
    for (int i=0; i<ROW; i++){
        for(int j=0; j<COL; j++){
            if (posPM.first==i && posPM.second==j)
                cout << "X"; //Por poner algo
            else if (posF.first==i && posF.second==j)
                cout << "M";
            else if (posFr.first==i && posFr.second==j)
                cout << "F";
            else if (moneda.dispMoneda(i,j))
                cout << ".";
            else{
                if (juego1.grid[i][j]==1)
                    cout <<" ";
                else
                    cout << juego1.grid[i][j];
            }
        }
        cout << endl;
    }
    cout << "Score: " << juego1.puntuacion << "  Vidas: " << juego1.vidas;
    cout << endl;
    return;
}
