#pragma once
class  AbstractView {
public:
	virtual void on_pushButton_clicked() = 0;
	virtual ~AbstractView() = default;
};