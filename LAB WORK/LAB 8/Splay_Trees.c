#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int key;
    struct Node *left, *right;
} Node;

// Create new node
Node* newNode(int key) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->key = key;
    node->left = node->right = NULL;
    return node;
}

// Right rotation
Node* rightRotate(Node* x) {
    Node* y = x->left;
    x->left = y->right;
    y->right = x;
    return y;
}

// Left rotation
Node* leftRotate(Node* x) {
    Node* y = x->right;
    x->right = y->left;
    y->left = x;
    return y;
}

// Splay operation (bring key to root)
Node* splay(Node* root, int key) {
    if (root == NULL || root->key == key)
        return root;

    // Key lies in left subtree
    if (key < root->key) {
        if (root->left == NULL)
            return root;

        // Zig-Zig (Left Left)
        if (key < root->left->key) {
            root->left->left = splay(root->left->left, key);
            root = rightRotate(root);
        }
        // Zig-Zag (Left Right)
        else if (key > root->left->key) {
            root->left->right = splay(root->left->right, key);
            if (root->left->right != NULL)
                root->left = leftRotate(root->left);
        }

        return (root->left == NULL) ? root : rightRotate(root);
    }

    // Key lies in right subtree
    else {
        if (root->right == NULL)
            return root;

        // Zag-Zig (Right Left)
        if (key < root->right->key) {
            root->right->left = splay(root->right->left, key);
            if (root->right->left != NULL)
                root->right = rightRotate(root->right);
        }
        // Zag-Zag (Right Right)
        else if (key > root->right->key) {
            root->right->right = splay(root->right->right, key);
            root = leftRotate(root);
        }

        return (root->right == NULL) ? root : leftRotate(root);
    }
}

// Search (splay the key)
Node* search(Node* root, int key) {
    return splay(root, key);
}

// Insert
Node* insert(Node* root, int key) {
    if (root == NULL)
        return newNode(key);

    root = splay(root, key);

    if (root->key == key)
        return root;  // Already exists

    Node* node = newNode(key);

    if (key < root->key) {
        node->right = root;
        node->left = root->left;
        root->left = NULL;
    } else {
        node->left = root;
        node->right = root->right;
        root->right = NULL;
    }

    return node;
}

// Delete
Node* deleteKey(Node* root, int key) {
    if (root == NULL)
        return NULL;

    root = splay(root, key);

    if (root->key != key)
        return root;   // Key not found

    Node* temp;
    if (root->left == NULL) {
        temp = root;
        root = root->right;
    } else {
        temp = root;
        root = splay(root->left, key);
        root->right = temp->right;
    }

    free(temp);
    return root;
}

// Inorder traversal
void inorder(Node* root) {
    if (root) {
        inorder(root->left);
        printf("%d ", root->key);
        inorder(root->right);
    }
}

// Demo
int main() {
    Node* root = NULL;

    root = insert(root, 30);
    root = insert(root, 40);
    root = insert(root, 50);
    root = insert(root, 20);
    root = insert(root, 10);

    printf("Inorder traversal: ");
    inorder(root);

    root = search(root, 20);
    printf("\n\nAfter searching 20 (splayed to root): %d\n", root->key);

    root = deleteKey(root, 30);
    printf("After deleting 30 inorder: ");
    inorder(root);
    printf("\n");

    return 0;
}
