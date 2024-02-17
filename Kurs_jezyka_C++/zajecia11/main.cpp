#include <iostream>
#include <fstream>
#include "cezar.hpp"

//Patryk Maciąg

using namespace std;


int main(int argc, char *argv[])
{

    if (argc < 4)
    {
        cerr << "Poprawne wywołanie: ./main <plik_wejscia> <plik_wyjscia> <klucz_szyfru>\n";
        return 0;
    }

    cezar(argv[1], argv[2], stoi(argv[3]));
    return 0;
}
