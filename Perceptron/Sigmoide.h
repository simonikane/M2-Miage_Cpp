//
// Created by DiKeLa M'Babane on 21/05/2020.
// Cette classe définit la fonction d'activation "Sigmoide".

#ifndef PROJET_CPP_SIGMOIDE_H
#define PROJET_CPP_SIGMOIDE_H
#include "Fonction_activation.h"

class Sigmoide: public Fonction_activation {
    public:
        double prim(double val);
        double operator()(double val) override;
    private:
};


#endif //PROJET_CPP_SIGMOIDE_H
