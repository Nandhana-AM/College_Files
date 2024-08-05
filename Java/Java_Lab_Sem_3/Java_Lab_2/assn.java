import java.util.Scanner;

public class assn
{

    public static void main(String[] args)
    {
        Scanner sc=new Scanner(System.in);
        time t=new time();
        distance d=new distance();
        currency m=new currency();

        while(true)
        {
            System.out.println("\nEnter \n1. Currency\n2. Distance\n3. Time\n4. Exit: ");
            int ch=sc.nextInt();
            double value;
            int ch2;
            switch(ch)
            {
                case 1:

                System.out.println("\nEnter \n1. Dollar to Rupees\n2. Euro to Rupees\n3. Yen to Rupees\n4. Rupees to Dollar\n5. Rupees to Euro\n6. Rupees to Yen: ");
                ch2=sc.nextInt();
                switch(ch2)
                {
                    case 1:
                    
                    System.out.println("Enter the amount: ");
                    value=sc.nextDouble();
                    System.out.println(value + "Dollars =" + m.usd_to_inr(value)+"Rupees");
                    break;

                    case 2:
                    System.out.println("Enter the amount: ");
                    value=sc.nextDouble();
                    System.out.println(value + "Euros =" + m.euro_to_inr(value)+"Rupees");
                    break;

                    case 3:
                    System.out.println("Enter the amount: ");
                    value=sc.nextDouble();
                    System.out.println(value + "Yen =" + m.yen_to_inr(value)+"Rupees");
                    break;

                    case 4:
                    System.out.println("Enter the amount: ");
                    value=sc.nextDouble();
                    System.out.println(value + "Rupees =" + m.inr_to_usd(value)+"Dollars");
                    break;

                    case 5:
                    System.out.println("Enter the amount: ");
                    value=sc.nextDouble();
                    System.out.println(value + "Rupees =" + m.inr_to_euro(value)+"Euros");
                    break;

                    case 6:
                    System.out.println("Enter the amount: ");
                    value=sc.nextDouble();
                    System.out.println(value + "Rupees =" + m.inr_to_yen(value)+"Yen");
                    break;
                }
                break;

                case 2:
                System.out.println("\nEnter \n1. Meter to Kilometer\n2. Kilometer to Meter\n3. Miles to Kilometer\n4. Kilometer to Miles: ");
                ch2=sc.nextInt();
                switch(ch2)
                {
                    case 1:
                    System.out.println("Enter the measurement: ");
                    value=sc.nextDouble();
                    System.out.println(value + "Meters =" + d.m_to_km(value)+"Kilometers");
                    break;

                    case 2:
                    System.out.println("Enter the measurement: ");
                    value=sc.nextDouble();
                    System.out.println(value + "Kilometers =" + d.km_to_m(value)+"Meters");
                    break;
                    
                    case 3:
                    System.out.println("Enter the measurement: ");
                    value=sc.nextDouble();
                    System.out.println(value + "Miles =" + d.miles_to_km(value)+"Kilometers");
                    break;

                    case 4:
                    System.out.println("Enter the measurement: ");
                    value=sc.nextDouble();
                    System.out.println(value + "Kilometers =" + d.km_to_m(value)+"Miles");
                    break;
                }
                break;
                
                case 3:
                System.out.println("\nEnter \n1. Hours to Minutes\n2. Minutes to Hours\n3. Minutes to Seconds\n4. Seconds to Minutes: ");
                ch2=sc.nextInt();
                switch(ch2)
                {
                    case 1:
                    System.out.println("Enter the value: ");
                    value=sc.nextDouble();
                    System.out.println(value + "Hours =" + t.hrs_to_mins(value)+"Minutes");
                    break;

                    case 2:
                    System.out.println("Enter the value: ");
                    value=sc.nextDouble();
                    System.out.println(value + "Minutes =" + t.mins_to_hrs(value)+"Hours");
                    break;

                    case 3:
                    System.out.println("Enter the value: ");
                    value=sc.nextDouble();
                    System.out.println(value + "Minutes =" + t.mins_to_secs(value)+"Seconds");
                    break;

                    case 4: 
                    System.out.println("Enter the value: ");
                    value=sc.nextDouble();
                    System.out.println(value + "seconds =" + t.secs_to_mins(value)+"Minutes");
                    break;

                }
                break;

                case 4:
                System.out.println("Exiting application :)");
                sc.close();
                System.exit(0);
                break;

                default:
                System.out.println("Please enter a valid option!");
            }
        }
    }
}