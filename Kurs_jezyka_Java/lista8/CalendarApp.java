import javax.swing.*;
import javax.swing.event.ChangeEvent;
import javax.swing.event.ChangeListener;
import java.awt.*;
import java.text.DateFormatSymbols;
import java.util.Calendar;
import java.util.GregorianCalendar;
import java.awt.event.MouseAdapter;
import java.awt.event.MouseEvent;


public class CalendarApp {

    public static void main(String[] args) {
        SwingUtilities.invokeLater(() -> {
            JFrame frame = new JFrame("Universal Calendar");
            frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
            frame.getContentPane().add(new CalendarPanel());
            frame.pack();
            frame.setLocationRelativeTo(null);
            frame.setVisible(true);
        });
    }
}

class CalendarPanel extends JPanel {

    private JTabbedPane tabbedPane;
    private CalendarModel dayListModel;
    private CalendarModel prevDayListModel;
    private CalendarModel nextDayListModel;
    private JLabel yearLabel;
    private int currentYear;
    private int currentMonth;
    public JPanel monthPanel;
    public JPanel[] singlemonthPanel;
    public CalendarPanel() {
        setLayout(new BorderLayout());
        currentYear = getCurrentYear();
        currentMonth = getCurrentMonth();

        currentMonth++;

        tabbedPane = new JTabbedPane();

        createYearTab();
        createMonthTab();

        add(tabbedPane, BorderLayout.CENTER);
        add(createToolBar(), BorderLayout.SOUTH);
    }

    private void createYearTab() {
        JPanel yearPanel = new JPanel(new GridLayout(3, 4));

        


        tabbedPane.addTab("Year", yearPanel);

        singlemonthPanel = new JPanel[13];
        for (int month = 1; month <= 12; month++) {
            singlemonthPanel[month] = new JPanel(new GridLayout(0, 7));

            int temp = month;

            singlemonthPanel[month].addMouseListener(new MouseAdapter() {
                @Override
                public void mouseClicked(MouseEvent e) {


                    updateDayList(temp);


                    int currentIndex = tabbedPane.getSelectedIndex();
                    int nextIndex = (currentIndex + 1) % tabbedPane.getTabCount();
                    tabbedPane.setSelectedIndex(nextIndex);
                }
            });
            yearPanel.add(singlemonthPanel[month]);

            int daysInMonth = getDaysInMonth(currentYear, month - 1);
            int startDayOfWeek = getStartDayOfWeek(currentYear, month - 1);

            if (startDayOfWeek == 1) {
                startDayOfWeek = 7;
            }
            else {
                startDayOfWeek -= 1;
            }

            for (int i = 1; i <= daysInMonth + startDayOfWeek - 1; i++) {
                if (i < startDayOfWeek) {
                    singlemonthPanel[month].add(new JLabel(""));
                } else {
                    int day = i - startDayOfWeek + 1;
                    JLabel dayLabel = new JLabel(String.valueOf(day));
                    dayLabel.setHorizontalAlignment(JLabel.CENTER);
                    if ((i % 7) == 0) {
                        dayLabel.setForeground(Color.RED);
                    }
                    singlemonthPanel[month].add(dayLabel);
                }
            }
        }
    }

    private void createMonthTab() {
        monthPanel = new JPanel(new GridLayout(1, 3));
        tabbedPane.addTab("Month", monthPanel);


        int prevmonth = currentMonth, prevyear = currentYear;
        if (currentMonth == 1) {
            prevmonth = 12;
            prevyear = currentYear - 1;
        }
        prevDayListModel = new CalendarModel(prevyear, prevmonth);
        JList<String> prevdayList = new JList<>(prevDayListModel);
        prevdayList.setCellRenderer(new CalendarCellRenderer());
        monthPanel.add(new JScrollPane(prevdayList), BorderLayout.CENTER);

        dayListModel = new CalendarModel(currentYear, currentMonth);
        JList<String> dayList = new JList<>(dayListModel);
        dayList.setCellRenderer(new CalendarCellRenderer());
        monthPanel.add(new JScrollPane(dayList), BorderLayout.CENTER);

        int nextmonth = currentMonth, nextyear = currentYear;
        if (currentMonth == 12) {
            nextmonth = 1;
            nextyear = currentYear + 1;
        }
        nextDayListModel = new CalendarModel(nextyear, nextmonth);
        JList<String> nextdayList = new JList<>(nextDayListModel);
        nextdayList.setCellRenderer(new CalendarCellRenderer());
        monthPanel.add(new JScrollPane(nextdayList), BorderLayout.CENTER);
    }

    

