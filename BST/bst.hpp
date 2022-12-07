#include <iostream>
#include <memory>

template <class T>
class Node{
public:
    T data;
    Node* left;
    Node* right;
    Node(T d):data(d), left(nullptr), right(nullptr){}
};



