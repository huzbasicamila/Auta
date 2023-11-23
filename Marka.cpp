//
// Created by Amila Huzbasic on 11/21/2023.
//

#include <iostream>
#include <string.h>
#include "Marka.h"

Marka::Marka() {
    strcpy_s(this->naziv, "Avto");
    strcpy_s(this->zemljaPorijekla, "Nigdjezemska");
}

void Marka::setNaziv() {
    std::cout<<"Unesi naziv: ";
    std::cin.getline(this->naziv, 30);
}

void Marka::setZemljaPorijekla() {
    std::cout<<"Unesi zemlju porijekla: ";
    std::cin.getline(this->zemljaPorijekla, 40);
}

char* Marka::getNaziv() {
    return this->naziv;
}

char* Marka::getZemljaPorijekla() {
    return this->getZemljaPorijekla();
}

