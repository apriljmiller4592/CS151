/**
SortScore. Sorting Test Scores and calculating average
Name: April J Miller
Module: 3- Pointers and Dynamic Memory Allocation
Project: 2
Problem statement: The goal is to take in the names and test scores of 30 students and sort the scores in ascending order. Then, calculate the average of all of the test scores.
Algorithm:
1) Import iostream so that the program can process inputs and outputs.
2) Make a class to represent a student that contains instance variables for name and test score.
3) Create an h file which will contain the class functions and definitions.
4) Create a cpp file that will contain the implementation of the class.
Get and set each instance variable.
5) In the main method, prormpt user for how many test scores they would like to enter.
6) If the number of test scores is less than 0 or more than 30, print an error message and prompt them to enter a different score.
7) Place their name and score into the array and print it.
8) Create a method called sort that will sort the array by looping through the size of the array and comparing each element to the one in front of it.
If the size of the array is 0, skip that iteration of the loop. If it's greater than 0, and the score that is ahead of the score at each index in the size is greater than that score, swap them.
9) Call the sort method in the main method and then loop through the array and print out each element in the array to show the scores in ascending order.
10) Create a method called calculateAverage that will loop through the array of scores and add them up, and then divide by the size of the array to calculate the average.
11) In the main method, call the method to get the value of the average score.
12) Finally, delete the score array to free up memory.




*/



#include <iostream>
#include "Scores.h"

void sort(Scores *scores, int size)
{
  
    for (int t = 0; t < size; t++)
    {
      for (int z = t; z < size; z++)
      {
        if ((*(scores + z)).score() < (*(scores + t)).score())
        {
          if (z == 0 || t == 0)
          continue;

          Scores temp = (*(scores + t));
          (*(scores + t)) = (*(scores + z));
          (*(scores + z)) = temp;
        }
      }
    }
}

int calculateAverage(Scores *scores, int size)
{
  int sum = 0;

  for (int q = 0; q < size; ++q)
 {
    sum += (*(scores + q)).score();
  }
    return sum/size;
}



int main() {
  int size;
  std::string name = "";
  int score;

do {
  std::cout << "How many test scores would you like to enter? " << std::endl;
  std::cin >> size;

  if (size > 30)
  {
    std::cout << "Hey silly goose! You can't enter more than 30 test scores. Try again." << std::endl;
  }
  else if (size <= 0)
  {
    std::cout << "Please enter a positive number!" << std::endl;
    std::cout << std::endl;
  }
}while (size < 0 || size >30);

Scores *scores = new Scores[size];

for (int i = 0; i < size; i++)
 {

  std::cout<< "Whats the student's name?" << std::endl;
  std::cin >> name;
  do{
  std::cout << "What score did they get?" << std::endl;
  std::cin >> score;
  if (score < 0)
  {
    std::cout<< "Score cannot be less than 0!\n" << std::endl;
  }
  } while (score < 0);
  (*(scores + i)).setName(name);
  (*(scores + i)).setScore(score);
   std::cout <<"Name: " << (*(scores + i)).name()<<std::endl;
   std::cout <<"Score: " << (*(scores + i)).score()<<std::endl;


 } 
  sort(scores, size);
   std::cout<< "\nSorted list: " << std::endl;
  for (int i = 0; i < size; i++)
  {
    std::cout <<"Name: " << (*(scores + i)).name()<<std::endl;
    std::cout <<"Score: " << (*(scores + i)).score()<<std::endl;

  } 


  int x = calculateAverage(scores, size);
  std::cout << "\nAverage: " << x << std::endl;
  
  delete[] scores;
  return 0;
}

