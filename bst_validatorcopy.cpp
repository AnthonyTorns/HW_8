//PSEUDOCODE:
/*
Is_BST: retunrs a bool takes in a vector of ints
  pos = the position of last element in the vector
  leaf reperesents the current element at the position of pos 
  root equals the first element 
  leaf_pos represents the posittion of the current leaf 
  sub_tree_root equals the sub_tree_root root of a given leaf
  ***Proofs****
  (we can find the parent position of a leaf by using this equation (i - 1)/2 where i is a given leafs position )
  (We also know that the equation 2*i+2(even) we give the position of any leaf that is greater than it's subroot and 2*i+1(odd) will the give the position of any leaf that is less than it's sub root)
  (Lastly if a leaf's greatest sub root (excluding the top root) is odd it must be less than the top root and on the left side and vice versa)
  Using these proofs we can validate if a list of values represents a BST by traveling from the botttom of the tree and comparing all roots with a leaf.
  ********
  while the pos of a leaf is > 0 
     if(sub_tree_root equals the root)
       make sure the reat is not less than both children or greater than both children 
       return false if so
     else
       if the current leaf positio is <= 2(we have traversed to the roots children)
         if the sub_tree_root equals the lement at position 1
           check if the root < leaf return false if so
         else if the current leaf position is at 2
           check if the root > than the leaf 
             return false if so
         reset the pos, leaf value and position and sub_tree_root
        
        else 
          if the leaf position is even(shoudl be on the right)
            if(leaf < sub_tree_root)(not on right)
              return false
          else
             if(leaf > sub_tree_root)(should be on the left)
               return false;
          leaf_pos set to next sub_tree_root pos
          sub_tree_root = next sub_tree_root value

            

*/

#include <iostream>
#include <vector>
#include <string>
#include <sstream>
//#include <cmath>
/*
bool Is_BST(std::vector<int> vec) {
  int pos = vec.size() - 1;
  int leaf = vec[pos];
  int root = vec[0];
  int leaf_pos = pos;
  int sub_tree_root = vec[floor((pos - 1) / 2)];
  int i = pos;
  while (pos > 0) {
    if (sub_tree_root == root) {
      if (vec[2] < root || vec[1] > root) {
        return false;
        }
        pos--;
    }
    else {
      if (leaf_pos <= 2) {
        if (sub_tree_root == vec[1]) {
          if (root < leaf) {
            return false;
          }
        }
        else if (sub_tree_root == vec[2]) {
          if (root > leaf) {
            return false;
            }
        }
        pos--;
        leaf = vec[pos];
        leaf_pos = pos;
        i = floor((pos - 1) / 2);
        sub_tree_root = vec[i];
      }
      else {
        if (leaf_pos % 2 == 0) {
          if (leaf < sub_tree_root) {
            return false;
          }
        }
        else {
          if (leaf > sub_tree_root) {
            return false;
            }
        }
        i = floor((i - 1) / 2);
        leaf_pos = i;
        sub_tree_root = vec[leaf_pos];
        }
      }
    }

  return true;
}
*/
bool Is_BST(std::vector<int> &vec) {
    for(int i = 1; i < vec.size(); i++) {
        if(vec[i] < vec[i-1]) {
            return false;
        }
    }
    return true;
}
void PlaceInorder(std::vector<int> &inorder_tree, int index, std::vector<int> &vec) {
  if(index < vec.size()) {
    PlaceInorder(inorder_tree, 2 * index + 1, vec);
    inorder_tree.push_back(vec[index]);
    PlaceInorder(inorder_tree, 2 * index + 2, vec);
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
    PlaceInorder(bst, 0, elements);
  bool value = Is_BST(bst);
  std::string conditiion;
  if (!value)
    conditiion = "False";
  else
    conditiion = "True";

  std::cout << conditiion;
  return 0;
}
