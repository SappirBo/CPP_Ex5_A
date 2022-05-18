#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;


class Node{
    private:
    string n_data;
    Node * pFather;
    vector<Node *> n_childrens; // This Vector contains Pointers to all the childrens
    size_t size;

    public:
    using valuetype = string;

    public:
    /**
     * @brief Construct a new Node object
     *       1. defult Constructor.
     *       2. argument Constructor - data (type string)
     */
    Node(){
        this->pFather = NULL;
        this->size = 1;
        }
    Node(string data){
        this->pFather = NULL;
        this->n_data = data;
        this->size = 1;
    }
    ~Node(){}
    /**
     * @brief Get the Data object
     * @return T - The data stored in the Node (Type T).
     */
    string getData(){ return this->n_data;}
    /**
     * @brief Set the Data object
     * @param data 
     */
    void setData(string data){this->n_data = data;}
    /**
     * @brief Get the Size Of the Tree Starting from this Node.
     * @return size_t  - size;
     */
    size_t getSize(){
        return this->size;
    }
    /**
     * @brief Add children to the Node, the children father (A.K.A pFather) set to be this Node.
     * @param pchild - (type Node<T>) Children Node adding to this vector array (By reffrence); 
     */
    void addSon(Node *pchild){
        pchild->setFather(this);
        this->n_childrens.push_back(pchild);
        Node *ptr = this;
        while(ptr != NULL){
            ptr->size += 1;
            ptr = ptr->pFather;
        }
    }
    /**
     * @brief Get the Father object
     * @return Node* - pointer to the father.
     */
    Node *getFather(){
        return this->pFather;
    }
    /**
     * @brief Set the Father object
     * @param pNode - Pointer to the father
     */
    void setFather(Node *pNode){
        this->pFather = pNode;
    }
    /**
     * @brief  Get  pointer to the node contains that data. 
     * @param data - The data we want to receive --> if the data doesn't exist, Return NULL.
     * @return Node<T>*  - Pointer to Node;
     */
    Node *get(string data){
        Node * ans = NULL;
        Node * ptr = this;
        queue< Node* > node_q;
        node_q.emplace(ptr);
        while(!node_q.empty()){
            ptr = node_q.front();
            node_q.pop();
            if(ptr->getData() == data){
                ans = ptr;
                break;
            }
            vector<Node *> tmp = ptr->getSons();
            for(size_t i=0; i<tmp.size(); i++){
                node_q.emplace(tmp[i]);
            }
        }
        return ans;
    }
    /**
     * @brief Checks if there is a Node in the Tree that contains this data.
     * 
     * @param data - The data we look for.
     * @return true - there is a node in this sub tree that contains this data (Get it with the get(T data)).
     * @return false - there is no node in this Sub-Tree that contains this data.
     */
    bool contains(string data){
        Node *ptr = this->get(data);
        if(ptr == NULL){
            return false;
        }
        return true;
    }
    /**
     * @brief This Function returns the level of this node. 
     *          Root level equals 0, his childrens are 1 and move on.
     * @return int  - the level number.
     */
    int level(){
        int count = 0;
        Node *ptr = (this);
        while(ptr->pFather != NULL){
            ptr = ptr->pFather;
            count++;
        }
        return count;
    }

    vector<Node *> getSons(){return this->n_childrens;}
    
    string to_string(){
        queue<Node *> node_q;
        string str = "| ";
        Node *ptr = this;
        node_q.emplace(ptr);
        while(! node_q.empty()){
            ptr = node_q.front();
            node_q.pop();
            vector<Node *> tmp = ptr->getSons();
            for(size_t i=0; i<tmp.size(); i++){
                node_q.emplace(tmp[i]);
            }
            str += ptr->getData();
            str += " | ";
        }
        return str;
    }

    friend ostream& operator<<(ostream& os, Node& N){
        auto data = N.getData();
        os << data;
        return os;
    }


};