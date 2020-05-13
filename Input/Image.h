//
// Created by CRYSTA on 10/05/2020.
//

#ifndef PROJET_CPP_IMAGE_H
#define PROJET_CPP_IMAGE_H


#include "Input.h"

class Image: public Input{
    public:
        Image(int indice);//constructeur indice i correspondant à l'indice de l'image
        double operator[](int pixel);//Renvoie le niveau de gris du pixel correspondant
        //get_label deja utilisé dans Input même signature donc pas bésoin de le redefinir
    private:
        char pixel[28][28];

};

#endif //PROJET_CPP_IMAGE_H
