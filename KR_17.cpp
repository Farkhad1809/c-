// KR_19.cpp — Розділ 19. Класна робота (19.1–19.4)
// Студент: Фархад Фаталієв

#include <algorithm>
#include <cmath>
#include <iostream>
#include <limits>
#include <list>
#include <queue>
#include <vector>

using namespace std;

// 19.1. Черга на білому прилавку: прибуття через 1 хв; ci — час у черзі; мін. ti та макс. ci.
void task_19_1() {
    int n{};
    cout << "n: ";
    cin >> n;
    vector<double> t(n);
    cout << "Час обслуговування t1..tn: ";
    for (int i = 0; i < n; ++i) {
        cin >> t[i];
    }
    vector<double> wait(n), end(n);
    for (int i = 0; i < n; ++i) {
        const double arrive = i;
        const double start = (i == 0) ? 0.0 : max(arrive, end[i - 1]);
        wait[i] = start - arrive;
        end[i] = start + t[i];
    }
    cout << "Час у черзі: ";
    for (int i = 0; i < n; ++i) {
        cout << wait[i] << ' ';
    }
    cout << '\n';
    int minTIdx = 0, maxWaitIdx = 0;
    for (int i = 1; i < n; ++i) {
        if (t[i] < t[minTIdx]) {
            minTIdx = i;
        }
        if (wait[i] > wait[maxWaitIdx]) {
            maxWaitIdx = i;
        }
    }
    cout << "Найменший час обслуговування: покупець " << minTIdx + 1 << " (t=" << t[minTIdx]
         << ")\n";
    cout << "Найдовше в черзі: покупець " << maxWaitIdx + 1 << " (" << wait[maxWaitIdx]
         << " хв)\n";
}

// 19.2. d-вимірні вектори; сума норм.
void task_19_2() {
    int d{};
    cout << "Розмірність d: ";
    cin >> d;
    int n{};
    cout << "Кількість векторів n: ";
    cin >> n;
    double sumNorms = 0;
    for (int i = 0; i < n; ++i) {
        vector<double> v(d);
        cout << "Вектор " << i + 1 << ": ";
        double sq = 0;
        for (int j = 0; j < d; ++j) {
            cin >> v[j];
            sq += v[j] * v[j];
        }
        sumNorms += sqrt(sq);
    }
    cout << "Сума норм = " << sumNorms << '\n';
}

// 19.3. Шаблон Поліном на list; +, *, значення.
template <typename T>
class Polynomial {
    list<T> coef_;

public:
    void input() {
        int deg{};
        cout << "Ступінь: ";
        cin >> deg;
        coef_.clear();
        cout << "Коефіцієнти від молодшого до старшого: ";
        for (int i = 0; i <= deg; ++i) {
            T c{};
            cin >> c;
            coef_.push_back(c);
        }
    }

    void print() const {
        int p = 0;
        for (const T &c : coef_) {
            cout << c;
            if (p) {
                cout << "*x^" << p;
            }
            cout << " + ";
            ++p;
        }
        cout << "0\n";
    }

    Polynomial operator+(const Polynomial &o) const {
        Polynomial r;
        auto it1 = coef_.begin(), it2 = o.coef_.begin();
        while (it1 != coef_.end() || it2 != o.coef_.end()) {
            T a{}, b{};
            if (it1 != coef_.end()) {
                a = *it1++;
            }
            if (it2 != o.coef_.end()) {
                b = *it2++;
            }
            r.coef_.push_back(a + b);
        }
        return r;
    }

    Polynomial operator*(const Polynomial &o) const {
        const size_t sz = coef_.size() + o.coef_.size() - 1;
        vector<T> tmp(sz, T{});
        int i = 0;
        for (const T &a : coef_) {
            int j = 0;
            for (const T &b : o.coef_) {
                tmp[i + j] = tmp[i + j] + a * b;
                ++j;
            }
            ++i;
        }
        Polynomial r;
        for (const T &x : tmp) {
            r.coef_.push_back(x);
        }
        return r;
    }

    T value(T x) const {
        T res{}, powX = 1;
        for (const T &c : coef_) {
            res = res + c * powX;
            powX = powX * x;
        }
        return res;
    }
};

struct Rational {
    int n{0}, d{1};

    friend istream &operator>>(istream &in, Rational &r) {
        in >> r.n >> r.d;
        return in;
    }

    friend ostream &operator<<(ostream &out, const Rational &r) {
        return out << r.n << '/' << r.d;
    }

    Rational operator+(const Rational &o) const {
        return {n * o.d + o.n * d, d * o.d};
    }

    Rational operator*(const Rational &o) const {
        return {n * o.n, d * o.d};
    }
};

void task_19_3() {
    cout << "--- double ---\n";
    Polynomial<double> p1, p2;
    p1.input();
    p2.input();
    auto s = p1 + p2;
    cout << "Сума: ";
    s.print();
    auto m = p1 * p2;
    cout << "Добуток: ";
    m.print();
    double x{};
    cout << "x: ";
    cin >> x;
    cout << "p1(x)=" << p1.value(x) << '\n';

    cout << "--- Rational ---\n";
    Polynomial<Rational> r1, r2;
    r1.input();
    r2.input();
    (r1 + r2).print();
}

// 19.4. Матриця n×m як vector<list<int>>; поміняти рядки — макс. елементи у спадному порядку.
void task_19_4() {
    int n{}, m{};
    cout << "n m: ";
    cin >> n >> m;
    vector<list<int>> mat(n);
    cout << "Елементи:\n";
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            int v{};
            cin >> v;
            mat[i].push_back(v);
        }
    }
    auto rowMax = [](const list<int> &row) {
        return *max_element(row.begin(), row.end());
    };
    sort(mat.begin(), mat.end(), [&](const list<int> &a, const list<int> &b) {
        return rowMax(a) > rowMax(b);
    });
    cout << "Після перестановки рядків:\n";
    for (const auto &row : mat) {
        for (int v : row) {
            cout << v << ' ';
        }
        cout << '\n';
    }
}

void printMenu() {
    cout << "\n=== KR Розділ 19 ===\n1-19_1, 2-19_2, 3-19_3, 4-19_4, 0-вихід\nОберіть: ";
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
            task_19_1();
            break;
        case 2:
            task_19_2();
            break;
        case 3:
            task_19_3();
            break;
        case 4:
            task_19_4();
            break;
        case 0:
            return 0;
        default:
            cout << "?\n";
        }
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
}