    private JToolBar createToolBar() {
        JToolBar toolBar = new JToolBar();

        yearLabel = new JLabel(String.valueOf(currentYear));
        JButton prevYearButton = new JButton("<<");
        JButton nextYearButton = new JButton(">>");
        JSpinner yearSpinner = new JSpinner(new SpinnerNumberModel(currentYear, 1, 9999, 1));

        prevYearButton.addActionListener(e -> updateYear(-1));
        nextYearButton.addActionListener(e -> updateYear(1));
        yearSpinner.addChangeListener(new ChangeListener() {
            @Override
            public void stateChanged(ChangeEvent e) {
                updateYear((int) yearSpinner.getValue() - currentYear);
            }
        });

        toolBar.add(prevYearButton);
        toolBar.add(yearLabel);
        toolBar.add(nextYearButton);
        toolBar.add(new JLabel("   "));
        toolBar.add(new JLabel("Year:"));
        toolBar.add(yearSpinner);

        return toolBar;
    }

    private void updateYear(int offset) {
        currentYear += offset;
        yearLabel.setText(String.valueOf(currentYear));
        updateMonthList();
        updateDayList(currentMonth);
    }

    private void updateMonthList() {
        String[] monthNames = new DateFormatSymbols().getMonths();

       

        for (int month = 1; month <= 12; month++) {

            int daysInMonth = getDaysInMonth(currentYear, month - 1);
            int startDayOfWeek = getStartDayOfWeek(currentYear, month - 1);

            if (startDayOfWeek == 1) {
                startDayOfWeek = 7;
            }
            else {
                startDayOfWeek -= 1;
            }

            singlemonthPanel[month].removeAll();
            singlemonthPanel[month].revalidate();
            singlemonthPanel[month].repaint();
            for (int i = 1; i <= daysInMonth + startDayOfWeek - 1; i++) {
                if (i < startDayOfWeek) {
                    singlemonthPanel[month].add(new JLabel(""));
                } else {
                    int day = i - startDayOfWeek + 1;
                    JLabel dayLabel = new JLabel(String.valueOf(day));
                    dayLabel.setHorizontalAlignment(JLabel.CENTER);
                    if ((i % 7) == 0) {
                        dayLabel.setForeground(Color.RED);
                    }
                    singlemonthPanel[month].add(dayLabel);
                }
            }
        }
    }


    private void updateDayList(int currentindex) {
        int prevmonth = currentindex - 1, prevyear = currentYear;
        if (prevmonth == 0) {
            prevmonth = 12;
            prevyear = currentYear - 1;
        }

        prevDayListModel.month = prevmonth;
        prevDayListModel.year = prevyear;

        dayListModel.month = currentindex;
        dayListModel.year = currentYear;

        int nextmonth = currentindex + 1, nextyear = currentYear;
        if (nextmonth == 13) {
            nextmonth = 1;
            nextyear = currentYear + 1;
        }

        nextDayListModel.month = nextmonth;
        nextDayListModel.year = nextyear;
    }

 




    private int getDaysInMonth(int year, int month) {
        Calendar calendar = new GregorianCalendar(year, month, 1);
        return calendar.getActualMaximum(Calendar.DAY_OF_MONTH);
    }

    private int getStartDayOfWeek(int year, int month) {
        Calendar calendar = new GregorianCalendar(year, month, 1);
        return calendar.get(Calendar.DAY_OF_WEEK);
    }


    private int getCurrentYear() {
        return new GregorianCalendar().get(Calendar.YEAR);
    }

    private int getCurrentMonth() {
        return new GregorianCalendar().get(Calendar.MONTH);
    }
}


class CalendarCellRenderer extends DefaultListCellRenderer {
    @Override
    public Component getListCellRendererComponent(JList<?> list, Object value, int index, boolean isSelected, boolean cellHasFocus) {
        Component component = super.getListCellRendererComponent(list, value, index, isSelected, cellHasFocus);

        String dateString = (String) value;
        String[] parts = dateString.split(", ");
        String dayOfWeek = parts[0];

        if (dayOfWeek.equals("SUNDAY")) {
            component.setForeground(Color.RED);
        } else {
            component.setForeground(Color.BLACK);
        }

        return component;
    }
}


