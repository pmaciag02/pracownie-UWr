public class Wymierna implements Comparable<Wymierna> {
    private int licznik, mianownik = 1;

    public Wymierna() {
        this.licznik = 0;
    }

    public Wymierna(int n) {
        this(n, 1);
    }

    public Wymierna(int k, int m) {
        if (m == 0) {
            throw new IllegalArgumentException("Mianownik nie może być równy 0.");
        }
        this.licznik = k;
        this.mianownik = m;
        this.skroc();
    }

    private int NWD(int a, int b) {
        return b == 0 ? a : NWD(b, a % b);
    }

    private void skroc() {
        int nwd = NWD(Math.abs(licznik), Math.abs(mianownik));
        this.licznik = licznik / nwd;
        this.mianownik = mianownik / nwd;
        if(mianownik < 0) {
            this.licznik *= -1;
            this.mianownik *= -1;
        }
    }

    public int getLicznik() {
        return licznik;
    }

    public int getMianownik() {
        return mianownik;
    }

    @Override
    public String toString() {
        return licznik + "/" + mianownik;
    }

    // @Override
    public boolean equals(Wymierna w) {
        return licznik == w.licznik && mianownik == w.mianownik;
    }

    @Override
    public int compareTo(Wymierna w) {
        Wymierna roznica = odejmowanie(this, w);
        if (roznica.getLicznik() > 0) {
            return 1;
        } else if (roznica.getLicznik() < 0) {
            return -1;
        } else {
            return 0;
        }
    }

    public static Wymierna dodawanie(Wymierna a, Wymierna b) {
        int newLicznik = a.licznik * b.mianownik + a.licznik * b.mianownik;
        int newMianownik = a.mianownik * b.mianownik;
        return new Wymierna(newLicznik, newMianownik);
    }

    public static Wymierna odejmowanie(Wymierna a, Wymierna b) {
        int newLicznik = a.licznik * b.mianownik - b.licznik * a.mianownik;
        int newMianownik = a.mianownik * b.mianownik;
        return new Wymierna(newLicznik, newMianownik);
    }

    public static Wymierna mnozenie(Wymierna a, Wymierna b) {
        int newLicznik = a.licznik * b.licznik;
        int newMianownik = a.mianownik * b.mianownik;
        return new Wymierna(newLicznik, newMianownik);
    }

    public static Wymierna dzielenie(Wymierna a, Wymierna b) {
        if (b.licznik == 0) {
            throw new ArithmeticException("Nie można dzielić przez zero.");
        }

        int newLicznik = a.licznik * b.mianownik;
        int newMianownik = a.mianownik * b.licznik;
        return new Wymierna(newLicznik, newMianownik);
    }
}
