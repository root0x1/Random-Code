int* Swap(int* List, int x, int y){
	int tmp = List[x];
	List[x] = List[y];
	List[y] = tmp;
	return List;
}
int Search(int *List, size_t len, int piv){
	for(int i = 0; i < len; i++)
		if(List[i] == piv) return i;
}
int Partition(int* List, size_t len){
	int pivot = List[len-1], idx = len-1, i = 0, size = len;
	for(; i+1 < size; i++){
		if(List[i] <= pivot) ;
		if(List[i] > pivot) Swap(List, i, i+1);
	}
	if(size--) Partition(List, size--);
	return Search(List, len, pivot);
}