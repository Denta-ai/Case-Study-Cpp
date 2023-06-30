#include <iostream>

using namespace std;

int getStringLength(string strings){
  int length = 0;
  while(strings[length] != '\0'){
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

void findSubString(string name, string keyword){
  string slices[5];
  int indexes[2];
  string lastSlice = "";
  int strlength = getStringLength(name);
  int keywordLength = getStringLength(keyword);

  for (int i = 0; i < strlength; i++){
    lastSlice += name[i];
    int lastSliceLength = getStringLength(lastSlice);

    if (lastSliceLength == keywordLength && lastSlice != keyword){
      slices[i] = lastSlice;
      lastSlice = delString(lastSlice);
    }
    if (lastSliceLength == keywordLength && lastSlice == keyword){
      int startIndex = (i - keywordLength) + 1;
      int lastIndex = i;
      cout << keyword << " " << "found on indexs " << startIndex << " - " << lastIndex << " from string " << name; 
      break;
    }
  }
}


int main(){
  string name = "languages";
  string keyword = "gua";
  findSubString(name, keyword);
}