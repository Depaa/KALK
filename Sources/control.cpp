#include "control.h"

control::control(model* m) : mod(m){}

control::~control() {}

bool control::onClickCreaOrario(QString t) const {
    try {
        /*viene utilizzato string in quanto se avessi usato QTime poi non avrei potuto gestire
         * l'eccezione di QT nel caso i valori non fossero entro i parametri di QTime */

        QRegExp separator("(,|:|/)");
        QStringList aux=t.split(separator);
        int h=aux.operator [](0).toInt();
        int m=aux.operator [](1).toInt();
        int s=aux.operator [](2).toInt();
        mod->buildOrario(h, m, s);
    }
    catch (overflow_error) {
        return false;
    }
    return true;
}

bool control::onClickCreaData(QString d) const {
    try {
        QRegExp separator("(,|:|/)");
        QStringList aux=d.split(separator);
        int g=aux.operator [](0).toInt();
        int me=aux.operator [](1).toInt();
        int a=aux.operator [](2).toInt();
        int h=aux.operator [](3).toInt();
        int mi=aux.operator [](4).toInt();
        int s=aux.operator [](5).toInt();
        mod->buildData(g, me, a, h, mi, s);
    }
    catch (overflow_error) {
        return false;
    }
    return true;
}

bool control::onClickCreaFuso(string f) const {
    try {
        mod->buildFusoorario(f);
    }
    catch (overflow_error) {
        return false;
    }
    return true;
}

bool control::onClickCreaSole(QString s) const {
    try {
        QRegExp separator("(,|:|/)");
        QStringList aux=s.split(separator);
        double la=aux.operator [](0).toDouble();
        double lo=aux.operator [](1).toDouble();
        int t=aux.operator [](2).toInt();
        //ora gli passo una data con tutti i relativi parametri
        int g=aux.operator [](3).toInt();
        int me=aux.operator [](4).toInt();
        int a=aux.operator [](5).toInt();
        int h=aux.operator [](6).toInt();
        int mi=aux.operator [](7).toInt();
        int s=aux.operator [](8).toInt();
        //oraLegale è un Int, fare controllo se è 1 o 0
        bool ol=aux.operator [](9).toInt();
        double eq=aux.operator [](10).toDouble();
        double sd=aux.operator [](11).toDouble();

        if(ol!=0 && ol!=1)
            //qua non sono molto sicuro, forse è return false;
            throw overflow_error();
        else
            mod->buildSole(la, lo, t, data(g, me, a, h, mi, s), ol, eq, sd);
    }
    catch (overflow_error) {
        return false;
    }
    return true;
}

//METODI VIRTUALI
bool control::onClickSomma(QString sum) const {
    QRegExp separator("(,|:|/)");
    QStringList aux=sum.split(separator);
    int h=aux.operator [](0).toInt();
    int m=aux.operator [](1).toInt();
    int s=aux.operator [](2).toInt();

    //mancano controlli se h,m,s sono != int

    mod->somma(h, m, s);
    return true;
}

bool control::onClickSottrazione(QString sum) const {
    QRegExp separator("(,|:|/)");
    QStringList aux=sum.split(separator);
    int h=aux.operator [](0).toInt();
    int m=aux.operator [](1).toInt();
    int s=aux.operator [](2).toInt();
    mod->somma(h, m, s);
    return true;
}

void control::onClickClear() const {
    mod->clearMemory();
}

//metodi solo di orario
double control::onClickVelocita(double km) const {
    return mod->distanzaVelocita(km);
}

void control::onClickOrarioForm() const {

}

void control::onClickDividi() const {

}


//metodi solo di data
int control::onClickSettimana() const { //numero settimana
    return mod->settimaneAnno();
}

int control::onClickGiornoAnno() const { //numero
    return mod->giorniAnno();
}

string control::onClickGiornoSett() const { //nome giorno
    return mod->giorniSettimana();
}

string control::onClickStagione() const {
    return mod->stagioni();
}

void control::onClickDataForm() const {

}

int control::onClickDurata(QString s) const {
    QRegExp separator("(,|:|/)");
    QStringList aux=s.split(separator);
    int g=aux.operator [](0).toInt();
    int me=aux.operator [](1).toInt();
    int a=aux.operator [](2).toInt();
    return mod->durataDate(g, me, a);
}


//metodi solo di fuso
int control::onClickFuso() const {
    return mod->getFuso();
}

double control::onClickLat() const {
    return mod->getLatitude();
}

double control::onClickLon() const {
    return mod->getLongitude();
}

int control::onClickEmis() const {
    return mod->getEmisfero();
}

int control::onClickDifferenza(string c) const {
    return mod->differenzaFusi(c);
}

QDateTime control::getDateTime() const {
    int g=mod->Giorno();
    int me=mod->Mese();
    int a=mod->Anno();
    int o=mod->Ore();
    int mi=mod->Minuti();
    int s=mod->Secondi();
    QDate auxD(g, me, a);
    QTime auxT(o, mi, s);
    return QDateTime(auxD, auxT);
}

QDateTime control::onClickOrarioAltraCitta(string c) const {
    mod->orarioAltraCitta(c);
    return getDateTime();
}


//metodi solo di sole
QDateTime control::onClickSunrise() const {
    mod->sunrise();
    return getDateTime();
}

QDateTime control::onClickSunset() const {
    mod->sunset();
    return getDateTime();
}

QDateTime control::onClickNoon() const {
    mod->solarnoon();
    return getDateTime();
}

