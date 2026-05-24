/* DR_9.c — Розділ 9. Домашня робота (C)
   Студент: Фархад Фаталієв
*/

#include <stdio.h>

/* Умова: 9.9ц */
void task_9_9c(){ printf("[task_9_9c] Плейсхолдер для 9.9ц.\n"); }

/* Умова: 9.9у */
void task_9_9u(){ printf("[task_9_9u] Плейсхолдер для 9.9у.\n"); }

static void printMenu(){ puts("\n=== DR Розділ 9 (C) ==="); puts("1 - task_9_9c"); puts("2 - task_9_9u"); puts("0 - вихід"); printf("Оберіть завдання: "); }

int main(void){ int choice; while(1){ printMenu(); if(scanf("%d", &choice)!=1){ int ch; while((ch=getchar())!=EOF && ch!='\n'); printf("Некоректний ввід\n"); continue; } switch(choice){ case 1: task_9_9c(); break; case 2: task_9_9u(); break; case 0: return 0; default: printf("Немає такого пункту.\n"); } } }
