// DR_21.cpp — Розділ 21. Домашня робота (21.19)
// Студент: Фархад Фаталієв

#include <algorithm>
#include <iostream>
#include <limits>
#include <random>
#include <vector>

using namespace std;

// 21.19. Сортування виділенням: max_element, обмін з кінцем, повторити.
void task_21_19() {
    int n{};
    cout << "Розмір масиву: ";
    cin >> n;
    vector<int> a(n);
    cout << "1-ввести 2-випадкові: ";
    int mode{};
    cin >> mode;
    if (mode == 1) {
        cout << "Елементи: ";
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
    } else {
        mt19937 gen(random_device{}());
        uniform_int_distribution<int> dist(0, 99);
        for (int i = 0; i < n; ++i) {
            a[i] = dist(gen);
        }
        cout << "Згенеровано: ";
        for (int v : a) {
            cout << v << ' ';
        }
        cout << '\n';
    }

    for (int end = static_cast<int>(a.size()) - 1; end > 0; --end) {
        const auto it = max_element(a.begin(), a.begin() + end + 1);
        swap(*it, a[end]);
    }

    cout << "Відсортовано: ";
    for (int v : a) {
        cout << v << ' ';
    }
    cout << '\n';
}

int main() {
    task_21_19();
    return 0;
}
