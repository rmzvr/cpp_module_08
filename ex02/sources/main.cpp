#include "MutantStack.hpp"
#include <list>

void	mutant_stack_test()
{
	std::cout << "Mutant stack test start\n-----------------------------" << std::endl;
	MutantStack<int> mstack;
	mstack.push(5);
	mstack.push(17);
	std::cout << mstack.top() << std::endl;
	mstack.pop();
	std::cout << mstack.size() << std::endl;
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	mstack.push(0);
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	++it;
	--it;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
	std::stack<int> s(mstack);
	std::cout << "-----------------------------\nMutant stack test end\n" << std::endl;
}

void	list_test()
{
	std::cout << "List test start\n-----------------------------" << std::endl;
	std::list<int> list;
	list.push_back(5);
	list.push_back(17);
	std::cout << list.back() << std::endl;
	list.pop_back();
	std::cout << list.size() << std::endl;
	list.push_back(3);
	list.push_back(5);
	list.push_back(737);
	list.push_back(0);
	std::list<int>::iterator it = list.begin();
	std::list<int>::iterator ite = list.end();
	++it;
	--it;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
	std::list<int> s(list);
	std::cout << "-----------------------------\nList test end\n" << std::endl;
}

int main()
{
	try
	{
		mutant_stack_test();
		list_test();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
	return 0;
}