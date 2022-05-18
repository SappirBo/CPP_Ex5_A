#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <Node.hpp>
#include "OrgChart.hpp"

using namespace std;

using namespace ariel;

OrgChart::OrgChart(){
    this->root = NULL;
}

OrgChart::~OrgChart(){}

OrgChart& OrgChart::add_root(const string& str){
    // Node<string> root(str);
    // this->root = &root;
    return *this;
}

OrgChart& OrgChart::add_sub(string manager,string employee){
    // if(! this->root->contains(manager)){
    //     string str = "The name" + manager + " doesn't exist!";
    //     throw invalid_argument(str);
    // }
    // Node<string> *ptr = this->root->get(manager);
    // Node<string> emp(employee);
    // ptr->addSon( &emp);
    return *this;
}

Node<string> *OrgChart::getRoot() const{
    return this->root;
}

string OrgChart::to_string(){
    Node<string> *ptr = this->root;
    string str = ptr->to_string();
    return str;
}

ostream& ariel::operator<<(ostream &o, OrgChart &chart){
    o << "";
    // o << chart.to_string();
    return o;
}


//----Implementing Level Order Iterator----//

OrgChart::level_iterator::level_iterator(){}

bool ariel::OrgChart::level_iterator::operator==(level_iterator& it){
    return true;
}
ostream& ariel::operator<<(ostream &o,const OrgChart::level_iterator &chart){
    return o;
}
