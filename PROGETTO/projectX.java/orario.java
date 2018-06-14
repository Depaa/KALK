package projectX;

public class orario {
	int sec;
	
	public orario() {
		sec=0;
	}
	
	//costruttore
	public orario(int o, int m, int s) throws overflow_error {
	    if(o<0 || o>23 || m<0 || m>59 || s<0 || s>59)
	        throw new overflow_error();
	    else
	        sec=(o*3600)+(m*60)+s;
	};

	//costruttore di copia deep?

	public int getOre() {
	    return sec/3600;
	}

	public int getMinuti() {
	    return (sec/60)%60;
	}

	public int getSecondi() {
	    return sec%60;
	}

	public int getSec() {
	    return sec;
	}

	public void cambiaSec(int s) {
	    sec=s;
	}

	public orario somma(orario o) throws overflow_error {
	    int secT=0, minT=0, oreT=0;

	    secT=o.getSecondi()+sec;
	    minT=o.getMinuti()+secT/60;
	    secT=secT%60;
	    oreT=o.getOre()+minT/60;
	    minT=minT%60;
	    oreT=oreT%24;

	    orario aux=new orario(oreT, minT, secT);
	    return aux;
	}

	public orario sottrazione(orario o) throws overflow_error {
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

	    orario aux=new orario(oreT, minT, secT);
	    return aux;
	}

	public void aggiungiSecondi(int s) {
	    if(s<0)
	        sottraiSecondi(-s);
	    else if(s>0 && s+sec>86400)
	        sec=sec+s-86400*((s+sec)/86400);
	    else if(s>=0)
	        sec=sec+s;
	}

	public void aggiungiMinuti(int m) {
	    if(m<0)
	        sottraiMinuti(-m);
	    else if(m>0 && m*60+sec>86400)
	        sec=sec+(m*60)-86400*((sec+m*60)/86400);
	    else if(m>0)
	        sec=sec+m*60;
	}

	public void aggiungiOre(int o) {
	    if(o<0)
	        sottraiOre(-o);
	    else if(o>0 && o*3600+sec>86400)
	        sec=sec+(o*3600)-86400*((sec+o*3600)/86400);
	    else if(o>0)
	        sec=sec+o*3600;
	}

	public void sottraiSecondi(int s) {
	    if(s<0)
	        aggiungiSecondi(-s);
	    else if(s>0 && sec<s) //giorni precedenti
	        sec=86400-((86400*(s/86400))-(sec-s))%86400;
	    else if(s>=0)
	        sec=sec-s;
	}

	public void sottraiMinuti(int m) {
	    if(m<0)
	        aggiungiMinuti(-m);
	    else if(m>0 && sec<m*60)
	        sec=86400-((86400*((m*60)/86400))-(sec-m*60))%86400;
	    else if(m>0)
	        sec=sec-m*60;
	}

	public void sottraiOre(int o) {
	    if(o<0)
	        aggiungiOre(-o);
	    else if(o>0 && sec<o*3600)
	        sec=86400-((86400*((o*3600)/86400))-(sec-o*3600))%86400;
	    else if(o>0)
	        sec=sec-o*3600;
	}

	//ritorna la velocita' media fatta in un intervallo o per fare km kilometri
	public double distanzaVel(double km) throws overflow_error {
		if(km<=0)
			throw new overflow_error();
		else
			return (km/sec)*3600;
	}


	public orario quantoMancaMezzogiorno() {
	    orario aux=new orario();
	    if(sec > 43200)  //se orario>12:00:00
	        aux.sec=86400-sec+43200;
	    else
	        aux.sec=43200-sec;
	    return aux;
	}

	public orario divisione(int d) throws overflow_error {
	    //divido sec in d parti
	    orario aux=new orario();
	    if(sec<d)
	        throw new overflow_error();
	    else
	        aux.sec=sec/d;
	    return aux;
	}

	public orario formato12h() {
	    orario aux=new orario();
	    if(sec>=43200)
	        aux.sec=sec-43200;
	    else
	        aux.sec=sec;
	    return aux;
	}

	public void clearMem() throws overflow_error {
	    cambiaSec(0);
	}

	//overloading con public void println()
	public void println() {
		System.out.print(this.getOre() + ":" + this.getMinuti() + ":" + this.getSecondi());
	}

}
