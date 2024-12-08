#include <iostream>
using namespace std;

union EndianTest {
    int num;
    char bytes[sizeof(int)];
};

int main() {
    EndianTest test;
    test.num = 1;

    if (test.bytes[0] == 1) {
        cout << "Малый порядок байт (Little Endian)" << endl;
    } else {
        cout << "Большой порядок байт (Big Endian)" << endl;
    }

    return 0;
}
