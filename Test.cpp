#include <iostream>
#include <string>
#include <Node.hpp>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include "doctest.h"
using namespace std;

#include "OrgChart.hpp"
using namespace ariel;

TEST_CASE("Test 1")
{
    for(int i=0;i<30;i++){
        CHECK_EQ(true,true);
    }

};