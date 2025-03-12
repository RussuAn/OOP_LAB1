#include "price.h"

void add(Price &a, Price &b) {
    a.grn += b.grn;
    a.kop += b.kop;

    if (a.kop >= 100) {
        a.grn += 1;
        a.kop %= 100;
    }
}

void mult(Price &a, int qnt) {
    int total_kop = (a.grn * 100 + a.kop) * qnt;
    a.grn = total_kop / 100;
    a.kop = total_kop % 100;
}

void roundto10(Price &m) {
    if (m.kop % 10 < 5) {
        m.kop -= m.kop % 10;
    } else {
        m.kop += (10 - m.kop % 10);
    }

    if (m.kop == 100) {
        m.kop = 0;
        m.grn += 1;
    }
}

void print(Price m) {
    cout << m.grn << " грн " << m.kop << " копійок.\n";
}

void runcode(const string &filename) {
    ifstream file(filename);
    if (!file) {
        cout << "Неможливо відкрити файл!\n";
        return;
    }

    Price total = {0, 0};
    int grn, qnt;
    short int kop;

    while (file >> grn >> kop >> qnt) {
        Price item = {grn, kop};
        mult(item, qnt);
        add(total, item);
    }
    file.close();

    cout << "Загальна сума: ";
    print(total);

    roundto10(total);
    cout << "Сума до сплати: ";
    print(total);
}