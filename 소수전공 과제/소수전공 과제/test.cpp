#include<iostream>
#include<string>
using namespace std;

class Weapon{
public:
	Weapon(float weapon_damage, float weapon_speed)
		:weapon_damage(weapon_damage), weapon_speed(weapon_speed)
	{
	}
		float weapon_damage, weapon_speed;
};


class Player{
public:
	Player(float hp, float mp, float player_damage,string player_name, Weapon weapon)
		:hp(hp), mp(mp), player_damage(player_damage), player_name(player_name), weapon(weapon)
	{
		/*int a = 10;     //초기화하는 3가지 방법
		int a(10);
		int a{ 10 };*/
	}
	float hp, mp, player_damage;
	string player_name;
	Weapon weapon;

	void attack(Player& other)const
	{
		if (hp >= (player_damage + weapon.weapon_damage))
			other.hp -= player_damage + weapon.weapon_damage;
		else
			other.hp = 0;
		cout << other.player_name << "의 공격 후 체력: " << other.hp << endl;
		if (other.hp == 0)
			cout << other.player_name << "이 쓰러졌다." << endl;
	}

	void heal(Player& other)
	{
		other.hp += mp;
		mp = 0;
		cout << other.player_name << "의 회복 후 체력: " << other.hp <<endl;
	}
};

void main(){
	Weapon sword{ 100, 5 };
	Weapon gun{ 100, 100 };
	Player player1{ 100, 50, 10, "P1", sword};
	Player player2{ 100, 50, 10, "P2", gun };
	Player player3 = Player(100, 50, 10, "P3", sword);

	player1.attack(player2);
	player1.heal(player2);

}