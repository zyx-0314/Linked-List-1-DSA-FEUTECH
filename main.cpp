#include <iostream>
#include <string>

using namespace std;

// Data Structure
struct ProductData {
  string productName;
  int quantity;
  float price;
};

// Node
struct Stack {
  // Address
  Stack *next = NULL;
  // Data
  ProductData productData;
};

void MainMenu(int &choice) {
  cout << "1. Add New Stack\n"
       << "2. Display Stack\n"
       << "3. Delete Stack\n"
       << "0. Exit\n"
       << "\n"
       << ":: ";

  cin >> choice;

  system("cls");
}

ProductData SetProductData() {
  ProductData temp;

  cout << "Enter Product Name: ";
  cin >> temp.productName;

  cout << "Enter Price: ";
  cin >> temp.price;

  cout << "Enter Quantity: ";
  cin >> temp.quantity;

  return temp;
}

void SetProduct(int &counter, Stack *&tail) {
  Stack *temp = NULL;

	tail = new Stack;  // head ay gagawa ng bagong Stack
	
  if (!counter) // If counter is 0
  {
    tail->next = NULL; // in head the next will contain null

    // add data
    tail->productData = SetProductData();
  } else         // else counter is not 0
  {
    temp->next = tail; // in temp there is next where contains tail

    // add data
    temp->productData = SetProductData();

    tail = temp; // tail will be updated
  }

  counter++; // add counter
}

void Traversal(Stack *&tail) {
  Stack *temp = tail; // temp will point to the tail

  if (temp) // if temp is not empty
  {
    do {
      cout << temp->productData.productName << " - " << temp->productData.quantity << " - " << temp->productData.price << "\n"; // display the data

      if (temp->next == NULL) // if the next is empty break the loop
        break;

      temp = temp->next; // replace temp with the next from temp
    } while (true);
  } else // else empty
    cout << "No Product Yet";

  system("pause");
}

void DeleteNode(Stack *&tail, int & counter) {
  Stack *temp = NULL, *prev = NULL;
  string toDelete;
  
	// accept what to delete
	cout << "What to Delete: ";
	cin >> toDelete;

	// temp will point tail
	temp = tail;

	do {
		if (toDelete == temp->productData.productName) {   // if toDelete is match with the temps name
			if (prev != NULL) // if the prev is not empty
				prev->next = temp->next;

			if (tail == temp) // if temp is the current tail
				tail = temp->next;
			
			delete temp;
			counter--;
			break;
		}

		if (temp->next == NULL) // if the next is empty break the loop
			break;

		prev = temp;       // prev will point temp
		temp = temp->next; // temp will point the temp next
	} while (true);
}

/* Stack
 * - FILO
 * - tail <- node
 * 		Data is being pulled from tail and data is being pushed in the tail
*/

int main() {
  int choice, counter = 0;
  Stack *tail = NULL;

  do {
    MainMenu(choice);

    switch (choice) {
    case 0:
      return 0;
    case 1:
      SetProduct(counter, tail);
      break;
    case 2:
			Traversal(tail);
      break;
    case 3:
    	DeleteNode(tail, counter);
      break;
    default:
      break;
    }

    system("cls");
  } while (true);
}
