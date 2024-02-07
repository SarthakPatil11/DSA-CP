#include<iostream>
#include<queue>
#include<deque>
#include<stack>
#include<map>

using namespace std;

class node{
    public:
        int data;
        node *left;
        node *right;

    node() {
        this->data = 0;
        this->left = nullptr;
        this->right = nullptr;
    }

    node(int d) {
        this->data = d;
        this->left = nullptr;
        this->right = nullptr;
    }
};

node* build_tree(node *root) {
    cout<<"Enter data: ";
    int data;
    cin>>data;

    if (data == -1)
        return nullptr;
    
    root = new node(data);

    cout<<"Enter left of "<<data<<endl;
    root->left = build_tree(root->left);

    cout<<"Enter right of "<<data<<endl;
    root->right = build_tree(root->right);

    return root;
}

node * bulid_Levelraversal_Tree (node * root) {
    queue<node *> q;
    cout<<"Enter root's data: "<<endl;
    int data;
    cin>>data;
    root = new node(data);
    q.push(root);

    while (!q.empty())
    {
        node *temp = q.front();
        q.pop();

        cout<<"Enter left of "<<temp->data<<endl;
        int left;
        cin>>left;

        if (left != -1) {
            temp->left = new node(left);
            q.push(temp->left);
        }

        cout<<"Enter right of "<<temp->data<<endl;
        int right;
        cin>>right;

        if (right != -1) {
            temp->right = new node(right);
            q.push(temp->right);
        }
    }
    return root;
}

int get_index(int arr[], int st, int end, int el) {
    for (int i = st; i <= end; i++)
        if (arr[i] == el) 
            return i;
    return -1;
}

node *build_tree_PeI(int pre[], int in[], int size, int &i, int in_st, int in_end) {
    if(i > size || in_st > in_end) {
        return nullptr;
    }

    int cur = pre[i];
    i++;
    int pos = get_index(in, in_st, in_end, cur);

    node * root = new node(cur);
    root->left = build_tree_PeI(pre, in, size, i, in_st, pos-1);
    root->right = build_tree_PeI(pre, in, size, i, pos+1, in_end);

    return root;
}

node *build_tree_PoI(int post[], int in[], int &i, int in_st, int in_end) {
    if(i < 0 || in_st > in_end) {
        return nullptr;
    }

    int cur = post[i];
    i--;
    int pos = get_index(in, in_st, in_end, cur);

    node * root = new node(cur);
    root->right = build_tree_PoI(post, in, i, pos+1, in_end);
    root->left = build_tree_PoI(post, in, i, in_st, pos-1);

    return root;
}

// node *build_tree_LvI(int level[], int in[], int size, int &i, int in_st, int in_end) {
//     if(i > size || in_st > in_end) {
//         return nullptr;
//     }

//     int curr = level[i];
//     i++;
//     int pos = get_index(in, in_st, in_end, curr);
    
//     node *root = new node(curr);
//     root->left = build_tree_LvI(level, in, size, i, in_st, pos-1);
//     root->right = build_tree_LvI(level, in, size, i, pos+1, in_end);

//     return root;
// }

node* build_from_In(int arr[], int in[], int size, bool which) {
    int i = 0;
    //we can reduse the complexity of get_index by PRE-COMPUTING using MAP.
    //call here get_index only once and create map<int, int> element and index.

    if (which)
        return build_tree_PeI(arr, in, size, i, 0, size-1);
    else {
        i = size-1;
        return build_tree_PoI(arr, in, i, 0, i);
    }
}

void levelOrdertraversal(node * root) {
    queue<node*> q;
    q.push(root);
    q.push(nullptr);
        
    while (!q.empty()) {
        node * temp = q.front();
        q.pop();

        if (temp == nullptr) {
            cout<<endl;
            if (!q.empty())
                q.push(nullptr);
        }
        else {
            cout<<temp->data<<" ";
            if (temp->left)
                q.push(temp->left);
            
            if (temp->right)
                q.push(temp->right);
        }
    }
    
}

