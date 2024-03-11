#include <cstdio>
void regaloScontato(float &regalo, float &percentuale, float &scontato);
void piuCostoso(float &x, float &y);

int main(){

    float prezzoScontato, percentualeSconto, prezzoRegalo;
    float totaleRegali, regaloCostoso, mediaCosti;
    totaleRegali = 0;


    for (int i = 1; i <= 7; i++) {
        regaloScontato( prezzoRegalo, percentualeSconto, prezzoScontato);

        piuCostoso(regaloCostoso, prezzoScontato);

        totaleRegali = totaleRegali + prezzoScontato;
        printf(" Regalo Scontato = %.2f\n", prezzoScontato);
    }
    mediaCosti = totaleRegali / 7;
    printf("Mario ha speso euro: %.2f\n", totaleRegali);
    printf("La media di cio' che ha speso e': %.2f \n", mediaCosti);
    printf("Il regalo piu' costoso equivale a: %.2f \n", regaloCostoso);
}

void regaloScontato (float &regalo, float &percentuale, float &scontato) {
    printf("Costo regalo = \n");
    scanf(" %f", &regalo);
    do {
        printf("Percentuale sconto = \n");
        scanf(" %f", &percentuale);
    } while (percentuale < 10 || percentuale > 50);
    percentuale = (1 - (percentuale / 100));
    scontato = regalo * percentuale;
    return;
}

void piuCostoso(float &x, float &y) {
    if (x < y)
        x = y;
    return;
}
