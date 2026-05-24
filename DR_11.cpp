// DR_13.cpp — Розділ 13. Домашня робота (C++)
// Студент: Фархад Фаталієв

#include <iostream>
using namespace std;

// Умова: 13.22 (плейсхолдер)
void task_13_22(){ cout << "[task_13_22] Плейсхолдер.\n"; }

int main(){
    while(true){ cout << "\n=== DR Розділ 13 (C++) ===\n1 - task_13_22\n0 - вихід\nОберіть завдання: "; int c; if(!(cin>>c)){ cin.clear(); string s; getline(cin,s); cout<<"Некоректний ввід\n"; continue; } switch(c){ case 1: task_13_22(); break; case 0: return 0; default: cout<<"Немає такого пункту.\n"; }
    }
}
