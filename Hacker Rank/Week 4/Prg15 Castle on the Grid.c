typedef struct {
    int x;
    int y;
} Point;

typedef struct Node {
    Point p;
    int moves;
    struct Node* next;
} Node;

typedef struct {
    Node* front;
    Node* rear;
} Queue;

void enqueue(Queue* q, int x, int y, int moves) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->p.x = x;
    newNode->p.y = y;
    newNode->moves = moves;
    newNode->next = NULL;
    if (!q->rear) {
        q->front = q->rear = newNode;
    } else {
        q->rear->next = newNode;
        q->rear = newNode;
    }
}

Node* dequeue(Queue* q) {
    if (!q->front) return NULL;
    Node* temp = q->front;
    q->front = q->front->next;
    if (!q->front) q->rear = NULL;
    return temp;
}

bool isEmpty(Queue* q) {
    return q->front == NULL;
}

int minimumMoves(int grid_count, char** grid, int startX, int startY, int goalX, int goalY) {
    bool visited[grid_count][grid_count];
    for (int i = 0; i < grid_count; i++)
        for (int j = 0; j < grid_count; j++)
            visited[i][j] = false;

    Queue q = {NULL, NULL};
    enqueue(&q, startX, startY, 0);
    visited[startX][startY] = true;

    int dirX[] = {-1, 1, 0, 0};
    int dirY[] = {0, 0, -1, 1};

    while (!isEmpty(&q)) {
        Node* node = dequeue(&q);
        int x = node->p.x;
        int y = node->p.y;
        int moves = node->moves;
        free(node);

        if (x == goalX && y == goalY) {
            return moves;
        }

        for (int d = 0; d < 4; d++) {
            int nx = x + dirX[d];
            int ny = y + dirY[d];
            while (nx >= 0 && nx < grid_count && ny >= 0 && ny < grid_count && grid[nx][ny] != 'X') {
                if (!visited[nx][ny]) {
                    visited[nx][ny] = true;
                    enqueue(&q, nx, ny, moves + 1);
                }
                nx += dirX[d];
                ny += dirY[d];
            }
        }
    }

    return -1;
}
