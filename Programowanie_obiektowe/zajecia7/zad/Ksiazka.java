import java.io.FileInputStream;
import java.io.FileOutputStream;
//import java.io.ObjectInput;
import java.io.ObjectInputStream;
import java.io.ObjectOutputStream;
import java.io.Serializable;

//import java.io.*;

public class Ksiazka implements Serializable{
    String nazwa, autor;
    int rok;
    
    public Ksiazka()
    {

    }
    
    public Ksiazka(String n, String a, int r)
    {
        this.nazwa = n;
        this. autor = a;
        this.rok = r;
    }

    public String toString()
    {
        return "Książka: " + this.nazwa + ", autor: " + this.autor + ", rok wydania: " + this.rok;

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
            //e.printStackTrace();
        }



    }

    public Ksiazka czytaj(String plik)
    {
        Ksiazka k = null;

        try
        {
            FileInputStream f = new FileInputStream(plik);
            ObjectInputStream o = new ObjectInputStream(f);

            k = (Ksiazka) o.readObject();
            o.close();
        }
        catch(Exception e)
        {
            //System.out.println(e);
            //e.printStackTrace();
            k = new Ksiazka();
        }

        System.out.println(k.toString());
        return k;
    }

}
