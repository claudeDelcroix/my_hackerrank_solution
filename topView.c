/* you only have to complete the function given below.  
node is defined as  

struct node {
    
    int data;
    struct node *left;
    struct node *right;
  
};

*/

int plus[100];
int minus[100];
int pd[100];


int rootData;

void top();

void topView( struct node *root) {
    
    for(int i=0;i<100;i++)
    {
        plus[i]=0;
        minus[i]=0;
    }
    
    rootData = root->data;
    
    top(root->left,-1,1);
    top(root->right,1,1);

    int i=1;
    while(minus[i]!=0)
        i++;
    while(i>1)
        printf("%d ",minus[--i]);
    i=1;
    printf("%d ", root->data);
    while(plus[i]!=0)
        printf("%d ",plus[i++]);
}

void top(struct node*temp, int pos, int depth)
{
    
    
    if(temp==NULL)
        return;
    
    //printf("->%d %d %d\n",temp->data, pos, depth);
    
    if(pos<0)
    {if(minus[-pos]==0)
            minus[-pos] = temp->data;
    }
    
    else{
        if(plus[pos]==0 || pd[pos] > depth)
        {
            plus[pos] = temp->data;
             pd[pos] = depth;   }
    }
    
    //printf("->%d %d\n",temp->data, plus[pos]);
    
    top(temp->left,pos-1,depth+1);
    top(temp->right, pos+1,depth+1);
    return;
    
}



//resolution avec la queue 
/*
struct node
{
    int data;
    node* left;
    node* right;
};

*/

struct node2
{
    struct node2* next;
    struct node2* prev;
    struct node* data;
    int idx;
};

typedef struct{
    int size;
    struct node2* front;
    struct node2* rear;
}queue;

struct node2* CreateNode(struct node * data, int idx)
{
    struct node2* n;
    // n = (struct node2*)malloc(sizeof(struct node2));
    // n->data = (struct node*)malloc(sizeof(struct node));
    // n->next = NULL;
    // n->prev = NULL;
    // n->idx = idx;
    struct node2* node2 = (struct node2*)malloc(sizeof(struct node2));

        node2->idx = idx;

        node2->prev = NULL;
        node2->next = NULL;
    node2->data = data;
    return node2;
}


queue CreateQueue()
{
    queue q;
    q.size = 0;
    q.front = NULL;
    q.rear = NULL;
    return q;
}

void
Enqueue(queue *q, struct node * data, int idx)
{
    struct node2* n = CreateNode(data, idx);
    if(q->front == NULL)
        q->front = q->rear = n;
    else
    {
        q->rear->next = n;
        q->rear = n;
    }
    q->size++;
}

struct node2*
Dequeue(queue *q)
{
    if(q->size <= 0)
        return NULL; 
    struct node2* del = q->front;
    q->front = q->front->next;
    q->size--;
    return del;
}

int
IsQueueEmpty(queue *q)
{
    return q == NULL || q->size == 0;
}

void topView(struct node * root) {
    int *a, i, arr_size, idx;
    arr_size = 1001;
    idx = 500;
    struct node2 *curr;
    a = (int*)calloc(arr_size, sizeof(int));
    for (i = 0; i < arr_size; i ++) {
        a[i] = -1;
    }
    queue que = CreateQueue();
    Enqueue(&que, root, idx);
    while (!IsQueueEmpty(&que)) {
        curr = Dequeue(&que);

        if (a[curr->idx] == -1) {
            a[curr->idx] = (int)curr->data->data;
        }
        if (curr->data->left != NULL) {
            Enqueue(&que, curr->data->left, curr->idx -1);
        }
        if (curr->data->right != NULL) {
            Enqueue(&que, curr->data->right, curr->idx +1);
        }
    }

    for (i = 0; i < 1001; i++) {
        if (a[i] != -1){
            printf("%d ", a[i]);
        }
    }
    // if (root == NULL) {
    //     return;
    // }
    // if (a[idx] == -1) {
    //     a[idx] = root->data;
    // }
    // traverse(root->left; a; idx - 1);
    // traverse(root->right; a; idx + 1);
    
  
}


// a l'americaine 
/* you only have to complete the function given below.  
node is defined as  

struct node {
    
    int data;
    struct node *left;
    struct node *right;
  
};



*/

