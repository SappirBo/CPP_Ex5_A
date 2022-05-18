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



TEST_CASE("Test 1 - Level Order")
{
    cout<<"Starting Test!"<<endl;
    OrgChart MicroSoft;
    vector<string> check;

    check.push_back("Bill Gates");
    check.push_back("aaa");
    check.push_back("bbb");
    check.push_back("ccc");
    check.push_back("ddd");
    check.push_back("eee");
    check.push_back("fff");

    CHECK_NOTHROW(MicroSoft.add_root("Bill Gates"););
    CHECK_NOTHROW(MicroSoft.add_sub("Bill Gates","aaa"););
    CHECK_NOTHROW(MicroSoft.add_sub("Bill Gates","bbb"););
    CHECK_NOTHROW(MicroSoft.add_sub("Bill Gates","ccc"););
    CHECK_NOTHROW(MicroSoft.add_sub("aaa","ddd"););
    CHECK_NOTHROW(MicroSoft.add_sub("aaa","eee"););
    CHECK_NOTHROW(MicroSoft.add_sub("ccc","fff"););

    size_t counter = 0;
    for(auto i=MicroSoft.begin_level_order(); i != MicroSoft.end_level_order() && counter < check.size(); ++i){
        CHECK_EQ(check[counter++] , i->curr->getData());
    }
};

TEST_CASE("Test 2 - Pre Order")
{
    OrgChart MicroSoft;
    vector<string> check;
    check.push_back("Bill Gates");
    check.push_back("aaa");
    check.push_back("ddd");
    check.push_back("eee");
    check.push_back("bbb");
    check.push_back("ccc");
    check.push_back("fff");

    CHECK_NOTHROW(MicroSoft.add_root("Bill Gates"););
    CHECK_NOTHROW(MicroSoft.add_sub("Bill Gates","aaa"););
    CHECK_NOTHROW(MicroSoft.add_sub("Bill Gates","bbb"););
    CHECK_NOTHROW(MicroSoft.add_sub("Bill Gates","ccc"););
    CHECK_NOTHROW(MicroSoft.add_sub("aaa","ddd"););
    CHECK_NOTHROW(MicroSoft.add_sub("aaa","eee"););
    CHECK_NOTHROW(MicroSoft.add_sub("ccc","fff"););

    size_t counter = 0;
    for(auto i=MicroSoft.begin_preorder(); i != MicroSoft.end_preorder() && counter < check.size(); ++i){
        CHECK_EQ(check[counter++] , i->curr->getData());
    }
};

TEST_CASE("Test 3 - Reverse Order")
{
    OrgChart MicroSoft;
    vector<string> check;
    check.push_back("ddd");
    check.push_back("eee");
    check.push_back("fff");
    check.push_back("aaa");
    check.push_back("bbb");
    check.push_back("ccc");
    check.push_back("Bill Gates");

    CHECK_NOTHROW(MicroSoft.add_root("Bill Gates"););
    CHECK_NOTHROW(MicroSoft.add_sub("Bill Gates","aaa"););
    CHECK_NOTHROW(MicroSoft.add_sub("Bill Gates","bbb"););
    CHECK_NOTHROW(MicroSoft.add_sub("Bill Gates","ccc"););
    CHECK_NOTHROW(MicroSoft.add_sub("aaa","ddd"););
    CHECK_NOTHROW(MicroSoft.add_sub("aaa","eee"););
    CHECK_NOTHROW(MicroSoft.add_sub("ccc","fff"););

    size_t counter = 0;
    for(auto i=MicroSoft.begin_reverse_order(); i != MicroSoft.reverse_order() && counter < check.size(); ++i){
        CHECK_EQ(check[counter++] , i->curr->getData());
    }
};
