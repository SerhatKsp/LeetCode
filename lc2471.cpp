#include <iostream>
#include <queue>

struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    int minimumOperations(TreeNode* root) {
        //approach: level-order traverse
        //-> BFS: use queue to store nodes for BFS traversal
        std::queue<TreeNode*> queue;
        queue.push(root);
        int totalSwaps = 0;

        //BFS
        while(!queue.empty()){
            int levelSize = queue.size();
            std::vector<int> levelVals(levelSize);

            for(int i = 0; i < levelSize; ++i){
                TreeNode* node = queue.front();
                queue.pop();
                levelVals[i] = node->val; //store current level node->val

                //add children to queue
                if(node->left != nullptr) queue.push(node->left);
                if(node->right != nullptr) queue.push(node->right);
            }
            //add min swaps for current level
            totalSwaps += getMinSwaps(levelVals);
        }
        return totalSwaps;
    }

private:
    int getMinSwaps(std::vector<int>& original){
        int swaps = 0;
        std::vector<int> target = original;
        std::sort(target.begin(), target.end());

        std::unordered_map<int,int> pos;
        for(int i = 0; i < original.size(); ++i){
            pos[original[i]] = i;
        }
        
        for(int i = 0; i < original.size(); ++i){
            if(original[i] != target[i]){
                ++swaps;

                int currpos = pos[target[i]];
                pos[original[i]] = currpos;
                std::swap(original[currpos], original[i]);
            }
        }
        return swaps;
    }
};