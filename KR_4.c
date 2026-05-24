/* KR_4.c — Розділ 4. Класна робота (C)
   Студент: Фархад Фаталієв
   Увага: коментарі-плейсхолдери "Умова: ..." потрібно замінити на точні формулювання з methodicalCPP.pdf
*/

#include <stdio.h>
#include <stdlib.h>

/* Умова: (потрібно вставити точний текст умови з methodicalCPP.pdf для завдання 4.1) */
void task_4_1() {
    printf("[task_4_1] Плейсхолдер. Введіть число: ");
    double x; if (scanf("%lf", &x)!=1) { printf("Невірний ввід\n"); return; }
    printf("Ви ввели: %.6f\n", x);
}

/* Умова: (потрібно вставити точний текст умови з methodicalCPP.pdf для завдання 4.2) */
void task_4_2() { printf("[task_4_2] Плейсхолдер.\n"); }

/* Умова: ... для 4.3 */
void task_4_3() { printf("[task_4_3] Плейсхолдер.\n"); }

/* Умова: ... для 4.4 */
void task_4_4() { printf("[task_4_4] Плейсхолдер.\n"); }

/* Умова: ... для 4.5 */
void task_4_5() { printf("[task_4_5] Плейсхолдер.\n"); }

/* Умова: ... для 4.6 */
void task_4_6() { printf("[task_4_6] Плейсхолдер.\n"); }

/* Умова: ... для 4.7 */
void task_4_7() { printf("[task_4_7] Плейсхолдер.\n"); }

/* Умова: ... для 4.8 */
void task_4_8() { printf("[task_4_8] Плейсхолдер.\n"); }

/* Умова: ... для 4.9 */
void task_4_9() { printf("[task_4_9] Плейсхолдер.\n"); }

/* Умова: ... для 4.10 */
void task_4_10() { printf("[task_4_10] Плейсхолдер.\n"); }

/* Умова: ... для 4.11 */
void task_4_11() { printf("[task_4_11] Плейсхолдер.\n"); }

/* Умова: ... для 4.12 */
void task_4_12() { printf("[task_4_12] Плейсхолдер.\n"); }

static void printMenu() {
    puts("\n=== KR Розділ 4 (C) ===");
    puts("1  - task_4_1");
    puts("2  - task_4_2");
    puts("3  - task_4_3");
    puts("4  - task_4_4");
    puts("5  - task_4_5");
    puts("6  - task_4_6");
    puts("7  - task_4_7");
    puts("8  - task_4_8");
    puts("9  - task_4_9");
    puts("10 - task_4_10");
    puts("11 - task_4_11");
    puts("12 - task_4_12");
    puts("0  - вихід");
    printf("Оберіть завдання: ");
}

int main(void) {
    int choice = -1;
    while (1) {
        printMenu();
        if (scanf("%d", &choice)!=1) { printf("Некоректний ввід\n"); int ch; while((ch=getchar())!=EOF && ch!='\n'); continue; }
        switch (choice) {
            case 1: task_4_1(); break;
            case 2: task_4_2(); break;
            case 3: task_4_3(); break;
            case 4: task_4_4(); break;
            case 5: task_4_5(); break;
            case 6: task_4_6(); break;
            case 7: task_4_7(); break;
            case 8: task_4_8(); break;
            case 9: task_4_9(); break;
            case 10: task_4_10(); break;
            case 11: task_4_11(); break;
            case 12: task_4_12(); break;
            case 0: return 0;
            default: printf("Немає такого пункту.\n");
        }
    }
}
