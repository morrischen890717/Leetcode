class Solution {
public:
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        int d = 0;
        int n = edges.size();
        vector<bool> visited1(n, false), visited2(n, false);
        bool finish1 = false, finish2 = false;
        while(!finish1 || !finish2){
            visited1[node1] = visited2[node2] = true;
            if(visited1[node2] && visited2[node1])
                return min(node1, node2);
            else if(visited1[node2])
                return node2;
            else if(visited2[node1])
                return node1;
            if(edges[node1] != -1 && !visited1[edges[node1]])
                node1 = edges[node1];
            else
                finish1 = true;
            if(edges[node2] != -1 && !visited2[edges[node2]])
                node2 = edges[node2];
            else
                finish2 = true;
            d++;
        }
        return -1;
        
    }
};