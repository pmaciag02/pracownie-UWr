import java.util.concurrent.*;

public class Lesson10 {

    private static Runnable taskA = () -> hardCalculation(10);
    private static Runnable taskB = () -> hardCalculation(5);
    private static Runnable taskC = () -> hardCalculation(1);
    private static Runnable taskWithError = () -> hardCalculation(0);
    private static Runnable taskD = () -> printWithDelayInLoop(2, "Task D", 10);
    private static Runnable taskE = () -> printWithDelayInLoop(3, "Task E", 10);

    public static void main(String[] args) throws Exception {
//        runnableExample();
//        runnableExample2();
//        runnableExample3();
//        runnableExample4();
//        runnableExample5();
//        runnableExample6();
//        runnableExample7();
//        callableExample();
//        callableExample2();
//        threadPoolExample();
//        threadPoolExample2();
//        threadPoolExample3();
//        threadPoolExample4();
//        futureExample();
//        futureExample2();
//        futureExample3();
//        futureExample4();
//        completableFutureExample();
//        completableFutureExample2();
//        completableFutureExample3();
//        completableFutureExample4();
//        completableFutureExample5();
        System.out.println("MAIN LAST LINE");
    }

    private static void runnableExample() {
        taskA.run();
        taskB.run();
        taskC.run();
        System.out.println("ALL TASKS ENDED");
    }

    private static void runnableExample2() {
        (new Thread(taskA)).run();
        (new Thread(taskB)).run();
        (new Thread(taskC)).run();
        System.out.println("ALL TASKS ENDED");
    }

    private static void runnableExample3() {
        (new Thread(taskA)).start();
        (new Thread(taskB)).start();
        (new Thread(taskC)).start();
        System.out.println("ALL TASKS STARTED");
    }

    private static void runnableExample4() {
        Thread threadD = new Thread(taskD);
        Thread threadE = new Thread(taskE);
        threadD.start();
        threadE.start();
        System.out.println("ALL TASKS STARTED");
        try {
            threadD.join();
            threadE.join();
        } catch (InterruptedException e) {
            e.printStackTrace();
        }
        System.out.println("ALL TASKS ENDED");
    }

    private static void runnableExample5() {
        Thread threadD = new Thread(taskD);
        Thread threadE = new Thread(taskE);
        threadD.start();
        threadE.start();
        System.out.println("ALL TASKS STARTED");
        try {
            System.out.println("WAITING FOR THREAD D");
            while (threadD.isAlive()) {
                System.out.println("THREAD D IS STILL RUNNING");
                threadD.join(5_000);
            }

            System.out.println("WAITING FOR THREAD E");
            while (threadE.isAlive()) {
                System.out.println("THREAD E IS STILL RUNNING");
                threadE.join(5_000);
            }
        } catch (InterruptedException e) {
            e.printStackTrace();
        } finally {
            System.out.println("ALL TASKS ENDED");
        }
    }

    private static void runnableExample6() {
        (new Thread(taskA)).run();
        (new Thread(taskB)).run();
        (new Thread(taskWithError)).run();
        (new Thread(taskC)).run();
        System.out.println("ALL TASKS ENDED");
    }

    private static void runnableExample7() {
        (new Thread(taskA)).start();
        (new Thread(taskB)).start();
        (new Thread(taskWithError)).start();
        (new Thread(taskC)).start();
        System.out.println("ALL TASKS STARTED");
    }

    private static Callable<Long> futureTaskA = () -> hardCalculation2(10);
    private static Callable<Long> futureTaskB = () -> hardCalculation2(5);
    private static Callable<Long> futureTaskC = () -> hardCalculation2(1);
    private static Callable<Long> futureTaskWithError = () -> hardCalculation2(0);

    private static void callableExample() throws Exception {
        futureTaskA.call();
        futureTaskB.call();
        futureTaskC.call();
    }

    private static void callableExample2() throws Exception {
        System.out.println(futureTaskA.call());
        System.out.println(futureTaskB.call());
        System.out.println(futureTaskC.call());
    }

    private static ExecutorService threadPool = Executors.newFixedThreadPool(3);
    private static ExecutorService threadPool2 = Executors.newFixedThreadPool(10);

    private static void threadPoolExample() {
        addTasks(threadPool, 10);
    }

    private static void threadPoolExample2() {
        addTasks(threadPool2, 10);
    }

