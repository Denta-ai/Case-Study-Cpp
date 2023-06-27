#include <iostream>
#include <vector>

class PocketMoneyCalculator {
private:
    std::vector<double> expenses;

public:
    void addExpense(double amount) {
        expenses.push_back(amount);
    }

    double calculateTotalExpenses() {
        double total = 0.0;
        for (double expense : expenses) {
            total += expense;
        }
        return total;
    }

    double calculateCurrentSavings(double pocketMoney) {
        double totalExpenses = calculateTotalExpenses();
        return pocketMoney - totalExpenses;
    }

    void displayMonthlyExpenses() {
        int month = 1;
        for (double expense : expenses) {
            std::cout << "Month " << month << " expense: $" << expense << std::endl;
            month++;
        }
    }
};

int main() {
    double pocketMoney;
    int numOfMonths;

    std::cout << "Enter the amount of pocket money Andi receives every month: $";
    std::cin >> pocketMoney;

    std::cout << "Enter the number of months: ";
    std::cin >> numOfMonths;

    PocketMoneyCalculator calculator;

    for (int i = 0; i < numOfMonths; i++) {
        double expense;
        std::cout << "Enter the expense for month " << (i + 1) << ": $";
        std::cin >> expense;
        calculator.addExpense(expense);
    }

    std::cout << std::endl;
    calculator.displayMonthlyExpenses();

    double totalExpenses = calculator.calculateTotalExpenses();
    double currentSavings = calculator.calculateCurrentSavings(pocketMoney);

    std::cout << "Total expenses: $" << totalExpenses << std::endl;
    std::cout << "Current savings: $" << currentSavings << std::endl;

    return 0;
}
