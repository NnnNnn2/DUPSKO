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

	DataElement<T>* getFirst()
	{
		return first;
	}

	DataElement<T>* getLast()
	{
		return last;
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

	void setElement(T element, int index)
	{
		if (index < 0 || index > NumberOfElements)
			return;
		DataElement<T>* tempEl = this->first;
		for (int i = 0; i < index; i++)
			tempEl = tempEl->next;
		tempEl->data = element;
	}

	void insertAfter(T element, int index)
	{
		if (index < 0 || index > NumberOfElements)
			return;
		DataElement<T>* temp = new DataElement<T>;
		temp->data = element;
		temp->next = nullptr;
		DataElement<T>* tempEl = this->first;
		for (int i = 0; i < index; i++)
			tempEl = tempEl->next;
		if (tempEl->next != nullptr)
		{
			tempEl->next->prev = temp;
			temp->next = tempEl->next;
		}
		else
			this->last = temp;
		temp->prev = tempEl;
		tempEl->next = temp;
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

	T popElement(int index)
	{
		if (index < 0 || index > NumberOfElements)
			return NULL;
		DataElement<T>* temp = this->first;
		for (int i = 0; i < index; i++)
			temp = temp->next;
		T data = temp->data;
		if (temp->prev != nullptr && temp->next != nullptr)
		{
			temp->prev->next = temp->next;
			temp->next->prev = temp->prev;
		}
		else if (temp->prev == nullptr && temp->next != nullptr)
			temp->next->prev = nullptr;
		else if (temp->next == nullptr && temp->prev != nullptr)
			temp->prev->next = nullptr;
		delete temp;
		return data;
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

	T getElement(int index)
	{
		if (index < 0 || index > NumberOfElements)
			return NULL;
		DataElement<T>* temp = this->first;
		for (int i = 0; i < index; i++)
			temp = temp->next;
		return temp->data;
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