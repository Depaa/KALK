#include "data.h"
#include<string>
#include<sstream>

namespace patch {
	template <typename T> std::string to_string(const T& n) {
		std::ostringstream stm;
		stm << n;
		return stm.str();
	}
}

//data::data() : orario(), giorno(1), mese(1), anno(2018) {}

//costruttore GIORNO-MESE-ANNO-ORE-MINUTI-SECONDI
data::data(int g, int me, int a, int o, int mi, int s) : orario(o, mi, s), giorno(g), mese(me), anno(a) {
    if(g<1 || g>giorniMese() || me<1 || me>12 || a<1 || a>3500) {
        throw overflow_error();
    }
}

data::data(int g, int m, int a) : orario(), giorno(g), mese(m), anno(a) {}

//costruttore GIORNO-MESE-ANNO-SECONDI
/*data::data(int g, int m, int a, int s) {
    giorno=g;
    mese=m;
    anno=a;
    cambiaSec(s);
}*/

//costruttore di copia deep
data::data(const data& d) :
    orario(d), giorno(d.getGiorno()), mese(d.getMese()), anno(d.getAnno()) {}

int data::getGiorno() const {
    return giorno;
}

int data::getMese() const {
    return mese;
}

int data::getAnno() const {
    return anno;
}

bool data::operator==(const data& d) const {
    return d.giorno==giorno && d.mese==mese && d.anno==anno;
}

bool data::isBisestile() const {
    bool bisestile=false;
    if(anno%4==0) {
        bisestile=true;
        if(anno%100==0)
            bisestile=false;
        if(anno%400==0)
            bisestile=true;
    }
    return bisestile;
}

/*
//non serve più
bool data::dataError() const {
    bool bisFeb=true;
    bool countMese=false;
    if(isBisestile() && mese==2)  //arriva fino a 29
        bisFeb=giorno<30;
    else if(mese==2)
        bisFeb=giorno<29;

    if(mese==11 || mese==4 || mese==6 || mese==9)
        countMese=giorno<31;
    else
        countMese=giorno<32;

    return bisFeb && countMese;
}*/

int data::giorniMese() const {
    int m=mese;
    if(m==2) {  //siamo a febbraio
        if(isBisestile())
            return 29;
        else
            return 28;
    }
    else if(m%2!=0 && m<8)  //gennaio, marzo, maggio, luglio
        return 31;
    else if(m%2==0 && m>6)  //agosto, ottobre, dicembre
        return 31;
    else
        return 30;
}

data* data::somma(const orario& d) const {
    data* aux=new data(*this);
    aux->aggiungiSecondi(d.getSecondi());
    aux->aggiungiMinuti(d.getMinuti());
    aux->aggiungiOre(d.getOre());

    return aux;
}

data* data::sottrazione(const orario& d) const {
    data* aux=new data(*this);
    aux->sottraiSecondi(d.getSecondi());
    aux->sottraiMinuti(d.getMinuti());
    aux->sottraiOre(d.getOre());

    return aux;
}

void data::aggiungiSecondi(int s) {
    if(s<0)
        sottraiSecondi(-s);
    else {
        //trovo quanti minuti devo aggiungere
        int m=(s+getSecondi())/60;
        if(m)
            aggiungiMinuti(m);

        //trovo quanti secondi rimangono
        s=(s+getSecondi())%60;
        int aux=getOre()*3600+getMinuti()*60+s;
        cambiaSec(aux);
    }
}

void data::aggiungiMinuti(int m) {
    if(m<0)
        sottraiMinuti(-m);
    else {
        //trovo quante ore devo aggiungere
        int o=(m+getMinuti())/60;
        if(o)
            aggiungiOre(o);

        //trovo quanti minuti rimangono
        m=(m+getMinuti())%60;
        int aux=getOre()*3600+m*60+getSecondi();
        cambiaSec(aux);
    }
}

void data::aggiungiOre(int o) {
    if(o<0)
        sottraiOre(-o);
    else {
        //trovo quanti giorni devo aggiungere
        int g=(o+getOre())/24;
        if(g)
            aggiungiGiorno(g);

        //trovo le ore rimanenti
        o=(o+getOre())%24;
        int aux=o*3600+getMinuti()*60+getSecondi();
        cambiaSec(aux);
    }
}

