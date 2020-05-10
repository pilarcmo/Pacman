#include <ctime>

#include "juego.h"
#include "fantasma.h"
#include "frutas.h"
#include "pacman.h"
#include "otherfunctions.h"
#include "monedas.h"
#include "astar.cpp"

using namespace std;

int main() {
    srand(time(NULL));
    Juego juego1;
    Pacman pacman;
    Fantasma fantasma;
    Frutas fruta;
    Monedas moneda;
    visualizar(juego1, moneda, pacman.posPM,fantasma.posF,fruta.posFr);
    int q,puntuacionC=0,puntuacionF=0;

    cout << "Seleccione un modo de juego:\n [1] Mover Pacman con teclado \n [2] Juego automático " << endl;
    cin >> q;

    switch(q){
    case 1:
        while (juego1.salida==0){ //Espacio para salir
            //Movimiento de fantasma y pacman:
            pacman.posPM=keyMov(juego1,pacman.posPM.first,pacman.posPM.second);
            fantasma.posF=randomMov(juego1,fantasma.posF.first, fantasma.posF.second);
            //Si encuentra una moneda o una fruta suma la puntuación correspondiente
            puntuacionC=moneda.existeMoneda(pacman.posPM);
            puntuacionF=fruta.existeFruta(pacman.posPM);
            juego1.puntuacion=puntuacionC+puntuacionF;
            //Se comprueban las vidas del pacman y si se ha conseguido toda la puntuación
            juego1.vidas=pacman.chequeaVida(pacman.posPM,fantasma.posF);
            moneda.chequeaMonedas();

            visualizar(juego1, moneda, pacman.posPM,fantasma.posF,fruta.posFr);

            Sleep(80);
        } break;

    case 2:
        do{
        point s(pacman.posPM.first,pacman.posPM.second), e(fruta.posFr.first,fruta.posFr.second);
        aStar as;
        if( as.search( s, e) ) {
            std::list<point> path;
            int c=as.path(path);
            pair<int,int> posInicial=pacman.posPM;
            for( int x = 0; x < COL; x++ ) {
                for( int y = 0; y < ROW; y++ ) {
                    if( std::find( path.begin(), path.end(), point( x, y ) )!= path.end() ){
                        pacman.posPM.first=x;
                        pacman.posPM.second=y;
                    }
                    if(posInicial!=pacman.posPM){ //Esto para que no se este rehaciendo la pantalla mientras no se mueve nada
                        fantasma.posF=randomMov(juego1,fantasma.posF.first, fantasma.posF.second);
                        //Si encuentra una moneda o una fruta suma la puntuación correspondiente
                        puntuacionC=moneda.existeMoneda(pacman.posPM);
                        puntuacionF=fruta.existeFruta(pacman.posPM);
                        juego1.puntuacion=puntuacionC+puntuacionF;
                        //Se comprueban las vidas del pacman y si se ha conseguido toda la puntuación
                        juego1.vidas=pacman.chequeaVida(pacman.posPM,fantasma.posF);
                        moneda.chequeaMonedas();

                        visualizar(juego1, moneda, pacman.posPM,fantasma.posF,fruta.posFr);
                    }
                    Sleep(80); 
                }
            }
        }
        }while(!moneda.chequeaMonedas() && juego1.salida==0);
        break;
    }
    return 0;
}

