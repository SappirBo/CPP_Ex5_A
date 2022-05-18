#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include "Node.hpp"

namespace ariel{

    class OrgChart
    {
        class iterator{
            public:
                Node *curr;
                size_t it_Size;

                iterator(){}
                size_t size(){return 0;}
                friend bool operator!=(const iterator& it1,const iterator& it2){return false;}
                bool operator==(iterator& it){return false;}
                iterator operator++(){return *this;}
                iterator* operator->(){return this;}
                iterator operator*(){return *this;}
                friend std::ostream& operator<<(std::ostream &o,const iterator &chart){return o;}
        };

        private:
        /**
         * root is the root node of the tree represnting the organization.
         */
        Node *root;
        
        public:
        // Constructor / Deconstructor
        OrgChart();
        ~OrgChart();
    
        OrgChart& add_root(const string& str);
        OrgChart& add_sub(string manager,string employee);

        Node *getRoot() const;

        iterator begin(){return OrgChart::iterator();}
        iterator end(){return OrgChart::iterator();}
        iterator begin_level_order(){return OrgChart::iterator();}
        iterator end_level_order(){return OrgChart::iterator();}
        iterator begin_reverse_order(){return OrgChart::iterator();}
        iterator reverse_order(){return OrgChart::iterator();}
        iterator begin_preorder(){return OrgChart::iterator();}
        iterator end_preorder(){return OrgChart::iterator();}

        string to_string();

        friend ostream& operator<<(std::ostream &o, OrgChart &chart);
        friend ostream& operator<<(std::ostream &o,const iterator &chart);
    
    };
};