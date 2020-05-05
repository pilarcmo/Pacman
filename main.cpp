#include <ctime>

#include "juego.h"
#include "fantasma.h"
#include "frutas.h"
#include "pacman.h"
#include "otherfunctions.h"
#include "monedas.h"


using namespace std;

int main() {
    srand(time(NULL));
    Juego juego1;
    Pacman pacman;
    Fantasma fantasma;
    Frutas fruta;
    Monedas moneda;
    visualizar(juego1, moneda, pacman.posPM,fantasma.posF,fruta.posFr);
    int puntuacionC,puntuacionF;

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

            Sleep(80); //recomended speed is 40 to 80;
        }

    return 0;
}
