package projectP2;

import java.lang.String;

public class fusoorario extends data {
	String citta;
	
	public fusoorario() {
		super();
		citta="Londra";
	}

	public fusoorario(String c)  throws overflow_error {
        super();
        citta=c;
        if (checkCitta(c)==false) {
            throw new overflow_error();
        }
    }
 
    public fusoorario(String c, data da)  throws overflow_error {
        super(da.getGiorno(), da.getMese(), da.getAnno(), da.getOre(), da.getMinuti(), da.getSecondi());
        citta=c;
        if (checkCitta(c)==false) {
            throw new overflow_error();
        }
    }
 
    public String getCitta() {
        return citta;
    }
   
    public boolean checkCitta(String citta) {
        if (citta=="Londra")
            return true;
        else if (citta=="Casablanca")
            return true;
        else if (citta=="Roma")
            return true;
        else if (citta=="Parigi")
            return true;
        else if (citta=="Madrid")
            return true;
        else if (citta=="Helsinki")
            return true;
        else if (citta=="Citta del Capo")
            return true;
        else if (citta=="Mosca")
            return true;
        else if (citta=="Abu Dhabi")
            return true;
        else if (citta=="Bangkok")
            return true;
        else if (citta=="Pechino")
            return true;
        else if (citta=="Tokyo")
            return true;
        else if (citta=="Seul")
            return true;
        else if (citta=="Sydney")
            return true;
        else if (citta=="Wellington")
            return true;
        else if (citta=="Rio de Janeiro")
            return true;
        else if (citta=="Buenos Aires")
            return true;
        else if (citta=="Santiago")
            return true;
        else if (citta=="New York")
            return true;
        else if (citta=="Chicago")
            return true;
        else if (citta=="Citta del Messico")
            return true;
        else if (citta=="Denver")
            return true;
        else if (citta=="Los Angeles")
            return true;
        else
            return false;
    }

	public int Fuso() throws overflow_error {
	    if (citta=="Londra")
	        return 0;
	    else if (citta=="Casablanca")
	        return 0;
	    else if (citta=="Roma")
	        return 1;
	    else if (citta=="Parigi")
	        return 1;
	    else if (citta=="Madrid")
	        return 1;
	    else if (citta=="Helsinki")
	        return 2;
	    else if (citta=="Citta del Capo")
	        return 2;
	    else if (citta=="Mosca")
	        return 3;
	    else if (citta=="Abu Dhabi")
	        return 4;
	    else if (citta=="Bangkok")
	        return 7;
	    else if (citta=="Pechino")
	        return 8;
	    else if (citta=="Tokyo")
	        return 9;
	    else if (citta=="Seul")
	        return 9;
	    else if (citta=="Sydney")
	        return 10;
	    else if (citta=="Wellington")
	        return 12;
	    else if (citta=="Rio de Janeiro")
	        return -3;
	    else if (citta=="Buenos Aires")
	        return -3;
	    else if (citta=="Santiago")
	        return -4;
	    else if (citta=="New York")
	        return -5;
	    else if (citta=="Chicago")
	        return -6;
	    else if (citta=="Citta del Messico")
	        return -6;
	    else if (citta=="Denver")
	        return -7;
	    else if (citta=="Los Angeles")
	        return -8;
	    else
	    	throw new overflow_error();
	}

	public double Latitudine() throws overflow_error {
	    if (citta=="Londra")
	        return 51.5085300;
	    else if (citta=="Casablanca")
	        return 33.5883100;
	    else if (citta=="Roma")
	        return 41.8919300;
	    else if (citta=="Parigi")
	        return 48.8534100;
	    else if (citta=="Madrid")
	        return 40.4165000;
	    else if (citta=="Helsinki")
	        return 60.1695200;
	    else if (citta=="Citta del Capo")
	        return -33.9258400;
	    else if (citta=="Mosca")
	        return 55.7522200;
	    else if (citta=="Abu Dhabi")
	        return 24.4666700;
	    else if (citta=="Bangkok")
	        return 13.7539800;
	    else if (citta=="Pechino")
	        return 39.9075000;
	    else if (citta=="Tokyo")
	        return 35.6895000;
	    else if (citta=="Seul")
	        return 37.5660000;
	    else if (citta=="Sydney")
	        return -33.8678500;
	    else if (citta=="Wellington")
	        return -41.2866400;
	    else if (citta=="Rio de Janeiro")
	        return -22.9027800;
	    else if (citta=="Buenos Aires")
	        return -34.6131500;
	    else if (citta=="Santiago")
	        return -33.4569400;
	    else if (citta=="New York")
	        return 40.7142700;
	    else if (citta=="Chicago")
	        return 41.8500300;
	    else if (citta=="Citta del Messico")
	        return 19.4284700;
	    else if (citta=="Denver")
	        return 39.7391500;
	    else if (citta=="Los Angeles")
	        return 34.0522300;
	    else
	    	throw new overflow_error();
	}

