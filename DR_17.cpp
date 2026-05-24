// DR_19.cpp — Розділ 19. Домашня робота (19.20)
// Студент: Фархад Фаталієв

#include <algorithm>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <limits>
#include <map>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

struct GradeRec {
    string surname;
    string initials;
    int cls{};
    char subject{};
    int mark{};
};

// 19.20. Бінарний файл оцінок; середні по алгебрі, геометрії, інформатиці для кожного учня.
void task_19_20() {
    const string inName = "grades.bin";
    const string outName = "grades_avg.txt";

    cout << "Скільки записів записати у " << inName << "? ";
    int cnt{};
    cin >> cnt;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    {
        ofstream out(inName, ios::binary);
        for (int i = 0; i < cnt; ++i) {
            GradeRec g;
            cout << "\nПрізвище ініціали клас предмет(A/G/I) оцінка: ";
            getline(cin, g.surname, ' ');
            string rest;
            getline(cin, rest);
            istringstream iss(rest);
            iss >> g.initials >> g.cls >> g.subject >> g.mark;
            const size_t sn = g.surname.size(), in = g.initials.size();
            out.write(reinterpret_cast<const char *>(&sn), sizeof(sn));
            out.write(g.surname.data(), static_cast<streamsize>(sn));
            out.write(reinterpret_cast<const char *>(&in), sizeof(in));
            out.write(g.initials.data(), static_cast<streamsize>(in));
            out.write(reinterpret_cast<const char *>(&g.cls), sizeof(g.cls));
            out.write(reinterpret_cast<const char *>(&g.subject), sizeof(g.subject));
            out.write(reinterpret_cast<const char *>(&g.mark), sizeof(g.mark));
        }
    }

    ifstream in(inName, ios::binary);
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
        in.read(reinterpret_cast<char *>(&g.cls), sizeof(g.cls));
        in.read(reinterpret_cast<char *>(&g.subject), sizeof(g.subject));
        in.read(reinterpret_cast<char *>(&g.mark), sizeof(g.mark));
        data[{g.surname, g.initials}][g.subject].push_back(g.mark);
    }

    ofstream report(outName);
    cout << fixed << setprecision(2);
    for (const auto &student : data) {
        auto avg = [&](char subj) {
            const auto it = student.second.find(subj);
            if (it == student.second.end() || it->second.empty()) {
                return 0.0;
            }
            double s = 0;
            for (int m : it->second) {
                s += m;
            }
            return s / it->second.size();
        };
        const double a = avg('A'), g = avg('G'), inf = avg('I');
        cout << student.first.first << ' ' << student.first.second << "  A=" << a << " G=" << g
             << " I=" << inf << '\n';
        report << student.first.first << ' ' << student.first.second << ' ' << a << ' ' << g << ' '
               << inf << '\n';
    }
    cout << "Звіт у " << outName << '\n';
}

int main() {
    task_19_20();
    return 0;
}
