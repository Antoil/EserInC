#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>

typedef char String[31];

#define N 13

int choiceMenu();
float calculationTotalInvested(float priceFlower[], int stockFlower[], float totalInvestedFlower[]);
void flowerSupply(int stockFlower[], int *quantityflower,int *totalFlower, int i);
void invalidQuantity(int *quantityflower, int *bouquetFlower, int stockFlower[], int i);
void maxMinFlower(int flowerCount[], int *maxFlower, int *minFlower, int *c, int *v);
void printMenu();

int main() {

    String fiori[N] = {"Tulipani", "Rose Rosse", "Rose blu",
                       "Rosetea", "Orchidea", "Petunia",
                       "Gerbera", "Anemone", "Iris",
                       "Pervinca", "Lobelia", "Fiordaliso",
                       "Narciso"};
    float priceFlower[N] = {0.5, 0.73, 0.41,
                            1.08, 1.6, 0.72,
                            0.41, 0.33, 0.45,
                            0.9, 0.59, 0.68,
                            1.3};
    float totalInvested,
          dailyIncome = 0,
          totalBouquetIncome = 0;
    float flowerIncome[N] = {0};
    float totalInvestedFlower[N];
    float flowerProfit[N] = {0};
    int choice;
    int stockFlower[N] = {0};
    int flowerCount[N] = {0};
    int flowerAmount = 0,
        flowerBouquet = 0,
        totalFlower = 0;
    int maxFiore, minFiore, count, point; // variabili per la conta del massimo e minimo dei fiori venduti


    printf("Inserisci la quantita' di fiori: \n");

    for (int i = 0; i < N; i++) {

        printf("-Quantita' %s:\n", fiori[i]);
        scanf("%d", &stockFlower[i]);

        while (stockFlower[i] < 0) {
            printf("Quantita' invalida. Inserisci un valore positivo\n");
            scanf("%d", &stockFlower[i]);
        }
        totalFlower += stockFlower[i];

    }
    printf("Totale fiori: %d\n", totalFlower);
    totalInvested = calculationTotalInvested(priceFlower, stockFlower, totalInvestedFlower);

    printf("Benvenuti dal Fioraio Linciano\n");

    do {
        printMenu();

        choice = choiceMenu();

        // switch con le possibilità di scelta del menu
        switch (choice) {
            case 1:

                printf("Totale investito: %.2f\n", totalInvested);
                totalFlower = 0;
                flowerAmount = 0;
                for (int i = 0; i < N; i++) {
                    flowerSupply(stockFlower, &flowerAmount, &totalFlower, i);
                    printf("Totale %s: %d\n", fiori[i], stockFlower[i]);
                }

                printf("Totale fiori: %d\n", totalFlower);

                break;
            case 2:

                totalBouquetIncome = 0;

                if (totalFlower == 0) {
                    printf("Nessun bouquet da creare\n");
                } else {
                    printf("Inserisci quantita' di fiori per il bouquet:\n");
                    scanf("%d", &flowerBouquet);

                    while ((flowerBouquet < 0) || (flowerBouquet % 2 == 0) || flowerBouquet > totalFlower) {
                        printf("Quantita' invalida. Inserisci un valore positivo e dispari, minore di %d\n", totalFlower);
                        scanf("%d", &flowerBouquet);
                    }

                    totalFlower = 0;

                    for (int i = 0; i < N; i++) {
                        printf("Fiori mancanti %d\n", flowerBouquet);
                        printf("Inserisci la quantita' di %s per il bouquet (quantita' %d):\n", fiori[i], stockFlower[i]);
                        scanf("%d", &flowerAmount);

                        invalidQuantity(&flowerAmount, &flowerBouquet, stockFlower, i);

                        flowerCount[i] += flowerAmount;

                        flowerBouquet -= flowerAmount;

                        flowerSupply(stockFlower, &flowerAmount, &totalFlower, i);

                        totalBouquetIncome += flowerAmount * priceFlower[i];

                    }

                    if (flowerBouquet == 0) {
                        printf("Bouquet completato\n");
                    } else {
                        printf("Bouquet non completato\n");
                    }
                }
                    dailyIncome += totalBouquetIncome;
                printf("Totale bouquet da pagare: %.2f\n", totalBouquetIncome);
                break;
        }

    } while (choice != 3);

    for (int i = 0; i < N; i++) {
        flowerIncome[i] = (flowerCount[i] * priceFlower[i]);
        flowerProfit[i] = flowerIncome[i] - totalInvestedFlower[i];
    }

    printf("---CHIUSURA CASSA---\n");

    printf("GIACENZA FIORI\n");
    for (int i = 0; i < N; i++) {
        printf("%s: %d\n", fiori[i], stockFlower[i]);
    }

    // Stampa il guadagno giornaliero e il guadagno per ogni fiore
    printf("INCASSO GIORNALIERO: %.2f\n", dailyIncome);
    printf("INCASSO FIORI:\n");

    for (int i = 0; i < N; i++) {
        printf("-%s: (incasso: %.2f), (guadagno: %.2f)\n", fiori[i], flowerIncome[i], flowerProfit[i]);
    }

    printf("FIORI VENDUTI:\n");
    maxMinFlower(flowerCount, &maxFiore, &minFiore, &count, &point);
    printf("-Fiore piu' venduto: %s (venduto %d)\n", fiori[count], maxFiore);
    printf("-Fiore meno venduto: %s (venduto %d)\n", fiori[point], minFiore);
}