void data::sottraiSecondi(int s) {
    if(s<0)
        aggiungiSecondi(-s);
    else {
        int m=0;
        while(s>=60) {
            m=m+1;
            s=s-60;
        }
        if(s>getSecondi())
            m=m+1;
        if(m)
            sottraiMinuti(m);

        int aux=getOre()*3600+getMinuti()*60+((60+getSecondi()-s)%60);
        cambiaSec(aux);
    }
}

void data::sottraiMinuti(int m) {
    if(m<0)
        aggiungiMinuti(-m);
    else {
        int o=0;
        while(m>=60) {
            o=o+1;
            m=m-60;
        }
        if(m>getMinuti())
            o=o+1;
        if(o)
            sottraiOre(o);

        int aux=getOre()*3600+((60+getMinuti()-m)%60)*60+getSecondi();
        cambiaSec(aux);
    }
}

void data::sottraiOre(int o) {
    if(o<0)
        aggiungiOre(-o);
    else {
        int g=0;
        while(o>=24) {
            g=g+1;
            o=o-24;
        }
        if(o>getOre())
            g=g+1;
        if(g)
            togliGiorno(g);

        //int aux=86400-o*3600+getMinuti()*60+getSecondi();
        int aux=(86400+getSec()-o*3600)%86400;
        cambiaSec(aux);
    }
}

void data::aggiungiGiorno(int g) {
    if(g<0)
        togliGiorno(-g);
    else {
        while(g) {
            //calcolo i giorni totali da aggiungere
            int aux=giorno+g;
            //giorno=0 per far si che nella prossima iterazione non vengano contati ancora inutilmente
            giorno=0;
            if(aux<=giorniMese()) {
                giorno=aux;
                g=0;
            }
            else {
                g=aux-giorniMese();
                aggiungiMese(1);
            }
        }
    }
}

void data::aggiungiMese(int m) {
    if(m<0)
        togliMese(-m);
    else {
        int aux=m+mese;
        if(aux<=12)
            mese=aux;
        else {
            anno=anno+aux/12;
            mese=aux%12;
        }
    }
}

void data::aggiungiAnno(int a) {
    if(a<0)
        togliAnno(-a);
    else
        anno=anno+a;

}

void data::togliGiorno(int g) {
    if(g<0)
        aggiungiGiorno(-g);
    else {
        while(g) {
            //calcolo i giorni totali da aggiungere
            if(giorno>g) {
                giorno=giorno-g;
                g=0;
            }
            else {
                g=g-giorno;
                togliMese(1);
                giorno=giorniMese();
            }
        }
    }

}

void data::togliMese(int m) {
    if(m<0)
        aggiungiMese(-m);
    else {
        int aux=mese-m;
        if(aux>=1)
            mese=aux;
        else {
            anno=anno+aux/12-1;
            mese=12+aux%12;
        }
    }
}

void data::togliAnno(int a) {
    if(a<0)
        aggiungiAnno(-a);
    else
        anno=anno-a;

    if(anno<0) {
        //anno=0;
        throw overflow_error();
    }
}


int data::contaSettAnno() const {
    int count=1;
    data aux=*this;
    bool stop=false;
    while(!stop) {
        if(aux.getMese()==1 && aux.getGiorno()<=7)
            stop=true;
        else {
            aux.togliGiorno(7);
            count=count+1;
        }
    }
    return count;
}

int data::contaGiorniAnno() const {
    int count=0;
    data aux=*this;
    bool stop=false;
    while(!stop) {

        if(aux.getMese()==1) {
            count=count+aux.getGiorno();
            stop=true;
        }
        else {
            count=count+aux.getGiorno();
            int togli=aux.getGiorno();
            aux.togliGiorno(togli);
        }
    }
    return count;
}


string data::stagione() const {
    string stag;
    if(getMese()>2 && getMese()<7) {
        if(getMese()==3 && getGiorno()>20)
            stag="Primavera";
        else if(getMese()==3 && getGiorno()<21)
            stag="Inverno";
        else if(getMese()==6 && getGiorno()<22)
            stag="Primavera";
        else if(getMese()==6 && getGiorno()>21)
            stag="Estate";
        else
            stag="Primavera";
    }
    else if(getMese()>6 && getMese()<10) {
        if(getMese()==9 && getGiorno()<23)
            stag="Estate";
        else if(getMese()==9 && getGiorno()>22)
            stag="Autunno";
        else
            stag="Estate";
    }
    else if(getMese()>9 && getMese()<=12) {
        if(getMese()==12 && getGiorno()<22)
            stag="Autunno";
        else if(getMese()==12 && getGiorno()>21)
            stag="Inverno";
        else
            stag="Autunno";
    }
    else {
        stag="Inverno";
    }
    return stag;

}

