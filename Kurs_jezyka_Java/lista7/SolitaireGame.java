import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.event.KeyEvent;
import java.awt.event.KeyListener;
import java.io.*;

public class SolitaireGame extends JFrame {
    private SolitaireBoard board;
    // private JLabel statusLabel;

    public SolitaireGame() {

        board = new SolitaireBoard();

        setTitle("Samotnik - Peg Solitaire");
        setSize(400, 400);
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

        board.statusLabel = new JLabel("Rozpocznij nową grę");
        add(board.statusLabel, BorderLayout.SOUTH);

        add(board, BorderLayout.CENTER);

        JMenuBar menuBar = new JMenuBar();
        setJMenuBar(menuBar);

        JMenu gameMenu = new JMenu("Gra");
        gameMenu.setMnemonic(KeyEvent.VK_G);
        menuBar.add(gameMenu);

        JMenuItem newGameItem = new JMenuItem("Nowa (brytyjska)", KeyEvent.VK_B);
        // newGameItem.setAccelerator(KeyStroke.getKeyStroke('n'));
        newGameItem.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                startNewGame(0);
            }
        });
        gameMenu.add(newGameItem);


        JMenuItem newGameItem2 = new JMenuItem("Nowa (europejska)", KeyEvent.VK_E);
        newGameItem2.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                startNewGame(1);
            }
        });
        gameMenu.add(newGameItem2);

        JMenuItem exitItem = new JMenuItem("Koniec", KeyEvent.VK_K);
        exitItem.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                exitGame();
            }
        });
        gameMenu.add(exitItem);

        JMenu movesMenu = new JMenu("Ruchy");
        // movesMenu.setMnemonic(KeyEvent.VK_R);
        menuBar.add(movesMenu);

        

        JMenuItem newmoveItem1 = new JMenuItem("Lewo");
        newmoveItem1.setAccelerator(KeyStroke.getKeyStroke(KeyEvent.VK_LEFT, 0));
        newmoveItem1.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                board.makeMove(37);
            }
        });
        movesMenu.add(newmoveItem1);

        JMenuItem newmoveItem2 = new JMenuItem("Góra", KeyEvent.VK_UP);
        newmoveItem2.setAccelerator(KeyStroke.getKeyStroke(KeyEvent.VK_UP, 0));
        newmoveItem2.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                board.makeMove(38);
            }
        });
        movesMenu.add(newmoveItem2);

        JMenuItem newmoveItem3 = new JMenuItem("Prawo");
        newmoveItem3.setAccelerator(KeyStroke.getKeyStroke(KeyEvent.VK_RIGHT, 0));
        newmoveItem3.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                board.makeMove(39);
            }
        });
        movesMenu.add(newmoveItem3);


        JMenuItem newmoveItem4 = new JMenuItem("Dół");
        newmoveItem4.setAccelerator(KeyStroke.getKeyStroke(KeyEvent.VK_DOWN, 0));
        newmoveItem4.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                board.makeMove(40);
            }
        });
        movesMenu.add(newmoveItem4);


        JMenuItem newmoveItem5 = new JMenuItem("Zatwierdź");
        newmoveItem5.setAccelerator(KeyStroke.getKeyStroke(KeyEvent.VK_ENTER, 0));
        newmoveItem5.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                board.makeMove(10);
            }
        });
        movesMenu.add(newmoveItem5);




        JMenu gameMenu3 = new JMenu("Ustawienia");
        menuBar.add(gameMenu3);

        JMenuItem newSettingsItem1 = new JMenuItem("Plansza żółta");
        newSettingsItem1.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                board.setBoardColor(new Color(255, 255, 0));
            }
        });
        gameMenu3.add(newSettingsItem1);

        JMenuItem newSettingsItem2 = new JMenuItem("Plansza pomarańczowa");
        newSettingsItem2.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                board.setBoardColor(new Color(255, 165, 0));
            }
        });
        gameMenu3.add(newSettingsItem2);


        JMenuItem newSettingsItem3 = new JMenuItem("Piony różowe");
        newSettingsItem3.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                board.setOvalColor(new Color(255, 182, 193));
            }
        });
        gameMenu3.add(newSettingsItem3);




        JMenuItem newSettingsItem4 = new JMenuItem("Piony czerwone");
        newSettingsItem4.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                board.setOvalColor(new Color(255, 0, 0));
            }
        });
        gameMenu3.add(newSettingsItem4);



        menuBar.add(Box.createHorizontalGlue());
        JMenu gameMenu4 = new JMenu("Pomoc");
        // gameMenu.setMnemonic(KeyEvent.VK_G);
        menuBar.add(gameMenu4);

        JMenuItem gameInfoItem = new JMenuItem("O grze");
        gameInfoItem.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                JOptionPane.showMessageDialog(null, "Opis zasad gry: https://en.wikipedia.org/wiki/Peg_solitaire", "O grze", JOptionPane.INFORMATION_MESSAGE);
            }
        });
        gameMenu4.add(gameInfoItem);


        JMenuItem gameInfoItem2 = new JMenuItem("O aplikacji");
        gameInfoItem2.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                String appInfo = "Autor: Patryk Maciąg\nWersja: 1.0\nData powstania: 20-12-2023";
                JOptionPane.showMessageDialog(null, appInfo, "O aplikacji", JOptionPane.INFORMATION_MESSAGE);
            }
        });
        gameMenu4.add(gameInfoItem2);

        

       

       
        setVisible(true);
    }

    private void startNewGame(int boardtype) {

        board.changeType(boardtype);

        board.statusLabel.setText("Rozpoczęto nową grę");
    }

    private void exitGame() {

        board.saveGameStateToFile();

        dispose();
    }

    public static void main(String[] args) {
        SwingUtilities.invokeLater(new Runnable() {
            @Override
            public void run() {
                new SolitaireGame();
            }
        });
    }
}


