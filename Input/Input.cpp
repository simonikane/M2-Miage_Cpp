//
// Created by CRYSTA on 10/05/2020.
//

#include "Input.h"
#include <string>

Input::Input() {

}

Input::~Input() {

}

std::string Input::get_label() {
    return this->label;
}

void Input::set_label(std::string label) {
    this->label = label;
}