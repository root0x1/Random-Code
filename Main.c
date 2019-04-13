#include <stdio.h>
#define LESS_RANGE -1
int* Swap(int* List, int x, int y){
	int tmp = List[x];
	List[x] = List[y];
	List[y] = tmp;
	return List;
}
void Sort(int* List, size_t len){
	for(int i = 1; i < len; i++)
		if(List[i] < List[i-1]) Swap(List, i, i-1);
	if(len--) Sort(List, len--);
	return;
}
int Merge(int* ListA, size_t lenA, int* ListB, size_t lenB, int* Merged, size_t lenM, _Bool Sorted){
	if(lenM < lenB || lenM < lenA || lenM < lenA+lenB) return LESS_RANGE;
	if(Sorted == 0) {Sort(ListA, lenA); Sort(ListB, lenB);}
	size_t i = 0, j = 0;
	for(; i < lenA; i++)
		Merged[i] = ListA[i];
	for(; j < lenB; j++, i++)
		Merged[i] = ListB[j];
	Sort(Merged, lenM);
	return 0;
}