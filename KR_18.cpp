// KR_20.cpp — Розділ 20. Класна робота (20.1–20.3)
// Студент: Фархад Фаталієв

#include <algorithm>
#include <cmath>
#include <fstream>
#include <iostream>
#include <limits>
#include <map>
#include <set>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

struct Point {
    int x{}, y{};
};

// 20.1. Текст англійською; map — частота слів (регістр враховується).
void task_20_1() {
    string fname;
    cout << "Ім'я файлу: ";
    cin >> fname;
    ifstream in(fname);
    if (!in) {
        cout << "Не вдалося відкрити.\n";
        return;
    }
    map<string, int> freq;
    string word;
    while (in >> word) {
        ++freq[word];
    }
    for (const auto &p : freq) {
        cout << p.first << ": " << p.second << '\n';
    }
}

// 20.2. Set: попарне підсумовування сусідніх до одного числа.
void task_20_2() {
    cout << "Кількість чисел: ";
    int n{};
    cin >> n;
    vector<double> cur(n);
    cout << "Числа: ";
    for (int i = 0; i < n; ++i) {
        cin >> cur[i];
    }
    if (cur.size() < 2) {
        cout << "Потрібно щонайменше 2 числа.\n";
        return;
    }
    while (cur.size() > 1) {
        vector<double> nxt;
        for (size_t i = 0; i + 1 < cur.size(); i += 2) {
            nxt.push_back(cur[i] + cur[i + 1]);
        }
        if (cur.size() % 2) {
            nxt.push_back(cur.back());
        }
        cur.swap(nxt);
    }
    cout << "Результат: " << cur[0] << '\n';
}

// 20.3. Координати точок у файлі; відрізки між усіма парами, сортування за довжиною.
double dist(const Point &a, const Point &b) {
    const double dx = a.x - b.x, dy = a.y - b.y;
    return sqrt(dx * dx + dy * dy);
}

void task_20_3() {
    string inName, outName;
    cout << "Вхідний файл: ";
    cin >> inName;
    cout << "Вихідний файл: ";
    cin >> outName;
    ifstream in(inName);
    if (!in) {
        cout << "Помилка читання.\n";
        return;
    }
    string raw;
    getline(in, raw);
    vector<Point> pts;
    size_t i = 0;
    while (i < raw.size()) {
        if (raw[i] == '(') {
            Point p{};
            if (sscanf(raw.c_str() + i, "(%d,%d)", &p.x, &p.y) == 2) {
                pts.push_back(p);
            }
            ++i;
            while (i < raw.size() && raw[i] != ')') {
                ++i;
            }
        }
        ++i;
    }
    struct Seg {
        Point a, b;
        double len;
    };
    vector<Seg> segs;
    for (size_t u = 0; u < pts.size(); ++u) {
        for (size_t v = u + 1; v < pts.size(); ++v) {
            segs.push_back({pts[u], pts[v], dist(pts[u], pts[v])});
        }
    }
    sort(segs.begin(), segs.end(), [](const Seg &x, const Seg &y) { return x.len < y.len; });
    ofstream out(outName);
    for (const Seg &s : segs) {
        const string line = "(" + to_string(s.a.x) + "," + to_string(s.a.y) + ")-(" +
                            to_string(s.b.x) + "," + to_string(s.b.y) +
                            ") len=" + to_string(s.len);
        out << line << '\n';
        cout << line << '\n';
    }
}

void printMenu() {
    cout << "\n=== KR Розділ 20 ===\n1-20_1, 2-20_2, 3-20_3, 0-вихід\nОберіть: ";
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
            task_20_1();
            break;
        case 2:
            task_20_2();
            break;
        case 3:
            task_20_3();
            break;
        case 0:
            return 0;
        default:
            cout << "?\n";
        }
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
}
