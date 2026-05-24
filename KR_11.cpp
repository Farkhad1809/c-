// KR_13.cpp — Розділ 13. Класна робота (C++)
// Студент: Фархад Фаталієв

#include <iostream>
using namespace std;

// Умова: 13.1 - 13.3, 13.6 (плейсхолдери)
void task_13_1(){ cout << "[task_13_1] Плейсхолдер.\n"; }
void task_13_2(){ cout << "[task_13_2] Плейсхолдер.\n"; }
void task_13_3(){ cout << "[task_13_3] Плейсхолider.\n"; }
void task_13_6(){ cout << "[task_13_6] Плейсхолдер.\n"; }

int main(){
    while(true){ cout << "\n=== KR Розділ 13 (C++) ===\n1 - task_13_1\n2 - task_13_2\n3 - task_13_3\n4 - task_13_6\n0 - вихід\nОберіть завдання: "; int c; if(!(cin>>c)){ cin.clear(); string s; getline(cin,s); cout<<"Некоректний ввід\n"; continue; } switch(c){ case 1: task_13_1(); break; case 2: task_13_2(); break; case 3: task_13_3(); break; case 4: task_13_6(); break; case 0: return 0; default: cout<<"Немає такого пункту.\n"; }
    }
}
