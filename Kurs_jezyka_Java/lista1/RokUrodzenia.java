import java.util.Scanner;
import java.util.regex.MatchResult;	


public class RokUrodzenia
{
    // tablica z wybranymi liczbami rzymskimi
    private static final  String[] RZYMSKIE = { "M", "CM", "D", "CD", "C","XC", "L", "XL", "X", "IX", "V", "IV", "I" };
    // tablica z wybranymi liczbami arabskimi
    private static int[] arabskie = { 1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1 };

    public static String rzymska(int n) {
        String wynik = "";// StringBuilder
        // int i = 0;
        // while(n > 0) {
        for (int i = 0; n > 0; ){
            if (arabskie[i] <= n) {
                wynik += RZYMSKIE[i];
                n -= arabskie[i];
            }
            else {
                i++;
            }
        }
        return wynik;
    }
    

    public static void main (String[] args)
    {
        System.out.println("Podaj imię i rok urodzenia: ");

        Scanner s = new Scanner(System.in);
        s.findInLine("(\\w+) (\\d+)");
        MatchResult result = s.match();

        System.out.println("Cześć " + result.group(1) + "!");
        int year = Integer.parseInt(result.group(2));
        s.close();

        if (year <= 0 || year >= 4000) throw new IllegalArgumentException("liczba " + year + " spoza zakresu 1-3999");

        System.out.println("Twój rok urodzenia w zapisie rzymskim to " + rzymska(year) + ".");

        System.out.println("Patron tego roku w kalendarzu chińskim to " + 
        switch (year % 12) {
            case 0 -> "małpa";
            case 1 -> "kurczak";
            case 2 -> "pies";
            case 3 -> "świnia";
            case 4 -> "szczur";
            case 5 -> "bawół";
            case 6 -> "tygrys";
            case 7 -> "królik";
            case 8 -> "smok";
            case 9 -> "wąż";
            case 10 -> "koń";
            case 11 -> "owca";
            default -> "";
        }
        + ".");
    }
}