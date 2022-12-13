#include "bt.hpp"
#include <queue>
#include <stack>

void    print(BTs<int> tree)
{
    std::queue<BT<int>*> qu;
    BT<int> *a;
    qu.push(tree._root);
    while (!qu.empty())
    {
        a = qu.front();
        std::cout<<qu.front()->val<<std::endl;
        if (a->left)
        qu.push(a->left);
        if (a->right)
        qu.push(a->right);
        qu.pop();
    }
}
void    preorder(BTs<int> tree)
{
    std::stack<BT<int>*> st;
    BT<int> *a;
    st.push(tree._root);
    while(!st.empty())
    {
        a = st.top();
        st.pop();
        if (a->left)
            st.push(a->left);
        if (a->right)
            st.push(a->right);
        std::cout<<a->val<<std::endl;
    }   
}


void    inorder(BT<int> *r)
{
	BT<int>* temp = r;
    std::stack<BT<int>*> st;
    while (temp != NULL || !st.empty()) {
        if (temp != NULL) {
            st.push(temp);
            temp = temp->left;
        }
        else {
            temp = st.top();
            st.pop();
            std::cout << temp->val << " ";
            temp = temp->right;
        }
    }
}

int main()
{
    BTs<int> tree;

    tree.insert(7);
    tree.insert(2);
    tree.insert(9);
    tree.insert(8);
    tree.insert(1);
    tree.insert(12);
    tree.insert(-8);
    tree.insert(4);
    tree.insert(41);
    tree.insert(-41);
    print(tree);
    std::cout <<"----------------"<<std::endl;
    // preorder(tree);
    std::cout <<"----------------"<<std::endl;
    std::cout <<"----------------"<<std::endl;
    std::cout<<tree.search(8)->val<<std::endl;
    std::cout <<"----------------"<<std::endl;
    // tree.deletez(-41);
    // tree.deletez(7);
	inorder(tree._root);
    // print(tree);
}