#include<iostream>

struct PointData{  //�⺻�� �ۺ��� Ŭ����
	int x;
	int y;
}; 

class Point {
public:
	PointData data;
};

/*
class Point{
private: //�ƹ��͵� �� �� �Ͱ� �Ȱ���(������)
	int x;
	int y;

public: //(������)
	int z;

protected:
	//
};
*/
   
void main(){
	Point pt;
	pt.data.x;

}