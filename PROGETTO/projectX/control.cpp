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

bool control::onClickCreaFuso(QString f) const {
    try {
        QRegExp separator("(,|:|/)");
        QStringList aux=f.split(separator);
        string c=aux.operator [](0).toStdString();
        //if()
        //se la lunghezza dopo è maggiore allora c'è altro
        if(!(aux.operator [](1).isEmpty())) {
            int g=aux.operator [](1).toInt();
            int me=aux.operator [](2).toInt();
            int a=aux.operator [](3).toInt();
            int o=aux.operator [](4).toInt();
            int mi=aux.operator [](5).toInt();
            int s=aux.operator [](6).toInt();

            data aux(g, me, a, o, mi, s);
            mod->buildFusoorario(c, aux);
        }
        else
            mod->buildFusoorario(c);
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
        int ol=aux.operator [](9).toInt();
        double eq=aux.operator [](10).toDouble();
        double sd=aux.operator [](11).toDouble();

        if((ol!=0 && ol!=1) || (t<-11 || t>14))
            throw overflow_error();
        data auxD(g, me, a, h, mi, s);
        mod->buildSole(la, lo, t, auxD, ol, eq, sd);
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

    mod->Sum(h, m, s);
    return true;
}

bool control::onClickSottrazione(QString sum) const {
    QRegExp separator("(,|:|/)");
    QStringList aux=sum.split(separator);
    int h=aux.operator [](0).toInt();
    int m=aux.operator [](1).toInt();
    int s=aux.operator [](2).toInt();
    mod->Sub(h, m, s);
    return true;
}

void control::onClickClear() {
    mod->clearMemory();
}

//metodi solo di orario
double control::onClickVelocita(double km) const {
    try {
        mod->distanzaVelocita(km);
    }
    catch (overflow_error) {
        return -1;
    }
    return mod->distanzaVelocita(km);
}

QTime control::onClickOrarioForm() const {
    orario aux=mod->orarioFormato();
    int s=aux.getSecondi();
    int m=aux.getMinuti();
    int o=aux.getOre();
    QTime auxT(o, m, s);
    return auxT;
}

QTime control::onClickDividi(int d) const {
    orario aux=mod->divisioneOrario(d);
    int s=aux.getSecondi();
    int m=aux.getMinuti();
    int o=aux.getOre();
    return QTime(o, m, s);
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

QString control::onClickDataForm() const {
    return QString::fromStdString(mod->dataFormato());
}

int control::onClickDurata(QString s) const {
    QRegExp separator("(,|:|/)");
    QStringList aux=s.split(separator);
    int g=aux.operator [](0).toInt();
    int me=aux.operator [](1).toInt();
    int a=aux.operator [](2).toInt();
    return mod->durataDate(g, me, a);
}

void control::onClickAggGiorni(int g) {
    mod->aggGiorni(g);
}

void control::onClickTogGiorni(int g) {
    mod->togGiorni(g);
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

QString control::onClickEmis() const {
    int aux=mod->getEmisfero();
    if(!aux)
        return "Boreale";
    else
        return "Australe";
}

int control::onClickDifferenza(string c) const {
    return mod->differenzaFusi(c);
}

QTime control::getTime() const {
    int o=mod->Ore();
    int mi=mod->Minuti();
    int s=mod->Secondi();
    QTime auxT(o, mi, s);
    return auxT;
}

QDate control::getDate() const {
    int g=mod->Giorno();
    int me=mod->Mese();
    int a=mod->Anno();
    QDate auxD(a, me, g);
    return auxD;
}

QDateTime control::getDateTime() const {
    int g=mod->Giorno();
    int me=mod->Mese();
    int a=mod->Anno();
    int o=mod->Ore();
    int mi=mod->Minuti();
    int s=mod->Secondi();
    QDate auxD(a, me, g);
    QTime auxT(o, mi, s);
    return QDateTime(auxD, auxT);
}

QString control::getFuso() const {
    string c=mod->Citta();
    return QString::fromStdString(c);
}

QDateTime control::onClickOrarioAltraCitta(string c) const {
    data aux=mod->orarioAltraCitta(c);
    int g=aux.getGiorno();
    int me=aux.getMese();
    int a=aux.getAnno();
    int o=aux.getOre();
    int mi=aux.getMinuti();
    int s=aux.getSecondi();
    QDate auxD(a, me, g);
    QTime auxT(o, mi, s);
    return QDateTime(auxD, auxT);
}


//metodi solo di sole
QDateTime control::onClickSunrise() const {
    data aux=mod->sunrise();
    int g=aux.getGiorno();
    int me=aux.getMese();
    int a=aux.getAnno();
    int o=aux.getOre();
    int mi=aux.getMinuti();
    int s=aux.getSecondi();
    QDate auxD(a, me, g);
    QTime auxT(o, mi, s);
    return QDateTime(auxD, auxT);
}

QDateTime control::onClickSunset() const {
    data aux=mod->sunset();
    int g=aux.getGiorno();
    int me=aux.getMese();
    int a=aux.getAnno();
    int o=aux.getOre();
    int mi=aux.getMinuti();
    int s=aux.getSecondi();
    QDate auxD(a, me, g);
    QTime auxT(o, mi, s);
    return QDateTime(auxD, auxT);
}

QDateTime control::onClickNoon() const {
    data aux=mod->solarnoon();
    int g=aux.getGiorno();
    int me=aux.getMese();
    int a=aux.getAnno();
    int o=aux.getOre();
    int mi=aux.getMinuti();
    int s=aux.getSecondi();
    QDate auxD(a, me, g);
    QTime auxT(o, mi, s);
    return QDateTime(auxD, auxT);
}
