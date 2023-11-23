//
// Created by Amila Huzbasic on 11/21/2023.
//
#include "Datum.h"
#include <iomanip>


Datum::Datum() {
    this->dan=1;
    this->mjesec=12;
    this->godina=1900;
}

void Datum::setDan() {
    switch (this->mjesec) {
        case 1: case 3: case 5: case 7: case 8: case 10: case 12:
        do{
            std::cout<<"Unesite dan: ";
            std::cin>>this->dan;
            if(this->dan > 31) {
                std::cout<<"[GRESKA]" << this->mjesec << ". Mjesec ima samo 31 dan!\n";

            } else if (this->dan<1) {
                std::cout<<" [GRESKA] Dan mora biti pozitivni broj\n";
            }
        } while (this->dan<1 || this->dan>31);
        break;
        case 4: case 6: case 9: case 11:
            do {
                std::cout<< "Unesite dan: ";
                std::cin>>this->dan;
                if(this->dan> 30) {
                    std::cout<<"[GRESKA]"<< this->mjesec << " ima 30 dana!";
                } else if (this->dan<1) {
                    std::cout<<"[GRESKA] Dan mora biti pozitivan broj.";
                }
            } while(this->dan<1 || this->dan>30);
            break;
        case 2:
            if (this->godina % 4 ==0) {
                do {
                    std::cout <<"Unesite dan:";
                    std::cin>> this->dan;
                    if (this->dan>29) {
                        std::cout<<"[GRESKA] Prestupna godina";
                    } else if (this->dan<1){
                        std::cout<<"[GRESKA] Dan mora biti pozitivan broj!";
                    }
                }while(this->dan<1 || this->dan>29);
            } else {
                do {
                    std::cout<<"Unesite dan: ";
                    std::cin>> this->dan;
                    if(this->dan >28) {
                        std::cout<<"[GRESKA] Nije prestupna godina!";
                    } else if (this->dan <1) {
                        std::cout<< "[GRESKA] Dan mora da bude pozitivan broj!";
                    }
                } while(this->dan<1 || this->dan>28);
            }
            break;
        default:
            break;
    }
    std::cin.ignore();
}

void Datum::setMjesec() {
    do {
        std::cout<<"Unesi redni broj mjeseca: ";
        std::cin>>this->mjesec;
        if(this->mjesec<1 || this->mjesec>12) {
            std::cout<<"[GRESKA] Pogresno unesen redni broj mjeseca!\n";
        }

    } while (this->mjesec<1 || this->mjesec>12);
    std::cin.ignore();
}

void Datum::setGodina() {
    do {
        std:: cout<<"Unesite godinu: ";
        std:: cin>>this->godina;
        if(this->godina<1900) {
            std::cout<<"[GRESKA] Pogresno unesena godina!";
        }
    } while (this->godina<1900);
    std::cin.ignore();
}

int Datum::getDan() {
    return this->dan;
}

int Datum::getMjesec() {
    return this->mjesec;
}

int Datum::getGodina() {
    return this->godina;
}

void Datum::postaviDaatum() {
    std::cout<<"**UNOS DATUMA**\n";
    this->setGodina();
    this->setMjesec();
    this->setDan();
}

void Datum::ispisDatum() {
    std::cout << std::setw(2) << std::setfill('0') << this->getDan() << "."
              << std::setw(2) << std::setfill('0') << this->getMjesec() << "."
              << this->getGodina() << ".\n";
}

std::string Datum::getDatum() {
    std::string stringDan, stringMjesec;
    if(this->dan<10){
        stringDan = "0"+std::to_string(this->dan);
    }else{
        stringDan = std::to_string(this->dan);
    }
    if(this->mjesec<10){
        stringMjesec = "0"+std::to_string(this->mjesec);
    }else{
        stringMjesec = std::to_string(this->mjesec);
    }
    std::string rez = stringDan + "." + stringMjesec + "." + std::to_string(this->godina) + ". - " + this->nazivDana();
    return rez;
}

std::string Datum::nazivDana() {
    int m = this->mjesec;
    if(m == 1){
        m = 11;
    }else if(m == 2){
        m = 12;
    }else{
        m -= 2;
    }
    int d = this->dan;
    int g = this->godina;
    int D = g % 100;
    int C = g / 100;
    int f = d+(13*m-1)/5+D+D/4+C/4-2*C;
    if(f<0){
        int temp = f;
        do{
            if(std::abs(temp) % 7 != 0) temp--;
        }while(std::abs(temp)%7 != 0);
        f = std::abs(temp)-std::abs(f);
    }else{
        f %= 7;
    }
    switch(f){
        case 0:
            return "Nedjelja";
            break;
        case 1:
            return "Ponedjeljak";
            break;
        case 2:
            return "Utorak";
            break;
        case 3:
            return "Srijeda";
            break;
        case 4:
            return "Četvrtak";
            break;
        case 5:
            return "Petak";
            break;
        case 6:
            return "Subota";
            break;
        default:
            return "Ponedjeljak";
    }
}
