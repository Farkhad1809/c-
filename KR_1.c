/* KR_1.c — Розділ 1. Класна робота (завдання 1.1–1.9) — C-версія
   Студент: Фархад Фаталієв
*/

#include <stdio.h>
#include <math.h>
#include <stdlib.h>

/* Завдання 1.1. Обчислити наступні математичні вирази та вивести результати:
   2+31; 45*54-11; 15/4; 15.0/4; 67%5; (2*45.1 +3.2)/2
*/
void task_1_1() {
    printf("2+31 = %d\n", 2 + 31);
    printf("45*54-11 = %d\n", 45 * 54 - 11);
    printf("15/4 = %d (цілочисельний)\n", 15 / 4);
    printf("15.0/4 = %.6f\n", 15.0 / 4);
    printf("67%%5 = %d\n", 67 % 5);
    printf("(2*45.1 +3.2)/2 = %.6f\n", (2.0 * 45.1 + 3.2) / 2.0);
}

/* Завдання 1.2. Ініціалізувати числа як float, double та long double:
   10^-4, 24.33E5, pi, e, sqrt(5), ln(100) — вивести з 2 знаками після коми.
*/
void task_1_2() {
    float a = 1e-4f;
    double b = 24.33E5;
    long double c = (long double)M_PI;
    long double d = (long double)M_E;
    double root5 = sqrt(5.0);
    double ln100 = log(100.0);

    printf("float 10^-4 = %.2f\n", a);
    printf("double 24.33E5 = %.2f\n", b);
    printf("long double pi = %.2Lf\n", c);
    printf("long double e = %.2Lf\n", d);
    printf("sqrt(5) = %.2f\n", root5);
    printf("ln(100) = %.2f\n", ln100);
}

/* Завдання 1.3. Вивести на екран текст (хрест з символу a, введеного з клавіатури)
*/
void task_1_3() {
    int ch = 0;
    printf("Введіть символ a: ");
    while ((ch = getchar()) != EOF) {
        if (ch == '\n') continue;
        break;
    }
    if (ch == EOF) return;
    char a = (char)ch;
    printf("  - %c - %c - %c\n", a, a, a);
    printf("  %c | %c | %c\n", a, a, a);
    printf("  - %c - %c - %c\n", a, a, a);
    /* Очистити залишок рядка */
    int c; while ((c = getchar()) != EOF && c != '\n');
}

/* Завдання 1.4. Обчислити силу притягання F = gamma*m1*m2/r^2, gamma = 6.673e-11
*/
void task_1_4() {
    const double gamma = 6.673e-11;
    double m1, m2, r;
    printf("m1 (кг): "); if (scanf("%lf", &m1) != 1) { fprintf(stderr, "Невірний ввід\n"); return; }
    printf("m2 (кг): "); if (scanf("%lf", &m2) != 1) { fprintf(stderr, "Невірний ввід\n"); return; }
    printf("r (м): ");  if (scanf("%lf", &r)  != 1) { fprintf(stderr, "Невірний ввід\n"); return; }
    if (r == 0.0) { printf("Помилка: r не може бути 0.\n"); return; }
    double F = gamma * m1 * m2 / (r * r);
    printf("F=%.*e\n", 3, F);
}

/* Завдання 1.5. Дано x. Лише множенням отримати степені: x^4, x^6, x^9, x^15, x^28, x^64
*/
void task_1_5() {
    double x;
    printf("x = "); if (scanf("%lf", &x) != 1) { fprintf(stderr, "Невірний ввід\n"); return; }
    double x2 = x * x;
    double x4 = x2 * x2;
    double x6 = x4 * x2;
    double x3 = x2 * x;
    double x9 = x6 * x3;
    double x15 = x9 * x6;
    double x28 = x15 * x9 * x4;
    double x64 = x28 * x28 * x4 * x4;
    printf("x^4 = %.4f\n", x4);
    printf("x^6 = %.4f\n", x6);
    printf("x^9 = %.4f\n", x9);
    printf("x^15 = %.4f\n", x15);
    printf("x^28 = %.4f\n", x28);
    printf("x^64 = %.4f\n", x64);
}

