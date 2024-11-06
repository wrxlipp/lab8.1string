#include <iostream>
#include <string>
using namespace std;

// Функція для підрахунку кількості входжень символів "+", "-", "="
int Count(const string& s) {
    int k = 0;
    size_t pos = 0;
    // Шукаємо символи "+" в рядку
    while ((pos = s.find('+', pos)) != string::npos) {
        pos++;  // Переміщаємо позицію на наступний символ
        if (pos < s.size() && s[pos] == '-') {
            k++;  // Якщо після "+" йде "-", збільшуємо лічильник
        }
    }
    // Повторюємо те ж саме для символів "-" і "="
    pos = 0;
    while ((pos = s.find('-', pos)) != string::npos) {
        pos++;
        if (pos < s.size() && s[pos] == '=') {
            k++;
        }
    }

    return k;
}

// Функція для заміни символів "+", "-", "=" на "**"
string Change(string& s) {
    size_t pos = 0;
    while ((pos = s.find('+', pos)) != string::npos) {
        s.replace(pos, 1, "**");
        pos += 2;  // Оскільки замінюємо один символ на два
    }

    pos = 0;
    while ((pos = s.find('-', pos)) != string::npos) {
        s.replace(pos, 1, "**");
        pos += 2;
    }

    pos = 0;
    while ((pos = s.find('=', pos)) != string::npos) {
        s.replace(pos, 1, "**");
        pos += 2;
    }

    return s;
}

int main() {
    string str;
    cout << "Enter string:" << endl;
    getline(cin, str);  // Вводимо рядок

    // Виводимо кількість символів "+", "-", "="
    cout << "Total occurrences of '+', '-', '=': " << Count(str) << endl;

    // Модифікуємо рядок, замінюючи символи на "**"
    string modifiedStr = Change(str);

    // Виводимо результат
    cout << "Modified string: " << modifiedStr << endl;

    return 0;
}
