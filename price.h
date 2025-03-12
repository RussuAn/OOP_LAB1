#ifndef PRICE_H
#define PRICE_H

#include <iostream>
#include <fstream>
using namespace std;

struct Price {
    int grn;
    short int kop;
};

void add(Price &a, Price &b);
void mult(Price &a, int qnt);
void roundto10(Price &m);
void print(Price m);
void runcode(const string &filename);

#endif