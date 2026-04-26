#include <stdio.h>
#include <string.h>
#include "marshrut.h"

int input_marshruts(struct MARSHRUT1 *arr, int max_size) {
    int count = 0;
    printf("Введите количество маршрутов (не более %d): ", max_size);
    scanf("%d", &count);
    
    if (count > max_size) count = max_size;
    if (count < 0) count = 0;

    for (int i = 0; i < count; i++) {
        printf("\n--- Маршрут %d ---\n", i + 1);
        printf("Номер маршрута: ");
        scanf("%d", &arr[i].number);
        printf("Начальный пункт: ");
        scanf("%s", arr[i].start_point);
        printf("Конечный пункт: ");
        scanf("%s", arr[i].end_point);
        printf("Длина маршрута: ");
        scanf("%f", &arr[i].length);
    }
    return count;
}

int find_min_length_index(const struct MARSHRUT1 *arr, int size) {
    if (size <= 0) return -1;
    int min_idx = 0;
    for (int i = 1; i < size; i++) {
        if (arr[i].length < arr[min_idx].length) {
            min_idx = i;
        }
    }
    return min_idx;
}

void sort_by_length(struct MARSHRUT1 *arr, int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j].length > arr[j + 1].length) {
                struct MARSHRUT1 temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void print_by_point(const struct MARSHRUT1 *arr, int size, const char *point) {
    int found = 0;
    printf("\nМаршруты, связанные с пунктом '%s':\n", point);
    for (int i = 0; i < size; i++) {
        if (strcmp(arr[i].start_point, point) == 0 || strcmp(arr[i].end_point, point) == 0) {
            printf("№%d: %s -> %s (Длина: %.2f)\n", arr[i].number, arr[i].start_point, arr[i].end_point, arr[i].length);
            found = 1;
        }
    }
    if (!found) printf("Таких маршрутов не найдено.\n");
}

void print_all(const struct MARSHRUT1 *arr, int size) {
    for (int i = 0; i < size; i++) {
        printf("№%d: %s -> %s (Длина: %.2f)\n", arr[i].number, arr[i].start_point, arr[i].end_point, arr[i].length);
    }
}