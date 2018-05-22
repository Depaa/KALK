package projectX;

public class data extends orario {
	int giorno;
	int mese;
	int anno;

	public data() {
		super();
		giorno=1;
		mese=1;
		anno=2018;
	}
	
	//costruttore GIORNO-MESE-ANNO-ORE-MINUTI-SECONDI
	public data(int g, int m, int a) throws overflow_error {
		super();
	    giorno=g; 
	    mese=m;
	    anno=a;
		     
		if(g<1 || g>giorniMese() || m<1 || m>12 || a<1 || a>3500) {
	         throw new overflow_error();
	    }
	}
	
	public data(int g, int me, int a, int o, int mi, int s) throws overflow_error {
		super(o, mi, s);
	    giorno=g; 
	    mese=me;
	    anno=a;
	    if(g<1 || g>giorniMese() || me<1 || me>12 || a<1 || a>3500) {
	    	throw new overflow_error();
	    }
	 }

	public int getGiorno() {
	    return giorno;
	}

	public int getMese() {
	    return mese;
	}

	public int getAnno() {
	    return anno;
	}

	public boolean isBisestile() {
	    boolean bisestile=false;
	    if(anno%4==0) {
	        bisestile=true;
	        if(anno%100==0)
	            bisestile=false;
	        if(anno%400==0)
	            bisestile=true;
	    }
	    return bisestile;
	}

	public int giorniMese() {
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

	public data somma(orario d) throws overflow_error {
		
		data aux=new data(getGiorno(), getMese(), getAnno(), getOre(), getMinuti(), getSecondi());
	    aux.aggiungiSecondi(d.getSecondi());
	    aux.aggiungiMinuti(d.getMinuti());
	    aux.aggiungiOre(d.getOre());
	    return aux;
	}

	public data sottrazione(orario d) throws overflow_error {
	    data aux=new data(getGiorno(), getMese(), getAnno(), getOre(), getMinuti(), getSecondi());
	    aux.sottraiSecondi(d.getSecondi());
	    aux.sottraiMinuti(d.getMinuti());
	    aux.sottraiOre(d.getOre());

	    return aux;
	}

	public void aggiungiSecondi(int s) {
	    if(s<0)
	        sottraiSecondi(-s);
	    else {
	        //trovo quanti minuti devo aggiungere
	        int m=(s+getSecondi())/60;
	        if(m>0)
	            aggiungiMinuti(m);

	        //trovo quanti secondi rimangono
	        s=(s+getSecondi())%60;
	        int aux=getOre()*3600+getMinuti()*60+s;
	        cambiaSec(aux);
	    }
	}

	public void aggiungiMinuti(int m) {
	    if(m<0)
	        sottraiMinuti(-m);
	    else {
	        //trovo quante ore devo aggiungere
	        int o=(m+getMinuti())/60;
	        if(o>0)
	            aggiungiOre(o);

	        //trovo quanti minuti rimangono
	        m=(m+getMinuti())%60;
	        int aux=getOre()*3600+m*60+getSecondi();
	        cambiaSec(aux);
	    }
	}

	public void aggiungiOre(int o) {
	    if(o<0)
	        sottraiOre(-o);
	    else {
	        //trovo quanti giorni devo aggiungere
	        int g=(o+getOre())/24;
	        if(g>0)
	            aggiungiGiorno(g);

	        //trovo le ore rimanenti
	        o=(o+getOre())%24;
	        int aux=o*3600+getMinuti()*60+getSecondi();
	        cambiaSec(aux);
	    }
	}

	public void sottraiSecondi(int s) {
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
	        if(m>0)
	            sottraiMinuti(m);

	        int aux=getOre()*3600+getMinuti()*60+((60+getSecondi()-s)%60);
	        cambiaSec(aux);
	    }
	}

