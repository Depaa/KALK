#include "sole.h"

sole::sole(double la, double lo, int t, data d, bool o, double tEQ, double sD) : data(d),
    lat(la), lon(lo), tz(t), time(d), oraLegale(o), tempoEQ(tEQ), soleDeclina(sD) {}

//costruttore di copia deep
sole::sole(const sole& s) :
    data(s), lat(s.getLat()), lon(s.getLon()), tz(s.getTz()), time(s.getTime()),
    oraLegale(s.getOraLegale()), tempoEQ(s.getTempoEQ()), soleDeclina(s.getSoleDeclina()) {}

double sole::getLat() const {
    return lat;
}
double sole::getLon() const {
    return lon;
}
int sole::getTz() const {
    return tz;
}
data sole::getTime() const {
    return time;
}
bool sole::getOraLegale() const {
    return oraLegale;
}
double sole::getTempoEQ() const {
    return tempoEQ;
}
double sole::getSoleDeclina() const {
    return soleDeclina;
}

bool sole::operator==(const sole& s) const {
    return lat==s.getLat() && lon==s.getLon() && tz==s.getTz() && time==s.getTime() && oraLegale==s.getOraLegale() && tempoEQ==s.getTempoEQ() && soleDeclina==s.getSoleDeclina();
}

//occhio ai parametri
double sole::giornoGiuliano() const {
    int year=getTime().getAnno();
    int month=getTime().getMese();

    if(getMese()<=2) {
        year=year-1;
        month=month+12;
    }

    int a=year/100;
    int b=2-a+a/4;
    int c=365.25*year;
    int d=30.6001*(month+1);

    double dataGiuliana=b+c+d+getGiorno()+1720994.50;

    double offsetGiornata=getSec()/86400;
    return dataGiuliana+offsetGiornata;

}
double sole::secoloGiuliano() const {
    double GG=giornoGiuliano();
    return (GG-2451545.0)/36525.0;
}
double sole::angoloSolare() const {
    double grado=3.14159265/180;    //grado=pi/180=0,01745
    double as=cos(90.833*grado)/(cos(lat*grado)*cos(soleDeclina*grado)) - tan(lat*grado)*tan(soleDeclina*grado);

    return acos(as);
}

double sole::soleUTC(int tsm) const {
    double degrado=180/3.14159265;    //degrado=180/pi=57.2957795
    if(tsm==3)
        degrado=3.14159265/180;
    //double sg=secoloGiuliano(); //servirebber per tempoEQ e soleDeclina
    double as=angoloSolare();

    if(tsm==1)
        as=-as;

    double aux=720-4*(lon+as*degrado)-tempoEQ;
    return aux;
}

data sole::Tramonto() const {
    double tempoUTC=soleUTC(1);

    double tempoLocale=tempoUTC+tz*60;    //in minuti
    tempoLocale+=oraLegale?60:0;

    data aux=getTime();

    if(tempoLocale>=0 && tempoLocale<1440) {
        int secondiLocale=tempoLocale*60;
        aux.cambiaSec(secondiLocale);
    }
    else {
        int incremento=(tempoLocale<0)?1:-1;
        while(tempoLocale<0 || tempoLocale>=1440) {
            tempoLocale=tempoLocale+incremento*1440;
        }

        int secondiLocale=tempoLocale*60;
        aux.cambiaSec(secondiLocale);
    }
    return aux;
}

data sole::Sorgere() const {
    double tempoUTC=soleUTC(2);

    double tempoLocale=tempoUTC+tz*60.0;    //in minuti
    tempoLocale+=oraLegale?60:0;

    data aux=getTime();

    if(tempoLocale>=0 && tempoLocale<1440) {
        int secondiLocale=tempoLocale*60;
        aux.cambiaSec(secondiLocale);
    }
    else {
        int incremento=(tempoLocale<0)?1:-1;
        while(tempoLocale<0 || tempoLocale>=1440) {
            tempoLocale=tempoLocale+incremento*1440;
        }

        int secondiLocale=tempoLocale*60;
        aux.cambiaSec(secondiLocale);
    }
    return aux;
}

data sole::mezzogiornoSolare() const {
    double tempoUTC=soleUTC(3);

    double tempoLocale=tempoUTC+tz*60.0;    //in minuti
    tempoLocale+=oraLegale?60:0;

    data aux=getTime();

    if(tempoLocale>=0 && tempoLocale<1440) {
        int secondiLocale=tempoLocale*60;
        aux.cambiaSec(secondiLocale);
    }
    else {
        int incremento=(tempoLocale<0)?1:-1;
        while(tempoLocale<0 || tempoLocale>=1440) {
            tempoLocale=tempoLocale+incremento*1440;
        }

        int secondiLocale=tempoLocale*60;
        aux.cambiaSec(secondiLocale);
    }
    return aux;
}

void sole::cambiaLat(double l) {
    if(l<-90 || l>90)
        overflow_error();
    else
        lat=l;
}

void sole::cambiaLon(double l) {
    if(l<-180 || l>180)
        overflow_error();
    else
        lon=l;
}

void sole::cambiaTz(int t) {
    if(t<-11 || t>14)
        overflow_error();
    else
        tz=t;
}

void sole::cambiaTime(data d) {
    //passo con il costruttore quindi sarà già una data corretta
    time=d;
}

void sole::cambiaLegale(bool l) {
    oraLegale=l;
}

void sole::cambiaTempoEQ(double e) {
    //massimi e minimi non disponibili
    //l'utente come specificato deve calcolarseli
    tempoEQ=e;
}

void sole::cambiaSoleDeclina(double s) {
    soleDeclina=s;
}


void sole::clearMem() {
    //vengono passati i valori di Padova al 1/01/2018 10:00
    data d(1, 1, 2018, 10, 0, 0);
    cambiaLat(45.40643);
    cambiaLon(11.87676);
    cambiaTz(1);
    cambiaTime(d);
    cambiaLegale(false);
    cambiaTempoEQ(-3.459);
    cambiaSoleDeclina(-22.996);
}

ostream& operator <<(ostream& os, const sole& s) {
    //tolgo ore/minuti/secondi
    os << "Il giorno " << s.getTime().getGiorno() << "/" << s.getTime().getMese() << "/" << s.getTime().getAnno() << endl;
    os << "Sorgere: " << s.Sorgere();
    os << "Mezzogiorno Solare: " << s.mezzogiornoSolare();
    os << "Tramonto: " << s.Tramonto();
    return os;
}
