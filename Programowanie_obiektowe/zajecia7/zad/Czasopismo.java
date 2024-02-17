import java.io.FileInputStream;
import java.io.FileOutputStream;
//import java.io.ObjectInput;
import java.io.ObjectInputStream;
import java.io.ObjectOutputStream;

public class Czasopismo extends Ksiazka{
    String tematyka;
    int numer, liczba_stron;


    public Czasopismo()
    {

    }
    
    public Czasopismo(String nazwa, String autor, int rok, String t, int n, int l)
    {
        super(nazwa, autor, rok);
        this.tematyka = t;
        this.numer = n;
        this.liczba_stron = l;
    }

    public String toString()
    {
        return "Czasopismo: " + this.nazwa + ", tematyka: " + this.tematyka + ", numer egzemplarza: " + this.numer + ", liczba stron: " + this.liczba_stron;

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

    public Czasopismo czytaj(String plik)
    {
        Czasopismo cz = null;

        try
        {
            FileInputStream f = new FileInputStream(plik);
            ObjectInputStream o = new ObjectInputStream(f);

            cz = (Czasopismo) o.readObject();
            o.close();
        }
        catch(Exception e)
        {
            //System.out.println(e);
            cz = new Czasopismo();
        }

        return cz;
    }

}
