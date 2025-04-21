//approach: dfs to leaf nodes and from there on looking for cutting edges
//constraint: sum of values is divisible by k
#include <vector>
#include <iostream>

class Solution{
public: 
    int ans = 0; 

    int maxKDivisibleComponents(int n, std::vector<std::vector<int>> edges, std::vector<int> values, int k){
        int countComponents = 0; 

        //store graph/tree as adjacency list
        std::vector<int> adjList[n]; 
        for(auto& edge : edges){
            adjList[edge[0]].push_back(edge[1]);
            adjList[edge[1]].push_back(edge[0]); //undirected graph
        }

        dfs(-1, 0, adjList, values, k, countComponents); 

        return countComponents; 
    }

private: 
    int dfs(int parentNode, int currentNode, std::vector<int> adjList[], std::vector<int>& values, int k, int& countComponents){
        int sum = 0; //initialize sum of subtree

        for(auto& neighborNode : adjList[currentNode]){ //start recursive from currNode to neighbors(!=parent) (till leaf nodes) and pass the sum
            if(neighborNode != parentNode){
                sum += dfs(currentNode, neighborNode, adjList, values, k, countComponents);
                sum %= k; 
            }
        }

        sum += values[currentNode]; 
        sum %= k;

        if(sum == 0) ++countComponents;

        return sum; 
    }
};

int main(){
    std::vector<int> values = {2,5,3,1,1};
    std::vector<std::vector<int>> edges = {{0,1}, {1,2}, {1,3}, {3,4}};
    int k = 2; 

    Solution solution; 
    solution.ans = solution.maxKDivisibleComponents(values.size(), edges, values, k); 

    std::cout << "maximum by k divisible components: " << solution.ans << std::endl; 
    return 0;
}