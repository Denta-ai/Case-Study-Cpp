#include <iostream>
#include <vector>

enum MenuChoice {
    AYAM_GEPREK,
    AYAM_GORENG,
    UDANG_GORENG,
    CUMI_GORENG,
    AYAM_BAKAR,
    NUM_MENU_CHOICES
};

class Menu {
public:
    std::string name;
    int price;
};

class DeliveryFee {
public:
    int shortRange;
    int longRange;
};

class Data {
private:
    int choice;                       // User's menu choice
    int amount;                       // Amount of items
    int userRange;                    // Distance from the restaurant
    Menu listMenu[NUM_MENU_CHOICES];  // Array of Menu objects
    DeliveryFee deliveryFees;         // Delivery fee options
    int discountDelivery[3];          // Discount values for delivery
    float discountCost[2];            // Discount percentages for cost
    int smallDiscount;                // Discount amount
    int bigDiscount;                  // Discount amount
    int firstCost;                    // Initial cost before discounts
    int finalCost;                    // Final cost after discounts

public:
    void outputListMenu();                     // Output the restaurant menu
    void inputUserData();                      // Input user's data (choice, amount, range)
    void countPrice();                         // Calculate initial and final cost
    void checkUserRangeAndCountFinalPrice();    // Check user's range and apply discounts
    void outputDeliveryFee();                   // Output the delivery fee
    void receipts();                            // Output the receipts
};

void Data::outputListMenu() {
    std::cout << "Restaurant Menu : " << std::endl;
    for (int i = 0; i < NUM_MENU_CHOICES; i++) {
        std::cout << i + 1 << ". " << listMenu[i].name << " : Rp " << listMenu[i].price << std::endl;
    }
}

void Data::inputUserData() {
    std::cout << "Input menu = ";
    std::cin >> choice;
    std::cout << "Amount = ";
    std::cin >> amount;
    std::cout << "Distance = ";
    std::cin >> userRange;
    std::cout << std::endl;
}

void Data::countPrice() {
    firstCost = listMenu[choice - 1].price * amount;
    finalCost = listMenu[choice - 1].price * amount;
}

void Data::checkUserRangeAndCountFinalPrice() {
    int minRange = 3;
    if (userRange <= minRange) {
        finalCost += deliveryFees.shortRange;
    }
    else {
        if (finalCost >= 50000 && finalCost < 150000) {
            deliveryFees.longRange -= discountDelivery[1];
            smallDiscount = finalCost * discountCost[0];
            finalCost -= smallDiscount + deliveryFees.longRange;
        }
        else if (finalCost >= 150000) {
            deliveryFees.longRange -= discountDelivery[2];
            bigDiscount = finalCost * discountCost[1];
            finalCost -= bigDiscount;
            finalCost -= deliveryFees.longRange;
        }
    }
}

void Data::outputDeliveryFee() {
    int minRange = 3;
    if (userRange <= minRange) {
        std::cout << "Delivery fee = " << deliveryFees.shortRange << std::endl;
    }
    else {
        std::cout << "Delivery fee = " << deliveryFees.longRange << std::endl;
    }
}

void Data::receipts() {
    std::cout << "Receipts: " << std::endl;
    std::cout << amount << "x " << listMenu[choice - 1].name << std::endl;
    std::cout << "First cost = Rp " << firstCost << std::endl;
    std::cout << "Distance = " << userRange << std::endl;
    outputDeliveryFee();
    std::cout << "Discount = Rp " << smallDiscount << std::endl;
    std::cout << "Final cost = " << finalCost << std::endl;
}

int main() {
    Data data;
    data.outputListMenu();
    data.inputUserData();
    data.countPrice();
    data.checkUserRangeAndCountFinalPrice();
    data.receipts();

    return 0;
}
