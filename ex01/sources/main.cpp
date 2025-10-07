#include <Span.hpp>
#include <random>
#include <algorithm>
#include <chrono>

static void test_basic_functionality()
{
	std::cout << "--- Testing basic Span functionality ---" << std::endl;
	
	// Create Span with capacity 5
	Span sp(5);
	
	// Add numbers one by one
	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	
	std::cout << "Added numbers: 6, 3, 17, 9, 11" << std::endl;
	
	try
	{
		int shortest = sp.shortestSpan();
		int longest = sp.longestSpan();
		
		std::cout << "Shortest span: " << shortest << std::endl;
		std::cout << "Longest span: " << longest << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}
}

static void test_exception_handling()
{
	std::cout << "\n--- Testing exception handling ---" << std::endl;
	
	// Test SpanFullException
	std::cout << "Testing SpanFullException:" << std::endl;
	try
	{
		Span sp(2);
		sp.addNumber(1);
		sp.addNumber(2);
		std::cout << "Added 2 numbers to capacity-2 Span" << std::endl;
		sp.addNumber(3); // Should throw exception
	}
	catch (const Span::SpanFullException& e)
	{
		std::cout << "Caught expected exception: " << e.what() << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cout << "Unexpected exception: " << e.what() << std::endl;
	}
	
	// Test NotEnoughElementsException with empty span
	std::cout << "\nTesting NotEnoughElementsException (empty span):" << std::endl;
	try
	{
		Span sp(5);
		sp.shortestSpan(); // Should throw exception
	}
	catch (const Span::NotEnoughElementsException& e)
	{
		std::cout << "Caught expected exception: " << e.what() << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cout << "Unexpected exception: " << e.what() << std::endl;
	}
	
	// Test NotEnoughElementsException with one element
	std::cout << "\nTesting NotEnoughElementsException (one element):" << std::endl;
	try
	{
		Span sp(5);
		sp.addNumber(42);
		sp.longestSpan(); // Should throw exception
	}
	catch (const Span::NotEnoughElementsException& e)
	{
		std::cout << "Caught expected exception: " << e.what() << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cout << "Unexpected exception: " << e.what() << std::endl;
	}
}

static void test_add_numbers_functionality()
{
	std::cout << "\n--- Testing addNumbers functionality ---" << std::endl;
	
	// Test successful batch addition
	std::cout << "Testing successful batch addition:" << std::endl;
	Span sp(10);
	std::vector<int> numbers = {1, 5, 3, 9, 7, 2, 8};
	
	try
	{
		sp.addNumbers(numbers);
		std::cout << "Successfully added vector of " << numbers.size() << " elements" << std::endl;
		std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
		std::cout << "Longest span: " << sp.longestSpan() << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}
	
	// Test InsufficientCapacityException
	std::cout << "\nTesting InsufficientCapacityException:" << std::endl;
	try
	{
		Span small_span(3);
		std::vector<int> too_many_numbers = {1, 2, 3, 4, 5};
		small_span.addNumbers(too_many_numbers); // Should throw exception
	}
	catch (const Span::InsufficientCapacityException& e)
	{
		std::cout << "Caught expected exception: " << e.what() << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cout << "Unexpected exception: " << e.what() << std::endl;
	}
	
	// Test partial fill and then overflow
	std::cout << "\nTesting partial fill then overflow:" << std::endl;
	try
	{
		Span partial_span(5);
		partial_span.addNumber(1);
		partial_span.addNumber(2);
		std::cout << "Added 2 numbers individually" << std::endl;
		
		std::vector<int> remaining = {3, 4, 5, 6}; // 4 numbers, but only 3 spaces left
		partial_span.addNumbers(remaining); // Should throw exception
	}
	catch (const Span::InsufficientCapacityException& e)
	{
		std::cout << "Caught expected exception: " << e.what() << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cout << "Unexpected exception: " << e.what() << std::endl;
	}
}

static void test_edge_cases()
{
	std::cout << "\n--- Testing edge cases ---" << std::endl;
	
	// Test with two identical numbers
	std::cout << "Testing with identical numbers:" << std::endl;
	try
	{
		Span sp(3);
		sp.addNumber(5);
		sp.addNumber(5);
		sp.addNumber(10);
		
		std::cout << "Added: 5, 5, 10" << std::endl;
		std::cout << "Shortest span: " << sp.shortestSpan() << " (expected: 0)" << std::endl;
		std::cout << "Longest span: " << sp.longestSpan() << " (expected: 5)" << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}
	
	// Test with negative numbers
	std::cout << "\nTesting with negative numbers:" << std::endl;
	try
	{
		Span sp(4);
		sp.addNumber(-10);
		sp.addNumber(-5);
		sp.addNumber(0);
		sp.addNumber(15);
		
		std::cout << "Added: -10, -5, 0, 15" << std::endl;
		std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
		std::cout << "Longest span: " << sp.longestSpan() << " (expected: 25)" << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}
	
	// Test with minimum capacity (2 elements)
	std::cout << "\nTesting minimum viable span:" << std::endl;
	try
	{
		Span sp(2);
		sp.addNumber(1);
		sp.addNumber(100);
		
		std::cout << "Added: 1, 100" << std::endl;
		std::cout << "Shortest span: " << sp.shortestSpan() << " (expected: 99)" << std::endl;
		std::cout << "Longest span: " << sp.longestSpan() << " (expected: 99)" << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}
}

