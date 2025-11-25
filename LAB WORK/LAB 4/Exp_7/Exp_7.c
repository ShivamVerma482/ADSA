//  Program	to	encode	data	in	a	text	file	using	Huffman	coding.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TREE_HT 256
#define CHAR_SET 256

// Node structure for Huffman Tree
typedef struct MinHeapNode {
    char data;
    unsigned freq;
    struct MinHeapNode *left, *right;
} MinHeapNode;

// Min Heap structure
typedef struct MinHeap {
    unsigned size;
    unsigned capacity;
    MinHeapNode **array;
} MinHeap;

// Function to create a new node
MinHeapNode* newNode(char data, unsigned freq) {
    MinHeapNode* temp = (MinHeapNode*) malloc(sizeof(MinHeapNode));
    temp->data = data;
    temp->freq = freq;
    temp->left = temp->right = NULL;
    return temp;
}

// Function to create a min heap of given capacity
MinHeap* createMinHeap(unsigned capacity) {
    MinHeap* minHeap = (MinHeap*) malloc(sizeof(MinHeap));
    minHeap->size = 0;
    minHeap->capacity = capacity;
    minHeap->array = (MinHeapNode**) malloc(minHeap->capacity * sizeof(MinHeapNode*));
    return minHeap;
}

// Swap two min heap nodes
void swapMinHeapNode(MinHeapNode** a, MinHeapNode** b) {
    MinHeapNode* t = *a;
    *a = *b;
    *b = t;
}

// Heapify at given index
void minHeapify(MinHeap* minHeap, int idx) {
    int smallest = idx;
    int left = 2*idx + 1;
    int right = 2*idx + 2;

    if (left < minHeap->size && minHeap->array[left]->freq < minHeap->array[smallest]->freq)
        smallest = left;

    if (right < minHeap->size && minHeap->array[right]->freq < minHeap->array[smallest]->freq)
        smallest = right;

    if (smallest != idx) {
        swapMinHeapNode(&minHeap->array[smallest], &minHeap->array[idx]);
        minHeapify(minHeap, smallest);
    }
}

// Check if size of heap is 1
int isSizeOne(MinHeap* minHeap) {
    return (minHeap->size == 1);
}

// Extract minimum value node
MinHeapNode* extractMin(MinHeap* minHeap) {
    MinHeapNode* temp = minHeap->array[0];
    minHeap->array[0] = minHeap->array[minHeap->size - 1];
    minHeap->size--;
    minHeapify(minHeap, 0);
    return temp;
}

// Insert a node into min heap
void insertMinHeap(MinHeap* minHeap, MinHeapNode* node) {
    minHeap->size++;
    int i = minHeap->size - 1;
    while (i && node->freq < minHeap->array[(i - 1)/2]->freq) {
        minHeap->array[i] = minHeap->array[(i - 1)/2];
        i = (i - 1)/2;
    }
    minHeap->array[i] = node;
}

// Build min heap
void buildMinHeap(MinHeap* minHeap) {
    int n = minHeap->size - 1;
    for (int i = (n-1)/2; i >= 0; i--)
        minHeapify(minHeap, i);
}

// Create and build min heap from frequency array
MinHeap* createAndBuildMinHeap(unsigned freq[]) {
    MinHeap* minHeap = createMinHeap(CHAR_SET);
    for (int i = 0; i < CHAR_SET; i++)
        if (freq[i])
            minHeap->array[minHeap->size++] = newNode((char)i, freq[i]);
    buildMinHeap(minHeap);
    return minHeap;
}

// Build Huffman Tree
MinHeapNode* buildHuffmanTree(unsigned freq[]) {
    MinHeapNode *left, *right, *top;
    MinHeap* minHeap = createAndBuildMinHeap(freq);

    while (!isSizeOne(minHeap)) {
        left = extractMin(minHeap);
        right = extractMin(minHeap);

        top = newNode('$', left->freq + right->freq);
        top->left = left;
        top->right = right;

        insertMinHeap(minHeap, top);
    }

    return extractMin(minHeap);
}

// Print Huffman codes
void printCodes(MinHeapNode* root, int arr[], int top) {
    if (root->left) {
        arr[top] = 0;
        printCodes(root->left, arr, top+1);
    }

    if (root->right) {
        arr[top] = 1;
        printCodes(root->right, arr, top+1);
    }

    if (!root->left && !root->right) {
        printf("%c: ", root->data);
        for (int i = 0; i < top; i++)
            printf("%d", arr[i]);
        printf("\n");
    }
}

int main() {
    char filename[100];
    printf("Enter text file name to encode: ");
    scanf("%s", filename);

    FILE *file = fopen(filename, "r");
    if (!file) {
        printf("Cannot open file %s\n", filename);
        return 1;
    }

    unsigned freq[CHAR_SET] = {0};
    char ch;

    // Count frequency of each character
    while ((ch = fgetc(file)) != EOF) {
        freq[(unsigned char)ch]++;
    }
    fclose(file);

    // Build Huffman Tree
    MinHeapNode* root = buildHuffmanTree(freq);

    int arr[MAX_TREE_HT], top = 0;
    printf("\nHuffman Codes:\n");
    printCodes(root, arr, top);

    return 0;
}
