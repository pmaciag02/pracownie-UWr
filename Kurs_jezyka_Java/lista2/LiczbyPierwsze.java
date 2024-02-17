import java.util.Arrays;

public final class LiczbyPierwsze {
    private final static int POTEGA2 = 21;
    private final static int[] SITO = new int[1 << POTEGA2];
    
    static {
        Arrays.fill(SITO, 1);

        for (int i = 2; i * i <= (SITO.length - 1); i++) {
            if(SITO[i] != 1) {
                continue;
            }
            SITO[i] = i;
            for (int j = i + i; j <= (SITO.length - 1); j += i) {
                if(SITO[j] == 1) {
                    SITO[j] = i;
                }
            }
        }
    }
    
    public static boolean czyPierwsza(long x) {
        if (x == Long.MIN_VALUE) {
            return false;
        }

        x = Math.abs(x);
        if (x < 2) return false;

        if (x < 1 << POTEGA2) {
            if (SITO[(int) x] == x) {
                return true;
            }
            else {
                return false;
            }
        }
        else {
            // long sqrtX = (long)Math.sqrt(x)+1;
            // if % 2
            for (long i = 3; i * i <= x; i++) { //int przechodzi zakres i wywala
                if (x % i == 0) {
                    System.out.println(i);
                    return false;
                }
            }
        }
        return true;
    }

    public static long[] naCzynnikiPierwsze(long x) {

        int index = 0;
        long[] czynniki = new long[64];

        if (x == Long.MIN_VALUE) {
            x /= 2;
            czynniki[index++] = 2;
            x *= -1;
        }

        if (x < 0) x *= -1;
        int maxFactor = (int) Math.sqrt(x);

        if (x < 2) return new long[]{x};

        if (x > (1 << POTEGA2)) {
            long k = 2;
            while(k <= maxFactor && x >= (1 << POTEGA2)) {
                while(x % k == 0 && x >= (1 << POTEGA2)) {
                    czynniki[index++] = k;
                    x /= k;
                }
            k++;
            }
            if (x != 1 && k <= maxFactor) {
                while (x > 1) {
                    czynniki[index++] = SITO[(int) x];
                    x /= SITO[(int) x];
                }
            }
        }
        else {
            while (x > 1) {
                czynniki[index++] = SITO[(int) x];
                x /= SITO[(int) x];
            }
        }

        if (x > 1) czynniki[index++] = x;


        long[] result = new long[index];
        System.arraycopy(czynniki, 0, result, 0, index);
        return result;
    }

    public static void main(String[] args) {
        if (args.length == 0) {
            System.err.println("Użycie: java LiczbyPierwsze <liczba1> <liczba2> ...");
        } else {
            for (String arg : args) {
                long liczba = Long.parseLong(arg);
                // System.out.print(liczba + " = ");
                // long[] czynniki = naCzynnikiPierwsze(liczba);

                // for (int i = 0; i < czynniki.length; i++) {
                //     System.out.print(czynniki[i]);
                //     if (i < czynniki.length - 1) {
                //         System.out.print(" * ");
                //     }
                // }
                System.out.println(czyPierwsza(liczba));
                System.out.println();
            }

            // System.out.println(czyPierwsza(4));
            // System.out.println(czyPierwsza(-7));
        }
    }
}
