#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include "Node.hpp"

namespace ariel{

    class OrgChart
    {
        class level_iterator{
            public:
                size_t it_Size;
                level_iterator();
                size_t size();
                friend bool operator!=(const level_iterator& it1,const level_iterator& it){return false;}
                bool operator==(level_iterator& it);
                level_iterator operator++(){return *this;}
                level_iterator* operator->(){return this;}
                level_iterator operator*(){return *this;};
        };
        class pre_iterator{
            public:
                size_t it_Size;
                pre_iterator();
                size_t size();
                friend bool operator!=(const pre_iterator& it1,const pre_iterator& it);
                bool operator==(pre_iterator& it);
                pre_iterator operator++();
                pre_iterator* operator->();
                pre_iterator operator*();
                friend std::ostream& operator<<(std::ostream &o,const pre_iterator &chart);
        };
        class reverse_iterator{
            public:
                size_t it_Size;
                reverse_iterator();
                size_t size();
                friend bool operator!=(const reverse_iterator& it1,const reverse_iterator& it);
                bool operator==(reverse_iterator& it);
                reverse_iterator operator++();
                reverse_iterator* operator->();
                reverse_iterator operator*();
                friend std::ostream& operator<<(std::ostream &o,const reverse_iterator &chart);
        };

        private:
        /**
         * root is the root node of the tree represnting the organization.
         */
        Node<string> *root;
        
        public:
        // Constructor / Deconstructor
        OrgChart();
        ~OrgChart();
    
        OrgChart& add_root(const string& str);
        OrgChart& add_sub(string manager,string employee);

        Node<string> *getRoot() const;

        level_iterator begin(){return OrgChart::level_iterator();}
        level_iterator end(){return OrgChart::level_iterator();}
        level_iterator begin_level_order(){return OrgChart::level_iterator();}
        level_iterator end_level_order(){return OrgChart::level_iterator();}
        reverse_iterator begin_reverse_order();
        reverse_iterator reverse_order();
        pre_iterator begin_preorder();
        pre_iterator end_preorder();

        string to_string();

        friend ostream& operator<<(std::ostream &o, OrgChart &chart);
        friend ostream& operator<<(std::ostream &o,const level_iterator &chart);
    
    };
};