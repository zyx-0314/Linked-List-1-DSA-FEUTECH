#ifndef NODE_DLL_H
#define NODE_DLL_H

#include "ds.h"

// Node
struct Node_DLL {
	// Address
	Node_DLL* next = NULL;
	Node_DLL* prev = NULL;
	// Data
	ProductData productData;
};

#endif // NODE_DLL_H