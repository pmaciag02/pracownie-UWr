import figury.*;

public class Figury
{
    public static void main (String[] args) throws Exception
    {
        Punkt a = new Punkt(0,0);
        Punkt b = new Punkt(1,1);

        System.out.println("punkt: " + a.toString());
        System.out.println("punkt: " + b.toString());
        a.obroc(b,180);
        b.obroc(a,90);

        System.out.println("punkt: " + a.toString());
        System.out.println("punkt: " + b.toString());

        Wektor v1 = new Wektor(1,2);
        Wektor v2 = new Wektor(3,4);
        Wektor v3 = Wektor.skladanie(v1,v2);

        System.out.println("wektor: " + v3.toString());
    

        Trojkat t = new Trojkat(new Punkt(1, 1), new Punkt(1, 2), new Punkt(3, 1));
        System.out.println("trójkąt: " + t.toString());
        
        Prosta p = new Prosta(1,0,0);
        t.odbij(p);
        System.out.println("trójkąt: " + t.toString());
        t.przesun(v2);
        System.out.println("trójkąt: " + t.toString());
    }
}
