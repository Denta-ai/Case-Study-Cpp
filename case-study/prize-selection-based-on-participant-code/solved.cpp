#include <iostream>

using namespace std;

int getStringLength(string strings){
  int length = 0;
  while(strings[length] != '\0'){
    length+=1;
  }
  return length;
}

void findSubString(string code){
  int codeLength = getStringLength(code);
}

int main(){
  string code;
  cout << "Input: "; cin >> code;
  findSubString(code);

  return 0;
}