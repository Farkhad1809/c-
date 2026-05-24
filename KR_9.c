/* KR_10.c — Розділ 10. Класна робота (C)
   Студент: Фархад Фаталієв
*/

#include <stdio.h>

void task_10_1(){ printf("[task_10_1] Плейсхолдер.\n"); }
void task_10_2(){ printf("[task_10_2] Плейсхолдер.\n"); }
void task_10_3(){ printf("[task_10_3] Плейсхолдер.\n"); }
void task_10_4(){ printf("[task_10_4] Плейсхолder.\n"); }
void task_10_5(){ printf("[task_10_5] Плейсхолдер.\n"); }

static void printMenu(){ puts("\n=== KR Розділ 10 (C) ==="); puts("1 - task_10_1"); puts("2 - task_10_2"); puts("3 - task_10_3"); puts("4 - task_10_4"); puts("5 - task_10_5"); puts("0 - вихід"); printf("Оберіть завдання: "); }

int main(void){ int choice; while(1){ printMenu(); if(scanf("%d", &choice)!=1){ int ch; while((ch=getchar())!=EOF && ch!='\n'); printf("Некоректний ввід\n"); continue; } switch(choice){ case 1: task_10_1(); break; case 2: task_10_2(); break; case 3: task_10_3(); break; case 4: task_10_4(); break; case 5: task_10_5(); break; case 0: return 0; default: printf("Немає такого пункту.\n"); } } }
