#ifndef ITABLICA_H
#define ITABLICA_H


class ITablica {
  protected:
  virtual bool isFull() = 0;
  virtual void increaseSize() = 0;
  virtual int getSize() = 0;
  virtual int getDesiredSize() const = 0;
  virtual void setDesiredSize(int) = 0;
  virtual int operator[] (int i) const = 0;
  virtual int& operator[] (int i) = 0;
};

#endif