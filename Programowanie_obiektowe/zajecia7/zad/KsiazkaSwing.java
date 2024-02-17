import javax.swing.*;
import java.awt.*;
import java.awt.event.*;

public class KsiazkaSwing extends JComponent implements ActionListener{
    
    Ksiazka ksiazka;
    String plik;
    JTextField tytul2, autor2, rok2;

    public KsiazkaSwing(Ksiazka k, String p)
    {
        //JPanel panel = new JPanel();
        ksiazka = k;
        plik = p;

        setBorder(BorderFactory.createTitledBorder("Książka"));

        setLayout(new GridLayout(4, 2));

        JLabel tytul = new JLabel("Tytuł: ");
        add(tytul);

        tytul2 = new JTextField();
        add(tytul2);


        JLabel autor = new JLabel("Autor: ");
        add(autor);

        autor2 = new JTextField();
        add(autor2);


        JLabel rok = new JLabel("Rok: ");
        add(rok);

        rok2 = new JTextField();
        add(rok2);

        JButton zapisz = new JButton("Zapisz");
        add(zapisz);
        zapisz.addActionListener(this);
    }

    public void actionPerformed(ActionEvent e)
    {
        String n = tytul2.getText();
        String a = autor2.getText();
        int r = Integer.parseInt(rok2.getText());

        ksiazka = new Ksiazka(n, a, r);
        ksiazka.zapisz(plik);
        System.out.println(ksiazka.toString());
    }
}
