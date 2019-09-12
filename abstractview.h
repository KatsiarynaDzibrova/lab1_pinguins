#ifndef ABSTRACTVIEW_H
#define ABSTRACTVIEW_H

class  AbstractView  {
public:
    virtual void drawPinguin() = 0;
    virtual void on_pushButton_clicked() = 0;
    virtual ~AbstractView() = default;
};

#endif // ABSTRACTVIEW_H
