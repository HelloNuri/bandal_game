#include<iostream>
#include<string>
using namespace std;

//struct Player{
//	float hp, mp, attack_damage;
//	string name;
//};

//Weapon 클래스 만들기
//멤버변수: 공격력, 공격속도
//멤버함수: 공격력과 공격속도를 초기화하는 생성자
class Weapon{
public:
	Weapon(float damage, float attack_speed)
		:damage(damage), attack_speed(attack_speed)
	{

	}
	float damage, attack_speed;

};

class Player{
public:
	//생성자(constructor)
	Player(float hp, float mp, float attack_damage, Weapon weapon, string name)
		:hp(hp), mp(mp), attack_damage(attack_damage), weapon(weapon), name(name)
	{	
		//const 위치에 따라
		//const가 앞에 있을 경우 포인터가 가르키는 값을 바꿀 수 없다.
		//const가 뒤에 있을 경우 포인터를 바꿀 수 없다.

		/*const Player* self1 = this;
		Player* const self2 = this;

		self1 = this;
		self2 = this;

		self1->hp = 0;
		self2->hp = 0;*/


		//this는 자기자신의 포인터

		/*this->hp = hp;
		this->mp = mp;
		this->attack_damage = attack_damage;
		this->name = name;*/
	}

	float hp, mp, attack_damage;
	Weapon weapon;
	string name;


	/*void attack(Player* other){			//'other->hp' = '*(other).hp'
		cout << "공격 전 " << other->name << "의 체력 : " << other->hp << endl;
		other->hp -= attack_damage;
		cout << attack_damage << "의 데미지를 주었다." << endl;
		cout << "공격 후 " << other->name << "의 체력 : " << other->hp << endl << endl;
	}
	*/

	void attack(Player& other)const     //'&'를 붙여 player2의 체력을 복사하지 않고 그대로 사용한다.
	{									//이곳에 'const'를 붙이면 자기 자신을 바꿀 수 없다.
										//따라서 this->hp = 3;가 불가능 하다.
		cout << "공격 전 " << other.name << "의 체력 : " << other.hp << endl;


		if ((attack_damage+weapon.damage)> hp)
			other.hp = 0;
		else
			other.hp -= attack_damage+weapon.damage;


		cout << attack_damage+weapon.damage << "의 데미지를 주었다." << endl;
		cout << "공격 후 " << other.name << "의 체력 : "<< other.hp << endl;
		if (other.hp == 0)
			cout << other.name << "이(가) 사망하였습니다." << endl << endl;
	}

	void heal(float heal_amount){
		//mp를 heal_amount만큼 줄이고 그만큼 hp를 회복한다.
		cout << "회복하기 전 체력: " << hp << endl;
		if (mp > heal_amount)
			mp -= heal_amount;
		else{
			heal_amount = mp;
			mp = 0;
		}
		hp += heal_amount;
		cout << "회복한 후 체력: " << hp << endl << endl;
	}
};

int main(){
	Weapon weapon(100, 50);
	Player player1(100,50,400, weapon,"P1");
	Player player2(300,10,10,weapon,"P2");

	//함수 오버로딩
	//C++에서는 함수이름이 같아도 매개변수가 다르면 매개변수에 따라 함수를 찾아 호출해준다.

	player1.attack(player2);	//레퍼런스 버전

//	player1.attack(&player2);	//포인터 버전

	player2.heal(5);

	//player1.attack_damage = 23423523;
	//player1.hp = 100000;
	//player1.mp = 100000;
	//player1.name = "abc";
	//player1.name.append("ghi");
	//
//	cout << player1.name << ' ' << player1.name.length() << endl;
}