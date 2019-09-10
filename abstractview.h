#ifndef ABSTRACTVIEW_H
#define ABSTRACTVIEW_H

class  AbstractView  {
public:
    AbstractView();
    virtual void DrawPinguin();
    virtual void on_pushButton_clicked();
    virtual ~AbstractView();
};

#endif // ABSTRACTVIEW_H
