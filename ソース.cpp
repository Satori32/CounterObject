#include <iostream>
#include <cstdint>

template<class T>
class CounterObject {
public:

	CounterObject() {}
	CounterObject(const T& In) :N(In) {}

	bool Increment() {
		N++;
		return true;
	}
	bool Decrement() {
		N--;
		return true;
	}

	const T& Get() {
		return N;
	}

	bool Set(const T& In) {
		N = In;
	}

	T operator ++(T) {
		Increment();
		return Get();
	}

	T operator --(T) {
		Decrement();
		return Get();
	}

	operator T() {
		return N;
	}

protected:
	T N{ 0, };
};

int main() {
	CounterObject<int> CO=10;

	CO++;
	std::cout << CO << std::endl;
	CO--;
	std::cout << CO << std::endl;

	return 0;
}