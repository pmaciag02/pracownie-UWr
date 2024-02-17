import java.util.ArrayList;

public class Bufor<T>
{
    ArrayList<T> lista;
    public int max, ile;

    public Bufor(int m)
    {
        this.max = m;
        this.ile = 0;
        this.lista = new ArrayList<T>(max);
    }

    public synchronized void dodaj(T e) throws InterruptedException
    {
        while(ile == max)
        {
            wait();
        }

        notify();
        ile++;
        lista.add(e);
        return;
    }

    public synchronized T usun() throws InterruptedException
    {
        while(ile == 0)
        {
            wait();
        }
        notify();
        ile--;
        return lista.remove(0);
    }
}