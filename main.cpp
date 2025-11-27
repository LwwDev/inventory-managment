/*
bennys fruits management system
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
- RemoveProduct(): Delete product by ID
*/
#include <iostream>
#include "Product.h"
#include <vector>

char Menu();
void AddProduct(std::vector<Product>& inventory, int& lastID);

int main(){
    std::vector<Product> inventory; // creates a vector with the custom struct we made product.h we also name this invetory
    int lastID = 223;

    inventory.push_back({++lastID, "apple", 2.5, 10});
    inventory.push_back({++lastID, "banana", 4.2, 20});
    inventory.push_back({++lastID, "watermelon", 6, 5});





    char choice = Menu();
    std::cout << choice;

    switch(choice){
        case '1': //DisplayAll(); break;
        case '2': AddProduct(); break;
        case '7': std::cout << "test"; break;
        default: std::cout << "invalid"; break;
    }

    return 0;
}

void AddProduct(std::vector<Product>& inventory, int& lastID){
    Product p;
    p.id = ++lastID;
    std::cout << "Enter Product name: ";
    std::cin >> p.name;

    do{
        std::cout << "Enter a price: ";
        std::cin >> p.price;
        if(p.price <= 0) std::cout << "Price must be over 0";
    }while(p.price <= 0);



}


char Menu(){
    char opt; //opt char just for holding answer
    while(true){ //keep going 
    std::cout << "========================================\n"
              << "        INVENTORY MANAGEMENT\n"  
              << "========================================\n";
    std::cout << "1. Display all products\n"
              << "2. Add new product\n"
              << "3. Update product quantity\n"
              << "4. Search product\n"
              << "5. Total inventory value\n"
              << "6. Remove Product\n"
              << "7. Exit\n";
    std::cin >> opt; //getting answer
    if (opt > '7'){ std::cout << "invalid option. Try again\n\n"; continue;} // if answer is larger then 7 make it invalid
    if (opt == '7'){std::cout << " Exiting program...\n"; break;} // if equal 7 leave loop
    
    return opt; //return opt to main function
    }
    return '7'; // just to satisfy compiler
}

