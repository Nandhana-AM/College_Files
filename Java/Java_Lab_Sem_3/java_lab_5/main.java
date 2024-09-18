import java.util.*;
public class main
{
    ArrayList<String> arr=new ArrayList();
    public void append(String str)
    {
        arr.add(str);
    }
    public void insert(String str, int pos)
    {
        arr.add(pos,str);
    }
    public void search(String str)
    {
        boolean ans=arr.contains(str);
        if (ans==true)
        {
            System.out.println(str+ " found in the ArrayList");
        }
        else
        {
            System.out.println(str+ " not found in the ArrayList");
        }
    }
    public void sortasc()
    {
        Collections.sort(arr);
        System.out.println("Array in ascending order: "+arr);
    }
    public void sortdesc()
    {
        Collections.sort(arr,Collections.reverseOrder());
        System.out.println("Array in descending order: "+arr);
    }
    public void startswith(char a)
    {
        for (String i : arr)
        {
            if (i.charAt(0)==a)
            {
                System.out.println(i);
            }
        }
    }
    public static void main(String[] args)
    {
        Scanner sc=new Scanner(System.in);
        main list=new main();
        int ch,pos;
        String str;
        
        while (true)
        {
            System.out.println("Enter\n1. Append\n2. Insert\n3. Search\n4. Startswith a given letter\n5. Sort in ascending\n6. Sort in descending\n7. Exit :");
            ch=sc.nextInt();
            switch(ch)
            {
                case 1:
                    System.out.println("Enter the string you want to append: ");
                    str=sc.next();
                    list.append(str);
                    System.out.println(list.arr);
                    break;
                    
                case 2:
                    System.out.println("Enter the string you want to insert: ");
                    str=sc.next();
                    System.out.println("Enter the position where you want to insert: ");
                    pos=sc.nextInt();
                    if (pos>(list.arr.size()+1))
                    {
                        System.out.println("Enter a valid position (length of the ArrayList is "+ list.arr.size()+ ") :");
                    }
                    else if (pos==(list.arr.size()+1))
                    {
                        list.append(str);
                        System.out.println(list.arr);
                    }
                    else
                    {
                        list.insert(str,pos);
                        System.out.println(list.arr);
                    }
                    break;
                    
                case 3:
                    System.out.println("Enter the substring string you want to search: ");
                    str=sc.next();
                    list.search(str);
                    break;
                    
                case 4:
                    System.out.println("Enter the starting letter: ");
                    char a=sc.next().charAt(0);
                    list.startswith(a);
                    break;
                    
                case 5:
                    list.sortasc();
                    break;
                    
                case 6:
                    list.sortdesc();
                    break;
                    
                case 7:
                    System.out.println("Program terminated :)");
                    sc.close();
                    System.exit(0);
                    
            }  
        }
    }
}