class GameState implements Serializable {
    public int[][] intboard = new int[7][7];
    public int counter;
    public int[][] checkboard = new int[7][7];
}

class SolitaireBoard extends JPanel {
    public JLabel statusLabel;
    private static final int CELL_SIZE = 45;
    private int[][] intboard = new int[7][7];
    private int[][] britishBoard = {
        {2, 2, 1, 1, 1, 2, 2},
        {2, 2, 1, 1, 1, 2, 2},
        {1, 1, 1, 1, 1, 1, 1},
        {1, 1, 1, 0, 1, 1, 1},
        {1, 1, 1, 1, 1, 1, 1},
        {2, 2, 1, 1, 1, 2, 2},
        {2, 2, 1, 1, 1, 2, 2}
    };
    private int[][] europeBoard = {
        {2, 2, 1, 1, 1, 2, 2},
        {2, 1, 1, 1, 1, 1, 2},
        {1, 1, 1, 1, 1, 1, 1},
        {1, 1, 1, 0, 1, 1, 1},
        {1, 1, 1, 1, 1, 1, 1},
        {2, 1, 1, 1, 1, 1, 2},
        {2, 2, 1, 1, 1, 2, 2}
    };
    private int[][] checktemp = {
        {0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 1, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0}
    };
    private int[][] checkboard = new int[7][7];

    private int counter, move = 0, selectn = 3, selectm = 3, fild1n = 3, fild1m = 3, fild2n = 3, fild2m = 3; // start new game!!!
    private Color ovalColor = new Color(0, 0, 0), boardColor = new Color(255, 255, 255);

    public void changeType(int type) {
        if (type == 0) {
            gameState.intboard = britishBoard;
            gameState.counter = 33;
        }
        else {
            gameState.intboard = europeBoard;
            gameState.counter = 37;
        }
        
        gameState.checkboard = checktemp;
        statusLabel.setText("Ruch 1");

        
        // System.out.println(gameState.counter);
        
        // gameState.counter = 3;
        // saveGameStateToFile();
    }

