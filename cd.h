#ifndef CD_H
#define CD_H
#include <iostream>

using namespace std;
class Cd
{
  private:
    char prformance[64];
    char label[32];
    int selections;
    double playtime;

  public:
    Cd(const char *s1, char *s2, int n, double x);
    Cd(const Cd &d);
    Cd();
    virtual ~Cd();
    virtual void Report() const
    {
        cout << "class_work" << classical_work << endl;
    }
    Cd &operator=(const Cd &d);
};
#endif /* CD_H */
