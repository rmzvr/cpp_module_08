#ifndef SPAN_HPP
# define SPAN_HPP

# include <iostream>
# include <algorithm>
# include <vector>
# include <chrono>

class Span
{
	private:
		const unsigned int	_MIN_NUMBERS_COUNT_TO_FIND_SPAN = 2;
		unsigned int		_N;
		std::vector<int>	_numbers;
	public:
		Span() = delete;
		Span( unsigned int	_n );
		Span( Span const & other );
		Span & operator=( Span const & other );
		~Span();

		int		shortestSpan();
		int		longestSpan();
		void	addNumber( int n );
		void	addNumbers( std::vector<int> newNumbers );

		class SpanFullException : public std::exception
		{
			public:
				const char * what() const noexcept override;
		};

		class NotEnoughElementsException : public std::exception
		{
			public:
				const char * what() const noexcept override;
		};

		class InsufficientCapacityException : public std::exception
		{
			public:
				const char * what() const noexcept override;
		};
};

#endif