package figury;

public class Trojkat {
    Punkt a, b, c;

    public Trojkat(Punkt a, Punkt b, Punkt c) {
        if (a.x * (b.y - c.y) + b.x * (c.y - a.y) + c.x * (a.y - b.y) == 0) {
            throw new IllegalArgumentException("Podane punkty są współliniowe.");
        }
        else {
            this.a = a;
            this.b = b;
            this.c = c;
        }
    }

    public void przesun(Wektor v) {
        a.przesun(v);
        b.przesun(v);
        c.przesun(v);
    }

    public void obroc(Punkt p, double kat) {
        a.obroc(p, kat);
        b.obroc(p, kat);
        c.obroc(p, kat);
    }

    public void odbij(Prosta k) {
        a.odbij(k);
        b.odbij(k);
        c.odbij(k);
    }


    public String toString() {
        return a.toString() + " " + b.toString() + " " + c.toString();
    }
}