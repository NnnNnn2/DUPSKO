#include "DUPSKO.h"
#include <iostream>

int main()
{
	DUPSKO<int> stack;
	stack.pushBack(1);
	stack.pushBack(2);
	stack.pushBack(3);
	std::cout << stack.getElement(1);
	std::cout << stack.popElement(1) << std::endl;
	stack.insertAfter(4, 1);
	std::cout << stack.popBack();
	std::cout << stack.popBack();
	std::cout << stack.popBack();

	std::cout << std::endl;

	DUPSKO<int> queue;
	queue.pushBack(1);
	queue.pushBack(2);
	queue.pushBack(3);
	queue.setElement(9, 0);
	queue.setStart();
	for (int i = 0; i < 3; i++)
		std::cout << queue.getNext()<<' ';
	std::cout << "\n\n";
	queue.setEnd();
	for (int i = 0; i < 3; i++)
		std::cout << queue.getPrev() << ' ';
	std::cout << "\n\n";
	std::cout << queue.popFront();
	std::cout << queue.popFront();
	std::cout << queue.popFront();

}