#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "model.h"
#include "view.h"

class Controller
{
public:
    Controller();
    void AddCustomer();
    void SetView(const View* view_);
private:
    Model model;
    const View* view;
};

#endif // CONTROLLER_H
