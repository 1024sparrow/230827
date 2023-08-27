#pragma once

#include <QThread>

class KeyboardLayoutChangeListener : public QThread
{
	Q_OBJECT
public:
	KeyboardLayoutChangeListener(QObject *a_parent = nullptr);

signals:
	void sgnLayoutChanged(int a_index);

protected:
	void run() override;
};
