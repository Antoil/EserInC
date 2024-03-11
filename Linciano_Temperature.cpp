#include <cstdio>

void leggiTemperatura(double temperature[], int dim);
int menu();
double calcoloMedia(double temperature[], int &inizio, int &fine, double *media);
void massimaMinima(double temperature[], int *max, int *min, int *ore, int *oreMin);
int main() {

    int scelta, inizio, fine, massima, minima, orarioMax, orarioMin;
    double media;
    int dim = 24;
    double temperatura[24];
    leggiTemperatura(temperatura, dim);

    do {
        scelta = menu();

        switch (scelta) {
            case 1:
                inizio = 0,
                fine = 23;
                media = calcoloMedia(temperatura, inizio, fine, &media);
                printf("La media della temperatura della giornata e' : %.2lf\n", media);
                break;
            case 2:
                inizio = 0,
                fine = 6;
                media = calcoloMedia(temperatura, inizio, fine, &media);
                printf("La media della temperatura notturna e' : %.2lf\n", media);
                break;
            case 3:
                inizio = 8,
                fine = 14;
                media = calcoloMedia(temperatura, inizio, fine, &media);
                printf("La media della temperatura diurna e' : %.2lf\n", media);
                break;
            case 4:
                inizio = 17,
                fine = 21;
                media = calcoloMedia(temperatura, inizio, fine, &media);
                printf("La media della temperatura crepuscolare e' : %.2lf\n", media);
                break;
        }
    } while (scelta != 0);

    massimaMinima(temperatura, &massima, &minima, &orarioMax, &orarioMin);

    printf("La temperatura massima e' : %d ", massima);
    printf("delle ore : %d \n", orarioMax);

    printf("La temperatura minima e' : %d ", minima);
    printf("delle ore : %d \n", orarioMin);

}

void leggiTemperatura(double temperature[], int dim) {

    for (int i = 0; i < dim; i++) {
            printf("Inserisci temperature delle ore %d : ", i);
            scanf(" %lf", &temperature[i]);
    }
}

int menu(){

    int sceltaMenu;

    printf("1. Media Giornaliera\n");
    printf("2. Media Notturna\n");
    printf("3. Media Diurna\n");
    printf("4. Media Crepuscolare\n");
    printf("0. Esci\n");

    do {
        printf("Inserisci scelta: ");
        scanf(" %d", &sceltaMenu);
    } while(sceltaMenu < 0 || sceltaMenu > 4);

    return sceltaMenu;
}

double calcoloMedia(double temperature[], int &inizio, int &fine, double *media) {

    double somma = 0;
    for (int i = inizio; i <= fine; i++) {
        somma = somma + temperature[i];
    }
    *media = somma / ((fine - inizio) + 1);

    return *media;
}

void massimaMinima(double temperature[], int *max, int *min, int *ore, int *oreMin) {
    for (int i = 0; i <= 23; i++) {
        if (i == 0) {
            *min = temperature[i];
            *max = temperature[i];
        }
        if (temperature[i] < *min) {
            *min = temperature[i];
            *oreMin = i;
        }
        if (temperature[i] > *max) {
            *max = temperature[i];
            *ore = i;
        }
    }
}