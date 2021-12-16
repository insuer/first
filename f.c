#include <stdio.h>
#include <stdlib.h>
#define QueueMax 100

typedef struct Node
{
    char data;
    struct Node *LChild, *RChild;
}BiNode, *BiTree;

typedef struct
{
    BiTree data[QueueMax];
    int head;
    int rear;
    int len;
}Queue;

BiTree CreateTree();  //����������
Queue InitQueue();  //��ʼ������
int IsEmptyQueue(Queue seq);  //�����п�
int IsFullQueue(Queue seq);   //��������
void PushQueue(Queue *seq, BiTree T);  //���
void PopQueue(Queue *seq, BiTree *T);  //����
void LayerOrder(BiTree T);  //�������

int main()
{
    BiTree T;
    T = CreateTree();
    LayerOrder(T);
    return 0;
}

BiTree CreateTree()
{  //����������
    char c;
    c = getchar();
    BiTree T;
    if (c == '#') {
        return NULL;
    }
    T = (BiTree) malloc (sizeof(BiNode));
    T->data = c;
    T->LChild = CreateTree();
    T->RChild = CreateTree();
    return T;
}

Queue InitQueue()
{  //��ʼ������
    Queue seq;
    for(int i = 0; i < QueueMax; i++) {
        seq.data[i] = NULL;
    }
    seq.head = 0;
    seq.rear = -1;
    seq.len = 0;
    return seq;
}

int IsEmptyQueue(Queue seq)
{  //�����п�
    if (seq.len == 0) {
        return 1;
    }
    return 0;
}

int IsFullQueue(Queue seq)
{  //��������
    if (seq.len == QueueMax) {
        return 1;
    }
    return 0;
}

void PushQueue(Queue *seq, BiTree T)
{  //���
    if (IsFullQueue(*seq)) {
        printf("ErrorFull");
        return;
    }
    seq->rear = (seq->rear + 1) % QueueMax;
    seq->len++;
    seq->data[seq->rear] = T;
}

void PopQueue(Queue *seq, BiTree *T)
{  //����
    if (IsEmptyQueue(*seq)) {
        printf("ErrorEmpty");
        return;
    }
    seq->head = (seq->head + 1) % QueueMax;
    *T = seq->data[seq->head];
    seq->len--;
}

void LayerOrder(BiTree T)
{  //�������
    Queue seq;
    seq = InitQueue();
    BiTree tmp;
    tmp = T;
    PushQueue(&seq, tmp);
    while(!IsEmptyQueue(seq)) {
        printf("%c", tmp->data);
        if (tmp->LChild != NULL) {
            PushQueue(&seq, tmp->LChild);
        }
        if (tmp->RChild != NULL) {
            PushQueue(&seq, tmp->RChild);
        }
        PopQueue(&seq, &tmp);
    }

