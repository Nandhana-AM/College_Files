//Create a multithreaded program by creating a subclass of Thread and then creating,
// initializing, and starting two Thread objects from your class. The threads will execute
// concurrently and display Today is hot, humid, and sunny

class WeatherThread extends Thread{
    public void run(){
        System.out.println("Today is a hot, humid, day");
    }
}
public class lab11q1 {
    public static void main(String args[]){
        WeatherThread thread1=new WeatherThread();
        WeatherThread thread2=new WeatherThread();

        thread1.start();
        thread2.start();

        try{
            thread1.join();
            thread2.join();
        }
        catch(Exception e){
            System.out.println("Exception caught: "+e.getMessage());
        }
    }
}
