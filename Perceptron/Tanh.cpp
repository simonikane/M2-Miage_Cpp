//
// Created by DiKeLa M'Babane on 19/05/2020.
// Cette classe définit la fonction d'activation "Tanh".

#include "Tanh.h"
#include <math.h>

using namespace std;

/** @brief Application de la dérivée
   @param double val : donnée issue du dataset
   @return double : La dérivée de val (Tangente) */
double Tanh::prim(double val) {
    double tanh = (exp(val) - exp(-val)) / (exp(val) + exp(-val));
    double tanhPrime = 1 - pow(tanh, 2);
    return tanhPrime;
}

/** @brief Application de la fonction d'activation
   @param double val : donnée issue du dataset
   @return double : la fonction d'application appliquée sur "val" */
double Tanh::operator()(double val) {
    double tanh = (exp(val) - exp(-val)) / (exp(val) + exp(-val));
    return tanh;

}