void inorder(node *root) {
    if (root != nullptr) {
        if (root->left)
            inorder(root->left);
        cout<<root->data<<" ";
        if (root->right)
            inorder(root->right);
    }
}

void preorder(node *root) {
    if (root != nullptr) {
        cout<<root->data<<" ";
        if (root->left)
            preorder(root->left);
        if (root->right)
            preorder(root->right);
    }
}

void postorder(node *root) {
    if (root != nullptr) {
        if (root->left)
            postorder(root->left);
        if (root->right)
            postorder(root->right);
        cout<<root->data<<" ";
    }
}

int ct = 0;
int noOfleafNodes(node * root) {
    if (root != nullptr)
    {
        if (root->left)
            noOfleafNodes(root->left);
        if (root->right)
            noOfleafNodes(root->right);

        if (!root->left && !root->right)
            ct++;
    }
   return ct; 
}

void inorderLoop(node * root) {
    stack<node *> s;
    s.push(root);

    while (!s.empty())
    {
        node *temp = s.top();
        s.pop();

        if (temp->left)
        {
            s.push(temp->left);
            continue;
        }
        cout<<temp->data<<endl;
        if (temp->right)
        {
            s.push(temp->right);
        }
    }
}

int sum_of_kth_level(node* root, int k) {
    if (k == 0) return root->data;

    queue<node *> q;
    q.push(root);
    q.push(nullptr);

    int ct = 0, sum = 0;
    while (!q.empty())
    {
        node * temp = q.front();
        q.pop();

        if (temp == nullptr)
        {
            ct++;
            if (ct > k)
                return sum;
            if (!q.empty())
                q.push(nullptr);
        }
        else {
            if (ct == k)
                sum += temp->data;
            
            if (temp->left)
                q.push(temp->left);
            if (temp->right)
                q.push(temp->right);
        }
    }
    return -1;
}

void calculate_S_C(node * root, int &s, int &c) {
    if (root)
    {
        c++;
        s += root->data;

        calculate_S_C(root->right, s, c);      
        calculate_S_C(root->left, s, c);
    }
}

void sum_cont_nodes(node *root) {
    int sum = 0, count = 0;
    calculate_S_C(root, sum, count);
    cout<<"Sum: "<<sum<<" Count: "<<count<<endl;
}

//Hight and Diameter of tree
int hight_of_tree(node * root) {
    if (root)
    {
        int lh = 0, rh = 0;
        if (root->left)
            lh = hight_of_tree(root->left);
        if (root->right)
            rh = hight_of_tree(root->right);

        return max(lh, rh) + 1;
    }
    return 0;
}

int diameter (node *root) {
    if (!root) return 0;
    
    static int maxd = 0;
    int lh = hight_of_tree(root->left);      //left hight of current node.
    int rh = hight_of_tree(root->right);     //right hight of current node.
 
    maxd = max(maxd, lh+rh);

    diameter(root->left);
    diameter(root->right);

    return maxd;
}

//Hight and Diameter of tree (OPTIMIZED)
int treeH(node *root, int &diameter) {
    int lh = 0, rh = 0;
    if (root->left)
        lh = treeH(root->left, diameter);
    if (root->right)
        rh = treeH(root->right, diameter);
        
    diameter = max(diameter, lh+rh);

    return max(lh, rh) + 1;
}

int treeD (node *root) {
    if (root) {
        static int di = 0;
        treeH(root, di);
        return di;
    }
    return -1;
}

//Sum replacement of tree (Sum of sub-tree is contained by root of that perticular sub-tree)
int sum_replace(node *root) {
    if (root == nullptr) return 0;
    int l = 0, r = 0;
    l = sum_replace(root->left);
    r = sum_replace(root->right);
    root->data += (l + r);
    return root->data;
}

