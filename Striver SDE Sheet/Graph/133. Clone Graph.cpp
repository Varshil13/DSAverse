/* We had to create a deep copy of a graph, we did simple dfs and used a map to keep 
a track of the cloned nodes, if the neighbor is already cloned previously then we just
 simply add the cloned node address to the neighbor array of the current node*/

class Solution {
public:
unordered_map <Node*,Node*> m;

void DFS(Node* node, Node* clone_node){
    for(Node* n : node->neighbors){
        if(m.find(n) == m.end()){
            Node* clone = new Node(n->val);
            m[n] = clone;
            clone_node->neighbors.push_back(clone);
            DFS(n,clone);
        }
        else{
            clone_node->neighbors.push_back(m[n]);

        }

    }

}

    Node* cloneGraph(Node* node) {

        if(node == nullptr){
            return nullptr;
        }
        m.clear();
        // clone the given node
        Node * clone_node = new Node(node->val);

        //now its neighbours and recursively its neighbours 
        //if a node reapperars , then we need to access that cloned node , so we can use map<Node*,Node*>
          m[node] = clone_node;
          DFS(node,clone_node);

        return clone_node;
    }
};



