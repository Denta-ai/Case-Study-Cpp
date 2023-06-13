#include <iostream>
#include <string>

class GasStationReceipts {
  public:
    GasStationReceipts(double pertalitePrice, double pertamaxPrice, double priceTotal);
    void acceptUserInput();
    void calculateTotalPrice();
    void printReceipts();

  private:
    double pricePertalite;
    double pricePertamax;
    double totalLiters;
    std::string customerName;
    std::string gasolineType;
    double totalPrice;

};

GasStationReceipts::GasStationReceipts(double pertalitePrice, double pertamaxPrice, double priceTotal)
    : pricePertalite(pertalitePrice), pricePertamax(pertamaxPrice), totalPrice(priceTotal) {}

int main(){
  double pertalitePrice = 7000;
  double pertamaxPrice = 9000;
  double priceTotal = 0;
  char repeatOrder = 'y';

  GasStationReceipts receipt(pertalitePrice,pertamaxPrice, priceTotal);

  while(repeatOrder == 'y'){

    std::system("cls");
    receipt.acceptUserInput();
    receipt.calculateTotalPrice();
    receipt.printReceipts();

    std::cout << "Order again? (y/n) : "; std::cin >> repeatOrder;
    if (repeatOrder != 'y'){
      break;
    } 
  }

}

void GasStationReceipts::acceptUserInput(){
  std::cout << "Input your order" << std::endl;
  std::cout << "Input customer name\t\t\t\t: "; std::cin >> customerName;
  std::cout << "Input gasoline type (pertalite,pertamax)\t: "; std::cin >> gasolineType;
  std::cout << "Input total liters\t\t\t\t: "; std::cin >> totalLiters;

}

void GasStationReceipts::calculateTotalPrice(){
  if (gasolineType == "pertalite"){
    totalPrice = pricePertalite*totalLiters;
  }
  if (gasolineType == "pertamax"){
    totalPrice = pricePertamax*totalLiters;
  }
  if (gasolineType != "pertalite" && gasolineType != "pertamax"){
    std::cout << "Error! Gasoline type isn't available";
  }

}

void GasStationReceipts::printReceipts(){
  std::cout << std::endl << std::endl;
  std::cout << "Receipt" << std::endl;
  std::cout << "Customer name\t: " << customerName << std::endl;
  std::cout << "Gasoline Type\t: " << gasolineType << std::endl;
  std::cout << "Total liters\t: " << totalLiters << std::endl;
  std::cout << "Total price\t: " << totalPrice << std::endl;

}