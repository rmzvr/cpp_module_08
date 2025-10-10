#ifndef MUTANT_STACK_HPP
# define MUTANT_STACK_HPP

# include <iostream>
# include <deque>
# include <stack>

template< typename T, typename Container = std::deque<T> >
class MutantStack : public std::stack<T>
{
	public:
		using	std::stack<T, Container>::c;
		using	iterator = typename Container::iterator;
		using	const_iterator = typename Container::const_iterator;

		iterator			begin();
		const_iterator		begin() const;

		iterator			end();
		const_iterator		end() const;

		iterator			rbegin();
		const_iterator		rbegin() const;

		iterator			rend();
		const_iterator		rend() const;
};

# include "../templates/MutantStack.tpp"

#endif

