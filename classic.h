#ifndef CLASSIC_H
#define CLASSIC_H

#include "cd.h"
#include <iostream>

using namespace std;
class Classic : public Cd
{
  private:
    char classical_work[64];

  public:
    Classic(char *s1, const char *s2, char *s3, int n, double x) : Cd(s2, s3, n, x)
    {
        strcpy(classical_work, s1);
    }
    Classic();
    virtual ~Classic();
    virtual void Report() const
    {
        cout << "class_work" << classical_work << endl;
    }
};
#endif /* CLASSIC_H */
