import java.util.Random;

public class SharesThread extends Thread
{
    
    public SharesThread(int maxValue) {
        this.maxValue = maxValue;
    }
    
    public void fluctuatePrice()
    {
        while(true) {
            Random rn = new Random(); //random number generator
            int newPrice = rn.nextInt(this.maxValue);
            Shares.shareprice = newPrice; //set shareValue in main class
            System.out.println("Price changed to " + newPrice);
            try {
                Thread.sleep(frequency);
            } catch(java.lang.InterruptedException ie){}; //delay fluctuation*/
        }
    }
    
    public void run()
    {
        fluctuatePrice();
    }
    
    private int maxValue=100;
    private final long frequency=200; //frequency of fluctuating share value in msec
}
