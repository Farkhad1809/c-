// DR_16.cpp — Розділ 16. Домашня робота (16.11)
// Студент: Фархад Фаталієв

#include <iostream>
#include <limits>

using namespace std;

// 16.11. Machine, Personal, Truck; fuelPerKm(); go(distance); перевірка проїзду.
class Machine {
protected:
    double fuel_{50.0};
    double km_{0.0};

    virtual double fuelPerKm() const = 0;

public:
    virtual ~Machine() = default;

    bool go(double distance) {
        const double need = distance * fuelPerKm();
        if (need > fuel_) {
            cout << "Недостатньо палива (потрібно " << need << ", є " << fuel_ << ").\n";
            return false;
        }
        fuel_ -= need;
        km_ += distance;
        cout << "Проїхали " << distance << " км. Залишок палива: " << fuel_ << '\n';
        return true;
    }

    void setFuel(double f) { fuel_ = f; }
};

class Personal : public Machine {
    int passengers_{0};

    double fuelPerKm() const override {
        return 0.08 * (1.0 + 0.1 * passengers_);
    }

public:
    void setPassengers(int p) { passengers_ = p; }
};

class Truck : public Machine {
    double cargoTons_{0};

    double fuelPerKm() const override {
        return 0.2 * (1.0 + 0.25 * cargoTons_);
    }

public:
    void setCargo(double t) { cargoTons_ = t; }
};

void task_16_11() {
    char type{};
    cout << "Тип (p-легковий, t-вантажівка): ";
    cin >> type;
    double fuel{}, dist{};
    cout << "Паливо (л): ";
    cin >> fuel;

    if (type == 'p' || type == 'P') {
        Personal car;
        int pass{};
        cout << "Пасажири: ";
        cin >> pass;
        car.setPassengers(pass);
        car.setFuel(fuel);
        cout << "Відстань (км): ";
        cin >> dist;
        car.go(dist);
    } else {
        Truck truck;
        double tons{};
        cout << "Вантаж (т): ";
        cin >> tons;
        truck.setCargo(tons);
        truck.setFuel(fuel);
        cout << "Відстань (км): ";
        cin >> dist;
        truck.go(dist);
    }
}

int main() {
    while (true) {
        cout << "\n=== DR Розділ 16 ===\n1-16_11, 0-вихід\nОберіть: ";
        int c{};
        if (!(cin >> c)) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }
        if (c == 1) {
            task_16_11();
        } else if (c == 0) {
            return 0;
        }
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
}
