#include<iostream>

struct PointData{  //기본이 퍼블릭인 클래스
	int x;
	int y;
}; 

class Point {
public:
	PointData data;
};

/*
class Point{
private: //아무것도 안 쓴 것과 똑같다(개인의)
	int x;
	int y;

public: //(대중의)
	int z;

protected:
	//
};
*/
   
void main(){
	Point pt;
	pt.data.x;

}