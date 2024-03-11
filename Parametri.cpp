#include <cstdio>

void scambio(int &x, int &y);

int main() {
    int a = 3,
        b = 5;

    scambio(a, b);
    printf(" a = %d, b = %d", a, b);
}

void scambio(int &x, int &y) {
    int c;

    c = x;
    x = y;
    y = c;
}
