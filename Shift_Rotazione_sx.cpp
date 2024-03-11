#include <cstdio>

#define N 5

void shift_Sx(int vet[]);
void rotazione_Sx(int vet[]);
int menu();
void letturaVet(int vet[]);
void stampaVet(int vet[]);
void shift_Dx(int vet[]);
void rotazione_Dx(int vet[]);
void azzeramentoVet(int vet[], int vetOriginal[]);

int choice(int *sceltaMenu);

int main() {

    int vettore[N];
    int vetOriginal[N];
    int sceltaMenu;

    letturaVet(vettore);
    for (int i = 0; i <= N; i++) {
        vetOriginal[i] = vettore[i];
    }
    do {
        sceltaMenu = menu();
        switch (sceltaMenu) {
            case 1:
                azzeramentoVet(vettore, vetOriginal);
                shift_Sx(vettore);
                stampaVet(vettore);
                break;
            case 2:
                azzeramentoVet(vettore, vetOriginal);
                rotazione_Sx(vettore);
                stampaVet(vettore);
                break;
            case 3:
                azzeramentoVet(vettore, vetOriginal);
                shift_Dx(vettore);
                stampaVet(vettore);
                break;
            case 4:
                azzeramentoVet(vettore, vetOriginal);
                rotazione_Dx(vettore);
                stampaVet(vettore);
                break;
        }
    } while(sceltaMenu != 0);
    printf("Fine programma\n");
}

void letturaVet(int vet[]) {

    for (int i = 0; i <= N; i++) {
        printf("Inserisci numero:\n");
        scanf("%d", &vet[i]);
    }
}

int menu() {
    int scelta;

    printf("---Menu:\n");
    printf("1. Muovi vettore a sinistra\n");
    printf("2. Ruota vettore a sinistra\n");
    printf("3. Muovi vettore a destra\n");
    printf("4. Ruota vettore a destra\n");
    printf("0. Fine programma\n");


    choice(&scelta);

    return scelta;
}

int choice(int *sceltaMenu) {

    do {
        printf("Inserisci scelta:\n");
        scanf("%d", *&sceltaMenu);
    } while(*sceltaMenu < 0 || *sceltaMenu > 4);

    return *sceltaMenu;
}
void shift_Sx(int vet[]) {
    int fine = vet[N];
    for (int i = 0; i <= N; i++) {
        vet[i] = vet[i + 1];
    }
    vet[N] = fine;
}


void rotazione_Sx(int vet[]) {
    int inizio = vet[0];
    for (int i = 0; i <= N; i++) {
        vet[i] = vet[i + 1];
    }
    vet[N] = inizio;
}

void shift_Dx(int vet[]) {
    int inizio = vet[0];
    for (int i = N; i >= 0; i--) {
        vet[i] = vet[i - 1];
    }
    vet[0] = inizio;
}

void rotazione_Dx(int vet[]) {
    int fine = vet[N];
    for (int i = N; i >= 0; i--) {
        vet[i] = vet[i - 1];
    }
    vet[0] = fine;
}

void azzeramentoVet(int vet[], int vetOriginal[]) {

    for (int i = 0; i <= N; i++) {
        vet[i] = vetOriginal[i];
    }
}
void stampaVet(int vet[]) {
    for (int i = 0; i <= N; ++i) {
        printf(" Vettore n: %d, valore: %d\n", i, vet[i]);
    }
}