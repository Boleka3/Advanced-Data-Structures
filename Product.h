//
// Created by HP on 5/18/2024.
//

#ifndef ASSIGNMENT_2_DS_PRODUCT_H
#define ASSIGNMENT_2_DS_PRODUCT_H
#include<string>
using namespace std;


class Product {
private:
    string itemName;
    string category;
    int price;
public:
    Product(string name, string category, int price);

    string getName() const;

    string getCategory() const;

    int getPrice() const ;
    bool operator<(const Product& other);
    bool operator>(const Product& other);

    bool operator==(const Product& other);

    bool operator!=(const Product& other);

    void print();

    friend ostream& operator<<(ostream& os, const Product& item);
};


#endif //ASSIGNMENT_2_DS_PRODUCT_H