static void test_large_dataset()
{
	std::cout << "\n--- Testing large dataset performance ---" << std::endl;
	
	const unsigned int size = 10000;
	std::cout << "Creating Span with capacity " << size << std::endl;
	
	// Generate random numbers
	std::vector<int> numbers(size);
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<int> dis(1, 100000);
	
	for (unsigned int i = 0; i < size; ++i) {
		numbers[i] = dis(gen);
	}
	
	try
	{
		Span sp(size);
		
		// Measure time for batch addition
		auto start = std::chrono::high_resolution_clock::now();
		sp.addNumbers(numbers);
		auto stop = std::chrono::high_resolution_clock::now();
		auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
		
		std::cout << "Batch addition time: " << duration.count() << " microseconds" << std::endl;
		
		// Measure time for shortest span calculation
		start = std::chrono::high_resolution_clock::now();
		int shortest = sp.shortestSpan();
		stop = std::chrono::high_resolution_clock::now();
		duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
		
		std::cout << "Shortest span calculation time: " << duration.count() << " microseconds" << std::endl;
		std::cout << "Shortest span: " << shortest << std::endl;
		
		// Measure time for longest span calculation
		start = std::chrono::high_resolution_clock::now();
		int longest = sp.longestSpan();
		stop = std::chrono::high_resolution_clock::now();
		duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
		
		std::cout << "Longest span calculation time: " << duration.count() << " microseconds" << std::endl;
		std::cout << "Longest span: " << longest << std::endl;
		
	}
	catch (const std::exception& e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}
}

static void test_copy_operations()
{
	std::cout << "\n--- Testing copy constructor and assignment operator ---" << std::endl;
	
	// Test copy constructor
	std::cout << "Testing copy constructor:" << std::endl;
	try
	{
		Span original(5);
		original.addNumber(1);
		original.addNumber(10);
		original.addNumber(5);
		
		Span copied(original);
		
		std::cout << "Original shortest span: " << original.shortestSpan() << std::endl;
		std::cout << "Copied shortest span: " << copied.shortestSpan() << std::endl;
		
		// Verify they are independent
		copied.addNumber(2);
		std::cout << "After adding number to copy:" << std::endl;
		std::cout << "Original shortest span: " << original.shortestSpan() << std::endl;
		std::cout << "Copied shortest span: " << copied.shortestSpan() << std::endl;
		
	}
	catch (const std::exception& e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}
	
	// Test assignment operator
	std::cout << "\nTesting assignment operator:" << std::endl;
	try
	{
		Span original(4);
		original.addNumber(20);
		original.addNumber(30);
		original.addNumber(25);
		
		Span assigned(10); // Different capacity
		assigned = original;
		
		std::cout << "Original shortest span: " << original.shortestSpan() << std::endl;
		std::cout << "Assigned shortest span: " << assigned.shortestSpan() << std::endl;
		
	}
	catch (const std::exception& e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}
}

static void test_mixed_operations()
{
	std::cout << "\n--- Testing mixed operations ---" << std::endl;
	
	try
	{
		Span sp(10);
		
		// Add some numbers individually
		sp.addNumber(50);
		sp.addNumber(25);
		std::cout << "Added 2 numbers individually" << std::endl;
		
		// Add some numbers in batch
		std::vector<int> batch1 = {10, 40, 30};
		sp.addNumbers(batch1);
		std::cout << "Added batch of 3 numbers" << std::endl;
		
		// Add more individually
		sp.addNumber(35);
		sp.addNumber(45);
		std::cout << "Added 2 more numbers individually" << std::endl;
		
		// Add final batch
		std::vector<int> batch2 = {20, 60};
		sp.addNumbers(batch2);
		std::cout << "Added final batch of 2 numbers" << std::endl;
		
		std::cout << "Final shortest span: " << sp.shortestSpan() << std::endl;
		std::cout << "Final longest span: " << sp.longestSpan() << std::endl;
		
		// Try to add one more (should fail)
		sp.addNumber(70);
		
	}
	catch (const std::exception& e)
	{
		std::cout << "Caught expected exception: " << e.what() << std::endl;
	}
}

int main(void)
{
	try
	{
		test_basic_functionality();
		test_exception_handling();
		test_add_numbers_functionality();
		test_edge_cases();
		test_copy_operations();
		test_mixed_operations();
		test_large_dataset();
	}
	catch (const std::exception& e)
	{
		std::cerr << "Unexpected exception in main: " << e.what() << std::endl;
	}
	return 0;
}