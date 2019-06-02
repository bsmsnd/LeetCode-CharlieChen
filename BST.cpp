class BST{
    struct node
    {
        int value;
        node* left;
        node* right;
    };

    node* root;
    node* reset(node* t)
    {
        if (t == nullptr)
            return nullptr;
        reset(t->left);
        reset(t->right);
        delete t;
        return nullptr;
    };


    BST()
    {
        root = nullptr;
    }

    node* insert(int newValue, node* t)
    {
        if (t == nullptr)
        {
            t = new node;
            t->value = newValue;
            t->left = t->right = nullptr;
        }
        else if (newValue > t->value)
            t->right = insert(newValue, t->right);
        else if (newValue < t->value)
            t-> left = insert(newValue, t->left);        
        return t;
    };

    node* findMin(node* t)
    {
        if (t->left == nullptr)
            return t;
        else
            return findMin(t->left);
    }
    
    node* findMax(node* t)
    {
        if (t->right == nullptr)
            return t;
        else
            return findMin(t->right);
    }

    node* find(int x, node* t)
    {
        if (t == nullptr)
            return nullptr;
        if (x == t->value)
            return t;
        if (x > t->value)
            return find(x, t->right);
        if (x < t->value)
            return find(x, t->left);
    }

    node* remove(int x, node* t)
    {
        if (t == nullptr)
            return nullptr;
        node* tmp;
        if (x < t->value)
            return remove(x, t->left);
        else if (x > t->value)
            return remove(x, t->right);
        else  // x == t->value
        {
            if (t->left != nullptr && t->right != nullptr)
            {
                tmp = findMin(t->right);
                t->value = tmp->value;
                t->right = remove(t->value, t->right);
            }
            else
            {
                tmp = t;
                if (t->left == nullptr)
                    t = t->right;
                else if (t->right == nullptr)
                    t = t->left;
                delete tmp;
                
            }
            return t;
        }   
        
    }
};