import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

public class GUIApp extends JFrame {

    public GUIApp() {
        super("GUIApp");

        BST<String> bst;
        bst = new BST<>();

        JPanel Panel1;
        Panel1 = new JPanel() {
            @Override
            protected void paintComponent(Graphics g) {
                super.paintComponent(g);
                drawBST(g, getWidth() / 2, 10, bst.getRoot(), getWidth() / 4);
            }

            private void drawBST(Graphics g, int x, int y, BST.Node<String> node, int horizontalSpace) {
                if (node != null) {
                    g.drawString(node.getData(), x, y);

                    if (node.getLeft() != null) {
                        g.drawLine(x, y, x - horizontalSpace, y + 50);
                        drawBST(g, x - horizontalSpace, y + 50, node.getLeft(), horizontalSpace / 2);
                    }
                    if (node.getRight() != null) {
                        g.drawLine(x, y, x + horizontalSpace, y + 50);
                        drawBST(g, x + horizontalSpace, y + 50, node.getRight(), horizontalSpace / 2);
                    }
                }
            }
        };

    
        JTextField inputField = new JTextField(10);
        
        


        
        JButton insertButton = new JButton("Insert");
        insertButton.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                String value = inputField.getText();
                if (!value.isEmpty()) {
                    bst.insert(value);
                    Panel1.repaint();
                }
            }
        });


        JButton deleteButton = new JButton("Delete");
        deleteButton.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                String value = inputField.getText();
                if (!value.isEmpty()) {
                    bst.remove(value);
                    Panel1.repaint();
                }
            }
        });

        
        JPanel Panel2 = new JPanel();
        Panel2.add(new JLabel("Value: "));
        Panel2.add(inputField);
        Panel2.add(insertButton);
        Panel2.add(deleteButton);
        

        
        add(Panel1, BorderLayout.CENTER);
        add(Panel2, BorderLayout.SOUTH);

        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setSize(600, 400);
    }


    

    public static void main(String[] args) {
        GUIApp guiapp = new GUIApp();
        guiapp.setVisible(true);
    }
}
