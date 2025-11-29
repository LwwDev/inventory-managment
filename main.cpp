#include <iostream>
#include "Product.h"
#include <vector>
#include <limits>

char Menu();
void DisplayAll(std::vector<Product>& inventory, int& lastID);
void AddProduct(std::vector<Product>& inventory, int& lastID);
void PreloadedItems(std::vector<Product>& inventory, int& lastID);
void UpdateProduct(std::vector<Product>& inventory, int& lastID);
void Pause();
void Clear();

int main(){
    std::vector<Product> inventory; // creates a vector with the custom struct we made product.h we also name this invetory
    int lastID = 223; 
    PreloadedItems(inventory, lastID); // calls preloaded items
    while(true){
    char choice = Menu();
    switch(choice){
        case '1': DisplayAll(inventory, lastID); Pause(); break;
        case '2': AddProduct(inventory, lastID); break;
        case '3': UpdateProduct(inventory, lastID); break;
        case '7': return 0;
        default: std::cout << "invalid"; break;
    }
    }
    return 0;
}

void DisplayAll(std::vector<Product>& inventory, int& lastID){
    Clear();
    if(inventory.empty()){std::cout << "Inventory is empty\n\n"; return;}
    std::cout << "========================================\n";
    std::cout << "            ALL PRODUCTS\n";
    std::cout << "========================================\n";

    for(int i = 0; i < inventory.size(); i++){
        std::cout << "ID: " << inventory[i].id << '\n';
        std::cout << "Name: " << inventory[i].name << '\n';
        std::cout << "Price: " << inventory[i].price << '\n';
        std::cout << "Quantity: " << inventory[i].quantity << '\n';
        std::cout << "========================================\n";
    }
    std::cout << '\n';
}



void AddProduct(std::vector<Product>& inventory, int& lastID){
    Clear();
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

void PreloadedItems(std::vector<Product>& inventory, int& lastID){
    inventory.push_back({++lastID, "apple", 2.5, 10});
    inventory.push_back({++lastID, "banana", 4.2, 20});
    inventory.push_back({++lastID, "watermelon", 6, 5});
}

void UpdateProduct(std::vector<Product>& inventory, int& lastID){
    int ProductID;
    DisplayAll(inventory, lastID);
    std::cout << "Which product to update (ID): ";
    std::cin >> ProductID;
    
}

void Pause(){
    std::cout << "Press ENTER to continue...";
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cin.get();
}
void Clear(){
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}