package figury;


public final class Wektor {
    public final double  dx, dy;

    public Wektor(double dx,double dy) {
        this.dx = dx;
        this.dy = dy;
    }

    public static Wektor skladanie(Wektor a, Wektor b) {
        return new Wektor(a.dx + b.dx, a.dy + b.dy);
    } 



    public String toString(){
        return "[" + dx + ", " + dy + "]";
    }
}