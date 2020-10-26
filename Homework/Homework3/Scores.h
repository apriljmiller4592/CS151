#ifndef SCORES_H
#define SCORES_H
#include <iostream>
#include <ostream>
#include <istream>

class Scores
{
  public:
  Scores(std::string& name, int score);
  Scores();
  ~Scores();
  const std::string& name() const;
  void setName( std::string& newName);
  int score() const;
  void setScore(int newScore);

  private:
  std::string mName;
  int mScore;

};

#endif