#include <stdio.h>
int main() {
    int p1[30] = {3, 2, 4, 1, 2, 4, 0};
    int p2[30] = {3, 5, 4, 2, 2, 7, 0};
    int p3[30] = {0};

    int i = 1, j = 1, k = 1;
    int n = p1[0], m = p2[0];

    while (i <= n && j <= m) {
        if (p1[2*i] == p2[2*j]) {
            int t = p1[2*i-1] + p2[2*j-1];
            if (t != 0) {
                p3[2*k] = p1[2*i];
                p3[2*k-1] = t;
                k = k + 1;
            }
            i = i + 1;
            j = j + 1;
        }
        else if (p1[2*i] > p2[2*j]) {
            p3[2*k] = p1[2*i];
            p3[2*k-1] = p1[2*i-1];
            i = i + 1;
            k = k + 1;
        }
        else if (p1[2*i] < p2[2*j]) {
            p3[2*k] = p2[2*j];
            p3[2*k-1] = p2[2*j-1];
            j = j + 1;
            k = k + 1;
        }
    }

    while (i <= n) {
        p3[2*k] = p1[2*i];
        p3[2*k-1] = p1[2*i-1];
        i = i + 1;
        k = k + 1;
    }

    while (j <= m) {
        p3[2*k] = p2[2*j];
        p3[2*k-1] = p2[2*j-1];
        j = j + 1;
        k = k + 1;
    }

    p3[0] = k - 1;

    int total = 2 * p3[0] + 1;
    for (int idx = 0; idx < total; idx++) {
        printf("%5d", p3[idx]);
    }

    printf("\n");
    return 0;
}
