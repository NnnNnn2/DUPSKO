#pragma once
// Dynamic Uviversal Practical Structure with Key Operations
// Dynamiczna Uniwersalna Praktyczna Struktura z Kluczowymi Operacjami

/* 
 * Dynamic
 * Unversal
 * Practical
 * Structure with
 * Key
 * Operations
 */

/*
 * Dynamiczna
 * Uniwersalna
 * Praktyczna
 * Struktura z
 * Kluczowymi
 * Operacjami
 */

#include <cstddef>

template<typename T>
struct DataElement
{
	T data;
	DataElement* prev;
	DataElement* next;
};

template<class T>
class DUPSKO
{
private:
	DataElement<T>* first;
	DataElement<T>* last;
	int NumberOfElements;

public:
	DUPSKO()
	{
		this->first = nullptr;
		this->last = nullptr;
		this->NumberOfElements = 0;
	}

	void pushFront(T element)
	{
		DataElement<T>* temp = new DataElement<T>;
		temp->data = element;
		temp->prev = nullptr;
		temp->next = this->first;
		if (this->first == nullptr || last == nullptr)
			this->last = temp;
		else
			this->first->prev = temp;
		this->first = temp;
		this->NumberOfElements++;
	}

	void pushBack(T element)
	{
		DataElement<T>* temp = new DataElement<T>;
		temp->data = element;
		temp->prev = this->last;
		temp->next = nullptr;
		if (this->first == nullptr || last == nullptr)
			this->first = temp;
		else
			this->last->next = temp;
		this->last = temp;
		this->NumberOfElements++;
	}

	T popFront()
	{
		if (this->first != nullptr)
		{
			DataElement<T>* temp = this->first;
			T data = temp->data;
			this->first = temp->next;
			if (this->first != nullptr)
				this->first->prev = nullptr;
			else
				this->last = nullptr;
			this->NumberOfElements--;
			delete temp;
			return data;
		}
		else
			return NULL;
	}

	T popBack()
	{
		if (this->last != nullptr)
		{
			DataElement<T>* temp = this->last;
			T data = temp->data;
			this->last = temp->prev;
			if (this->last != nullptr)
				this->last->next = nullptr;
			else
				this->first = nullptr;
			this->NumberOfElements--;
			delete temp;
			return data;
		}
		else
			return NULL;
	}

	T getFront()
	{
		T temp = first->data;
		return temp;
	}

	T getBack()
	{
		T temp = last->data;
		return temp;
	}

	int numberOfElements()
	{
		return NumberOfElements;
	}

	bool isEmpty()
	{
		return (first == nullptr || last == nullptr);
	}

	void clear()
	{
		DataElement<T>* temp = this->last;
		if (temp == nullptr)
			return;
		while (temp->prev != nullptr)
		{
			DataElement<T>* tempPrev = temp->prev;
			delete temp;
			temp = tempPrev;
		}
		this->first = nullptr;
		this->last = nullptr;
	}

	~DUPSKO()
	{
		DataElement<T>* temp = this->last;
		if (temp == nullptr)
			return;
		while (temp->prev != nullptr)
		{
			DataElement<T>* tempPrev = temp->prev;
			delete temp;
			temp = tempPrev;
		}
	}
};