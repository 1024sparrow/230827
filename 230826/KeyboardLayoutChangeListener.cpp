#include "KeyboardLayoutChangeListener.h"

#include <X11/Xutil.h>
#include <X11/XKBlib.h>

KeyboardLayoutChangeListener::KeyboardLayoutChangeListener(QObject *a_parent)
	: QThread(a_parent)
{

}

void KeyboardLayoutChangeListener::run()
{
	XEvent e;
	Display *d;

	if (!(d = XOpenDisplay(NULL))) {
			fprintf(stderr, "cannot open display\n");
			return;
	}

	XKeysymToKeycode(d, XK_F1);

	int xkbEventType;
	XkbQueryExtension(d, 0, &xkbEventType, 0, 0, 0);
	XkbSelectEvents(d, XkbUseCoreKbd, XkbAllEventsMask, XkbAllEventsMask);

	XSync(d, False);

	while (1)
	{
		XNextEvent(d, &e);
		if (e.type == xkbEventType) {
			XkbEvent* xkbEvent = (XkbEvent*) &e;
			if (xkbEvent->any.xkb_type == XkbStateNotify) {
				int lang = xkbEvent->state.group;
				emit sgnLayoutChanged(lang);
			}
		}
	}
	return;
}
