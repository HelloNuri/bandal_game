#include<iostream>
#include<string>

using namespace std;
class Player;    // 전방선언 - 원래 class Monster에서 Player 클래스를 쓰기 위해 순서가 바뀌어야 하지만
				// 전방선언을 해서 레퍼런스를 쓸 때 에러를 방지한다고 배웠지만 아님 고로 전방선언을 하고 포인터를 써야함

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
			cout << name << "은 죽었다." << endl << endl;
		else
			cout << name << "은 살아있다." << endl << endl;

	}
	//이 부분부터 주석친걸 매개변수를 레퍼런스에서 포인터로 바꿔야 하는듯
	//void attack(Player& other)const
	//{
	//	if (other.hp < damage) {
	//		other.hp = 0;
	//	}
	//	else
	//		other.hp -= damage;
	//	cout << "공격으로 "<< damage << "의 피해를 입었다." << endl;
	//	cout << other.name << "의 체력: " << other.hp << endl;
	//	if (other.hp == 0)
	//		cout << other.name << "은 쓰러졌다." << endl << endl;
	//}

	//void rush(Player& other)
	//	{
	//		if (other.hp < damage*2) {
	//			other.hp = 0;
	//		}
	//		else
	//			other.hp -= damage*2;
	//		hp -= damage / 2;
	//		cout << "돌진으로 "<< damage*2 << "의 피해를 입었다." << endl;
	//		cout << "반동으로 " << name << "은 " << damage / 2 << "의 피해를 입었다." << endl;
	//		cout << other.name << "의 체력: " << other.hp << endl;
	//		cout << name << "의 체력: " << hp << endl << endl;
	//		if (other.hp == 0)
	//			cout << other.name << "는 쓰러졌다." << endl << endl;
	//		if(hp == 0)
	//			cout << name << "는 쓰러졌다." << endl << endl;
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
			cout << name << "는 죽었다." << endl << endl;
		else
			cout << name << "는 살아있다." << endl << endl;

	}

		void attack(Monster& other)const
		{
			if (other.hp < damage) {
				other.hp = 0;
			}
			else
				other.hp -= damage;
			cout << "일반공격으로 " << damage << "의 피해를 주었다." << endl;
			cout << other.name << "의 체력: " << other.hp << endl << endl;;
			if (other.hp == 0)
				cout << other.name << "은 쓰러졌다." << endl << endl;
		}
	
		void magic_attack(Monster& other)
		{
			if ((mp - 10) < 0) {
				cout << "마나가 부족합니다." << endl;
				return;
			}
			if (other.hp < (damage + 10)) {
				other.hp = 0;
			}
			else
				other.hp -= damage + 10;
			mp -= 10;
			cout << "마법공격으로 " << damage + 10 << "의 피해를 주었다." << endl;
			cout << other.name << "의 체력: " << other.hp << endl;
			cout << "남은 마나: " << mp << endl << endl;
			if (other.hp == 0)
				cout << other.name << "은 쓰러졌다." << endl << endl;
		}
};

void main() {
	Monster mob1{ 50, 10, "슬라임" };
	Player P1{ 100, 40, 10, "마법사" };


	P1.magic_attack(mob1);
	mob1.is_dead();

	P1.attack(mob1);
	mob1.is_dead();

	P1.magic_attack(mob1);
	mob1.is_dead();

	if (mob1.hp == 0)
		cout << P1.name << "가 승리했다." << endl << endl;
	else if(P1.hp == 0)
		cout << mob1.name << "이 승리했다." << endl << endl;

}