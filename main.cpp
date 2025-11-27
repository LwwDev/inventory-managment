#include <iostream>
#include "Product.h"
#include <vector>

char Menu();
void AddProduct(std::vector<Product>& inventory, int& lastID);
void preloadedItems(std::vector<Product>& inventory, int& lastID);

int main(){
    std::vector<Product> inventory; // creates a vector with the custom struct we made product.h we also name this invetory
    int lastID = 223;
    preloadedItems(inventory, lastID);
    while(true){
    char choice = Menu();
    switch(choice){
        case '1': //DisplayAll(); break;
        case '2': AddProduct(inventory, lastID); break;
        case '7': return 0;
        default: std::cout << "invalid"; break;
    }
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
        if(p.price <= 0) std::cout << "Price must be over 0\n";
    }while(p.price <= 0);

    do{
        std::cout << "Enter the quantity: ";
        std::cin >> p.quantity;
        if(p.quantity <= 0) std::cout << "Quantity must be over 0\n";
    }while(p.quantity <= 0);

    inventory.push_back(p);
    std::cout << "Product added successfully\n\n";
    

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

void preloadedItems(std::vector<Product>& inventory, int& lastID){
    inventory.push_back({++lastID, "apple", 2.5, 10});
    inventory.push_back({++lastID, "banana", 4.2, 20});
    inventory.push_back({++lastID, "watermelon", 6, 5});
}