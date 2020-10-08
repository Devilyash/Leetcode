/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
	void dfs(TreeNode* node, int r, int c, unordered_map<int, vector<pair<int, int>>> &cache, int &minC, int &maxC)
	{
		if(node == NULL) return;
		// if there are nodes present in some column already the simply append other nodes as well
		if(cache.count(c))
		{
			// insert row value and node's value at a specified column
			cache[c].push_back({r, node->val});
		}
		// otherwise make a new entry with column index as the key
		cache.insert({c, {{r, node->val}}});
		minC = min(minC, c);
		maxC = max(maxC, c);
		// for left child column value will be one less
		dfs(node->left, r+1, c-1, cache, minC, maxC);
		// for right child column value will be one more
		dfs(node->right, r+1, c+1, cache, minC, maxC);
	}
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) 
	{
        vector<vector<int>> result;
        if(root == NULL) return result;
        // key = column index and value = vector having nodes in that column
        unordered_map<int, vector<pair<int, int>>> cache;
        // minimum & maximum column index
        int minC = 0, maxC = 0;
        dfs(root, 0, 0, cache, minC, maxC);
        for(int c = minC; c < maxC+1; c++)
        {
        	// if there are multiple entries in one column then we need them sorted
        	sort(cache[c].begin(), cache[c].end(), [](pair<int, int> &p1, pair<int, int> &p2){
        		return (p1.first < p2.first) || ((p1.first == p2.first) && (p1.second < p2.second));
			});
			vector<int> col;
			for(pair<int, int> &p: cache[c])
			{
				col.push_back(p.second);
			}
			result.push_back(col);
		}
		return result;
    }
};
/* Alternate solution using inorder traversal
class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int, map<int, vector<int>>> m;
        inorder(root, 0, 0, m);
        
        vector<vector<int>> ans;
        for(auto& e:m){
            vector<int> cur;
            for(auto& f:e.second){
                sort(begin(f.second), end(f.second));
                cur.insert(end(cur), begin(f.second), end(f.second));
            }
            ans.push_back(cur);
        }
        return ans;
    }
private:
    void inorder(TreeNode* root, int x, int y, map<int, map<int, vector<int>>>& m){
        if(!root) return;
        m[x][y].push_back(root->val);
        inorder(root->left, x-1, y+1, m);
        inorder(root->right,x+1, y+1, m);
    }
};
*/
