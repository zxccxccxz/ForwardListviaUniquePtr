#include "LinkedList.hpp"
#include "LinkedListIt.hpp"

template <typename ListType>
class LinkedListIt;

template <class T>
void LinkedList<T>::push_front(const T& data) {
	if (!head_) {
		head_ = std::make_unique<Node>(data);
	}
	else {
		std::unique_ptr<Node> tmp(std::move(head_));
		head_ = std::make_unique<Node>(data, std::move(tmp));
	}
	++size_;
}

template <class T>
void LinkedList<T>::push_front(T&& data) {
	if (!head_) {
		head_ = std::make_unique<Node>(std::move(data));
	}
	else {
		std::unique_ptr<Node> tmp(std::move(head_));
		head_ = std::make_unique<Node>(std::move(data), std::move(tmp));
	}
	++size_;
}

template <class T>
void LinkedList<T>::pop_front() {
	if (!head_)
		return;
	std::unique_ptr<Node> tmp(std::move(head_.get()->next_));
	head_.reset(nullptr);
	head_ = std::move(tmp);
	--size_;
}

template <class T>
void LinkedList<T>::print() const {
	if (!head_)
		return;
	Node* tmp = head_.get();
	for (size_t i = 0; i < size_; ++i) {
		std::cout << i << ". " << tmp->GetData() << "\n";
		tmp = tmp->next_.get();
	}
}

template <class T>
template <typename...Args>
void LinkedList<T>::emplace_front(Args&&... args) {
	if (!head_) {
		head_ = std::make_unique<Node>(nullptr, std::forward<Args>(args)...);
	}
	else {
		std::unique_ptr<Node> tmp(std::move(head_));
		head_ = std::make_unique<Node>(std::move(tmp), std::forward<Args>(args)...);
	}
	++size_;
}

template <class T>
typename LinkedList<T>::Iterator LinkedList<T>::begin() {
	return Iterator(head_.get());
}

template<typename T>
typename LinkedList<T>::Iterator LinkedList<T>::end()
{
	/*if (!head_)
		return;*/
	Iterator tmp = begin();
	while (tmp != nullptr) {
		++tmp;
	}

	return tmp;
}

//template <class T>
//LinkedList<T>::LinkedList() = default;
//
//template <class T>
//LinkedList<T>::~LinkedList() {
//	/* no :\\\\
//	todo: fix possible stackoverflow
//	*/
//}
