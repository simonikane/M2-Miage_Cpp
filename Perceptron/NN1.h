//
// Created by CRYSTA on 27/05/2020.
//

#ifndef PROJET_CPP_NN1_H
#define PROJET_CPP_NN1_H


#include "../Input/Input.h"

class NN1 {
public:
    NN1(int intSize, int nbCategories);

    char evaluation(Input &input);

    void apprentissage(Input &input, double mu);

private:
};


#endif //PROJET_CPP_NN1_H
