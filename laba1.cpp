#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int toDecimal(string number, int base) {
    int result = 0;
    for (char c : number) {
        int digit = (isdigit(c)) ? c - '0' : toupper(c) - 'A' + 10;
        result = result * base + digit;
    }
    return result;
}

void processInput(string input) {
    size_t space = input.find(' ');
    if (space == string::npos) {
        cout << "Ошибка ввода!" << endl;
        return;
    }
    string number = input.substr(0, space);
    int base = stoi(input.substr(space + 1));
    if (base < 2 || base > 16) {
        cout << "Неверное основание!" << endl;
        return;
    }
    cout << "Десятичное число: " << toDecimal(number, base) << endl;
}

void readFile(string filename) {
    ifstream file(filename);
    string line;
    while (getline(file, line)) processInput(line);
    file.close();
}

int main() {
    cout << "1 - Ввести вручную, 2 - Файл: ";
    int choice;
    cin >> choice;
    cin.ignore();
    if (choice == 1) {
        cout << "Введите число и основание: ";
        string input;
        getline(cin, input);
        processInput(input);
    }
    else if (choice == 2) {
        cout << "Имя файла: ";
        string filename;
        cin >> filename;
        readFile(filename);
    }
    else {
        cout << "Ошибка выбора!" << endl;
    }
    return 0;
}