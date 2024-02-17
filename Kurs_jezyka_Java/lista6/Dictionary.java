public interface Dictionary<T extends Comparable<T>> {
    // Wyszukiwanie elementu w słowniku
    boolean search(T x);

    // Wstawianie elementu do słownika
    void insert(T x);

    // Usuwanie elementu ze słownika
    void remove(T x);

    // Wyznaczanie minimum w słowniku
    T min();

    // Wyznaczanie maksimum w słowniku
    T max();
}
