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


void cur(short x, short y)		//ȭ���� ���ϴ� x, y��ǥ�� ����
{
	COORD pos = { x, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}



int main() {
	char Cont;
	int flag = 0;
	LinkedList* Lists[Max] = { NULL, };
	int List_num = 0;
	int Num_tmp = 0;
	int Num_tmp2 = 0;
	Node* Node_tmp = NULL;
	int SearchResultSize;
	Node** SearchSortResultArr;
	COORD pos = { 0,0 };

	while (flag == 0) {
		system("cls");
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
		printf("///////////////////////////////////////////////////////////////////////\n");
		printf("1. ���� ���� ����\t\t2. �������� �Ҹ�\n3. ���� ��ġ �� �б�\t\t4. ��� ��ȸ\n");
		printf("5. �� ��� �߰�\t\t\t6. �� ��� �߰�\n");
		printf("7. ���� ��� �� ����\t\t8. ���� ��� �� ����\n");
		printf("9. �� ��� ����\t\t\t10. �� ��� ����\n");
		printf("11. ���� ��ġ ����\t\t12. ��� ��� ����\n");
		printf("13. ���� ��� ����\n14. ���� ���� Ž��\t\t");
		printf("15. ���� ���� Ž��\n16. ���� ���� Ž��\t\t");
		printf("17. ���� ���� Ž��\n18. ��ǰ ����\t");
		printf("19. ���� ����\t20. ���� ����\n21. ����\n");
		printf("///////////////////////////////////////////////////////////////////////\n");
		printf("����Ʈ�� �ִ� 10������ ���� ����.");
		printf("\n\n");

		if (!Node_tmp) Node_tmp == NULL;

		if (List_num == 0) {
			printf("None..\n");
			printf("\n");
		}
		else {
			printf("���� �����ϴ� ����Ʈ�� _\n");
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

		printf("\n��� ����:");
		int err = scanf("%d", &Selection);
		if (err != 1) {
			printf("\n�߸��� �Է�\n");
			Sleep(300);
			while(getchar() != '\n')
			continue;

		}
		printf("\n\n");
		if (Selection == 1) {
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
			printf("���� ����Ʈ ? :");
			 err = scanf("%d", &Num_tmp);
			if (err != 1) {
				printf("\n�߸��� �Է�\n");
				Sleep(300);
				while (getchar() != '\n') {}
				continue;

			}
			Destroy(&Lists[Num_tmp]);
			List_num--;

		}

		if (Selection == 3) {
			printf("���° ����Ʈ���� ? :");
			 err = scanf("%d", &Num_tmp2);
			if (err != 1) {
				printf("\n�߸��� �Է�\n");
				Sleep(300);
				while (getchar() != '\n') {}
				continue;

			}
			printf("���° ��带 ? :");
			 err = scanf("%d", &Num_tmp);
			if (err != 1) {
				printf("\n�߸��� �Է�\n");
				Sleep(300);
				while (getchar() != '\n') {}
				continue;

			}
			Node_tmp = Read(Lists[Num_tmp2], Num_tmp);
		}
		if (Selection == 4) {
			printf("���° ����Ʈ ? :");
			 err = scanf("%d", &Num_tmp);
			if (err != 1) {
				printf("\n�߸��� �Է�\n");
				Sleep(300);
				while (getchar() != '\n') {}
				continue;

			}
			Traversal(Lists[Num_tmp]);
		}
		if (Selection == 5) {
			printf("���° ����Ʈ ? :");
			 err = scanf("%d", &Num_tmp);
			if (err != 1) {
				printf("\n�߸��� �Է�\n");
				Sleep(300);
				while (getchar() != '\n') {}
				continue;

			}
			printf("���� Object ? :");
			 err = scanf("%d", &Num_tmp2);
			if (err != 1) {
				printf("\n�߸��� �Է�\n");
				Sleep(300);
				while (getchar() != '\n') {}
				continue;

			}
			if (Lists[Num_tmp] != NULL) {
				Node_tmp = AppendFromHead(Lists[Num_tmp], Num_tmp2);
			}
			else {
				printf("����Ʈ ����");
				Sleep(500);

			}
		}
		if (Selection == 6) {
			printf("���° ����Ʈ ? :");
			 err = scanf("%d", &Num_tmp);
			if (err != 1) {
				printf("\n�߸��� �Է�\n");
				Sleep(300);
				while (getchar() != '\n') {}
				continue;

			}
			printf("���� Object ? :");
			 err = scanf("%d", &Num_tmp2);
			if (err != 1) {
				printf("\n�߸��� �Է�\n");
				Sleep(300);
				while (getchar() != '\n') {}
				continue;

			}
			if (Lists[Num_tmp] != NULL) {
				Node_tmp = AppendFromTail(Lists[Num_tmp], Num_tmp2);
			}
			else {
				printf("����Ʈ ����");
				Sleep(500);

			}

		}
		if (Selection == 7) {
			printf("���° ����Ʈ ? :");
			 err = scanf("%d", &Num_tmp);
			if (err != 1) {
				printf("\n�߸��� �Է�\n");
				Sleep(300);
				while (getchar() != '\n') {}
				continue;

			}
			printf("���� Object ? :");
			 err = scanf("%d", &Num_tmp2);
			if (err != 1) {
				printf("\n�߸��� �Է�\n");
				Sleep(300);
				while (getchar() != '\n') {}
				continue;

			}
			Node_tmp = InsertBefore(Lists[Num_tmp], Node_tmp, Num_tmp2);
		}
		if (Selection == 8) {
			printf("���° ����Ʈ ? :");
			 err = scanf("%d", &Num_tmp);
			if (err != 1) {
				printf("\n�߸��� �Է�\n");
				Sleep(300);
				while (getchar() != '\n') {}
				continue;

			}
			printf("���� Object ? :");
			 err = scanf("%d", &Num_tmp2);
			if (err != 1) {
				printf("\n�߸��� �Է�\n");
				Sleep(300);
				while (getchar() != '\n') {}
				continue;

			}
			Node_tmp = InsertAfter(Lists[Num_tmp], Node_tmp, Num_tmp2);
		}
		if (Selection == 9) {
			printf("���° ����Ʈ ? :");
			 err = scanf("%d", &Num_tmp);
			if (err != 1) {
				printf("\n�߸��� �Է�\n");
				Sleep(300);
				while (getchar() != '\n') {}
				continue;

			}
			Node_tmp = DeleteFromHead(Lists[Num_tmp]);
			free(Node_tmp);
			Node_tmp = NULL;
		}
		if (Selection == 10) {
			printf("���° ����Ʈ ? :");
			 err = scanf("%d", &Num_tmp);
			if (err != 1) {
				printf("\n�߸��� �Է�\n");
				Sleep(300);
				while (getchar() != '\n') {}
				continue;

			}
			Node_tmp = DeleteFromTail(Lists[Num_tmp]);
			free(Node_tmp);
			Node_tmp = NULL;
		}
		if (Selection == 11) {
			printf("���° ����Ʈ ? :");
			 err = scanf("%d", &Num_tmp);
			if (err != 1) {
				printf("\n�߸��� �Է�\n");
				Sleep(300);
				while (getchar() != '\n') {}
				continue;

			}
			Node_tmp = Delete(Lists[Num_tmp], Node_tmp);
			free(Node_tmp);
			Node_tmp = NULL;
		}
		if (Selection == 12) {
			printf("���° ����Ʈ ? :");
			 err = scanf("%d", &Num_tmp);
			if (err != 1) {
				printf("\n�߸��� �Է�\n");
				Sleep(300);
				while (getchar() != '\n') {}
				continue;

			}
			DeleteAll(Lists[Num_tmp]);
		}
		if (Selection == 13) {
			printf("���° ����Ʈ ? :");
			 err = scanf("%d", &Num_tmp);
			if (err != 1) {
				printf("\n�߸��� �Է�\n");
				Sleep(300);
				while (getchar() != '\n') {}
				continue;

			}
			printf("������ Object ? :");
			 err = scanf("%d", &Num_tmp2);
			if (err != 1) {
				printf("\n�߸��� �Է�\n");
				Sleep(300);
				while (getchar() != '\n') {}
				continue;

			}
			Node_tmp = Modify(Lists[Num_tmp], Node_tmp, Num_tmp2);
		}
		if (Selection == 14) {
			printf("���° ����Ʈ ? :");
			 err = scanf("%d", &Num_tmp);
			if (err != 1) {
				printf("\n�߸��� �Է�\n");
				Sleep(300);
				while (getchar() != '\n') {}
				continue;

			}
			printf("ã�� Object ? :");
			 err = scanf("%d", &Num_tmp2);
			if (err != 1) {
				printf("\n�߸��� �Է�\n");
				Sleep(300);
				while (getchar() != '\n') {}
				continue;

			}
			Node_tmp = LinearSearchByUnique(Lists[Num_tmp], Num_tmp2);
		}
		if (Selection == 15) {
			printf("���° ����Ʈ ? :");
			 err = scanf("%d", &Num_tmp);
			if (err != 1) {
				printf("\n�߸��� �Է�\n");
				Sleep(300);
				while (getchar() != '\n') {}
				continue;

			}
			printf("ã�� Object ? :");
			 err = scanf("%d", &Num_tmp2);
			if (err != 1) {
				printf("\n�߸��� �Է�\n");
				Sleep(300);
				while (getchar() != '\n') {}
				continue;

			}
			LinearSearchByDuplicate(Lists[Num_tmp], Num_tmp2, &SearchResultSize, &SearchSortResultArr);
			
		}
		if (Selection == 16) {
			printf("���° ����Ʈ ? :");
			 err = scanf("%d", &Num_tmp);
			if (err != 1) {
				printf("\n�߸��� �Է�\n");
				Sleep(300);
				while (getchar() != '\n') {}
				continue;

			}
			printf("ã�� Object ? :");
			 err = scanf("%d", &Num_tmp2);
			if (err != 1) {
				printf("\n�߸��� �Է�\n");
				Sleep(300);
				while (getchar() != '\n') {}
				continue;

			}
			Node_tmp = BinarySearchByUnique(Lists[Num_tmp], Num_tmp2);
		}
		if (Selection == 17) {
			printf("���° ����Ʈ ? :");
			 err = scanf("%d", &Num_tmp);
			if (err != 1) {
				printf("\n�߸��� �Է�\n");
				Sleep(300);
				while (getchar() != '\n') {}
				continue;

			}
			printf("ã�� Object ? :");
			 err = scanf("%d", &Num_tmp2);
			if (err != 1) {
				printf("\n�߸��� �Է�\n");
				Sleep(300);
				while (getchar() != '\n') {}
				continue;

			}
			BinarySearchByDuplicate(Lists[Num_tmp], Num_tmp2, &SearchResultSize, &SearchSortResultArr);
			
		}
		if (Selection == 18) {
			printf("���° ����Ʈ ? :");
			 err = scanf("%d", &Num_tmp);
			if (err != 1) {
				printf("\n�߸��� �Է�\n");
				Sleep(300);
				while (getchar() != '\n') {}
				continue;

			}
			SortByBubble(Lists[Num_tmp]);

		}
		if (Selection == 19) {
			printf("���° ����Ʈ ? :");
			 err = scanf("%d", &Num_tmp);
			if (err != 1) {
				printf("\n�߸��� �Է�\n");
				Sleep(300);
				while (getchar() != '\n') {}
				continue;

			}
			SortByInsertion(Lists[Num_tmp]);

		}
		if (Selection == 20) {
			printf("���° ����Ʈ ? :");
			 err = scanf("%d", &Num_tmp);
			if (err != 1) {
				printf("\n�߸��� �Է�\n");
				Sleep(300);
				while (getchar() != '\n') {}
				continue;

			}
			SortBySelection(Lists[Num_tmp]);

		}
		if (Selection == 21) {
			printf("����\n");
			flag = 1;


		}


	}


	return 0;
}
