#include "LinkedList_int.h"
#include <stdio.h>
#include <stdlib.h>
#include<Windows.h>

void Traversal(LinkedList* _ptList);

////////////////////////////////////////////////////////////////////

/*
	��� : ���������� �ʱ�ȭ �Ѵ�.
	�Լ��� : Create
	�������� : �������� ��ﺯ���� �ּ�(LinkedList **)
	�ǵ����� : -
	�˰��� : -
*/

void Create(LinkedList** _ptList) {
	//0���� �ʱ�ȭ�� ���������� ����
	*_ptList = (LinkedList*)calloc(1, sizeof(LinkedList));
}


/*
	��� : ���������� ���� �Ѵ�.
	�Լ��� : Destroy
	�������� : �������� ��ﺯ���� �ּ�(LinkedList **)
	�ǵ����� : -
	�˰��� : ��带 ��ȸ�ϸ�
*/

void Destroy(LinkedList** _ptList) {
	if ((*_ptList) == NULL) {
		printf("�ش� ����Ʈ�� ��� �ֽ��ϴ�.");
		Sleep(2000);
		return;				//��� ������ ����
	}
	if (!(*_ptList)->m_pHead) {
		free(*_ptList);
		*_ptList = NULL;
		return;				//��� ������ ����
	}
	while ((*_ptList)->m_uCount != 0) {
		(*_ptList)->m_pCurrent = (*_ptList)->m_pHead->m_pNext;
		free((*_ptList)->m_pHead);
		(*_ptList)->m_pHead = (*_ptList)->m_pCurrent;

		(*_ptList)->m_uCount--;

	}
	free(*_ptList);
	*_ptList = NULL;
}

/*
	��� : ��带 ����
	�Լ��� : GetNode
	�������� : ��ü ��(int)
	�ǵ����� : Node *
	�˰��� : -
*/



Node* GetNode(int _iObject) {
	Node* pNode = (Node*)malloc(sizeof(Node));
	pNode->m_pNext = pNode;
	pNode->m_pPrevious = pNode;
	pNode->m_iObject = _iObject;
	return pNode;
}

/*
	��� : ���� ��ġ �� �б�
	�Լ��� : Read
	�������� : LinkedList * unsigned int
	�ǵ����� : Node * // ���� �� NULL
	�˰��� : -
*/

Node* Read(LinkedList* _ptList, unsigned int i) {
	if (!(_ptList)) {
		printf("�ش� ����Ʈ�� ��� �ֽ��ϴ�.");
		Sleep(2000);
		return NULL;				//��� ������ ����
	}
	if (_ptList->m_uCount < i) {
		printf("�ش� ����Ʈ�� %d���� ��Ҹ� �����ֽ��ϴ�.", _ptList->m_uCount);
		Sleep(2000);
		return NULL;				//����� ����
	}
	int count = 0;
	_ptList->m_pCurrent = _ptList->m_pHead;
	while (count < i) {
		_ptList->m_pCurrent = _ptList->m_pCurrent->m_pNext;
		count++;
	}
	return _ptList->m_pCurrent;
}

/*
	��� : ��� ��ȸ
	�Լ��� : Read
	�������� : LinkedList *
	�ǵ����� : -
	�˰��� : ��ȸ�ϸ� m_iObject �� ���
*/

void Traversal(LinkedList* _ptList) {
	int count = 0;/*
	_ptList->m_pCurrent = _ptList->m_pHead;
	printf("��ȸ ����\n");
	while (count < _ptList->m_uCount) {
		printf("%d\n", _ptList->m_pCurrent->m_iObject);
		_ptList->m_pCurrent = _ptList->m_pCurrent->m_pNext;
		count++;
	}
	*/
	if (!_ptList) {
		printf("�ش縮��Ʈ�� ��������� �ʾҽ��ϴ�.");
		Sleep(3000);
		return;
	}
	if (!_ptList->m_pHead) { printf("Empty"); Sleep(2000); return; }
	
	Node* curr = _ptList->m_pHead;
	while (count < _ptList->m_uCount) {

		printf(" %d @ \n", curr->m_iObject);
		curr = curr->m_pNext;
		count++;
	}
	Sleep(3000);
}



