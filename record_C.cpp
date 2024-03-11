#include <cstdio>
#define N 10
struct cars {
    int price[N];
    char manufacturer[];
};

int main() {
    struct cars carModel;

    for (int i = 0; i <= N; i++) {

        printf("Enter the car manufacturer:");
        scanf("  %s", &carModel.manufacturer[i]);

        do {
            printf("Enter the car price (min 10'000, max 500'000) :");
            scanf("  %d", &carModel.price[i]);
        }while(carModel.price[i] <= 10000 || carModel.price[i] >= 500000);

    }
    for (int i = 0; i <= N; i++)
        printf("Car n: %d ", i);
        printf("car manufacturer: %s model:", carModel.manufacturer);
}