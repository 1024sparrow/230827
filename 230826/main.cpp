#include <QApplication>
#include <string.h>
#include <stdio.h>

#include "LanguageIndicatorWidget.h"

//int gameplay();
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



	QApplication app(argc, argv);
	LanguageIndicatorWidget w(nullptr);
	w.show();
	return app.exec();
}
