/* KR_7.c — Розділ 7. Класна робота (C)
   Студент: Фархад Фаталієв
   Плейсхолдери умов — замінити на точні формулювання з methodicalCPP.pdf
*/

#include <stdio.h>

void task_7_1(){ printf("[task_7_1] Плейсхолдер.\n"); }
void task_7_2(){ printf("[task_7_2] Плейсхолдер.\n"); }
void task_7_3(){ printf("[task_7_3] Плейсхолдер.\n"); }
void task_7_4(){ printf("[task_7_4] Плейсхолдер.\n"); }
void task_7_5(){ printf("[task_7_5] Плейсхолдер.\n"); }
void task_7_6(){ printf("[task_7_6] Плейсхолдер.\n"); }

static void printMenu(){ puts("\n=== KR Розділ 7 (C) ==="); puts("1 - task_7_1"); puts("2 - task_7_2"); puts("3 - task_7_3"); puts("4 - task_7_4"); puts("5 - task_7_5"); puts("6 - task_7_6"); puts("0 - вихід"); printf("Оберіть завдання: "); }

int main(void){ int choice; while(1){ printMenu(); if(scanf("%d", &choice)!=1){ int ch; while((ch=getchar())!=EOF && ch!='\n'); printf("Некоректний ввід\n"); continue; } switch(choice){ case 1: task_7_1(); break; case 2: task_7_2(); break; case 3: task_7_3(); break; case 4: task_7_4(); break; case 5: task_7_5(); break; case 6: task_7_6(); break; case 0: return 0; default: printf("Немає такого пункту.\n"); } } }
