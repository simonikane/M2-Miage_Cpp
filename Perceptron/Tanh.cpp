//
// Created by DiKeLa M'Babane on 19/05/2020.
//

#include "Tanh.h"
#include <math.h>

using namespace std;

Tanh::Tanh() {
}

double Tanh::prim(double val) {
    //Calcul de la tangente
    double tanh = (exp(val) - exp(-val)) / (exp(val) + exp(-val));
    //la derivé de la tangente
    double tanhPrime = 1 - pow(tanh, 2);
    return tanhPrime;
}

double Tanh::operator()(double val) {
    double tanh = (exp(val) - exp(-val)) / (exp(val) + exp(-val));
    return tanh;

}
