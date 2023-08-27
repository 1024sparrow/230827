# pragma once

#include <QWidget>

class KeyboardLayoutChangeListener;
class LanguageIndicatorWidget : public QWidget
{
	Q_OBJECT
public:
	LanguageIndicatorWidget(QWidget *a_parent);

private slots:
	void onKeyboardLayoutChanged(int a_index);

private:
	void mousePressEvent(QMouseEvent *event) override;
	void paintEvent(QPaintEvent *) override;

private:
	KeyboardLayoutChangeListener *_kbLayoutListener;
	int _kbLayout = -1;
};
