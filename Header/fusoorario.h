#ifndef FUSOORARIO_H
#define FUSOORARIO_H
#include "data.h"

class fusoorario : public data
{
    private:
        string citta;
    public:
        fusoorario();
        fusoorario(string);
        fusoorario(string, data);

        fusoorario(const fusoorario&);

        string getCitta() const;

        int Fuso() const;
        double Latitudine() const;
        double Longitudine() const;
        int Emisfero() const;

        int confrontaFusi(string) const;
        data orarioCitta(string) const;

        void cambiaCitta(string);

        virtual void clearMem();
        /*
         * non vengono ridefinite somma e sottrazione
         * in quanto per sommare o sottrarre un fuso
         * e' sufficiente invocare aggiungiOre alla
         * data
        */
};

ostream& operator <<(ostream&, const fusoorario&);

#endif // FUSOORARIO_H
