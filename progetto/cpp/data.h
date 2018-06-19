#ifndef DATA_H
#define DATA_H
#include"orario.h"
using std::string;

/*
    gennaio, 31
    febbraio, 28 (29 se bisestile)
    marzo, 31
    aprile, 30
    maggio, 31
    giugno, 30
    luglio, 31
    agosto, 31
    settembre, 30
    ottobre, 31
    novembre, 30
    dicembre, 31
*/

class data : public orario
{
    private:
        int giorno;
        int mese;
        int anno;
        //sec è ereditato
    public:
        //costruttore per costruire le gg/mm/aa
        data(int, int, int);
        //costruttore GIORNO-MESE-ANNO-ORE-MINUTI-SECONDI
        data(int=1, int=1, int=2018, int=0, int=0, int=0);
        //cotruttore GIORNO-MESE-ANNO-SECONDI
        //data(int=1, int=1, int=0, int=0);

        //costruttore di copia deep
        data(const data&);

        int getGiorno() const;
        int getMese() const;
        int getAnno() const;

        bool operator==(const data&) const;

        bool operator<(const data&) const;

        bool isBisestile() const;
        //bool dataError() const;

        int giorniMese() const;

        virtual data* somma(const orario&) const;
        virtual data* sottrazione(const orario&) const;

        virtual void aggiungiSecondi(int);
        virtual void aggiungiMinuti(int);
        virtual void aggiungiOre(int);
        virtual void sottraiSecondi(int);
        virtual void sottraiMinuti(int);
        virtual void sottraiOre(int);

        virtual void aggiungiGiorno(int);
        virtual void aggiungiMese(int);
        virtual void aggiungiAnno(int);
        virtual void togliGiorno(int);
        virtual void togliMese(int);
        virtual void togliAnno(int);

        int contaSettAnno() const;
        int contaGiorniAnno() const;

        string stagione() const;
        string giornoSettimana() const;
        string meseAnno() const;
        string formatoData() const;

        int durata(const data&) const;

        virtual void cambiaGiorno(int);
        virtual void cambiaMese(int);
        virtual void cambiaAnno(int);

        virtual void clearMem();
};

ostream& operator<<(ostream&, const data&);

#endif // DATA_H
