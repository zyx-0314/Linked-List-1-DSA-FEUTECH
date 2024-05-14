#ifndef STACK_SLL_H
#define STACK_SLL_H

#include <string>

// Data Structure
struct ProductData {
	std::string productName;
	int quantity;
	float price;
};

// Node
struct Stack_SLL {
	// Address
	Stack_SLL* next = NULL;
	// Data
	ProductData productData;
};

#endif // STACK_SLL_H