    @Override
    public void paintComponent(Graphics g) {
        super.paintComponent(g);
        for (int i = 0; i < gameState.intboard.length; i++) {
            for (int j = 0; j < gameState.intboard[i].length; j++) {
                if (gameState.checkboard[i][j] == 1) {
                    g.setColor(Color.blue);
                    g.fillOval(j * CELL_SIZE, i * CELL_SIZE, CELL_SIZE, CELL_SIZE);
                }
                else if (gameState.intboard[i][j] == 1) {
                    g.setColor(ovalColor);
                    g.fillOval(j * CELL_SIZE, i * CELL_SIZE, CELL_SIZE, CELL_SIZE);
                }
                else if (gameState.intboard[i][j] == 0) {
                    g.setColor(boardColor);
                    g.fillRect(j * CELL_SIZE, i * CELL_SIZE, CELL_SIZE, CELL_SIZE);
                }
                else if (gameState.intboard[i][j] == 3) { // first to move
                    g.setColor(Color.blue);
                    g.fillOval(j * CELL_SIZE, i * CELL_SIZE, CELL_SIZE, CELL_SIZE);
                }
                else if (gameState.intboard[i][j] == 4) { // second to delete
                    g.setColor(Color.blue);
                    g.fillOval(j * CELL_SIZE, i * CELL_SIZE, CELL_SIZE, CELL_SIZE);
                }
            }
        }
    }

    // @Override
    // public void keyTyped(KeyEvent e) {
    //     // Obsługa klawiatury
    //     // ...
    //     // System.out.println("Key Typed: " + e.getKeyChar());
    // }

    // @Override
    // public void keyPressed(KeyEvent e) {
    //     // Obsługa klawiatury
    //     // ...
    //     System.out.println("Key Pressed: " + e.getKeyCode());
    //     int code = e.getKeyCode();
    //     makeMove(code);
    // }

    // @Override
    // public void keyReleased(KeyEvent e) {
    //     // Obsługa klawiatury
    //     // ...
    //     // System.out.println("Key Released: " + e.getKeyCode());
    // }

    public void makeMove(int code) {
        if (code == 37) {
            if (selectm > 0 && gameState.intboard[selectn][selectm - 1] != 2) {
                gameState.checkboard[selectn][selectm] = 0;
                selectm--;
                gameState.checkboard[selectn][selectm] = 1;
                repaint();
            }
        }
        else if (code == 38) {
            if (selectn > 0 && gameState.intboard[selectn - 1][selectm] != 2) {
                gameState.checkboard[selectn][selectm] = 0;
                selectn--;
                gameState.checkboard[selectn][selectm] = 1;
                super.repaint();
            }
        }
        else if (code == 39) {
            if (selectm < 6 && gameState.intboard[selectn][selectm + 1] != 2) {
                gameState.checkboard[selectn][selectm] = 0;
                selectm++;
                gameState.checkboard[selectn][selectm] = 1;
                super.repaint();
            }
        }
        else if (code == 40) {
            if (selectn < 6 && gameState.intboard[selectn + 1][selectm] != 2) {
                gameState.checkboard[selectn][selectm] = 0;
                selectn++;
                gameState.checkboard[selectn][selectm] = 1;
                super.repaint();
            }
        }
        else if (code == 10) {
            if (move == 0) {
                fild1n = selectn;
                fild1m = selectm;
                move = 1;
                statusLabel.setText("Ruch 2");
            }
            else if (move == 1) {
                fild2n = selectn;
                fild2m = selectm;
                move = 0;
                statusLabel.setText("Ruch 1");
                checkMove();
            }
            selectn = 3;
            selectm = 3;
            // checkboard = checktemp;
            for (int i = 0; i < gameState.checkboard.length; i++) {
                for (int j = 0; j < gameState.checkboard[i].length; j++) {
                    if (i == 3 && j == 3) {
                        gameState.checkboard[i][j] = 1;
                    }
                    else {
                        gameState.checkboard[i][j] = 0;
                    }
                }
            }
            super.repaint();
            if (counter == 1 && intboard[3][3] == 1) {
                statusLabel.setText("Zwycięstwo!!!");
            }
        }
    }

