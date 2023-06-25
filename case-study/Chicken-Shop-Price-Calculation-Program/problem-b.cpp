#include <iostream>
#include <string>

class ChickenShopReceipts {
  public:
    ChickenShopReceipts(const double friedChickenPrice, const double grilledChickenPrice, const double discountCost, const double purchaseMinim);
    void acceptUserInput(); // Accepts user input for order details
    void calculateTotalPrice(); // Calculates the total price including discounts
    void printReceipts(); // Prints the receipt

  private:
    double priceFriedChicken;
    double priceGrilledChicken;
    double totalPrice;
    double discount;
    double priceDiscount;
    double minimPurchase;
    std::string customerName;
    int selectedMenuOption;
    int totalAmount;
};

ChickenShopReceipts::ChickenShopReceipts(const double friedChickenPrice, const double grilledChickenPrice, const double discountCost, const double purchaseMinim)
    : priceFriedChicken(friedChickenPrice), priceGrilledChicken(grilledChickenPrice), discount(discountCost), minimPurchase(purchaseMinim) {}

void ChickenShopReceipts::acceptUserInput() {
  std::cout << "Input your order" << std::endl;
  std::cout << "1. Fried Chicken\t: IDR 17,000" << std::endl;
  std::cout << "2. Grilled Chicken\t: IDR 21,000" << std::endl;
  std::cout << "Discount 10%, if the purchase exceeds IDR 45,000 " << std::endl;
  std::cout << "Name\t\t: ";
  std::cin >> customerName;
  std::cout << "Input menu\t: ";
  std::cin >> selectedMenuOption;
  std::cout << std::endl;

  if (selectedMenuOption != 1 && selectedMenuOption != 2) {
      std::cout << "Error: Invalid menu option!" << std::endl;
      exit(0);
  }

  // Determine the menu name and price based on the selected option
  std::string menuName = (selectedMenuOption == 1) ? "Fried Chicken" : "Grilled Chicken";
  double menuPrice = (selectedMenuOption == 1) ? priceFriedChicken : priceGrilledChicken;

  std::cout << std::endl;
  std::cout << "Menu chosen: " << menuName << std::endl;
  std::cout << menuName << "\t: IDR " << menuPrice << std::endl;

  std::cout << "Input amount\t: ";
  std::cin >> totalAmount;

  if (totalAmount <= 0) {
      std::cout << "Error: Invalid amount!" << std::endl;
      exit(0);
  }
}

void ChickenShopReceipts::calculateTotalPrice() {
  // Determine the menu price based on the selected option
  double menuPrice = (selectedMenuOption == 1) ? priceFriedChicken : priceGrilledChicken;
  totalPrice = menuPrice * totalAmount;

  if (totalPrice > minimPurchase) {
      priceDiscount = totalPrice * discount;
      totalPrice -= priceDiscount;
  }
}

void ChickenShopReceipts::printReceipts() {
  std::cout << std::endl << std::endl;
  std::cout << "Receipt" << std::endl;
  std::cout << "Menu chosen" << std::endl;
  std::cout << "Customer\t\t: " << customerName << std::endl;

  // Determine the menu name and price based on the selected option
  std::string menuName = (selectedMenuOption == 1) ? "Fried Chicken" : "Grilled Chicken";
  double menuPrice = (selectedMenuOption == 1) ? priceFriedChicken : priceGrilledChicken;

  std::cout << selectedMenuOption << ". " << menuName << "\t: IDR " << menuPrice << std::endl;
  std::cout << "Total amount\t\t: " << totalAmount << std::endl;
  std::cout << "Discount 10%, if the purchase exceeds IDR 45,000 " << std::endl;
  std::cout << "Total price\t\t: IDR " << totalPrice << std::endl;
}

int main() {
  const double friedChickenPrice = 17000;
  const double grilledChickenPrice = 21000;
  const double discountCost = 0.10;
  const double purchaseMinim = 45000;

  ChickenShopReceipts receipt(friedChickenPrice, grilledChickenPrice, discountCost, purchaseMinim);
  receipt.acceptUserInput();
  receipt.calculateTotalPrice();
  receipt.printReceipts();

  return 0;
}