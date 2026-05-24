/* KR_5.c — Розділ 5. Класна робота (C)
   Студент: Фархад Фаталієв
   Плейсхолдери умов — замінити на точні формулювання з methodicalCPP.pdf
*/

#include <stdio.h>
#include <stdlib.h>

/* 5.1 - 5.8 */
void task_5_1(){ printf("[task_5_1] Плейсхолдер.\n"); }
void task_5_2(){ printf("[task_5_2] Плейсхолдер.\n"); }
void task_5_3(){ printf("[task_5_3] Плейсхолдер.\n"); }
void task_5_4(){ printf("[task_5_4] Плейсхолдер.\n"); }
void task_5_5(){ printf("[task_5_5] Плейсхолдер.\n"); }
void task_5_6(){ printf("[task_5_6] Плейсхолдер.\n"); }
void task_5_7(){ printf("[task_5_7] Плейсхолдер.\n"); }
void task_5_8(){ printf("[task_5_8] Плейсхолдер.\n"); }

static void printMenu(){
    puts("\n=== KR Розділ 5 (C) ===");
    puts("1 - task_5_1"); puts("2 - task_5_2"); puts("3 - task_5_3"); puts("4 - task_5_4");
    puts("5 - task_5_5"); puts("6 - task_5_6"); puts("7 - task_5_7"); puts("8 - task_5_8");
    puts("0 - вихід"); printf("Оберіть завдання: ");
}

int main(void){
    int choice;
    while(1){ printMenu(); if(scanf("%d", &choice)!=1){ int ch; while((ch=getchar())!=EOF && ch!='\n'); printf("Некоректний ввід\n"); continue; }
        switch(choice){
            case 1: task_5_1(); break; case 2: task_5_2(); break; case 3: task_5_3(); break; case 4: task_5_4(); break;
            case 5: task_5_5(); break; case 6: task_5_6(); break; case 7: task_5_7(); break; case 8: task_5_8(); break;
            case 0: return 0; default: printf("Немає такого пункту.\n");
        }
    }
}
