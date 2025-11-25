//Functions	to	perform	the	insert	and	delete	
//operations	on	a	B-Tree.

#include <stdio.h>
#include <stdlib.h>

#define T 3   // Minimum degree of B-Tree

// B-Tree node structure
typedef struct BTreeNode {
    int keys[2 * T - 1];
    struct BTreeNode* children[2 * T];
    int n;
    int leaf;
} BTreeNode;

// Create new B-Tree node
BTreeNode* createNode(int leaf) {
    BTreeNode* node = (BTreeNode*)malloc(sizeof(BTreeNode));
    node->leaf = leaf;
    node->n = 0;
    for (int i = 0; i < 2 * T; i++)
        node->children[i] = NULL;
    return node;
}

// Traverse B-Tree
void traverse(BTreeNode* root) {
    if (!root) return;

    int i;
    for (i = 0; i < root->n; i++) {
        if (!root->leaf)
            traverse(root->children[i]);
        printf("%d ", root->keys[i]);
    }

    if (!root->leaf)
        traverse(root->children[i]);
}

// Search a key
BTreeNode* search(BTreeNode* root, int key) {
    int i = 0;
    while (i < root->n && key > root->keys[i])
        i++;

    if (i < root->n && root->keys[i] == key)
        return root;

    if (root->leaf)
        return NULL;

    return search(root->children[i], key);
}

// Split a full child
void splitChild(BTreeNode* parent, int i, BTreeNode* child) {
    BTreeNode* newNode = createNode(child->leaf);
    newNode->n = T - 1;

    for (int j = 0; j < T - 1; j++)
        newNode->keys[j] = child->keys[j + T];

    if (!child->leaf) {
        for (int j = 0; j < T; j++)
            newNode->children[j] = child->children[j + T];
    }

    child->n = T - 1;

    for (int j = parent->n; j >= i + 1; j--)
        parent->children[j + 1] = parent->children[j];

    parent->children[i + 1] = newNode;

    for (int j = parent->n - 1; j >= i; j--)
        parent->keys[j + 1] = parent->keys[j];

    parent->keys[i] = child->keys[T - 1];
    parent->n++;
}

// Insert non-full
void insertNonFull(BTreeNode* node, int key) {
    int i = node->n - 1;

    if (node->leaf) {
        while (i >= 0 && key < node->keys[i]) {
            node->keys[i + 1] = node->keys[i];
            i--;
        }
        node->keys[i + 1] = key;
        node->n++;
    } else {
        while (i >= 0 && key < node->keys[i])
            i--;

        if (node->children[i + 1]->n == 2 * T - 1) {
            splitChild(node, i + 1, node->children[i + 1]);

            if (key > node->keys[i + 1])
                i++;
        }

        insertNonFull(node->children[i + 1], key);
    }
}

// Insert key in B-Tree
BTreeNode* insert(BTreeNode* root, int key) {
    if (!root)
        root = createNode(1);

    if (root->n == 2 * T - 1) {
        BTreeNode* newRoot = createNode(0);
        newRoot->children[0] = root;
        splitChild(newRoot, 0, root);
        root = newRoot;
    }

    insertNonFull(root, key);
    return root;
}

// Get predecessor
int getPred(BTreeNode* node, int idx) {
    BTreeNode* cur = node->children[idx];
    while (!cur->leaf)
        cur = cur->children[cur->n];
    return cur->keys[cur->n - 1];
}

// Get successor
int getSucc(BTreeNode* node, int idx) {
    BTreeNode* cur = node->children[idx + 1];
    while (!cur->leaf)
        cur = cur->children[0];
    return cur->keys[0];
}

// Merge two children
void merge(BTreeNode* node, int idx) {
    BTreeNode* child = node->children[idx];
    BTreeNode* sibling = node->children[idx + 1];

    child->keys[T - 1] = node->keys[idx];

    for (int i = 0; i < sibling->n; i++)
        child->keys[i + T] = sibling->keys[i];

    if (!child->leaf) {
        for (int i = 0; i <= sibling->n; i++)
            child->children[i + T] = sibling->children[i];
    }

    for (int i = idx; i < node->n - 1; i++)
        node->keys[i] = node->keys[i + 1];

    for (int i = idx + 1; i < node->n; i++)
        node->children[i] = node->children[i + 1];

    child->n += sibling->n + 1;
    node->n--;

    free(sibling);
}

