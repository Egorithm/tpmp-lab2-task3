#ifndef MARSHRUT_H
#define MARSHRUT_H

#define MAX_STR 50

struct MARSHRUT1 {
    int number;
    char start_point[MAX_STR];
    char end_point[MAX_STR];
    float length;
};

// Прототипы функций (без глобальных переменных, все передаем через параметры)
int input_marshruts(struct MARSHRUT1 *arr, int max_size);
int find_min_length_index(const struct MARSHRUT1 *arr, int size);
void sort_by_length(struct MARSHRUT1 *arr, int size);
void print_by_point(const struct MARSHRUT1 *arr, int size, const char *point);
void print_all(const struct MARSHRUT1 *arr, int size);

#endif