/* DR_3.c — Розділ 3. Домашня робота (3.14, 3.23в) — C-версія
   Студент: Фархад Фаталієв
*/

#include <stdio.h>
#include <math.h>
#include <stdlib.h>

/* 3.14. Число точок перетину кола x^2+y^2=r^2 з відрізком x=a, b<=y<=b+c^2. */
void task_3_14() {
    double r,a,b,c;
    printf("r a b c: "); if (scanf("%lf %lf %lf %lf", &r, &a, &b, &c) != 4) { fprintf(stderr, "Невірний ввід\n"); return; }
    double yMax = b + c * c;
    if (fabs(a) > r) { printf("0 точок перетину.\n"); return; }
    double yCircle = sqrt(r*r - a*a);
    int count = 0;
    if (yCircle >= b && yCircle <= yMax) count++;
    if (-yCircle >= b && -yCircle <= yMax && yCircle != 0) count++;
    if (fabs(a*a + b*b - r*r) < 1e-9) count++;
    if (fabs(a*a + yMax*yMax - r*r) < 1e-9) count++;
    printf("Орієнтовна кількість точок перетину: %d\n", count);
    printf("y на колі: ±%f, відрізок y: [%f, %f]\n", yCircle, b, yMax);
}

/* 3.23в) leakyReLu(x,a): x при x>=0, a*x при x<0. */
double leakyReLu(double x, double alpha) { return x >= 0 ? x : alpha * x; }
double leakyReLu_derivative(double x, double alpha) { return x >= 0 ? 1.0 : alpha; }
void task_3_23v() { double x,a; printf("x alpha: "); if (scanf("%lf %lf", &x, &a) != 2) { fprintf(stderr, "Невірний ввід\n"); return; } printf("leakyReLu = %f\n", leakyReLu(x,a)); printf("leakyReLu' = %f\n", leakyReLu_derivative(x,a)); }

static void printMenu() { puts("\n=== DR Розділ 3 (C) ==="); puts("1 - task_3_14"); puts("2 - task_3_23v"); puts("0 - вихід"); printf("Оберіть: "); }
int main(void) { int c; while (1) { printMenu(); if (scanf("%d", &c) != 1) { int ch; while((ch=getchar())!=EOF && ch!='\n'); printf("Некоректний ввід\n"); continue; } switch(c){ case 1: task_3_14(); break; case 2: task_3_23v(); break; case 0: return 0; default: printf("?\n"); } int ch; while((ch=getchar())!=EOF && ch!='\n'); } }