    private static void threadPoolExample3() {
        addTasks(threadPool2, 10);
        threadPool2.shutdown();
        System.out.println(threadPool2.isShutdown() + ", " + threadPool2.isTerminated());
    }

    private static void threadPoolExample4() {
        addTasks(threadPool2, 10);
        sleepSeconds(5);
        threadPool2.shutdownNow();
        System.out.println(threadPool2.isShutdown() + ", " + threadPool2.isTerminated());
        sleepSeconds(1);
        System.out.println(threadPool2.isShutdown() + ", " + threadPool2.isTerminated());
    }

    private static void futureExample() throws Exception {
        Future<Long> futureA = threadPool.submit(() -> futureTaskA.call());
        Future<Long> futureB = threadPool.submit(() -> futureTaskB.call());
        Future<Long> futureC = threadPool.submit(() -> futureTaskC.call());
        System.out.println("ALL TASKS STARTED");
        while (!futureA.isDone() || !futureB.isDone() || !futureC.isDone()) {
            System.out.print(".");
            sleepSeconds(1);
        }
        System.out.println();
        System.out.println(futureA.get() + ", " + futureB.get() + ", " + futureC.get());
    }

    private static void futureExample2() {
        Future<Long> futureA = threadPool.submit(() -> futureTaskA.call());
        Future<Long> futureB = threadPool.submit(() -> futureTaskB.call());
        Future<Long> futureC = threadPool.submit(() -> futureTaskC.call());
        System.out.println("ALL TASKS STARTED");
        tryGetFutureResult(futureA, 2);
        tryGetFutureResult(futureB, 2);
        tryGetFutureResult(futureC, 2);
    }

    private static void futureExample3() {
        Future<Long> futureA = threadPool.submit(() -> futureTaskA.call());
        Future<Long> futureB = threadPool.submit(() -> futureTaskB.call());
        Future<Long> futureC = threadPool.submit(() -> futureTaskC.call());
        Future<Long> futureWithError = threadPool.submit(() -> futureTaskWithError.call());
        System.out.println("ALL TASKS STARTED");
        tryGetFutureResult(futureA, 2);
        tryGetFutureResult(futureB, 2);
        tryGetFutureResult(futureC, 2);
        tryGetFutureResult(futureWithError, 0);
    }

    private static void futureExample4() {
        Future<Long> futureA = threadPool.submit(() -> futureTaskA.call());
        Future<Long> futureB = threadPool.submit(() -> futureTaskB.call());
        Future<Long> futureC = threadPool.submit(() -> futureTaskC.call());
        System.out.println("ALL TASKS STARTED");
        sleepSeconds(7);
        futureA.cancel(true);
        futureB.cancel(true);
        futureC.cancel(true);
        System.out.println(futureA.isDone() + ", " + futureB.isDone() + ", " + futureC.isDone());
        tryGetFutureResult(futureA, 0);
        tryGetFutureResult(futureB, 0);
        tryGetFutureResult(futureC, 0);
    }

    private static void completableFutureExample() throws ExecutionException, InterruptedException {
        Future<Long> futureA = CompletableFuture.supplyAsync(() -> hardCalculation(10), threadPool);
        Future<Long> futureB = CompletableFuture.supplyAsync(() -> hardCalculation(5), threadPool);
        Future<Long> futureC = CompletableFuture.supplyAsync(() -> hardCalculation(1), threadPool);
        System.out.println("ALL TASKS STARTED");
        while (!futureA.isDone() || !futureB.isDone() || !futureC.isDone()) {
            System.out.print(".");
            sleepSeconds(1);
        }
        System.out.println();
        System.out.println(futureA.get() + ", " + futureB.get() + ", " + futureC.get());
    }

    private static void completableFutureExample2() throws ExecutionException, InterruptedException {
        CompletableFuture<Long> futureA = CompletableFuture.supplyAsync(() -> hardCalculation(10), threadPool);
        CompletableFuture<Long> futureB = CompletableFuture.supplyAsync(() -> hardCalculation(5), threadPool);
        CompletableFuture<Long> futureC = CompletableFuture.supplyAsync(() -> hardCalculation(1), threadPool);
        CompletableFuture<Void> completableFuture = CompletableFuture.allOf(futureA, futureB, futureC);
        completableFuture.get();
        System.out.println("ALL TASKS ENDED");
        while (!futureA.isDone() || !futureB.isDone() || !futureC.isDone()) {
            System.out.print(".");
            sleepSeconds(1);
        }
        System.out.println();
        System.out.println(futureA.get() + ", " + futureB.get() + ", " + futureC.get());
    }