    private void checkMove() {
        if (gameState.intboard[fild1n][fild1m] != 1 || gameState.intboard[fild2n][fild2m] != 0) {
            statusLabel.setText("Niepoprawny ruch. Wykonaj ruch 1");
        }
        else if (fild1n == fild2n && Math.abs(fild2m - fild1m) == 2) {
            int temp = Math.min(fild2m, fild1m) + 1;
            if (gameState.intboard[fild1n][temp] == 1) {
                gameState.intboard[fild1n][temp] = 0;
                gameState.intboard[fild1n][fild1m] = 0;
                gameState.intboard[fild2n][fild2m] = 1;
                counter--;
            }
            else {
                statusLabel.setText("Niepoprawny ruch. Wykonaj ruch 1");
            }
        }
        else if (fild1m == fild2m && Math.abs(fild2n - fild1n) == 2) {
            int temp = Math.min(fild2n, fild1n) + 1;
            if (gameState.intboard[temp][fild1m] == 1) {
                gameState.intboard[temp][fild1m] = 0;
                gameState.intboard[fild1n][fild1m] = 0;
                gameState.intboard[fild2n][fild2m] = 1;
                counter--;
            }
            else {
                statusLabel.setText("Niepoprawny ruch. Wykonaj ruch 1");
            }
        }
        else {
            statusLabel.setText("Niepoprawny ruch. Wykonaj ruch 1");
        }
    }

    public void endGame() {
        int ok = 0;
        for (int i = 0; i < gameState.intboard.length; i++) {
            for (int j = 0; j < gameState.intboard[i].length; j++) {
                if (gameState.intboard[i][j] == 1) {
                    if (i > 0 && gameState.intboard[i - 1][j] == 1) {
                        ok = 1;
                        break;
                    }
                    if (j > 0 && gameState.intboard[i][j - 1] == 1) {
                        ok = 1;
                        break;
                    }
                    if (i < 6 && gameState.intboard[i + 1][j] == 1) {
                        ok = 1;
                        break;
                    }
                    if (j < 6 && gameState.intboard[i][j + 1] == 1) {
                        ok = 1;
                        break;
                    }
                }
            }
            if (ok == 1) break;
        }

        if (ok == 0) {
            statusLabel.setText("Koniec gry. Przegrałeś.");
        }
    }

    

    public SolitaireBoard() {
        loadGameStateFromFile();
        if (gameState == null) {
            gameState = new GameState();
        }
        // this.addKeyListener(this);
        this.setFocusable(true);
        this.requestFocus();
    }


    private GameState gameState;
    
    public void saveGameStateToFile() {
        try (ObjectOutputStream outputStream = new ObjectOutputStream(new FileOutputStream("solitaire.ser"))) {
            outputStream.writeObject(gameState);
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    public void loadGameStateFromFile() {
        File file = new File("solitaire.ser");
        if (file.exists()) {
            try (ObjectInputStream inputStream = new ObjectInputStream(new FileInputStream(file))) {
                gameState = (GameState) inputStream.readObject();
                file.delete(); // Usunięcie pliku po odczytaniu
            } catch (IOException | ClassNotFoundException e) {
                e.printStackTrace();
            }
        }
    }

    public void setBoardColor(Color color) {
        setBackground(color);
        boardColor = color;
        super.repaint();
    }

    public void setOvalColor(Color color) {
        ovalColor = color;
        super.repaint();
    }
}
