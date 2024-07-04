#include <stdio.h>
#include <stdlib.h>

// تابع مقایسه برای استفاده در تابع qsort
int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

int main() {
    int n, k;
    scanf("%d %d", &n, &k);

    int *friends = (int *)malloc(n * sizeof(int));
    if (friends == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }

    for (int i = 0; i < n; i++) {
        scanf("%d", &friends[i]);
    }

    // تعداد کل افراد شامل کارمند و دوستانش
    int *total_people = (int *)malloc(n * sizeof(int));
    if (total_people == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }

    for (int i = 0; i < n; i++) {
        total_people[i] = friends[i] + 1;
    }

    // مرتب کردن آرایه تعداد کل افراد به ترتیب صعودی
    qsort(total_people, n, sizeof(int), compare);

    int current_total = 0;
    int max_employees = 0;

    for (int i = 0; i < n; i++) {
        if (current_total + total_people[i] <= k) {
            current_total += total_people[i];
            max_employees++;
        } else {
            break;
        }
    }

    printf("%d\n", max_employees);

    // آزادسازی حافظه
    free(friends);
    free(total_people);

    return 0;
}
