#include "DUPSKO.h"
#include <iostream>

int main()
{
	DUPSKO<int> stack;
	stack.pushBack(1);
	stack.pushBack(2);
	stack.pushBack(3);
	stack.pushBack(4);
	std::cout << stack.getElement(1);
	std::cout << stack.popElement(1) << std::endl;
	std::cout << stack.popBack() << stack.popBack() << stack.popBack();

	std::cout << std::endl;

	DUPSKO<int> queue;
	queue.pushBack(1);
	queue.pushBack(2);
	queue.pushBack(3);
	std::cout << queue.popFront() << queue.popFront() << queue.popFront();

}