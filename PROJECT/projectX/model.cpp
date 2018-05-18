#include "model.h"

model::model() : m() {}

model::~model() {
    delete m;
}

//chiamo i costruttori
void model::buildOrario(int o, int mi, int s) {
    orario* aux=new orario(o, mi, s);
    if(m)
        delete m;
    m=aux;
}

void model::buildData(int g, int me, int a, int o, int mi, int s) {
    orario* aux=new data(g, me, a, o, mi, s);
    if(m)
        delete m;
    m=aux;
}

void model::buildFusoorario(string c) {
    orario* aux=new fusoorario(c);
    if(m)
        delete m;
    m=aux;
}

void model::buildFusoorario(string c, data d) {
    orario* aux=new fusoorario(c, d);
    if(m)
        delete m;
    m=aux;
}

void model::buildSole(double la, double lo, int tz, data t, bool ol, double teq, double sd) {
    orario* aux=new sole(la, lo, tz, t, ol, teq, sd);
    if(m)
        delete m;
    m=aux;
}

int model::Ore() const {
    return m->getOre();
}

int model::Minuti() const {
    return m->getMinuti();
}

int model::Secondi() const {
    return m->getSecondi();
}

int model::SecondiTot() const {
    return m->getSec();
}

int model::Giorno() const {
    //devo fare downcasting da orario* a data*
    data* aux=dynamic_cast<data*>(m);
    return aux->getGiorno();
}

int model::Mese() const {
    data* aux=dynamic_cast<data*>(m);
    return aux->getMese();
}

int model::Anno() const {
    data* aux=dynamic_cast<data*>(m);
    return aux->getAnno();
}


string model::Citta() const {
    fusoorario* aux=dynamic_cast<fusoorario*>(m);
    return aux->getCitta();
}


double model::Latitude() const {
    sole* aux=dynamic_cast<sole*>(m);
    return aux->getLat();
}

double model::Longitude() const {
    sole* aux=dynamic_cast<sole*>(m);
    return aux->getLon();
}

int model::timeZone() const {
    sole* aux=dynamic_cast<sole*>(m);
    return aux->getTz();
}

data model::tempoS() const {
    sole* aux=dynamic_cast<sole*>(m);
    return aux->getTime();
}

bool model::oraLegal() const {
    sole* aux=dynamic_cast<sole*>(m);
    return aux->getOraLegale();
}

double model::equazioneTempo() const {
    sole* aux=dynamic_cast<sole*>(m);
    return aux->getTempoEQ();
}

double model::declinazioneSolare() const {
    sole* aux=dynamic_cast<sole*>(m);
    return aux->getSoleDeclina();
}

//metodi virtuali con polimorfismo
//GIORNO-MESE-ANNO-ORE-MINUTI-SECONDI
void model::Sum(int o, int mi, int s) {
    if(s>59 || s<0 || mi>59 || mi<0 || o>23 || o<0) {
        m->aggiungiSecondi(s);
        m->aggiungiMinuti(mi);
        m->aggiungiOre(o);
    }
    else {
        try {
            dynamic_cast<data*>(m);
        }
        catch(std::bad_cast e) {
            m=m->somma(orario(o, mi, s));
        }
        m=m->somma(orario(o, mi, s));
    }
    //forse devo fare un controllo quando è data con dynamic cast
}

void model::Sub(int o, int mi, int s) {
    if(s>59 || s<0 || mi>59 || mi<0 || o>23 || o<0) {
        m->sottraiSecondi(s);
        m->sottraiMinuti(mi);
        m->sottraiOre(o);
    }
    else {
        try {
            dynamic_cast<data*>(m);
        }
        catch(std::bad_cast e) {
            m=m->sottrazione(orario(o, mi, s));
        }
        m=m->sottrazione(orario(o, mi, s));
    }
    //forse devo fare un controllo quando è data con dynamic cast
}


//funzioni virtuali
void model::clearMemory() {
    if(dynamic_cast<orario*>(m)) {
        //errore qua dentro
        m->clearMem();
    }
    //cambia i secondi in 0, poi accade l'errore fatale
}


//funzioni di orario
double model::distanzaVelocita(double km) const {
    return m->distanzaVel(km);
}

/*NB: CHIEDERE AL PROF SE VA BENE O E' MEGLIO FARE UN RITORNO IN INT*/
//tolto orario per void
orario model::orarioFormato() const {
    return m->formato12h();
}

 //controllare se da formato12h a formato24h
orario model::divisioneOrario(int d) const {
    return m->divisione(d);
    //niente dynamic_cast perchè è già orario
}


//funzioni di data
int model::settimaneAnno() const {
    data* aux=dynamic_cast<data*>(m);
    return aux->contaSettAnno();
}

int model::giorniAnno() const {
    data* aux=dynamic_cast<data*>(m);
    return aux->contaGiorniAnno();
}

string model::stagioni() const {
    data* aux=dynamic_cast<data*>(m);
    return aux->stagione();
}

string model::giorniSettimana() const {
    data* aux=dynamic_cast<data*>(m);
    return aux->giornoSettimana();
}

string model::dataFormato() const {
    data* aux=dynamic_cast<data*>(m);
    return aux->formatoData();
}

int model::durataDate(int g, int me, int a) const {
    data* auxM=dynamic_cast<data*>(m);
    return auxM->durata(data(g, me, a, 0, 0, 0));
}

void model::aggGiorni(int g) {
    data* aux=dynamic_cast<data*>(m);
    aux->aggiungiGiorno(g);
}

void model::togGiorni(int g) {
    data* aux=dynamic_cast<data*>(m);
    aux->togliGiorno(g);
}

//funzioni di fusoorario
int model::getFuso() const {
    fusoorario* aux=dynamic_cast<fusoorario*>(m);
    return aux->Fuso();
}

double model::getLatitude() const {
    fusoorario* aux=dynamic_cast<fusoorario*>(m);
    return aux->Latitudine();
}

double model::getLongitude() const {
    fusoorario* aux=dynamic_cast<fusoorario*>(m);
    return aux->Longitudine();
}

int model::getEmisfero() const {
    fusoorario* aux=dynamic_cast<fusoorario*>(m);
    return aux->Emisfero();
}

int model::differenzaFusi(string c) const {
    fusoorario* aux=dynamic_cast<fusoorario*>(m);
    return aux->confrontaFusi(c);
}

data model::orarioAltraCitta(string c) const {
    fusoorario* aux=dynamic_cast<fusoorario*>(m);
    return aux->orarioCitta(c);
}


//funzioni di sole
data model::sunrise() const {
    sole* aux=dynamic_cast<sole*>(m);
    return aux->Sorgere();
}

data model::sunset() const {
    sole* aux=dynamic_cast<sole*>(m);
    return aux->Tramonto();
}

data model::solarnoon() const {
    sole* aux=dynamic_cast<sole*>(m);
    return aux->mezzogiornoSolare();
}
/*
void model::stampacose() const {
    sole* aux=dynamic_cast<sole*>(m);
    cout << "lat: " << aux->getLat();
    cout << " lon: " << aux->getLon();
    cout << " tz: " << aux->getTz();
    cout << " data: " << aux->getTime();
    cout << " ol: " << aux->getOraLegale();
    cout << " teq: " << aux->getTempoEQ();
    cout << " sd: " << aux->getSoleDeclina();
}
*/
