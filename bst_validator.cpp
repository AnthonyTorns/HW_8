//PSEUDOCODE:
/*
Is_BST: retunrs a bool takes in a vector of ints
  checks if in order traversal of vector
  returns false if not other wise returns true
PlaceInorder: takes in two vectors and an int 
  if the index of the original vec is less than the size
    recursive call to the left leaf(will keep calling until it reaches the end of the vector or most left node)
    places element in a new vector(starting w left leaf, then root, then right leaf)
    recursive call to the right leaf

  main: 
  take in user input as a string, 
  parse string and store ints in vector using while loop
  create new empty vector 
  place elements in the new vector using in order traversal(call Place_InOrder)
  validate if the vector is a bst and store boolean return value(call IS_BST)
  print out either true or false based on Is_BST return value;

*/

#include <iostream>
#include <vector>
#include <string>
#include <sstream>

bool Is_BST(std::vector<int> &vec) {
  for(int i = 1; i < vec.size(); i++) {
    if(vec[i] < vec[i-1]) {
      return false;
    }
  }
  return true;
}

void Place_InOrder(std::vector<int> &inorder_tree, int index, std::vector<int> &vec) {
  if(index < vec.size()) {
    Place_InOrder(inorder_tree, 2 * index + 1, vec);
    inorder_tree.push_back(vec[index]);
    Place_InOrder(inorder_tree, 2 * index + 2, vec);
  }
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
    std::vector<int> bst;
    Place_InOrder(bst, 0, elements);
  bool value = Is_BST(bst);
  std::string conditiion;
  if (!value)
    conditiion = "False";
  else
    conditiion = "True";

  std::cout << conditiion;
  return 0;
}
