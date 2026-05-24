// KR_12.cpp — Розділ 12. Класна робота (C++)
// Студент: Фархад Фаталієв

#include <iostream>
#include <string>

using namespace std;

// Умова: 12.1 (плейсхолдер)
void task_12_1(){ cout << "[task_12_1] Плейсхолдер.\n"; }
void task_12_2(){ cout << "[task_12_2] Плейсхолдер.\n"; }
void task_12_3(){ cout << "[task_12_3] Плейсхолдер.\n"; }
void task_12_4(){ cout << "[task_12_4] Плейсхолдер.\n"; }
void task_12_5(){ cout << "[task_12_5] Плейсхолдер.\n"; }

void printMenu(){
    cout << "\n=== KR Розділ 12 (C++) ===\n";
    cout << "1 - task_12_1\n";
    cout << "2 - task_12_2\n";
    cout << "3 - task_12_3\n";
    cout << "4 - task_12_4\n";
    cout << "5 - task_12_5\n";
    cout << "0 - вихід\n";
    cout << "Оберіть завдання: ";
}

int main(){
    while(true){ printMenu(); int c; if(!(cin>>c)){ cin.clear(); string s; getline(cin,s); cout<<"Некоректний ввід\n"; continue; }
        switch(c){ case 1: task_12_1(); break; case 2: task_12_2(); break; case 3: task_12_3(); break; case 4: task_12_4(); break; case 5: task_12_5(); break; case 0: return 0; default: cout<<"Немає такого пункту.\n"; }
    }
}
