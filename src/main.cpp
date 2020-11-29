
#include "core/application.h"

using namespace std;

int main(int argc, char** argv)
{
    Application app;
    if (!app.readArguments(argc, argv))
    {
        return -1;
    };

    app.runGenerator();
    app.displayPwdList();
    return 0;
}
