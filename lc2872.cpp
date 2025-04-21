#include <iostream>
#include <vector>

class Solution {
private: 
    int dfs(int currentNode, int parentNode, std::vector<int> adjList[], std::vector<int> &nodeValues, int k, int &componentCount){
        int sum = 0; //initizalize sum for current subtree

        //traverse all neighbors
        for(auto neighborNode : adjList[currentNode]){
            if(neighborNode != parentNode){
                sum += dfs(neighborNode, currentNode, adjList, nodeValues, k, componentCount);
                sum %= k; 
            }
        }
        sum += nodeValues[currentNode]; 
        sum %= k; 

        if(sum == 0) ++componentCount;
        
        return sum; 
        }

public:
    int maxKDivisibleComponents(int n, std::vector<std::vector<int>>& edges, std::vector<int>& values, int k){
        //initialize adjacency list storing all connections
        std::vector<int> adjList[n];
        for(auto& edge : edges){
            adjList[edge[0]].push_back(edge[1]);
            adjList[edge[1]].push_back(edge[0]);
        }
        int componentCount = 0;

        dfs(0, -1, adjList, values, k, componentCount);

        return componentCount; 
    }
};

int main(){
    std::vector<std::vector<int>> edges = {{0,1}, {1,2}, {1,3}, {1,4}};
    std::vector<int> values = {10,10,10,10,10};
    int k = 10; 
    int n = values.size(); 
    Solution solution; 
    int ans = solution.maxKDivisibleComponents(n, edges, values, k);

    std::cout << "maximum amount of divisible components: " << ans << std::endl; 

    return 0;
}