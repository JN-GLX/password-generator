#include <string>
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <random>
#include <chrono>
#include <algorithm>

class Engine
{
public:
    Engine();

    virtual ~Engine();

    std::string generatePassword(int length);


};

class PronouncableEngine : Engine {

};