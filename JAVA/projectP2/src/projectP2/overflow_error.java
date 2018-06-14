package projectP2;

public class overflow_error extends Exception {
	
	static final long serialVersionUID=1L;
	
	public overflow_error() {
		
	}
	
	public String getReason() { return "Il dato immesso non e' valido"; }
}
