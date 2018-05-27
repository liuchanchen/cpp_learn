#ifndef MOVIE_CONSTRUCTOR_H
#define MOVIE_CONSTRUCTOR_H

class move_class
{
private:
public:
  int x = 0;
  move_class();
  move_class(class move_class &);
  move_class(class move_class &&);
};

#endif /* MOVIE_CONSTRUCTOR_H */
