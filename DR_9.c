/* DR_10.c — Розділ 10. Домашня робота (C)
   Студент: Фархад Фаталієв
*/

#include <stdio.h>

/* 10.6г */
void task_10_6g(){ printf("[task_10_6g] Плейсхолдер для 10.6г.\n"); }

/* 10.11 */
void task_10_11(){ printf("[task_10_11] Плейсхолдер для 10.11.\n"); }

static void printMenu(){ puts("\n=== DR Розділ 10 (C) ==="); puts("1 - task_10_6g"); puts("2 - task_10_11"); puts("0 - вихід"); printf("Оберіть завдання: "); }

int main(void){ int choice; while(1){ printMenu(); if(scanf("%d", &choice)!=1){ int ch; while((ch=getchar())!=EOF && ch!='\n'); printf("Некоректний ввід\n"); continue; } switch(choice){ case 1: task_10_6g(); break; case 2: task_10_11(); break; case 0: return 0; default: printf("Немає такого пункту.\n"); } } }
