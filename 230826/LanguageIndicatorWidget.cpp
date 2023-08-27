#include "LanguageIndicatorWidget.h"
#include "KeyboardLayoutChangeListener.h"

#include <QApplication>
#include <QPainter>
#include <QDebug>

LanguageIndicatorWidget::LanguageIndicatorWidget(QWidget *a_parent)
	: QWidget(a_parent)
	, _kbLayoutListener(new KeyboardLayoutChangeListener(this))
{
	setFixedSize(50,50);

	connect(
		_kbLayoutListener,
		&KeyboardLayoutChangeListener::sgnLayoutChanged,
		this,
		&LanguageIndicatorWidget::onKeyboardLayoutChanged
	);
	_kbLayoutListener->start();
}

void LanguageIndicatorWidget::onKeyboardLayoutChanged(int a_index)
{
	_kbLayout = a_index;
	repaint();
}

void LanguageIndicatorWidget::mousePressEvent(QMouseEvent *event)
{
	// поступил сигнал от пользователя на смену раскладки клавиатуры
}

void LanguageIndicatorWidget::paintEvent(QPaintEvent *)
{
	QColor bgColor;
	if (_kbLayout == 0)
	{
		bgColor = Qt::gray;
	}
	else if (_kbLayout == 1)
	{
		bgColor = Qt::red;
	}
	else
	{
		bgColor = Qt::magenta;
	}

	QPainter painter(this);
	painter.fillRect(rect(), bgColor);
}
