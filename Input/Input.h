//
// Created by CRYSTA on 10/05/2020.
//

#ifndef PROJET_CPP_INPUT_H
#define PROJET_CPP_INPUT_H


#include <string>

class Input{
    public:
        Input();
        virtual double operator[](int i) = 0;// permet d'accéder à une valeur du tableau
        std::string get_label();// Renvoie le label de l'input
        void set_label(std::string label);
        ~Input();

    private:
        std::string label;// le label de l'input
};


#endif //PROJET_CPP_INPUT_H
