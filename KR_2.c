/* KR_2.c — Розділ 2. Класна робота (2.1–2.6) — C-версія
   Студент: Фархад Фаталієв
*/

#include <stdio.h>
#include <math.h>
#include <stdlib.h>

/* Завдання 2.1. Ввести дійсне x і обчислити cos(x) */
void task_2_1() {
    double x;
    printf("x (радіани): "); if (scanf("%lf", &x) != 1) { fprintf(stderr, "Невірний ввід\n"); return; }
    printf("cos(x) = %f\n", cos(x));
}

/* Завдання 2.2. Обчислити гіпотенузу c за катетами a, b */
void task_2_2() {
    double a, b;
    printf("a = "); if (scanf("%lf", &a) != 1) { fprintf(stderr, "Невірний ввід\n"); return; }
    printf("b = "); if (scanf("%lf", &b) != 1) { fprintf(stderr, "Невірний ввід\n"); return; }
    printf("c = %f\n", hypot(a, b));
}

/* Завдання 2.3. Площа трикутника за трьома сторонами (формула Герона) */
void task_2_3() {
    double a, b, c;
    printf("a = "); if (scanf("%lf", &a) != 1) { fprintf(stderr, "Невірний ввід\n"); return; }
    printf("b = "); if (scanf("%lf", &b) != 1) { fprintf(stderr, "Невірний ввід\n"); return; }
    printf("c = "); if (scanf("%lf", &c) != 1) { fprintf(stderr, "Невірний ввід\n"); return; }
    double p = (a + b + c) / 2.0;
    double under = p * (p - a) * (p - b) * (p - c);
    if (under < 0) { printf("Трикутник не існує.\n"); return; }
    printf("S = %f\n", sqrt(under));
}

static double poly_a(double x) { return x*x*x*x + 2*x*x + 1; }
static double poly_b(double x) { return x*x*x*x + x*x*x + x*x + x + 1; }
static double poly_v(double x) { double x2=x*x,x3=x2*x,x4=x2*x2,x5=x4*x; return x5+5*x4+10*x3+10*x2+5*x+1; }
static double poly_g(double x) { double x3=x*x*x; double x9 = x3*x3*x3; return x9 + x3 + 1; }
static double poly_d(double x) { double x2=x*x,x3=x2*x,x4=x2*x2; return 16*x4 + 8*x3 + 4*x2 + 2*x + 1; }
static double poly_e(double x) { double x2=x*x,x3=x2*x,x5=x3*x2; return x5 + x3 + x; }

/* Завдання 2.4. Обчислення многочленів */
void task_2_4() {
    double x; printf("x = "); if (scanf("%lf", &x) != 1) { fprintf(stderr, "Невірний ввід\n"); return; }
    printf("а) y = x^4+2x^2+1 = %f\n", poly_a(x));
    printf("б) y = x^4+x^3+x^2+x+1 = %f\n", poly_b(x));
    printf("в) y = (x+1)^5 = %f\n", poly_v(x));
    printf("г) y = x^9+x^3+1 = %f\n", poly_g(x));
    printf("д) y = 16x^4+8x^3+4x^2+2x+1 = %f\n", poly_d(x));
    printf("е) y = x^5+x^3+x = %f\n", poly_e(x));
}

/* Завдання 2.5. Rosenbrock2d */
static double Rosenbrock2d(double x, double y) { return 100.0 * pow(x*x - y, 2) + pow(x - 1.0, 2); }
void task_2_5() {
    for (int i = 0; i < 3; ++i) {
        double x, y; printf("Пара %d — x y: ", i+1); if (scanf("%lf %lf", &x, &y) != 2) { fprintf(stderr, "Невірний ввід\n"); return; }
        printf("Rosenbrock2d(%f, %f) = %f\n", x, y, Rosenbrock2d(x, y));
    }
}

/* Завдання 2.6. Трикутник за координатами вершин */
static double dist(double x1,double y1,double x2,double y2){ return hypot(x1-x2,y1-y2); }
static double triangleAreaBySides(double a,double b,double c){ double p=(a+b+c)/2.0; double u=p*(p-a)*(p-b)*(p-c); return u<0?-1.0:sqrt(u); }
void task_2_6() {
    double ax,ay,bx,by,cx,cy;
    printf("Координати A (x y): "); if (scanf("%lf %lf", &ax, &ay) != 2) { fprintf(stderr, "Невірний ввід\n"); return; }
    printf("Координати B (x y): "); if (scanf("%lf %lf", &bx, &by) != 2) { fprintf(stderr, "Невірний ввід\n"); return; }
    printf("Координати C (x y): "); if (scanf("%lf %lf", &cx, &cy) != 2) { fprintf(stderr, "Невірний ввід\n"); return; }
    double ab = dist(ax,ay,bx,by); double bc = dist(bx,by,cx,cy); double ca = dist(cx,cy,ax,ay);
    double S = triangleAreaBySides(ab,bc,ca);
    if (S < 0) { printf("Некоректний трикутник.\n"); }
    else { printf("Сторони: AB=%f, BC=%f, CA=%f\n", ab, bc, ca); printf("Площа S = %f\n", S); }
}

static void printMenu(){ puts("\n=== KR Розділ 2 (C) ==="); puts("1 - task_2_1"); puts("2 - task_2_2"); puts("3 - task_2_3"); puts("4 - task_2_4"); puts("5 - task_2_5"); puts("6 - task_2_6"); puts("0 - вихід"); printf("Оберіть: "); }

int main(void){ int c; while(1){ printMenu(); if (scanf("%d", &c) != 1) { int ch; while((ch=getchar())!=EOF && ch!='\n'); printf("Некоректний ввід\n"); continue; } switch(c){ case 1: task_2_1(); break; case 2: task_2_2(); break; case 3: task_2_3(); break; case 4: task_2_4(); break; case 5: task_2_5(); break; case 6: task_2_6(); break; case 0: return 0; default: printf("Немає такого пункту.\n"); } int ch; while((ch=getchar())!=EOF && ch!='\n'); } }
