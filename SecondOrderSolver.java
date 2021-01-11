
import java.util.Scanner;
public class SecondOrderSolver {
	public static void main(String [] args){
		double a, b, c, d, x1, x2, x3, ip;
		System.out.println("Please Enter number 1 : ");
		Scanner ia = new Scanner(System.in);
		a = ia.nextDouble();
		System.out.println("Please Enter number 2 : ");
		Scanner ib = new Scanner(System.in);
		b = ib.nextDouble();
		System.out.println("Please Enter number 3 : ");
		Scanner ic = new Scanner(System.in);
		c = ic.nextDouble();
		d = (b*b) - (4*a*c);
		if (d > 0)
		{
			x1 = -b/(2*a) + Math.sqrt(d)/(2*a);
			x2 = -b/(2*a) - Math.sqrt(d)/(2*a);
			System.out.println("x1 = " + x1);
			System.out.println("x2 = " + x2);
		}else if(d == 0)
		{
			x3 = -b/(2*a);
			System.out.println("There is one solution "+ x3);
		}else if(d < 0)
		{
			x3 = -b/(2*a);
			x1 = x3;
			x2 = x3;
			ip = Math.sqrt(-d)/(2*a);
			System.out.println("x1 = "+ x1+" + "+ ip+"*i");
			System.out.println("x2 = "+ x2+" - "+ ip+"*i");
		}
		
		
	}
}
