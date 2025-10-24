#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "./include/functions.h"

int main()
{
    double eps;
    printf("Введите точность вычислений >> "); 
    while (scanf("%lf", &eps) != 1 || eps <= 0) {
        while(getchar() != '\n');
        printf("Ошибка ввода. Введите корректное значение точности >> ");
    }


    /*
        НАХОЖДЕНИЕ e
    */

    /* Нахождение e через предел*/
    double e_limit = func_e_limit(eps);
    printf("\nПредел: e = %lf\n", e_limit);

    /* Нахождение e через ряд/произведение */
    double e_series = func_e_series(eps);
    printf("Ряд/произведение: e = %lf\n", e_series);

    /* Нахождение e через решение специального уравнения */
    double e_equation = func_e_equation(eps);
    printf("Решение спец. уравнения: e = %lf\n\n", e_series);


    /*
        НАХОЖДЕНИЕ pi
    */

    /* Нахождение pi через предел*/
    double pi_limit = func_pi_limit(eps);
    printf("\nПредел: pi = %lf\n", pi_limit);

    /* Нахождение pi через ряд*/
    double pi_series = func_pi_series(eps);
    printf("Ряд/произведение: pi = %lf\n", pi_series);

    /* Нахождение pi через решение специального уравнения */
    double pi_equation = func_pi_equation(eps);
    printf("Решение спец. уравнения: pi = %lf\n\n", pi_equation);


    /*
        НАХОЖДЕНИЕ ln2
    */

    /* Нахождение ln2 через предел*/
    double ln2_limit = func_ln2_limit(eps);
    printf("\nПредел: ln2 = %lf\n", ln2_limit);

    /* Нахождение ln2 через ряд*/
    double ln2_series = func_ln2_series(eps);
    printf("Ряд/произведение: ln2 = %lf\n", ln2_series);

    /* Нахождение ln2 через решение специального уравнения */
    double ln2_equation = func_ln2_equation(eps);
    printf("Решение спец. уравнения: ln2 = %lf\n\n", ln2_equation);


    /*
        НАХОЖДЕНИЕ sqrt2
    */

    /* Нахождение sqrt2 через предел*/
    double sqrt2_limit = func_sqrt2_limit(eps);
    printf("\nПредел: sqrt2 = %lf\n", sqrt2_limit);

    /* Нахождение sqrt2 через ряд*/
    double sqrt2_series = func_sqrt2_series(eps);
    printf("Ряд/произведение: sqrt2 = %lf\n", sqrt2_series);

    /* Нахождение sqrt2 через решение специального уравнения */
    double sqrt2_equation = func_sqrt2_equation(eps);
    printf("Решение спец. уравнения: sqrt2 = %lf\n\n", sqrt2_equation);


    /*
        НАХОЖДЕНИЕ y
    */

    /* Нахождение y через предел*/
    double y_limit = func_y_limit(eps);
    printf("\nПредел: y = %lf\n", y_limit);

    /* Нахождение y через ряд*/
    double y_series = func_y_series(eps, pi_series);
    printf("Ряд/произведение: y = %lf\n", y_series);

    /* Нахождение y через решение специального уравнения */
    double y_equation = func_y_equation(eps);
    printf("Решение спец. уравнения: y = %lf\n\n", y_equation);

    printf("\n\n");

    printf("_________________________________________________________________\n");
    printf("|         | %15s | %15s | %15s |\n", "Limit", "Series/Product", "Equation");
    printf("|_________|_________________|_________________|_________________|\n");
    printf("|  e      | %15lf | %15lf | %15lf |\n", e_limit, e_series, e_equation);
    printf("|  pi     | %15lf | %15lf | %15lf |\n", pi_limit, pi_series, pi_equation);
    printf("|  ln2    | %15lf | %15lf | %15lf |\n", ln2_limit, ln2_series, ln2_equation);
    printf("|  sqrt2  | %15lf | %15lf | %15lf |\n", sqrt2_limit, sqrt2_series, sqrt2_equation);
    printf("|  y      | %15lf | %15lf | %15lf |\n", y_limit, y_series, y_equation);
    printf("|_________|_________________|_________________|_________________|\n");

    return 0;
}