#include<iostream>
#include<string>

using namespace std;
class Player;    // ���漱�� - ���� class Monster���� Player Ŭ������ ���� ���� ������ �ٲ��� ������
				// ���漱���� �ؼ� ���۷����� �� �� ������ �����Ѵٰ� ������� �ƴ� ��� ���漱���� �ϰ� �����͸� �����

class Monster {
public:
	Monster(float hp, float damage, string name)
		:hp(hp), damage(damage), name(name)
	{
	}

	float hp;
	float damage;
	string name;

	void is_dead()const
	{
		if (hp == 0)
			cout << name << "�� �׾���." << endl << endl;
		else
			cout << name << "�� ����ִ�." << endl << endl;

	}
	//�� �κк��� �ּ�ģ�� �Ű������� ���۷������� �����ͷ� �ٲ�� �ϴµ�
	//void attack(Player& other)const
	//{
	//	if (other.hp < damage) {
	//		other.hp = 0;
	//	}
	//	else
	//		other.hp -= damage;
	//	cout << "�������� "<< damage << "�� ���ظ� �Ծ���." << endl;
	//	cout << other.name << "�� ü��: " << other.hp << endl;
	//	if (other.hp == 0)
	//		cout << other.name << "�� ��������." << endl << endl;
	//}

	//void rush(Player& other)
	//	{
	//		if (other.hp < damage*2) {
	//			other.hp = 0;
	//		}
	//		else
	//			other.hp -= damage*2;
	//		hp -= damage / 2;
	//		cout << "�������� "<< damage*2 << "�� ���ظ� �Ծ���." << endl;
	//		cout << "�ݵ����� " << name << "�� " << damage / 2 << "�� ���ظ� �Ծ���." << endl;
	//		cout << other.name << "�� ü��: " << other.hp << endl;
	//		cout << name << "�� ü��: " << hp << endl << endl;
	//		if (other.hp == 0)
	//			cout << other.name << "�� ��������." << endl << endl;
	//		if(hp == 0)
	//			cout << name << "�� ��������." << endl << endl;
	//
	//	}
};


class Player {
public:
	Player(float hp, float mp, float damage, string name)
		:hp(hp), mp(mp), damage(damage), name(name)
	{}

	float hp;
	float mp;
	float damage;
	string name;

	void is_dead()const
	{
		if (this->hp == 0)
			cout << name << "�� �׾���." << endl << endl;
		else
			cout << name << "�� ����ִ�." << endl << endl;

	}

		void attack(Monster& other)const
		{
			if (other.hp < damage) {
				other.hp = 0;
			}
			else
				other.hp -= damage;
			cout << "�Ϲݰ������� " << damage << "�� ���ظ� �־���." << endl;
			cout << other.name << "�� ü��: " << other.hp << endl << endl;;
			if (other.hp == 0)
				cout << other.name << "�� ��������." << endl << endl;
		}
	
		void magic_attack(Monster& other)
		{
			if ((mp - 10) < 0) {
				cout << "������ �����մϴ�." << endl;
				return;
			}
			if (other.hp < (damage + 10)) {
				other.hp = 0;
			}
			else
				other.hp -= damage + 10;
			mp -= 10;
			cout << "������������ " << damage + 10 << "�� ���ظ� �־���." << endl;
			cout << other.name << "�� ü��: " << other.hp << endl;
			cout << "���� ����: " << mp << endl << endl;
			if (other.hp == 0)
				cout << other.name << "�� ��������." << endl << endl;
		}
};

void main() {
	Monster mob1{ 50, 10, "������" };
	Player P1{ 100, 40, 10, "������" };


	P1.magic_attack(mob1);
	mob1.is_dead();

	P1.attack(mob1);
	mob1.is_dead();

	P1.magic_attack(mob1);
	mob1.is_dead();

	if (mob1.hp == 0)
		cout << P1.name << "�� �¸��ߴ�." << endl << endl;
	else if(P1.hp == 0)
		cout << mob1.name << "�� �¸��ߴ�." << endl << endl;

}