////////////////////////////////////////////////////////////////////

/*
	��� : �տ� ��带 �߰��Ѵ�.
	�Լ��� : AppendFromHead
	�������� : LinkedList* , int
	�ǵ����� : Node *
	�˰��� : -
*/

Node* AppendFromHead(LinkedList* _ptList, int _iObject) {
	if (!_ptList) { printf("�ش縮��Ʈ�� ��������� �ʾҽ��ϴ�."); Sleep(500); return NULL; }

	_ptList->m_pCurrent = GetNode(_iObject);
	if (_ptList->m_pHead) {
		_ptList->m_pCurrent->m_pNext = _ptList->m_pHead; // ������� ������ �߰��� ����� �ؽ�Ʈ��  ������ ����
		_ptList->m_pHead->m_pPrevious = _ptList->m_pCurrent; //���� ����� prev �� �߰��� ����
	}
	else {
		_ptList->m_pTail = _ptList->m_pCurrent;			//��������� tail �� ����
	}
	_ptList->m_pHead = _ptList->m_pCurrent;				//�������� ����
	(_ptList->m_uCount)++;

	return _ptList->m_pCurrent;
}


/*
	��� : �ڿ� ��带 �߰��Ѵ�.
	�Լ��� : AppendFromtail
	�������� : LinkedList* , int
	�ǵ����� : Node *
	�˰��� : -
*/

Node* AppendFromTail(LinkedList* _ptList, int _iObject) {
	if (!_ptList) { printf("�ش縮��Ʈ�� ��������� �ʾҽ��ϴ�."); Sleep(500); return NULL; }

	_ptList->m_pCurrent = GetNode(_iObject);
	if (_ptList->m_pHead) {
		_ptList->m_pCurrent->m_pPrevious = _ptList->m_pTail; // ������� ������ �߰��� ����� �ؽ�Ʈ��  ������ tail��
		_ptList->m_pTail->m_pNext = _ptList->m_pCurrent; //���� ����� next �� �߰��� ����
	}
	else {
		_ptList->m_pHead = _ptList->m_pCurrent;			//��������� head �� ����
	}
	_ptList->m_pTail = _ptList->m_pCurrent;				// �������� ����
	(_ptList->m_uCount)++;

	return _ptList->m_pCurrent;
}
////////////////////////////////////////////////////////////////////


Node* InsertBefore(LinkedList* _ptList, Node* _ptNode, int Object) {
	if (_ptList == NULL) {
		printf(" �ش� ����Ʈ�� ����ֽ��ϴ�.");
		return _ptNode;
	}
	int Isin = 0;
	_ptList->m_pCurrent = _ptList->m_pHead;
	for (int i = 0; i < _ptList->m_uCount; i++) {
		if (_ptList->m_pCurrent == _ptNode) {
			printf("���� ��� ã��.\n");
			Isin = 1;

		}
		_ptList->m_pCurrent = _ptList->m_pCurrent->m_pNext;
	}
	if (Isin == 0) {
		printf("���س�� ����\n");
		Sleep(1000);
		return _ptNode;

	}

	if (_ptList->m_pHead == _ptNode) {
		return AppendFromHead(_ptList, Object);
	}

	_ptList->m_pCurrent = GetNode(Object);
	_ptList->m_pCurrent->m_pPrevious = _ptNode->m_pPrevious;
	_ptList->m_pCurrent->m_pNext = _ptNode;
	_ptList->m_pCurrent->m_pPrevious->m_pNext = _ptList->m_pCurrent;
	_ptNode->m_pPrevious = _ptList->m_pCurrent;
	_ptList->m_uCount++;
	return _ptList->m_pCurrent;
}

