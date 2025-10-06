#include <easyfind.hpp>

#include <vector>
#include <array>
#include <list>
#include <deque>

static void test_vector()
{
	std::cout << "--- Testing std::vector<int> ---" << std::endl;
	
	// Test with populated vector
	std::vector<int> numbers = {1, 2, 3, 4, 5, 2, 6};
	std::cout << "Vector elements: ";
	for (const auto& n : numbers) {
		std::cout << n << " ";
	}
	std::cout << std::endl;

	// Test finding existing element
	auto result = easyfind(numbers, 3);
	if (result != numbers.end()) {
		std::cout << "Found element 3 at position: " << std::distance(numbers.begin(), result) << std::endl;
	} else {
		std::cout << "Element 3 not found" << std::endl;
	}

	// Test finding first occurrence of duplicate
	result = easyfind(numbers, 2);
	if (result != numbers.end()) {
		std::cout << "Found first occurrence of 2 at position: " << std::distance(numbers.begin(), result) << std::endl;
	} else {
		std::cout << "Element 2 not found" << std::endl;
	}

	// Test finding non-existing element
	result = easyfind(numbers, 99);
	if (result != numbers.end()) {
		std::cout << "Found element 99" << std::endl;
	} else {
		std::cout << "Element 99 not found (expected)" << std::endl;
	}

	// Test with empty vector
	std::vector<int> empty_vector;
	result = easyfind(empty_vector, 1);
	if (result != empty_vector.end()) {
		std::cout << "Found element in empty vector" << std::endl;
	} else {
		std::cout << "Element not found in empty vector (expected)" << std::endl;
	}
}

static void test_array()
{
	std::cout << "\n--- Testing std::array<int, 5> ---" << std::endl;
	
	std::array<int, 5> numbers = {{10, 20, 30, 40, 50}};
	std::cout << "Array elements: ";
	for (const auto& n : numbers) {
		std::cout << n << " ";
	}
	std::cout << std::endl;

	// Test finding existing element
	auto result = easyfind(numbers, 30);
	if (result != numbers.end()) {
		std::cout << "Found element 30 at position: " << std::distance(numbers.begin(), result) << std::endl;
	} else {
		std::cout << "Element 30 not found" << std::endl;
	}

	// Test finding non-existing element
	result = easyfind(numbers, 60);
	if (result != numbers.end()) {
		std::cout << "Found element 60" << std::endl;
	} else {
		std::cout << "Element 60 not found (expected)" << std::endl;
	}

	// Test with zero-size array
	std::array<int, 0> empty_array = {{}};
	result = easyfind(empty_array, 1);
	if (result != empty_array.end()) {
		std::cout << "Found element in empty array" << std::endl;
	} else {
		std::cout << "Element not found in empty array (expected)" << std::endl;
	}
}

static void test_list()
{
	std::cout << "\n--- Testing std::list<int> ---" << std::endl;
	
	std::list<int> numbers = {100, 200, 300, 200, 400};
	std::cout << "List elements: ";
	for (const auto& n : numbers) {
		std::cout << n << " ";
	}
	std::cout << std::endl;

	// Test finding existing element
	auto result = easyfind(numbers, 200);
	if (result != numbers.end()) {
		std::cout << "Found first occurrence of 200" << std::endl;
	} else {
		std::cout << "Element 200 not found" << std::endl;
	}

	// Test finding non-existing element
	result = easyfind(numbers, 999);
	if (result != numbers.end()) {
		std::cout << "Found element 999" << std::endl;
	} else {
		std::cout << "Element 999 not found (expected)" << std::endl;
	}

	// Test with empty list
	std::list<int> empty_list;
	result = easyfind(empty_list, 1);
	if (result != empty_list.end()) {
		std::cout << "Found element in empty list" << std::endl;
	} else {
		std::cout << "Element not found in empty list (expected)" << std::endl;
	}
}

static void test_deque()
{
	std::cout << "\n--- Testing std::deque<int> ---" << std::endl;
	
	std::deque<int> numbers = {7, 8, 9, 7, 10};
	std::cout << "Deque elements: ";
	for (const auto& n : numbers) {
		std::cout << n << " ";
	}
	std::cout << std::endl;

	// Test finding existing element
	auto result = easyfind(numbers, 9);
	if (result != numbers.end()) {
		std::cout << "Found element 9 at position: " << std::distance(numbers.begin(), result) << std::endl;
	} else {
		std::cout << "Element 9 not found" << std::endl;
	}

	// Test finding first occurrence of duplicate
	result = easyfind(numbers, 7);
	if (result != numbers.end()) {
		std::cout << "Found first occurrence of 7 at position: " << std::distance(numbers.begin(), result) << std::endl;
	} else {
		std::cout << "Element 7 not found" << std::endl;
	}

	// Test finding non-existing element
	result = easyfind(numbers, 77);
	if (result != numbers.end()) {
		std::cout << "Found element 77" << std::endl;
	} else {
		std::cout << "Element 77 not found (expected)" << std::endl;
	}

	// Test with empty deque
	std::deque<int> empty_deque;
	result = easyfind(empty_deque, 1);
	if (result != empty_deque.end()) {
		std::cout << "Found element in empty deque" << std::endl;
	} else {
		std::cout << "Element not found in empty deque (expected)" << std::endl;
	}
}

