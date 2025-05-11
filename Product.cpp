//
// Created by HP on 5/18/2024.
//
#include "Product.h"
#include<bits/stdc++.h>

Product::Product(string itemName, string category, int price) : itemName(itemName), category(category), price(price) {}
string Product:: getName() const { return itemName; }

string Product:: getCategory() const { return category; }

int Product:: getPrice() const { return price; }
bool Product:: operator<(const Product& other) {
    return itemName < other.getName();
}
bool Product:: operator>(const Product& other) {
    return itemName > other.getName();
}

bool Product:: operator==(const Product& other) {
    return itemName == other.getName() and category == other.getCategory() and price == other.getPrice();
}

bool Product:: operator!=(const Product& other) {
    return itemName != other.getName() and category != other.getCategory() and price != other.getPrice();
}

void Product:: print() {
    cout << "Product: " << itemName << ", Category: " << category << ", Price: " << price << endl;
}

ostream& operator<<(ostream& os, const Product& item) {
    os << "Product: " << item.getName() << ", Category: " << item.getCategory() << ", Price: " << item.getPrice() << endl;
    return os;
}
