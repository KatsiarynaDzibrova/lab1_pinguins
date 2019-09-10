#include "controller.h"
#include "model.h"
#include "view.h"

Controller::Controller()
{}

void Controller::AddCustomer() {
}

void Controller::SetView(const View *view_){
    view = view_;
}
