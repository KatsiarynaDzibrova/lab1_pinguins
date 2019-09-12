#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "model.h"
#include "abstractview.h"
#include "abstractcontroller.h"

class Controller: public AbstractController
{
public:
    Controller(AbstractView* view);
    ~Controller() override = default;
    void AddCustomer() override;
private:
    Model model;
    const AbstractView* view;
};

#endif // CONTROLLER_H