Node* InsertAfter(LinkedList* _ptList, Node* _ptNode, int Object) {
	if (_ptList == NULL) {
		printf(" �ش� ����Ʈ�� ����ֽ��ϴ�.");
		return _ptNode;
	}
	int Isin = 0;
	_ptList->m_pCurrent = _ptList->m_pHead;
	for (int i = 0; i < _ptList->m_uCount; i++) {
		if (_ptList->m_pCurrent == _ptNode) {
			printf("���� ��� ã��.\n");
			Isin = 1;

		}
		_ptList->m_pCurrent = _ptList->m_pCurrent->m_pNext;
	}
	if (Isin == 0) {
		printf("���س�� ����\n");
		Sleep(1000);
		return _ptNode;
	}

	if (_ptList->m_pTail == _ptNode) {
		return AppendFromTail(_ptList, Object);
	}
	_ptList->m_pCurrent = GetNode(Object);
	_ptList->m_pCurrent->m_pNext = _ptNode->m_pNext;
	_ptList->m_pCurrent->m_pPrevious = _ptNode;
	_ptList->m_pCurrent->m_pNext->m_pPrevious = _ptList->m_pCurrent;
	_ptNode->m_pNext = _ptList->m_pCurrent;
	_ptList->m_uCount++;
	return _ptList->m_pCurrent;
}


/*
	��� : �տ� ��带 �����Ѵ�
	�Լ��� : DeleteFromHead
	�������� : LinkedList*
	�ǵ����� : Node * // ���� �� NULL
	�˰��� : -
*/

Node* DeleteFromHead(LinkedList* _ptList) {
	if (_ptList->m_uCount == 0) {						//��������� ����
		printf("�ش� ����Ʈ�� ����ֽ��ϴ�.");
		Sleep(1000);
		return NULL;
	}

	Node* deletedNode;

	_ptList->m_pCurrent = _ptList->m_pHead;


	_ptList->m_pHead = _ptList->m_pCurrent->m_pNext;
	_ptList->m_pHead->m_pPrevious = _ptList->m_pHead;
	(_ptList->m_uCount)--;
	if (_ptList->m_uCount == 0) {
		_ptList->m_pTail = NULL;
		_ptList->m_pHead = NULL;
	}
	_ptList->m_pCurrent->m_pNext = NULL;
	_ptList->m_pCurrent->m_pPrevious = NULL;	//Ȥ�ø� ���� ����

	deletedNode = _ptList->m_pCurrent;
	_ptList->m_pCurrent = NULL;					//������ ��� ���ٺҰ�

	return deletedNode;
}


/*
	��� : �ڿ� ��带 �����Ѵ�
	�Լ��� : DeleteFromtail
	�������� : LinkedList* , int
	�ǵ����� : Node * // ���� �� NULL
	�˰��� : -
*/

Node* DeleteFromTail(LinkedList* _ptList) {
	if (_ptList->m_uCount == 0) {					//��������� ����
		printf("�ش� ����Ʈ�� ����ֽ��ϴ�.");
		Sleep(1000);
		return NULL;
	}

	Node* deletedNode;

	_ptList->m_pCurrent = _ptList->m_pTail;


	_ptList->m_pTail = _ptList->m_pCurrent->m_pPrevious;
	_ptList->m_pTail->m_pNext = _ptList->m_pTail;
	(_ptList->m_uCount)--;
	if (_ptList->m_uCount == 0) {
		_ptList->m_pHead = NULL;
		_ptList->m_pTail = NULL;
	}
	_ptList->m_pCurrent->m_pNext = NULL;
	_ptList->m_pCurrent->m_pPrevious = NULL;	//Ȥ�ø� ���� ����

	deletedNode = _ptList->m_pCurrent;
	_ptList->m_pCurrent = NULL;					//������ ��� ���ٺҰ�

	return deletedNode;
}


/*
	��� : ���� ��ġ ��带 �����Ѵ�
	�Լ��� : Delete
	�������� : LinkedList* , Node *
	�ǵ����� : Node * // ���� �� NULL
	�˰��� : -
*/

