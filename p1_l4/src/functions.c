#include <stdio.h>
#include <math.h>
#include "./include/functions.h"
#include <stdbool.h>

double machine_epsilon_double() {
    double eps = 1.0;
    
    while (1.0 + eps != 1.0) {
        eps /= 2.0;
    }
    
    return eps * 2.0;
}




// Нахождение e с помощью предела
double func_e_limit(double eps)
{
    double limit = 1;
    double limit_pred;
    double n = 1;
    do {
        limit_pred = limit;
        limit = pow((1 + (1.0 / n)), n);
        n++;
    } while (fabs(limit - limit_pred) > eps);

    return limit;
}


// Нахождение e с помощью суммы ряда
double func_e_series(double eps)
{
    double sum = 1;
    double factorial = 1;
    int n = 1;
    do {
        factorial = factorial / n;
        sum += factorial;
        n++;
    } while (factorial > eps);

    return sum;
}


// Нахождение e с помощью специального уравнения
double func_e_equation(double eps)
{
    double x0;
    double x1 = 2;
    double ln = log(0);
    do {
        x0 = x1;
        x1 = x0 * (2.0 - log(x0));
    } while(fabs(x1 - x0) > eps);

    return x1;
}


// Нахождение pi с помощью предела
double func_pi_limit(double eps)
{
    double lim0;
    double lim1 = 4;
    double n = 1;
    do {
        lim0 = lim1;
        double dop = (4 * n * (n + 1.0)) / ((2 * n + 1.0) * (2 * n + 1.0));
        n++;
        lim1 = lim0 * dop;
    } while (fabs(lim1 - lim0) > eps);

    return lim1;
    

}

// Нахождение pi с помощью суммы ряда
double func_pi_series(double eps) 
{
    double sum = 0.0;
    int n = 1;
    double term;
    
    do {
        term = (n % 2 == 1 ? 1.0 : -1.0) / (2.0 * n - 1);
        sum += term;
        n++;
    } while (fabs(term) > eps && n < 100000);
    
    return 4.0 * sum;
}


// Нахождение pi с помощью специального уравнения
double func_pi_equation(double eps)
{
    double x_prev = 3.0;
    double x = 3.0;
    do {
        x_prev = x;
        x = x_prev + (cos(x_prev) + 1.0) / sin(x_prev);
    } while (fabs(x - x_prev) > eps);
    
    return x;
}


// Нахождение ln2 с помощью предела
double func_ln2_limit(double eps)
{
    double lim0;
    double lim1 = 1;
    double n = 1;
    do {
        lim0 = lim1;
        n++;
        lim1 = n * (pow(2, 1.0 / n) - 1);
    } while (fabs(lim1 - lim0) > eps);

    return lim1;

}


// Нахождение ln2 с помощью суммы ряда
double func_ln2_series(double eps) 
{
    double sum = 0.0;
    int n = 1;
    double term;
    do {
        term = ((n - 1) % 2 == 0 ? 1.0 : -1.0) / n;
        sum += term;
        n++;
    } while (fabs(term) > eps && n < 100000);
    
    return sum;
}


// Нахождение ln2 с помощью специального уравнения
double func_ln2_equation(double eps)
{
    double x0 = 0.7;
    double x = 0.7;
    
    do {
        x0 = x;
        double exp_x = exp(x0);
        x = x0 - (exp_x - 2.0) / exp_x;
    } while (fabs(x - x0) > eps);
    
    return x;
}


// Нахождение sqrt2 с помощью предела
double func_sqrt2_limit(double eps)
{
    eps = eps > 1e-15? eps: 1e-15;

    double x = 0.5, x0;
    do {
        x0 = x;
        x = x0 - (x0 * x0) / 2 + 1;
    } while (fabs(x - x0) > eps );

    return x;

}

// Нахождение sqrt2 с помощью произведения ряда
double func_sqrt2_series(double eps) 
{
    int k = 2;
    double x0;
    double x = pow(2, pow(2, -k));
    double product = x;
    do {
        x0 = x;
        x = sqrt(x0);
        product *= x;
    } while (fabs(x - x0) > eps);
    
    return product;
}


