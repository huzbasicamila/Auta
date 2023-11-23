//
// Created by Amila Huzbasic on 11/21/2023.
//

#ifndef AUTA_MARKA_H
#define AUTA_MARKA_H

class Marka {
private:
    char naziv[30], zemljaPorijekla[40];

public:
    Marka();
    void setNaziv();
    void setZemljaPorijekla();
    char* getNaziv();
    char* getZemljaPorijekla();
    ~Marka(){};
};

#endif //AUTA_MARKA_H
