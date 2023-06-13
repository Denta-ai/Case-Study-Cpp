#include <iostream>
#include <string>

class ChickenShopReceipts {
  public:
    ChickenShopReceipts(const double friedChickenPrice, const double grilledChickenPrice, const double discountCost, const double purchaseMinim);
    void acceptUserInput();
    void calculateTotalPrice();
    void printReceipts();

  private:
    double priceFriedChicken;
    double priceGrilledChicken;
    double totalPrice;
    double Discount;
    double priceDiscount;
    double minimPurchase;
    std::string customerName;
    int selectedOrder;
    int totalAmount;
    
};

ChickenShopReceipts::ChickenShopReceipts(const double friedChickenPrice, const double grilledChickenPrice, const double discountCost, const double purchaseMinim)
  : priceFriedChicken(friedChickenPrice), priceGrilledChicken(grilledChickenPrice), Discount(discountCost), minimPurchase(purchaseMinim) {};

int main(){
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

void ChickenShopReceipts::acceptUserInput(){
  std::cout << "Input your order" << std::endl;
  std::cout << "1. Fried Chicken\t: IDR 17,000" << std::endl;
  std::cout << "2. Grilled Chicken\t: IDR 21,000" << std::endl;
  std::cout << "Discount 10%, if the purchase exceeds IDR 45,000 " << std::endl;
  std::cout << "Name\t\t: "; std::cin >> customerName;
  std::cout << "Input menu\t: "; std::cin >> selectedOrder;
  std::system("cls");

  if (selectedOrder == 1){
    std::cout << "Menu chose 1" << std::endl;
    std::cout << "Fried chicken\t: IDR 17,000" << std::endl;
    std::cout << "Input amount\t: "; std::cin >> totalAmount;
    calculateTotalPrice();
  }
  if (selectedOrder == 2){
    std::cout << "Menu chose 2" << std::endl;
    std::cout << "Grilled chicken\t: IDR 21,000" << std::endl;
    std::cout << "Input amount\t: "; std::cin >> totalAmount;
    calculateTotalPrice();
  }
  if (selectedOrder != 1 && selectedOrder != 2){
    std::system("cls");
    std::cout << "Error, wrong input!";
    exit(0);
  }

}

void ChickenShopReceipts::calculateTotalPrice(){
  std::system("cls");
  if (selectedOrder == 1){
    totalPrice = priceFriedChicken*totalAmount;
  }
  if (selectedOrder == 2){
    totalPrice = priceGrilledChicken*totalAmount;
  }
  if (totalPrice > minimPurchase){
    priceDiscount = totalPrice*Discount;
    totalPrice -= priceDiscount;
  }
}

void ChickenShopReceipts::printReceipts(){
  std::cout << "Receipt" << std::endl;
  std::cout << "Menu chose" << std::endl;
  std::cout << "Customer\t\t: " << customerName << std::endl;

  if (selectedOrder == 1){
    std::cout << "1. Fried Chicken\t: IDR 17,000" << std::endl;
    std::cout << "total amount\t\t: " << totalAmount << std::endl;
    std::cout << "Discount 10%, if the purchase exceeds IDR 45,000 " << std::endl;
    std::cout << "Total price\t\t: " << totalPrice << std::endl;

  }
  if (selectedOrder == 2){
    std::cout << "2. Grilled Chicken\t: IDR 21,000" << std::endl;
    std::cout << "total amount\t\t: " << totalAmount << std::endl;
    std::cout << "Discount 10%, if the purchase exceeds IDR 45,000 " << std::endl;
    std::cout << "Total price\t\t: " << totalPrice << std::endl;

  }

}

