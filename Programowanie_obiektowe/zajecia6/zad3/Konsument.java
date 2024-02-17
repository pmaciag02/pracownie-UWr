public class Konsument extends Thread
{
    Bufor<String> bufor;
    int ile;

    public Konsument(Bufor<String> b)
    {
        this.ile = 0;
        this.bufor = b;
    }

    public void run()
    {
        while(true)
        {
            try
            {
                System.out.println("Skonsumowano " + bufor.usun() + ", bufor: " + String.valueOf(bufor.ile));
            }
            catch (InterruptedException e)
            {
                
            }
            ile++;
            if (ile == 50)
                return;
        }


    }
}