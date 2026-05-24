/* DR_2.c — Розділ 2. Домашня робота (2.14, 2.17e) — C-версія
   Студент: Фархад Фаталієв
*/

#include <stdio.h>
#include <math.h>
#include <stdlib.h>

/* Завдання 2.14. Корені квадратного рівняння ax^2+bx+c=0 */
void task_2_14() {
    double a, b, c;
    printf("a b c: "); if (scanf("%lf %lf %lf", &a, &b, &c) != 3) { fprintf(stderr, "Невірний ввід\n"); return; }
    if (a == 0.0) { printf("Це не квадратне рівняння (a=0).\n"); return; }
    double D = b*b - 4*a*c;
    if (D < 0) { printf("Дискримінант < 0 — дійсних коренів немає.\n"); return; }
    double sqrtD = sqrt(D);
    double x1 = (-b + sqrtD)/(2*a);
    double x2 = (-b - sqrtD)/(2*a);
    printf("D = %f\n", D);
    printf("x1 = %f\n", x1);
    printf("x2 = %f\n", x2);

    printf("\nПеревірка (a=3, b=100, c=2):\n");
    double ta=3, tb=100, tc=2; double tD = tb*tb - 4*ta*tc; double tx1 = (-tb + sqrt(tD))/(2*ta); double tx2 = (-tb - sqrt(tD))/(2*ta);
    printf("x1 = %f, x2 = %f\n", tx1, tx2);
}

/* Завдання 2.17e. sigmoid(x) і похідна */
static double sigmoid(double x) { return 1.0 / (1.0 + exp(-x)); }
static double sigmoid_derivative(double x) { double s = sigmoid(x); return s * (1.0 - s); }
void task_2_17e() { double x; printf("x = "); if (scanf("%lf", &x) != 1) { fprintf(stderr, "Невірний ввід\n"); return; } printf("sigmoid(x) = %f\n", sigmoid(x)); printf("sigmoid'(x) = %f\n", sigmoid_derivative(x)); }

static void printMenu() { puts("\n=== DR Розділ 2 (C) ==="); puts("1 - task_2_14"); puts("2 - task_2_17e"); puts("0 - вихід"); printf("Оберіть: "); }
int main(void) { int c; while(1){ printMenu(); if (scanf("%d", &c) != 1) { int ch; while((ch=getchar())!=EOF && ch!='\n'); printf("Некоректний ввід\n"); continue; } switch(c){ case 1: task_2_14(); break; case 2: task_2_17e(); break; case 0: return 0; default: printf("Немає такого пункту.\n"); } int ch; while((ch=getchar())!=EOF && ch!='\n'); } }
