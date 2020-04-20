#include "header.h"

// ----------- CLASE JUEGO: ------------
class Juego{
private:
    int puntuacion;
    int grid[ROW][COL]=
    {
        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
        {0,1,1,1,1,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,1,1,1,1,0},
        {0,1,0,0,0,1,0,0,0,0,0,0,1,0,1,0,0,0,0,0,0,1,0,0,0,1,0},
        {0,1,0,0,0,1,0,0,0,1,1,1,1,1,1,1,1,1,0,0,0,1,0,0,0,1,0},
        {0,1,0,0,0,1,0,0,0,1,0,0,0,0,0,0,0,1,0,0,0,1,0,0,0,1,0},
        {0,1,1,1,1,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,1,1,1,1,0},
        {0,1,0,0,0,1,0,0,0,0,0,0,1,0,1,0,0,0,0,0,0,0,0,0,0,1,0},
        {0,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,0},
        {0,0,0,0,0,0,0,1,0,1,0,0,0,1,0,0,0,1,0,1,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,1,0,1,0,1,1,1,1,1,0,1,0,1,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,1,1,1,0,1,1,1,1,1,0,1,1,1,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,1,0,1,0,1,1,1,1,1,0,1,0,1,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,1,0,1,0,0,0,0,0,0,0,1,0,1,0,0,0,0,0,0,0},
        {0,1,1,1,1,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,1,1,1,1,0},
        {0,1,0,0,0,1,0,0,0,0,0,0,1,0,1,0,0,0,0,0,0,1,0,0,0,1,0},
        {0,1,1,1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,1,1,1,0},
        {0,0,0,1,0,0,0,1,0,1,0,0,0,0,0,0,0,1,0,1,0,0,0,1,0,0,0},
        {0,1,1,1,1,1,1,1,0,1,1,1,1,0,1,1,1,1,0,1,1,1,1,1,1,1,0},
        {0,1,0,0,0,0,0,0,0,0,0,0,1,0,1,0,0,0,0,0,0,0,0,0,0,1,0},
        {0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0},
        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}
    };
public:
        Juego(); //Constructor
        int salida;
        int marcadorUp();
        void gameover();
        bool isBlocked(int row, int col); //Comprobar si la celda esta bloqueada
        void visualizar(pair<int,int> posPM, pair<int,int> posF);
};

Juego::Juego(){
    puntuacion=0;
    salida=0;
}

int Juego::marcadorUp(){
    return puntuacion++;
}

void Juego::gameover(){
    salida=1;
    cout << "Final del juego" <<endl;
    cout << "Su puntuacion final es " << puntuacion << endl;
    return;
}

void Juego::visualizar(pair<int,int> posPM,pair<int,int> posF){
//Añadir elementos que faltan
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