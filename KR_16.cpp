// KR_18.cpp — Розділ 18. Класна робота (18.1–18.2)
// Студент: Фархад Фаталієв

#include <algorithm>
#include <iostream>
#include <limits>
#include <stack>
#include <vector>

using namespace std;

namespace myalg {

// 18.1. Шаблон max2 для стандартних типів.
template <typename T>
T max2(const T &a, const T &b) {
    return (a < b) ? b : a;
}

// 18.2. Ввід цілих до нуля; стек; порівняння з STL stack.
template <typename T>
size_t readUntilZero(vector<T> &out) {
    out.clear();
    stack<T> st;
    while (true) {
        T v{};
        cin >> v;
        if (v == T{}) {
            break;
        }
        st.push(v);
        out.push_back(v);
    }
    return out.size();
}

} // namespace myalg

void task_18_1() {
    cout << "int a b: ";
    int a{}, b{};
    cin >> a >> b;
    cout << "max = " << myalg::max2(a, b) << '\n';

    cout << "double a b: ";
    double x{}, y{};
    cin >> x >> y;
    cout << "max = " << myalg::max2(x, y) << '\n';
}

void task_18_2() {
    vector<int> data;
    cout << "Вводьте цілі (0 — кінець):\n";
    const size_t n = myalg::readUntilZero(data);
    cout << "Прочитано: " << n << " чисел\n";

    stack<int> stl;
    for (int v : data) {
        stl.push(v);
    }
    cout << "STL stack (зверху вниз): ";
    while (!stl.empty()) {
        cout << stl.top() << ' ';
        stl.pop();
    }
    cout << '\n';
}

void printMenu() {
    cout << "\n=== KR Розділ 18 ===\n1-18_1, 2-18_2, 0-вихід\nОберіть: ";
}

int main() {
    while (true) {
        printMenu();
        int c{};
        if (!(cin >> c)) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }
        switch (c) {
        case 1:
            task_18_1();
            break;
        case 2:
            task_18_2();
            break;
        case 0:
            return 0;
        default:
            cout << "?\n";
        }
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
}
