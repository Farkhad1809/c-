/* DR_5.c — Розділ 5. Домашня робота (C)
   Студент: Фархад Фаталієв
   Плейсхолдери умов — замінити на точні формулювання з methodicalCPP.pdf
*/

#include <stdio.h>
#include <stdlib.h>

/* Умова: 5.11в */
void task_5_11(){ printf("[task_5_11] Плейсхолдер для 5.11в.\n"); }

/* Умова: 5.16є */
void task_5_16(){ printf("[task_5_16] Плейсхолдер для 5.16є.\n"); }

static void printMenu(){
    puts("\n=== DR Розділ 5 (C) ===");
    puts("1 - task_5_11"); puts("2 - task_5_16"); puts("0 - вихід"); printf("Оберіть завдання: ");
}

int main(void){
    int choice;
    while(1){ printMenu(); if(scanf("%d", &choice)!=1){ int ch; while((ch=getchar())!=EOF && ch!='\n'); printf("Некоректний ввід\n"); continue; }
        switch(choice){ case 1: task_5_11(); break; case 2: task_5_16(); break; case 0: return 0; default: printf("Немає такого пункту.\n"); }
    }
}
