#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>
#include <cstring>

typedef char string[30];

void elaborateLastName(string cognome);          // calcola le cifre del CF relative al cognome
void elaborateName(string name);                 // calcola le cifre del CF relative al nome
void rimozioneSpecialCara(char *parola);          // elimina i caratteri speciali
bool isVocale(char c);                            // ritorna True se il carattere é una vocale
bool isConsonante(char c);                        // ritorna True se il carattere é una consonante
void printFiscalCode();


int main() {

    string cognome;
    string name;

    printf("\nInserisci il cognome: \n");
    scanf("%s", cognome);

    elaborateLastName(cognome);

    printf("\nInserisci il nome:\n");
    scanf("%s", name);

    elaborateName(name);

}

void elaborateLastName(string cognome) {

    char consonants[4];
    int j = 0;


    // Ricerca per consonanti, ne servono 3
    for (int i = 0; cognome[i] != '\0'; i++) {

        // Porta in maiuscolo il carattere del cognome
        cognome[i] = toupper(cognome[i]);

        if (isConsonante(cognome[i])) {
            consonants[j++] = cognome[i];
        }

    }

    // Ricerca per vocali
    for (int i = 0; cognome[i] != '\0' && j < 3; i++) {
        if (isVocale(cognome[i])) {
            consonants[j++] = cognome[i];
        }
    }

    // Se non ci sono abbastanza consonanti e lettere si completa con X
    while (j < 3) {
        consonants[j++] = 'X';
    }

    printf("Le consonanti per il cognome sono:");
    for (int i = 0; i < 3; i++) {
        printf(" %c", consonants[i]);
    }
}

void rimozioneSpecialCara(char *parola) {

    for(int i = 0; parola[i] != '\0'; i++) {
        if (parola[i] < 'A' || parola[i] > 'Z') {

            // se il carattere non é una lettera, elimina
            for(int j = i; parola[j] != '\0'; j++) {

                // sposto tutti i caratteri a sinistra per sovrascrivere
                // il carattere da eliminare
                parola[j] = parola[j + 1];
            }
        }
    }

}

bool isVocale(char c) {
    c = toupper(c);

    if (c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U') {
        return true;
    }
    return false;
}


bool isConsonante(char c) {
    c = toupper(c);

    if (c >= 'A' && c <= 'Z' && !isVocale(c)) {
        return true;
    }
    return false;
}
