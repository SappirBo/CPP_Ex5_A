#include <iostream>
#include <string>
#include <vector>

using namespace std;


/**
 * @brief 
 * 
 * @tparam T 
 */
template<typename T>
class Node{
    private:
    T n_data;
    vector<Node<T> *> n_sons;
    public:
    /**
     * @brief Construct a new Node object
     *  Two Constructors, one with no argument, onther with argument.
     */
    Node(){ this->data = NULL;}
    Node(T data){ this->n_data = data;}
    ~Node(){}

    T getData(){ return this->n_data;}
    void setData(T data){this->n_data = data;}
    void addSon(Node *pSon){
        this->n_sons.push_back(pSon);
    }
    
    vector<Node<T> *> getSons(){ return this->n_sons;}

    friend ostream& operator<<(ostream& os, Node& N){
        auto data = N.getData();
        os << data;
        return os;
    }  
};
