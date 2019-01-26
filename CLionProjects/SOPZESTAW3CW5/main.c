#include <stdio.h>
#include <unistd.h>


void write_from_ile_to_file(char *source_file_path, FILE *target_file_handler) {
    FILE *source_file_handler = fopen(source_file_path, "r");   //otwiera plik source_file_path i zwraca jego identyfikator, po czym przypisuje to do STRUKTRY  FILE pod wskaznikiem source_file_handler
    if (source_file_handler== NULL) {                           // pętla warunek kiedy funkcja fopen zwróci NULL to znaczy, że source_file_path nie isteniej i zamyka program
        printf("Plik %s nie istnieje", &source_file_path);
        _exit(1);
    }

    int c = getc(source_file_handler);                          //zczytuje pojedyńczy znak z klamki source_file_handler
    while (c != EOF) {                                          //dopóki pojedzyńczy znak nie równa sie znakowi końca pliku to dodaje ten znak d target_file_handler i przechpdzi d
        fputc(c, target_file_handler);                          //nastepnego znaku
        c = getc(source_file_handler);                          // przechodzi do nastepnego znaku i pobiera z source_file_handler
                                                                //kiedy dojdzie do konca petli to zammyka plik
    }

    fclose(source_file_handler);

}

int main(int argc, char *argv[]) {
    int n = argc;     //liczba podanych przez uzytkownika sciezek
    char *target_path;   //deklaracja target path jako tablicy
    target_path = argv[n - 1];  //przypisanie do zmiennej target_path

    FILE *target_file_handler = fopen(target_path, "w"); //otwiera plik i zwraca jego identyfikator
    int i;
    for (i = 1; i < n - 1; i++) {                        //petla ktora przechodzi po kazdym argumencie od 1 do przedostatniego
        write_from_ile_to_file(argv[i], target_file_handler); // a nastepnie wywoluje funkcje write from file to file
    }
    fclose(target_file_handler);
}
