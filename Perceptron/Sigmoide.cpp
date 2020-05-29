//
// Created by DiKeLa M'Babane on 21/05/2020.
//

#include "Sigmoide.h"
#include <math.h>

double Sigmoide::prim(double val) {
    //return Fonction_activation::prim(val);
    double fi = 1/(1 + exp(- val));
    double fiPrime = fi * (1 - fi);
    fi = fiPrime < 0.5 ? 0 : 1;
    return fiPrime;
}

double Sigmoide::operator()(double val) {
    double fi = 1 / (1 + exp(-val));
    fi = fi < 0.5 ? 0 : 1;
    return fi;
}
