#include <iostream>
#include <memory>


template <class T>
struct BT
{
    BT  *left;
    BT  *wrigth;
    BT  *parent;
    T   val;
    BT(T v): left(nullptr), wrigth(nullptr), parent(nullptr), val(v){}
};






template <class T, class alloc = std::allocator<T> >
class BTs
{
public:
    BTs():_root(nullptr), _size(0) {}
    


private:
    BT  *_root;
    int _size;
};