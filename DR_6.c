/* DR_7.c — Розділ 7. Домашня робота (C)
   Студент: Фархад Фаталієв
   Плейсхолдери умов — замінити на точні формулювання з methodicalCPP.pdf
*/

#include <stdio.h>

/* Умова: 7.9б */
void task_7_9(){ printf("[task_7_9] Плейсхолдер для 7.9б/7.10е.\n"); }

/* Умова: 7.10е */
void task_7_10(){ printf("[task_7_10] Плейсхолдер для 7.10е.\n"); }

static void printMenu(){ puts("\n=== DR Розділ 7 (C) ==="); puts("1 - task_7_9"); puts("2 - task_7_10"); puts("0 - вихід"); printf("Оберіть завдання: "); }

int main(void){ int choice; while(1){ printMenu(); if(scanf("%d", &choice)!=1){ int ch; while((ch=getchar())!=EOF && ch!='\n'); printf("Некоректний ввід\n"); continue; } switch(choice){ case 1: task_7_9(); break; case 2: task_7_10(); break; case 0: return 0; default: printf("Немає такого пункту.\n"); } } }
