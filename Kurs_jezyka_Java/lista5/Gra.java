import java.io.IOException;
import java.util.logging.FileHandler;
import java.util.logging.Level;
import java.util.logging.Logger;


public class Gra {
    private int zakres;
    private Wymierna liczba;
    private int maksIloscProb;
    private int licznikProb;
    private String stan;
    private static final Logger logger = Logger.getLogger(Gra.class.getName());
    private FileHandler fileHandler;
    private boolean sukces;

    private void configureLogger() {
        try {
            // Konfiguracja loggera do zapisu do pliku rozgrywka.log
            fileHandler = new FileHandler("rozgrywka.log");
            logger.addHandler(fileHandler);
            // Konfiguracja poziomu logowania (np. Level.INFO, Level.WARNING)
            logger.setLevel(Level.INFO);
        } catch (IOException e) {
            e.printStackTrace();
        }
    }


    public Gra() {
        this.stan = "NIEAKTYWNA";
        this.sukces = false;
        configureLogger();
    }

    // public void zmienZakres(int z) {
    //     if (stan == "NIEAKTYWNA") {
    //         if (z < 5 || z > 20) {
    //             throw new IllegalArgumentException("Zakres musi być między 5 a 20.");
    //         }
    //         zakres = z;
    //     } else {
    //         throw new IllegalStateException("Nie można zmieniać zakresu w trakcie aktywnej rozgrywki.");
    //     }
    // }

    public void zmienMaksIloscProb(int m) {
        this.maksIloscProb = m;
        logger.info("Nowa wartość maksymalnej ilości prób: " + m);
    }

    public void start(int z) {
        try {

        this.stan = "AKTYWNA";
        if (z < 5 || z > 20) throw new IllegalArgumentException("Zakres musi być między 5 a 20.");
        System.out.println("zakres: " + z);
        zakres = z;
        int licz, mian;
         do {
            licz = (int) (Math.random() * zakres) + 1;
            mian = (int) (Math.random() * zakres) + 1;
         }while (licz >= mian);
        liczba = new Wymierna(licz, mian);
        maksIloscProb = (int) Math.round(Math.ceil(3 * Math.log(zakres)));
        licznikProb = 0;
        assert licz > 0 && licz < mian : "Błąd losowania liczby wymiernej. Wylosowano:" + licz + " / " + mian ;
        // System.out.println(licz + " / " + mian);
        logger.info("Rozpoczęcie nowej gry. Zakres: " + zakres + ". Wylosowana liczba: " + liczba + ". Maks. liczba prób: " + maksIloscProb);
        } catch(Exception e) {
            logger.log(Level.SEVERE, "Błąd przy rozpoczynaniu gry: " + e.getMessage(), e);
        }
    }

    

    public Wymierna getLiczba() {
        return liczba;
    }

    public int getMaksIloscProb() {
        return maksIloscProb;
    }

    public int getLicznikProb() {
        return licznikProb;
    }

    public void increaseLicznikProb() {
        licznikProb++;
    }

    public boolean BrakProb() {
        return licznikProb == maksIloscProb;
    }

    public void End() {
        if (sukces) {
            logger.info("Zakończenie gry. Sukces.");
        }
        else {
            logger.info("Zakończenie gry. Porażka.");
        }
    }

    public void Sukces() {
        sukces = true;
    }

    public void Dziennik(String s) {
        logger.info(s);
    }

    public void DziennikErrors(String s, NumberFormatException e) {
        logger.log(Level.SEVERE, s + " " + e.getMessage(), e);
    }
}
