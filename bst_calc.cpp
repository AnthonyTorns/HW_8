/*PSEUDOCODE: 
Sort void return type takes in a vector of ints
  implementation of Insertion search used to sort the elements of the vector

Main:
  input read into string variable using getline 
  stringstream used to convert the numerical values of the string
  while loop places numerical values into a vector after theyve been converted
  Sort elements to find min and max easier
  sum found using the accumulate function form STL
  find avg(divede sum by size of the vec) and store in float variabnle 
  display max, min, avg, and sum
*/

#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <numeric>
#include <iomanip>

void Sort(std::vector<int> &vals) {
  for (int i = 1; i < vals.size(); i++) {
    int j = i - 1;
    int key = vals[i];
    while (j > -1 && vals[j] > key)
    {
      vals[j + 1] = vals[j];
      j = j - 1;
    }
    vals[j + 1] = key;
  }
}

int main() {
  std::string input;
  std::getline(std::cin, input);
  std::stringstream convert(input);
  std::vector<int> elements;
  int number;
  float sum = 0;
  while (convert >> number) {
    elements.push_back(number);
  }

  Sort(elements);
  sum = std::accumulate(elements.begin(), elements.end(), sum);
  float avg = sum / elements.size();
  std::cout << "min = " << elements[0] << std::endl;
  std::cout << "max = " << elements[elements.size() - 1] << std::endl;
  std::cout << std::setprecision(2) << std::fixed << "avg = " << avg;

  return 0;
}
