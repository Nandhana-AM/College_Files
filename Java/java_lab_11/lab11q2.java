// Create two threads using runnable interface and one thread should print “Hi” and
// another thread as “AI” with a time interval 300ms.

class hiRunnable implements Runnable{
    @Override
    public void run(){
        try{
            int i=3;
            while (i>0){
                i--;
                System.out.println("HI");
                Thread.sleep(1000);
                
            }
            
        }
        catch(InterruptedException e){
            Thread.currentThread().interrupt();
        }
    }
}

class aiRunnable implements Runnable{
    @Override
    public void run(){
        try{
            int i=3;
            while (i>0){
                System.out.println("AI");
                Thread.sleep(1000);
                i--;
            }
            
        }
        catch(InterruptedException e){
            Thread.currentThread().interrupt();
        }
    }
}

public class lab11q2 {
    public static void main(String[] args) {
        Thread hiThread=new Thread(new hiRunnable());
        Thread aiThread=new Thread(new aiRunnable());

        hiThread.start();
        aiThread.start();
    }
   
}
