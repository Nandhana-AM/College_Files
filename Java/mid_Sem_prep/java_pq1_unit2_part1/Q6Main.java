import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;
public class Q6Main{
    public static void main(String[] args){
        Bank bank=new Bank();
        Scanner sc=new Scanner(System.in);
        int ch;
        double basic,amount;
            
                System.out.println("Enter a basic amount to start the Savings account");
                basic=sc.nextDouble();
                Q6SavingsAccount sa=new Q6SavingsAccount(basic,5);
                bank.addAccount(sa);
                
                System.out.println("Enter a basic amount to start the Current account");
                basic=sc.nextDouble();
                Q6CurrentAccount ca=new Q6CurrentAccount(basic);
                bank.addAccount(ca);
        while(true){
            System.out.println("Enter\n1. Enter the Savings Account\n2. Enter the Current Account\n3. Show Accounts\n4. Exit");
            ch=sc.nextInt();
            switch (ch)
            {
                case 1:
                    System.out.println("Enter\n1. Deposit\n2. Withdraw\n3. Show balance\n4. Calculate interest\n5. Balance with interest: ");
                    ch=sc.nextInt();
                    switch(ch){
                        case 1:
                            System.out.println("Enter amount: ");
                            amount=sc.nextDouble();
                            sa.deposit(amount);
                            break;
                            
                        case 2:
                            System.out.println("Enter amount: ");
                            amount=sc.nextDouble();
                            sa.withdraw(amount);
                            break;
                            
                        case 3:
                            sa.show_balance();
                            break;
                            
                        case 4:
                            sa.calculate_interest();
                            break;
                            
                        case 5:
                            sa.bal_with_int();
                            break;
                        
                    }
                    break;
                    
                case 2:
                    System.out.println("Enter\n1. Deposit\n2. Withdraw\n3. Show balance: ");
                    ch=sc.nextInt();
                    switch(ch){
                        case 1:
                            System.out.println("Enter amount: ");
                            amount=sc.nextDouble();
                            ca.deposit(amount);
                            break;
                            
                        case 2:
                            System.out.println("Enter amount: ");
                            amount=sc.nextDouble();
                            ca.withdraw(amount);
                            break;
                            
                        case 3:
                            ca.show_balance();
                            break;
                        }
                
                case 3:
                    List<Q6Account> accounts=bank.getAccounts();
                    System.out.println(accounts);
                    break;
                    
                case 4:
                    sc.close();
                    System.exit(0);
            }
        }
    }
    
}