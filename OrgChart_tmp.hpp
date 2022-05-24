#include <iostream>
#include <string>
#include <string>
#include <Node.hpp>

namespace ariel{
    class OrgChart
    {
        private:
        /**
         *  Some kind of data structure here.
         */

        public:
        // Constructor / Deconstructor
        OrgChart();
        ~OrgChart();

        OrgChart add_root(string str);
        OrgChart add_sub(string manager,string employee);


        string* begin_level_order();
        string* end_level_order();
        string* begin_reverse_order();
        string* reverse_order();
        string* begin_preorder();
        string* end_preorder();


        friend std::ostream& operator<<(std::ostream &o,const OrgChart &chart);

    };
};
