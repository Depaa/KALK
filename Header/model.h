#ifndef MODEL_H
#define MODEL_H
/*
Model:
Manages the app data and state
Not concerned with UI or presentation
Often persists somewhere
Same model should be reusable, unchanged in different interfaces
*/
#include"sole.h"
#include"fusoorario.h"


class model
{
    private:
        orario* m;
    public:
        //costruttore
        model();
        //distruttore
        ~model();

        //chiamo i costruttori
        void buildOrario(int, int, int);
        void buildData(int, int, int, int, int, int);
        void buildFusoorario(string);
        void buildFusoorario(string, data);
        void buildSole(double, double, int, data, bool, double, double);

        int Ore() const;
        int Minuti() const;
        int Secondi() const;
        int SecondiTot() const;

        int Giorno() const;
        int Mese() const;
        int Anno() const;

        string Citta() const;

        double Latitude() const;
        double Longitude() const;
        int timeZone() const;
        data tempoS() const;
        bool oraLegal() const;
        double equazioneTempo() const;
        double declinazioneSolare() const;

        //metodi virtuali con polimorfismo
        //ORE-MINUTI-SECONDI
        void Sum(int, int, int);
        void Sub(int, int, int);

        //funzioni virtuali
        void clearMemory();

        //funzioni di orario
        double distanzaVelocita(double) const;
        /*NB: CHIEDERE AL PROF SE VA BENE O E' MEGLIO FARE UN RITORNO IN INT*/
        //tolto orario per void
        orario orarioFormato() const; //controllare se da formato12h a formato24h
        orario divisioneOrario(int) const;

        //funzioni di data
        int settimaneAnno() const;
        int giorniAnno() const;
        string stagioni() const;
        string giorniSettimana() const;
        string dataFormato() const;
        int durataDate(int, int, int) const;
        void aggGiorni(int);
        //funzioni di fusoorario
        int getFuso() const;
        double getLatitude() const;
        double getLongitude() const;
        int getEmisfero() const;
        int differenzaFusi(string) const;
        data orarioAltraCitta(string) const;

        //funzioni di sole
        data sunrise() const;
        data sunset() const;
        data solarnoon() const;
};

#endif // MODEL_H