Node* Delete(LinkedList* _ptList, Node* _ptNode) {
	if (!_ptList || !_ptNode) {
		printf("����Ʈ�� ����ְų�, �ش� ���� ����ֽ��ϴ�.");
		Sleep(3000);
		return NULL;
	}


	Node* deletedNode;
	if (_ptNode == _ptList->m_pHead) {
		deletedNode = DeleteFromHead(_ptList);
		return deletedNode;
	}
	if (_ptNode == _ptList->m_pTail) {
		deletedNode = DeleteFromTail(_ptList);
		return deletedNode;
	}
	int count = 0;
	_ptList->m_pCurrent = _ptList->m_pHead;
	while (_ptNode != _ptList->m_pCurrent && count < _ptList->m_uCount) {
		_ptList->m_pCurrent = _ptList->m_pCurrent->m_pNext;
		count++;
	}
	if (count == _ptList->m_uCount) {
		printf("����Ʈ���� �ش� ��带 ã�� �� �����ϴ�.\n");
		Sleep(3000);
		return NULL;
	}
	else {
		_ptList->m_pCurrent->m_pPrevious->m_pNext = _ptList->m_pCurrent->m_pNext;
		_ptList->m_pCurrent->m_pNext->m_pPrevious = _ptList->m_pCurrent->m_pPrevious;

		_ptList->m_pCurrent->m_pNext = NULL;
		_ptList->m_pCurrent->m_pPrevious = NULL;	//Ȥ�ø� ���� ����

		_ptList->m_uCount--;
	}

	deletedNode = _ptList->m_pCurrent;
	_ptList->m_pCurrent = NULL;					//������ ��� ���ٺҰ�

	return deletedNode;

}

/*
	��� : ��� ��带 �����Ѵ�
	�Լ��� : DeleteAll
	�������� : LinkedList*
	�ǵ����� : -
	�˰��� : -
*/

void DeleteAll(LinkedList* _ptList) {
	if (!_ptList) {
		printf("�ش縮��Ʈ�� ��������� �ʾҽ��ϴ�.");
		Sleep(3000);
		return;
	}
	if (_ptList->m_uCount == 0) {
		printf("����Ʈ�� ��� �ֽ��ϴ�.");
		Sleep(1000);
		return;
	}

	while ((_ptList)->m_uCount != 0) {
		(_ptList)->m_pCurrent = (_ptList)->m_pHead;;
		(_ptList)->m_pHead = (_ptList)->m_pCurrent->m_pNext;
		free((_ptList)->m_pCurrent);
		(_ptList)->m_uCount--;
	}

	_ptList->m_pHead = NULL;
	_ptList->m_pTail = NULL;
}

////////////////////////////////////////////////////////////////////////////////////////
/*
	��� : ���� ��� ����
	�Լ��� : Modify
	�������� : LinkedList* Node * int
	�ǵ����� : Node* // ������ NULL
	�˰��� : -
*/


Node* Modify(LinkedList* _ptList, Node* _ptNode, int iObject) {
	if (!_ptList || !_ptNode) {
		return NULL;
	}
	int count = 0;
	_ptList->m_pCurrent = _ptList->m_pHead;
	while (_ptNode != _ptList->m_pCurrent && count < _ptList->m_uCount) {
		_ptList->m_pCurrent = _ptList->m_pCurrent->m_pNext;
		count++;
	}
	if (count == _ptList->m_uCount) {
		printf("�ش� ��带 ã�� �� �����ϴ�.\n");
		return NULL;
	}
	else {
		_ptList->m_pCurrent->m_iObject = iObject;
	}
	return _ptList->m_pCurrent;
}

////////////////////////////////////////////////////////////////////////////////////////

/*
	��� : ���� ���� Ž��
	�Լ��� : LinearSearchByUnique
	�������� : LinkedList* int
	�ǵ����� : Node *
	�˰��� : -
*/

Node* LinearSearchByUnique(LinkedList* _ptList, int Object) {

	if (!_ptList) {
		printf("����Ʈ�� ��� �ֽ��ϴ�.\n");
		Sleep(500);
		return NULL;
	}


	_ptList->m_pCurrent = _ptList->m_pHead;
	for (int i = 0; i < _ptList->m_uCount; i++) {

		if (_ptList->m_pCurrent->m_iObject == Object) {
			//Node* RTN = (Node*)malloc(sizeof(Node*));
			Node* RTN;
			RTN = _ptList->m_pCurrent;
			return RTN;
		}
		_ptList->m_pCurrent = _ptList->m_pCurrent->m_pNext;
	}

	printf("�ش� ���ڸ� ã�� �� �����ϴ�.\n");
	Sleep(500);
	return NULL;


}
/*
	��� : ���� ���� Ž��
	�Լ��� : LinearSearchByDuplicate
	�������� : LinkedList* int int* Node***
	�ǵ����� : -
	�˰��� : -
*/


