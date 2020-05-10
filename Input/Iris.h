//
// Created by CRYSTA on 10/05/2020.
//

#ifndef PROJET_CPP_IRIS_H
#define PROJET_CPP_IRIS_H


#include "Input.h"

class Iris: public Input{
    public:
        Iris(int indice);//charge la description de la fleur et son label
        double& operator[](int i);
        //get_label deja defini
    private:
};


#endif //PROJET_CPP_IRIS_H
