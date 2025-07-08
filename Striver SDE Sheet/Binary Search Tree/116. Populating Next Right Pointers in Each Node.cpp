

class Solution {
public:
    Node* connect(Node* root) {
        if (!root) return nullptr; 
        queue<Node*> q;


        q.push(root);
        root->next = nullptr;
        while (!q.empty()) {

            int s = q.size();
            for (int i= 0; i < s - 1; i++) {
                Node* x = q.front();
                q.pop();
                x->next = q.front();
                if (x->left != nullptr) {
                    q.push(x->left);
                }
                if (x->right != nullptr) {
                    q.push(x->right);
                }
            }
                Node* t = q.front();
                q.pop();
                t->next = nullptr;
                if (t->left != nullptr) {
                    q.push(t->left);
                }
                if (t->right != nullptr) {
                    q.push(t->right);
                }
            }
            
        
        return root;
    }
    };



    // recurssive approach 


    class Solution {
public:
    Node* connect(Node* root) {
        if (!root || !root->left) return root;

        root->left->next = root->right;

        if (root->next) {
            root->right->next = root->next->left;
        }

        connect(root->left);
        connect(root->right);

        return root;
    }
};
