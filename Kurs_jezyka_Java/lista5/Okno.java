import java.awt.*;
import java.awt.event.*;

public class Okno extends Frame {
    private TextField licznikField, mianownikField, probyField;
    private Button propozycjaButton, nowaGraButton, zakonczButton;
    private Scrollbar probScrollbar, zakresScrollbar;
    private Label informacjaLabel, przedzial;
    private Wymierna min, max; 

    private Gra gra;
    private int zakres;

    public Okno() {
        super("Gra w zgadywanie ułamków");

        
        gra = new Gra();

        
        setSize(450, 300);

        addWindowListener(new WindowAdapter() {
            public void windowClosing(WindowEvent we) {
                gra.End();
                System.exit(0);
            }
        });


        
        Panel panel1 = new Panel();
        panel1.setSize(450, 300);
        panel1.setLayout(new GridLayout(3, 1));

        Panel panel2 = new Panel();
        panel2.setSize(450, 300);
        panel2.setLayout(new GridLayout(5, 2));

        Label Label3 = new Label("Licznik:");
        panel2.add(Label3);
        licznikField = new TextField("0");
        panel2.add(licznikField);

        Label Label4 = new Label("Mianownik:");
        panel2.add(Label4);
        mianownikField = new TextField("1");
        panel2.add(mianownikField);


        Label Label5 = new Label("Ilość wykorzystanych prób:");
        panel2.add(Label5);
        probScrollbar = new Scrollbar(Scrollbar.HORIZONTAL, 0, 1, 0, 100);
        panel2.add(probScrollbar);

        informacjaLabel = new Label();

        propozycjaButton = new Button("Wyślij propozycję");
        propozycjaButton.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent ae) {
                sprawdzPropozycje();
            }
        });

        propozycjaButton.addMouseListener(new MouseAdapter() {
            String text = informacjaLabel.getText();
            @Override
            public void mouseEntered(MouseEvent e) {
                int licznik = Integer.parseInt(licznikField.getText());
                int mianownik = Integer.parseInt(mianownikField.getText());
                informacjaLabel.setText(licznik + "/" + mianownik);
            }

            @Override
            public void mouseExited(MouseEvent e) {
                informacjaLabel.setText(text);
            }
        });
        panel2.add(propozycjaButton);

        // informacjaLabel = new Label();
        panel2.add(informacjaLabel);

        


        // Label Label1 = new Label("Ilość prób:");
        // panel1.add(Label1);
        // probyField = new TextField();
        // panel1.add(probyField);


        Label Label2 = new Label("Zakres losowanych ułamków:");
        panel1.add(Label2);
        zakresScrollbar = new Scrollbar(Scrollbar.HORIZONTAL, 5, 1, 5, 20);
        zakresScrollbar.addAdjustmentListener(new AdjustmentListener() {
            public void adjustmentValueChanged(AdjustmentEvent ae) {
                zakres = zakresScrollbar.getValue();
            }
        });
        panel1.add(zakresScrollbar);

        nowaGraButton = new Button("Nowa gra");
        nowaGraButton.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent ae) {
                // int temp = Integer.parseInt(probyField.getText());
                // gra.zmienMaksIloscProb(temp);
                gra.start(zakres);
                probScrollbar.setMaximum(gra.getMaksIloscProb());
                min = new Wymierna(0);
                max = new Wymierna(1);
                remove(panel1);
                add(panel2, BorderLayout.CENTER);
                revalidate();
                repaint();
            }
        });
        panel1.add(nowaGraButton);

        zakonczButton = new Button("Zakończ");
        zakonczButton.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent ae) {
                gra.End();
                System.exit(0);
            }
        });
        panel1.add(zakonczButton);
        panel2.add(zakonczButton);

        przedzial = new Label();
        panel2.add(przedzial);


        add(panel1, BorderLayout.CENTER);

    }

    
    private void sprawdzPropozycje() {
        if(gra.BrakProb()) {
            informacjaLabel.setText("Wykożystano wszystkie próby.");
            gra.Dziennik("Wykożystano wszystkie próby.");
        }
        else {
        try {
            gra.increaseLicznikProb();
            int licznik = Integer.parseInt(licznikField.getText());
            int mianownik = Integer.parseInt(mianownikField.getText());
            Wymierna propozycja = new Wymierna(licznik, mianownik);
            

                if (propozycja.compareTo(gra.getLiczba()) < 0) {
                    // min = propozycja;
                    if (min.compareTo(propozycja) < 0) min = propozycja;
                    informacjaLabel.setText("Za mało!");
                    gra.Dziennik("Próba zgadnięcia. Za mało. Update zakresu zgadywania.");
                } else if (propozycja.compareTo(gra.getLiczba()) > 0) {
                    // max = propozycja;
                    if (max.compareTo(propozycja) > 0) max = propozycja;
                    informacjaLabel.setText("Za dużo!");
                    gra.Dziennik("Próba zgadnięcia. Za dużo. Update zakresu zgadywania.");
                } else {
                    informacjaLabel.setText("Zgadza się!");
                    gra.Dziennik("Próba zgadnięcia. Sukces.");
                    gra.Sukces();
                }
                probScrollbar.setValue(gra.getLicznikProb());
                // revalidate();
                // repaint();
                przedzial.setText("Przedział poszukiwania: [" + min.toString() + ", " + max.toString() + "]");

                System.out.println(gra.getLicznikProb());
        } catch (NumberFormatException e) {
            informacjaLabel.setText("Niepoprawny format liczby");
            gra.DziennikErrors("Niepoprawny format liczby. ", e);
        }
    }
    }


    public static void main(String[] args) {
        Okno okno = new Okno();
        okno.setVisible(true);
    }
}
