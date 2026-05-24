/* DR_1.c — Розділ 1. Домашня робота (завдання 1.11, 1.18) — C-версія
   Студент: Фархад Фаталієв
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/* Завдання 1.11. Ініціалізувати два рядки та вивести в форматі: !!! s1 , s2 !!! */
void task_1_11() {
    char s1[256] = "Hello";
    char s2[256] = "World!";
    char buf[256];
    int ch;
    printf("Рядок 1 (натисніть Enter щоб залишити '%s'): ", s1);
    if (fgets(buf, sizeof(buf), stdin) != NULL) {
        if (buf[0] != '\n') {
            buf[strcspn(buf, "\n")] = 0;
            strncpy(s1, buf, sizeof(s1)-1);
            s1[sizeof(s1)-1] = 0;
        }
    }
    printf("Рядок 2 (натисніть Enter щоб залишити '%s'): ", s2);
    if (fgets(buf, sizeof(buf), stdin) != NULL) {
        if (buf[0] != '\n') {
            buf[strcspn(buf, "\n")] = 0;
            strncpy(s2, buf, sizeof(s2)-1);
            s2[sizeof(s2)-1] = 0;
        }
    }
    printf("!!! %s , %s !!!\n", s1, s2);
}

/* Завдання 1.18. Позиція в грі 'Хрестики-нулики' — 9 символів, показати поле */
void task_1_18() {
    char cells[10] = "         ";
    char input[64];
    printf("Введіть 9 символів (' ', 'O', 'X') без пробілів (або натисніть Enter для поодинокого вводу):\n");
    if (fgets(input, sizeof(input), stdin) != NULL) {
        size_t n = strlen(input);
        if (n > 0 && input[n-1] == '\n') input[--n] = '\0';
        if (n == 9) {
            for (int i = 0; i < 9; ++i) {
                char ch = input[i];
                if (ch == 'O' || ch == 'X' || ch == ' ') cells[i] = ch;
            }
        } else {
            for (int i = 0; i < 9; ++i) {
                printf("[%d]: ", i);
                int c = getchar();
                while (c == '\n') c = getchar();
                if (c == EOF) { cells[i] = ' '; break; }
                cells[i] = (char)c;
                int skip; while ((skip = getchar()) != EOF && skip != '\n');
            }
        }
    }
    printf("%c | %c | %c\n", cells[0], cells[1], cells[2]);
    printf("---------\n");
    printf("%c | %c | %c\n", cells[3], cells[4], cells[5]);
    printf("---------\n");
    printf("%c | %c | %c\n", cells[6], cells[7], cells[8]);
}

static void printMenu() {
    puts("\n=== DR Розділ 1 (C) ===");
    puts("1 - task_1_11");
    puts("2 - task_1_18");
    puts("0 - вихід");
    printf("Оберіть завдання: ");
}

int main(void) {
    int choice = -1;
    while (1) {
        printMenu();
        if (scanf("%d", &choice) != 1) { printf("Некоректний ввід\n"); int c; while ((c = getchar()) != EOF && c != '\n'); continue; }
        int c; while ((c = getchar()) != EOF && c != '\n');
        switch (choice) {
            case 1: task_1_11(); break;
            case 2: task_1_18(); break;
            case 0: return 0;
            default: printf("Немає такого пункту.\n");
        }
    }
}
