//
// Created by Amila Huzbasic on 11/21/2023.
//

#include <string.h>
#include <iostream>
#include "Auto.h"

Auto::Auto() {
    strcpy_s(this->tip, "Golf 2");
    strcpy_s(this-> gorivo, "dizel");
    this->godinaProizvodnje=1995;
    this->brojBrzina=5;
}

void Auto::setMarka() {
    this->marka.setNaziv();
    this->marka.setZemljaPorijekla();
}

void Auto::setTip() {
    std::cout<<"Unesite tip auta: ";
    std::cin.getline(this->tip, 30);
}

void Auto::setGorivo() {
    std::cout<<"Unesite vrstu goriva: ";
    std::cin.getline(this->gorivo, 40);
}

void Auto::setGodinaProizvodnje() {
    std::cout<<"Unesite godinu proizvodnje: ";
    std::cin>>this->godinaProizvodnje;
    std::cin.ignore();
}

void Auto::setBrojBrzina() {
    std::cout<<"Unesite broj brzina: ";
    std::cin>>this->brojBrzina;
    std::cin.ignore();
}

Marka Auto::getMarka() {
    return this->marka;
}

char* Auto::getTip() {
    return this->tip;
}

char *Auto::getGorivo() {
    return this->gorivo;
}

int Auto::getGodinaProizvodnje() {
    return this->godinaProizvodnje;
}

int Auto::getBrojBrzina() {
    return this->brojBrzina;
}

void Auto::postaviAuto() {
    std::cout << "***** Unos auta *****\n";
    this->setMarka();
    this->setTip();
    this->setGorivo();
    this->setGodinaProizvodnje();
    this->setBrojBrzina();
}

void Auto::ispisAuta() {
    std::cout << "Auto: " << this->marka.getNaziv() << " - " << this->getTip()
              << " iz " << this->marka.getZemljaPorijekla() << " sa "
              << this->getBrojBrzina() << " brzina.\n";
    std::cout << "Proizvedeno: " << this->getGodinaProizvodnje() << " godine "
              << "i trosi " << this->getGorivo() << ".\n";
}