void LinearSearchByDuplicate(LinkedList* _ptList, int Object, int* _resultSize, Node*** _resultArray) {
	if (!_ptList) {
		return;
	}
	_ptList->m_pCurrent = _ptList->m_pHead;
	int Match_Count = 0;
	for (int i = 0; i < _ptList->m_uCount; i++) {

		if (_ptList->m_pCurrent->m_iObject == Object) {
			printf("%d ��° ���", i);
			Match_Count++;
			Sleep(500);
		}
		_ptList->m_pCurrent = _ptList->m_pCurrent->m_pNext;
	}
	if (Match_Count == 0) {
		return;						// ���� ���
	}


	*_resultSize = Match_Count;
	/*
	*_resultArray = (Node**)calloc(Match_Count, sizeof(Node*));	//����ŭ ���� �Ҵ�
	_ptList->m_pCurrent = _ptList->m_pHead;

	Match_Count = 0;
	for (int i = 0; i < _ptList->m_uCount; i++) {
		if (_ptList->m_pCurrent->m_iObject == Object) {
			(*_resultArray)[Match_Count++] = _ptList->m_pCurrent;
		}
		_ptList->m_pCurrent = _ptList->m_pCurrent->m_pNext;
	}
	*/
}

/*
��� : ���� ���� Ž��
�Լ��� : BinarySearchByUnique
�������� : LinkedList * int
�ǵ����� : ã���� Node* ��ã���� NULL
�˰��� : -
*/
Node* BinarySearchByUnique(LinkedList* _ptList, int Object) {
	if (!_ptList) {
		printf("����Ʈ�� ��� �ֽ��ϴ�.\n");
		Sleep(500);
		return NULL;

	}
	if (_ptList->m_pHead == NULL) {
		printf("����Ʈ�� ��� �ֽ��ϴ�.\n");
		Sleep(500);
		return NULL;
	}
	int FoundFlag = 0;
	int Start = 0;
	int End = _ptList->m_uCount;
	_ptList->m_pCurrent = NULL;
	while (Start <= End) {

		int Mid = (Start + End) / 2;
		_ptList->m_pCurrent = _ptList->m_pHead;
		for (int i = 0; i < Mid; i++) {
			_ptList->m_pCurrent = _ptList->m_pCurrent->m_pNext;
		}

		if (Object == _ptList->m_pCurrent->m_iObject) {
			FoundFlag = 1;
			break;
		}
		if (Object < _ptList->m_pCurrent->m_iObject) {
			End = Mid - 1;
		}
		else {
			Start = Mid + 1;
		}
	}
	if (FoundFlag == 0) {
		printf("%d ����Ʈ ���� �����ϴ�.\n", Object);
		Sleep(500);
		return NULL;
	}
	Node* RTN = _ptList->m_pCurrent;
	_ptList->m_pCurrent = NULL;
	return RTN;
}


/*
	��� : ���� ���� Ž��
	�Լ��� : LinearSearchByDuplicate
	�������� : LinkedList* int int* Node***
	�ǵ����� : -
	�˰��� : -
*/


