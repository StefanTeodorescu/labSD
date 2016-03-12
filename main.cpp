#include <iostream>
#include "lista.h"

using namespace std;

int main() {

	List<int> v;
    for (int i = 1; i <= 10; i ++) {
        v.push_back(i);
    }

    for (int i = 0; i < v.length(); i ++) {
        cout << v[i] << " ";
    }
    return 0;
}