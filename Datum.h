#include <iostream>

class Datum {
private:
    int dan, mjesec, godina;

public:
    Datum();
    void setDan();
    void setMjesec();
    void setGodina();

    int getDan();
    int getMjesec();
    int getGodina();

    void postaviDaatum();
    void ispisDatum();

    std::string getDatum();
    std::string nazivDana();
    ~Datum(){};
};