#include<iostream>

using my_int = int;

//std::cout << "  ";
// :: - 범위 지정 연산자

//전방 선언 - 에러를 피할 수 있음
struct Point;
void add(int, int);


class Rectangle{
public:
	Point top_left;
	Point bottom_right;
};

struct Point{
	int x;
	int y;

	float distance(const Point& other)const;    	//other.x = 10;  - 앞의 const를 통해서 수정을 막음
													//this->x = 10;  - 뒤의 const를 통해서 수정을 막음
};

//선언과 정의 분리
float Point::distance(const Point& other)const
{
	return sqrt(pow(other.x - this->x, 2) + pow(other.y - this->y, 2)); //헷갈릴게 없다면 'this->' 생략가능
}


void main(){
	Point p1 = { 0, 0 };
	Point p2 = { 1, 1 };
	Point p3 = { 2, 2 };
	std::cout << p1.distance(p2) << p1.distance(p3) << std::endl;
}

//포인터와 레퍼런스의 차이

/*

void main(){
	Point pt = { 10, 20 };

	//아무 값도 안 가진 상태로 존재할 수 있는가?

	//레퍼런스: 다른 변수의 별명(항상 유의미한 데이터를 가리켜야 하는 경우)
	//가리키는 다른 변수가 없으면 존재할 수 없음
	Point & pt_ref;
	
	//포인터: 가리키고 있지 않아도 존재(상관없을 경우)
	Point * pt_ptr;


	//멤버 접근을 어떻게 하는가?
	pt.x;        //원본
	pt_ref.x;    //레퍼런스
	(*pt_ptr).x; //포인터: 화살표가 없을 때
	pt_ptr->x;   //포인터: 화살표가 있을 때
}

*/