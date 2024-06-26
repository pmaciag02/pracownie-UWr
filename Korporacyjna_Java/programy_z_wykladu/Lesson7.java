public class Lesson7 {

    public static void main(String[] args) {
//        System.out.println(test1());
//        System.out.println(test2());
//        System.out.println(test3());
//        test4();
//        test5();
//        test6();
//        test7();
//        System.out.println(test8());
//        System.out.println(test9());
//        System.out.println(test10());
//        System.out.println(test11());
        System.out.println(test12());
    }

    private static int test1() {
        int a = 2;
        try {
            return a;
        } finally {
            a += 1;
        }
    }

    private static IntWrapper test2() {
        IntWrapper a = new IntWrapper(2);
        try {
            return a;
        } finally {
            a.changeBy(1);
        }
    }

    private static int test3() {
        int a = 2;
        try {
            return a;
        } finally {
            a += 1;
            return a;
        }
    }

    private static void test4() {
        try {
            System.out.print("Hello");
            return;
        } finally {
            System.out.println(" World");
        }
    }

    private static void test5() {
        try {
            System.out.print("Hello");
            while (true) ;
        } finally {
            System.out.println(" World");
        }
    }

    private static void test6() {
        try {
            System.out.print("Hello");
            throw new RuntimeException("I don't like World");
        } finally {
            System.out.println(" World");
        }
    }

    private static void test7() {
        try {
            System.out.print("Hello");
            System.exit(0);
        } finally {
            System.out.println(" World");
        }
    }

    private static int test8() {
        int a = 0;
        try {
            return 10 / a;
        } catch (ArithmeticException arithmeticException) {
            a += 1;
            return 10 / a;
        } finally {
            a += 1;
            return 10 / a;
        }
    }

    private static int test9() {
        IntWrapper a = new IntWrapper(0);
        try {
            return 10 / a.value;
        } catch (ArithmeticException arithmeticException) {
            a.changeBy(1);
            return 10 / a.value;
        } finally {
            a.changeBy(1);
            return 10 / a.value;
        }
    }

    private static int test10() {
        int a = 0;
        try {
            System.out.println("Block try");
            return 10 / a;
        } catch (ArithmeticException arithmeticException) {
            System.out.println("Block catch: detailed");
            a += 1;
            return 10 / a;
        } catch (RuntimeException runtimeException) {
            System.out.println("Block catch: general");
            a += 1;
            return 10 / a;
        } catch (Exception exception) {
            System.out.println("Block catch: more general");
            a += 1;
            return 10 / a;
        } finally {
            System.out.println("Block finally");
            a += 1;
            return 10 / a;
        }
    }

    private static int test11() {
        int a = 0;
        try {
            System.out.println("Block try");
            return 10 / a;
        } catch (ArithmeticException arithmeticException) {
            System.out.println("Block catch: detailed");
            return 10 / a;
        } catch (RuntimeException runtimeException) {
            System.out.println("Block catch: general");
            a += 1;
            return 10 / a;
        } catch (Exception exception) {
            System.out.println("Block catch: more general");
            a += 1;
            return 10 / a;
        } finally {
            System.out.println("Block finally");
            a += 1;
            return 10 / a;
        }
    }

    private static int test12() {
        int a = 0;
        try {
            try {
                System.out.println("Block try");
                return 10 / a;
            } catch (ArithmeticException arithmeticException) {
                System.out.println("Block catch: detailed");
                return 10 / a;
            } catch (RuntimeException runtimeException) {
                System.out.println("Block catch: general");
                a += 1;
                return 10 / a;
            } catch (Exception exception) {
                System.out.println("Block catch: more general");
                a += 1;
                return 10 / a;
            }
        } catch (Exception exception) {
            System.out.println("Block catch: outer");
            a += 1;
            return 10 / a;
        }
    }

    private static class IntWrapper {
        int value;

        public IntWrapper(int value) {
            this.value = value;
        }

        public void changeBy(int by) {
            value += by;
        }

        @Override
        public String toString() {
            return Integer.toString(value);
        }
    }
}
