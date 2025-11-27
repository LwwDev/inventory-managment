/*
Inventory management system 
*/
#include <iostream>
#include "Product.h"
#include <vector>

char Menu();
void DisplayAll();
void AddProduct();

int main(){
    char choice = Menu();
    std::cout << choice;

    switch(choice){
        case 1: DisplayAll(); break;
        case 2: AddProduct(); break;
        default: std::cout << "invalid"; break;
    }

    return 0;
}


void Addproduct(){
    
}



void DisplayAll(){

}













char Menu(){
    char opt;
    while(true){
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
    std::cin >> opt;
    if (opt > '7'){ std::cout << "invalid option. Try again\n\n"; continue;}
    if (opt == '7'){std::cout << " Exiting program...\n"; break;}
    
    return opt;
    }
    return '7';
}

