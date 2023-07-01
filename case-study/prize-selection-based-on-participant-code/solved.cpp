#include <iostream>

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

void findSubString(string code, string key){
  int codeLength = getStringLength(code);
  int keyLength = getStringLength(key);
  string slices[codeLength];
  string lastSlice = "";

  for (int i = 0; i < codeLength; i++){
    lastSlice += code[i];
    int lastSliceLength = getStringLength(lastSlice);

    if (lastSliceLength == keyLength && lastSlice != key){
      slices[i] = lastSlice;
      lastSlice = delString(lastSlice);
    }
    if (lastSliceLength == keyLength && lastSlice == key){
      int startIndex = (i - keyLength) + 1;
      int lastIndex = i;
      cout << key << " " << "ditemukan pada indeks " << startIndex << " - " << lastIndex << " dari string " << code;
      break;
    }
  }
}

int main(){
  string code;
  string key = "70";
  cout << "Input: "; cin >> code;
  findSubString(code, key);

  return 0;
}