    private static void completableFutureExample3() throws ExecutionException, InterruptedException {
        CompletableFuture<Long> futureA = CompletableFuture.supplyAsync(() -> hardCalculation(10), threadPool);
        CompletableFuture<Long> futureB = CompletableFuture.supplyAsync(() -> hardCalculation(5), threadPool);
        CompletableFuture<Long> futureC = CompletableFuture.supplyAsync(() -> hardCalculation(1), threadPool);
        CompletableFuture<Object> completableFuture = CompletableFuture.anyOf(futureA, futureB, futureC);
        System.out.println("ALL TASKS STARTED");
        System.out.println("FIRST RESULT: " + completableFuture.get());
        threadPool.shutdownNow();
        System.out.println(futureA.isDone() + ", " + futureB.isDone() + ", " + futureC.isDone());
    }

    private static void completableFutureExample4() throws ExecutionException, InterruptedException {
        CompletableFuture<Long> futureB = CompletableFuture.supplyAsync(() -> hardCalculation(3), threadPool);
        CompletableFuture<Long> futureCombined = futureB.thenCompose(l -> CompletableFuture.supplyAsync(() -> hardCalculation(l), threadPool));
        futureCombined.get();
    }

    private static void completableFutureExample5() throws ExecutionException, InterruptedException {
        CompletableFuture<Long> futureB = CompletableFuture.supplyAsync(() -> hardCalculation(3), threadPool);
        CompletableFuture<Long> futureCombined = futureB.thenApply(l -> hardCalculation(l));
        futureCombined.get();
    }

    private static void addTasks(ExecutorService executorService, int taskCount) {
        for (int task = 0; task < taskCount; ++task) {
            int taskNumber = task + 1;
            executorService.submit(() -> waitingTask(taskNumber, "TASK " + taskNumber));
        }
    }

    private static void tryGetFutureResult(Future<Long> future, int seconds) {
        try {
            System.out.println(future.get(seconds, TimeUnit.SECONDS));
        } catch (ExecutionException e) {
            System.out.println("ExecutionException");
        } catch (InterruptedException e) {
            System.out.println("InterruptedException");
        } catch (TimeoutException e) {
            System.out.println("TimeoutException");
        } catch (CancellationException e) {
            System.out.println("CancellationException");
        }
    }

    private static long hardCalculation(long number) {
        if (number <= 0) {
            throw new RuntimeException("Input number must be positive");
        }
        System.out.println("HARD CALCULATION FOR: " + number + " STARTS");
        long result = 0;
        for (long l = 1; l <= number; ++l) {
            if (!sleepSeconds(1)) {
                System.out.println("HARD CALCULATION FOR: " + number + " TERMINATED :-(");
                return result;
            }
            result += l;
        }
        System.out.println("HARD CALCULATION FOR: " + number + " ENDS WITH RESULT: " + result);
        return result;
    }

    private static long hardCalculation2(long number) throws Exception {
        if (number <= 0) {
            throw new Exception("Input number must be positive");
        }
        System.out.println("HARD CALCULATION FOR: " + number + " STARTS");
        long result = 0;
        for (long l = 1; l <= number; ++l) {
            if (!sleepSeconds(1)) {
                System.out.println("HARD CALCULATION FOR: " + number + " TERMINATED :-(");
                return result;
            }
            result += l;
        }
        System.out.println("HARD CALCULATION FOR: " + number + " ENDS WITH RESULT: " + result);
        return result;
    }

    private static void waitingTask(int delayInSeconds, String taskName) {
        System.out.println("START TASK: " + taskName);
        if (sleepSeconds(delayInSeconds))
            System.out.println("END TASK: " + taskName);
        else
            System.out.println("FORCE END TASK: " + taskName);
    }

    private static void printWithDelayInLoop(int delayInSeconds, String text, int times) {
        for (int t = 0; t < times; ++t) {
            sleepSeconds(delayInSeconds);
            System.out.println(text);
        }
    }

    private static boolean sleepSeconds(int seconds) {
        try {
            TimeUnit.SECONDS.sleep(seconds);
            return true;
        } catch (InterruptedException e) {
            return false;
        }
    }
}
