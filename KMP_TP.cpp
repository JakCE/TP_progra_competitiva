/*
INTEGRANTES:
Jak Cristian Campos Espinoza -U20211A184
Alejandro Olaf López Flores - U201922773
*/

#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<int> compute_lps(string& pattern) {
    int n = pattern.size();
    vector<int> lps(n);
    lps[0] = 0;
    int len = 0;
    int i = 1;
    while (i < n) {
        if (pattern[i] == pattern[len]) {
            len++;
            lps[i] = len;
            i++;
        }
        else {
            if (len != 0) {
                len = lps[len - 1];
            }
            else {
                lps[i] = 0;
                i++;
            }
        }
    }
    return lps;
}

void kmp_search_and_remove(string& text, string& pattern) {
    int n = text.size();
    int m = pattern.size();
    vector<int> lps = compute_lps(pattern);
    int i = 0;
    int j = 0;
    int count = 0;
    while (i < n) {
        if (text[i] == pattern[j]) {
            i++;
            j++;
        }
        if (j == m) {
            // Found pattern
            count++;
            if (count > 3) {
                cout << "El patrón es muy frecuente en el texto." << endl;
                return;
            }
            // Remove pattern from text
            text.erase(i - m, m);

            n = text.size();
            i -= m;
            j = 0;
        }
        else if (i < n && text[i] != pattern[j]) {
            if (j != 0) {
                j = lps[j - 1];
            }
            else {
                i++;
            }
        }
    }
    if (count == 0) {
        cout << "No encontró patrón." << endl;
    }
    else {
        cout << text << endl;
    }
}

int main() {
    int T;
    cout << "Ingrese el número de casos de prueba: ";
    cin >> T;
    while (T--) {
        string text, pattern;
        int text_size, pattern_size;
        cout << "Ingrese el tamaño del texto: ";
        cin >> text_size;
        cout << "Ingrese el tamaño del patrón: ";
        cin >> pattern_size;
        cout << "Ingrese el texto: ";
        cin >> text;
        cout << "Ingrese el patrón: ";
        cin >> pattern;
        kmp_search_and_remove(text, pattern);
    }
    return 0;
}