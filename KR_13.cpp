// KR_15.cpp — Розділ 15. Класна робота (15.1–15.3)
// Студент: Фархад Фаталієв

#include <cmath>
#include <iostream>
#include <limits>
#include <vector>

using namespace std;

int gcd_int(int a, int b) {
    a = abs(a);
    b = abs(b);
    while (b) {
        const int t = a % b;
        a = b;
        b = t;
    }
    return a ? a : 1;
}

// 15.1. Клас раціональне число: чисельник, знаменник; ввід/вивід, +, *, НСД, оператори.
class Rational {
    int num_{1};
    int den_{1};

    void reduce() {
        if (den_ < 0) {
            num_ = -num_;
            den_ = -den_;
        }
        const int g = gcd_int(num_, den_);
        num_ /= g;
        den_ /= g;
    }

public:
    Rational() = default;
    Rational(int n, int d) : num_(n), den_(d) {
        if (den_ == 0) {
            throw invalid_argument("Знаменник не може бути 0");
        }
        reduce();
    }

    void input() {
        cout << "Чисельник знаменник: ";
        int n{}, d{};
        cin >> n >> d;
        if (d == 0) {
            throw invalid_argument("Знаменник не може бути 0");
        }
        num_ = n;
        den_ = d;
        reduce();
    }

    void print() const { cout << num_ << '/' << den_; }

    Rational operator+(const Rational &o) const {
        return Rational(num_ * o.den_ + o.num_ * den_, den_ * o.den_);
    }

    Rational operator*(const Rational &o) const {
        return Rational(num_ * o.num_, den_ * o.den_);
    }

    bool operator<(const Rational &o) const {
        return static_cast<long long>(num_) * o.den_ < static_cast<long long>(o.num_) * den_;
    }

    double toDouble() const { return static_cast<double>(num_) / den_; }
};

void task_15_1() {
    try {
        Rational a, b;
        cout << "a: ";
        a.input();
        cout << "b: ";
        b.input();
        cout << "a = ";
        a.print();
        cout << "\nb = ";
        b.print();
        cout << "\na+b = ";
        (a + b).print();
        cout << "\na*b = ";
        (a * b).print();
        cout << '\n';
    } catch (const exception &e) {
        cout << e.what() << '\n';
    }
}

// 15.2. Клас Точка зі статичним лічильником; багатокутник, периметр.
class Point {
    double x_{}, y_{};
    static int count_;

public:
    Point() { ++count_; }
    Point(double x, double y) : x_(x), y_(y) { ++count_; }
    Point(const Point &o) : x_(o.x_), y_(o.y_) { ++count_; }
    ~Point() { --count_; }

    static int counter() { return count_; }

    double dist(const Point &o) const { return hypot(x_ - o.x_, y_ - o.y_); }

    void input() {
        cout << "x y: ";
        cin >> x_ >> y_;
    }

    void print() const { cout << '(' << x_ << ", " << y_ << ')'; }
};

int Point::count_ = 0;

class Polygon {
    vector<Point> v_;

public:
    void input() {
        int n{};
        cout << "Кількість вершин: ";
        cin >> n;
        v_.clear();
        for (int i = 0; i < n; ++i) {
            cout << "Вершина " << i + 1 << ": ";
            Point p;
            p.input();
            v_.push_back(p);
        }
    }

    double perimeter() const {
        if (v_.size() < 2) {
            return 0;
        }
        double p = 0;
        for (size_t i = 0; i < v_.size(); ++i) {
            p += v_[i].dist(v_[(i + 1) % v_.size()]);
        }
        return p;
    }
};

void task_15_2() {
    Polygon poly;
    poly.input();
    cout << "Вершин (об'єктів Point): " << Point::counter() << '\n';
    cout << "Периметр: " << poly.perimeter() << '\n';
}

// 15.3. Клас Поліном: масив коефіцієнтів, ввід/вивід, значення в точці x.
class Polynomial {
    vector<double> c_;

public:
    explicit Polynomial(size_t n = 0) : c_(n) {}

    void input() {
        int n{};
        cout << "Ступінь n: ";
        cin >> n;
        c_.assign(n + 1, 0);
        cout << "Коефіцієнти від a0 до a" << n << ": ";
        for (int i = 0; i <= n; ++i) {
            cin >> c_[i];
        }
    }

    void print() const {
        bool first = true;
        for (int i = static_cast<int>(c_.size()) - 1; i >= 0; --i) {
            if (fabs(c_[i]) < 1e-12) {
                continue;
            }
            if (!first && c_[i] > 0) {
                cout << " + ";
            } else if (c_[i] < 0) {
                cout << " - ";
            } else if (!first) {
                cout << " + ";
            }
            first = false;
            cout << fabs(c_[i]);
            if (i > 1) {
                cout << "x^" << i;
            } else if (i == 1) {
                cout << 'x';
            }
        }
        if (first) {
            cout << '0';
        }
    }

    double value(double x) const {
        double r = 0;
        double p = 1;
        for (double a : c_) {
            r += a * p;
            p *= x;
        }
        return r;
    }
};

void task_15_3() {
    Polynomial p;
    p.input();
    cout << "P(x) = ";
    p.print();
    double x{};
    cout << "\nx = ";
    cin >> x;
    cout << "P(" << x << ") = " << p.value(x) << '\n';
}

void printMenu() {
    cout << "\n=== KR Розділ 15 ===\n1-15_1, 2-15_2, 3-15_3, 0-вихід\nОберіть: ";
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
            task_15_1();
            break;
        case 2:
            task_15_2();
            break;
        case 3:
            task_15_3();
            break;
        case 0:
            return 0;
        default:
            cout << "?\n";
        }
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
}
