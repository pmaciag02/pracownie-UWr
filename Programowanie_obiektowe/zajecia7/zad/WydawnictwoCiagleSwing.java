import javax.swing.*;
import java.awt.*;
import java.awt.event.*;


import javax.swing.JComponent;

public class WydawnictwoCiagleSwing extends JComponent implements ActionListener{
    WydawnictwoCiagle wydawnictwo;
    String plik;
    JTextField tytul2, autor2, rok2, rok_rozpoczecia2, krajowe2, dwujezyczne2;

    public WydawnictwoCiagleSwing(WydawnictwoCiagle w, String p)
    {
        wydawnictwo = w;
        plik = p;

        setBorder(BorderFactory.createTitledBorder("Wydawnictwo Ciagle"));

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


        JLabel rok_rozpoczecia = new JLabel("Rok rozpoczecia: ");
        add(rok_rozpoczecia);

        rok_rozpoczecia2 = new JTextField();
        add(rok_rozpoczecia2);


        JLabel krajowe = new JLabel("Krajowe (tak/nie): ");
        add(krajowe);

        krajowe2 = new JTextField();
        add(krajowe2);


        JLabel dwujezyczne = new JLabel("Dwujezyczne (tak/nie): ");
        add(dwujezyczne);

        dwujezyczne2 = new JTextField();
        add(dwujezyczne2);

        JButton zapisz = new JButton("Zapisz");
        add(zapisz);
        zapisz.addActionListener(this);


    }

    public void actionPerformed(ActionEvent e)
    {
        String nazwa = tytul2.getText();
        String autor = autor2.getText();
        int rok = Integer.parseInt(rok2.getText());
        int r = Integer.parseInt(rok_rozpoczecia2.getText());
        boolean k, d;
        
        if(krajowe2.getText().equals("tak"))
        {
            k=true;
        }
        else
        {
            k=false;
        }

        if(dwujezyczne2.getText().equals("tak"))
        {
            d=true;
        }
        else
        {
            d=false;
        }

        wydawnictwo = new WydawnictwoCiagle(nazwa, autor, rok, r, k, d);

        wydawnictwo.zapisz(plik);
        System.out.println(wydawnictwo.toString());
    }
}
