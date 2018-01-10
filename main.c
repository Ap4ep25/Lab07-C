#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main() {

    FILE *file_write, *file_read;

    struct mas_struct {
        double G;
        double F;
        double Y;
    } functions;

    struct mas_struct item[100];

    double a, x, d, xmin, xmax, s = 0, steps;
    int i = 0;
    char value[100];

    printf("Введите минимальное значение х: ");
    scanf("%s", &value);
    xmin = atof(value);

    printf("Введите максимальное значение x: ");
    scanf("%s", &value);
    xmax = atof(value);

    printf("Введите а: ");
    scanf("%s", &value);
    a = atof(value);

    printf("Введите количество шагов:\n");
    scanf("%s", &value);
    steps = atoi(value);
    s = (xmax - xmin) / (steps - 1);

    i = 0;

    x = xmin;

    while ((x <= xmax) && (i <= steps)) {
        d = (10 * pow(a, 2) + 11 * a * x + 3 * pow(x, 2));
        if (d == (10e-6)) {
            printf("Введите другие значения \n");
            break;
        } else {
            item[i].G = (5 * (-2 * pow(a, 2) + a * x + 3 * pow(x, 2))/d);
            printf("G=%lf\n", item[i].G);
        }
        i++;
        if (i > 100) {
            printf("Массив переполнен.");
            break;
        }
        x += s;
    }
    printf("_______________________________________\n");

    i = 0;

    x = xmin;

    while ((x <= xmax) && (i <= steps)) {
        item[i].F = sin(10 * pow(a, 2) - 7 * a * x + pow(x ,2));
            printf("F= %0.18lf\n", item[i].F);

        i++;
        if (i > 100) {
            printf("Массив переполнен.");
            break;
        }
        x += s;
    }
    printf("_______________________________________\n");

    i = 0;

    x = xmin;

    while ((x <= xmax) && (i <= s)) {
        item[i].Y = atan(45 * pow(a, 2) + 79 * a * x + 30 * pow(x, 2));
            printf("Y= %lf\n", item[i].Y);

        i++;
        if (i > 100) {
            printf("Массив переполнен.");
            break;
        }
        x += s;
    }
    printf("_______________________________________\n");

    file_write = fopen("/home/ap4ep25/CLionProjects/untitled6/file.txt", "w");
    for (i = 0; i < steps; i++) {
        fprintf(file_write, "%lf, %0.18lf, %lf\n", item[i].G, item[i].F, item[i].Y);
    }
    fclose(file_write);

    file_read = fopen("/home/ap4ep25/CLionProjects/untitled6/file.txt", "r");
    while (!feof(file_read)) {
        double g1,f1,y1;
        fscanf(file_read, "%lf, %lf, %lf\n", &g1, &f1, &y1);
        printf("G = %lf, F = %0.18lf, Y = %lf\n", g1, f1, y1);
    }
    fclose(file_read);

    return 0;
}