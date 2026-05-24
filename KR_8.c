/* KR_9.c — Розділ 9. Класна робота (C)
   Студент: Фархад Фаталієв
*/

#include <stdio.h>

void task_9_1(){ printf("[task_9_1] Плейсхолдер.\n"); }
void task_9_2(){ printf("[task_9_2] Плейсхолдер.\n"); }
void task_9_3(){ printf("[task_9_3] Плейсхолдер.\n"); }
void task_9_4(){ printf("[task_9_4] Плейсхолolder.\n"); }

static void printMenu(){ puts("\n=== KR Розділ 9 (C) ==="); puts("1 - task_9_1"); puts("2 - task_9_2"); puts("3 - task_9_3"); puts("4 - task_9_4"); puts("0 - вихід"); printf("Оберіть завдання: "); }

int main(void){ int choice; while(1){ printMenu(); if(scanf("%d", &choice)!=1){ int ch; while((ch=getchar())!=EOF && ch!='\n'); printf("Некоректний ввід\n"); continue; } switch(choice){ case 1: task_9_1(); break; case 2: task_9_2(); break; case 3: task_9_3(); break; case 4: task_9_4(); break; case 0: return 0; default: printf("Немає такого пункту.\n"); } } }
