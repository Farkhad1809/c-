// KR_16.cpp — Розділ 16. Класна робота (16.1)
// Студент: Фархад Фаталієв

#include <fstream>
#include <iostream>
#include <limits>
#include <string>
#include <vector>

using namespace std;

// 16.1. Person → Acquaintance → телефонний довідник (до 100), файл, пошук за прізвищем.
class Person {
protected:
    string name_;
    unsigned byear_{2000};

public:
    virtual ~Person() = default;

    virtual void input() {
        cout << "Прізвище: ";
        cin >> name_;
        cout << "Рік народження: ";
        cin >> byear_;
    }

    virtual void show() const {
        cout << name_ << ", " << byear_;
    }

    const string &name() const { return name_; }
    unsigned byear() const { return byear_; }
};

class Acquaintance : public Person {
    string phone_;

public:
    void input() override {
        Person::input();
        cout << "Телефон: ";
        cin >> phone_;
    }

    void show() const override {
        Person::show();
        cout << ", тел: " << phone_;
    }

    const string &phone() const { return phone_; }
    void setPhone(const string &p) { phone_ = p; }

    void loadLine(const string &n, unsigned y, const string &p) {
        name_ = n;
        byear_ = y;
        phone_ = p;
    }
};

class PhoneBook {
    vector<Acquaintance> data_;

public:
    bool add() {
        if (data_.size() >= 100) {
            cout << "Довідник заповнений (100).\n";
            return false;
        }
        Acquaintance a;
        a.input();
        data_.push_back(a);
        return true;
    }

    void findBySurname() const {
        string s;
        cout << "Прізвище: ";
        cin >> s;
        bool ok = false;
        for (const auto &a : data_) {
            if (a.name() == s) {
                a.show();
                cout << '\n';
                ok = true;
            }
        }
        if (!ok) {
            cout << "Не знайдено.\n";
        }
    }

    void replacePhone() {
        string s, p;
        cout << "Прізвище: ";
        cin >> s;
        for (auto &a : data_) {
            if (a.name() == s) {
                cout << "Новий телефон: ";
                cin >> p;
                a.setPhone(p);
                cout << "Оновлено.\n";
                return;
            }
        }
        cout << "Не знайдено.\n";
    }

    void save(const string &path) const {
        ofstream out(path);
        for (const auto &a : data_) {
            out << a.name() << ' ' << a.byear() << ' ' << a.phone() << '\n';
        }
        cout << "Збережено: " << path << '\n';
    }

    void load(const string &path) {
        ifstream in(path);
        if (!in) {
            cout << "Не вдалося відкрити файл.\n";
            return;
        }
        data_.clear();
        string n, p;
        unsigned y{};
        while (in >> n >> y >> p) {
            Acquaintance a;
            a.loadLine(n, y, p);
            data_.push_back(a);
        }
        cout << "Завантажено " << data_.size() << " записів.\n";
    }

    void list() const {
        for (const auto &a : data_) {
            a.show();
            cout << '\n';
        }
    }
};

void task_16_1() {
    PhoneBook book;
    int op{};
    do {
        cout << "\n1-додати 2-пошук 3-заміна тел. 4-список 5-зберегти 6-завантажити 0-вихід\n";
        cin >> op;
        switch (op) {
        case 1:
            book.add();
            break;
        case 2:
            book.findBySurname();
            break;
        case 3:
            book.replacePhone();
            break;
        case 4:
            book.list();
            break;
        case 5:
            book.save("phonebook.txt");
            break;
        case 6:
            book.load("phonebook.txt");
            break;
        case 0:
            break;
        default:
            cout << "?\n";
        }
    } while (op != 0);
}

int main() {
    task_16_1();
    return 0;
}
