public class Q4Class
{
    int roomno,ACmachine;
    String roomtype,roomarea;
    
    public void setdata(int roomno,int ACmachine,String roomtype,String roomarea){
       this.roomno=roomno; 
       this.ACmachine=ACmachine;
       this.roomtype=roomtype;
       this.roomarea=roomarea;
    }
    
    public void displaydata(){
        System.out.println("Room no. : "+roomno+"\nAC id : "+ACmachine+"\nRoom type : "+roomtype+"\nRoom area: "+roomarea);
    }
}
