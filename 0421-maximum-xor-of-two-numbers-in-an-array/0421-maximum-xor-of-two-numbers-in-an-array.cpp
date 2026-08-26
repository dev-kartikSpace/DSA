class Solution {
public:
    struct trieNode {
        trieNode* children[2];
    };

    trieNode*
    createNode() {
        trieNode* newNode = new trieNode();
        newNode->children[0] = NULL;
        newNode->children[1] = NULL;

        return newNode;
    }

    trieNode* root;

    void insert(int& num) {
        trieNode* crawl = root;
        for (int i = 31; i >= 0; i--) {
            int bit = (num >> i) & 1;
            if (crawl->children[bit] == NULL) {
                crawl->children[bit] = createNode();
            }
            crawl = crawl->children[bit];
        }
    }

    int findMaximumXOR(vector<int>& nums) {
        root = createNode();
        int ans = 0;

        for (int i = 0; i < nums.size(); i++) {
            insert(nums[i]);
        }

        for(auto val : nums){
            ans = max(ans, findMax(val));
        }

        return ans;
    }
    int findMax(int n){
        int currAns = 0;
        trieNode* crawl = root;
        for(int i = 31; i>=0; i--){
            int bit = (n >> i) & 1;
            int opp = 1 - bit;
            if(crawl->children[opp]){
                currAns |= (1<<i); 
                crawl = crawl->children[opp];
            }
            else crawl = crawl->children[bit];
        }
        return currAns;
    }
};