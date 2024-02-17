package figury;

public class Punkt {
    double x, y;

    public Punkt(double x, double y) {
        this.x = x;
        this.y = y;
    }


    public void przesun(Wektor v) {
        this.x += v.dx;
        this.y += v.dy;
    }

    public void obroc(Punkt p, double alfa) {
        double X = p.x + (this.x - p.x) * Math.sin(alfa * (Math.PI / 180)) + (this.y - p.y) * Math.cos(alfa * (Math.PI / 180));
        double Y = p.y + (this.x - p.x) * Math.cos(alfa * (Math.PI / 180)) - (this.y - p.y) * Math.sin(alfa * (Math.PI / 180));
        this.x = X;
        this.y = Y;
    }

    public void odbij(Prosta k) {
        double X = this.x - 2 * (k.a * this.x + k.b * this.y + k.c) / (Math.pow(k.a, 2) + Math.pow(k.b, 2)) * k.a;
        double Y = this.y - 2 * (k.a * this.x + k.b * this.y + k.c) / (Math.pow(k.a, 2) + Math.pow(k.b, 2)) * k.b;
        this.x = X;
        this.y = Y;
    }

    public String toString(){
        return "(" + x + ", " + y + ")";
    }
}