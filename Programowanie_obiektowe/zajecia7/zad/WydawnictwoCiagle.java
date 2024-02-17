import java.io.FileInputStream;
import java.io.FileOutputStream;
//import java.io.ObjectInput;
import java.io.ObjectInputStream;
import java.io.ObjectOutputStream;


public class WydawnictwoCiagle extends Ksiazka{
    int rok_rozpoczecia;
    boolean krajowe, dwujezyczne;

    public WydawnictwoCiagle()
    {

    }
    
    public WydawnictwoCiagle(String nazwa, String autor, int rok, int r, boolean k, boolean d)
    {
        super(nazwa, autor, rok);
        this.rok_rozpoczecia = r;
        this.krajowe = k;
        this.dwujezyczne = d;
    }

    public String toString()
    {
        String kraj, jezyk;

        if(this.krajowe)
        {
            kraj = "tak";
        }
        else
        {
            kraj = "nie";
        }

        if(this.dwujezyczne)
        {
            jezyk = "tak";
        }
        else
        {
            jezyk = "nie";
        }


        return "Wydawnictwo Ciągłe od roku: " + this.rok_rozpoczecia + ", krajowe: " + kraj + ", dwujęzyczne: " + jezyk;
    }


    public void zapisz(String plik)
    {
        try
        {
            FileOutputStream f = new FileOutputStream(plik);
            ObjectOutputStream o = new ObjectOutputStream(f);

            o.writeObject(this);
            o.close();
        }
        catch(Exception e)
        {
            System.out.println(e);
        }



    }

    public WydawnictwoCiagle czytaj(String plik)
    {
        WydawnictwoCiagle w = null;

        try
        {
            FileInputStream f = new FileInputStream(plik);
            ObjectInputStream o = new ObjectInputStream(f);

            w = (WydawnictwoCiagle) o.readObject();
            o.close();
        }
        catch(Exception e)
        {
            //System.out.println(e);
            w = new WydawnictwoCiagle();
        }

        return w;
    }
}
