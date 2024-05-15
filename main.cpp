#include "./header/stack-sll.h"
#include "./header/queue-dll.h"
#include <cstdlib>

int Menu();

int main() {
  Stack_sll stack;
  Queue_dll queue;

  do {
  switch (Menu()) {
  case 0:
    exit(0);
  case 1:
    stack.Starting();
    break;
  case 2:
    queue.Starting();
    break;
  }
  
  }while (true);
}

int Menu() {
  int choice;

  std::cout << "1. Stack SLL\n"
            << "2. Queue DLL\n"
            << "0. Exit\n"
            << ":: ";
  std::cin >> choice;

  system("cls");

  return choice;
}