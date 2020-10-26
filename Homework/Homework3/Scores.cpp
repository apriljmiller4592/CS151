#include "Scores.h"
#include <iomanip>
#include <iostream>
#include <ostream>

Scores::Scores(std::string& name, int score)
{
  mName = name;
  mScore = score;
}

Scores::Scores()
{

}

Scores::~Scores()
{
  
}

const std::string& Scores::name() const
{
  return mName;
}

void Scores::setName(std::string& newName)
{
  mName = newName;
}
int Scores::score() const
{
  return mScore;
}
void Scores::setScore(int newScore)
{
  mScore = newScore;
}





