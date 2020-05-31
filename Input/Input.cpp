//
// Created by CRYSTA on 10/05/2020.
// La classe "Input" représente tout type de donnée pouvant être analysé par le réseau de neurone
// Ainsi dans notre cas, ce sont des set d'iris et d'images.

#include "Input.h"

char Input::get_label() {
    return this->label;
}

void Input::set_label(char label) {
    this->label = label;
}