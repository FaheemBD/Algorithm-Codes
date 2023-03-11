#include <stdio.h>

int subset[100], n, sum;

void subset_sum(int s[], int k, int r) {
    int i;

    subset[k] = 1;
    if (k <= n && r - s[k] == 0) {
        for (i = 1; i <= k; i++) {
            if (subset[i])
                printf("%d ", s[i]);
        }
        printf("\n");
    } else if (k < n && r - s[k] >= 0) {
        subset_sum(s, k+1, r - s[k]);
    }

    if (k <= n && r - s[k] - s[k+1] >= 0) {
        subset[k] = 0;
        subset_sum(s, k+1, r - s[k]);
    }
}

int main() {
    int s[] = {10, 7, 5, 18, 12, 20, 15};
    n = sizeof(s) / sizeof(int);
    sum = 35;

    subset_sum(s, 0, sum);

    return 0;
}
