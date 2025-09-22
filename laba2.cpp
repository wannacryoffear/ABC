#include <iostream>
#include <iomanip>
#include <cstring>

using namespace std;

int main() {
    float num;
    cout << "Введите число: ";
    cin >> num;

    unsigned int bits;
    memcpy(&bits, &num, sizeof(bits));

    cout << "Битовое представление: ";
    for (int i = 31; i >= 0; --i) {
        cout << ((bits >> i) & 1);
        if (i % 8 == 0) cout << " ";
    }
    cout << endl;

    cout << "В шестнадцатеричной форме (IEEE-754): 0x"
        << hex << uppercase << bits << endl;

    return 0;
}