typedef struct
{
    int height;
    int data;
} top_map;

void findMinMaxDist(struct node *root, int *max, int* min, int hd)
{
    if(root == NULL)
        return;
    
    if(*min > hd)
        *min = hd;
    if(*max < hd)
        *max = hd;
    
    if(root->left)
        findMinMaxDist(root->left, max, min, hd - 1);
    if(root->right)
        findMinMaxDist(root->right, max, min, hd + 1);
}

void fill_map(struct node *root, top_map *map, int pos, int height)
{
    if(root == NULL)
        return;
    
    fill_map(root->left,  map, pos-1, height + 1);
    if(map[pos].height > height)
    {
        map[pos].height = height;
        map[pos].data = root->data;
        //printf("pos=%d ht=%d data=%d \n", pos, map[pos].height, map[pos].data);
    }
    else
    {
        //printf("NOT pos=%d ht=%d data=%d \n", pos, height, root->data);
    }
    
    fill_map(root->right, map, pos+1, height + 1);
}
void topView( struct node *root) 
{
    int min = 0, max = 0, num_elem = 0, pos;
    findMinMaxDist(root, &max, &min, 0);

    /*! Number of elments in top view */
    num_elem = max - min + 1;
    //printf("%d %d %d\n", min, max, num_elem);
    top_map *bst_map = (top_map*)malloc(num_elem * sizeof(top_map));
    
    if(bst_map == NULL)
    {
        return;
    }
    
    pos = min * -1;

    for(int i = 0; i < num_elem; i++)
    {
        /*! Initialize to invalid high height val */
        bst_map[i].height = 10000;
    }
    fill_map(root, bst_map, pos, 0);
    
    for(int i = 0; i < num_elem; i++)
    {
        printf("%d ", bst_map[i].data);
    }
}

// i take this for my solution 
struct my_node {
    struct node* node;
    int index;
    struct my_node* next;
};

struct queue {
    struct my_node* front;
    struct my_node* back;
};

int queue_is_empty(struct queue* q) {
    return q->front == NULL;
}

void add_to_front(struct queue* q, struct node* node, int index) {
    struct my_node* new_node = malloc(sizeof(struct my_node));
    new_node->next = NULL;
    new_node->index = index;
    new_node->node = node;
    if (q->front == NULL) {
        q->front = new_node;
        q->back = new_node;
    } else {
        new_node->next = q->front;
        q->front = new_node;
    }
}

void add_to_back(struct queue* q, struct node* node, int index) {
    struct my_node* new_node = malloc(sizeof(struct my_node));
    new_node->next = NULL;
    new_node->index = index;
    new_node->node = node;
    if (q->back == NULL) {
        q->back = new_node;
        q->front = new_node;
    } else {
        q->back->next = new_node;
        q->back = new_node;
    }
}

struct my_node* remove_from_front(struct queue* q) {
    struct my_node* n = q->front;
    if (q->front->next == NULL) { 
        q->front = NULL;
        q->back = NULL;
    } else {
        q->front = q->front->next;
    }
    return n;
}

void topView( struct node *root) {
    int max_left = 0;
    int max_right = 0;
    if (root == NULL) {
        return;
    } else {
        struct queue* print_order = malloc(sizeof(struct queue));
        struct queue* q = malloc(sizeof(struct queue));
        add_to_back(print_order, root, 0);
        add_to_back(q, root, 0);
        while (!queue_is_empty(q)) {
            struct my_node* n = remove_from_front(q);
            if (n->node->left) {
                if (n->index - 1 < max_left) {
                    add_to_front(print_order, n->node->left, max_left - 1);
                    --max_left;
                }
                add_to_back(q, n->node->left, n->index - 1);
            }
            if (n->node->right) {
                if (n->index + 1 > max_right) {
                    add_to_back(print_order, n->node->right, max_right + 1);
                    ++max_right;
                }
                add_to_back(q, n->node->right, n->index + 1);
            }
            free(n);
        }
        free(q);
        while (!queue_is_empty(print_order)) {
            struct my_node* n = remove_from_front(print_order);
            printf("%d ", n->node->data);
            free(n);
        }
    }
}
