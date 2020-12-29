/*
PSEUDOCODE:

Find Lca returns an int, takes in the vector, and two integers
  while the i is within the range of the vector size (0 - vec.size())
    if the current root is greater than both leaves 
      go to the left( 2 * position in the array + 1 goes to the left root)
    else if the current root is less than both of the leaves 
      go to the right(2 * position in the arrray + 2) goes to the right root
    else the root must be in range of the two leaves 
      therefore the current root is the lca 
      return the numerical value of the lca
Main:
    take in user input
    use string stream to convert strings to ints 
    store in vec
    call FindLca and store the return value: passed value to copying the vector
    print to console 
*/
#include <iostream> 
#include <vector>
#include <sstream>
#include <string>

int FindLca(std::vector<int> &vec, int num1, int num2) {
  int i = 0;
  while(i < vec.size() && i >= 0) {
    if(vec[i] > num1 && vec[i] > num2) {
       i = 2*i+1;
    }
    else if(vec[i] < num1 && vec[i] < num2) {
      i = 2*i+2;
    }
    else {
      return vec[i];
    }
  }
  return 0;
}

int main() {
  std::vector<int> elements;
  std::string input;
  std::getline(std::cin, input);
  std::stringstream convert(input);
  int number;
  while (convert >> number) {
    elements.push_back(number);
  }
  int leaf1, leaf2;

  std::cin>>leaf1>>leaf2;
  int lca = FindLca(elements, leaf1, leaf2);
  std::cout<<"lca = "<<lca;
}
