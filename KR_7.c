/* KR_8.c — Розділ 8. Класна робота (C)
   Студент: Фархад Фаталієв
*/

#include <stdio.h>

void task_8_1(){ printf("[task_8_1] Плейсхолдер.\n"); }
void task_8_2(){ printf("[task_8_2] Плейсхолдер.\n"); }
void task_8_3(){ printf("[task_8_3] Плейсхолдер.\n"); }
void task_8_4(){ printf("[task_8_4] Плейсхолдер.\n"); }
void task_8_5(){ printf("[task_8_5] Плейсхолдер.\n"); }
void task_8_6(){ printf("[task_8_6] Плейсхолder.\n"); }
void task_8_7(){ printf("[task_8_7] Плейсхолдер.\n"); }

static void printMenu(){ puts("\n=== KR Розділ 8 (C) ==="); puts("1 - task_8_1"); puts("2 - task_8_2"); puts("3 - task_8_3"); puts("4 - task_8_4"); puts("5 - task_8_5"); puts("6 - task_8_6"); puts("7 - task_8_7"); puts("0 - вихід"); printf("Оберіть завдання: "); }

int main(void){ int choice; while(1){ printMenu(); if(scanf("%d", &choice)!=1){ int ch; while((ch=getchar())!=EOF && ch!='\n'); printf("Некоректний ввід\n"); continue; } switch(choice){ case 1: task_8_1(); break; case 2: task_8_2(); break; case 3: task_8_3(); break; case 4: task_8_4(); break; case 5: task_8_5(); break; case 6: task_8_6(); break; case 7: task_8_7(); break; case 0: return 0; default: printf("Немає такого пункту.\n"); } } }
