/* KR_3.c — Розділ 3. Класна робота (3.1–3.7) — C-версія
   Студент: Фархад Фаталієв
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/* 3.1. Натуральне тризначне число: одиниці, десятки, сотні; сума цифр; число справа наліво. */
void task_3_1() {
    int n;
    printf("Тризначне натуральне n: "); if (scanf("%d", &n) != 1) { fprintf(stderr, "Невірний ввід\n"); return; }
    if (n < 100 || n > 999) { printf("Потрібне тризначне число.\n"); return; }
    int ones = n % 10;
    int tens = (n / 10) % 10;
    int hundreds = n / 100;
    int sum = ones + tens + hundreds;
    int reversed = ones*100 + tens*10 + hundreds;
    printf("Одиниці: %d, десятки: %d, сотні: %d\n", ones, tens, hundreds);
    printf("Сума цифр: %d\n", sum);
    printf("Справа наліво: %d\n", reversed);
}

/* 3.2. Тризначне n: якщо всі цифри різні — вивести всі перестановки. */
void task_3_2() {
    int n; printf("Тризначне n: "); if (scanf("%d", &n) != 1) { fprintf(stderr, "Невірний ввід\n"); return; }
    if (n < 100 || n > 999) { printf("Потрібне тризначне число.\n"); return; }
    int d0 = n/100, d1 = (n/10)%10, d2 = n%10;
    if (d0==d1 || d0==d2 || d1==d2) { printf("Не всі цифри різні — перестановки не виводяться.\n"); return; }
    int perms[6][3] = {{d0,d1,d2},{d0,d2,d1},{d1,d0,d2},{d1,d2,d0},{d2,d0,d1},{d2,d1,d0}};
    printf("Перестановки:\n");
    for (int i=0;i<6;++i) printf("%d\n", perms[i][0]*100 + perms[i][1]*10 + perms[i][2]);
}

/* 3.3. Три цілих через кому; добуток якщо всі |x| < bound. */
void task_3_3() {
    int a,b,c; char comma1, comma2;
    printf("a,b,c: ");
    /* Зчитуємо у форматі a,b,c */
    if (scanf("%d %c %d %c %d", &a, &comma1, &b, &comma2, &c) != 5 || comma1!=',' || comma2!=',') { printf("Формат: a,b,c\n"); return; }
    int bound; printf("Межа модулю (210 або 221): "); if (scanf("%d", &bound) != 1) { fprintf(stderr, "Невірний ввід\n"); return; }
    if (abs(a) < bound && abs(b) < bound && abs(c) < bound) printf("Добуток = %lld\n", (long long)a * b * c);
    else printf("Умова |xi| < %d не виконана.\n", bound);
}

/* 3.4. Добуток двох 8-бітних як 16-бітне */
unsigned multiply8to16(unsigned char u, unsigned char v) { return (unsigned)u * (unsigned)v; }
void task_3_4() {
    unsigned u,v; printf("u v (0..255): "); if (scanf("%u %u", &u, &v) != 2) { fprintf(stderr, "Невірний ввід\n"); return; }
    if (u > 255 || v > 255) { printf("Поза діапазоном 8 біт.\n"); return; }
    unsigned prod = multiply8to16((unsigned char)u, (unsigned char)v);
    printf("Добуток (16 біт) = %u\n", prod);
}

/* 3.5. Більше та менше з двох чисел. */
void task_3_5() {
    double a,b; if (scanf("%lf %lf", &a, &b) != 2) { fprintf(stderr, "Невірний ввід\n"); return; }
    if (a > b) printf("Більше: %g, менше: %g\n", a, b);
    else if (a < b) printf("Більше: %g, менше: %g\n", b, a);
    else printf("Числа рівні.\n");
}

/* 3.6. Три дійсних: найбільше та найменше за модулем. */
void task_3_6() {
    double a,b,c; if (scanf("%lf %lf %lf", &a, &b, &c) != 3) { fprintf(stderr, "Невірний ввід\n"); return; }
    double vals[3] = {a,b,c};
    double maxAbs = vals[0], minAbs = vals[0];
    for (int i=0;i<3;++i){ if (fabs(vals[i]) > fabs(maxAbs)) maxAbs = vals[i]; if (fabs(vals[i]) < fabs(minAbs)) minAbs = vals[i]; }
    printf("Найбільше за |.|: %g\n", maxAbs);
    printf("Найменше за |.|: %g\n", minAbs);
}

/* 3.7. Розв'язки квадратних та біквадратних рівнянь */
void solveQuad(double a,double b,double c){ if (a==0){ if (b==0) printf(c==0?"Нескінченно багато розв'язків.\n":"Розв'язків немає.\n"); else printf("1 розв'язок: x = %f\n", -c/b); return; } double D=b*b-4*a*c; if (D<0) printf("0 дійсних розв'язків (D<0).\n"); else if (D==0) printf("1 розв'язок: x = %f\n", -b/(2*a)); else { double sd=sqrt(D); printf("2 розв'язки: x1 = %f, x2 = %f\n", (-b+sd)/(2*a), (-b-sd)/(2*a)); } }
void task_3_7(){ char sub; printf("Підпункт (а/б): "); if (scanf(" %c", &sub) != 1) { fprintf(stderr, "Невірний ввід\n"); return; } double a,b,c; printf("a b c: "); if (scanf("%lf %lf %lf", &a, &b, &c) != 3) { fprintf(stderr, "Невірний ввід\n"); return; } if (sub=='a' || sub=='A') solveQuad(a,b,c); else { solveQuad(a,b,c); printf("(Для x: якщо t>=0, x=±sqrt(t))\n"); } }

static void printMenu(){ puts("\n=== KR Розділ 3 (C) ==="); puts("1 - task_3_1"); puts("2 - task_3_2"); puts("3 - task_3_3"); puts("4 - task_3_4"); puts("5 - task_3_5"); puts("6 - task_3_6"); puts("7 - task_3_7"); puts("0 - вихід"); printf("Оберіть: "); }
int main(void){ int c; while(1){ printMenu(); if (scanf("%d", &c) != 1) { int ch; while((ch=getchar())!=EOF && ch!='\n'); printf("Некоректний ввід\n"); continue; } switch(c){ case 1: task_3_1(); break; case 2: task_3_2(); break; case 3: task_3_3(); break; case 4: task_3_4(); break; case 5: task_3_5(); break; case 6: task_3_6(); break; case 7: task_3_7(); break; case 0: return 0; default: printf("Немає такого пункту.\n"); } int ch; while((ch=getchar())!=EOF && ch!='\n'); } }
