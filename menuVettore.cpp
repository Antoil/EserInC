#include <stdio.h>

#define N 8

void readVet(int vet[]);
int menu();
int sumVet(int vet[]);
void maxMin(int vet[], int *max, int *min);
int averageVet(int vet[]);
void printVet(int vet[]);
void printEvenVet(int vet[]);
void printEvenPosVet(int vet[]);
void binaryConversion(int vet[], int vetCobnversion[]);
void decimalConversion(int vet[], int vetCobnversion[]);
void octalConversion(int vet[], int vetCobnversion[]);

int main() {

    /*
     * Dopo aver caricato un vettore di 100 elementi, stamparare gli elemnti in posizione pari.
     */

    int vettore[N];
    int vetCobnversion[N];
    int choiceMenu, sum, maxi, mini, average;

    readVet(vettore);

    do{

        choiceMenu = menu();

        switch (choiceMenu) {
            case 1:
                sum = sumVet(vettore);
                printf("Sum elements equal: %d\n", sum);
                break;
            case 2:
                maxMin(vettore, &maxi, &mini);
                printf("Max elements equal: %d\n", maxi);
                break;
            case 3:
                maxMin(vettore, &maxi, &mini);
                printf("Min elements equal: %d\n", mini);
                break;
            case 4:
                average = averageVet(vettore);
                printf("Average elements equal: %d\n", average);
                break;
            case 5:
                printVet(vettore);
                break;
            case 6:
                readVet(vettore);
                break;
            case 7:
                printEvenVet(vettore);
                break;
            case 8:
                printEvenPosVet(vettore);
                break;
            case 9:
                binaryConversion(vettore, vetCobnversion);
                break;
            case 10:
                decimalConversion(vettore, vetCobnversion);
                break;
            case 11:
                octalConversion(vettore, vetCobnversion);
                break;
            default:
                printf("-Exit\n");
        }
    }while(choiceMenu != 0);
}

void readVet(int vet[]) {

    for (int i = 0; i <= N; i++) {

            printf("Enter number:\n");
            scanf(" %d", &vet[i]);
    }
}

int menu() {
    int choice;
    printf("1. Sum Elements\n");
    printf("2. Maximum\n");
    printf("3. Minimum\n");
    printf("4. Average\n");
    printf("5. Print Elements\n");
    printf("6. Value reassignment\n");
    printf("7. Print only even elements\n");
    printf("8. Print onlY elements in even positions\n");
    printf("9. Binary conversion \n");
    printf("10. Decimal conversion\n");
    printf("11. Octal conversion\n");
    printf("0. Exit\n");

    do {
        printf("Enter choice: ");
        scanf(" %d", &choice);
    } while(choice < 0 || choice > 11);
    return choice;
}

int sumVet(int vet[]) {
    int sum = 0;

    for (int i = 0; i <= N; i++) {
        sum += vet[i];
    }
    return sum;
}

void maxMin(int vet[], int *max, int *min){
    for (int i = 0; i <= N; i++) {
        if (i == 0) {
            *min = vet[i];
            *max = vet[i];
        }
        if (vet[i] < *min) {
            *min = vet[i];
        }
        if (vet[i] > *max) {
            *max = vet[i];
        }
    }
}

int averageVet(int vet[]) {
    int sum = 0,
        average;
    for (int i = 0; i <= N; i++) {
        sum += vet[i];
    }
    average = sum / N + 1;
    return average;
}

void printVet(int vet[]) {
    for (int i = 0; i <= N; i++) {
        printf("Element n%d, value : %d\n", i, vet[i]);
    }
}

void printEvenVet(int vet[]) {
    for (int i = 0; i <= N; i++) {
        if (vet[i] % 2 == 0) {
            printf("Element n%d, value : %d\n", i, vet[i]);
        }
    }
}

void printEvenPosVet(int vet[]) {
    for (int i = 0; i <= N; i++) {
        if (i % 2 == 0) {
            printf("Element n%d, value : %d\n", i, vet[i]);
        }
    }
}

void binaryConversion(int vet[], int vetCobnversion[]) {

    for (int i = 0; i <= N; i++) {
        vetCobnversion[i] = vet[i] % 2;
        printf("Element n%d, value : %d\n", i, vetCobnversion[i]);
    }
}

void decimalConversion(int vet[], int vetCobnversion[]) {

    for (int i = 0; i <= N; i++) {
        vetCobnversion[i] = vet[i] * 2;
        printf("Element n%d, value : %d\n", i, vetCobnversion[i]);    }
}

void octalConversion(int vet[], int vetCobnversion[]) {

    for (int i = 0; i <= N; i++) {
        vetCobnversion[i] = vet[i] * 8;
        printf("Element n%d, value : %d\n", i, vetCobnversion[i]);    }
}

