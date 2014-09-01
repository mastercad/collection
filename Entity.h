#ifndef __ENTITY_H__
#define __ENTITY_H__

#include <string>

class Entity
{
  public:
    std::string getName() const;
    void setName(const std::string);
    Entity();
    ~Entity();
  protected:
  private:
    std::string _sName;
};

#endif