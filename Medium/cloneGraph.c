/**
 * Definition for a Node.
 * struct Node {
 *     int val;
 *     int numNeighbors;
 *     struct Node** neighbors;
 * };
 */

struct Node** nodes[100]; // Cache of nodes already encountered

struct Node* func(struct Node* s) {
    struct Node* res = NULL;

    // Return cahced node
    if (nodes[s->val - 1] != NULL) {
        res = nodes[s->val - 1];
        return res;
    } else { // Create new copy for node
        res = (struct Node*)malloc(sizeof(struct Node));
        assert(res != NULL);

        res->val = s->val;
        res->numNeighbors = s->numNeighbors;
        res->neighbors =
            (struct Node**)malloc(sizeof(struct Node*) * s->numNeighbors);

        nodes[res->val - 1] = res; // Add newly created node to cache
    }

    // Clone each neighbor of given node
    for (int i = 0; i < s->numNeighbors; ++i)
        res->neighbors[i] = func(s->neighbors[i]);

    return res;
}

struct Node* cloneGraph(struct Node* s) {
    if (s == NULL)
        return NULL;

    for (int i = 0; i < 100; ++i)
        nodes[i] = NULL;

    return func(s);
}