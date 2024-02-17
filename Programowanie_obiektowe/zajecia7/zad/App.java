//import javax.lang.model.util.ElementScanner6;
import javax.swing.*;
import java.awt.*;
//import java.awt.event.*;

public class App {
    public static void main(String[] args){

        if(args.length == 0)
        {
            System.err.println("sposób użycia programu: program plik.txt klasa");
            return;
        }

        JFrame frame = new JFrame();
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

        Container kontener = frame.getContentPane();

        if(args[1].equals("Ksiazka"))
        {
            Ksiazka klasa = new Ksiazka();
            klasa = klasa.czytaj(args[0]);
            KsiazkaSwing klasa2 = new KsiazkaSwing(klasa, args[0]);
            kontener.add(klasa2);
        }
        else if(args[1].equals("Czasopismo"))
        {
            Czasopismo klasa = new Czasopismo();
            klasa = klasa.czytaj(args[0]);
            CzasopismoSwing klasa2 = new CzasopismoSwing(klasa, args[0]);
            kontener.add(klasa2);
        }
        else
        {
            WydawnictwoCiagle klasa = new WydawnictwoCiagle();
            klasa = klasa.czytaj(args[0]);
            WydawnictwoCiagleSwing klasa2 = new WydawnictwoCiagleSwing(klasa, args[0]);
            kontener.add(klasa2);
        }
        

        frame.pack();
        frame.setVisible(true);
    }
}
