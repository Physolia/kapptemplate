echo "Creating $LOCATION_ROOT/main.cpp...";
cat << EOF > $LOCATION_ROOT/main.cpp
#include "${APP_NAME_LC}.h"
#include <kapplication.h>
#include <kaboutdata.h>
#include <kcmdlineargs.h>
#include <KLocale>

static const char description[] =
    I18N_NOOP("A KDE 4 Application");

static const char version[] = "${APP_VERSION}";

int main(int argc, char **argv)
{
    KAboutData about("${APP_NAME_LC}", 0, ki18n("${APP_NAME}"), version, ki18n(description),
                     KAboutData::License_GPL, ki18n("(C) 2007 ${AUTHOR}"), KLocalizedString(), 0, "${EMAIL}");
    about.addAuthor( ki18n("${AUTHOR}"), KLocalizedString(), "${EMAIL}" );
    KCmdLineArgs::init(argc, argv, &about);

    KCmdLineOptions options;
    options.add("+[URL]", ki18n( "Document to open" ));
    KCmdLineArgs::addCmdLineOptions(options);
    KApplication app;

    ${APP_NAME} *widget = new ${APP_NAME};

    // see if we are starting with session management
    if (app.isSessionRestored())
    {
        RESTORE(${APP_NAME});
    }
    else
    {
        // no session.. just start up normally
        KCmdLineArgs *args = KCmdLineArgs::parsedArgs();
        if (args->count() == 0)
        {
            //${APP_NAME_LC} *widget = new ${APP_NAME_LC};
            widget->show();
        }
        else
        {
            int i = 0;
            for (; i < args->count(); i++)
            {
                //${APP_NAME_LC} *widget = new ${APP_NAME_LC};
                widget->show();
            }
        }
        args->clear();
    }

    return app.exec();
}
