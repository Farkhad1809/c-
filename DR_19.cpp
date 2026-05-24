// DR_20.cpp — Розділ 20. Домашня робота (20.16, 20.20)
// Студент: Фархад Фаталієв

#include <fstream>
#include <iomanip>
#include <iostream>
#include <limits>
#include <map>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

// 20.16. Групування елементів V за останньою цифрою; map<int, vector<int>>.
void task_20_16() {
    int n{};
    cout << "Кількість чисел: ";
    cin >> n;
    vector<int> v(n);
    cout << "Елементи: ";
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
    }
    map<int, vector<int>> groups;
    for (int x : v) {
        const int key = abs(x) % 10;
        groups[key].push_back(x);
    }
    for (const auto &p : groups) {
        cout << p.first << ": ";
        for (int x : p.second) {
            cout << x << ' ';
        }
        cout << '\n';
    }
}

struct GradeRec {
    string surname;
    string initials;
    char subject{};
    int mark{};
};

// 20.20. Бінарний файл оцінок; середні по предметах (як 19.20).
void task_20_20() {
    const string bin = "grades20.bin";
    cout << "Записів: ";
    int cnt{};
    cin >> cnt;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    ofstream out(bin, ios::binary);
    for (int i = 0; i < cnt; ++i) {
        GradeRec g;
        cout << "Прізвище ініціали предмет оцінка: ";
        cin >> g.surname >> g.initials >> g.subject >> g.mark;
        const size_t sn = g.surname.size(), in = g.initials.size();
        out.write(reinterpret_cast<const char *>(&sn), sizeof(sn));
        out.write(g.surname.data(), static_cast<streamsize>(sn));
        out.write(reinterpret_cast<const char *>(&in), sizeof(in));
        out.write(g.initials.data(), static_cast<streamsize>(in));
        out.write(reinterpret_cast<const char *>(&g.subject), sizeof(g.subject));
        out.write(reinterpret_cast<const char *>(&g.mark), sizeof(g.mark));
    }
    out.close();

    ifstream in(bin, ios::binary);
    map<pair<string, string>, map<char, vector<int>>> data;
    while (in.peek() != EOF) {
        GradeRec g;
        size_t sn{}, inLen{};
        in.read(reinterpret_cast<char *>(&sn), sizeof(sn));
        g.surname.resize(sn);
        in.read(g.surname.data(), static_cast<streamsize>(sn));
        in.read(reinterpret_cast<char *>(&inLen), sizeof(inLen));
        g.initials.resize(inLen);
        in.read(g.initials.data(), static_cast<streamsize>(inLen));
        in.read(reinterpret_cast<char *>(&g.subject), sizeof(g.subject));
        in.read(reinterpret_cast<char *>(&g.mark), sizeof(g.mark));
        data[{g.surname, g.initials}][g.subject].push_back(g.mark);
    }
    cout << fixed << setprecision(2);
    for (const auto &st : data) {
        auto avg = [&](char s) {
            const auto it = st.second.find(s);
            if (it == st.second.end() || it->second.empty()) {
                return 0.0;
            }
            double sum = 0;
            for (int m : it->second) {
                sum += m;
            }
            return sum / it->second.size();
        };
        cout << st.first.first << ' ' << st.first.second << "  alg=" << avg('A')
             << " geom=" << avg('G') << " inf=" << avg('I') << '\n';
    }
}

int main() {
    while (true) {
        cout << "\n=== DR Розділ 20 ===\n1-20_16, 2-20_20, 0-вихід\nОберіть: ";
        int c{};
        if (!(cin >> c)) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }
        switch (c) {
        case 1:
            task_20_16();
            break;
        case 2:
            task_20_20();
            break;
        case 0:
            return 0;
        default:
            cout << "?\n";
        }
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
}
