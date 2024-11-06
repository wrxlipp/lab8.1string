#include <iostream>
#include <string>
using namespace std;

// ������� ��� ��������� ������� �������� ������� "+", "-", "="
int Count(const string& s) {
    int k = 0;
    size_t pos = 0;
    // ������ ������� "+" � �����
    while ((pos = s.find('+', pos)) != string::npos) {
        pos++;  // ��������� ������� �� ��������� ������
        if (pos < s.size() && s[pos] == '-') {
            k++;  // ���� ���� "+" ��� "-", �������� ��������
        }
    }
    // ���������� �� � ���� ��� ������� "-" � "="
    pos = 0;
    while ((pos = s.find('-', pos)) != string::npos) {
        pos++;
        if (pos < s.size() && s[pos] == '=') {
            k++;
        }
    }

    return k;
}

// ������� ��� ����� ������� "+", "-", "=" �� "**"
string Change(string& s) {
    size_t pos = 0;
    while ((pos = s.find('+', pos)) != string::npos) {
        s.replace(pos, 1, "**");
        pos += 2;  // ������� �������� ���� ������ �� ���
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
    getline(cin, str);  // ������� �����

    // �������� ������� ������� "+", "-", "="
    cout << "Total occurrences of '+', '-', '=': " << Count(str) << endl;

    // ���������� �����, �������� ������� �� "**"
    string modifiedStr = Change(str);

    // �������� ���������
    cout << "Modified string: " << modifiedStr << endl;

    return 0;
}
