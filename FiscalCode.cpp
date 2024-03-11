#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cctype>

// Prototipi funzioni
void elaborateLastName(char cognome[]);
void elaborateName(char nome[]);
void toUpperCase(char word[]);
bool isVocale(char c);
bool isConsonante(char c);
void eliminateSpecialCharact(char *word);
void enterWord(char word[]);

int main () {

    char cognome[30];
    char nome[30];

    // Inserimento cognome e nome
    printf("Inserisci il cognome: \n");
    enterWord(cognome);

    printf("Inserisci il nome: \n");
    enterWord(nome);


    // elaborazione del cognome e del nome
    elaborateLastName(cognome);
    elaborateName(nome);

}

// Elaborazione del cognome
void elaborateLastName(char cognome[]) {

    char consonants[4];
    int j = 0;

    // Ciclo for per la ricerca delle consonanti
    for (int i = 0; i < strlen(cognome); ++i) {
        if (isConsonante(cognome[i])) {
            consonants[j++] = cognome[i];
        }
    }

    // Se le consonanti non bastano si aggiungo le vocali
    for (int i = 0; i < strlen(cognome) && j < 3; ++i) {
        if (isVocale(cognome[i])) {
            consonants[j++] = cognome[i];
        }
    }

    // Se non ci sono abbastanza consonanti e vocali si completa con X

    while (j < 3) {
        consonants[j++] = 'X';
    }

        for (int i = 0; i < 3; i++) {
            printf(" %c", consonants[i]);
        }
}

// Elaborazione del nome
void elaborateName(char nome[]) {

    char consonants[4];
    char contaConsonanti[7];
    int k = 0;
    int j = 0;

    // Ciclo for per la ricerca delle consonanti
    // devono essere prese la prima, la seconda e la terza consonante
    for (int i = 0; i < strlen(nome); ++i) {

        if (isConsonante(nome[i])) {
            contaConsonanti[j++] = nome[i];
            consonants[k++] = nome[i];
        }
    }

    if (k > 3) {
        consonants[0] = contaConsonanti[0];
        consonants[1] = contaConsonanti[2];
        consonants[2] = contaConsonanti[3];
    }

    // Se le consonanti non bastano si aggiungo le vocali
    for (int i = 0; i < strlen(nome) && k < 3; ++i) {
        if (isVocale(nome[i])) {
            consonants[k++] = nome[i];
        }
    }

    // Se non ci sono abbastanza consonanti e vocali si completa con X

    while (k < 3) {
        consonants[k++] = 'X';
    }

        for (int i = 0; i < 3; i++) {
            printf(" %c", consonants[i]);
        }
}

void toUpperCase(char word[]) {
    char c;
    for (int i = 0; i < strlen(word); ++i) {
        c = word[i];
        if (c >= 'a' && c <= 'z') {
            c = c - 32;
            word[i] = c;
        }
    }
}

bool isVocale(char c) {

    if (c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U') {
        return true;
    }
    return false;
}

bool isConsonante(char c) {

    if (c != 'A' && c != 'E' && c != 'I' && c != 'O' && c != 'U') {
        return true;
    }
    return false;
}

void enterWord(char word[]) {


    gets(word);

    for (int i = 0; i < strlen(word); ++i) {
        if (word[i] == ' ') {
            word[i] = word[i] + word[i + 1];
        }
    }
    toUpperCase(word);
    eliminateSpecialCharact(word);


}

void eliminateSpecialCharact(char *word) {

    for(int i = 0; word[i] != '\0'; i++) {
        if (word[i] < 'A' || word[i] > 'Z') {
            for (int j = i; word[j] != '\0'; j++) {
                word[j] = word[j + 1];
            }
        }
    }
}