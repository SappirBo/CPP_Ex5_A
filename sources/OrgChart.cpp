#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <Node.hpp>
#include "OrgChart.hpp"

using namespace std;

using namespace ariel;

OrgChart::OrgChart(){}

OrgChart::~OrgChart(){}

OrgChart& OrgChart::add_root(const string& str){
    // string s = str;
    // Node tmp(s);
    // this->root = &tmp;
    return *this;
}

OrgChart& OrgChart::add_sub(string manager,string employee){
    // if(! this->root->contains(manager)){
    //     string str = "The name" + manager + " doesn't exist!";
    //     throw invalid_argument(str);
    // }
    // cout << "add_sub 1\n";
    // Node *ptr = this->root->get(manager);
    // cout << "add_sub 2 , menager = "<< *ptr<< endl;
    // Node emp(employee);
    // ptr->addSon( &emp);
    return *this;
}

Node *OrgChart::getRoot() const{
    return this->root;
}

// string OrgChart::to_string(){
//     Node  *ptr = this->root;
//     string str = ptr->to_string();
//     return str;
// }

ostream& ariel::operator<<(ostream &o, OrgChart &chart){
    // Node ptr = (Node *) (chart.getRoot());
    // o << ptr ;
    // o << chart.to_string();
    return o;
}


//----Implementing Level Order Iterator----//

// OrgChart::level_iterator::level_iterator(){}

// bool ariel::OrgChart::level_iterator::operator==(level_iterator& it){
//     return true;
// }

// ostream& ariel::operator<<(ostream &o,const OrgChart::iterator &chart){
//     // o<<"HEllo Broooo";
//     return o;
// }
