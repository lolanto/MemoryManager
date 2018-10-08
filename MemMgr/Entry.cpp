#include <iostream>
using namespace std;

size_t func(size_t size) {
	if (size <= 4) return 4;
	return (size_t)(ceilf((float)size / 8.0f) * 8);
}

void main() {
	for (int i = 0; i <= 128; ++i) {
		cout << i << ": " << func(i) << endl;
	}
	system("pause");
}