//
// Created by Amila Huzbasic on 11/22/2023.
//

#ifndef AUTA_MOJEAUTO_H
#define AUTA_MOJEAUTO_H

#include "Auto.h"
#include "Datum.h"

enum Brzina{rikverc=-1, ler, prva, druga, treca, cetvrta, peta, sesta};
enum Stanje{ugasen=0, upaljen};

class MojeAuto{
private:

    Auto mojeAuto;
    Datum datumRegistracije;
    char registracija[20];
    Brzina brzina;
    Stanje stanje;

public:
    MojeAuto();
    void setMojeAuto();
    void setDatumRegistracije();
    void setRegistracija();
    Auto getMojeAuto();
    Datum getDatumRegistracije();
    char* getRegistracija();

    std::string ispisBrzine();
    std::string ispisStanja();

    void unosMogAuta();
    void IspisMogAuta();
    void trenutnaBrzina();
    void prebaciRikverc();
    void prebaciPrvaBrzina();
    void prebaciVecuBrzinu();
    void prebaciManjuBrzinu();
    void promijeniStanje();

    ~MojeAuto()=default;

};

#endif //AUTA_MOJEAUTO_H
