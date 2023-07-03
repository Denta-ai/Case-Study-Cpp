#include <iostream>
#include <vector>

using namespace std;

int getStringLength(string strings){
  int length = 0;
  while (strings[length] != '\0'){
    length += 1;
  }
  return length;
}

string delString(string lastSlice){
  int lastSliceLength = getStringLength(lastSlice);
  string deletedString = "";
  for (int character = 1; character < lastSliceLength; character++){
    deletedString += lastSlice[character];
  }
  return deletedString;
}

void findSubString(string code, string keys[], int numbKeys, string values[]){
  int codeLength = getStringLength(code);
  int keyLength = getStringLength(keys[0]);
  bool found = false;
  vector<string>slices;
  string lastSlice = "";

  for (int i = 0; i < codeLength - keyLength + 1; i++){
    lastSlice += code[i];
    int lastSliceLength = getStringLength(lastSlice);

    for (int j = 0; j < numbKeys; j++) {
      if (lastSliceLength == keyLength && lastSlice == keys[j]) {
        int startIndex = i;
        int lastIndex = i + keyLength - 1;
        cout << keys[j] << " ditemukan pada indeks " << startIndex
        << " - " << lastIndex << " dari string " << code << " dengan isi "
        << values[j] << endl;
        found = true;
      }
    }
    if (lastSliceLength == keyLength){
      slices.push_back(lastSlice);
      lastSlice = delString(lastSlice);
    }
    
  }
}

int main(){
  string code;
  cout << "Input: "; cin >> code;

  string keys[4] = {
    "15", "70", "90", "45" 
  };

  string values[4] = {
    "Rice cooker", "TV 45 Inch", "Kulkas 2 pintu", "iPhone 14"
  };

  int numbKeys = sizeof(keys)/sizeof(keys[0]);

  findSubString(code, keys, numbKeys, values);

  return 0;
}