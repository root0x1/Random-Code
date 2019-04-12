#include <stdio.h>
#include <stdlib.h>

struct List
{
	int data;
	struct List* next;
};

struct Linked
{
	struct List* head;
	struct List* tail;
};

struct Linked* InitList(struct Linked* link)
{
	if(link == NULL) return NULL;
	struct List* head = (struct List*)(malloc(sizeof(struct List*))), *tail = (struct List*)(malloc(sizeof(struct List*)));
	head->next = tail;
	link->head = head;
	tail->next = NULL;
	link->tail = tail;
	return link;
}
struct List* AddNode(struct Linked* link, struct List* list, int Data)
{
	struct List* node = (struct List*)(malloc(sizeof(struct List*)));
	node->data = Data;
	node->next = link->head->next;
	link->head->next = node;
	return node;
}

struct List* SearchData(struct List* list, int Data)
{
	for(; list && list->data != Data; list = list->next) ;
	return list;
}

struct List* RemoveNode(struct Linked* link, struct List* list, int Data)
{
	if(link->head == NULL) return NULL;
	if(link->head->data == Data)
	{
		struct List* _list = link->head->next;
		free(link->head);
		link->head = _list;
		return link->head;
	}

	if(link->tail->data == Data)
	{
		while(list != link->tail)
		{
			if(list->next == link->tail)
			{
				free(link->tail);
				list->next = NULL;
				link->tail = list;
				return link->tail;
			}
			else
				list = list->next;
		}

	}

	struct List* node = (struct List*)SearchData(list, Data);
	struct List* _list = (struct List*)(malloc(sizeof(struct List*)));
	if(node)
	{
		_list = node->next;
		free(node);
		link->head->next = _list;
		_list->next = _list->next->next;
		return _list;
	}
	else
		return NULL;
}
void FreeList(struct Linked* list)
{
	if(list == NULL) return;
	return free(list);
}
void PrintList(struct List* list)
{
	if(list == NULL) { printf("Empty List!\n"); exit(1); }
	while(list)
	{
		printf("Data: %i\n", list->data);
		list = list->next;
	}
	printf("\n");
}
struct List* ReverseList(struct List* head)
{
   	struct List* prev = NULL;
   	for(struct List *curr = head, *next = NULL; curr; curr = next)
   	{
   		next = curr->next;
   		curr->next = prev;
   		prev = curr;
   	}
   	return head = prev;
}
struct List* RTraverseList(struct List* head){
	struct List* node = ReverseList(head);
	PrintList(node);
	return head = ReverseList(node);
}
void InsertSortList(struct List* head)
{
	for(struct List* node = head->next; node; node = node->next){
		while(head->data > node->data){
			int tmp = head->data;
			head->data = node->data;
			node->data = tmp;
		}
	}
	return (head->next) ? InsertSortList(head->next) : NULL;
}
void SwitchList(struct List* A, struct List* B){
	struct List* tmp = A;
	A = B;
	B = tmp;
}
void PartitionList(struct Linked* Link){
	int piv = Link->tail->data, tmp = 0;
	struct List* list = Link->head, _list = Link->head->next;
	for(; list; list = list->next, tmp = list->data){
		tmp = list->data;
		if(tmp <= piv){
			SwitchList(list, )
		}
	}
}