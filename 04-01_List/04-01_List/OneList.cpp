#include "iostream"

using namespace std;

struct ListItem {
	int n;
	ListItem* next;
};

void ListPrint (ListItem *head);
void ListAddEnd(ListItem *head);
int  ListAddN(ListItem **head, int num);

int  ListDelN(ListItem **head, int num);
int  ListSize(ListItem *head);
void ListAddHead(ListItem **head);

void main() 
{

	ListItem * head = new ListItem;
	head->n = 1;        // значение поля структуры
	head->next = NULL;  // значение поля типа указатель

	// Add items to list
	ListPrint(head);
	for (int i = 0; i < 6; i++)
		ListAddEnd(head);
	ListPrint(head);	
	cout << "List size: " << ListSize(head) << endl << endl;

	// Add Items
	//ListAddN (head, 100);
	ListAddN (&head, 1);
	ListAddN (&head, 0);
	ListPrint(head);
	//ListAddN (&head, 0);
	ListAddN (&head, ListSize(head));
	ListPrint(head);
	
	// delete items
	ListDelN (&head, 3);
	ListDelN (&head, ListSize(head));
	ListPrint(head);

	// newHead
	ListAddHead(&head);
	ListPrint(head);

	// delete
	while (ListSize(head))
	{
		ListDelN(&head, ListSize(head));
		ListPrint(head);
	}

	system("pause");
}

void ListAddHead(ListItem **head)
{
	//ListItem *cur = head;
	ListItem *NewHead = new ListItem;

	NewHead->n = 15;
	NewHead->next = *head;
	*head = NewHead;
	
	cout << "Item Added: " << NewHead->n << " to Head" << endl;
	//return NewHead;
}

void ListAddEnd(ListItem *head)
{
	ListItem *cur = head;

	// reach end
	while (cur->next != NULL)
	{
		cur = cur->next;
	}

	// create new item
	ListItem *End = new ListItem;

	End->n = cur->n + 1;
	End->next = NULL;
	cur->next = End;

	cout << "Item Added: " << End->n << endl;
}

int  ListAddN(ListItem **head, int num)
{
	ListItem *cur = *head;
	int k = 1;

	if (!num)
	{
		ListAddHead(head);
		return 0;
	}

	// reach num item
	while ( (cur->next != NULL) && (k < num ) )
	{
		cur = cur->next;
		k++;
	}
	if (k < num)
	{
		cout << "Error in Item Add: very much" << endl;
		return 1;
	}

	// create new item
	ListItem *Add = new ListItem;

	Add->n    = cur->n * 10;
	Add->next = cur->next;
	cur->next = Add;

	cout << "Item Added: " << Add->n << " to position: " << num << endl;
	return 0;
}


int  ListAddNOld(ListItem *head, int num)
{
	ListItem *cur = head;
	int k = 1;

	/*if (!num)
	{
	ListAddHead(&head);
	return 0;
	}*/

	// reach num item
	while ((cur->next != NULL) && (k < num))
	{
		cur = cur->next;
		k++;
	}
	if (k < num)
	{
		cout << "Error in Item Add: very much" << endl;
		return 1;
	}

	// create new item
	ListItem *Add = new ListItem;

	Add->n = cur->n * 10;
	Add->next = cur->next;
	cur->next = Add;

	cout << "Item Added: " << Add->n << " to position: " << num << endl;
	return 0;
}
int  ListDelN(ListItem **head, int num)
{
	ListItem *cur  = *head;
	ListItem *prev = *head;
	int k = 1;

	// reach end
	while ((cur->next != NULL) && (k < num))
	{
		prev = cur;
		cur  = cur->next;
		k++;
	}
	if (k < num)
	{
		cout << "Error in Item Deleting: very much" << endl;
		return 1;
	}
	if (cur == prev)
	{
		*head = NULL;
		//delete cur;
		return 2;
	}

	// delete cur item
	prev->next = cur->next;
	cout << "Item Deleted: " << cur->n << " from position: " << num << endl;

	delete cur;

	int a = 12;
}

int  ListSize(ListItem *head)
{
	if (head == NULL){
		return 0;
	}
	ListItem *cur = head;
	int n = 1;

	// reach end
	while (cur->next != NULL)
	{
		cur = cur->next;
		n++;
	}
	return n;
}


void ListPrint(ListItem *head)
{
	ListItem *cur = head;

	cout << "List of Items:" << " ";

	while (cur != NULL)
	{
		cout << cur->n << " ";
		cur = cur->next;
	}
	cout << endl;
}
