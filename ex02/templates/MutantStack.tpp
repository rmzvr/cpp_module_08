#ifndef MUTANT_STACK_TPP
# define MUTANT_STACK_TPP

template < typename T, typename Container >
inline typename Container::iterator MutantStack<T, Container>::begin()
{
	return this->c.begin();
}

template < typename T, typename Container >
inline typename Container::const_iterator MutantStack<T, Container>::begin() const
{
	return this->c.begin();
}

template < typename T, typename Container >
inline typename Container::iterator MutantStack<T, Container>::end()
{
	return this->c.end();
}

template < typename T, typename Container >
inline typename Container::const_iterator MutantStack<T, Container>::end() const
{
	return this->c.end();
}

template < typename T, typename Container >
inline typename Container::iterator MutantStack<T, Container>::rbegin()
{
	return this->c.rbegin();
}

template < typename T, typename Container >
inline typename Container::const_iterator MutantStack<T, Container>::rbegin() const
{
	return this->c.rbegin();
}

template < typename T, typename Container >
inline typename Container::iterator MutantStack<T, Container>::rend()
{
	return this->c.rend();
}

template < typename T, typename Container >
inline typename Container::const_iterator MutantStack<T, Container>::rend() const
{
	return this->c.rend();
}

#endif