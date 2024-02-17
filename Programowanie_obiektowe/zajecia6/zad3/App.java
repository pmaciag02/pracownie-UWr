public class App {
    public static void main(String[] args){
        Bufor<String> bufor = new Bufor<String>(5);

        Producent producent = new Producent(bufor);
        Konsument konsument = new Konsument(bufor);

        producent.start();
        konsument.start();
    }
}
