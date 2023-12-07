#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include "LinkedList_int.h"
#include <CoreWindow.h>
#include <windows.h>
#define Max 10




void Create(LinkedList** _ptList);
void Destroy(LinkedList** _ptList);
Node* GetNode(int _iObject);
Node* Read(LinkedList* _ptList, unsigned int i);
void Traversal(LinkedList* _ptList);
Node* AppendFromHead(LinkedList* _ptList, int _iObject);
Node* AppendFromTail(LinkedList* _ptList, int _iObject);
Node* InsertBefore(LinkedList* _ptList, Node*, int Object);
Node* InsertAfter(LinkedList* _ptList, Node* _ptNode, int Object);
Node* DeleteFromHead(LinkedList* _ptList);
Node* DeleteFromTail(LinkedList* _ptList);
Node* Delete(LinkedList* _ptList, Node* _ptNode);
Node* DeleteNode_Count(LinkedList* _ptList, int count);
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
Node* Modify_by_Count(LinkedList* _ptList, int count, int iObject);

void cur(short x, short y)		//화면의 원하는 x, y좌표로 보냄
{
	COORD pos = { x, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}



int main() {
	long long L =(-2147483647 -1 );
	int R = 2147483647;
	char Cont;
	int flag = 0;
	LinkedList* Lists[Max] = { NULL, };
	int List_num = 0;
	long long Num_tmp = 0;
	long long Num_tmp2 = 0;
	long long Num_tmp3 = 0;
	Node* Node_tmp = NULL;
	int SearchResultSize;
	Node** SearchSortResultArr;
	COORD pos = { 0,0 };

	while (flag == 0) {
		
		printf("///////////////////////////////////////////////////////////////////////\n");
		printf("1. 관리 구조 생성\t\t2. 관리구조 소멸\n3. 임의 위치 값 읽기\t\t4. 노드 순회\n");
		printf("5. 앞 노드 추가\t\t\t6. 뒤 노드 추가\n");
		printf("7. 기준 노드 앞 삽입\t\t8. 기준 노드 뒤 삽입\n");
		printf("9. 앞 노드 삭제\t\t\t10. 뒤 노드 삭제\n");
		printf("11. 기준 위치 삭제\t\t22. 임의 노드 삭제\t\t12. 모든 노드 삭제\n");
		printf("13. 기준 노드 수정\t\t23. 임의 노드 수정\n14. 단일 선형 탐색\t\t");
		printf("15. 다중 선형 탐색\n16. 단일 이진 탐색\t\t");
		printf("17. 다중 이진 탐색\n18. 거품 정렬\t");
		printf("19. 삽입 정렬\t20. 선택 정렬\n21. 종료\n");
		printf("///////////////////////////////////////////////////////////////////////\n");
		printf("리스트는 최대 10개까지 생성 가능.");
		printf("\n\n");

		if (!Node_tmp) Node_tmp == NULL;

		if (List_num == 0) {
			printf("None..\n");
			printf("\n");
		}
		else {
			printf("현재 존재하는 리스트들 _\n");
			for (int i = 0; i < Max; i++) {
				int count = 0;
				if (Lists[i] != NULL) {
					printf("\nList %d :", i);
					if (!Lists[i]->m_pHead) { printf("Empty"); continue; }
					Node* curr = Lists[i]->m_pHead;
					while (count < Lists[i]->m_uCount) {
						if (curr == Node_tmp) {
							printf(" '%d' ", curr->m_iObject);
							curr = curr->m_pNext;
							count++;
							continue;
						}
						printf(" %d ", curr->m_iObject);
						curr = curr->m_pNext;
						count++;
					}

				}
				else printf("\n@ ");

			}
			printf("\n\n");
		}




		int Selection = -1;

		printf("\n기능 선택:");
		int err = scanf("%d", &Selection);
		if (err != 1) {

			printf("\n잘못된 입력\n");
			Sleep(300);
			while (getchar() != '\n')
				system("cls");
				continue;

		}
		printf("\n\n");
		if (Selection == 1) {
			system("cls");
			SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
			if (List_num < Max) {
				for (int i = 0; i < Max; i++) {
					if (Lists[i] == NULL) {
						Create(&Lists[i]);
						List_num++;
						break;

					}
				}
				printf("%d \n", List_num);
			}
			else printf("Full");
		}
		if (Selection == 2) {
			printf("지울 리스트 ? :");
			err = scanf("%d", &Num_tmp);
			if (err != 1) {
				printf("\n잘못된 입력\n");
				Sleep(300);
				while (getchar() != '\n') {}
				system("cls");
				SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
				continue;

			}
			Destroy(&Lists[Num_tmp]);
			List_num--;

		}

		if (Selection == 3) {
			printf("몇번째 리스트에서 ? :");
			err = scanf("%d", &Num_tmp2);
			if (err != 1) {
				printf("\n잘못된 입력\n");
				Sleep(300);
				while (getchar() != '\n') {}
				system("cls");
				SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
				continue;

			}
			printf("몇번째 노드를 ? :");
			err = scanf("%d", &Num_tmp);
			if (err != 1) {
				printf("\n잘못된 입력\n");
				Sleep(300);
				while (getchar() != '\n') {}
				system("cls");
				SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
				continue;

			}
			Node_tmp = Read(Lists[Num_tmp2], Num_tmp);
		}
		if (Selection == 4) {
			printf("몇번째 리스트 ? :");
			err = scanf("%d", &Num_tmp);
			if (err != 1) {
				printf("\n잘못된 입력\n");
				Sleep(300);
				while (getchar() != '\n') {}
				continue;

			}
			system("cls");
			SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
			Traversal(Lists[Num_tmp]);
		}
		if (Selection == 5) {
			printf("몇번째 리스트 ? :");
			err = scanf("%d", &Num_tmp);
			if (err != 1) {
				printf("\n잘못된 입력\n");
				Sleep(300);
				while (getchar() != '\n') {}
				system("cls");
				SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
				continue;

			}
			printf("넣을 Object ? :");
			err = scanf("%d", &Num_tmp2);
			if (err != 1) {
				printf("\n잘못된 입력\n");
				Sleep(300);
				while (getchar() != '\n') {}
				system("cls");
				SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
				continue;

			}
			else {
				if (Num_tmp2 >= L && Num_tmp2 <= R) {

				}
				else {
					printf("오버,언더플로우 발생");
					Sleep(500);
					system("cls");
					SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
					continue;
				}
			}
			if (Lists[Num_tmp] != NULL) {
				Node_tmp = AppendFromHead(Lists[Num_tmp], Num_tmp2);
				system("cls");
				SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
			}
			else {
				system("cls");
				SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
				printf("리스트 없음");
				Sleep(500);

			}
		}
		if (Selection == 6) {
			printf("몇번째 리스트 ? :");
			err = scanf("%d", &Num_tmp);
			if (err != 1) {
				printf("\n잘못된 입력\n");
				Sleep(300);
				while (getchar() != '\n') {}
				system("cls");
				SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
				continue;

			}
			printf("넣을 Object ? :");
			err = scanf("%d", &Num_tmp2);
			if (err != 1) {
				printf("\n잘못된 입력\n");
				Sleep(300);
				while (getchar() != '\n') {}
				system("cls");
				SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
				continue;

			}
			else {
				if (Num_tmp2 >= L && Num_tmp2 <= R) {

				}
				else {
					system("cls");
					SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
					printf("오버,언더플로우 발생");

					continue;
				}
			}
			if (Lists[Num_tmp] != NULL) {
				Node_tmp = AppendFromTail(Lists[Num_tmp], Num_tmp2);
				system("cls");
				SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
			}
			else {
				system("cls");
				SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
				printf("리스트 없음");


			}

		}
		if (Selection == 7) {
			printf("몇번째 리스트 ? :");
			err = scanf("%d", &Num_tmp);
			if (err != 1) {
				printf("\n잘못된 입력\n");
				Sleep(300);
				while (getchar() != '\n') {}
				system("cls");
				SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
				continue;

			}
			printf("넣을 Object ? :");
			err = scanf("%d", &Num_tmp2);
			if (err != 1) {
				printf("\n잘못된 입력\n");
				Sleep(300);
				while (getchar() != '\n') {}
				system("cls");
				SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
				continue;

			}
			else {
				if (Num_tmp2 >= L && Num_tmp2 <= R) {

				}
				else {
					system("cls");
					SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
					printf("오버,언더플로우 발생");
					
					continue;
				}
			}
			Node_tmp = InsertBefore(Lists[Num_tmp], Node_tmp, Num_tmp2);
			system("cls");
			SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
		}
		if (Selection == 8) {
			printf("몇번째 리스트 ? :");
			err = scanf("%lld", &Num_tmp);
			if (err != 1) {
				printf("\n잘못된 입력\n");
				Sleep(300);
				while (getchar() != '\n') {}
				system("cls");
				SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
				continue;

			}
			printf("넣을 Object ? :");
			err = scanf("%lld", &Num_tmp2);
			if (err != 1) {
				printf("\n잘못된 입력\n");
				Sleep(300);
				while (getchar() != '\n') {}
				system("cls");
				SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
				continue;

			}
			else {
				if (Num_tmp2 >= L && Num_tmp2 <= R) {

				}
				else {
					printf("오버,언더플로우 발생");
					Sleep(500);
					system("cls");
					SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
					continue;
				}
			}
			Node_tmp = InsertAfter(Lists[Num_tmp], Node_tmp, Num_tmp2);
		}
		if (Selection == 9) {
			printf("몇번째 리스트 ? :");
			err = scanf("%lld", &Num_tmp);
			if (err != 1) {
				printf("\n잘못된 입력\n");
				Sleep(300);
				while (getchar() != '\n') {}
				system("cls");
				SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
				continue;

			}
			Node_tmp = DeleteFromHead(Lists[Num_tmp]);
			free(Node_tmp);
			Node_tmp = NULL;
			system("cls");
			SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
		}
		if (Selection == 10) {
			printf("몇번째 리스트 ? :");
			err = scanf("%lld", &Num_tmp);
			if (err != 1) {
				printf("\n잘못된 입력\n");
				Sleep(300);
				while (getchar() != '\n') {}
				system("cls");
				SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
				continue;

			}
			Node_tmp = DeleteFromTail(Lists[Num_tmp]);
			free(Node_tmp);
			Node_tmp = NULL;
			system("cls");
			SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
		}
		if (Selection == 11) {
			printf("몇번째 리스트 ? :");
			err = scanf("%lld", &Num_tmp);
			if (err != 1) {
				printf("\n잘못된 입력\n");
				Sleep(300);
				while (getchar() != '\n') {}
				system("cls");
				SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
				continue;

			}
			Node_tmp = Delete(Lists[Num_tmp], Node_tmp);
			free(Node_tmp);
			Node_tmp = NULL;
			system("cls");
			SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
		}
		if (Selection == 22) {
			printf("몇번째 리스트 ? :");
			err = scanf("%lld", &Num_tmp);
			if (err != 1) {
				printf("\n잘못된 입력\n");
				Sleep(300);
				while (getchar() != '\n') {}
				system("cls");
				SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
				continue;

			}
			printf("몇번째 요소 ? :");
			err = scanf("%lld", &Num_tmp2);
			if (err != 1) {
				printf("\n잘못된 입력\n");
				Sleep(300);
				while (getchar() != '\n') {}
				system("cls");
				SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
				continue;

			}
			Node_tmp = DeleteNode_Count(Lists[Num_tmp], Num_tmp2);
			free(Node_tmp);
			Node_tmp = NULL;
			system("cls");
			SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
		}
		if (Selection == 12) {
			printf("몇번째 리스트 ? :");
			err = scanf("%lld", &Num_tmp);
			if (err != 1) {
				printf("\n잘못된 입력\n");
				Sleep(300);
				while (getchar() != '\n') {}
				system("cls");
				SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
				continue;

			}
			DeleteAll(Lists[Num_tmp]);
			system("cls");
			SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
		}
		if (Selection == 13) {
			printf("몇번째 리스트 ? :");
			err = scanf("%lld", &Num_tmp);
			if (err != 1) {
				printf("\n잘못된 입력\n");
				Sleep(300);
				while (getchar() != '\n') {}
				system("cls");
				SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
				continue;

			}
			printf("수정할 Object ? :");
			err = scanf("%lld", &Num_tmp2);
			if (err != 1) {
				printf("\n잘못된 입력\n");
				Sleep(300);
				while (getchar() != '\n') {}
				system("cls");
				SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
				continue;

			}
			Node_tmp = Modify(Lists[Num_tmp], Node_tmp, Num_tmp2);
			system("cls");
			SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
		}
		if (Selection == 23) {
			printf("몇번째 리스트 ? :");
			err = scanf("%lld", &Num_tmp);
			if (err != 1) {
				printf("\n잘못된 입력\n");
				Sleep(300);
				while (getchar() != '\n') {}
				system("cls");
				SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
				continue;

			}
			printf("몇번째 노드 ? :");
			err = scanf("%lld", &Num_tmp2);
			if (err != 1) {
				printf("\n잘못된 입력\n");
				Sleep(300);
				while (getchar() != '\n') {}
				system("cls");
				SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
				continue;

			}
			printf("수정할 Object ? :");
			err = scanf("%lld", &Num_tmp3);
			if (err != 1) {
				printf("\n잘못된 입력\n");
				Sleep(300);
				while (getchar() != '\n') {}
				system("cls");
				SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
				continue;

			}
			Node_tmp = Modify_by_Count(Lists[Num_tmp], Num_tmp2, Num_tmp3);
			system("cls");
			SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
		}
		if (Selection == 14) {
			printf("몇번째 리스트 ? :");
			err = scanf("%lld", &Num_tmp);
			if (err != 1) {
				printf("\n잘못된 입력\n");
				Sleep(300);
				while (getchar() != '\n') {}
				system("cls");
				SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
				continue;

			}
			printf("찾을 Object ? :");
			err = scanf("%lld", &Num_tmp2);
			if (err != 1) {
				printf("\n잘못된 입력\n");
				Sleep(300);
				while (getchar() != '\n') {}
				system("cls");
				SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
				continue;

			}
			system("cls");
			SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
			Node_tmp = LinearSearchByUnique(Lists[Num_tmp], Num_tmp2);
		}
		if (Selection == 15) {
			printf("몇번째 리스트 ? :");
			err = scanf("%lld", &Num_tmp);
			if (err != 1) {
				printf("\n잘못된 입력\n");
				Sleep(300);
				while (getchar() != '\n') {}
				system("cls");
				SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
				continue;

			}
			printf("찾을 Object ? :");
			err = scanf("%lld", &Num_tmp2);
			if (err != 1) {
				printf("\n잘못된 입력\n");
				Sleep(300);
				while (getchar() != '\n') {}
				system("cls");
				SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
				continue;

			}
			system("cls");
			SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
			LinearSearchByDuplicate(Lists[Num_tmp], Num_tmp2, &SearchResultSize, &SearchSortResultArr);

		}
		if (Selection == 16) {
			printf("몇번째 리스트 ? :");
			err = scanf("%lld", &Num_tmp);
			if (err != 1) {
				printf("\n잘못된 입력\n");
				Sleep(300);
				while (getchar() != '\n') {}
				system("cls");
				SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
				continue;

			}
			printf("찾을 Object ? :");
			err = scanf("%lld", &Num_tmp2);
			if (err != 1) {
				printf("\n잘못된 입력\n");
				Sleep(300);
				while (getchar() != '\n') {}
				system("cls");
				SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
				continue;

			}
			system("cls");
			SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
			Node_tmp = BinarySearchByUnique(Lists[Num_tmp], Num_tmp2);
		}
		if (Selection == 17) {
			printf("몇번째 리스트 ? :");
			err = scanf("%lld", &Num_tmp);
			if (err != 1) {
				printf("\n잘못된 입력\n");
				Sleep(300);
				while (getchar() != '\n') {}
				system("cls");
				SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
				continue;

			}
			printf("찾을 Object ? :");
			err = scanf("%lld", &Num_tmp2);
			if (err != 1) {
				printf("\n잘못된 입력\n");
				Sleep(300);
				while (getchar() != '\n') {}
				system("cls");
				SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
				continue;

			}
			system("cls");
			SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
			BinarySearchByDuplicate(Lists[Num_tmp], Num_tmp2, &SearchResultSize, &SearchSortResultArr);

		}
		if (Selection == 18) {
			printf("몇번째 리스트 ? :");
			err = scanf("%lld", &Num_tmp);
			if (err != 1) {
				printf("\n잘못된 입력\n");
				Sleep(300);
				while (getchar() != '\n') {}
				system("cls");
				SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
				continue;

			}
			SortByBubble(Lists[Num_tmp]);
			system("cls");
			SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
		}
		if (Selection == 19) {
			printf("몇번째 리스트 ? :");
			err = scanf("%lld", &Num_tmp);
			if (err != 1) {
				printf("\n잘못된 입력\n");
				Sleep(300);
				while (getchar() != '\n') {}
				system("cls");
				SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
				continue;

			}
			SortByInsertion(Lists[Num_tmp]);
			system("cls");
			SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
		}
		if (Selection == 20) {
			printf("몇번째 리스트 ? :");
			err = scanf("%lld", &Num_tmp);
			if (err != 1) {
				printf("\n잘못된 입력\n");
				Sleep(300);
				while (getchar() != '\n') {}
				system("cls");
				SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
				continue;

			}
			SortBySelection(Lists[Num_tmp]);
			system("cls");
			SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
		}
		if (Selection == 21) {
			printf("종료\n");
			flag = 1;
			system("cls");
			SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
		}


	}


	return 0;
}