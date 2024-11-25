abstract class emp_class
{
    abstract void emp_det(String name,double id,String add,String mail,double num);
    public void basic_pay(double BP)
    {
        double DA,HRA,PF,SCF;
        DA=0.97*BP;
        HRA=0.1*BP;
        PF=0.12*BP;
        SCF=0.001*BP;
        
        System.out.print("\nYour DA is : "+DA);
        System.out.print("\nYour HRA is : "+HRA);
        System.out.print("\nYour PF is : "+PF);
        System.out.print("\nYour SCF is : "+SCF);
    }
}