void BinarySearchByDuplicate(LinkedList* _ptList, int Object, int* _resultSize, Node*** _resultArray) {
	if (!_ptList) {
		printf("����Ʈ�� ��� �ֽ��ϴ�.\n");
		Sleep(500);
		return;
	}
	if (_ptList->m_pHead == NULL) {
		printf("����Ʈ�� ��� �ֽ��ϴ�.\n");
		Sleep(500);
		return;
	}
	int FoundFlag = 0;
	int Start = 0;
	int End = _ptList->m_uCount;
	_ptList->m_pCurrent = NULL;

	int S_tmp = 0;
	printf("\n���� ���� ��� ã�� ����.\n");
	while (Start < End) {


		int Mid = (Start + End) / 2;

		_ptList->m_pCurrent = _ptList->m_pHead;
		for (int i = 0; i < Mid; i++) {
			_ptList->m_pCurrent = _ptList->m_pCurrent->m_pNext;
		}

		if (Object == _ptList->m_pCurrent->m_iObject && FoundFlag == 0) {
			FoundFlag = 1;


		}
		if (Object <= _ptList->m_pCurrent->m_iObject) {
			End = Mid;
			if (Object == _ptList->m_pCurrent->m_iObject) {
				printf("%d ", Mid);
			}
		}
		else {
			Start = Mid + 1;
		}
	}
	S_tmp = Start;
	printf("\n���� ������ ��� ã�� ����.\n");
	Start = 0;
	End = _ptList->m_uCount;
	Node* Prev_tmp = NULL;
	while (Start < End) {
	

		int Mid = (Start + End) / 2;

		_ptList->m_pCurrent = _ptList->m_pHead;
		for (int i = 0; i < Mid; i++) {
			_ptList->m_pCurrent = _ptList->m_pCurrent->m_pNext;
		}
		
		
		if (Object == _ptList->m_pCurrent->m_iObject && FoundFlag == 0) {
			FoundFlag = 1;


		}
		if (Object >= _ptList->m_pCurrent->m_iObject) {
			Start = Mid;
			if (Object == _ptList->m_pCurrent->m_iObject) {
				printf("%d ", Mid);
			}
		}
		else {
			End = Mid - 1;
		}
		if (Prev_tmp == _ptList->m_pCurrent) {
			if (_ptList->m_pCurrent->m_pNext->m_iObject == Object) {
				if (_ptList->m_pTail != _ptList->m_pCurrent) {
					Start = Mid + 1;
					break;
				}
			}
			Start = Mid;
			break;
		}
		Prev_tmp = _ptList->m_pCurrent;
	}

	if (FoundFlag == 0) {
		printf("%d ��(��) ����Ʈ ���� �����ϴ�.\n", Object);
		Sleep(2000);
		return;
	}

	printf("%d\n", Start);

	printf("%d�� �ִ� ���� : %d~%d   \n", Object, S_tmp, Start);
	*_resultSize = Start - S_tmp + 1;
	printf("%d �� ã��\n", *_resultSize);
	Sleep(5000);
	//*_resultArray = (Node**)calloc(*_resultSize, sizeof(Node*));	//����ŭ ���� �Ҵ�
	
	//_ptList->m_pCurrent = _ptList->m_pHead;
	/*
	int Count = 0;
	int i = 0;
	while (Count < _ptList->m_uCount) {
		if (Count >= Start && Count <= End) {
			(*_resultArray)[i++] = _ptList->m_pCurrent;
		}
		_ptList->m_pCurrent = _ptList->m_pCurrent->m_pNext;
		Count++;
	}
	*/
	_ptList->m_pCurrent = NULL;
	return;

}


