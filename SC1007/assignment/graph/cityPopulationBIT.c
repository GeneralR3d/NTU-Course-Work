typedef struct _listnode
{
    int val;
    struct _listnode *next;
} ListNode;

void sort2Darr (int arr, int low, int high, int onIndex) {
    if (low >= high) return;
    // partition
    int pivot = arr[high][onIndex];
    int i = low-1, *temp;
    for (int j=low; j<high; j++) {
        if (arr[j][onIndex] <= pivot) {
            // swap
            i++;
            temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    i++;
    temp = arr[i];
    arr[i] = arr[high];
    arr[high] = temp;
    // run recursively on arr before and after pivot
    sort2Darr(arr, low, i-1, onIndex);
    sort2Darr(arr, i+1, high, onIndex);
}

int* city_population (int N, int* population, int road, int Q, int** cities) 
{
    // output list
    int *out = (int *) malloc(sizeof(int) * Q);

    // STEP 1: CREATE ADJACENCY LIST
    ListNode *adj[N];
    for (int i=0; i<N; i++) adj[i] = NULL;
    for (int r=0; r<N-1; r++) {
        int u = road[r][0], v = road[r][1];
        ListNode *uNode = (ListNode *) malloc(sizeof(ListNode)), *vNode = (ListNode *) malloc(sizeof(ListNode));
        uNode->val = u;
        uNode->next = adj[v-1];
        adj[v-1] = uNode;
        vNode->val = v;
        vNode->next = adj[u-1];
        adj[u-1] = vNode;
    }
    // printf("adj:\n");
    // for (int i=0; i<N; i++) {
    //     printf("%d: ", i+1);
    //     ListNode *_adjNode = adj[i];
    //     while (_adjNode != NULL) {
    //         printf("%d -> ", _adjNode->val);
    //         _adjNode = _adjNode->next;
    //     }
    //     printf("\n");
    // }

    // STEP 2: DFS TO GET
    int size[N]; // SUBTREE SIZE OF EACH NODE
    int depth[N]; // DEPTH OF EACH NODE
    int parent[N]; // PARENT OF EACH NODE
    for (int i=0; i<N; i++) size[i] = depth[i] = parent[i] = 0;
    int frontier[N], visited[N], fi = 0;
    for (int i=0; i<N; i++) frontier[i] = visited[i] = 0;
    frontier[fi++] = 1;
    visited[0] = 1;
    while (fi > 0) {
        int _parent = frontier[fi-1];
        ListNode *childNode;
        // look for child
        childNode = adj[_parent-1];
        while (childNode != NULL) {
            int _child = childNode->val;
            if (!visited[_child-1]) {
                frontier[fi++] = _child; // push child to frontier
                depth[_child-1] = depth[_parent-1] + 1; // set depth of child
                parent[_child-1] = _parent; // set parent of child
                visited[_child-1] = 1;
                break;
            }
            childNode = childNode->next;
        }
        if (childNode != NULL) continue;
        // no more child
        int _size = 1;
        childNode = adj[_parent-1];
        while (childNode != NULL) {
            int _child = childNode->val;
            if (_child != parent[_parent-1]) _size += size[_child-1];
            childNode = childNode->next;
        }
        size[_parent-1] = _size; // set size of parent
        fi--; // pop parent from frontier
    }
    // printf("size:\n");
    // for (int i=0; i<N; i++) printf("%d ", size[i]);
    // printf("\n");
    // printf("depth:\n");
    // for (int i=0; i<N; i++) printf("%d ", depth[i]);
    // printf("\n");
    // printf("parent:\n");
    // for (int i=0; i<N; i++) printf("%d ", parent[i]);
    // printf("\n");

    // // STEP 3: CREATE CHILD LIST ORDERED BY SIZE AND WITHOUT ADJACENT PARENTS
    // ListNode *child[N];
    // for (int i=0; i<N; i++) {
    //     child[i] = NULL;
    //     ListNode *_adjNode = adj[i];
    //     while (_adjNode != NULL) {
    //         int _adj = _adjNode->id;
    //         if (_adj != parent[i]) {
    //             ListNode *_prevNode = NULL, *_nextNode = child[i];
    //             while (_nextNode != NULL) {
    //                 int _next = _nextNode->id;
    //                 if (size[_next-1] <= size[_adj-1]) break;
    //                 _prevNode = _nextNode;
    //                 _nextNode = _nextNode->next;
    //             }
    //             ListNode *_childNode = (ListNode *) malloc(sizeof(ListNode));
    //             _childNode->id = _adj;
    //             _childNode->next = _nextNode;
    //             if (_prevNode == NULL) child[i] = _childNode;
    //             else _prevNode->next = _childNode;
    //         }
    //         _adjNode = _adjNode->next;
    //     }
    // }
    // // printf("child list:\n");
    // // for (int i=0; i<N; i++) {
    // //     printf("%d: ", i+1);
    // //     ListNode *childNode = child[i];
    // //     while (childNode != NULL) {
    // //         printf("%d -> ", childNode->id);
    // //         childNode = childNode->next;
    // //     }
    // //     printf("\n");
    // // }

    // // STEP 4: DFS TO GET HLD POSITIONS
    // int HLD[N];
    // int position[N], HLDp = 0, HLDi = 0; // POSITION IN HLD
    // int head[N]; // HEAD OF CHAIN OF EACH CITY
    // int start[N]; // START OF CHAIN OF EACH CITY
    // for (int i=0; i<N; i++) HLD[i] = position[i] = head[i] = start[i] = 0;
    // for (int i=0; i<N; i++) frontier[i] = 0;
    // frontier[fi++] = 1;
    // HLD[0] = 1;
    // position[0] = HLDi++;
    // head[0] = HLD[HLDp];
    // start[0] = HLDp;
    // while (fi > 0) {
    //     int _parent = frontier[fi-1];
    //     ListNode *_childNode = child[_parent-1];
    //     if (_childNode != NULL) {
    //         int _child = _childNode->id;
    //         frontier[fi++] = _child; // push child to frontier
    //         if (!start[_parent-1]) start[_parent-1] = _child;
    //         HLD[HLDi] = _child; // insert child in HLD
    //         position[_child-1] = HLDi++; // record position of child in HLD
    //         head[_child-1] = HLD[HLDp]; // record head of chain
    //         // start[_child-1] = HLDp; // record start of chain
    //         child[_parent-1] = _childNode->next; // pop child
    //         free(_childNode);
    //     }
    //     else {
    //         HLDp = HLDi;
    //         fi--;
    //     }
    // }
    // printf("HLD:\n");
    // for (int i=0; i<N; i++) printf("%d ", HLD[i]);
    // printf("\n");
    // printf("position:\n");
    // for (int i=0; i<N; i++) printf("%d ", position[i]);
    // printf("\n");
    // printf("head:\n");
    // for (int i=0; i<N; i++) printf("%d ", head[i]);
    // printf("\n");
    // printf("start:\n");
    // for (int i=0; i<N; i++) printf("%d ", start[i]);
    // printf("\n");

    // // replace cities in HLD with population
    // for (int i=0; i<N; i++) HLD[i] = population[HLD[i]-1];
    // printf("HLD:\n");
    // for (int i=0; i<N; i++) printf("%d ", HLD[i]);
    // printf("\n");


    // // STEP 5: SORT QUERIES BY W AND CITIES BY POPULATION
    // int sortedQueries = (int ) malloc(sizeof(int *) * Q);
    // for (int q=0; q<Q; q++) {
    //     sortedQueries[q] = (int *) malloc(sizeof(int) * 4);
    //     sortedQueries[q][0] = q;
    //     for (int i=0; i<3; i++) sortedQueries[q][i+1] = cities[q][i];
    // }
    // sort2Darr(sortedQueries, 0, Q-1, 3);
    // int sortedCities = (int ) malloc(sizeof(int *) * N);
    // for (int i=0; i<N; i++) {
    //     sortedCities[i] = (int *) malloc(sizeof(int) * 3);
    //     sortedCities[i][0] = i+1;
    //     sortedCities[i][1] = position[i];
    //     sortedCities[i][2] = population[i];
    // }
    // // sort2Darr(sortedCities, 0, N-1, 2);
    // // printf("sortedQueries:\n");
    // // for (int i=0; i<Q; i++) {
    // //     for (int j=0; j<4; j++) printf("%d ", sortedQueries[i][j]);
    // //     printf("\n");
    // // }
    // // printf("sortedCities:\n");
    // // for (int i=0; i<N; i++) {
    // //     for (int j=0; j<3; j++) printf("%d ", sortedCities[i][j]);
    // //     printf("\n");
    // // }

    // int scp = 0; // SORTED CITIES POINTER
    // LOOP THROUGH SORTED QUERIES
    for (int q=0; q<Q; q++) {
        // BINARY INDEXED TREE IS TOO SLOW
        int u = cities[q][0], v = cities[q][1], w = cities[q][2];
        int count = 0;
        while (depth[u-1] > depth[v-1]) {
            if (population[u-1] <= w) count++;
            u = parent[u-1];
        }
        while (depth[v-1] > depth[u-1]) {
            if (population[v-1] <= w) count++;
            v = parent[v-1];
        }
        while (u != v) {
            if (population[u-1] <= w) count++;
            if (population[v-1] <= w) count++;
            u = parent[u-1];
            v = parent[v-1];
        }
        if (population[u-1] <= w) count++;
        *(out+q) = count;
    }

    return out;
}