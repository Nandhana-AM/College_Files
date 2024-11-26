// PROJECT BY
// A M NANDHANA - 23011101001
// VARSHA C - 23011101033

import java.awt.*;
import java.awt.event.*;
import javax.swing.*;
import java.util.ArrayList;

public class BankAppGUI {
    private static ArrayList<BankAccount> accounts = new ArrayList<>();

    public static void main(String[] args) {
        JFrame frame = new JFrame("Bank Application");
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.setSize(400, 300);
        frame.setLayout(new FlowLayout());

        JButton createSavingsButton = new JButton("Create Savings Account");
        JButton createCheckingButton = new JButton("Create Checking Account");
        JButton transactionButton = new JButton("Deposit/Withdraw");
        JButton exitButton = new JButton("Exit");

        createSavingsButton.addActionListener(e -> createSavingsAccount());
        createCheckingButton.addActionListener(e -> createCheckingAccount());
        transactionButton.addActionListener(e -> performTransaction());
        exitButton.addActionListener(e -> System.exit(0));

        frame.add(createSavingsButton);
        frame.add(createCheckingButton);
        frame.add(transactionButton);
        frame.add(exitButton);

        frame.setVisible(true);
    }

    private static void createSavingsAccount() {
        String accNoStr = JOptionPane.showInputDialog("Enter account number:");
        if (accNoStr == null) {
            JOptionPane.showMessageDialog(null, "Account creation canceled.");
            return;
        }
        
        String initialAmountStr = JOptionPane.showInputDialog("Enter initial deposit amount:");
        if (initialAmountStr == null) {
            JOptionPane.showMessageDialog(null, "Account creation canceled.");
            return;
        }
        
        String interestRateStr = JOptionPane.showInputDialog("Enter interest rate:");
        if (interestRateStr == null) {
            JOptionPane.showMessageDialog(null, "Account creation canceled.");
            return;
        }
        
        String username = JOptionPane.showInputDialog("Set username:");
        if (username == null) {
            JOptionPane.showMessageDialog(null, "Account creation canceled.");
            return;
        }
        
        String password = JOptionPane.showInputDialog("Set password:");
        if (password == null) {
            JOptionPane.showMessageDialog(null, "Account creation canceled.");
            return;
        }

        int accNo = Integer.parseInt(accNoStr);
        int initialAmount = Integer.parseInt(initialAmountStr);
        double interestRate = Double.parseDouble(interestRateStr);

        if (isUsernameTaken(username)) {
            JOptionPane.showMessageDialog(null, "Username already taken. Choose a different username.");
        } else {
            SavingsAccount savingsAccount = new SavingsAccount(accNo, initialAmount, interestRate, username, password);
            accounts.add(savingsAccount);
            JOptionPane.showMessageDialog(null, "Savings account created successfully.");
            savingsAccount.applyInterest();
        }
    }

    private static void createCheckingAccount() {
        String accNoStr = JOptionPane.showInputDialog("Enter account number:");
        if (accNoStr == null) {
            JOptionPane.showMessageDialog(null, "Account creation canceled.");
            return;
        }

        String initialAmountStr = JOptionPane.showInputDialog("Enter initial deposit amount:");
        if (initialAmountStr == null) {
            JOptionPane.showMessageDialog(null, "Account creation canceled.");
            return;
        }

        String overdraftLimitStr = JOptionPane.showInputDialog("Enter overdraft limit:");
        if (overdraftLimitStr == null) {
            JOptionPane.showMessageDialog(null, "Account creation canceled.");
            return;
        }

        String username = JOptionPane.showInputDialog("Set username:");
        if (username == null) {
            JOptionPane.showMessageDialog(null, "Account creation canceled.");
            return;
        }

        String password = JOptionPane.showInputDialog("Set password:");
        if (password == null) {
            JOptionPane.showMessageDialog(null, "Account creation canceled.");
            return;
        }

        int accNo = Integer.parseInt(accNoStr);
        int initialAmount = Integer.parseInt(initialAmountStr);
        int overdraftLimit = Integer.parseInt(overdraftLimitStr);

        if (isUsernameTaken(username)) {
            JOptionPane.showMessageDialog(null, "Username already taken. Choose a different username.");
        } else {
            CheckingAccount checkingAccount = new CheckingAccount(accNo, initialAmount, overdraftLimit, username, password);
            accounts.add(checkingAccount);
            JOptionPane.showMessageDialog(null, "Checking account created successfully.");
        }
    }

    private static void performTransaction() {
        String username = JOptionPane.showInputDialog("Enter username:");
        String password = JOptionPane.showInputDialog("Enter password:");

        BankAccount account = authenticateUser(username, password);
        if (account == null) {
            JOptionPane.showMessageDialog(null, "Incorrect username or password.", "Error", JOptionPane.ERROR_MESSAGE);
        } else {
            int action = Integer.parseInt(JOptionPane.showInputDialog("Enter\n1-To deposit\n2-To withdraw:"));
            if (action == 1) {
                int depositAmount = Integer.parseInt(JOptionPane.showInputDialog("Enter amount to deposit:"));
                account.deposit(depositAmount);
                JOptionPane.showMessageDialog(null, "Deposit successful.");
            } else if (action == 2) {
                int withdrawAmount = Integer.parseInt(JOptionPane.showInputDialog("Enter amount to withdraw:"));
                account.withdraw(withdrawAmount);
            }
        }
    }

    private static boolean isUsernameTaken(String username) {
        for (BankAccount account : accounts) {
            if (account.getUsername().equals(username)) {
                return true;
            }
        }
        return false;
    }

    private static BankAccount authenticateUser(String username, String password) {
        for (BankAccount account : accounts) {
            if (account.authenticate(username, password)) {
                return account;
            }
        }
        return null;
    }
}

abstract class BankAccount {
    protected int accountNumber;
    protected int balance;
    protected String username;
    protected String password;

    public BankAccount(int accountNumber, int initialBalance, String username, String password) {
        this.accountNumber = accountNumber;
        this.balance = initialBalance;
        this.username = username;
        this.password = password;
    }

    public String getUsername() {
        return username;
    }

    public boolean authenticate(String username, String password) {
        return this.username.equals(username) && this.password.equals(password);
    }

    public void deposit(int amount) {
        balance += amount;
    }

    public abstract void withdraw(int amount);  // To be implemented in subclasses
}

class SavingsAccount extends BankAccount {
    private double interestRate;

    public SavingsAccount(int accountNumber, int initialBalance, double interestRate, String username, String password) {
        super(accountNumber, initialBalance, username, password);
        this.interestRate = interestRate;
    }

    public void applyInterest() {
        balance += (balance * interestRate / 100);
    }

    @Override
    public void withdraw(int amount) {
        if (amount <= balance) {
            balance -= amount;
        } else {
            JOptionPane.showMessageDialog(null, "Insufficient funds.");
        }
    }
}

class CheckingAccount extends BankAccount {
    private int overdraftLimit;

    public CheckingAccount(int accountNumber, int initialBalance, int overdraftLimit, String username, String password) {
        super(accountNumber, initialBalance, username, password);
        this.overdraftLimit = overdraftLimit;
    }

    @Override
    public void withdraw(int amount) {
        if (balance + overdraftLimit >= amount) {
            balance -= amount;
        } else {
            JOptionPane.showMessageDialog(null, "Overdraft limit exceeded.");
        }
    }
}
