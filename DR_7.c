/* DR_8.c — Розділ 8. Домашня робота (C)
   Студент: Фархад Фаталієв
*/

#include <stdio.h>

/* Умова: 8.19 */
void task_8_19(){ printf("[task_8_19] Плейсхолдер для 8.19.\n"); }

static void printMenu(){ puts("\n=== DR Розділ 8 (C) ==="); puts("1 - task_8_19"); puts("0 - вихід"); printf("Оберіть завдання: "); }

int main(void){ int choice; while(1){ printMenu(); if(scanf("%d", &choice)!=1){ int ch; while((ch=getchar())!=EOF && ch!='\n'); printf("Некоректний ввід\n"); continue; } switch(choice){ case 1: task_8_19(); break; case 0: return 0; default: printf("Немає такого пункту.\n"); } } }
