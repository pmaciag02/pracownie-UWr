import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;
import java.util.List;
import java.util.concurrent.ThreadLocalRandom;
import java.util.function.*;

/*
 *   Author: Daniel Górski
 */

public class Lesson8 {

    private static void consumerExample() {
        Consumer<Integer> printNumber = a -> System.out.println(a);
        Consumer<Integer> printSquare = a -> System.out.println("SQUARE: " + a * a);
        Consumer<Integer> printSqrt = a -> System.out.println("SQRT: " + Math.sqrt(a));

//        printNumber.accept(5);
        printNumber.andThen(printSquare).andThen(printSqrt).accept(4);
    }

    private static void biConsumerExample() {
        BiConsumer<Integer, Integer> printSum = (a, b) -> System.out.println("SUM: " + (a + b));
        BiConsumer<Integer, Integer> printMultiplier = (a, b) -> System.out.println("MULTIPLIER: " + (a * b));

//        printSum.accept(3, 5);
        printSum.andThen(printMultiplier).accept(3, 5);
    }

    private static void supplierExample() {
        Supplier<Integer> smallEvenNumberGenerator = () -> ThreadLocalRandom.current().nextInt(50) * 2;
        Supplier<Integer> smallOddNumberGenerator = () -> ThreadLocalRandom.current().nextInt(50) * 2 + 1;

        System.out.println(smallEvenNumberGenerator.get());
        System.out.println(smallOddNumberGenerator.get());
    }

    private static void predicateExample() {
        LongPredicate even = l -> (l % 2) == 0;
        LongPredicate threeDiv = l -> (l % 3) == 0;

//        System.out.println(threeDiv.test(9));
//        System.out.println(even.and(threeDiv).test(9));
//        System.out.println(even.or(threeDiv).test(9));
        System.out.println(even.and(threeDiv).test(12));
    }

    private static void functionExample() {
        Function<Integer, Integer> oneThird = a -> a / 3;
        Function<Integer, Integer> square = a -> a * a;

//        System.out.println(oneThird.apply(6));
        System.out.println(oneThird.andThen(square).apply(6));
        System.out.println(oneThird.compose(square).apply(6));
    }

    private static void biFunctionExample() {
        Function<Integer, Integer> oneThird = a -> a / 3;
        Function<Integer, Integer> square = a -> a * a;
        BiFunction<Integer, Integer, Integer> sum = (a, b) -> a + b;

//        System.out.println(sum.apply(2, 3));
        System.out.println(sum.andThen(oneThird).apply(4, 5));
        System.out.println(sum.andThen(square).apply(4, 5));
    }

    private static void operatorExample() {
        UnaryOperator<Integer> oneThird = a -> a / 3;
        UnaryOperator<Integer> square = a -> a * a;
        BinaryOperator<Integer> sum = (a, b) -> a + b;

        System.out.println(sum.apply(2, 3));
        System.out.println(sum.andThen(oneThird).apply(4, 5));
        System.out.println(sum.andThen(square).apply(4, 5));
    }

    private static void comparatorExample() {
        List<String> list = new ArrayList<>(List.of("Jeden", "Dwa", "Trzy", "Cztery", "Pięć"));

        System.out.println(list);
//        Collections.sort(list);
//        System.out.println(list);

        BiFunction<String, String, Integer> lengthDiv = (s1, s2) -> s1.length() - s2.length();
        Comparator<String> lengthComparator = (s1, s2) -> lengthDiv.apply(s1, s2);

//        Collections.sort(list, lengthComparator);
//        System.out.println(list);
//
//        Collections.sort(list, lengthComparator.thenComparing(String::compareTo));
//        System.out.println(list);

        list.add(null);
//        Collections.sort(list, lengthComparator);

        Collections.sort(list, Comparator.nullsFirst(lengthComparator.thenComparing(String::compareTo)));
        System.out.println(list);
        Collections.sort(list, Comparator.nullsLast(lengthComparator.thenComparing(String::compareTo)));
        System.out.println(list);
    }

    public static void main(String[] args) {
//        consumerExample();
//        biConsumerExample();
//        supplierExample();
//        predicateExample();
//        functionExample();
//        biFunctionExample();
//        operatorExample();
//        comparatorExample();
    }
}