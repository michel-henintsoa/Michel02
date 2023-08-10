import java.util.Scanner ;
public class secDeg{
	public static void main(String[] args){
		double carr = puiss(2, 2);
		System.out.println(carr);
		Scanner scan = new Scanner(System.in);
		int []coef = takeVal(scan);
		int a = coef[0];
		int b = coef[1];
		int c = coef[2];
		double delta = calcDelta(a, b, c);
		if(delta < 0){
			System.out.println("la solution ne se trouve pas dans R");
		}
		else{
			double []root = calcRoot(a, b, c, delta);
			double r1 = root[0];
			double r2 = root[1];
/*			Coefficient coef = takeVal(scan);
			int a = coef.a;
			int b = coef.b;
			int c = coef.c;*/
			System.out.println(":"+a+","+b+","+c+"\n "+delta+";"+r1+";"+r2);
		}
	}
	static double puiss(double iva, double avo){
		if (avo == 0){
			return 1;
		}
		for (int i=1; i<avo; i++){
			iva *= iva;
		}
		return iva;
	}
	static int []takeVal(Scanner scan){
		int a=0, b=0, c=0;
		System.out.print("entrez les valeurs \na:\t");
		a = scan.nextInt();
		System.out.print("b:\t");
		b = scan.nextInt();
		System.out.print("c:\t");
		c = scan.nextInt();
		scan.close();
		int []tmp = {a, b, c};
		return tmp;
	}
	static double calcDelta(int a, int b, int c){
		double delta = puiss(b, 2) - 4*(a*c);
		return delta;
	}
	static double []calcRoot(int a, int b, int c, double delta){
		double r1 = ((-b)-Math.sqrt(delta))/(2*a);
		double r2 = ((-b)+Math.sqrt(delta))/(2*a);
		if(r1>r2){
			double tmp;
			tmp = r1;
			r1=r2;
			r2=tmp;
		}
		double []results = {r1, r2};
		return results;
	}
	/*class Coefficient{
		int a;
		int b;
		int c;
	}
	public static Coefficient takeVal(Scanner scan){
		Coefficient coef = new Coefficient();
		System.out.print("entrez les valeurs \na:\t");
		coef.a = scan.nextInt();
		System.out.print("b:\t");
		coef.b = scan.nextInt();
		System.out.print("c:\t");
		coef.c = scan.nextInt();
		scan.close();
		return coef;
	}*/
}
