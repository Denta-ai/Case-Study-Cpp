// English:
//   Create a program where a restaurant has the following menu:
//   1. Geprek chicken : IDR 21000
//   2. Fried chicken: IDR 17000
//   3. Fried shrimp: IDR 19000
//   4. Fried squid : IDR 20000
//   5. Grilled chicken: IDR 25000

//   The restaurant provides delivery order services, for customers whose homes are less than
//   3KM will be given a postage fee of 15,000, if it is more than that, a postage fee of 15,000 will be charged
//   25000. If the total purchase is more than 25000, you will receive a discount on shipping costs of 3000.
//   If the total purchase exceeds 50000, a discount of shipping 5000 dan will be given
//   discount as much as 15%. And if the total purchase exceeds 150000, a discount will be given
//   shipping of 8000 and a discount of 35%. 

//   >> Implement the loop into the program.
//   >> The output that comes out is expected in the form of a payment slip.

#include <iostream>
#include <string>
#include <array>

class RestaurantReceipts {
  public:
    RestaurantReceipts();
    void acceptInputUser();
    void calculateProcess();
    void printReceipts();
  private:
    std::array<std::string, 5> menu;
    std::array<double, 5> menuPrice;
    std::array<double, 3> priceForDiscount;
    std::array<double, 2> discountPrice;
    std::array<double, 3> discountShipping;
    const double lowPostageCost;
    const double highPostageCost;
    double totalPrice;
    int selectedMenuChoice;
    int userDistance;
};

RestaurantReceipts::RestaurantReceipts() 
  : menu{"1.Greprek Chicken\t IDR 21000", "2.Fried chicken\t\t IDR 17000", 
          "3.Fried shrimp\t\t IDR 19000", "4.Fried squid\t\t IDR 20000", "5.Grilled chicken\t IDR 25000"},
    menuPrice{21000, 17000, 19000, 20000, 25000},
    priceForDiscount{25000, 50000, 150000},
    discountPrice{0.15, 0.35},
    discountShipping{3000, 5000, 8000},
    lowPostageCost(15000), highPostageCost(25000){}

void RestaurantReceipts::acceptInputUser(){
  std::cout << "Menu:" << std::endl;
  for (int i = 0; i < size(menu); i++){
    std::cout << menu[i] << std::endl;
  }
  std::cout << "Input choice: "; std::cin >> selectedMenuChoice;
  std::cout << "Input your distance: "; std::cin >> userDistance;
}

void RestaurantReceipts::calculateProcess(){
  
}

void RestaurantReceipts::printReceipts(){
  
}

int main(){
  RestaurantReceipts receipts;
  receipts.acceptInputUser();
  return 0;
}