int cal_hight_T(node *root) {
    if (!root) return 0;
    int lh, rh;
    if (root->left)
        lh = cal_hight_T(root->left);
    if (root->right)
        rh = cal_hight_T(root->right);

    return max(lh, rh) + 1;
}

bool isBalanced(node *root) {
    if (!root) return true;
    if (root->left)
        if (isBalanced(root->left) == false) return false;
    if (root->right)
        if (!isBalanced(root->right)) return false;

    int lh = 0, rh = 0;
    if (root->left)
        lh = cal_hight_T(root->left);
    if (root->right)
        rh = cal_hight_T(root->right);

    if (abs(lh - rh) > 1) return false;
    else return true;
}

bool isBalanced_opti(node *root, int *hight) {
    if (!root) return true;
    int lh = 0, rh = 0;         //when it travers left then the *hight points to lh and when travers right then rh.
    if (root->left)
        if (isBalanced_opti(root->left, &lh) == false) return false;
    if (root->right)
        if (!isBalanced_opti(root->right, &rh)) return false;

    *hight = max(lh, rh) + 1;   //it updates the previous stack frame's hight which can be lh/rh depends on who calls call.

    if (abs(lh - rh) > 1) return false;
    else return true;
}

void rightView(node *root) {
    if (!root) return;

    queue<node*> q;
    q.push(root);
    cout<<root->data<<' ';
    q.push(nullptr);

    while (!q.empty())
    {
        node *temp = q.front();
        q.pop();

        if (temp == nullptr) {
            if (!q.empty()) {
                cout<<q.back()->data<<' ';  //checks in the lavel which is after null (next level).
                q.push(nullptr);
            }
        }
        else {
            if (temp->left)
                q.push(temp->left);
            if (temp->right)
                q.push(temp->right);
        }
    }
    cout<<endl;
}

void leftView(node *root) {
    if (!root) return;

    queue<node*> q;
    q.push(root);
    cout<<root->data<<' ';
    q.push(nullptr);

    while (!q.empty())
    {
        node *temp = q.front();
        q.pop();

        if (temp == nullptr) {
            if (!q.empty()) {
                cout<<q.front()->data<<' ';  //checks in the lavel which is after null (next level).
                q.push(nullptr);
            }
        }
        else {
            if (temp->left)
                q.push(temp->left);
            if (temp->right)
                q.push(temp->right);
        }
    }
    cout<<endl;
}

void topView(node *root) {
    if (!root) return;

    queue<node*> q;
    deque<int> dq;
    q.push(root);
    dq.push_back(root->data);
    // cout<<root->data<<' ';
    q.push(nullptr);

    while (!q.empty())
    {
        node *temp = q.front();
        q.pop();

        if (temp == nullptr) {
            if (!q.empty()) {
                // cout<<q.front()->data<<' ';  //checks in the lavel which is after null (next level).
                dq.push_front(q.front()->data);
                dq.push_back(q.back()->data);
                q.push(nullptr);
            }
        }
        else {
            if (temp->left)
                q.push(temp->left);
            if (temp->right)
                q.push(temp->right);
        }
    }

    while (!dq.empty())
    {
        cout<<dq.front()<<' ';
        dq.pop_front();
    }
    cout<<endl;
}

bool getPath(node* root, int key, vector<int> &v) {
    if (!root) return false;
    
    v.push_back(root->data);
    if (root->data == key)
        return true;
    
    if (getPath(root->left, key, v) || getPath(root->right, key, v))
        return true;

    v.pop_back();
    return false;
}

int lowes_common_ancestor(node *root, int n1, int n2) {
    if (!root) return -1;
    vector<int> path_n1, path_n2;
    if (getPath(root, n1, path_n1) && getPath(root, n2, path_n2)) {
        int size = 0;
        if (path_n1.size() < path_n2.size())
            size = path_n1.size();
        else 
            size = path_n2.size();
        for (int i = 0; i < size; i++) {
            if (path_n1[i] != path_n2[i])
                return path_n1[i-1];
        }
    }
    return -1;
}

