// A company has planned to host parties for the employees. To follow covid protocols they
// have taken some measures. Employees who are having even employee-id and age less than 30
// are going to attend the party in hall 1 and those who are having odd employee-id with age of
// more than 30 are going to attend the party in hall 2. The remaining are supposed to attend in
// hall 3. Take user inputs for the employee details. Generate a user defined exception with
// message ccc when the employee has even employee-id
// and age less than 30. If the employee is having odd employee-id of age more than 30 then
// raise another user defined exception with message “You are not allowed in hall 1 or hall 3”.
// Also, print “Welcome to the party” along with the allotted hall name. At the same time, you
// need to check the average age of the employees for each of the halls. It is possible while
// finding average age, some exception may raise. Considering that predefined exception also
// keep proper exception handler. Print the exception in catch block.

import java.util.*;

public class lab8q1 {
    public static void main(String args[]){
        Scanner sc=new Scanner(System.in);
        allocateHall ac=new allocateHall();
        System.out.println("Enter the number of employees: ");
        int emp_no=sc.nextInt();
        int emp_id,age;
        for (int i=0;i<emp_no;i++){
            try{
                System.out.println("Enter the employee id: ");
                emp_id=sc.nextInt();
                System.out.println("Enter the age: ");
                age=sc.nextInt();
                ac.hall_allocation(emp_id, age);
            }
            catch(hallException e){
                System.out.println(e.getMessage());
            }
            
        }
        try{
            ac.calc_age();
        }
        catch(Exception e){
            System.out.println("Encountered an error while calculating average age!");
        }
        
    }
}

class hallException extends Exception{
    hallException(String message){
        super(message);
    }
}

class allocateHall{
    ArrayList<Integer> hall1_age=new ArrayList<>();
    ArrayList<Integer> hall2_age=new ArrayList<>();
    ArrayList<Integer> hall3_age=new ArrayList<>();

    public void hall_allocation(int emp_id,int age) throws hallException{
        if (emp_id%2==0 && age<30){
            hall1_age.add(age);
            System.out.println("Welcome to the party!");
            System.out.println("You've been alloacted to Hall 1.");
            throw new hallException("You are not allowed in hall 2 or hall 3");
        }
        else if(emp_id%2!=0 && age>30){
            hall2_age.add(age);
            System.out.println("Welcome to the party!");
            System.out.println("You've been alloacted to Hall 2.");
            throw new hallException("You are not allowed in hall 1 or hall 3");
        }
        else{
            hall3_age.add(age);
            System.out.println("Welcome to the party!");
            System.out.println("You've been alloacted to Hall 3.");
        }

        
    }
    public void calc_age(){
        int sum=0;
        for (int i:hall1_age){
            sum+=i;
        }
        System.out.println("Average age in Hall 1 is: "+sum/hall1_age.size());
        sum=0;
        for (int i:hall2_age){
            sum+=i;
        }
        System.out.println("Average age in Hall 2 is: "+sum/hall2_age.size());
        sum=0;
        for (int i:hall3_age){
            sum+=i;
        }
        System.out.println("Average age in Hall 3 is: "+sum/hall3_age.size());
    }
}
