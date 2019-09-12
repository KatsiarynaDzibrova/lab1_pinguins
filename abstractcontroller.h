#ifndef ABSTRACTCONTROLLER_H
#define ABSTRACTCONTROLLER_H

#include <stack>
#include "abstractview.h"
#include <string>

class AbstractController
{
public:
    virtual ~AbstractController() = default;
    virtual void AddCustomer() = 0;
private:
    std::stack<std::string> Stack;
};

#endif // ABSTRACTCONTROLLER_H