// Fill a child that has less than T-1 keys
void fill(BTreeNode* node, int idx) {
    if (idx != 0 && node->children[idx - 1]->n >= T)
        borrowFromPrev(node, idx);
    else if (idx != node->n && node->children[idx + 1]->n >= T)
        borrowFromNext(node, idx);
    else {
        if (idx != node->n)
            merge(node, idx);
        else
            merge(node, idx - 1);
    }
}

// Borrow from previous sibling
void borrowFromPrev(BTreeNode* node, int idx) {
    BTreeNode* child = node->children[idx];
    BTreeNode* sibling = node->children[idx - 1];

    for (int i = child->n - 1; i >= 0; i--)
        child->keys[i + 1] = child->keys[i];

    if (!child->leaf) {
        for (int i = child->n; i >= 0; i--)
            child->children[i + 1] = child->children[i];
    }

    child->keys[0] = node->keys[idx - 1];

    if (!child->leaf)
        child->children[0] = sibling->children[sibling->n];

    node->keys[idx - 1] = sibling->keys[sibling->n - 1];

    child->n++;
    sibling->n--;
}

// Borrow from next sibling
void borrowFromNext(BTreeNode* node, int idx) {
    BTreeNode* child = node->children[idx];
    BTreeNode* sibling = node->children[idx + 1];

    child->keys[child->n] = node->keys[idx];

    if (!child->leaf)
        child->children[child->n + 1] = sibling->children[0];

    node->keys[idx] = sibling->keys[0];

    for (int i = 1; i < sibling->n; i++)
        sibling->keys[i - 1] = sibling->keys[i];

    if (!sibling->leaf) {
        for (int i = 1; i <= sibling->n; i++)
            sibling->children[i - 1] = sibling->children[i];
    }

    child->n++;
    sibling->n--;
}

// Delete key from node
void deleteFromNode(BTreeNode* root, int key) {
    int idx = 0;

    while (idx < root->n && key > root->keys[idx])
        idx++;

    if (idx < root->n && root->keys[idx] == key) {
        if (root->leaf) {
            for (int i = idx + 1; i < root->n; i++)
                root->keys[i - 1] = root->keys[i];
            root->n--;
        } else {
            if (root->children[idx]->n >= T) {
                int pred = getPred(root, idx);
                root->keys[idx] = pred;
                deleteFromNode(root->children[idx], pred);
            } 
            else if (root->children[idx + 1]->n >= T) {
                int succ = getSucc(root, idx);
                root->keys[idx] = succ;
                deleteFromNode(root->children[idx + 1], succ);
            } 
            else {
                merge(root, idx);
                deleteFromNode(root->children[idx], key);
            }
        }
    } else {
        if (root->leaf) {
            printf("Key %d not present.\n", key);
            return;
        }

        int flag = (idx == root->n);

        if (root->children[idx]->n < T)
            fill(root, idx);

        if (flag && idx > root->n)
            deleteFromNode(root->children[idx - 1], key);
        else
            deleteFromNode(root->children[idx], key);
    }
}

// Delete key from B-Tree
BTreeNode* deleteKey(BTreeNode* root, int key) {
    if (!root) return NULL;

    deleteFromNode(root, key);

    if (root->n == 0) {
        BTreeNode* temp = root;
        if (root->leaf)
            root = NULL;
        else
            root = root->children[0];

        free(temp);
    }
    return root;
}

int main() {
    BTreeNode* root = NULL;
    int choice, key;

    while (1) {
        printf("\n1. Insert\n2. Delete\n3. Search\n4. Traverse\n5. Exit\nEnter choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Enter key to insert: ");
            scanf("%d", &key);
            root = insert(root, key);
            break;

        case 2:
            printf("Enter key to delete: ");
            scanf("%d", &key);
            root = deleteKey(root, key);
            break;

        case 3:
            printf("Enter key to search: ");
            scanf("%d", &key);
            if (search(root, key))
                printf("Key found!\n");
            else
                printf("Key not found!\n");
            break;

        case 4:
            printf("B-Tree Traversal: ");
            traverse(root);
            printf("\n");
            break;

        case 5:
            return 0;

        default:
            printf("Invalid option.\n");
        }
    }

    return 0;
}
