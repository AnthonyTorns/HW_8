/*
PSEUDOCODE: 
FindLeaf returns a tuple containing a vector and an int 
  tuple created 
  int vlaue that serves as counter set to 0  

Main:
  input read into string variable using getline 
  stringstream used to convert the numerical values of the string
  while loop places numerical values into a vector after theyve been converted
  target leaf entered by user 
  FindLeaf function called and stored in a tuple 
  vector containing roots within the path is stored 
  the depth of the tree is stored 
  print depth and values;
  for( ......) 
    if target leaf val == to the element at a given cev position
      push value at the  given position into the vec 
      break for loop 
    else if leaf val <  vec position
      push value from given vec position 
      increase the depth by one 
      i is increased to the left chiled position in the vec 
    else 
      push value from given vec position 
      increase the depth by one 
      i is increased to the right chiled position in the vec 
    return tuple
  
*/
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <tuple>
#include <cmath>

std::tuple<std::vector<int>, int>  FindLeaf(std::vector<int> vec, int leaf_val) {
   std::tuple <std::vector<int>, int> bst_tuple;
   std::get<1>(bst_tuple) = 0;
    for(int i = 0; i < vec.size();) {
        if(leaf_val == vec[i]) {
            std::get<0>(bst_tuple).push_back(vec[i]);
            break;
        }
        else if(leaf_val < vec[i]) {
            std::get<0>(bst_tuple).push_back(vec[i]);
            std::get<1>(bst_tuple)++;
            i = floor(2*i+1);
        }
        else {
            std::get<0>(bst_tuple).push_back(vec[i]);
            i = floor(2*i+2);
            std::get<1>(bst_tuple)++;
        }
    }
    return std::make_tuple(std::get<0>(bst_tuple), std::get<1>(bst_tuple));
}

int main() {
    std::string input;
    std::getline(std::cin,input);
    std::stringstream convert(input);
    std::vector<int> elements;
    int number; 
    while(convert>>number) {
        elements.push_back(number);
    }
    int target;
    std::cin>>target;
    auto bst_tuple = FindLeaf(elements, target);
    std::vector<int> path = std::get<0>(bst_tuple);
    int depth = std::get<1>(bst_tuple);
    std::cout<<"depth = "<<depth<<std::endl;
    std::cout<<"path =";
    for(int i = 0; i < path.size(); i++) {
        std::cout<<" "<<path[i];
    }
    return 0;
}
