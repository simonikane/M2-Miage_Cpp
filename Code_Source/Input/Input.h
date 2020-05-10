//
// Created by CRYSTA on 10/05/2020.
//

#ifndef PROJET_CPP_INPUT_H
#define PROJET_CPP_INPUT_H


class Input{
    public:
        //Input(char label);
        virtual double& operator[](int i);// permet d'accéder à une valeur du tableau
        char get_label();// Renvoie le label de l'input
        ~Input();

    private:
        char label;// le label de l'input
};


#endif //PROJET_CPP_INPUT_H
