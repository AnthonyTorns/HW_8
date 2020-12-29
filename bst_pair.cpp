/*
PSEUDOCODE::
  HAsPair returns bool takes in a vector and and int 
    iterator created foe vector 
      if the value at the iterator equals the desired number 
         true is returned 
      else false is returned

Main: 
  input read into string variable using getline 
  stringstream used to convert the numerical values of the string
  while loop places numerical values into a vector after theyve been converted
  iterator for given vector created
  for(....) {
     difference is taken by subtracting a value at a given position in the vec from the valuje entred 
     HasPair called if true 
     contains set to true and for loop breaks
     else iterator incremented
  
  if contains is true 
     print True 
  else 
    print false
  }
*/
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>

bool HasPair(std::vector<int> vec, int num) {
    std::vector<int>::iterator pos = std::find(vec.begin(), vec.end(), num);
    if(*pos == num) {
        return true;
    }
    return false;
}

int main() {
    std::string input;
    std::getline(std::cin, input);
    std::stringstream convert(input);
    std::vector<int> values;
    int number;
    while(convert>>number) {
        values.push_back(number);
    }
    int value = 0;
    int key = 0;
    std::cin>>value;
    bool contains = false;
    std::vector<int>::iterator it = values.begin();
    for( int i = 0; i < values.size(); i++) {
        key = value - (*it);
        if(HasPair(values, key)) {
            contains = true;
            break;
        }
        else{
            it++;
        }
    }
    if(contains == true) {
        std::cout<<"True";
    }
    else {
        std::cout<<"False";
    }
    return 0;
}