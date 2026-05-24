// KR_17.cpp — Розділ 17. Класна робота (17.1–17.2)
// Студент: Фархад Фаталієв

#include <fstream>
#include <iostream>
#include <limits>
#include <memory>
#include <stdexcept>
#include <string>
#include <vector>

using namespace std;

// 17.1. Rational: оператори вводу/виводу, ділення з виключенням при знаменнику 0, запис у файл.
class Rational {
    int num_{0};
    int den_{1};

    void normalize() {
        if (den_ == 0) {
            throw runtime_error("Знаменник 0");
        }
        if (den_ < 0) {
            num_ = -num_;
            den_ = -den_;
        }
    }

public:
    Rational() = default;
    Rational(int n, int d) : num_(n), den_(d) { normalize(); }

    friend istream &operator>>(istream &in, Rational &r) {
        cout << "Чисельник знаменник: ";
        in >> r.num_ >> r.den_;
        r.normalize();
        return in;
    }

    friend ostream &operator<<(ostream &out, const Rational &r) {
        out << r.num_ << '/' << r.den_;
        return out;
    }

    Rational operator/(const Rational &o) const {
        if (o.num_ == 0) {
            throw runtime_error("Ділення на 0");
        }
        return Rational(num_ * o.den_, den_ * o.num_);
    }
};

void writeRationalFile(const string &path, const Rational &r) {
    ofstream out(path);
    if (!out) {
        throw runtime_error("Не вдалося відкрити файл для запису");
    }
    out << r;
}

void task_17_1() {
    try {
        Rational r;
        cin >> r;
        cout << "r = " << r << '\n';
        Rational s;
        cout << "Другий дріб для ділення:\n";
        cin >> s;
        cout << "r/s = " << (r / s) << '\n';
        writeRationalFile("rational_out.txt", r);
        cout << "Записано у rational_out.txt\n";
    } catch (const exception &e) {
        cout << "Помилка: " << e.what() << '\n';
    }
}

// 17.2. Людина, Студент, Викладач, Аспірант; масив Людей; вивести ВУЗ для кожного.
class Human {
protected:
    string pib_;
    string gender_;
    int age_{};

public:
    virtual ~Human() = default;

    virtual void input() {
        cout << "ПІБ стать вік: ";
        cin >> pib_ >> gender_ >> age_;
    }

    virtual void show() const {
        cout << pib_ << ", " << gender_ << ", " << age_;
    }

    virtual string university() const { return "невідомо"; }
};

class Student : public Human {
    int course_{};
    string group_;
    string vuz_;

public:
    void input() override {
        Human::input();
        cout << "Курс група ВУЗ: ";
        cin >> course_ >> group_ >> vuz_;
    }

    void show() const override {
        Human::show();
        cout << ", студент " << course_ << " к., гр." << group_;
    }

    string university() const override { return vuz_; }
};

class Teacher : public Human {
    string vuz_;
    string pos_;

public:
    void input() override {
        Human::input();
        cout << "ВУЗ посада: ";
        cin >> vuz_ >> pos_;
    }

    void show() const override {
        Human::show();
        cout << ", викладач " << pos_;
    }

    string university() const override { return vuz_; }
};

class Postgrad : public Student {
    string pos_;

public:
    void input() override {
        Student::input();
        cout << "Посада аспіранта: ";
        cin >> pos_;
    }

    void show() const override {
        Student::show();
        cout << ", посада " << pos_;
    }
};

void task_17_2() {
    vector<unique_ptr<Human>> people;
    int n{};
    cout << "Скільки осіб: ";
    cin >> n;
    for (int i = 0; i < n; ++i) {
        char t{};
        cout << "Тип (s-студент, t-викладач, a-аспірант): ";
        cin >> t;
        unique_ptr<Human> p;
        if (t == 's') {
            p = make_unique<Student>();
        } else if (t == 't') {
            p = make_unique<Teacher>();
        } else {
            p = make_unique<Postgrad>();
        }
        p->input();
        people.push_back(move(p));
    }
    for (const auto &p : people) {
        p->show();
        cout << " | ВУЗ: " << p->university() << '\n';
    }
}

void printMenu() {
    cout << "\n=== KR Розділ 17 ===\n1-17_1, 2-17_2, 0-вихід\nОберіть: ";
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
            task_17_1();
            break;
        case 2:
            task_17_2();
            break;
        case 0:
            return 0;
        default:
            cout << "?\n";
        }
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
}
