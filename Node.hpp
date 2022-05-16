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
    Node * pFather;
    vector<Node<T> *> n_childrens; // This Vector contains Pointers to all the childrens

    public:
    /**
     * @brief Construct a new Node object
     *          1. defult Constructor.
     *          2. argument Constructor - data (type T)
     *          3. argument Constructor - pNode_Father (pointer to the father node) ,data (type T)
     */
    Node(){
        this->pFather = NULL;
        this->data = NULL;
        }
    Node(T data){
        this->pFather = NULL;
        this->n_data = data;
    }
    Node(Node *pNode_Father, T data){
        this->pFather = pNode_Father;
        this->n_data = data;
    }
    ~Node(){}

    T getData(){ return this->n_data;}
    void setData(T data){this->n_data = data;}
    void addSon(Node *pchild){
        this->n_sons.push_back(pchild);
    }
    void addFather(Node *pNode){
        this->pFather = pNode;
    }
    vector<Node<T> *> getSons(){ return this->n_childrens;}

    
    friend ostream& operator<<(ostream& os, Node& N){
        auto data = N.getData();
        os << data;
        return os;
    }  
};