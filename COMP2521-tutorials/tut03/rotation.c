// Left rotation algorithm:
TreeNode *leftRotate(TreeNode *root) {
    if (root == NULL) {
        return NULL;
    } 

    TreeNode *rightChild = root -> right;
    
    if (rightChild != NULL) {
        TreeNode *rightChildLeft = rightChild -> left;
        root -> right = rightChildLeft;
        rightChild -> left = root;
        return rightChild;
    } else {
        // You can't do a left rotation if there's no right child!
        return root;
    }
}

// Right rotation algorithm:
TreeNode *rightRotate(TreeNode *root) {
    if (root == NULL) {
        return NULL;
    } 

    TreeNode *leftChild = root -> left;
    
    if (leftChild != NULL) {
        TreeNode *leftChildRight = leftChild -> right;
        root -> left = leftChildRight;
        leftChild -> right = root;
        return leftChild;
    } else {
        // You can't do a right rotation if there's no left child!
        return root;
    }
}
































/**
 * Executes a left rotation on the node with the given target value.
 * Returns the resultant tree.
 */
TreeNode *leftRotate(TreeNode *root, int targetValue) {
    if (root == NULL) {
        return NULL;
    } else if (root -> value == targetValue) {
        TreeNode *rightChild = root -> right;
        TreeNode *rightChildLeft = NULL;
        if (rightChild != NULL) {
            rightChildLeft = rightChild -> left;
            root -> right = rightChildLeft;
            rightChild -> left = root;
            return rightChild;
        } else {
            // Can't rotate when there's no right child
            return root;
        }
    }

    if (targetValue < root -> value) {
        // Target node exists somewhere in the left subtree
        root -> left = leftRotate(root -> left, targetValue);
    } else if (targetValue > root -> value) {
        // Target tree exists somewhere in the right subtree
        root -> right = leftRotate(root -> right, targetValue);
    }
    return root;
}

/**
 * Executes a right rotation on the node with the given target value.
 * Returns the resultant tree.
 */
TreeNode *rightRotate(TreeNode *root, int targetValue) {
    if (root == NULL) {
        return NULL;
    } else if (root -> value == targetValue) {
        TreeNode *leftChild = root -> left;
        TreeNode *leftChildRight = NULL;
        if (leftChild != NULL) {
            leftChildRight = leftChild -> right;
            root -> left = leftChildRight;
            leftChild -> right = root;
            return leftChild;
        } else {
            // Can't rotate when there's no left child
            return root;
        }
    }

    if (targetValue < root -> value) {
        root -> left = rightRotate(root -> left, targetValue);
    } else if (targetValue > root -> value) {
        root -> right = rightRotate(root -> right, targetValue);
    }
    return root;
}