/////////////////////////////////////////////////////////////////////////////////////////
/*
	��� : ���� LinkedList �� �ִ� Node ��ġ ����
	�Լ��� : Change
	�������� : LinkedList* Node* Node*
	�ǵ����� : -
	�˰��� : -
*/
void Change(LinkedList* _ptList, Node* _ptNode1, Node* _ptNode2) {
	if (!_ptList || !_ptNode1 || !_ptNode2 || _ptNode1 == _ptNode2) return;


	int Node1_flag = 0, Node2_flag = 0;

	_ptList->m_pCurrent = _ptList->m_pHead;
	for (int i = 0; i < _ptList->m_uCount; i++) {
		if (Node1_flag == 1 && Node2_flag == 1) break;
		if (_ptList->m_pCurrent == _ptNode1)  Node1_flag = 1;
		if (_ptList->m_pCurrent == _ptNode2)  Node2_flag = 1;
		_ptList->m_pCurrent = _ptList->m_pCurrent->m_pNext;

	}

	if (Node1_flag != 1 || Node2_flag != 1) {
		printf("�� ��带 ���� ����Ʈ���� ã�� �� �����ϴ�.\n");
		return;
	}

	Node* Prev1 = _ptNode1->m_pPrevious;
	Node* Next1 = _ptNode1->m_pNext;
	Node* Prev2 = _ptNode2->m_pPrevious;
	Node* Next2 = _ptNode2->m_pNext;


	if (_ptNode1 == _ptList->m_pHead) {			//1�� ���
		_ptList->m_pHead = _ptNode2;


		Prev1 = _ptNode2;


	}
	else if (_ptNode2 == _ptList->m_pHead) {		//2�� ��� 
		_ptList->m_pHead = _ptNode1;

		Prev2 = _ptNode1;


	}
	if (_ptNode1 == _ptList->m_pTail) {
		_ptList->m_pTail = _ptNode2;

		Next1 = _ptNode2;


	}
	else if (_ptNode2 == _ptList->m_pTail) {
		_ptList->m_pTail = _ptNode1;

		Next2 = _ptNode1;


	}

	if (_ptNode1->m_pNext == _ptNode2) { //�پ�������
		Prev2 = _ptNode2;
		Next1 = _ptNode1;
	}

	if (_ptNode2->m_pNext == _ptNode1) {	//�پ�������
		Prev1 = _ptNode1;
		Next2 = _ptNode2;
	}

	Next2->m_pPrevious = _ptNode1;
	Prev2->m_pNext = _ptNode1;
	Next1->m_pPrevious = _ptNode2;
	Prev1->m_pNext = _ptNode2;
	_ptNode1->m_pNext = Next2;
	_ptNode1->m_pPrevious = Prev2;

	_ptNode2->m_pNext = Next1;
	_ptNode2->m_pPrevious = Prev1;


	_ptList->m_pCurrent = NULL;
}

void SortByBubble(LinkedList* _ptList) {
	if (!_ptList) return;
	for (int i = _ptList->m_uCount - 1; i > 0; i--) {
		_ptList->m_pCurrent = _ptList->m_pHead;

		for (int j = 0; j < i; j++) {
			if (_ptList->m_pCurrent->m_iObject > _ptList->m_pCurrent->m_pNext->m_iObject) {
				Node* tmpCurrent = _ptList->m_pCurrent;
				Node* tmpCurrent_Next = _ptList->m_pCurrent->m_pNext;
				Change(_ptList, tmpCurrent, tmpCurrent_Next);
				_ptList->m_pCurrent = tmpCurrent;
			}
			else { _ptList->m_pCurrent = _ptList->m_pCurrent->m_pNext; }

		}

	}
}

void SortByInsertion(LinkedList* _ptList) {
	if (!_ptList) return;
	if (_ptList->m_uCount <= 1) {
		return;									//������ �ʿ���� ���
	}
	int Sorted_Index = 1;



	while (Sorted_Index < _ptList->m_uCount) {
		Node* tmp = _ptList->m_pHead;

		for (int i = 0; i < Sorted_Index; i++) {
			tmp = tmp->m_pNext;
		}
		_ptList->m_pCurrent = tmp->m_pPrevious;
		while (tmp->m_pPrevious != tmp && _ptList->m_pCurrent->m_iObject > tmp->m_iObject) {		// tmp ���� ������ // tmp �� �� ������ �հ� ��ȯ
			_ptList->m_pCurrent = tmp->m_pPrevious;


			Change(_ptList, tmp, _ptList->m_pCurrent);
			_ptList->m_pCurrent = tmp->m_pPrevious;


		}

		Sorted_Index++;
	}
}

void SortBySelection(LinkedList* _ptList) {
	if (!_ptList) return;
	if (_ptList->m_uCount <= 1) {
		return;									//������ �ʿ���� ���
	}
	int Sorted_Index = 0;

	Node* Least;



	while (Sorted_Index < _ptList->m_uCount) {
		Least = _ptList->m_pHead;


		for (int i = 0; i < Sorted_Index; i++) {
			Least = Least->m_pNext;
		}

		Node* Bottom = Least;

		_ptList->m_pCurrent = Least->m_pNext;

		for (int i = Sorted_Index; i < _ptList->m_uCount; i++) {
			if (Least->m_iObject > _ptList->m_pCurrent->m_iObject) {
				Least = _ptList->m_pCurrent;

			}
			_ptList->m_pCurrent = _ptList->m_pCurrent->m_pNext;
		}

		Change(_ptList, Least, Bottom);
		Sorted_Index++;
	}
}

