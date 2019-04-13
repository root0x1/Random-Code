#include <string.h>
#include <stdio.h>
int IsGreater(char* strA, char* strB){
	int sumA = 0, sumB = 0;
	sumA += *strA;
	sumB += *strB;
	if(sumA < sumB) return -1;
	if(sumA > sumB) return 1;
	if(strcmp(strA, strB) == 0) return 0;
	if(*(strA++) && *(strB++))
		IsGreater(strA++, strB++);
}
char** Swap(char** List, int x, int y){
	char* tmp = List[x];
	List[x] = List[y];
	List[y] = tmp;
	return List;
}
void Sort(char** List, size_t len){
	for(int i = 1; i < len; i++)
		if(IsGreater(List[i], List[i-1]) == -1) Swap(List, i, i-1);
	if(len--) Sort(List, len--);
}