// Нахождение sqrt2 с помощью специального уравнения
double func_sqrt2_equation(double eps)
{
    double x_prev = 1.0;
    double x = 1.0;
    
    do {
        x_prev = x;
        x = (x_prev + 2.0 / x_prev) / 2.0;
    } while (fabs(x - x_prev) > eps);
    
    return x;
}


// Нахождение y с помощью предела
double func_y_limit(double eps)
{
    eps = eps > 1e-15? eps: 1e-15;
    long long int Factorial[20];
    func_Factorial(Factorial);
    int m = 10;
    int k;
    double sum_pred;
    double sum_next = 0;
    double sum0;
    do {
        k = 0;
        sum_pred = sum_next;
        sum_next = 0;
        for (k = 1; k <= m; k++) {
            sum0 = (combination(m, k, Factorial) * log(Factorial[k])) / k;
            sum0 *= k % 2 == 0? 1: -1;
            sum_next += sum0;
        }
        m++;
    } while (fabs(fabs(sum_next) - fabs(sum_pred)) > eps && m <= 19 && k <= 19);

    return sum_next;
}


// Заполнение списка факториалалами чисел
void func_Factorial(long long int * Factorial)
{
    Factorial[0] = 1;
    int i;
    for (i = 1; i <= 20; i++)
        Factorial[i] = Factorial[i - 1] * i;
}


// Вычисления значения С - сочетания
long long combination(long long m, long long k, long long Factorial[])
{
    return Factorial[m] / (Factorial[m - k] * Factorial[k]);
}


// Нахождение sqrt2 с помощью произведения ряда
double func_y_series(double eps, double pi_series) 
{
    double sum_pred;
    double sum_next = 0;
    double k = 2;
    double sum = 0;
    long long int_k;
    do {
        sum += sum_pred;
        sum_pred = sum_next;
        int_k = sqrt(k);
        sum_next = (1.0 / (int_k * int_k)) - (1 / k);
        k++;
    } while (fabs(sum_next - sum_pred) > eps && k < 100000);
    
    return sum - ((pi_series * pi_series) / 6);
}


double func_y_equation(double eps)
{
    long long simple_numbers[1000];
    func(1000, simple_numbers);

    double product = 1.0;
    double prev_value = 0.0;
    double current_value = 0.0;
    int t = 2;
    int max_t = 1000000; 
    
    do {
        prev_value = current_value;
        product = 1.0;
        int i = 0;
        while (simple_numbers[i] > 0 && simple_numbers[i] <= t && i < 1000) {
            product *= (simple_numbers[i] - 1.0) / simple_numbers[i];
            i++;
        }
        current_value = -log(t) * product;
        if (t > max_t) break;
        t *= 2;
        
    } while (fabs(current_value - prev_value) > eps && t <= max_t);
    
    return current_value;
}


// Заполняет данный массив простыми числами до определённого номера
int func(const int n, long long * simple_numbers)
{
    if (n <= 0 || n > 1000) return 0;
    
    int len = 0;
    simple_numbers[0] = 2;
    len++;
    
    for (int i = 3; len < n; i += 2) {
        int is_simple = 1;
        for (int j = 0; j < len && simple_numbers[j] * simple_numbers[j] <= i; j++) {
            if (i % simple_numbers[j] == 0) {
                is_simple = 0;
                break;
            }
        }
        if (is_simple) {
            simple_numbers[len] = i;
            len++;
        }
    }
    
    return len;
}

// Определяет, простое ли число
int simple(int x, long long * simple_numbers, int len)
{
    if (x < 2) return len;
    
    for (int i = 0; i < len && simple_numbers[i] * simple_numbers[i] <= x; i++) {
        if (x % simple_numbers[i] == 0) {
            return len;
        }
    }
    
    if (len < 1000) {
        simple_numbers[len] = x;
        len++;
    }
    return len;
}