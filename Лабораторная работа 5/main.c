#include <stdio.h>
#include "data.h"

int main(){
    Student students[MAX_STUDENTS];
    int count = 0;

    if(!read_students("students.txt", students, &count)) {
        return 1; // Ошибка при чтении данных
    }

    sort_students(students, count);
    double avg = calculate_average(students, count);

    if(!write_results("results.txt", students, count, avg)) {
        return 1; // Ошибка при записи результатов
    }
    printf("Результаты успешно записаны в файл results.txt\n");
    return 0; // Успешное завершение программы
}