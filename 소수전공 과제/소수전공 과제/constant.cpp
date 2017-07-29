#include<iostream>
using namespace std;

//#define PI 3.1415926535897932384246
//
//namespace math{
//
//	int add(int a, int b){
//		return a + b;
//	}
//}
//int main(){
//	std::cout << PI << std::endl;
//}

const float PI = 3.14159265358979;

float get_area(const float radius){ //'const'를 붙이면 값을 수정할 수 없다.
	return radius*radius*PI;
}
int main(){
	float radius;
	cin >> radius;
	cout << get_area(radius) << endl;
}