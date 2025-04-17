#include <iostream>

using namespace std;

int main() {
    // int a = 10;
    // cout << a << endl;

    // operator * dan &
    // * 
    // &

    int a = 10;
    int *b = &a;
    cout << "Nilai a = " << a << endl;
    cout << "Alamat a = " << &a << endl;
    cout << "Nilai b = " << b << endl;
    cout << "Alamat b = " << &b << endl;

    int c, *d;
    c = 10;
    d = &c;
    cout << "Nilai c = " << c << endl;
    cout << "Alamat c = " << &c << endl;
    cout << "Nilai d = " << d << endl;
    cout << "Alamat d = " << &d << endl;

    return 0;
}