#ifndef EASY_FIND_TPP
# define EASY_FIND_TPP

template< typename Container >
auto	easyfind(Container & container, int value) -> decltype(std::begin(container))
{
	return std::find(std::begin(container), std::end(container), value);
}

#endif