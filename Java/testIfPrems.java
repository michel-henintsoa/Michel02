import java.math.*;
public class Main {
	public static void main(String[] args) {
		int n=9;
		int m=testIfPrem(n);
		if(m==1) 
			System.out.println("le nombre n'est pas premier");
		if(m==0) 
			System.out.println(" le nombre est  premier");
	}
	static int testIfPrem(int n){
		int tmp=(int)Math.sqrt(n)+1;
		for(int i=2; i<tmp; i++){
			if(n%i==0) return 1;
		}
		return 0;
		
	}
}