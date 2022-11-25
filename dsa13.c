#include <stdio.h>
#include <stdlib.h>
typedef struct tmp {
    int item;
    struct tmp* next;
} Node;
typedef struct
    {
    Node* head;
    Node* tail;

} List;
void initList(List* lp)
{
    lp->head = NULL;
    lp->tail = NULL;
}
Node* createNode(int item)
{
    Node* nNode;

    nNode = (Node*)malloc(sizeof(Node));

    nNode->item = item;
    nNode->next = NULL;

    return nNode;
}
void addAtTail(List* lp, int item)
{
    Node* node;
    node = createNode(item);
    if (lp->head == NULL) {
        lp->head = node;
        lp->tail = node;
    }
    else {
        lp->tail->next = node;
        lp->tail = lp->tail->next;
    }
}
void addAtHead(List* lp, int item)
{
    Node* node;
    node = createNode(item);

    if (lp->head == NULL) {
        lp->head = node;
        lp->tail = node;
    }
    else {
        node->next = lp->head;
        lp->head = node;
    }
}
void printList(List* lp)
{
    Node* node;

    if (lp->head == NULL) {
        printf("\nEmpty List");
        return;
    }

    node = lp->head;

    printf("List:\n");
    while (node != NULL) {
        printf("| %05d |", node->item);
        node = node->next;

        if (node != NULL)
            printf("--->");
    }
    printf("\n\n");
}

void SearchItem(List* lp, int item)
{
    Node* node;
    int flag = 0;
    int index = 0;

    if (lp->head == NULL) {
        printf("\nEmpty List");
        return;
    }

    node = lp->head;

    while (node != NULL) {
        if (node->item == item) {
            flag = 1;
            break;
        }
        node = node->next;

        index++;
    }

    if (flag == 0)
        printf("Item not found\n");
    else
        printf("Item found at index: %d\n", index);
}
int main()
{
    List* lp;

    int item = 0;

    lp = (List*)malloc(sizeof(List));

    initList(lp);

    addAtTail(lp, 100);
    addAtTail(lp, 150);
    addAtHead(lp, 200);
    addAtHead(lp, 300);

    printList(lp);

    printf("Enter item to search: ");
    scanf("%d", &item);

    SearchItem(lp, item);

    return 0;
}
