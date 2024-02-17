import javax.swing.*;
import java.awt.*;
import java.awt.event.*;


public class CzasopismoSwing extends JComponent implements ActionListener{
    Czasopismo czasopismo;
    String plik;
    JTextField tytul2, autor2, rok2, tematyka2, numer2, liczba_stron2;

    public CzasopismoSwing(Czasopismo cz, String p)
    {
        //JPanel panel = new JPanel();
        czasopismo = cz;
        plik = p;
        setBorder(BorderFactory.createTitledBorder("Czasopismo"));

        setLayout(new GridLayout(7, 2));

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



        JLabel tematyka = new JLabel("Tematyka: ");
        add(tematyka);

        tematyka2 = new JTextField();
        add(tematyka2);


        JLabel numer = new JLabel("Numer: ");
        add(numer);

        numer2 = new JTextField();
        add(numer2);


        JLabel liczba_stron = new JLabel("Liczba stron: ");
        add(liczba_stron);

        liczba_stron2 = new JTextField();
        add(liczba_stron2);

        JButton zapisz = new JButton("Zapisz");
        add(zapisz);
        zapisz.addActionListener(this);


    }

    public void actionPerformed(ActionEvent e)
    {
        String nazwa = tytul2.getText();
        String autor = autor2.getText();
        int rok = Integer.parseInt(rok2.getText());
        String t = tematyka2.getText();
        int n = Integer.parseInt(numer2.getText());
        int l = Integer.parseInt(liczba_stron2.getText());
        

        czasopismo = new Czasopismo(nazwa, autor, rok, t, n, l);

        czasopismo.zapisz(plik);
        System.out.println(czasopismo.toString());
    }
}
