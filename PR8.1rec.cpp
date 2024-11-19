#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
using namespace std;

int Count(char* str, int i) {
    if (strlen(str) < 2)
        return 0;

    if (str[i + 1] != 0) { // якщо не д≥йшли до к≥нц€ р€дка
        if (str[i] == ',' && str[i + 1] == '-') // «найдена група ",-"
            return 1 + Count(str, i + 1);
        else
            return Count(str, i + 1); // ѕропускаЇмо символ ≥ рухаЇмос€ дал≥
    }
    else {
        return 0;
    }
}

char* Change(char* dest, const char* str, char* t, int i) {
    if (str[i + 1] != 0) { // якщо не д≥йшли до к≥нц€ р€дка
        if (str[i] == ',' && str[i + 1] == '-') { // «найдена група ",-"
            *t++ = '*'; // «ам≥нюЇмо групу на '*'
            return Change(dest, str, t, i + 2);
        }
        else {
            *t++ = str[i]; //  оп≥юЇмо поточний символ
            *t = '\0';
            return Change(dest, str, t, i + 1); // ѕереходимо до наступного символу
        }
    }
    else {
        *t++ = str[i];
        *t = '\0';
        return dest;
    }
}

int main() {
    char str[101];
    cout << "Enter string:" << endl;
    cin.getline(str, 100);

    cout << "String contained " << Count(str, 0) << " groups of \",-\"" << endl;

    char* dest1 = new char[151];
    dest1[0] = '\0';
    char* dest2 = Change(dest1, str, dest1, 0);

    cout << "Modified string (param) : " << dest1 << endl;
    cout << "Modified string (result): " << dest2 << endl;

    delete[] dest1;
    return 0;
}
