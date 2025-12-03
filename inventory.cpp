/* bennys fruits management system
1. display id name price quantity
2. add new product (auto generate id)
3. update product quantity (search by id) add ( subtract stock)
4. search product by name display full details
5. display total inventory value sum of price x quantity
6. remove product by id
7. exit

CHNICAL NOTES:
- Use std::vector<Product> to store inventory
- Start with 3-5 pre-loaded products
- Validate: price > 0, quantity >= 0
- Auto-increment IDs (last ID + 1)

STRUCT USAGE:
- Product is defined in Product.h
- Access members with dot notation: product.id, product.name, etc.
- Pass by reference to functions to avoid copying

FUNCTION ORGANIZATION:
- Menu(): Display menu and get user choice
- DisplayAll(): Show all products in table format
- AddProduct(): Add new product with validation
- UpdateQuantity(): Find by ID and modify stock
- SearchProduct(): Find by name and display
- CalculateTotalValue(): Sum all (price × quantity)
- RemoveProduct(): Delete product by ID */

#include "Product.h"
#include <iostream>
#include <limits>
#include <vector>

char Menu();
void DisplayAll(std::vector<Product> &inventory, int &lastID);
void AddProduct(std::vector<Product> &inventory, int &lastID);
void PreloadedItems(std::vector<Product> &inventory, int &lastID);
void UpdateProduct(std::vector<Product> &inventory, int &lastID);
void search(std::vector<Product> &inventory, int &lastID);
void Pause();
void Clear();

int main() {
  std::vector<Product> inventory; // creates a vector with the custom struct we
                                  // made product.h we also name this invetory
  int lastID = 223;
  PreloadedItems(inventory, lastID); // calls preloaded items
  while (true) {
    char choice = Menu();
    switch (choice) {
    case '1':
      DisplayAll(inventory, lastID);
      Pause();
      Clear();
      :reak;
    case '2':
      AddProduct(inventory, lastID);
      break;
    case '3':
      UpdateProduct(inventory, lastID);
      break;
    case '4':
      search(inventory, lastID);
    case '7':
      return 0;
    default:
      std::cout << "invalid";
      break;
    }
  }
  return 0;
}

void DisplayAll(std::vector<Product> &inventory, int &lastID) {
  Clear();
  if (inventory.empty()) {
    std::cout << "Inventory is empty\n\n";
    return;
  }
  std::cout << "========================================\n";
  std::cout << "            ALL PRODUCTS\n";
  std::cout << "========================================\n";

  for (int i = 0; i < inventory.size(); i++) {
    std::cout << "ID: " << inventory[i].id << '\n';
    std::cout << "Name: " << inventory[i].name << '\n';
    std::cout << "Price: " << inventory[i].price << '\n';
    std::cout << "Quantity: " << inventory[i].quantity << '\n';
    std::cout << "========================================\n";
  }
  std::cout << '\n';
}

void AddProduct(std::vector<Product> &inventory, int &lastID) {
  Clear();
  Product p;
  p.id = ++lastID;
  std::cout << "Enter Product name: ";
  std::cin >> p.name;

  do {
    std::cout << "Enter a price: ";
    std::cin >> p.price;
    if (p.price <= 0)
      std::cout << "Price must be over 0\n";
  } while (p.price <= 0);

  do {
    std::cout << "Enter the quantity: ";
    std::cin >> p.quantity;
    if (p.quantity <= 0)
      std::cout << "Quantity must be over 0\n";
  } while (p.quantity <= 0);

  inventory.push_back(p);
  std::cout << "Product added successfully\n\n";
}

char Menu() {
  char opt;      // opt char just for holding answer
  while (true) { // keep going
    std::cout << "========================================\n"
              << "        INVENTORY MANAGEMENT\n"
              << "========================================\n";
    std::cout << "1. Display all products\n"
              << "2. Add new product\n"
              << "3. Update product \n"
              << "4. Search product\n"
              << "5. Total inventory value\n"
              << "6. Remove Product\n"
              << "7. Exit\n";
    std::cin >> opt; // getting answer
    if (opt > '7') {
      std::cout << "invalid option. Try again\n\n";
      continue;
    } // if answer is larger then 7 make it invalid
    if (opt == '7') {
      std::cout << " Exiting program...\n";
      break;
    } // if equal 7 leave loop

    return opt; // return opt to main function
  }
  return '7'; // just to satisfy compiler
}

void PreloadedItems(std::vector<Product> &inventory, int &lastID) {
  inventory.push_back({++lastID, "apple", 2.5, 10});
  inventory.push_back({++lastID, "banana", 4.2, 20});
  inventory.push_back({++lastID, "watermelon", 6, 5});
}

void UpdateProduct(std::vector<Product> &inventory, int &lastID) {
  Clear();
  if (inventory.empty()) {
    std::cout << "Inventory is empty\n\n";
    Pause();
    return;
  }

  DisplayAll(inventory, lastID);

  int ProductID;
  std::cout << "Which product ID do you want to update?: ";
  std::cin >> ProductID;

  bool found = false;
  for (auto &product : inventory) { // auto not sure what it means
    if (product.id == ProductID) {
      found = true;
      std::cout << "\nUpdating product: " << product.name << '\n';

      double newPrice;
      do {
        std::cout << "Enter new price (current price: " << product.price
                  << "): ";
        std::cin >> newPrice;
        if (newPrice <= 0) {
          std::cout << "Price must be above 0.\n";
        }
      } while (newPrice <= 0);

      int newQuantity;
      do {
        std::cout << "Enter new quantity (current quantity: "
                  << product.quantity << "): ";
        std::cin >> newQuantity;
        if (newQuantity <= 0) {
          std::cout << "Quantity must be above 0.";
        }
      } while (newQuantity <= 0);

      product.price = newPrice;
      product.quantity = newQuantity;

      std::cout << "Product updated successfully!\n\n";
      Pause();
      return; // is this return needed
      // ?
    }
  }
  if (!found) {
    std::cout << "No product found with ID " << ProductID << "\n";
    Pause();
  }
}

void Pause() {
  std::cout << "Press ENTER to continue...";
  std::cin.clear();
  std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
  std::cin.get();
}

void Clear() {
#ifdef _WIN32
  system("cls");
#else
  system("clear");
#endif
}
