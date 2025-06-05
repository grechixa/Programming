#include "data.h"
#include <stdio.h>
#include <stdlib.h>

// Функция для чтения данных студентов из файла
int read_students(const char *filename, Student students[], int *count) {
    FILE *file = fopen(filename, "r");
    if (!file){
        perror("Не удалось открыть файл для чтения");
        return 0;
    }

    *count = 0;

    // Чтение данных студентов из файла
    while(fscanf(file, "%99s %d", students[*count].name, &students[*count].grade[0]) == 2) {
        (*count)++;
        if (*count >= MAX_STUDENTS) {
            fprintf(stderr, "Превышено максимальное количество студентов\n");
            break;
        }
    }

    fclose(file);
    return 1;
}

// Функция для сортировки студентов по оценкам (по убыванию)
void sort_students(Student students[], int count) {
    for (int i = 0; i < count - 1; i++) {
        for (int j = 0; j < count - i - 1; j++) {
            if (students[j].grade[0] < students[j + 1].grade[0]) {
                Student temp = students[j];
                students[j] = students[j + 1];
                students[j + 1] = temp;
            }
        }
    }
}

// Функция для вычисления средней оценки студентов
double calculate_average(Student students[], int count) {
    int sum = 0;
    for (int i = 0; i < count; i++) {
        sum += students[i].grade[0];
    }
    return (double)sum / count;
}

// Функция для записи результатов в файл
int write_results(const char *filename, Student students[], int count, double avg) {
    FILE *file = fopen(filename, "w");
    if (!file) {
        perror("Не удалось открыть файл для записи");
        return 0;
    }

    fprintf(file, "Список студентов по убыванию оценок:\n");
    for (int i = 0; i < count; i++) {
        fprintf(file, "%s %d\n", students[i].name, students[i].grade[0]);
    }
    fprintf(file, "\nСредняя оценка: %.2f\n", avg);

    fclose(file);
    return 1;
}