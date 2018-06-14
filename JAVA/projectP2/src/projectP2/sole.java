package projectP2;

import java.lang.Math;

public class sole extends data {
	double lat;
	double lon;
	int tz;
	boolean oraLegale;
	double tempoEQ;
	double soleDeclina;
	
	public sole() {
		//vengono passati i valori di Padova al 1/01/2018 10:00
	    super();
	    lat=45.40643;
	    lon=11.87676;
	    tz=1;
	    
	    oraLegale=false;
	    tempoEQ=-3.459;
	    soleDeclina=-22.996;
	}
	
	public sole(double la, double lo, int t, data d, boolean o, double tEQ, double sD) throws overflow_error {
		//controllo errori
		super(d.getGiorno(), d.getMese(), d.getAnno(), d.getOre(), d.getMinuti(), d.getSecondi());
	    lat=la;
	    lon=lo; 
	    tz=t; 
	    oraLegale=o; 
	    tempoEQ=tEQ;
	    soleDeclina=sD;
	    
	    if(checkSole(la, lo, t)==false)
	    	throw new overflow_error();
	}

	public boolean checkSole(double la, double lo, int t) {
		if(la<-90 || la>90)
			return false;
		else if(lo<-180 || lo>180)
			return false;
		else if(t<-11 || t>14)
			return false;
		return true;
	}
	public double getLat() {
	    return lat;
	}
	public double getLon()  {
	    return lon;
	}
	public int getTz() {
	    return tz;
	}
	public data getTime() throws overflow_error {
		data aux=new data(this.getGiorno(), this.getMese(), this.getAnno(), this.getOre(), this.getMinuti(), this.getSecondi());
	    return aux;
	}
	public boolean getOraLegale() {
	    return oraLegale;
	}
	public double getTempoEQ() {
	    return tempoEQ;
	}
	public double getSoleDeclina() {
	    return soleDeclina;
	}

	//occhio ai parametri
	public double giornoGiuliano() throws overflow_error {
	    int year=getTime().getAnno();
	    int month=getTime().getMese();

	    if(getMese()<=2) {
	        year=year-1;
	        month=month+12;
	    }

	    int a=year/100;
	    int b=2-a+a/4;
	    //aggiunto cast per seguire la formula
	    int c=(int) (365.25*year);
	    int d=(int) (30.6001*(month+1));

	    double dataGiuliana=b+c+d+getGiorno()+1720994.50;

	    double offsetGiornata=getSec()/86400;
	    return dataGiuliana+offsetGiornata;

	}
	
	public double secoloGiuliano() throws overflow_error {
	    double GG=giornoGiuliano();
	    return (GG-2451545.0)/36525.0;
	}
	public double angoloSolare() {
	    double grado=3.14159265/180;    //grado=pi/180=0,01745
	    double as=Math.cos(90.833*grado)/(Math.cos(lat*grado)*Math.cos(soleDeclina*grado)) - Math.tan(lat*grado)*Math.tan(soleDeclina*grado);

	    return Math.acos(as);
	}

	public double soleUTC(int tsm) {
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

	public data Tramonto() throws overflow_error {
	    double tempoUTC=soleUTC(1);

	    double tempoLocale=tempoUTC+tz*60;    //in minuti
	    tempoLocale+=oraLegale?60:0;

	    data aux=getTime();

	    if(tempoLocale>=0 && tempoLocale<1440) {
	        int secondiLocale=(int) (tempoLocale*60);
	        aux.cambiaSec(secondiLocale);
	    }
	    else {
	        int incremento=(tempoLocale<0)?1:-1;
	        while(tempoLocale<0 || tempoLocale>=1440) {
	            tempoLocale=tempoLocale+incremento*1440;
	        }

	        int secondiLocale=(int) (tempoLocale*60);
	        aux.cambiaSec(secondiLocale);
	    }
	    return aux;
	}

	public data Sorgere() throws overflow_error {
	    double tempoUTC=soleUTC(2);

	    double tempoLocale=tempoUTC+tz*60.0;    //in minuti
	    tempoLocale+=oraLegale?60:0;

	    data aux=getTime();

	    if(tempoLocale>=0 && tempoLocale<1440) {
	        int secondiLocale=(int) (tempoLocale*60);
	        aux.cambiaSec(secondiLocale);
	    }
	    else {
	        int incremento=(tempoLocale<0)?1:-1;
	        while(tempoLocale<0 || tempoLocale>=1440) {
	            tempoLocale=tempoLocale+incremento*1440;
	        }

	        int secondiLocale=(int) (tempoLocale*60);
	        aux.cambiaSec(secondiLocale);
	    }
	    return aux;
	}

	public data mezzogiornoSolare() throws overflow_error {
	    double tempoUTC=soleUTC(3);

	    double tempoLocale=tempoUTC+tz*60.0;    //in minuti
	    tempoLocale+=oraLegale?60:0;

	    data aux=getTime();

	    if(tempoLocale>=0 && tempoLocale<1440) {
	        int secondiLocale=(int) (tempoLocale*60);
	        aux.cambiaSec(secondiLocale);
	    }
	    else {
	        int incremento=(tempoLocale<0)?1:-1;
	        while(tempoLocale<0 || tempoLocale>=1440) {
	            tempoLocale=tempoLocale+incremento*1440;
	        }

	        int secondiLocale=(int) (tempoLocale*60);
	        aux.cambiaSec(secondiLocale);
	    }
	    return aux;
	}

	public void cambiaLat(double l) throws overflow_error {
	    if(l<-90 || l>90)
	        throw new overflow_error();
	    else
	        lat=l;
	}

	public void cambiaLon(double l) throws overflow_error {
	    if(l<-180 || l>180)
	    	throw new overflow_error();
	    else
	        lon=l;
	}

	public void cambiaTz(int t) throws overflow_error {
	    if(t<-11 || t>14)
	    	throw new overflow_error();
	    else
	        tz=t;
	}

	public void cambiaTime(data d) throws overflow_error {
	    //passo con il costruttore quindi sarà già una data corretta
	    this.cambiaAnno(d.getAnno());
	    this.cambiaMese(d.getMese());
	    this.cambiaGiorno(d.getGiorno());
	    this.cambiaSec(d.getSec());
	}

	public void cambiaLegale(boolean l) {
		oraLegale=l;
	}

	public void cambiaTempoEQ(double e) {
	    //massimi e minimi non disponibili
	    //l'utente come specificato deve calcolarseli
	    tempoEQ=e;
	}

	public void cambiaSoleDeclina(double s) {
	    soleDeclina=s;
	}


	public void clearMem() throws overflow_error {
	    //vengono passati i valori di Padova al 1/01/2018 10:00
	    data d=new data(1, 1, 2018, 10, 0, 0);
	    cambiaLat(45.40643);
	    cambiaLon(11.87676);
	    cambiaTz(1);
	    cambiaTime(d);
	    cambiaLegale(false);
	    cambiaTempoEQ(-3.459);
	    cambiaSoleDeclina(-22.996);
	}

	public void println(sole s) throws overflow_error {
	    //tolgo ore/minuti/secondi
		data tram=s.Tramonto();
		data sorg=s.Sorgere();
		data mezzsol=s.mezzogiornoSolare();
		System.out.println();
		System.out.println("Sorgere: ");
		sorg.println();
		
		System.out.println("Mezzogiorno Solare: ");
		mezzsol.println();
		
		System.out.println("Tramonto: ");
		tram.println();
	}

	
}
