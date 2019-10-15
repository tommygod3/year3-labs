import java.util.ArrayList;

public class BuyerThread extends Thread
{

    public BuyerThread()
    {
        this.sharePrices = new ArrayList<Integer>();
    }

    public void lookAtStocks()
    {
        while(true)
        {
            try
            {
                this.sleep(1000);
            }
            catch(java.lang.InterruptedException ie){}; //delay fluctuation*/
            if(this.sharePrices.size() > 9)
            {
                System.out.println(sharePrices);
                break;
            }
            this.potentialPurchase(Shares.shareprice);
        }
    }

    public void run()
    {
        lookAtStocks();
    }

    public synchronized void potentialPurchase(int sharePrice)
    {
        if(sharePrice > 20)
        {
            sharePrices.add(sharePrice);
        }
    }

    public ArrayList<Integer> sharePrices;
}