/* Завдання 1.6. Перетворення Цельсій->Фаренгейт */
void task_1_6() {
    double C;
    printf("Введіть температуру в градусах Цельсія C: "); if (scanf("%lf", &C) != 1) { fprintf(stderr, "Невірний ввід\n"); return; }
    double F = 9.0 * C / 5.0 + 32.0;
    printf("F=%g\n", F);
}

/* Завдання 1.7. Ввести x; обчислити цілу та дробову частини, ceil, floor, round */
void task_1_7() {
    double x;
    printf("x = "); if (scanf("%lf", &x) != 1) { fprintf(stderr, "Невірний ввід\n"); return; }
    double whole = trunc(x);
    double frac = x - whole;
    double ceilVal = ceil(x);
    double floorVal = floor(x);
    double roundVal = round(x);
    printf("Ціла частина (trunc): %.4f\n", whole);
    printf("Дробова частина: %.4f\n", frac);
    printf("ceil: %.0f, floor: %.0f, round: %.0f\n", ceilVal, floorVal, roundVal);
}

/* Завдання 1.8. Два дійсних числа, різниця та добуток */
void task_1_8() {
    double a, b;
    printf("Перше число: "); if (scanf("%lf", &a) != 1) { fprintf(stderr, "Невірний ввід\n"); return; }
    printf("Друге число: "); if (scanf("%lf", &b) != 1) { fprintf(stderr, "Невірний ввід\n"); return; }
    printf("Різниця = %.2f\n", a - b);
    printf("Добуток = %.2f\n", a * b);
}

/* Завдання 1.9. Два числа — середнє арифметичне та гармонічне */
void task_1_9() {
    double a, b;
    printf("Два числа через пробіл: "); if (scanf("%lf %lf", &a, &b) != 2) { fprintf(stderr, "Невірний ввід\n"); return; }
    if (a == 0.0 || b == 0.0 || (a + b) == 0.0) {
        printf("Неможливо обчислити гармонічне середнє (є нуль або сума = 0).\n");
        return;
    }
    double arith = (a + b) / 2.0;
    double harm = 2.0 * a * b / (a + b);
    printf("Арифметичне (десятковий): %.6f\n", arith);
    printf("Гармонічне (десятковий): %.6f\n", harm);
    printf("Арифметичне (науковий): %e\n", arith);
    printf("Гармонічне (науковий): %e\n", harm);
}

static void printMenu() {
    puts("\n=== KR Розділ 1 (C) ===");
    puts("1 - task_1_1");
    puts("2 - task_1_2");
    puts("3 - task_1_3");
    puts("4 - task_1_4");
    puts("5 - task_1_5");
    puts("6 - task_1_6");
    puts("7 - task_1_7");
    puts("8 - task_1_8");
    puts("9 - task_1_9");
    puts("0 - вихід");
    printf("Оберіть завдання: ");
}

int main(void) {
    int choice = -1;
    while (1) {
        printMenu();
        if (scanf("%d", &choice) != 1) { printf("Некоректний ввід\n"); int c; while ((c = getchar()) != EOF && c != '\n'); continue; }
        switch (choice) {
            case 1: task_1_1(); break;
            case 2: task_1_2(); break;
            case 3: task_1_3(); break;
            case 4: task_1_4(); break;
            case 5: task_1_5(); break;
            case 6: task_1_6(); break;
            case 7: task_1_7(); break;
            case 8: task_1_8(); break;
            case 9: task_1_9(); break;
            case 0: return 0;
            default: printf("Немає такого пункту.\n");
        }
        int c; while ((c = getchar()) != EOF && c != '\n');
    }
}