	public double Longitudine() throws overflow_error {
	    if (citta=="Londra")
	        return -0.1257400;
	    else if (citta=="Casablanca")
	        return -7.6113800;
	    else if (citta=="Roma")
	        return 12.5113300;
	    else if (citta=="Parigi")
	        return 2.3488000;
	    else if (citta=="Madrid")
	        return -3.7025600;
	    else if (citta=="Helsinki")
	        return 24.9354500;
	    else if (citta=="Citta del Capo")
	        return 18.4232200;
	    else if (citta=="Mosca")
	        return 37.6155600;
	    else if (citta=="Abu Dhabi")
	        return 54.3666700;
	    else if (citta=="Bangkok")
	        return 100.5014400;
	    else if (citta=="Pechino")
	        return 116.3972300;
	    else if (citta=="Tokyo")
	        return 139.6917100;
	    else if (citta=="Seul")
	        return 126.9784000;
	    else if (citta=="Sydney")
	        return 151.2073200;
	    else if (citta=="Wellington")
	        return 174.7755700;
	    else if (citta=="Rio de Janeiro")
	        return -43.2075000;
	    else if (citta=="Buenos Aires")
	        return -58.3772300;
	    else if (citta=="Santiago")
	        return -70.6482700;
	    else if (citta=="New York")
	        return -74.0059700;
	    else if (citta=="Chicago")
	        return -87.6500500;
	    else if (citta=="Citta del Messico")
	        return -99.1276600;
	    else if (citta=="Denver")
	        return -104.9847000;
	    else if (citta=="Los Angeles")
	        return -118.2436800;
	   else
	        throw new overflow_error();
	}

	public int Emisfero()  throws overflow_error {
	    if (Latitudine() > 0)
	        return 0;
	    else
	        return 1;
	}

	//ritorno la differenza di fuso orari tra 2 citta
	public int confrontaFusi(String c) throws overflow_error {
	    fusoorario fo= new fusoorario(c);
	     //tutti e 2 i fusi da confrontare sono <0
	    if(fo.Fuso()<0 && Fuso()<0) {
	        if (fo.Fuso() > Fuso())
	            return fo.Fuso() - Fuso();
	        else
	            return Fuso() -fo.Fuso();
	    }
	    //solo uno dei due è <0
	    else if (fo.Fuso()<0 || Fuso()>0) {
	        if (fo.Fuso() > Fuso()) //this <0 && fo >0
	            return fo.Fuso() - Fuso();
	        else //fo <0 && this>0
	            return Fuso() -fo.Fuso();
	    }
	    //entrambi >=0
	    else {
	        if (fo.Fuso() > Fuso())
	            return fo.Fuso()-Fuso();
	        else
	            return Fuso() -fo.Fuso();
	    }
	}

	//ritorno l'orario aggiunto al fuso orario di una citta
	public data orarioCitta(String c) throws overflow_error {

	    data aux = new data(getGiorno(), getMese(), getAnno(), getOre(),
	             getMinuti(), getSecondi());

	    fusoorario f= new fusoorario(c, aux);

	    int f1=Fuso();
	    int f2=f.Fuso();

	    aux.aggiungiOre(f2-f1);

	    return aux;
	}

	public void cambiaCitta(String c) throws overflow_error {
	    //c sarà corretta perchè la scelta è a tendina
		if (checkCitta(c)==false) {
            throw new overflow_error();
        }
		else
			citta=c;
	}

	public fusoorario somma (orario d) throws overflow_error {
		data auxD=new data(this.getGiorno(), this.getMese(), this.getAnno(), this.getOre(), this.getMinuti(), this.getSecondi());
	    fusoorario aux=new fusoorario(this.getCitta(), auxD);
	    aux.aggiungiSecondi(d.getSecondi());
	    aux.aggiungiMinuti(d.getMinuti());
	    aux.aggiungiOre(d.getOre());

	    return aux;
	}

	public fusoorario sottrazione(orario d) throws overflow_error {
		data auxD=new data(this.getGiorno(), this.getMese(), this.getAnno(), this.getOre(), this.getMinuti(), this.getSecondi());
		fusoorario aux=new fusoorario(this.getCitta(), auxD);
	    aux.sottraiSecondi(d.getSecondi());
	    aux.sottraiMinuti(d.getMinuti());
	    aux.sottraiOre(d.getOre());

	    return aux;
	}

	public void clearMem() throws overflow_error {
	    //pongo Londra come riferimento, il 1/01/2018 0:0:0
	    cambiaGiorno(1);
	    cambiaMese(1);
	    cambiaAnno(2018);
	    cambiaSec(0);
	    cambiaCitta("Londra");
	}
	
	
	public void println(fusoorario f) throws overflow_error {
		String E;
		if (f.Emisfero()==0) {
			E= "Boreale, ";
		}
		else
		{
			E="Australe, "; 
		}
		System.out.print("Il fuso orario di " + f.getCitta() + ", nell'emisfero "+ E + "e' "+ f.Fuso());
	}

}
