//
// Created by DiKeLa M'Babane on 21/05/2020.
//

#include "Sigmoide.h"
#include <math.h>

double Sigmoide::prim(double val) {
    //return Fonction_activation::prim(val);
    double fi = 1/(1 + exp(- val));
    double fiPrime = fi * (1 - fi);
    return fiPrime;
}

double Sigmoide::operator()(double val) {
    return this->prim(val);
}