string data::giornoSettimana() const {
    int giornoSett=anno+(anno-1)/4-(anno-1)/100+(anno-1)/400+contaGiorniAnno();
    giornoSett=giornoSett%7;
    string g;

    if(giornoSett==0)
        g="Sabato ";
    else if(giornoSett==1)
        g="Domenica ";
    else if(giornoSett==2)
        g="Lunedi' ";
    else if(giornoSett==3)
        g="Martedi' ";
    else if(giornoSett==4)
        g="Mercoledi' ";
    else if(giornoSett==5)
        g="Giovedi' ";
    else if(giornoSett==6)
        g="Venerdi' ";

    return g;
}

string data::meseAnno() const {
    if (mese==1)
        return " Gennaio ";
    else if(mese==2)
        return " Febbraio ";
    else if(mese==3)
        return " Marzo ";
    else if(mese==4)
        return " Aprile ";
    else if(mese==5)
        return " Maggio ";
    else if(mese==6)
        return " Giugno ";
    else if(mese==7)
        return " Luglio ";
    else if(mese==8)
        return " Agosto ";
    else if(mese==9)
        return " Settembre ";
    else if(mese==10)
        return " Ottobre ";
    else if(mese==11)
        return " Novembre ";
    else
        return " Dicembre ";
}

string data::formatoData() const {

    //osi << giornoSettimana << giorno << meseAnno() << anno;
    string gg=patch::to_string(giorno);
    string aa=patch::to_string(anno);
    string aux=giornoSettimana() + gg + meseAnno() + aa;
    return aux;
}

bool data::operator<(const data& o) const {
    if(o.getAnno()<getAnno())
        return true;
    else if(o.getAnno()>getAnno())
        return false;
    else {
        if(o.getMese()<getMese())
            return true;
        else if(o.getMese()>getMese())
            return false;
        else {
            if(o.getGiorno()<getGiorno())
                return true;
            else if(o.getGiorno()>getGiorno())
                return true;
            else {
                if(o.getSec()<getSec())
                    return true;
                else
                    return false;
            }
        }
    }
}

int data::durata(const data& o) const {
    if(o.getAnno()==anno) {
        if (o < *this)
            return o.contaGiorniAnno()-contaGiorniAnno();
        else
            return contaGiorniAnno()-o.contaGiorniAnno();
    }
    else if(o.getAnno()<anno) {   // quando anno(o) < anno(this) quindi faccio this - o
        data aux=*this;
        int gg=0;
        int count=anno-o.getAnno();
        while(count!=0) {
            int gtolti=aux.contaGiorniAnno();
            aux.togliGiorno(gtolti);
            gg=gg+gtolti;
            count=count-1;
        } //esco che sono allo stesso anno
        return gg+(aux.contaGiorniAnno()-o.contaGiorniAnno());
    }
    else {  //quando anno(o) > anno(this) quindi faccio o - this
        data aux=o;
        int gg=0;
        int count=o.getAnno()-anno;
        while(count!=0) {
            int gtolti=aux.contaGiorniAnno();
            aux.togliGiorno(gtolti);
            gg=gg+gtolti;
            count=count-1;
        } //esco che sono allo stesso anno
        return gg+(aux.contaGiorniAnno()-contaGiorniAnno());
    }
}

void data::cambiaGiorno(int g) {
    if(g<1 || g>giorniMese())
        overflow_error();
    else
        giorno=g;
}

void data::cambiaMese(int m) {
    if(m<1 || m>12)
        overflow_error();
    else
        mese=m;
}

void data::cambiaAnno(int a) {
    if(a<0)
        overflow_error();
    else
        anno=a;
}

void data::clearMem() {
    cambiaGiorno(1);
    cambiaMese(1);
    cambiaAnno(2018);
    cambiaSec(0);
}
ostream& operator<<(ostream& os, const data& d) {
    return os << d.getGiorno() << "/" << d.getMese() << "/" << d.getAnno() << " " << d.getOre() << ":" << d.getMinuti() << ":" << d.getSecondi() << endl;
}