void printMenu() {
    printf("---Menu---\n");
    printf("1. Approvvigionamento fiori e totale investito\n");
    printf("2. Gestione cliente\n");
    printf("3. Chiusura cassa\n");
}

int choiceMenu() {

    int choice;

    printf("Inserisci scelta:");
    scanf("%d", &choice);

    while (choice < 1 || choice > 3) {
        printf("Scelta invalita. Inserisci un valore tra 1 e 3\n");
        scanf("%d", &choice);
    }

    return choice;
}

float calculationTotalInvested(float priceFlower[], int stockFlower[], float totalInvestedFlower[]) {

    float invested = 0;

    for (int i = 0; i < N; i++) {
        totalInvestedFlower[i] = stockFlower[i] * priceFlower[i];
        invested += totalInvestedFlower[i];
    }

    for (int i = 0; i < N; i++) {
        priceFlower[i] = priceFlower[i] * 1.7;
    }

    return invested;
}

void flowerSupply(int stockFlower[], int *quantityflower,int *totalFlower, int i) {

    stockFlower[i] = stockFlower[i] - *quantityflower;
    *totalFlower += stockFlower[i];

}

void invalidQuantity(int *quantityflower, int *bouquetFlower, int stockFlower[], int i) {

    while (*quantityflower < 0 || *quantityflower > *bouquetFlower || *quantityflower > stockFlower[i]) {

        if (stockFlower[i] > *bouquetFlower) {
            if (*quantityflower < 0 || *quantityflower > *bouquetFlower) {
                printf("Quantita' invalida. Inserisci un valore positivo e minore di %d\n", *bouquetFlower);
                scanf("%d", *&quantityflower);
            }
        } else {
                printf("Quantita' invalida. Inserisci un valore positivo e minore di %d\n", stockFlower[i]);
                scanf("%d", *&quantityflower);
        }

    }
}

// funzione per calcolare il fiore più venduto e meno venduto
void maxMinFlower(int flowerCount[], int *maxFlower, int *minFlower, int *c, int *v) {

    *maxFlower = flowerCount[0];
    *minFlower = flowerCount[0];
    *c = 0;
    *v = 0;

    for (int i = 0; i < N; ++i) {
        if (flowerCount[i] > *maxFlower) {
            *maxFlower = flowerCount[i];
            *c = i;
        }
        if (flowerCount[i] < *minFlower) {
            *minFlower = flowerCount[i];
            *v = i;
        }
    }
}