#include <stdio.h>
#include <stdlib.h>
#include "LinkedList_int.h"

void Create(LinkedList** _ptList);
void Destroy(LinkedList** _ptList);
Node* GetNode(int _iObject);
Node* Read(LinkedList* _ptList, unsigned int i);
void Traversal(LinkedList* _ptList);
Node* AppendFromHead(LinkedList* _ptList, int _iObject);
Node* AppendFromTail(LinkedList* _ptList, int _iObject);
Node* DeleteFromHead(LinkedList* _ptList);
Node* DeleteFromTail(LinkedList* _ptList);
Node* Delete(LinkedList* _ptList, Node* _ptNode);
void DeleteAll(LinkedList* _ptList);
Node* Modify(LinkedList* _ptList, Node* _ptNode, int iObject);
Node* LinearSearchByUnique(LinkedList* _ptList, int Object);
void LinearSearchByDuplicate(LinkedList* _ptList, int Object, int* _resultSize, Node*** _resultArray);
Node* BinarySearchByUnique(LinkedList* _ptList, int Object);
void BinarySearchByDuplicate(LinkedList* _ptList, int Object, int* _resultSize, Node*** _resultArray);
void Change(LinkedList* _ptList, Node* _ptNode1, Node* _ptNode2);
void SortByBubble(LinkedList* _ptList);
void SortByInsertion(LinkedList* _ptList);
void SortBySelection(LinkedList* _ptList);



int main() {
    LinkedList* myList;
    Create(&myList);

    // ��� �߰�
    AppendFromHead(myList, 30);
    AppendFromHead(myList, 20);
    AppendFromHead(myList, 40);
    AppendFromHead(myList, 10);
    AppendFromHead(myList, 50);
    AppendFromHead(myList, 35);
    AppendFromHead(myList, 25);
    AppendFromHead(myList, 45);
    AppendFromHead(myList, 15);
    AppendFromHead(myList, 30);

    // ����Ʈ ��ȸ
    printf("����Ʈ ��ȸ:\n");
    Traversal(myList);

    // Ư�� ���� ���� ���� Ž��
    int searchValueLinear = 40;
    Node* resultNodeLinear = LinearSearchByUnique(myList, searchValueLinear);


    if (resultNodeLinear != NULL) {
        printf("\n%d�� ���� Ž���� ���: %p <- %d -> %p\n", searchValueLinear,resultNodeLinear->m_pPrevious, resultNodeLinear->m_iObject,resultNodeLinear->m_pNext);
    }
    // Ư�� ���� ���� ���� Ž��

    SortByBubble(myList);
    printf("\n���� ���� ��:\n");
    Traversal(myList);
    int searchValueBinary = 40;

    Node* resultNodeBinary = BinarySearchByUnique(myList, searchValueBinary);

    if (resultNodeBinary != NULL) {
        printf("%d�� ���� Ž���� ���: %p <- %d -> %p\n" , searchValueBinary,resultNodeBinary->m_pPrevious, resultNodeBinary->m_iObject, resultNodeBinary->m_pNext);
    }

    // ��� ����
    Node* nodeToModify = myList->m_pHead->m_pNext; // �� ��° ��� ����
    int newValue = 99;
    Modify(myList, nodeToModify, newValue);
    printf("\n��� ���� ���:\n");
    Traversal(myList);

    // ���� (���� ���� ���)
    printf("\n���� ���� ��:\n");
    SortByInsertion(myList);
    Traversal(myList);

    // ��� ����
    Node* nodeToDelete = myList->m_pHead->m_pNext; // �� ��° ��� ����
    Node* deletedNode = Delete(myList, nodeToDelete);
    printf("\n��� ���� ���:\n");
    Traversal(myList);

    AppendFromTail(myList, 10);
    AppendFromHead(myList, 50);
    AppendFromTail(myList, 35);
    AppendFromTail(myList, 25);
    AppendFromTail(myList, 45);
    AppendFromTail(myList, 15);
    AppendFromTail(myList, 30);

    Traversal(myList);
    printf("\n���� ���� ��:\n");
    SortBySelection(myList);

    Traversal(myList);
    //�յ� ����
    printf("\n��� 2�� ���� 1�� ���� ��:\n");
    DeleteFromHead(myList);
    DeleteFromHead(myList);
    DeleteFromTail(myList);

    Traversal(myList);

    // �޸� ����
    
    int searchValue = 30;

    int linearResultSize;
    Node** linearResultArray;
    LinearSearchByDuplicate(myList, searchValue, &linearResultSize, &linearResultArray);

    printf("���� ����:\n");
    for (int i = 0; i < linearResultSize; i++) {
        printf("Node %d: %p <- %d -> %p\n", i + 1,linearResultArray[i]->m_pPrevious, linearResultArray[i]->m_iObject, linearResultArray[i]->m_pNext);
    }

    // �޸� ����
    free(linearResultArray);

    // Binary Search �׽�Ʈ
    int binaryResultSize;
    Node** binaryResultArray;
    BinarySearchByDuplicate(myList, searchValue, &binaryResultSize, &binaryResultArray);

    printf("���� ����:\n");
    for (int i = 0; i < binaryResultSize; i++) {
        printf("Node %d: %p <- %d -> %p\n", i + 1,binaryResultArray[i]->m_pPrevious, binaryResultArray[i]->m_iObject, binaryResultArray[i]->m_pNext);
    }

    // �޸� ����
    free(binaryResultArray);

    // ����Ʈ �� ��� �޸� ����
    Destroy(&myList);


    return 0;
}
