#include "LinkedList.hpp"
#include "LinkedListIt.hpp"
#include "LinkedList.cpp"
#include <string>
#include <vector>

// test class
struct A {
	int x;
	char y;
	A(int a, char b) : x(a), y(b) {
		std::cout << "A ctor" << std::endl;
	}

	A(const A& o) : x(o.x), y(o.y) { 
		std::cout << "A copy ctor" << std::endl; 
	}

	A(A&& o) noexcept : x(std::move(o.x)), y(std::move(o.y)) {
		std::cout << "A move ctor" << std::endl;
	}

	~A() {
		std::cout << "A dtor" << std::endl;
	}

	friend std::ostream& operator <<(std::ostream& os, const A& a) {
		return os << a.x << " " << a.y;
	}
};

//template<typename T, template <class, class> class Container>
//class Deque {
//private:
//	Container<T, std::allocator<T>> v;
//};

int main() {
	
	LinkedList<A> ll;

	ll.emplace_front(1, 'a');
	ll.emplace_front(2, 'b');
	// ll.pop_front();
	ll.emplace_front(3, 'c');
	// ll.print();

	// ! causes stackoverflow
	//for (int i = 0; i < 100000; ++i) {
	//	ll.emplace_front(7, 'f');
	//}

	for (auto& el : ll) {
		std::cout << "> " << el << std::endl;
	}

	std::cin.get();

	return 0;
}
