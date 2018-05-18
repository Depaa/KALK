#include "orario.h"

//costruttore
orario::orario(int o, int m, int s) {
    if(o<0 || o>23 || m<0 || m>59 || s<0 || s>59)
        throw overflow_error();
    else
        sec=(o*3600)+(m*60)+s;
}

//costruttore di copia deep
orario::orario(const orario& o) : sec(o.getSec()) {}

//distruttore
orario::~orario() {}

int orario::getOre() const {
    return sec/3600;
}

int orario::getMinuti() const {
    return (sec/60)%60;
}

int orario::getSecondi() const {
    return sec%60;
}

int orario::getSec() const {
    return sec;
}

void orario::cambiaSec(int s) {
    sec=s;
}


bool orario::operator==(const orario& o) const {
    return o.sec==sec;
}

orario* orario::somma(const orario& o) const {
    int secT=0, minT=0, oreT=0;

    secT=o.getSecondi()+sec;
    minT=o.getMinuti()+secT/60;
    secT=secT%60;
    oreT=o.getOre()+minT/60;
    minT=minT%60;
    oreT=oreT%24;

    orario *aux=new orario(oreT, minT, secT);
    return aux;
}

orario* orario::sottrazione(const orario& o) const {
    int secT=0, minT=0, oreT=0;

    if(o.getSecondi()>getSecondi()) {
        secT=60+(getSecondi()-o.getSecondi());
        //secT=60+(sec%60-o.getSecondi());
        minT=minT+1;
    }
    else
        secT=getSecondi()-o.getSecondi();

    if(o.getMinuti()+minT>getMinuti()) {
        minT=60+(getMinuti()-(o.getMinuti()+minT));
        oreT=oreT+1;
    }
    else
        minT=getMinuti()-(o.getMinuti()+minT);

    if(o.getOre()+oreT>getOre())
        oreT=24+(getOre()-(o.getOre()+oreT));
    else
        oreT=getOre()-(o.getOre()+oreT);

    orario* aux=new orario(oreT, minT, secT);
    return aux;
}

void orario::aggiungiSecondi(int s) {
    if(s<0)
        sottraiSecondi(-s);
    else if(s>0 && s+sec>86400)
        sec=sec+s-86400*((s+sec)/86400);
    else if(s>=0)
        sec=sec+s;
}

void orario::aggiungiMinuti(int m) {
    if(m<0)
        sottraiMinuti(-m);
    else if(m>0 && m*60+sec>86400)
        sec=sec+(m*60)-86400*((sec+m*60)/86400);
    else if(m>0)
        sec=sec+m*60;
}

void orario::aggiungiOre(int o) {
    if(o<0)
        sottraiOre(-o);
    else if(o>0 && o*3600+sec>86400)
        sec=sec+(o*3600)-86400*((sec+o*3600)/86400);
    else if(o>0)
        sec=sec+o*3600;
}

void orario::sottraiSecondi(int s) {
    if(s<0)
        aggiungiSecondi(-s);
    else if(s>0 && sec<s) //giorni precedenti
        sec=86400-((86400*(s/86400))-(sec-s))%86400;
    else if(s>=0)
        sec=sec-s;
}

void orario::sottraiMinuti(int m) {
    if(m<0)
        aggiungiMinuti(-m);
    else if(m>0 && sec<m*60)
        sec=86400-((86400*((m*60)/86400))-(sec-m*60))%86400;
    else if(m>0)
        sec=sec-m*60;
}

void orario::sottraiOre(int o) {
    if(o<0)
        aggiungiOre(-o);
    else if(o>0 && sec<o*3600)
        sec=86400-((86400*((o*3600)/86400))-(sec-o*3600))%86400;
    else if(o>0)
        sec=sec-o*3600;
}

//ritorna la velocità media fatta in un intervallo o per fare km kilometri
double orario::distanzaVel(double km) const {
    return (km/sec)*3600;
}


orario orario::quantoMancaMezzogiorno() const {
    orario* aux=new orario();
    if(sec > 43200)  //se orario>12:00:00
        aux->sec=86400-sec+43200;
    else
        aux->sec=43200-sec;
    return *aux;
}

orario orario::divisione(int d) const {
    //divido sec in d parti
    orario* aux=new orario;
    if(sec<d)
        std::cerr << "errore" << endl;
    else
        aux->sec=sec/d;
    return *aux;
}

orario orario::formato12h() const{
    orario* aux=new orario;
    if(sec>=43200)
        aux->sec=sec-43200;
    else
        aux->sec=sec;
    return *aux;
}

void orario::clearMem() {
    cambiaSec(0);
}

ostream& operator<<(ostream& os, const orario& o) {
    return os << o.getOre() << ":" << o.getMinuti() << ":" << o.getSecondi() << endl;
}
