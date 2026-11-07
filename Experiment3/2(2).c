#include <stdio.h>

long long fact(int n) {
    if (n <= 1) return 1;
    return n * fact(n - 1);
}

int step;
void move(int k, char from, char to) {
    printf("%3d: %c--%d-->%c\n", ++step, from, k, to);
}

void hanoi(int n, char a, char b, char c) {
    if (n == 1) {
        move(1, a, c);
    } else {
        hanoi(n - 1, a, c, b);
        move(n, a, c);
        hanoi(n - 1, b, a, c);
    }
}

int main(void) {
    int n, k;
    printf("Input n (0-20) for n! :\n");
    if (scanf("%d", &n) != 1) return 1;
    if (n < 0 || n > 20) {
        printf("n out of range (0-20)\n");
        return 1;
    }
    printf("%d! = %lld\n\n", n, fact(n));
    printf("Hanoi moves of 4, 5, 6 disks (fixed):\n\n");
    for (k = 4; k <= 6; k++) {
        step = 0;
        printf("===== Hanoi: %d disks (a -> c) =====\n", k);
        hanoi(k, 'a', 'b', 'c');
        printf("Total steps: %d (= 2^%d - 1)\n\n", step, k);
    }
    return 0;
}