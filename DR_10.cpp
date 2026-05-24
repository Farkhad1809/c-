// DR_12.cpp — Розділ 12. Домашня робота (C++)
// Студент: Фархад Фаталієв

#include <iostream>
using namespace std;

// Умова: 12.17 (плейсхолдер)
void task_12_17(){ cout << "[task_12_17] Плейсхолдер.\n"; }

int main(){
    while(true){ cout << "\n=== DR Розділ 12 (C++) ===\n1 - task_12_17\n0 - вихід\nОберіть завдання: "; int c; if(!(cin>>c)){ cin.clear(); string s; getline(cin,s); cout<<"Некоректний ввід\n"; continue; } switch(c){ case 1: task_12_17(); break; case 0: return 0; default: cout<<"Немає такого пункту.\n"; }
    }
}
