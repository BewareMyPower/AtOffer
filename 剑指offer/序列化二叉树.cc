/*
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
};
*/
class Solution {
public:
    string res;  // 先序遍历的结果，用','分割，'#'记录空指针
    void SerializeImp(TreeNode* root) {
        if (!res.empty())
            res += ",";
        if (root) {
            res += to_string(root->val);
            SerializeImp(root->left);
            SerializeImp(root->right);
        } else {
            res += "#";
        }
    }
    
    char* Serialize(TreeNode *root) {
        res.clear();
        SerializeImp(root);
        return &res[0];
    }
    
    TreeNode* DeserializeImp(char*& str) {
        auto s_end = str + strlen(str);
        auto it = find(str, s_end, ',');
        TreeNode* res;
        if (*str == '#') {
            res = nullptr;
            if (it != s_end)
                str += 2;  // 跳过'#'和','
        }
        else {
            *it = '\0';
            res = new TreeNode(stoi(str));
            if (it != s_end) {
                str = it + 1;
                res->left = DeserializeImp(str);
                res->right = DeserializeImp(str);
            }
        }
        return res;
    }
    
    TreeNode* Deserialize(char *str) {
        return DeserializeImp(str);
    }
};