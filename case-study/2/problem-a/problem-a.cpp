#include <iostream>

struct data {
    int choice, amount, userRange;
    std::string menuList[5] = {"Ayam geprek : Rp 21.000", "Ayam goreng : Rp 17.000", "Udang goreng : Rp 19.000", 
                            "Cumi goreng : 20.000", "Ayam bakar : Rp25.000"};
    int menuPrice[5] = {21000, 17000, 19000, 20000, 25000};
    int deliveryFee[2] = {15000,25000};
    int discountDelivery[3] = {3000,5000,8000};
    float discountCost[2] = {0.15,0.35};
    int smallDiscount = 0, bigDiscount = 0;
    int firstCost = 0, finalCost = 0;
};

void outputMenuList(data& dt){
    int menuAmount = 5;
    std::cout << "Menu Rumah Makan: " << std::endl;
    for (int i = 0; i < menuAmount; i++){
        std::cout << i+1 << "." << dt.menuList[i] << std::endl; 
    }
}

void inputUserData(data& dt){
    std::cout << "Masukan pilihan menu = "; std::cin >> dt.choice;
    std::cout << "Jumlah yang diinginkan = "; std::cin >> dt.amount;
    std::cout << "Jarak rumah = "; std::cin >> dt.userRange;
    std::cout << std::endl;
}

void countPrice(data& dt){
    dt.firstCost = dt.menuPrice[dt.choice-1]*dt.amount;
    dt.finalCost = dt.menuPrice[dt.choice-1]*dt.amount;
}

void checkUserRangeAndCountFinalPrice(data& dt){
    int minRange = 3;
    if (dt.userRange <= minRange){
        dt.finalCost += dt.deliveryFee[0];
    }
    if (dt.userRange > minRange){
        if (dt.finalCost >= 50000 && dt.finalCost < 150000){
            dt.deliveryFee[1] -= dt.discountDelivery[1];
            dt.smallDiscount = dt.finalCost * dt.discountCost[0];
            dt.finalCost -= dt.smallDiscount + dt.deliveryFee[1];
        }
        if (dt.finalCost >= 150000){
            dt.deliveryFee[1] -= dt.discountDelivery[2];
            dt.bigDiscount = dt.finalCost * dt.discountCost[1];
            dt.finalCost -= dt.bigDiscount;
            dt.finalCost -= dt.deliveryFee[1];
        }
    }
}

void outputDeliveryFee(data& dt){
  int minRange = 3;
  if (dt.userRange <= minRange){
      std::cout << "biaya ongkir = " << dt.deliveryFee[0] << std::endl;
  }
  if (dt.userRange > minRange){
      std::cout << "biaya ongkir = " << dt.deliveryFee[1] << std::endl;
  }
}

void outputStruct(data& dt){
    std::cout << "Daftar pesanan: " << std::endl;
    std::cout << dt.amount << "x " << dt.menuList[dt.choice-1] << std::endl;
    std::cout << "total awal = Rp" << dt.firstCost << std::endl;
    std::cout << "jarak rumah = " << dt.userRange << std::endl;
    outputDeliveryFee(dt);
    std::cout << "diskon yang didapat = Rp" << dt.smallDiscount << std::endl;
    std::cout << "total akhir bayar = " << dt.finalCost;
}

int main(){
    data dt;
    outputMenuList(dt);
    inputUserData(dt);
    countPrice(dt);
    checkUserRangeAndCountFinalPrice(dt);
    outputStruct(dt);
    return 0;
}