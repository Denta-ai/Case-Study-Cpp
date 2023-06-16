// English:
//   Create a program where a restaurant has the following menu:
//   1. Geprek chicken : IDR 21000
//   2. Fried chicken: IDR 17000
//   3. Fried shrimp: IDR 19000
//   4. Fried squid : IDR 20000
//   5. Grilled chicken: IDR 25000

//   The restaurant provides delivery order services, for customers whose homes are less than
//   3KM will be given a postage fee of 15,000, if it is more than that, a postage fee will be charged
//   25000. If the total purchase is more than 25000, you will receive a discount on shipping costs of 3000.
//   If the total purchase exceeds 50000, a discount of shipping 5000 dan will be given
//   discount as much as 15%. And if the total purchase exceeds 150000, a discount will be given
//   shipping of 8000 and a discount of 35%. 

//   >> Implement the loop into the program.
//   >> The output that comes out is expected in the form of a payment slip.

#include <iostream>
#include <string>
#include <array>
#include <vector>

class RestaurantReceipts {
  public:
    RestaurantReceipts();
    void acceptInputUser();
    void calculatePrice();
    void customerDistance();
    void priceDiscount();
    void printReceipt();
  private:
    std::array<std::string, 5> menu;
    std::array<double, 5> menuPrice;
    int amount;
    int selectedMenu;
    double totalPrice;
    int distance;
};

RestaurantReceipts::RestaurantReceipts() 
  : menu{"1.Greprek Chicken\t IDR 21000", "2.Fried chicken\t\t IDR 17000", 
          "3.Fried shrimp\t\t IDR 19000", "4.Fried squid\t\t IDR 20000", "5.Grilled chicken\t IDR 25000"},
    menuPrice{21000, 17000, 19000, 20000, 25000} {}

void RestaurantReceipts::acceptInputUser(){
  std::cout << "Menu:" << std::endl;
  for (int i = 0; i < size(menu); i++){
    std::cout << menu[i] << std::endl;
  }
  std::cout << "Input your choice: "; std::cin >> selectedMenu;
  std::cout << "Input how many order: "; std::cin >> amount;
  
}

void RestaurantReceipts::calculatePrice(){
  totalPrice = menuPrice[selectedMenu-1] * amount;
  std::cout << "Your order: " << std::endl;
  std::cout << menu[selectedMenu-1] << std::endl;
  std::cout << "Total price: " << totalPrice << std::endl;
}

void RestaurantReceipts::priceDiscount(){
  if (totalPrice > 25000 && totalPrice <= 50000){
    totalPrice -= 3000;
  }
  if (totalPrice > 50000 && totalPrice <= 150000){
    int temp = totalPrice;
    temp *= 0.15;
    totalPrice -= temp;
    totalPrice -= 5000;
  }
  if (totalPrice > 150000){
    int temp = totalPrice;
    temp *= 0.35;
    totalPrice -= temp;
    totalPrice -= 8000;
  }
}

void RestaurantReceipts::customerDistance(){
  std::cout << "Input your distance: "; std::cin >> distance;
  if (distance <= 3){
    totalPrice += 15000;
  }else {
    totalPrice += 25000;
  }
}

void RestaurantReceipts::printReceipt(){
  std::cout << "Receipts" << std::endl;
  std::cout << "Your choice:" << std::endl;
  std::cout << menu[selectedMenu-1] << std::endl;
  std::cout << "total price: " << totalPrice << std::endl;

}

int main(){
  char repeatOrder = 'y';
  RestaurantReceipts receipts;
  while(repeatOrder == 'y'){
    receipts.acceptInputUser();
    receipts.calculatePrice();
    receipts.priceDiscount();
    std::cout << "You want to order again? (y/n): "; std::cin >> repeatOrder;
    if (repeatOrder == 'n'){
      break;
    }
  }
  receipts.customerDistance();
  receipts.printReceipt();
  return 0;
}