// DR_17.cpp — Розділ 17. Домашня робота (17.7)
// Студент: Фархад Фаталієв

#include <fstream>
#include <iostream>
#include <limits>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

// 17.7. Клас роботи з текстовими файлами: дійсні числа через пробіли у рядках.
class TextDoubleFile {
    string path_;
    size_t count_{0};
    size_t rows_{0};

public:
    explicit TextDoubleFile(string path) : path_(move(path)) {}

    void readFromConsoleToFile() {
        cout << "Рядків: ";
        cin >> rows_;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        ofstream out(path_);
        count_ = 0;
        for (size_t r = 0; r < rows_; ++r) {
            cout << "Рядок " << r + 1 << " (числа через пробіл): ";
            string line;
            getline(cin, line);
            out << line << '\n';
            istringstream iss(line);
            double v{};
            while (iss >> v) {
                ++count_;
            }
        }
        cout << "Записано. Чисел: " << count_ << '\n';
    }

    void print() const {
        ifstream in(path_);
        if (!in) {
            cout << "Файл не відкрито.\n";
            return;
        }
        string line;
        int r = 0;
        while (getline(in, line)) {
            cout << ++r << ": " << line << '\n';
        }
    }

    void reverseNumber(size_t index) {
        ifstream in(path_);
        vector<double> vals;
        string line;
        while (getline(in, line)) {
            istringstream iss(line);
            double v{};
            while (iss >> v) {
                vals.push_back(v);
            }
        }
        if (index == 0 || index > vals.size()) {
            cout << "Некоректний номер.\n";
            return;
        }
        double &x = vals[index - 1];
        x = -x;
        ofstream out(path_);
        for (size_t i = 0; i < vals.size(); ++i) {
            if (i) {
                out << ' ';
            }
            out << vals[i];
            if ((i + 1) % 5 == 0) {
                out << '\n';
            }
        }
        out << '\n';
        cout << "Число #" << index << " інвертовано за знаком.\n";
    }
};

void task_17_7() {
    TextDoubleFile f("doubles.txt");
    int op{};
    do {
        cout << "\n1-запис з консолі 2-перегляд 3-інвертувати число 0-вихід\n";
        cin >> op;
        switch (op) {
        case 1:
            f.readFromConsoleToFile();
            break;
        case 2:
            f.print();
            break;
        case 3: {
            size_t i{};
            cout << "Номер числа: ";
            cin >> i;
            f.reverseNumber(i);
            break;
        }
        case 0:
            break;
        default:
            cout << "?\n";
        }
    } while (op != 0);
}

int main() {
    task_17_7();
    return 0;
}
