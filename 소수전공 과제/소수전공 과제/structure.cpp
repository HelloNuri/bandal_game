#include<iostream>
#include<string>
using namespace std;

//struct Player{
//	float hp, mp, attack_damage;
//	string name;
//};

//Weapon Ŭ���� �����
//�������: ���ݷ�, ���ݼӵ�
//����Լ�: ���ݷ°� ���ݼӵ��� �ʱ�ȭ�ϴ� ������
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
	//������(constructor)
	Player(float hp, float mp, float attack_damage, Weapon weapon, string name)
		:hp(hp), mp(mp), attack_damage(attack_damage), weapon(weapon), name(name)
	{	
		//const ��ġ�� ����
		//const�� �տ� ���� ��� �����Ͱ� ����Ű�� ���� �ٲ� �� ����.
		//const�� �ڿ� ���� ��� �����͸� �ٲ� �� ����.

		/*const Player* self1 = this;
		Player* const self2 = this;

		self1 = this;
		self2 = this;

		self1->hp = 0;
		self2->hp = 0;*/


		//this�� �ڱ��ڽ��� ������

		/*this->hp = hp;
		this->mp = mp;
		this->attack_damage = attack_damage;
		this->name = name;*/
	}

	float hp, mp, attack_damage;
	Weapon weapon;
	string name;


	/*void attack(Player* other){			//'other->hp' = '*(other).hp'
		cout << "���� �� " << other->name << "�� ü�� : " << other->hp << endl;
		other->hp -= attack_damage;
		cout << attack_damage << "�� �������� �־���." << endl;
		cout << "���� �� " << other->name << "�� ü�� : " << other->hp << endl << endl;
	}
	*/

	void attack(Player& other)const     //'&'�� �ٿ� player2�� ü���� �������� �ʰ� �״�� ����Ѵ�.
	{									//�̰��� 'const'�� ���̸� �ڱ� �ڽ��� �ٲ� �� ����.
										//���� this->hp = 3;�� �Ұ��� �ϴ�.
		cout << "���� �� " << other.name << "�� ü�� : " << other.hp << endl;


		if ((attack_damage+weapon.damage)> hp)
			other.hp = 0;
		else
			other.hp -= attack_damage+weapon.damage;


		cout << attack_damage+weapon.damage << "�� �������� �־���." << endl;
		cout << "���� �� " << other.name << "�� ü�� : "<< other.hp << endl;
		if (other.hp == 0)
			cout << other.name << "��(��) ����Ͽ����ϴ�." << endl << endl;
	}

	void heal(float heal_amount){
		//mp�� heal_amount��ŭ ���̰� �׸�ŭ hp�� ȸ���Ѵ�.
		cout << "ȸ���ϱ� �� ü��: " << hp << endl;
		if (mp > heal_amount)
			mp -= heal_amount;
		else{
			heal_amount = mp;
			mp = 0;
		}
		hp += heal_amount;
		cout << "ȸ���� �� ü��: " << hp << endl << endl;
	}
};

int main(){
	Weapon weapon(100, 50);
	Player player1(100,50,400, weapon,"P1");
	Player player2(300,10,10,weapon,"P2");

	//�Լ� �����ε�
	//C++������ �Լ��̸��� ���Ƶ� �Ű������� �ٸ��� �Ű������� ���� �Լ��� ã�� ȣ�����ش�.

	player1.attack(player2);	//���۷��� ����

//	player1.attack(&player2);	//������ ����

	player2.heal(5);

	//player1.attack_damage = 23423523;
	//player1.hp = 100000;
	//player1.mp = 100000;
	//player1.name = "abc";
	//player1.name.append("ghi");
	//
//	cout << player1.name << ' ' << player1.name.length() << endl;
}