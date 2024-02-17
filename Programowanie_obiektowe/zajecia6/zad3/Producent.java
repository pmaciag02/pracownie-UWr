public class Producent extends Thread
{
    Bufor<String> bufor;
    int ile;

    public Producent(Bufor<String> b)
    {
        this.ile = 1;
        this.bufor = b;
    }

    public void run()
    {
        while(true)
        {
            try
            {
                bufor.dodaj("produkt nr " + String.valueOf(ile));
                System.out.println("Wyprodukowano produkt nr " + String.valueOf(ile) + ", bufor: " + String.valueOf(bufor.ile));
                ile++;
            }
            catch (InterruptedException e)
            {

            }
            if (this.ile == 50)
                return;
        }
    }
}