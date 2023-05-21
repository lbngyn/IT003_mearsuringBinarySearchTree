#ifndef AVL_TREE_AVL_H
#define AVL_TREE_AVL_H

using namespace std;

// An AVL tree node
template <typename T>
class Node
{
private:
    T key;
    Node<T> *left;
    Node<T> *right;
    int height;

public:
    Node(T newKey = -1, Node<T> *l = nullptr, Node<T> *r = nullptr, int h = 1) : key(newKey), left(l), right(r), height(h) {}
    ~Node() { delete this; };
    int getHeight();
    Node *rightRotate();
    Node *leftRotate();
    int getBalance();
    Node *insert(int newKey);
};

template <typename T>
int Node<T>::getHeight()
{
    if (this == nullptr)
        return 0;
    return height;
}

template <typename T>
Node<T> *Node<T>::rightRotate()
{
    Node<T> *x = left;
    Node<T> *T2 = x->right;

    x->right = this;
    left = T2;

    height = max(left->getHeight(), right->getHeight()) + 1;
    x->height = max(x->left->getHeight(), x->right->getHeight()) + 1;

    return x;
}

template <typename T>
Node<T> *Node<T>::leftRotate()
{
    Node *y = right;
    Node *T2 = y->left;

    // Perform rotation
    y->left = this;
    right = T2;

    // Update heights
    height = max(left->getHeight(), right->getHeight()) + 1;
    y->height = max(y->left->getHeight(), y->right->getHeight()) + 1;

    // Return new root
    return y;
}

template <typename T>
int Node<T>::getBalance()
{
    if (this == nullptr)
        return 0;
    return left->getHeight() - right->getHeight();
}

template <typename T>
Node<T> *Node<T>::insert(int newKey)
{
    if (this == nullptr)
    {
        return new Node<T>(newKey);
    }

    if (newKey < key)
        left = left->insert(newKey);
    else if (newKey > key)
        right = right->insert(newKey);
    else
        return this;

    height = 1 + max(left->getHeight(), right->getHeight());

    int balance = getBalance();

    // Left Left Case
    if (balance > 1 && newKey < left->key)
        return rightRotate();

    // Right Right Case
    if (balance < -1 && newKey > right->key)
        return leftRotate();

    // Left Right Case
    if (balance > 1 && newKey > left->key)
    {
        left = left->leftRotate();
        return rightRotate();
    }

    // Right Left Case
    if (balance < -1 && newKey < right->key)
    {
        right = right->rightRotate();
        return leftRotate();
    }

    return this;
}

template <typename T>
T max(T a, T b) { return a > b ? a : b; }

template <typename T>
void preOrder(Node<T> *root)
{
    if (root != nullptr)
    {
        cout << root->key << " ";
        preOrder(root->left);
        preOrder(root->right);
    }
}

#endif // AVL_TREE_AVL_H
