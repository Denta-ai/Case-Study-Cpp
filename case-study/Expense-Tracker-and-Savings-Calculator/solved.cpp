
// Andi mendapatkan uang saku dengan jumlah sama setiap bulannya. Ia gunakan uang saku itu untuk 
//   membeli beberapa keperluan kuliah dan jajannya. Akan tetapi, ia juga ingin menabung dari sisa uang 
//   saku yang ia miliki, walaupun tidak tentu setiap bulannya. 
//   Andi meminta kawannya yang kuliah Informatika untuk membuatkan aplikasi untuk menghitung itu 
//   semua dengan menampilkan pengeluaran tiap bulan, total pengeluaran, dan uang tabungannya saat ini.
//   Buatlah program dengan tim anda, dengan menerapkan materi iteratif-rekursif yang baru saja 
//   dipelajari dimateri praktikum minggu ini.
// Catatan :
// - Menampilkan data secara Iteratif
// - Menggunakan Class

#include <iostream>
#include <vector>

class moneyCalculator {
    public:
        void income();
        void expenses();
        void saving();
    private:

};

void moneyCalculator::income(){
    int moneyPerMonth = 0;
    char spentMoney;
    int items = 0;
    std::string itemsName;
    int itemsPrice;

    std::cout << "Input your money income per months : "; std::cin >> moneyPerMonth;
    std::cout << "Your stable income money : " << moneyPerMonth << std::endl;
    std::cout << "Did you spend your money? : "; std::cin >> spentMoney;
    if (spentMoney=='y'){
        while (spentMoney=='y'){
            items++;
            std::cout << "Your expenses" << std::endl;
            std::cout << "Item " << items << " : "; std::cin >> itemsName;
            std::cout << "Price " << items << " : "; std::cin >> itemsPrice;
            std::cout << "Again ? : "; std::cin >> spentMoney;
            if (spentMoney=='n'){
                exit(0);
            }
        }
    }
}

int main(){
    moneyCalculator count;
    count.income();
}