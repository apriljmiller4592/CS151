//Author: April J Miller
//Module: 1
//Project: Homework 1
//Problem statement: Scan through a vector of 30 random numbers 1-10
//and sort them in descending order. Then use the pop_back function
//to print them in ascending order until the vector is empty.

//Plan/Algorithm:
//1) Seed the srand so that you can use the rand() function.
//2) Generate a random number and mod it by 10 + 1 to make it into
//   a number between 0 and 10. In the for loop, add 1 to the beginning to get rid of the 0's. 
//3) Create an iterator so that you can insert values where the
//   iterator is pointing.
//4) Scan though the vector with the iterator and compare the numbers and use a temp variable to do the necessary swaps for sorting.
//5) Display the sorted vector.
//6) To display in ascending order, iterate from the end of the vector
// to the front. While the vector is not empty, pop each number back
//so that they are in ascending order and display them.



#include <iostream>
#include <vector>
#include <stdlib.h>
#include <cstdlib>
#include <time.h>

using namespace std;

int main() {
 
  vector<int> randomNums;
  vector<int>:: iterator it;
  srand(time(nullptr));

  it = randomNums.begin();
  randomNums.insert(it, (rand() % 10) + 1);

do {
    //scanning through vector with iterator 

  int num = (rand() % 10) + 1;
  cout << num << endl;
  for (it = randomNums.begin(); it < randomNums.end(); ++it)
  {
      //cout << "In the dooo" << endl;
      if (num >= *it)
      {
        randomNums.insert(it, num);
    //    cout << "i am smaller" << endl;
        break;
      }
  }
} while (randomNums.size() < 30);
//Descending print
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
  cout << "In descending order: " << endl;
  for (it = randomNums.begin(); it < randomNums.end(); ++it)
  {
    cout<< *it <<endl;
  }

//Ascending print
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
  cout << "In ascending order: " << endl;
  while (!randomNums.empty())
  {
    int x = randomNums.back();
    randomNums.pop_back();
    cout << x << endl;
  }




 /** for (it = randomNums.end(); it > randomNums.begin(); --it)
  {

    randomNums.pop_back();
  //  cout << *it << endl;
  }**/
  return 0;
}
