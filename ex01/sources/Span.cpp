#include "Span.hpp"

Span::Span( unsigned int _n ) : _N{ _n }
{}

Span::Span( Span const &other ) : _N{ other._N }, _numbers{ other._numbers }
{}

Span &Span::operator=( Span const &other )
{
	if (this != &other)
	{
		this->_N = other._N;
		this->_numbers = other._numbers;
	}
	return *this;
}

Span::~Span()
{}

int Span::shortestSpan()
{
	if (this->_numbers.size() < this->_MIN_NUMBERS_COUNT_TO_FIND_SPAN)
	{
		throw Span::NotEnoughElementsException();
	}
	int	differenceBetweenNumbers = 0;
	int	smallestSpan = std::numeric_limits<int>::max();
	std::vector<int> containerToSort = this->_numbers;
	std::sort(containerToSort.begin(), containerToSort.end());
	for (size_t i = 0; i < containerToSort.size() - 1; ++i)
	{
		differenceBetweenNumbers = std::abs(containerToSort[i] - containerToSort[i + 1]);
		if (differenceBetweenNumbers < smallestSpan)
		{
			smallestSpan = differenceBetweenNumbers;
		}
	}
	return smallestSpan;
}

int Span::longestSpan()
{
	if (this->_numbers.size() < this->_MIN_NUMBERS_COUNT_TO_FIND_SPAN)
	{
		throw Span::NotEnoughElementsException();
	}
	auto	smallestNumber = std::min_element(this->_numbers.begin(), this->_numbers.end());
	auto	biggestNumber = std::max_element(this->_numbers.begin(), this->_numbers.end());
	return *biggestNumber - *smallestNumber;
}

void Span::addNumber( int n )
{
	if (this->_numbers.size() < this->_N)
	{
		this->_numbers.push_back(n);
	}
	else
	{
		throw Span::SpanFullException();
	}
}

void Span::addNumbers( std::vector<int> newNumbers )
{
	if ((this->_N - this->_numbers.size()) >= newNumbers.size())
	{
		this->_numbers.insert(this->_numbers.end(), newNumbers.begin(), newNumbers.end());
	}
	else
	{
		throw Span::InsufficientCapacityException();
	}
}

const char * Span::SpanFullException::what() const noexcept
{
	return "Cannot add number: Span has reached maximum capacity";
}

const char * Span::NotEnoughElementsException::what() const noexcept
{
	return "Cannot calculate span: at least 2 elements required";
}

const char * Span::InsufficientCapacityException::what() const noexcept
{
	return "Cannot add numbers: insufficient remaining capacity for all elements";
}