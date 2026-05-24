/* DR_4.c — Розділ 4. Домашня робота (C)
   Студент: Фархад Фаталієв
   Плейсхолдери умов — замінити на точні формулювання з methodicalCPP.pdf
*/

#include <stdio.h>
#include <stdlib.h>

/* Умова: (4.18д) */
void task_4_18() { printf("[task_4_18] Плейсхолдер для домашнього завдання 4.18д.\n"); }

/* Умова: (4.27г) */
void task_4_27() { printf("[task_4_27] Плейсхолдер для домашнього завдання 4.27г.\n"); }

static void printMenu() {
    puts("\n=== DR Розділ 4 (C) ===");
    puts("1 - task_4_18");
    puts("2 - task_4_27");
    puts("0 - вихід");
    printf("Оберіть завдання: ");
}

int main(void) {
    int choice = -1;
    while (1) {
        printMenu();
        if (scanf("%d", &choice)!=1) { printf("Некоректний ввід\n"); int ch; while((ch=getchar())!=EOF && ch!='\n'); continue; }
        switch (choice) {
            case 1: task_4_18(); break;
            case 2: task_4_27(); break;
            case 0: return 0;
            default: printf("Немає такого пункту.\n");
        }
    }
}
