#include <iostream>
using namespace std;

void inputHpMp(int* status)
{
	while (1)
	{
		cout << "입력 HP : " << endl;
		cin >> status[0];
		cout << "입력 MP : " << endl;
		cin >> status[1];
		if (status[0] <= 50 || status[1] <= 50)
		{
			cout << "50이상의 값을 입력해주세요." << endl;
		}
		else break;
	}
	cout << "HP : " << status[0] << ", MP : " << status[1] << endl;
	return;
}

void inputAtkDef(int* status)
{
	while (1)
	{
		cout << "입력 ATK : " << endl;
		cin >> status[2];
		cout << "입력 DEF : " << endl;
		cin >> status[3];
		if (status[2] <= 0 || status[3] <= 0)
		{
			cout << "0이상의 값을 입력해주세요." << endl;
		}
		else break;
	}
	cout << "ATK : " << status[2] << ", DEF : " << status[3] << endl;
	return;
}

void inputStrDexInt(int* status)
{
	while (1)
	{
		cout << "입력 STR : " << endl;
		cin >> status[4];
		cout << "입력 DEX : " << endl;
		cin >> status[5];
		cout << "입력 INT : " << endl;
		cin >> status[6];
		if (status[4] <= 20 || status[5] <= 20 || status[6] <= 20)
		{
			cout << "20이상의 값을 입력해주세요." << endl;
		}
		else break;
	}
	cout << "STR : " << status[4] << ", DEX : " << status[5] << ", INT : " << status[6] << endl;
	return;
}

void setPotion(int count, int& p_HPPotion, int& p_MPPotion)
{
	p_HPPotion = count;
	p_MPPotion = count;
}

void hpUp(int* status, int& p_HPPotion)
{
	if (p_HPPotion <= 0)
	{
		cout << "HP포션이 부족하여 사용 할 수 없습니다." << endl;
	}
	else
	{
		cout << "HP가 20 증가했습니다. 포션이 1개 차감됩니다." << endl;
		status[0] += 20;
		p_HPPotion -= 1;
		cout << "현재 HP : " << status[0] << endl;
		cout << "남은 HP포션 수 : " << p_HPPotion << endl;
	}
}

void mpUp(int* status, int& p_MPPotion)
{
	if (p_MPPotion <= 0)
	{
		cout << "MP포션이 부족하여 사용 할 수 없습니다." << endl;
	}
	else
	{
		cout << "MP가 20 증가했습니다. 포션이 1개 차감됩니다." << endl;
		status[1] += 20;
		p_MPPotion -= 1;
		cout << "현재 MP : " << status[1] << endl;
		cout << "남은 MP포션 수 : " << p_MPPotion << endl;
	}
}

void atkUp(int* status)
{
	status[2] *= 2;
	cout << "공격력이 2배 증가했습니다 " << endl;
	cout << "현재 공격력 : " << status[2] << endl;
}

void defUp(int* status)
{
	status[3] *= 2;
	cout << "방어력이 2배 증가했습니다 " << endl;
	cout << "현재 방어력: " << status[3] << endl;
}

void strUp(int* status)
{
	status[4] *= 3;
	cout << "힘이 3배 증가했습니다." << endl;
	cout << "현재 STR : " << status[4] << endl;
}

void dexUp(int* status)
{
	status[5] *= 3;
	cout << "민첩이 3배 증가했습니다." << endl;
	cout << "현재 DEX : " << status[5] << endl;
}

void intUp(int* status)
{
	status[6] *= 3;
	cout << "지능이 3배 증가했습니다." << endl;
	cout << "현재 INT : " << status[6] << endl;
}

void nowAblity(int* status, int& ref_HpPotion, int& ref_MpPotion, int& ref_CurrentLevel)
{
	cout << "HP : " << status[0] << ", MP : " << status[1]
		<< ", ATK : " << status[2] << ", DEF : " << status[3]
		<< ", STR : " << status[4] << ", DEX : " << status[5]
		<< ", INT : " << status[6]
		<< ", 현재 레벨 : " << ref_CurrentLevel << endl;
	cout << "현재 HP 포션 : " << ref_HpPotion << ", 현재 MP포션 : " << ref_MpPotion << endl;
}

void potionCharge(int& p_HPPotion, int& p_MPPotion)
{
	p_HPPotion += 1;
	p_MPPotion += 1;
	if (p_HPPotion > 5) p_HPPotion = 5;
	if (p_MPPotion > 5) p_MPPotion = 5;
}

void levelUp(int& p_HPPotion, int& p_MPPotion, int& levelUpCheck, int& currentLevel)
{
	levelUpCheck += 1;
	if (levelUpCheck == 6)
	{
		currentLevel += 1;
		levelUpCheck = 0;
		cout << "레벨업! , 현재 레벨 : " << currentLevel << endl;
	}
	potionCharge(p_HPPotion, p_MPPotion);
	cout << "HP,MP Potion" << endl;
	cout << "남은 HP/MP 포션 수 : " << p_HPPotion << "/" << p_MPPotion << endl;
}

int main()
{
	int status[7] = { 0,0,0,0,0,0,0 };
	int hpPotion = 0;
	int mpPotion = 0;
	int currentLevel = 0;
	int levelUpCheck = 0;
	cout << "HP와 MP를 입력하세요 : " << endl;
	inputHpMp(status);
	cout << "ATK와 DEF를 입력하세요 : " << endl;
	inputAtkDef(status);
	cout << "STR, DEX, INT를 입력하세요 : " << endl;
	inputStrDexInt(status);
	cout << "포션이 지급되었습니다. (HP,MP 포션 각 5개)" << endl;
	setPotion(5, hpPotion, mpPotion);
	int num = 1;
	while (num != 0)
	{
		cout << "==============================" << endl;
		cout << "스탯 관리 시스템" << endl;
		cout << "1. Hp UP" << endl;
		cout << "2. Mp UP" << endl;
		cout << "3. Atk UP" << endl;
		cout << "4. Def UP" << endl;
		cout << "5. Now Ablity" << endl;
		cout << "6. Level Up" << endl;
		cout << "7. STR Up" << endl;
		cout << "8. DEX Up" << endl;
		cout << "9. INT Up" << endl;
		cout << "0. Exit" << endl;
		cin >> num;
		switch (num)
		{
		case 1: hpUp(status, hpPotion);
			break;
		case 2: mpUp(status, mpPotion);
			break;
		case 3: atkUp(status);
			break;
		case 4: defUp(status);
			break;
		case 5: nowAblity(status, hpPotion, mpPotion, currentLevel);
			break;
		case 6: levelUp(hpPotion, mpPotion, levelUpCheck, currentLevel);
			break;
		case 7: strUp(status);
			break;
		case 8: dexUp(status);
			break;
		case 9: intUp(status);
			break;
		case 0: cout << "프로그램을 종료합니다." << endl;
			break;
		}

	}
}