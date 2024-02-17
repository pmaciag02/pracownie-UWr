package figury;

public final class Prosta {
    public final double a, b, c;

    public Prosta (double a, double b, double c) {
        this.a = a;
        this.b = b;
        this.c = c;
    }

    public static Prosta przesun(Prosta k, Wektor v) {
        return new Prosta(k.a, k.b, k.c - k.a * v.dx - k.b * v.dy);
    }

    public static boolean rownolegle(Prosta k, Prosta l) {
        return k.a * l.b - k.b * l.a == 0;
    }

    public static boolean prostopadle(Prosta k, Prosta l) {
        return k.a * l.a + k.b * l.b == 0;
    }

    public static Punkt przeciecie(Prosta k, Prosta l) {
        if(!Prosta.rownolegle(k, l)) {
            double x = (l.b * k.c - k.b * l.c) / (k.a * l.b - k.b * l.a);
            double y = (k.a * l.c - l.a * k.c) / (k.a * l.b - k.b * l.a);

            return new Punkt(x , y);
        }
        else {
            throw new IllegalArgumentException("Proste są równoległe.");
        }
    }
}