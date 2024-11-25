import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;
interface Q6Account{
    public void deposit(double amount);
    public void withdraw(double amount);
    public void show_balance();
}

class Q6SavingsAccount implements Q6Account {
    double amount,balance,int_rate;
    public Q6SavingsAccount(double amount,double int_rate){
        this.int_rate=int_rate;
        balance=amount;
    }
    public void deposit(double amount)
    {
        balance+=amount;
    }
    public void withdraw(double amount)
    {
        if (amount<=balance) balance-=amount;
        else System.out.println("Insufficient balance");
    }
    public void calculate_interest(){
        double interest=balance*(int_rate/100);
        System.out.println("The interest for "+balance+" is "+interest);
    }
    public void show_balance(){
        System.out.println("The balance is "+balance);
    }
    public double bal_with_int(){
        double interest=balance*(int_rate/100);
        return balance+interest;
    }
}

class Q6CurrentAccount implements Q6Account{
    double amount,balance;
    public Q6CurrentAccount(double amount){
        balance=amount;
    }
    public void deposit(double amount)
    {
        balance+=amount;
    }
    public void withdraw(double amount)
    {
         if (amount<=balance) balance-=amount;
        else System.out.println("Insufficient balance");   
    }
    public void show_balance(){
        System.out.println("The balance is "+balance);
    }    
}

class Bank{
    ArrayList<Q6Account> accounts;
    Bank(){
        accounts=new ArrayList<>();
    }
     public void addAccount(Q6Account account) {
        accounts.add(account);
    }
    public List<Q6Account> getAccounts() {
    return new ArrayList<>(accounts);
    }
}

