#pragma once
#include "Product.h"
#include <vector>

struct Inventory {
    std::vector<Product> products;

    void addProduct();
    void DisplayProducts();
};