#ifndef SOLE_H
#define SOLE_H
#include "data.h"
#include<math.h>

class sole : public data
{
    private:
        double lat;
        double lon;
        int tz;
        data time;
        bool oraLegale;
        double tempoEQ;
        double soleDeclina;
    public:
        //costruttore LAT-LON-TZ-TIME-ORALEGALE-TEMPOEQ-SOLEDECLINA
        sole(double=0, double=0, int=0, data=0, bool=false, double=0, double=0);

        //costruttore di copia deep
        sole(const sole&);

        double getLat() const;
        double getLon() const;
        int getTz() const;
        data getTime() const;
        bool getOraLegale() const;
        double getTempoEQ() const;
        double getSoleDeclina() const;


        void cambiaLat(double);
        void cambiaLon(double);
        void cambiaTz(int);
        void cambiaTime(data);
        void cambiaLegale(bool);
        void cambiaTempoEQ(double);
        void cambiaSoleDeclina(double);

        bool operator==(const sole&) const;

        //occhio ai parametri
        double giornoGiuliano() const;
        double secoloGiuliano() const;
        double angoloSolare() const;
        double soleUTC(int) const;

        data Tramonto() const;
        data Sorgere() const;
        data mezzogiornoSolare() const;

        virtual void clearMem();

};

ostream& operator<<(ostream&, const sole&);

#endif // SOLE_H
