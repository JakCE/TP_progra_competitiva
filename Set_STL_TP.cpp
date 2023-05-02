/*
INTEGRANTES:
Jak Cristian Campos Espinoza -U20211A184
Alejandro Olaf López Flores - U201922773
*/

#include <iostream>
#include <set>
#include <utility>
using namespace std;

void encontrar_pares(const set<int>& numeros, int k) {
    set<pair<int, int>> pares;
    for (int x : numeros) {
        int y = k - x;
        if (numeros.count(y) && x <= y) {
            pares.insert(make_pair(x, y));
        }
    }
    for (auto p : pares) {
        if (p.first != p.second)
            cout << p.first << " " << p.second << endl;
    }
}

int main() {
    set<int> numeros = { 3, 4, 5, 6, 7 };
    int k = 10;
    encontrar_pares(numeros, k);
    return 0;
}