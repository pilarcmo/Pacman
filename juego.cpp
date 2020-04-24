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
    puntuacion+=10;
    return puntuacion;
}

void Juego::gameover(){
    salida=1;
    cout << "Final del juego" <<endl;
    cout << "Su puntuacion final es " << puntuacion << endl;
    return;
}

void Juego::restaVida(){
    vidas--;
    if(vidas==0){gameover();}
}

void Juego::visualizar(pair<int,int> posPM,pair<int,int> posF){
//Añadir moneditas
    system("cls");
    for (int i=0; i<ROW; i++){
        for(int j=0; j<COL; j++){
            if (posPM.first==i && posPM.second==j)
                cout << "X"; //Por poner algo
            else if (posF.first==i && posF.second==j)
                cout << "M";
            else{
                if (grid[i][j]==1)
                    cout <<" ";
                else
                    cout << grid[i][j];
            }
        }
        cout << endl;
    }
    return;
}

bool Juego::isBlocked(int row, int col){
    if(grid[row][col] == 1)
        return (false);
    else
        return (true); //TRUE si la celda esta bloqueada
}

//Funcion movimiento (lectura teclado juego1)
pair<int,int> keyMov(Juego juego1,int row, int col){
    if (_kbhit()) { //Modifica posicion segun teclas presionadas: w a s d
        switch (_getch()) {
        case 'a': // Mov izq
            if (juego1.isBlocked(row,col-1)==false)
                col = col-1;
            break;
        case 'd': // Mov dcha
            if (juego1.isBlocked(row,col+1)==false)
                col = col+1;
            break;
        case 'w': // Mov up
            if (juego1.isBlocked(row-1,col)==false)
                row = row-1;
            break;
        case 's': // Mov down
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
