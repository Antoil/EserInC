#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void readNameSurname(char nome[], char surname[]);
void readBirthday(int birthday[]);
void calculationFiscalCode(char name[], char surname[], int birthday[], char fiscalCoding[], int len, int len1);


int main() {

    char name[20];
    char cognome[20];
    char fiscalCode[16];
    int birhday[2];
    int len, len1;


    readNameSurname(name, cognome);

    len = strlen(name);
    len1 = strlen(cognome);
    readBirthday(birhday);

    calculationFiscalCode(name, cognome, birhday, fiscalCode, len, len1);


}

void readNameSurname(char nome[], char surname[]) {

    printf("Enter your name: ");
    gets(nome);
    printf("Enter your surname: ");
    gets(surname);

    printf("Your full name is: %s %s\n", nome, surname);

}

void readBirthday(int birthday[]) {

    int day, month, year;

    printf("Enter the day of birth: ");
    scanf("%d", &day);
    birthday[0] = day;
    printf("Enter the month of birth: ");
    scanf("%d", &month);
    birthday[1] = month;
    printf("Enter the year of birth: ");
    scanf("%d", &year);
    birthday[2] = year;

    printf("You born on %d/%d/%d\n", birthday[0], birthday[1], birthday[2]);
}

void calculationFiscalCode(char name[], char surname[], int birthday[], char fiscalCoding[], int len, int len1) {
    // calcola il codice fiscale
    char consonants[20];
    int u = 0;
    char vowels[]= {'A', 'E', 'I', 'O', 'U', 'a', 'e', 'i', 'o', 'u'};
    for (int i = 0; i < len1; i++) {
        if (surname[i] != vowels[0]) {
            if (surname[i] != vowels[1]) {
                if (surname[i] != vowels[2]) {
                    if (surname[i] != vowels[3]) {
                        if (surname[i] != vowels[4]) {
                            if (surname[i] != vowels[5]) {
                                if (surname[i] != vowels[6]) {
                                    if (surname[i] != vowels[7]) {
                                        if (surname[i] != vowels[8]) {
                                            if (surname[i] != vowels[9]) {
                                                consonants[u] = surname[i];
                                                u++;
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        } else;
    }

    for (int i = 0; i < len; i++) {
        if (name[i] != vowels[0]) {
            if (name[i] != vowels[1]) {
                if (name[i] != vowels[2]) {
                    if (name[i] != vowels[3]) {
                        if (name[i] != vowels[4]) {
                            if (name[i] != vowels[5]) {
                                if (name[i] != vowels[6]) {
                                    if (name[i] != vowels[7]) {
                                        if (name[i] != vowels[8]) {
                                            if (name[i] != vowels[9]) {
                                                consonants[u] = name[i];
                                                u++;
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
    } else;
    }


        for (int i = 0; i < 8; i++) {
            if (i < u) {
                printf("%c", consonants[i]); // stampa le consonanti
            }
                else {
                        printf("0%d%c%d", birthday[1], consonants[0], birthday[0]); // stampa la data di nascita e la prima consonante del cognome
                }

        }

}

