
#include "core/application.h"

using namespace std;

int main(int argc, char** argv)
{
    Application app;
    if (!app.readCommandLineArguments(argc, argv))
    {
        return -1;
    };

    app.initializeGenerator(EngineName::Prononçable);
    app.runGenerator();
    app.displayPasswordList();
    return 0;
}
