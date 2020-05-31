//
// Created by DiKeLa M'Babane on 21/05/2020.
// Cette classe définit la fonction d'activation "Sigmoide".

#include "Sigmoide.h"
#include <math.h>

/** @brief Application de la dérivée
   @param double val : donnée issue du dataset
   @return double : La dérivée de val (Sigmoide) */
double Sigmoide::prim(double val) {
    //return Fonction_activation::prim(val);
    double fi = 1/(1 + exp(- val));
    double fiPrime = fi * (1 - fi);
    return fiPrime;
}

/** @brief Application de la fonction d'activation
   @param double val : donnée issue du dataset
   @return double : la fonction d'application appliquée sur "val" */
double Sigmoide::operator()(double val) {
    double fi = 1 / (1 + exp(-val));
    return fi;
}
