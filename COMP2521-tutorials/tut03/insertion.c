
// Struct definition:
struct treeNode {
    int value;
    struct treeNode *left;
    struct treeNode *right;
}; 
typedef struct treeNode TreeNode;

TreeNode *insert(TreeNode *root, int value) {
    if (root == NULL) return newNode(value);

    if (value < root -> value) {
        // Insertion point exists somewhere in the left subtree
        root -> left = insert(root -> left, value);    
    } else if (value > root -> value) {
        // Insertion point exists somewhere in the right subtree
        root -> right = insert(root -> right, value);  
    } 
    return root;
}
