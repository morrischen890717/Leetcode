class Solution {
public:
    int find_root(vector<int>& parent, int id){
        if(parent[id] == id)
            return id;
        parent[id] = find_root(parent, parent[id]);
        return parent[id];
    }

    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
        /*
        using Union-Find
        reference: https://leetcode.com/problems/remove-max-number-of-edges-to-keep-graph-fully-traversable/solutions/3468004/python-java-c-simple-solution-easy-to-understand/
        */
        vector<int> alice_parent(n + 1);
        vector<int> bob_parent(n + 1);
        int alice_edge = 0, bob_edge = 0;
        int redundant = 0;
        for(int i = 0; i <= n; i++){ // every node construct a group which only contains itself
            alice_parent[i] = i;
        }
        for(auto& edge: edges){
            if(edge[0] == 3){   // type 3
                int node1 = edge[1], node2 = edge[2];
                int alice_root1 = find_root(alice_parent, node1);
                int alice_root2 = find_root(alice_parent, node2);
                if(alice_root1 != alice_root2){
                    alice_parent[alice_root2] = alice_root1;
                    alice_edge++;
                }
                else{
                    redundant++;
                }
            }
        }
        /*
        bacause type 3 edge can be traversed by both Alice and Bob, so we can 
        simply assign alice_parent and alice_edge to bob_parent and bob_edge 
        respectively now(after tackling type 3 and before dealing with type 1 and type 2)
        */
        bob_parent = alice_parent;
        bob_edge = alice_edge;

        for(auto& edge: edges){
            if(edge[0] == 1){   // type 1
                int node1 = edge[1], node2 = edge[2];
                int alice_root1 = find_root(alice_parent, node1);
                int alice_root2 = find_root(alice_parent, node2);
                if(alice_root1 != alice_root2){ // union them together
                    alice_parent[alice_root2] = alice_root1;
                    alice_edge++;
                }
                else{
                    /*
                    node1 and node2 are already in the same group, so this edge is redundant
                    */
                    redundant++;
                }
            }
        }

        for(auto& edge: edges){
            if(edge[0] == 2){   // type 2
                int node1 = edge[1], node2 = edge[2];
                int bob_root1 = find_root(bob_parent, node1);
                int bob_root2 = find_root(bob_parent, node2);
                if(bob_root1 != bob_root2){
                    bob_parent[bob_root2] = bob_root1;
                    bob_edge++;
                }
                else{
                    redundant++;
                }
            }
        }
        return (alice_edge == n - 1 && bob_edge == n - 1 ? redundant : -1);
    }
};