	public void sottraiMinuti(int m) {
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
	        if(o>0)
	            sottraiOre(o);

	        int aux=getOre()*3600+((60+getMinuti()-m)%60)*60+getSecondi();
	        cambiaSec(aux);
	    }
	}

	public void sottraiOre(int o) {
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
	        if(g>0)
	            togliGiorno(g);

	        //int aux=86400-o*3600+getMinuti()*60+getSecondi();
	        int aux=(86400+getSec()-o*3600)%86400;
	        cambiaSec(aux);
	    }
	}

	public void aggiungiGiorno(int g) {
	    if(g<0)
	        togliGiorno(-g);
	    else {
	        while(g>0) {
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

	public void aggiungiMese(int m) {
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

	public void aggiungiAnno(int a) throws overflow_error {
	    if(a<0)
	        togliAnno(-a);
	    else
	        anno=anno+a;

	}

	public void togliGiorno(int g) {
	    if(g<0)
	        aggiungiGiorno(-g);
	    else {
	        while(g>0) {
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

	public void togliMese(int m) {
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

	public void togliAnno(int a) throws overflow_error {
	    if(a<0)
	        aggiungiAnno(-a);
	    else
	        anno=anno-a;

	    if(anno<0) {
	        //anno=0;
	        throw new overflow_error();
	    }
	}


	public int contaSettAnno() throws overflow_error {
	    int count=1;
	    data aux=new data(getGiorno(), getMese(), getAnno(), getOre(), getMinuti(), getSecondi());
	    boolean stop=false;
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

	public int contaGiorniAnno() throws overflow_error {
	    int count=0;
	    data aux=new data(getGiorno(), getMese(), getAnno(), getOre(), getMinuti(), getSecondi());
	    boolean stop=false;
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


	public String stagione() {
	    String stag;
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

	public String giornoSettimana() throws overflow_error {
	    int giornoSett=anno+(anno-1)/4-(anno-1)/100+(anno-1)/400+contaGiorniAnno();
	    giornoSett=giornoSett%7;
	    String g="";

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

	public String meseAnno() {
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

	public String formatoData() throws overflow_error {
	    String gg=Integer.toString(giorno);
	    String aa=Integer.toString(anno);
	    String aux=giornoSettimana() + gg + meseAnno() + aa;
	    return aux;
	}

	public boolean maggiore(data o) {
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
	                return false;
	            else {
	                if(o.getSec()<getSec())
	                    return true;
	                else
	                    return false;
	            }
	        }
	    }
	}

	public int durata(data o) throws overflow_error {
	    if(o.getAnno()==getAnno()) {
	        if (maggiore(o)==false)
	            return o.contaGiorniAnno()-contaGiorniAnno();
	        else
	            return contaGiorniAnno()-o.contaGiorniAnno();
	    }
	    else if(o.getAnno()<anno) {   // quando anno(o) < anno(this) quindi faccio this - o
	        data aux=new data(getGiorno(), getMese(), getAnno(), getOre(), getMinuti(), getSecondi());
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
	        data aux=new data(o.getGiorno(), o.getMese(), o.getAnno(), o.getOre(), o.getMinuti(), o.getSecondi());
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

	public void cambiaGiorno(int g) throws overflow_error {
	    if(g<1 || g>giorniMese())
	    	throw new overflow_error();
	    else
	        giorno=g;
	}

	public void cambiaMese(int m) throws overflow_error {
	    if(m<1 || m>12)
	    	throw new overflow_error();
	    else
	        mese=m;
	}

	public void cambiaAnno(int a) throws overflow_error {
	    if(a<0)
	        throw new overflow_error();
	    else
	        anno=a;
	}

	public void clearMem() throws overflow_error {
	    cambiaGiorno(1);
	    cambiaMese(1);
	    cambiaAnno(2018);
	    cambiaSec(0);
	}
	
	public void println() {
	    System.out.println(this.getGiorno() + "/" + this.getMese() + "/" + this.getAnno() + " " + this.getOre() + ":" + this.getMinuti() + ":" + this.getSecondi());
	}
	
}
