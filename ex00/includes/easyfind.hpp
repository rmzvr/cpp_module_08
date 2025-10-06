#ifndef EASY_FIND_HPP
# define EASY_FIND_HPP

# include <iostream>
# include <algorithm>

template< typename Container >
auto	easyfind(Container & container, int value) -> decltype(std::begin(container));

# include "../templates/easyfind.tpp"

#endif