#include "funMat.h"

/* Función que recibe un punto y un número, aumenta las componenetes del punto tanto como indique el número. */
void funcionEscalar(Punto *punto, int num){
    punto->X = punto->X + num;
    punto->Y = punto->Y + num;
}