import javax.swing.*;
import java.time.DayOfWeek;
import java.time.LocalDate;

public class CalendarModel extends AbstractListModel<String> {
    public int year;
    public int month;

    public CalendarModel(int year, int month) {
        this.year = year;
        this.month = month;
    }

    @Override
    public String getElementAt(int index) {
        LocalDate date = LocalDate.of(year, month, index + 1);
        DayOfWeek dayOfWeek = date.getDayOfWeek();

        return String.format("%s, %d, %s", dayOfWeek.toString(), date.getDayOfMonth(), date.getMonth().toString());
    }

    @Override
    public int getSize() {
        return LocalDate.of(year, month, 1).lengthOfMonth();
    }

   
}


