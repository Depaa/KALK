#ifndef ORARIO_H
#define ORARIO_H
#include<iostream>
#include"overflow_error.h"
using std::ostream; using std::cout; using std::endl;

class orario
{
    private:
        int sec;

    public:
        //costruttore ORE-MINUTI-SECONDI
        orario(int=0, int=0, int=0);

        //distuttore virtual
        virtual ~orario();

        //costruttore di copia deep
        orario(const orario&);

        //operatore di assegnazione
        //orario& operator=(const orario&);

        int getOre() const;
        int getMinuti() const;
        int getSecondi() const;
        //secondi totali per copia deep
        int getSec() const;

        //serve per cambiare i sec nelle sottoclassi qualora servisse
        void cambiaSec(int);

        bool operator==(const orario&) const;

        virtual orario* somma(const orario&) const;
        virtual orario* sottrazione(const orario&) const;

        virtual void aggiungiSecondi(int);
        virtual void aggiungiMinuti(int);
        virtual void aggiungiOre(int);
        virtual void sottraiSecondi(int);
        virtual void sottraiMinuti(int);
        virtual void sottraiOre(int);

        double distanzaVel(double) const;

        orario quantoMancaMezzogiorno() const;

        orario divisione(int) const;

        orario formato12h() const;

        virtual void clearMem();
};

ostream& operator<<(ostream&, const orario&);
#endif // ORARIO_H
