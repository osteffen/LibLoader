#include <iostream>
using namespace std;

extern "C" {
int hook() {
    cout << "hook in lib1" << endl;
    return 5;
}
}
