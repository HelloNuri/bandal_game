#include<iostream>

using my_int = int;

//std::cout << "  ";
// :: - ���� ���� ������

//���� ���� - ������ ���� �� ����
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

	float distance(const Point& other)const;    	//other.x = 10;  - ���� const�� ���ؼ� ������ ����
													//this->x = 10;  - ���� const�� ���ؼ� ������ ����
};

//����� ���� �и�
float Point::distance(const Point& other)const
{
	return sqrt(pow(other.x - this->x, 2) + pow(other.y - this->y, 2)); //�򰥸��� ���ٸ� 'this->' ��������
}


void main(){
	Point p1 = { 0, 0 };
	Point p2 = { 1, 1 };
	Point p3 = { 2, 2 };
	std::cout << p1.distance(p2) << p1.distance(p3) << std::endl;
}

//�����Ϳ� ���۷����� ����

/*

void main(){
	Point pt = { 10, 20 };

	//�ƹ� ���� �� ���� ���·� ������ �� �ִ°�?

	//���۷���: �ٸ� ������ ����(�׻� ���ǹ��� �����͸� �����Ѿ� �ϴ� ���)
	//����Ű�� �ٸ� ������ ������ ������ �� ����
	Point & pt_ref;
	
	//������: ����Ű�� ���� �ʾƵ� ����(������� ���)
	Point * pt_ptr;


	//��� ������ ��� �ϴ°�?
	pt.x;        //����
	pt_ref.x;    //���۷���
	(*pt_ptr).x; //������: ȭ��ǥ�� ���� ��
	pt_ptr->x;   //������: ȭ��ǥ�� ���� ��
}

*/