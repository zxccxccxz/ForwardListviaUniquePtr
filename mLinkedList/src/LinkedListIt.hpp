#ifndef LINKED_LIST_IT_H
#define LINKED_LIST_IT_H

#include "LinkedList.hpp"

template <typename T>
class LinkedList;

template <typename ListType>
class LinkedListIt {
	using value_t = typename ListType::value_t;
	using ref_t = value_t&;
	using ptr_t = value_t*;

	using node_t = typename ListType::Node;
	using node_ptr = node_t*;

public:
	LinkedListIt(node_ptr ptr) : ptr_(ptr) {

	}

	ref_t operator*() const {
		return ptr_->data_;
	}

	ptr_t operator->() const {
		return &ptr_->data_;
	}

	LinkedListIt& operator++() {
		ptr_ = ptr_->next_.get();
		return *this;
	}

	bool operator==(const LinkedListIt& other) const {
		return this->ptr_ == other.ptr_;
	}

	bool operator!=(const LinkedListIt& other) const {
		return !(this->ptr_ == other.ptr_);
	}


private:
	node_ptr ptr_;
};

#endif