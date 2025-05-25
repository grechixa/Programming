// определение структуры данных и функций для работы с данными студентов
// Файл: data.h

#ifndef DATA_H
#define DATA_H

#define MAX_NAME_LEN 100
#define MAX_STUDENTS 100

typedef struct{
    char name[MAX_NAME_LEN];
    int grade[5];
} Student;

int read_students(const char *filename, Student students[], int *count); // Функция для чтения данных студентов из файла
void sort_students(Student students[], int count); // Функция для сортировки студентов по оценкам
double calculate_average(Student students[], int count); // Функция для вычисления средней оценки студентов
int write_results(const char *filename, Student students[], int count, double avg); // Функция для записи результатов в файл

#endif // DATA_H