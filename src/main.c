#include <stdio.h>
#include "marshrut.h"

int main() {
    struct MARSHRUT1 routes[10];
    int size = input_marshruts(routes, 10);

    if (size == 0) {
        printf("Нет данных для обработки.\n");
        return 0;
    }

    printf("\n=== Исходный список ===\n");
    print_all(routes, size);

    int min_idx = find_min_length_index(routes, size);
    if (min_idx != -1) {
        printf("\n=== Маршрут с минимальной длиной ===\n");
        printf("№%d: %s -> %s (Длина: %.2f)\n", 
               routes[min_idx].number, routes[min_idx].start_point, 
               routes[min_idx].end_point, routes[min_idx].length);
    }

    sort_by_length(routes, size);
    printf("\n=== Список после сортировки по длине ===\n");
    print_all(routes, size);

    char search_point[MAX_STR];
    printf("\nВведите название пункта для поиска: ");
    scanf("%s", search_point);
    print_by_point(routes, size, search_point);

    return 0;
}