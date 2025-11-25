#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <math.h>

typedef struct FibNode {
    int key;
    int degree;
    int mark;
    struct FibNode *parent;
    struct FibNode *child;
    struct FibNode *left;
    struct FibNode *right;
} FibNode;

typedef struct FibHeap {
    FibNode *min;
    int n;
} FibHeap;

// Create a new node
FibNode* createNode(int key) {
    FibNode* node = (FibNode*)malloc(sizeof(FibNode));
    node->key = key;
    node->degree = 0;
    node->mark = 0;
    node->parent = NULL;
    node->child = NULL;
    node->left = node;
    node->right = node;
    return node;
}

// Create empty heap
FibHeap* createHeap() {
    FibHeap* heap = (FibHeap*)malloc(sizeof(FibHeap));
    heap->min = NULL;
    heap->n = 0;
    return heap;
}

// Insert node into root list
void fibHeapInsert(FibHeap* heap, int key) {
    FibNode* node = createNode(key);

    if (heap->min == NULL) {
        heap->min = node;
    } else {
        node->left = heap->min;
        node->right = heap->min->right;
        heap->min->right->left = node;
        heap->min->right = node;

        if (key < heap->min->key)
            heap->min = node;
    }
    heap->n++;
}

// Link y under x
void fibHeapLink(FibHeap* heap, FibNode* y, FibNode* x) {
    y->left->right = y->right;
    y->right->left = y->left;
    y->parent = x;

    if (x->child == NULL) {
        x->child = y;
        y->right = y;
        y->left = y;
    } else {
        y->left = x->child;
        y->right = x->child->right;
        x->child->right->left = y;
        x->child->right = y;
    }
    x->degree++;
    y->mark = 0;
}

// Consolidate trees after extractMin
void fibHeapConsolidate(FibHeap* heap) {
    int D = (int)(log(heap->n) / log(2)) + 2;
    FibNode* A[D];
    for (int i = 0; i < D; i++)
        A[i] = NULL;

    FibNode* start = heap->min;
    FibNode* w = start;
    do {
        FibNode* x = w;
        int d = x->degree;

        while (A[d] != NULL) {
            FibNode* y = A[d];
            if (x->key > y->key) {
                FibNode* temp = x;
                x = y;
                y = temp;
            }
            fibHeapLink(heap, y, x);
            A[d] = NULL;
            d++;
        }
        A[d] = x;
        w = w->right;
    } while (w != start);

    heap->min = NULL;

    for (int i = 0; i < D; i++) {
        if (A[i] != NULL) {
            if (heap->min == NULL) {
                heap->min = A[i];
            } else {
                A[i]->left = heap->min;
                A[i]->right = heap->min->right;
                heap->min->right->left = A[i];
                heap->min->right = A[i];

                if (A[i]->key < heap->min->key)
                    heap->min = A[i];
            }
        }
    }
}

// Extract minimum element
FibNode* fibHeapExtractMin(FibHeap* heap) {
    FibNode* z = heap->min;
    if (z != NULL) {
        if (z->child != NULL) {
            FibNode* child = z->child;
            do {
                child->parent = NULL;
                child = child->right;
            } while (child != z->child);

            FibNode* rightMin = z->right;
            FibNode* leftChild = z->child->left;

            z->right->left = leftChild;
            leftChild->right = z->right;
            z->child->left = z;
            z->right = z->child;
        }

        z->left->right = z->right;
        z->right->left = z->left;

        if (z == z->right) {
            heap->min = NULL;
        } else {
            heap->min = z->right;
            fibHeapConsolidate(heap);
        }
        heap->n--;
    }
    return z;
}

// Cut y from parent x
void fibHeapCut(FibHeap* heap, FibNode* y, FibNode* x) {
    if (y->right == y)
        x->child = NULL;
    else {
        y->right->left = y->left;
        y->left->right = y->right;
        if (x->child == y)
            x->child = y->right;
    }
    x->degree--;

    y->left = heap->min;
    y->right = heap->min->right;
    heap->min->right->left = y;
    heap->min->right = y;

    y->parent = NULL;
    y->mark = 0;
}

// Cascading cut
void fibHeapCascadingCut(FibHeap* heap, FibNode* y) {
    FibNode* z = y->parent;
    if (z != NULL) {
        if (y->mark == 0)
            y->mark = 1;
        else {
            fibHeapCut(heap, y, z);
            fibHeapCascadingCut(heap, z);
        }
    }
}

// Decrease key
void fibHeapDecreaseKey(FibHeap* heap, FibNode* x, int newKey) {
    if (newKey > x->key) {
        printf("Error: new key is greater.\n");
        return;
    }
    x->key = newKey;

    FibNode* y = x->parent;
    if (y != NULL && x->key < y->key) {
        fibHeapCut(heap, x, y);
        fibHeapCascadingCut(heap, y);
    }

    if (x->key < heap->min->key)
        heap->min = x;
}

// Delete node
void fibHeapDelete(FibHeap* heap, FibNode* x) {
    fibHeapDecreaseKey(heap, x, INT_MIN);
    fibHeapExtractMin(heap);
}

// Demo
int main() {
    FibHeap* heap = createHeap();

    fibHeapInsert(heap, 10);
    fibHeapInsert(heap, 2);
    fibHeapInsert(heap, 15);
    fibHeapInsert(heap, 6);

    printf("Minimum: %d\n", heap->min->key);

    FibNode* m = fibHeapExtractMin(heap);
    printf("Extracted Min: %d\n", m->key);

    printf("New Minimum: %d\n", heap->min->key);

    return 0;
}
