#include<stdio.h>

//void swap(int *a, int *b){
//	int tmp = *a;
//	*a = *b;
//	*b = tmp;
//}
//
//void load_savefile(int* num){
//	*num = 100;
//}
//
//int main(){
//	int player_hp = 0;
//
//	printf("%d\n", player_hp);
//	load_savefile(&player_hp);
//	printf("%d\n", player_hp);
//
//	return 0;
//}

//int main(){
//	int arr[3] = { 1, 2, 3 };
//
//	printf("%d\n", arr);
//	printf("%d\n", *arr);
//	printf("%d\n", arr[0]);
//	printf("%d\n", arr + 1);
//	printf("%d\n", *(arr+1));
//	printf("%d\n", arr[1]);
//
//	return 0;
//}

//int get_string_length1(char* str){
//	int len = 0;
//	while (*str != NULL){
//		str++;
//		len++;
//	}
//	return len;
//}
//
//int get_string_length2(char* str){
//	int len =0;
//	for (; *str++ != NULL; len++);
//	return len;
//}
//
//int get_string_length3(char* str){
//	char* start = str;
//	while (*str++ != NULL);
//	return str - start -1;
//}
//
//int main(){
//	char asdf[] = "asdf";
//	printf("%d\n", get_string_length1(asdf));
//	printf("%d\n", get_string_length2(asdf));
//	printf("%d\n", get_string_length3(asdf));
//
//	return 0;
//}

//int find_char_index(char* str, char c){
//	int index = 1;
//	while (*str != NULL){
//		if (*str == c)
//			return index;
//		index++;
//		str++;
//	}
//	return -1;
//}
//
//int main(){
//	char str[] = "ABCDEF";
//
//	printf("%d\n", find_char_index(str, 'A'));
//	printf("%d\n", find_char_index(str, 'D'));
//	printf("%d\n", find_char_index(str, 'X'));
//	return 0;
//}

//bool is_string_equal1(char* str1, char* str2){
//
//	while (*str1 != NULL||*str2 != NULL){
//		if (*str1 != *str2)
//			return false;
//		else{
//			str1++;
//			str2++;
//		}
//	}
//	return true;
//}
//
//bool is_string_equal2(char* str1, char* str2){
//
//	while (*str1++ == *str2++){
//		if (*str1 == NULL && *str2 == NULL)
//			return true;
//	}
//	return false;
//}
//
//int main(){
//	char s1[] = "ABCDEF";
//	char s2[] = "ABCDEF";
//	char s3[] = "XYZ";
//	char s4[] = "ABC";
//
//	printf("%d\n", is_string_equal1(s1, s2));
//	printf("%d\n", is_string_equal2(s1, s3));
//	printf("%d\n", is_string_equal1(s1, s4));
//	printf("%d\n", is_string_equal2(s4, s1));
//}

//void reverse_string1(char* str){
//	int n = 0, tmp;
//	while (*str != NULL){
//		str++;
//		n++;
//	}
//	str = str - n;
//	for (int i = 0; i < n / 2; i++){
//		tmp = *(str + i);
//		*(str + i) = *(str + (n - i-1));
//		*(str + (n - i-1)) = tmp;
//	}
//}
//
//void reverse_string2(char* str){
//	char* start = str;
//	char* end = str;
//	while (*end != NULL)
//		end++;
//	end--;
//
//	while (start < end){
//		char tmp = *start;
//		*start = *end;
//		*end = tmp;
//
//		start++;
//		end--;
//	}
//}
//
//void main(){
//	char str[] = "ABCDEF";
//
//	reverse_string1(str);
//	printf("%s\n", str);
//
//	reverse_string2(str);
//	printf("%s\n", str);
//}