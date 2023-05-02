/*
INTEGRANTES:
Jak Cristian Campos Espinoza -U20211A184
Alejandro Olaf López Flores - U201922773
*/

#include <iostream>
#include <map>
#include <string>
#include <vector>
using namespace std;

void contar_palabras(const vector<string>& palabras) {
    map<string, int> frecuencia;
    for (const string& word : palabras) {
        frecuencia[word]++;
    }
    for (auto entry : frecuencia) {
        cout << entry.first << " " << entry.second << endl;
    }
}

int main() {
    vector<string> palabras = { "gato", "perro", "gato", "ratón", "perro", "perro" };
    contar_palabras(palabras);
    return 0;
}