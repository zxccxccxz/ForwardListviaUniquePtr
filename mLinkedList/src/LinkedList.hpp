#ifndef LINKED_LIST_H
#define LINKED_LIST_H
#include <memory>
#include <iostream>
#include "LinkedListIt.hpp"

template <typename ListType>
class LinkedListIt;

template <typename T>
class LinkedList {
private:
	template <typename ListType>
	friend class LinkedListIt;

	using value_t = T;
	using Iterator = LinkedListIt<LinkedList<T>>;

	struct Node {
	public:
		T data_;
		std::unique_ptr<Node> next_;

		Node(const T& data, std::unique_ptr<Node>&& next = nullptr) : data_(data), next_(std::move(next)) {
			// std::cout << "Node ctor" << std::endl;
		}

		Node(T&& data, std::unique_ptr<Node>&& next = nullptr) : data_(std::move(data)), next_(std::move(next)) {
			// std::cout << "Node move ctor" << std::endl;
		}

		template <typename...Args>
		Node(std::unique_ptr<Node>&& next, Args&&...args) : data_(std::forward<Args>(args)...), next_(std::move(next)) {
			// std::cout << "Node variadic ctor" << std::endl;
		}

		T& GetData() {
			return data_;
		} 

	};

	std::unique_ptr<Node> head_;
	size_t size_ = 0;

public:
	void push_front(const T& data);

	void push_front(T&& data);

	void pop_fornt();

	void print() const;

	template <typename...Args>
	void emplace_front(Args&&... args);

	LinkedList() = default;

	~LinkedList() {
		/* :\\\\ 
		todo: fix possible stackoverflow
		*/
	}

	Iterator begin();

	Iterator end();

};

#endif