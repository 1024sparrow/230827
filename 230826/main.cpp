#include <QCoreApplication>
#include <string.h>
#include <stdio.h>

#include <X11/Xutil.h>
#include <X11/XKBlib.h>

int gameplay();
int main(int argc, char **argv)
{
	for (int iArg = 0 ; iArg < argc ; ++iArg)
	{
		char *arg = argv[iArg];
		if (!strcmp(arg, "--help"))
		{
			puts("Program 230826");
			return 0;
		}
		else if (arg[0] == '-')
		{
			printf("Unknown key \"%s\". See help.\n", arg);
			return 1;
		}
	}



	//QCoreApplication app(argc, argv);
	//return app.exec();

	return gameplay();
}



int gameplay()
{
	XEvent e;
	Display *d;

	if (!(d = XOpenDisplay(NULL))) {
			fprintf(stderr, "cannot open display\n");
			return 1;
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
				if (lang == 1) {
					fprintf(stdout, "1\n");
					fflush(stdout);
				} else {
					fprintf(stdout, "0\n");
					fflush(stdout);
				}
			}
		}
	}
	return 0;
}
