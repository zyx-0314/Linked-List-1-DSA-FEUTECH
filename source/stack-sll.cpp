#include "../header/stack-sll.h"

void Stack_sll::Starting() {
  int choice;
	Stack_SLL* tail = NULL;

	do {
		MainMenu(choice);

		switch (choice) {
		case 0:
			return;
		case 1:
			SetProduct(tail);
			break;
		case 2:
			Traversal(tail);
			break;
		case 3:
			DeleteNode(tail);
			break;
		default:
			break;
		}

		system("cls");
	} while (true);
}

void Stack_sll::MainMenu(int& choice) {
	std::cout << "1. Add New Stack\n"
		<< "2. Display Stack\n"
		<< "3. Delete Stack\n"
		<< "0. Exit\n"
		<< "\n"
		<< ":: ";

	std::cin >> choice;

	system("cls");
}

int Stack_sll::MainMenu() {
  int choice;

	std::cout << "1. Add New Stack\n"
		<< "2. Display Stack\n"
		<< "3. Delete Stack\n"
		<< "0. Exit\n"
		<< "\n"
		<< ":: ";

  std::cin >> choice;

  return choice;

	system("cls");
}

ProductData Stack_sll::SetProductData() {
	ProductData temp;

	std::cout << "Enter Product Name: ";
	std::cin >> temp.productName;

	std::cout << "Enter Price: ";
	std::cin >> temp.price;

	std::cout << "Enter Quantity: ";
	std::cin >> temp.quantity;

	return temp;
}

void Stack_sll::SetProduct(Stack_SLL*& tail) {
	Stack_SLL* temp = NULL;
	temp = new Stack_SLL;


	if (!tail) // If counter is 0
	{
		temp->next = NULL; // in head the next will contain null

		// add data
		temp->productData = SetProductData();
	}
	else         // else counter is not 0
	{
		temp = new Stack_SLL;
		temp->next = tail; // in temp there is next where contains tail

		// add data
		temp->productData = SetProductData();

	}

	tail = temp; // tail will be updated
}

void Stack_sll::DeleteNode(Stack_SLL*& tail) {
	Stack_SLL* temp = NULL, * prev = NULL;
	std::string toDelete;

	// accept what to delete
	std::cout << "What to Delete: ";
	std::cin >> toDelete;

	// temp will point tail
	temp = tail;

	do {
		if (toDelete == temp->productData.productName) {   // if toDelete is match with the temps name
			if (prev != NULL) // if the prev is not empty
				prev->next = temp->next;

			if (tail == temp) // if temp is the current tail
				tail = temp->next;

			delete temp;
			break;
		}

		if (temp->next == NULL) // if the next is empty break the loop
			break;

		prev = temp;       // prev will point temp
		temp = temp->next; // temp will point the temp next
	} while (true);
}

void Stack_sll::Traversal(Stack_SLL*& tail) {
	Stack_SLL* temp = tail; // temp will point to the tail

	if (temp) // if temp is not empty
	{
		do {
			std::cout << temp->productData.productName << " - " << temp->productData.quantity << " - " << temp->productData.price << "\n"; // display the data

			if (temp->next == NULL) // if the next is empty break the loop
				break;

			temp = temp->next; // replace temp with the next from temp
		} while (true);
	}
	else // else empty
		std::cout << "No Product Yet";

	system("pause");
}