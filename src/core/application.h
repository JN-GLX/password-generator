#ifndef APPLICATION_H
#define APPLICATION_H

#include "../Password/Password.h"
#include <iostream>
#include <vector>
#include <string>

class Application
{
    public:
        /** Default constructor */
        Application();

        void readArguments(int argc, char **argv);
        /** Default destructor */
        virtual ~Application();

    protected:

    private:
        int m_argCount; //!< Member variable "m_argCount"
        std::vector<string> m_argList; //!< Member variable "m_argList"
        int m_pwdLength;
        int m_nbPwd;
        std::vector<string> m_listPwd;
};

#endif // APPLICATION_H