static void test_c_array()
{
	std::cout << "\n--- Testing C-style array ---" << std::endl;
	
	int numbers[] = {42, 43, 44, 42, 45};
	size_t size = sizeof(numbers) / sizeof(numbers[0]);
	
	std::cout << "C-array elements: ";
	for (size_t i = 0; i < size; ++i) {
		std::cout << numbers[i] << " ";
	}
	std::cout << std::endl;

	// Test finding existing element
	auto result = easyfind(numbers, 44);
	if (result != std::end(numbers)) {
		std::cout << "Found element 44 at position: " << std::distance(std::begin(numbers), result) << std::endl;
	} else {
		std::cout << "Element 44 not found" << std::endl;
	}

	// Test finding first occurrence of duplicate
	result = easyfind(numbers, 42);
	if (result != std::end(numbers)) {
		std::cout << "Found first occurrence of 42 at position: " << std::distance(std::begin(numbers), result) << std::endl;
	} else {
		std::cout << "Element 42 not found" << std::endl;
	}

	// Test finding non-existing element
	result = easyfind(numbers, 100);
	if (result != std::end(numbers)) {
		std::cout << "Found element 100" << std::endl;
	} else {
		std::cout << "Element 100 not found (expected)" << std::endl;
	}
}

static void test_edge_cases()
{
	std::cout << "\n--- Testing edge cases ---" << std::endl;
	
	// Test with single element container
	std::vector<int> single_element = {42};
	auto result = easyfind(single_element, 42);
	if (result != single_element.end()) {
		std::cout << "Found element 42 in single-element vector" << std::endl;
	} else {
		std::cout << "Element 42 not found in single-element vector" << std::endl;
	}

	result = easyfind(single_element, 43);
	if (result != single_element.end()) {
		std::cout << "Found element 43 in single-element vector" << std::endl;
	} else {
		std::cout << "Element 43 not found in single-element vector (expected)" << std::endl;
	}

	// Test with negative numbers
	std::vector<int> negative_numbers = {-1, -2, -3, 0, 1, 2};
	result = easyfind(negative_numbers, -2);
	if (result != negative_numbers.end()) {
		std::cout << "Found element -2 in negative numbers vector" << std::endl;
	} else {
		std::cout << "Element -2 not found in negative numbers vector" << std::endl;
	}

	result = easyfind(negative_numbers, 0);
	if (result != negative_numbers.end()) {
		std::cout << "Found element 0 in negative numbers vector" << std::endl;
	} else {
		std::cout << "Element 0 not found in negative numbers vector" << std::endl;
	}
}

static void test_const_modification()
{
	std::cout << "\n--- Testing const container modification (should not compile if uncommented) ---" << std::endl;
	
	// Test const vector - attempting to modify through iterator
	const std::vector<int> const_vector = {10, 20, 30, 40, 50};
	auto result = easyfind(const_vector, 30);
	if (result != const_vector.end()) {
		std::cout << "Found element 30 in const vector: " << *result << std::endl;
		std::cout << "Value is read-only - cannot modify through const iterator" << std::endl;
		// The following line would cause a compilation error if uncommented:
		// *result = 999; // ERROR: cannot assign to read-only location
	}

	// Test const array - attempting to modify through iterator
	const std::array<int, 3> const_array = {{100, 200, 300}};
	auto array_result = easyfind(const_array, 200);
	if (array_result != const_array.end()) {
		std::cout << "Found element 200 in const array: " << *array_result << std::endl;
		std::cout << "Value is read-only - cannot modify through const iterator" << std::endl;
		// The following line would cause a compilation error if uncommented:
		// *array_result = 999; // ERROR: cannot assign to read-only location
	}

	// Test const list - attempting to modify through iterator
	const std::list<int> const_list = {1000, 2000, 3000};
	auto list_result = easyfind(const_list, 2000);
	if (list_result != const_list.end()) {
		std::cout << "Found element 2000 in const list: " << *list_result << std::endl;
		std::cout << "Value is read-only - cannot modify through const iterator" << std::endl;
		// The following line would cause a compilation error if uncommented:
		// *list_result = 999; // ERROR: cannot assign to read-only location
	}

	// Test const deque - attempting to modify through iterator
	const std::deque<int> const_deque = {11, 22, 33};
	auto deque_result = easyfind(const_deque, 22);
	if (deque_result != const_deque.end()) {
		std::cout << "Found element 22 in const deque: " << *deque_result << std::endl;
		std::cout << "Value is read-only - cannot modify through const iterator" << std::endl;
		// The following line would cause a compilation error if uncommented:
		// *deque_result = 999; // ERROR: cannot assign to read-only location
	}

	// Test const C-style array - attempting to modify through iterator
	const int const_c_array[] = {111, 222, 333};
	auto c_array_result = easyfind(const_c_array, 222);
	if (c_array_result != std::end(const_c_array)) {
		std::cout << "Found element 222 in const C-array: " << *c_array_result << std::endl;
		std::cout << "Value is read-only - cannot modify through const iterator" << std::endl;
		// The following line would cause a compilation error if uncommented:
		// *c_array_result = 999; // ERROR: cannot assign to read-only location
	}

	// Demonstrate the difference: non-const container allows modification
	std::cout << "\n--- Demonstrating difference with non-const containers ---" << std::endl;
	std::vector<int> mutable_vector = {10, 20, 30};
	auto mutable_result = easyfind(mutable_vector, 20);
	if (mutable_result != mutable_vector.end()) {
		std::cout << "Found element 20 in mutable vector: " << *mutable_result << std::endl;
		*mutable_result = 999; // This works fine with non-const containers
		std::cout << "Modified element to: " << *mutable_result << std::endl;
		std::cout << "Vector after modification: ";
		for (const auto& n : mutable_vector) {
			std::cout << n << " ";
		}
		std::cout << std::endl;
	}

	std::cout << "\nConst-correctness verified: const containers return const iterators" << std::endl;
	std::cout << "that prevent modification of the underlying data." << std::endl;
}

int main(void)
{
	try
	{
		test_vector();
		test_array();
		test_list();
		test_deque();
		test_c_array();
		test_edge_cases();
		test_const_modification();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	return 0;
}