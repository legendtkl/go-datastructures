#include <iostream>

void foo1() {
	foo2();
}

void foo2() {
	std::cout << "hello";
}

int main() {
	foo1();
	return 0;
}
