//Author: April J. Miller
//Module: 1
//Project: Homework 1
//Problem Statement: In alphabetical order, display
//all Southern America countries sorted by area in ascending order.

//Algorithm: 
//1) Create Country class that contains name, area, and population variables.
//2) Create empty vector
//3) Create function to sort the areas of each country ascending
//   put them in the right place in the vector.
//4) This step has four cases to handle: If the vector is empty,
//   if the area is less than the areas before it, if the area is
//   greater than the areas before it, and if the area is greater than
//   all of the previous areas.
//5) After creating each Country object in alphabetical order in main,
//   call the function to place them in the right spot in the vector.
//6) Loop through the vector and display the Country names, populations, and areas.
//7) Use padding to make the display of countries and their information to make
//   the program easy to read and look more organized.








#include <iostream>
#include <vector>
#include <iomanip>

class Country
{
public:
  Country(const std::string& name, int population, int area)
  {
    _name = name;
    _area = area;
    _population = population;
  }

  const std::string& name() const 
  {
    return _name;
  }

  void setName(const std::string& newName)
  {
    _name = newName;
  }

  int area() const
  {
    return _area;
  }

  void setArea(int newArea)
  {
    _area = newArea;
  }

  int population() const
  {
    return _population;
  }

  void setPopulation(int newPopulation)
  {
    _population = newPopulation;
  }


private:
  std::string _name;
  int _area;
  int _population;
};

std::vector<Country> countries;

void sortArea(const Country c)
{
  int area = c.area();
  //if empty, add
  if(countries.empty())
  {
    countries.push_back(c);
    return;
  }

  for (int i = 0; i < countries.size(); i++)
  {
    if (area < countries[i].area())
    {
      countries.insert(countries.begin() + i, c);
      return;
    }
  }
  if (area >= countries.back().area())
  {
    countries.push_back(c);
  }
}

int main() {

  Country argentina("Argentina", 45259, 1073234);
  sortArea(argentina);
  Country bolivia("Bolivia", 11696, 424052);
  sortArea(bolivia);
  Country brazil("Brazil", 212845, 3287086);
  sortArea(brazil);
  Country chile("Chile", 19206, 291855);
  sortArea(chile);
  Country columbia("Columbia", 51115, 440715);
  sortArea(columbia);
  Country ecuador("Ecuador", 17705, 106851);
  sortArea(ecuador);
  Country falklandIslands("Falkland Islands", 3, 4700);
  sortArea(falklandIslands);
  Country frenchGuiana("French Guiana", 290, 32253);
  sortArea(frenchGuiana);
  Country guyana("Guyana", 787, 82978);
  sortArea(guyana);
  Country paraguay("Paraguay", 7145, 157056);
  sortArea(paraguay);
  Country peru("Peru", 33108, 496093);
  sortArea(peru);
  Country suriname("Suriname", 586, 63252);
  sortArea(suriname);
  Country uruguay("Uruguay", 3475, 68037);
  sortArea(uruguay);
  Country venezuela("Venezuela", 28102, 353748);
  sortArea(venezuela);
  


  std::cout << std::setw(16) << std::left << "  Country" << std::setw(13) << std::left <<"Population" << std::setw(7) << std::left << "Area" << std::endl;
  std::cout <<  std::setw(16) << std::left << "-----------"<<  std::setw(11) << std::left <<"----------" << "-------" << std::endl;
  for (int i = 0; i < countries.size(); i++)
  {

    std::cout << std::setw(16) << std::left << countries[i].name() << " ";
    std::cout << std::setw(6) << std:: right << countries[i].population() << " ";
    std::cout << std::setw(10) << std::right << countries[i].area() << " \n";
  }
}

