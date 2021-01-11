

/*Design and implement a class BankAccount that has the following properties:
 * - Default constructor, will increase account number by one each time you create an account. 
 * - AccountNumber (generated automatically ad unique to each account
 * - an array of maximum three holders (a holder is a Person) The holder at index 0 is the primary holder
 * - number of holders (minimum of 1)
 * - opening date
 * - last interest paid date
 * - interest rate (yearly)
 * - Balance
 * 
 * - deposit() will deposit a specific amount of money to the account
 * - withdraw() will remove specific amount of money if there are sufficient funds
 * - payInterest(Date d) interest in computed from last date interest is paid to date d. 
 * - toString() display all attributes in any way you want. 
 * 
 * 
 */
import java.util.*;
public class BankAccount {
	private Date openDate;
	private static int AccountNumber = 0;
	private Person [] holder = new Person [3];
	private int i = 0;
	private int numofholders = 0;
	private double balance = 0;
	private double interest = 0;
	private Date lastPayment;	
	static Scanner sc = new Scanner(System.in);
	public BankAccount(){
		++AccountNumber;
	}
	
	
	public double getBalance() {
		return balance;
	}
	public void setBalance(double balance) {
		this.balance = balance;
	}
	
	public double getInterest() {
		return interest;
	}
	public void setInterest(double interest) {
		this.interest = interest;
	}
	public Date getOpenDate() {
		return openDate;
	}

	public void setOpenDate(String s) {
		Date d = new Date(s);
		this.openDate = d;
	}

	public int getAccountNumber() {
		return AccountNumber;
	}

	public Date getLastPayment() {
		return lastPayment;
	}
	public void setLastPayment(Date lastPayment) {
		this.lastPayment = lastPayment;
	}
}
