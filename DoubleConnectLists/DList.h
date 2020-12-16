#pragma once
#include <iostream>
using namespace std;

template <typename T>
class DList
{
	struct Node
	{
		T data;
		Node* next, *prev;
		Node(const T& data = T(), Node* prev = nullptr, Node* next=nullptr)
			:data(data), next(next), prev(prev)
		{}
	};
public:
	DList() = default;
	//~Dlist();
		
	void pushFront(const T& data);
	void pushBack(const T& data);
	void pushFrontByData(const T& foundData, const T& data);
	void popByData(const T& data);
	void popFront();
	void popBack();
	bool isEmpty() const;
	size_t getSize() const;
	void clear();
	void print() const;
	void printR() const;

private:
	Node* head = nullptr, *tail = nullptr;
	size_t size = 0;
	auto findNode(const T& data);
};

//template<typename T>
//inline DList<T>::~Dlist()
//{
//	cout << "----Destructor-----" << endl;
//	clear();
//}

template<typename T>
inline void DList<T>::pushFront(const T& data)
{
	Node* temp = new Node(data,nullptr, head);
	if (isEmpty()) 	tail = temp; //first
	else
	{
		head->prev = temp;
	}
	head = temp;
	++size;
}

template<typename T>
inline void DList<T>::pushBack(const T& data)
{
	Node* temp = new Node(data, tail, nullptr);
	if (isEmpty())
	{
		head = temp;
	}
	else
	{
		tail->next = temp;
	}
	tail = temp;
	++size;
}

template<typename T>
inline void DList<T>::pushFrontByData(const T& foundData, const T& data)//need to complete
{
	Node* find = findNode(foundData);
	if (find != nullptr) {
		Node* temp = new Node(data, nullptr, find);
		if (isEmpty()) {
			head = temp;
			tail = temp; //first
		}
		else
		{
			find->prev = temp;
			temp->next = find;
			temp->prev = find->prev;
			find->prev->next = temp;

		}

		++size;
	}
}

template<typename T>
inline void DList<T>::popByData(const T& data)
{
	Node* find = findNode(data);
	if (find != nullptr) {
		while (find != nullptr) {
			Node* temp = find->next;
			if (find->next != nullptr && find->prev != nullptr)
			{
				temp->prev = find->prev;
				find->prev->next = find->next;
				delete find;
			}
			else if (find->prev == nullptr)
			{
				temp->prev = nullptr;
				delete find;
				head = temp;
			}
			else if (find->next == nullptr)
			{
				find->prev->next = nullptr;
				tail = find->prev;
				delete find;
			}
			--size;
			find = findNode(data);
		}
	}
}

template<typename T>
inline void DList<T>::popFront()
{
	if (isEmpty())
		return;
	else if (size == 1)
	{
		delete head;
		head = nullptr;
		tail = nullptr;
	}
	else
	{
		auto temp = head;
		head = head->next;
		head->prev = nullptr;
		delete temp;
	}
	--size;
}

template<typename T>
inline void DList<T>::popBack()
{
	if (isEmpty())
		return;
	else if (size == 1)
	{
		delete head;
		head = nullptr;
		tail = nullptr;
	}
	else
	{
		auto temp = tail;
		tail = tail->prev;
		tail->next = nullptr;
		delete temp;
	}
	--size;
}

template<typename T>
inline bool DList<T>::isEmpty() const
{
	return head == nullptr;
}

template<typename T>
inline size_t DList<T>::getSize() const
{
	return size;
}

template<typename T>
inline void DList<T>::clear()
{
	while (!isEmpty())
		popFront();
	size = 0;
}

template<typename T>
inline void DList<T>::print() const
{
	//from left to right
	Node* temp = head;
	cout << "List directly: " << endl;
	while(temp != nullptr) {
		cout << temp->data<<" ";
		temp = temp->next;
	}
	cout << endl;
}

template<typename T>
inline void DList<T>::printR() const
{
	//from right to left
	Node* temp = tail;
	cout << "List reverse: " << endl;
	while (temp != nullptr) {
		cout << temp->data << " ";
		temp = temp->prev;
	}
	cout << endl;
}

template<typename T>
inline auto DList<T>::findNode(const T& data)
{
	Node* res = head;
	while (res != nullptr && res->data != data)
		res = res->next;

	return res;
}