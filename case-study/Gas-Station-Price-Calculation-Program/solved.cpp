#include <iostream>
#include <string>
#include <vector>

class GasStationReceipts {
  public:
    // Constructor that initializes the prices and total.
    GasStationReceipts(double pertalitePrice, double pertamaxPrice, double priceTotal);
    
    // Accepts user input for the receipt.
    void acceptUserInput();

    // Calculates the total price based on the selected gasoline type and total liters.
    void calculateTotalPrice();

    // Prints the receipt details.
    void printReceipt() const;

  private:
    std::string customerName;
    std::string gasolineType;
    double pricePertalite;
    double pricePertamax;
    double totalLiters;
    double totalPrice;

};

// Constructor implementation
GasStationReceipts::GasStationReceipts(double pertalitePrice, double pertamaxPrice, double priceTotal)
  : pricePertalite(pertalitePrice), pricePertamax(pertamaxPrice), totalPrice(priceTotal) {}

// Accepts user input for the receipt.
void GasStationReceipts::acceptUserInput(){
  std::cout << "Input your order" << std::endl;
  std::cout << "1.Pertalite IDR 7,000/liter" << std::endl;
  std::cout << "2.Pertamax IDR 9,000/liter" << std::endl;
  std::cout << "Input customer name\t\t\t\t: "; std::cin >> customerName;
  std::cout << "Input gasoline type (pertalite,pertamax)\t: "; std::cin >> gasolineType;
  std::cout << "Input total liters\t\t\t\t: "; std::cin >> totalLiters;

}

// Calculates the total price based on the selected gasoline type and total liters.
void GasStationReceipts::calculateTotalPrice(){
  if (gasolineType == "pertalite"){
    totalPrice = pricePertalite*totalLiters;
  }
  if (gasolineType == "pertamax"){
    totalPrice = pricePertamax*totalLiters;
  }
  if (gasolineType != "pertalite" && gasolineType != "pertamax"){
    std::cout << "Error! Gasoline type isn't available";
    exit(0);
  }

}

// Prints the receipt details.
void GasStationReceipts::printReceipt() const {
  std::cout << std::endl << std::endl;
  std::cout << "Receipt" << std::endl;
  std::cout << "Customer name\t: " << customerName << std::endl;
  std::cout << "1.Pertalite IDR 7,000/liter" << std::endl;
  std::cout << "2.Pertamax IDR 9,000/liter" << std::endl;
  std::cout << "Gasoline Type\t: " << gasolineType << std::endl;
  std::cout << "Total liters\t: " << totalLiters << std::endl;
  std::cout << "Total price\t: " << totalPrice << std::endl;

}

int main(){
  const double pertalitePrice = 7000;
  const double pertamaxPrice = 9000;
  const double priceTotal = 0;
  char repeatOrder = 'y';

  std::vector<GasStationReceipts>receipts;  // Vector to store all receipts

  while(repeatOrder == 'y'){
    GasStationReceipts receipt(pertalitePrice,pertamaxPrice, priceTotal); // Create a new receipt

    std::system("cls");
    receipt.acceptUserInput();  // Accept user input for the receipt
    receipt.calculateTotalPrice();  // Calculate the total price for the receipt
    receipt.printReceipt(); // Print the receipt details

    receipts.push_back(receipt);  // Add the receipt to the vector

    std::cout << "Order again? (y/n) : "; std::cin >> repeatOrder;
    if (repeatOrder != 'y'){
      break;
    } 
  }

  std::cout << std::endl << "All Receipt" << std::endl;
  for (const auto& receipt : receipts){
    receipt.printReceipt(); // Print all receipts stored in the vector
  }

  return 0;

}