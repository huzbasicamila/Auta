//
// Created by Amila Huzbasic on 11/22/2023.
//

#include "MojeAuto.h"
#include "Marka.h"
#include <string.h>
#include <iostream>

MojeAuto::MojeAuto() {
    strcpy_s(this->registracija, "000-0-000");
    this->brzina=ler;
    this->stanje=ugasen;
}

void MojeAuto::setMojeAuto() {
    this->mojeAuto.postaviAuto();
}

void MojeAuto::setDatumRegistracije() {
    this->datumRegistracije.postaviDaatum();
}

void MojeAuto::setRegistracija() {
    std::cin.getline(this->registracija, 20);
    std::cin.ignore();
}

Auto MojeAuto::getMojeAuto() {
    return this->mojeAuto; //ispravit
}

Datum MojeAuto::getDatumRegistracije() {
    return this->datumRegistracije;
}

char* MojeAuto::getRegistracija() {
    return registracija;
}

std::string MojeAuto::ispisBrzine() {
    switch(brzina){
        case rikverc: return "Rikverc";
        //case ler: return "Ler";
        case prva: return "Prva";
        case druga: return "Druga";
        case treca: return "Treca";
        case cetvrta: return "Cetvrta";
        case peta: return "Peta";
        case sesta: return "Sesta";
        default: return "Ler";
    }

}

std::string MojeAuto::ispisStanja() {
    switch(stanje){
        case ugasen: return "Ugasen";
        case upaljen: return "Upaljen";
    }
}

void MojeAuto::unosMogAuta() {
    std::cout<<"Unos auta:";
    setMojeAuto();
    setDatumRegistracije();
    setRegistracija();

    int brzinaInput;
    do{
        std::cout<<"Unesite brzinu: (rikverc=0, ler=1, prva=2, druga=3, treca=4, cetvrta=5, peta=6, sesta=7):";
        std::cin>>brzinaInput;
        brzina = static_cast<Brzina>(brzinaInput);
    } while(brzinaInput<0 || brzinaInput>7);

    int stanjeInput;

    do{
        std::cout<<" Unesite stanje automobila: ";
        std::cin>>stanjeInput;
        stanje = static_cast<Stanje>(stanjeInput);
    } while(stanjeInput<0 || stanjeInput>1);


}

void MojeAuto::IspisMogAuta() {
    std::cout << "Marka i model auta: " <<  std::endl; // ovdje fali
    std::cout << "Datum registracije: " << getDatumRegistracije().getDatum() << std::endl;
    std::cout << "Registracija: " << getRegistracija() << std::endl;
    std::cout << "Brzina: " << ispisBrzine() << std::endl;
    std::cout << "Stanje: " << ispisStanja() << std::endl;


}

void MojeAuto::trenutnaBrzina() {
    std::cout<<"Trenutna brzina je: " << ispisBrzine();
}

void MojeAuto::prebaciRikverc() {
    if( stanje==ugasen) {
        std::cout <<"Auto je ugaseno!";
    } else {
        brzina=rikverc;
        std::cout<<"Auto je prebaceno u rikverc!";
    }
}

void MojeAuto::prebaciPrvaBrzina() {
    if(stanje==ugasen) {
        std::cout<<"Auto je ugaseno!";
    } else if (brzina==rikverc) {
        std::cout<<"Ne moze se prebaciti iz rikverca u prvu!";
    } else {
        brzina=prva;
        std::cout<<"Auto je prebaceno u prvu brzinu!";
    }
}

void MojeAuto::prebaciVecuBrzinu() {
    if(stanje==ugasen) {
        std::cout<<"Auto je ugaseno!";
    } else if (brzina==rikverc || brzina==sesta) {
        std::cout<<"Nemoguce je promijeniti u vecu brzinu!";
    } else {
        brzina=static_cast<Brzina>(static_cast<int>(brzina)+1);
        std::cout<< "Prebaceno u vecu brzinu! Brzina u kojoj je auto sada: " << brzina << std::endl;
    }
}

void MojeAuto::prebaciManjuBrzinu() {
    if(stanje==ugasen) {
        std::cout<<"Auto je ugaseno!";
    } else if (brzina==rikverc || brzina==ler) {
        std::cout<<"Nemoguce je promijeniti u manju brzinu!";
    } else {
        brzina=static_cast<Brzina>(static_cast<int>(brzina)-1);
        std::cout<< "Prebaceno u manju brzinu! Brzina u kojoj je auto sada: " << brzina << std::endl;
    }
}

void MojeAuto::promijeniStanje() {
    if (stanje==ugasen) {
    stanje=upaljen;
    std::cout<< "Auto je upaljeno!";
    } else {
        stanje=ugasen;
        std::cout<<"Auto je ugaseno!";
    }
}
