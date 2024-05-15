#include "../header/dll.h"

void Dll::Starting() {
  int choice;
  Node_DLL *tail = NULL, *head = NULL;
  bool loop = true;

	do {
		MainMenu(choice);

		switch (choice) {
		case 0:
			return;
		case 1:
			SetProduct_Queue(tail, head);
			break;
		case 2:
			SetProduct_Stack(tail, head);
			break;
		case 3:
			Traversal_Queue(head);
			break;
		case 4:
			Traversal_Stack(tail);
			break;
		case 5:
			DeleteNode_Queue(tail, head);
			break;
		case 6:
			DeleteNode_Stack(tail, head);
			break;
		default:
			break;
		}

		system("cls");
	} while (true);
}

void Dll::MainMenu(int& choice) {
  std::cout << "1. Add New Queue\n"
		<< "2. Add New Stack\n"
		<< "3. Display Queue\n"
		<< "4. Display Stack\n"
		<< "5. Delete Queue\n"
		<< "6. Delete Stack\n"
		<< "0. Exit\n"
		<< "\n"
		<< ":: ";

	std::cin >> choice;

	system("cls");
}

ProductData Dll::SetProductData() {
	ProductData temp;

	std::cout << "Enter Product Name: ";
	std::cin >> temp.productName;

	std::cout << "Enter Price: ";
	std::cin >> temp.price;

	std::cout << "Enter Quantity: ";
	std::cin >> temp.quantity;

	return temp;
}

void Dll::SetProduct_Queue(Node_DLL*& tail, Node_DLL*& head) {
	Node_DLL* temp = NULL;
	temp = new Node_DLL;

	if (!tail)
	{
		temp->prev = NULL; // in head the prev will contain null
		temp->next = NULL; // in head the next will contain null

		// add data
		temp->productData = SetProductData();
		
		// set as head since this node are the one starting the list
		head = temp;
	}
	else         // else counter is not 0
	{
		temp->prev = tail; // in temp there is prev where contains tail
		temp->next = NULL; // in head the next will contain null

    tail->next = temp; // the current tail will remember that temp will be the next after the node

		// add data
		temp->productData = SetProductData();
	}

	tail = temp; // tail will be updated
}

void Dll::SetProduct_Stack(Node_DLL*& tail, Node_DLL*& head) {
	Node_DLL* temp = NULL;
	temp = new Node_DLL;

	if (!head)
	{
		temp->next = NULL; // in temp the next will contain null
		temp->prev = NULL; // in temp the prev will contain null

		// add data
		temp->productData = SetProductData();
	}
	else
	{
    temp->next = head; // in temp there is next where contains tail
    temp->prev = NULL; // in temp the prev will contain null

    head->prev = temp;

		// add data
		temp->productData = SetProductData();
	}

	head = temp; // tail will be updated
}

void Dll::DeleteNode_Queue(Node_DLL*& tail, Node_DLL*& head) {
	Node_DLL* temp = NULL, * prev = NULL;
	std::string toDelete;

	// accept what to delete
	std::cout << "What to Delete: ";
	std::cin >> toDelete;

	// temp will point tail
	temp = head;

	do {
		if (toDelete == temp->productData.productName) {   // if toDelete is match with the temps name
			if (prev != NULL) // if the prev is not empty
			{
				prev->next = temp->next;
				if (temp->next != NULL)
					temp->next->prev = prev;
			}

			if (head == temp) // if temp is the current tail
			{
				head = temp->next;
				temp->next->prev = NULL;
			}
			if (tail == temp) // if temp is the current tail
			{
				if (temp->next != NULL)
					tail = temp->next;
				else
					tail = prev;
				temp->prev->next = NULL;
			}

			delete temp;
			break;
		}

		if (temp->next == NULL) // if the next is empty break the loop
			break;

		prev = temp;       // prev will point temp
		temp = temp->next; // temp will point the temp next
	} while (true);
}

// not working
void Dll::DeleteNode_Stack(Node_DLL*& tail, Node_DLL*& head) {
	Node_DLL* temp = NULL, * prev = NULL;
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

void Dll::Traversal_Queue(Node_DLL*& head) {
	Node_DLL* temp = head; // temp will point to the starting that has been set

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

void Dll::Traversal_Stack(Node_DLL*& tail) {
	Node_DLL* temp = tail; // temp will point to the tail

	if (temp) // if temp is not empty
	{
		do {
			std::cout << temp->productData.productName << " - " << temp->productData.quantity << " - " << temp->productData.price << "\n"; // display the data

			if (temp->prev == NULL) // if the prev is empty break the loop
				break;

			temp = temp->prev; // replace temp with the prev from temp
		} while (true);
	}
	else // else empty
		std::cout << "No Product Yet";

	system("pause");
}