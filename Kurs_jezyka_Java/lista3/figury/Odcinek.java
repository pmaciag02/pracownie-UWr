package figury;

public class Odcinek {
    Punkt a, b;

    public Odcinek(Punkt a, Punkt b){
        if (a.x != b.x || a.y != b.y) {
            this.a = a;
            this.b = b;
        }
        else {
            throw new IllegalArgumentException("Konstruktor wymaga 2 różnych punktów.");
        }
    }

    public void przesun(Wektor v){
        a.przesun(v);
        b.przesun(v);
    }

    public void obroc(Punkt p,double kat){
        a.obroc(p, kat);
        b.obroc(p, kat);
    }

    public void odbij(Prosta k){
        a.odbij(k);
        b.odbij(k);
    }

    public String toString(){
        return a.toString() + " " + b.toString();
    }
}