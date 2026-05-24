// DR_18.cpp — Розділ 18. Домашня робота (18.4, 18.5з)
// Студент: Фархад Фаталієв

#include <cmath>
#include <iostream>
#include <limits>
#include <stdexcept>
#include <vector>

using namespace std;

// 18.4. Комплексне число; arctg(z) рядом при |z|<1.
class Complex {
    double re_{}, im_{};

public:
    Complex() = default;
    Complex(double r, double i) : re_(r), im_(i) {}

    void input() {
        cout << "Re Im: ";
        cin >> re_ >> im_;
    }

    double abs() const { return hypot(re_, im_); }

    Complex operator+(const Complex &o) const { return {re_ + o.re_, im_ + o.im_}; }

    Complex operator*(const Complex &o) const {
        return {re_ * o.re_ - im_ * o.im_, re_ * o.im_ + im_ * o.re_};
    }

    void print() const {
        cout << re_;
        if (im_ >= 0) {
            cout << '+';
        }
        cout << im_ << 'i';
    }

    double real() const { return re_; }
    double imag() const { return im_; }
};

double arctgSeries(const Complex &z, double eps, int maxIter = 10000) {
    if (z.abs() >= 1.0) {
        throw invalid_argument("|z| має бути < 1");
    }
    double sum = 0;
    Complex zPow = z;
    int sign = 1;
    for (int n = 0; n < maxIter; n += 2) {
        const double term = sign * zPow.real() / (n + 1);
        if (fabs(term) < eps) {
            break;
        }
        sum += term;
        sign = -sign;
        zPow = zPow * z * z;
    }
    return sum;
}

void task_18_4() {
    try {
        Complex z;
        z.input();
        double eps{};
        cout << "Точність eps: ";
        cin >> eps;
        cout << "arctg(z) ≈ " << arctgSeries(z, eps) << " (дійсна частина ряду)\n";
    } catch (const exception &e) {
        cout << "Помилка: " << e.what() << '\n';
    }
}

// 18.5з. Шаблон Array: швидке сортування (quick sort).
template <typename T>
class Array {
    vector<T> data_;

    void quickSort(int l, int r) {
        if (l >= r) {
            return;
        }
        T pivot = data_[(l + r) / 2];
        int i = l, j = r;
        while (i <= j) {
            while (data_[i] < pivot) {
                ++i;
            }
            while (data_[j] > pivot) {
                --j;
            }
            if (i <= j) {
                swap(data_[i], data_[j]);
                ++i;
                --j;
            }
        }
        if (l < j) {
            quickSort(l, j);
        }
        if (i < r) {
            quickSort(i, r);
        }
    }

public:
    void input() {
        int n{};
        cout << "n: ";
        cin >> n;
        data_.resize(n);
        cout << "Елементи: ";
        for (int i = 0; i < n; ++i) {
            cin >> data_[i];
        }
    }

    void sortQuick() { quickSort(0, static_cast<int>(data_.size()) - 1); }

    void print() const {
        for (const T &x : data_) {
            cout << x << ' ';
        }
        cout << '\n';
    }
};

void task_18_5z() {
    Array<int> a;
    a.input();
    cout << "До: ";
    a.print();
    a.sortQuick();
    cout << "Після quick sort: ";
    a.print();
}

int main() {
    while (true) {
        cout << "\n=== DR Розділ 18 ===\n1-18_4, 2-18_5z, 0-вихід\nОберіть: ";
        int c{};
        if (!(cin >> c)) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }
        switch (c) {
        case 1:
            task_18_4();
            break;
        case 2:
            task_18_5z();
            break;
        case 0:
            return 0;
        default:
            cout << "?\n";
        }
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
}
