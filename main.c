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

    // 노드 추가
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

    // 리스트 순회
    printf("리스트 순회:\n");
    Traversal(myList);

    // 특정 값에 대한 선형 탐색
    int searchValueLinear = 40;
    Node* resultNodeLinear = LinearSearchByUnique(myList, searchValueLinear);


    if (resultNodeLinear != NULL) {
        printf("\n%d를 선형 탐색한 결과: %p <- %d -> %p\n", searchValueLinear,resultNodeLinear->m_pPrevious, resultNodeLinear->m_iObject,resultNodeLinear->m_pNext);
    }
    // 특정 값에 대한 이진 탐색

    SortByBubble(myList);
    printf("\n버블 정렬 후:\n");
    Traversal(myList);
    int searchValueBinary = 40;

    Node* resultNodeBinary = BinarySearchByUnique(myList, searchValueBinary);

    if (resultNodeBinary != NULL) {
        printf("%d를 이진 탐색한 결과: %p <- %d -> %p\n" , searchValueBinary,resultNodeBinary->m_pPrevious, resultNodeBinary->m_iObject, resultNodeBinary->m_pNext);
    }

    // 노드 수정
    Node* nodeToModify = myList->m_pHead->m_pNext; // 두 번째 노드 선택
    int newValue = 99;
    Modify(myList, nodeToModify, newValue);
    printf("\n노드 수정 결과:\n");
    Traversal(myList);

    // 정렬 (삽입 정렬 사용)
    printf("\n삽입 정렬 후:\n");
    SortByInsertion(myList);
    Traversal(myList);

    // 노드 삭제
    Node* nodeToDelete = myList->m_pHead->m_pNext; // 두 번째 노드 선택
    Node* deletedNode = Delete(myList, nodeToDelete);
    printf("\n노드 삭제 결과:\n");
    Traversal(myList);

    AppendFromTail(myList, 10);
    AppendFromHead(myList, 50);
    AppendFromTail(myList, 35);
    AppendFromTail(myList, 25);
    AppendFromTail(myList, 45);
    AppendFromTail(myList, 15);
    AppendFromTail(myList, 30);

    Traversal(myList);
    printf("\n선택 정렬 후:\n");
    SortBySelection(myList);

    Traversal(myList);
    //앞뒤 삭제
    printf("\n헤드 2개 테일 1개 삭제 후:\n");
    DeleteFromHead(myList);
    DeleteFromHead(myList);
    DeleteFromTail(myList);

    Traversal(myList);

    // 메모리 해제
    
    int searchValue = 30;

    int linearResultSize;
    Node** linearResultArray;
    LinearSearchByDuplicate(myList, searchValue, &linearResultSize, &linearResultArray);

    printf("선형 다중:\n");
    for (int i = 0; i < linearResultSize; i++) {
        printf("Node %d: %p <- %d -> %p\n", i + 1,linearResultArray[i]->m_pPrevious, linearResultArray[i]->m_iObject, linearResultArray[i]->m_pNext);
    }

    // 메모리 해제
    free(linearResultArray);

    // Binary Search 테스트
    int binaryResultSize;
    Node** binaryResultArray;
    BinarySearchByDuplicate(myList, searchValue, &binaryResultSize, &binaryResultArray);

    printf("이진 다중:\n");
    for (int i = 0; i < binaryResultSize; i++) {
        printf("Node %d: %p <- %d -> %p\n", i + 1,binaryResultArray[i]->m_pPrevious, binaryResultArray[i]->m_iObject, binaryResultArray[i]->m_pNext);
    }

    // 메모리 해제
    free(binaryResultArray);

    // 리스트 및 노드 메모리 해제
    Destroy(&myList);


    return 0;
}
