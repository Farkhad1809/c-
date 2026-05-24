// DR_15.cpp — Розділ 15. Домашня робота (15.8)
// Студент: Фархад Фаталієв

#include <iostream>
#include <limits>

using namespace std;

// 15.8. Класи Час (год, хв, сек) та Дата (рік, місяць, день) з методами різниці.
class Time {
    int h_{}, m_{}, s_{};

public:
    void input() {
        cout << "Год хв сек: ";
        cin >> h_ >> m_ >> s_;
    }

    int totalSeconds() const { return h_ * 3600 + m_ * 60 + s_; }

    void print() const { cout << h_ << ':' << m_ << ':' << s_; }

    int diffSeconds(const Time &o) const { return abs(totalSeconds() - o.totalSeconds()); }
};

class Date {
    int y_{}, mo_{}, d_{};
    static int instances_;

public:
    Date() { ++instances_; }
    ~Date() { --instances_; }

    static int instanceCount() { return instances_; }

    void input() {
        cout << "Рік місяць день: ";
        cin >> y_ >> mo_ >> d_;
    }

    int toDays() const { return y_ * 400 + mo_ * 31 + d_; }

    void print() const { cout << d_ << '.' << mo_ << '.' << y_; }

    int diffDays(const Date &o) const { return abs(toDays() - o.toDays()); }
};

int Date::instances_ = 0;

void task_15_8() {
    Time t1, t2;
    cout << "Час 1: ";
    t1.input();
    cout << "Час 2: ";
    t2.input();
    cout << "Різниця (сек): " << t1.diffSeconds(t2) << '\n';

    Date d1, d2;
    cout << "Дата 1: ";
    d1.input();
    cout << "Дата 2: ";
    d2.input();
    cout << "Різниця (умовних днів): " << d1.diffDays(d2) << '\n';
    cout << "Об'єктів Date створено: " << Date::instanceCount() << '\n';
}

int main() {
    while (true) {
        cout << "\n=== DR Розділ 15 ===\n1-15_8, 0-вихід\nОберіть: ";
        int c{};
        if (!(cin >> c)) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }
        if (c == 1) {
            task_15_8();
        } else if (c == 0) {
            return 0;
        }
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
}