bool get_path2(node *root, int key, vector<int> &v) {
    if(!root) return false;

    v.push_back(root->data);
    if (root->data == key) 
        return true;
    if (get_path2(root->left, key, v) || get_path2(root->right, key, v))
        return true;
    
    v.pop_back();
    return false;
}

int smallest_path(node *root, int n1, int n2) {
    if (!root) return false;
    vector<int> n1_path, n2_path;

    if (get_path2(root, n1, n1_path) && get_path2(root, n2, n2_path)) {
        deque<int> dq;
        int size_n1 = n1_path.size();
        int size_n2 = n2_path.size();
        int size = n1_path.size();
        int path_count = 0;
        
        if (size_n1 < size_n2)
            size = size_n2;
        
        int i = 0;
        for (i = 0; i < size; i++) {
            if (n1_path[i] != n2_path[i]) {
                dq.push_back(n1_path[i-1]);
                path_count = (size_n1 - i) + (size_n2 - i);
                // cout<<"Count: "<<path_count<<endl;
                break;
            }
        }

        for (int j = size_n1-1; j >= i; j--)
            dq.push_front(n1_path[j]);

        for (int j = i; j < size_n2; j++)
            dq.push_back(n2_path[j]);

        cout<<"Path: ";
        while (!dq.empty()) {
            cout<<dq.front()<<' ';
            dq.pop_front();
        }
        cout<<endl;
        return path_count;
    }
    return false;
}

int main(void)
{
    node *root = nullptr;
    // int pre[] = {0, 1, 3, 4, 2, 5};
    // int in[] = {7, 3, 11, 1, 17, 5};
    // int post[] = {3, 4, 1, 5, 2, 0};
    // int in[] = {3, 1, 4, 0, 5, 2};
    // int post[] = {0, 1, 3, 4, 2, 5};
    // int size = 6;
    // root = build_from_In(pre, in, size, 1);
    // root = build_tree(root);
    //1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
    //1 2 5 7 11 17 -1 -1 -1 -1 -1 -1 -1

    // cout<<"Print level order:"<<endl;
    // levelOrdertraversal(root);

    // cout<<"Inorder:"<<endl;
    // inorder(root);
    // cout<<endl<<"Preorder:"<<endl;
    // preorder(root);
    // cout<<endl<<"Postorder:"<<endl;
    // postorder(root);

    int post[] = {7, 11, 3, 33, 17, 5, 1};
    int  in[] = {7, 3, 11, 1, 33, 17, 5};
    int size = 7;
    int k = 2;
    root = build_from_In(post, in, size, 0);
    cout<<"\nInorder:"<<endl;
    inorder(root);

    // cout<<noOfleafNodes(root)<<endl;

    cout<<"\nLevelorder:"<<endl;
    levelOrdertraversal(root);
    
    // cout<<"Sum of level "<<k<<": "<<sum_of_kth_level(root, k)<<endl;
    // sum_cont_nodes(root);
    // cout<<"Hight of Tree: "<<hight_of_tree(root)<<endl;
    // cout<<"Diameter of Tree: "<<diameter(root)<<endl;
    // cout<<"Diameter of Tree (OPTIMIZED): "<<treeD(root)<<endl;

    // // sum_replace(root);
    // // cout<<"\nLevelorder:"<<endl;
    // // levelOrdertraversal(root);

    // cout<<"Bal: "<<isBalanced(root)<<endl;
    // int h = 0;
    // cout<<"Bal opti: "<<isBalanced_opti(root, &h)<<endl;

    // cout<<"Right View: ";
    // rightView(root);
    // cout<<"Left View: ";
    // leftView(root);
    // cout<<"Top View: ";
    // topView(root);

    cout<<"lowes common ancestor between 7 and 11: "<<lowes_common_ancestor(root, 7, 11)<<endl;

    cout<<"Smallest path & count: "<<smallest_path(root, 7, 11)<<endl;
    return 0;
}