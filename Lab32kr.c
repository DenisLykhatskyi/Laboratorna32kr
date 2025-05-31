#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Man {
    char surname[50];
    int age;
    char hair_color[30];
    char address[100];
};

int main() {
    struct Man men[] = {
        {"Лихацький", 18, "блондин", "Суми, зсу 37"},
        {"Іваненко", 15, "шатен", "Львів, Шевченка 10"},
        {"Сидоренко", 22, "блондин", "Одеса, Дерибасівська 5"},
        {"Коваленко", 25, "брюнет", "Харків, Сумська 20"},
        {"Мельник", 19, "шатен", "Київ, Перемоги 15"},
        {"Шевченко", 20, "блондин", "Черкаси, Гагаріна 7"},
        {"Лисенко", 17, "брюнет", "Полтава, Соборності 3"}
    };
    int num_men = sizeof(men) / sizeof(men[0]);

    char target_hair_color[30];
    int max_age;

    printf("Введіть колір волосся для пошуку (наприклад, блондин, шатен, брюнет): ");
    if (scanf("%29s", target_hair_color) != 1) {
        fprintf(stderr, "Помилка читання кольору волосся.\n");
        return EXIT_FAILURE;
    }

    printf("Введіть максимальний вік: ");
    if (scanf("%d", &max_age) != 1) {
        fprintf(stderr, "Помилка читання віку.\n");
        return EXIT_FAILURE;
    }

    FILE *outfile = fopen("filtered_men_ukr.txt", "w");
    if (outfile == NULL) {
        perror("Не вдалося відкрити файл для запису");
        return EXIT_FAILURE;
    }

    int found_count = 0;
    for (int i = 0; i < num_men; i++) {
        if (strcmp(men[i].hair_color, target_hair_color) == 0 && men[i].age < max_age) {
            fprintf(outfile, "Прізвище: %s\n", men[i].surname);
            fprintf(outfile, "Вік: %d\n", men[i].age);
            fprintf(outfile, "Колір волосся: %s\n", men[i].hair_color);
            fprintf(outfile, "Адреса: %s\n\n", men[i].address);
            found_count++;
        }
    }

    fclose(outfile);

    if (found_count > 0) {
        printf("Дані %d чоловік(ів) відфільтровано та записано у файл filtered_men_ukr.txt\n", found_count);
    } else {
        printf("Чоловіків із заданими параметрами не знайдено. Файл filtered_men_ukr.txt може бути порожнім.\n");
    }

    return EXIT_SUCCESS;
}