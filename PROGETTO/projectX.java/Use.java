package projectX;
import java.lang.String;

public class Use {
	public static void main(String args[]) {
		orario o=new orario();
		data d=new data();
		fusoorario f=new fusoorario();
		sole s=new sole();
		
		try {
			//ORARIO
			System.out.println("Metodi di Orario: "  + System.getProperty("line.separator"));
			
			System.out.println("Aggiungi Dati: ");
			o.aggiungiSecondi(5);
			o.aggiungiMinuti(5);
			o.aggiungiOre(15);
			o.println();
			System.out.println(System.getProperty("line.separator"));
			
			System.out.println("Sottrai Dati: ");
			o.sottraiSecondi(5);
			o.sottraiMinuti(5);
			o.sottraiOre(5);
			o.println();
			System.out.println(System.getProperty("line.separator"));
			
			System.out.println("Somma: ");
			orario o1=new orario(12, 30, 0);
			orario o2=o.somma(o1);
			o2.println();
			System.out.println(System.getProperty("line.separator"));
			
			System.out.println("Sottrazione: ");
			orario o4=o.sottrazione(o1); //sottraggo all'orario o(10:00:00) 
			o4.println();
			System.out.println(System.getProperty("line.separator"));
			
			System.out.println("Velocita' Media: ");
			double media=o.distanzaVel(1250);
			System.out.println(media + "km/h");
			System.out.println(System.getProperty("line.separator"));
			
			System.out.println("Divisione: ");
			orario o5=o.divisione(4);
			o5.println();
			System.out.println(System.getProperty("line.separator"));
			
			System.out.println("Clear: ");
			o.clearMem();
			o.println();
			System.out.println(System.getProperty("line.separator"));
			
			//DATA
			System.out.println("Metodi di Data: "  + System.getProperty("line.separator"));
			
			System.out.println("Aggiungi Dati: ");
			d.aggiungiAnno(1);
			d.aggiungiMese(10);
			d.aggiungiGiorno(20);
			d.cambiaSec(36000);
			d.println();
			System.out.println(System.getProperty("line.separator"));
			
			System.out.println("Sottrai Dati: ");
			d.togliAnno(1);
			d.togliMese(9);
			d.togliGiorno(20);
			d.cambiaSec(72000);
			d.println();
			System.out.println(System.getProperty("line.separator"));
			
			System.out.println("Somma: ");
			o.cambiaSec(36000); //sono le 10:00:00
			data d1=d.somma(o);
			d1.println();
			System.out.println(System.getProperty("line.separator"));
			
			System.out.println("Sottrazione: ");
			data d2=d.sottrazione(o);
			d2.println();
			System.out.println(System.getProperty("line.separator"));
			
			System.out.println("Settimane Anno: ");
			int settConta=d.contaSettAnno();
			System.out.println(settConta);
			System.out.println(System.getProperty("line.separator"));

			System.out.println("Giorni Anno: ");
			int ggConta=d.contaGiorniAnno();
			System.out.println(ggConta);
			System.out.println(System.getProperty("line.separator"));
			
			System.out.println("Stagione: ");
			String stag=d.stagione();
			System.out.println(stag);
			System.out.println(System.getProperty("line.separator"));
			
			System.out.println("Formato Data: ");
			String formData=d.formatoData();
			System.out.println(formData);
			System.out.println(System.getProperty("line.separator"));
		
			System.out.println("Durata in Giorni: ");
			data d3=new data(10, 01, 2018, 5,0,0);
			int ggDurata=d.durata(d3);
			System.out.println(ggDurata);
			System.out.println(System.getProperty("line.separator"));
			
			System.out.println("Clear: ");
			d.clearMem();
			d.println();
			System.out.println(System.getProperty("line.separator"));
			
			//FUSOORARIO
			System.out.println("Metodi di Fusoorario: "  + System.getProperty("line.separator"));

			System.out.println("Confronta Fusi: ");
			fusoorario f1=new fusoorario("Parigi");
			int conFuso=f1.confrontaFusi("Pechino");
			System.out.println(conFuso);
			System.out.println(System.getProperty("line.separator"));
			
			System.out.println("Orario in un'altra citta': ");
			fusoorario f2=new fusoorario("Roma", d3);
			data d4=f2.orarioCitta("Denver");
			d4.println();
			System.out.println(System.getProperty("line.separator"));
			
			System.out.println("Somma: ");
			fusoorario f3=f.somma(o1); //sommo 12:30:00
			f3.println();
			System.out.println(System.getProperty("line.separator"));
			
			System.out.println("Sottrazione: ");
			fusoorario f4=f.sottrazione(o1); //sommo 12:30:00
			f4.println();
			System.out.println(System.getProperty("line.separator"));
		
			System.out.println("Clear: ");
			f.clearMem();
			f.println(f);
			
			//SOLE
			System.out.println("Metodi di Sole: ");
			s.println(s);
			System.out.println(System.getProperty("line.separator"));
		}
		catch (overflow_error errore) {
			System.out.println(errore.getReason());
		}
	}
}
