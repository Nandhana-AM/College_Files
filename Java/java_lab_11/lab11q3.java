class BankAccount {
    private double balance;

    // Constructor to initialize balance
    public BankAccount(double initialBalance) {
        this.balance = initialBalance;
    }

    // Method to deposit money into the account
    public synchronized void deposit(double amount) {
        balance += amount;
        System.out.println("Deposited: " + amount + ", Current Balance: " + balance);
        // Notify any waiting thread that the balance has been updated
        notify();
    }

    // Method to withdraw money from the account
    public synchronized void withdraw(double amount) {
        while (balance < amount) {
            try {
                System.out.println("Insufficient balance for withdrawal of " + amount + ". Waiting for deposit...");
                wait(); // Wait until there is enough balance
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
        }
        balance -= amount;
        System.out.println("Withdrawn: " + amount + ", Current Balance: " + balance);
    }

    // Method to check the current balance (not synchronized)
    public double getBalance() {
        return balance;
    }
}

class DepositThread extends Thread {
    private BankAccount account;
    private double amount;

    public DepositThread(BankAccount account, double amount) {
        this.account = account;
        this.amount = amount;
    }

    @Override
    public void run() {
        account.deposit(amount);
    }
}

class WithdrawThread extends Thread {
    private BankAccount account;
    private double amount;

    public WithdrawThread(BankAccount account, double amount) {
        this.account = account;
        this.amount = amount;
    }

    @Override
    public void run() {
        account.withdraw(amount);
    }
}

public class lab11q3 {
    public static void main(String[] args) {
        // Create a bank account with an initial balance of 100
        BankAccount account = new BankAccount(100.00);

        // Create threads for deposit and withdrawal
        DepositThread depositThread1 = new DepositThread(account, 200.00);
        WithdrawThread withdrawThread1 = new WithdrawThread(account, 150.00);
        WithdrawThread withdrawThread2 = new WithdrawThread(account, 100.00);

        // Start the threads
        withdrawThread1.start();
        withdrawThread2.start();
        depositThread1.start();
    }
}
