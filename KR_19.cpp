// KR_21.cpp — Розділ 21. Класна робота (21.1–21.8)
// Студент: Фархад Фаталієв

#include <algorithm>
#include <cctype>
#include <ctime>
#include <iostream>
#include <iterator>
#include <limits>
#include <list>
#include <numeric>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

// 21.1. BoolVector на vector<bool>: &, |, !, підрахунок 0/1.
class BoolVector {
    vector<bool> bits_;

public:
    void input() {
        int n{};
        cout << "Розмір: ";
        cin >> n;
        bits_.resize(n);
        cout << "Біти (0/1): ";
        for (int i = 0; i < n; ++i) {
            int b{};
            cin >> b;
            bits_[i] = b != 0;
        }
    }

    void print() const {
        for (bool b : bits_) {
            cout << (b ? 1 : 0);
        }
        cout << '\n';
    }

    BoolVector operator&(const BoolVector &o) const {
        BoolVector r;
        const size_t n = min(bits_.size(), o.bits_.size());
        r.bits_.resize(n);
        for (size_t i = 0; i < n; ++i) {
            r.bits_[i] = bits_[i] && o.bits_[i];
        }
        return r;
    }

    BoolVector operator|(const BoolVector &o) const {
        BoolVector r;
        const size_t n = min(bits_.size(), o.bits_.size());
        r.bits_.resize(n);
        for (size_t i = 0; i < n; ++i) {
            r.bits_[i] = bits_[i] || o.bits_[i];
        }
        return r;
    }

    BoolVector operator!() const {
        BoolVector r;
        r.bits_.resize(bits_.size());
        for (size_t i = 0; i < bits_.size(); ++i) {
            r.bits_[i] = !bits_[i];
        }
        return r;
    }

    void counts() const {
        const int ones = static_cast<int>(count(bits_.begin(), bits_.end(), true));
        cout << "Одиниць: " << ones << ", нулів: " << bits_.size() - ones << '\n';
    }
};

void task_21_1() {
    BoolVector a, b;
    a.input();
    b.input();
    cout << "a&b: ";
    (a & b).print();
    cout << "a|b: ";
    (a | b).print();
    cout << "!a: ";
    (!a).print();
    a.counts();
}

// 21.2. Переставити list: спочатку <=X, потім >X без зміни розміру.
void task_21_2() {
    list<int> L;
    cout << "Числа (0 — кінець): ";
    while (true) {
        int x{};
        cin >> x;
        if (x == 0) {
            break;
        }
        L.push_back(x);
    }
    int X{};
    cout << "X: ";
    cin >> X;
    auto it = L.begin();
    for (auto cur = L.begin(); cur != L.end(); ++cur) {
        if (*cur <= X) {
            L.splice(it, L, cur);
            ++it;
        }
    }
    cout << "Результат: ";
    for (int v : L) {
        cout << v << ' ';
    }
    cout << '\n';
}

// 21.3. Сума k найбільших / масив k найменших.
void task_21_3() {
    int n{}, k{};
    cout << "n k: ";
    cin >> n >> k;
    vector<int> v(n);
    cout << "Елементи: ";
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
    }
    if (k > n) {
        cout << "k > n: сума=0, масив порожній\n";
        return;
    }
    vector<int> tmp = v;
    nth_element(tmp.begin(), tmp.begin() + (n - k), tmp.end());
    long long sumTop = 0;
    for (int i = n - k; i < n; ++i) {
        sumTop += tmp[i];
    }
    cout << "Сума " << k << " найбільших: " << sumTop << '\n';

    nth_element(v.begin(), v.begin() + k, v.end());
    cout << k << " найменших: ";
    for (int i = 0; i < k; ++i) {
        cout << v[i] << ' ';
    }
    cout << '\n';
}

// 21.4. Генератор clock(); list create_n; unique; copy.
clock_t clockGen() { return clock(); }

void task_21_4() {
  list<clock_t> L(10);
  generate_n(L.begin(), 10, clockGen);
  L.sort();
  L.unique();
  copy(L.begin(), L.end(), ostream_iterator<clock_t>(cout, " "));
  cout << '\n';
}

// 21.5. transform + toupper — один виклик для рядка.
void task_21_5() {
    string s;
    cout << "Рядок: ";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    getline(cin, s);
    transform(s.begin(), s.end(), s.begin(), [](unsigned char c) { return toupper(c); });
    cout << s << '\n';
}

// 21.6. Функтор Sum для for_each.
template <typename T>
struct Sum {
    T total{};

    void operator()(const T &x) { total += x; }
};

void task_21_6() {
    vector<double> v;
    cout << "Числа (Enter — кінець рядка):\n";
    double x{};
    while (cin >> x) {
        v.push_back(x);
        if (cin.peek() == '\n') {
            break;
        }
    }
    Sum<double> s;
    for_each(v.begin(), v.end(), s);
    cout << "Сума: " << s.total << '\n';
}

// 21.7. Генератор анаграм слова.
void permuteWord(string &s, size_t l, vector<string> &out) {
    if (l >= s.size()) {
        out.push_back(s);
        return;
    }
    for (size_t i = l; i < s.size(); ++i) {
        swap(s[l], s[i]);
        permuteWord(s, l + 1, out);
        swap(s[l], s[i]);
    }
}

void task_21_7() {
    string w;
    cout << "Слово: ";
    cin >> w;
    vector<string> all;
    permuteWord(w, 0, all);
    sort(all.begin(), all.end());
    all.erase(unique(all.begin(), all.end()), all.end());
    for (const string &a : all) {
        cout << a << '\n';
    }
}

// 21.8. Анаграми речення (перестановки слів).
void permuteWords(vector<string> &words, size_t l, vector<string> &out) {
    if (l >= words.size()) {
        ostringstream oss;
        for (size_t i = 0; i < words.size(); ++i) {
            if (i) {
                oss << ' ';
            }
            oss << words[i];
        }
        out.push_back(oss.str());
        return;
    }
    for (size_t i = l; i < words.size(); ++i) {
        swap(words[l], words[i]);
        permuteWords(words, l + 1, out);
        swap(words[l], words[i]);
    }
}

void task_21_8() {
    string line;
    cout << "Речення: ";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    getline(cin, line);
    istringstream iss(line);
    vector<string> words;
    string w;
    while (iss >> w) {
        words.push_back(w);
    }
    vector<string> out;
    permuteWords(words, 0, out);
    sort(out.begin(), out.end());
    out.erase(unique(out.begin(), out.end()), out.end());
    for (const string &s : out) {
        cout << s << '\n';
    }
}

void printMenu() {
    cout << "\n=== KR Розділ 21 ===\n";
    for (int i = 1; i <= 8; ++i) {
        cout << i << "-21_" << i << ' ';
    }
    cout << "\n0-вихід\nОберіть: ";
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
            task_21_1();
            break;
        case 2:
            task_21_2();
            break;
        case 3:
            task_21_3();
            break;
        case 4:
            task_21_4();
            break;
        case 5:
            task_21_5();
            break;
        case 6:
            task_21_6();
            break;
        case 7:
            task_21_7();
            break;
        case 8:
            task_21_8();
            break;
        case 0:
            return 0;
        default:
            cout << "?\n";
        }
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
}
