#pragma once
#include <SFML/Graphics.hpp>

// �����
class Player
{
public:
	// ������������� �������
	void init(char who);

	// �������� � �������� 1 ������ ������
	void moveRight_P1(float &frame, float &time);
	// �������� � �������� 1 ������ �����
	void moveLeft_P1(float &frame, float &time);
	// �������� 1 ������ � ��������� �����������
	void moveOnPlace_P1(float &frame, float &time);
	// �������� ����� ����� 1 ������
	void handAttack_P1(float &frame, float &time);
	// �������� ����� 1 ������
	void biteAttack_P1(float &frame, float &time);
	// �������� � ������ 1 ������
	void jump_P1(float &frame, float &time, bool &fullJump);
	// �������� ������ 1 ������
	void die_P1(float &frame, float &time, bool &end);

	// �������� 2 ������ � ��������� �����������
	void moveOnPlace_P2(float &frame, float &time);
	// �������� � �������� 2 ������ �����
	void moveLeft_P2(float &frame, float &time);
	// �������� � �������� 2 ������ ������
	void moveRight_P2(float &frame, float &time);
	// �������� ����� ����� 2 ������
	void handAttack_P2(float &frame, float &time);
	// �������� �������� 2 ������
	void shootingAttack_P2(float &frame, float &time);
	// �������� ������ 2 ������
	void jump_P2(float &frame, float &time, bool &fullJump);
	// �������� ������ 2 ������
	void die_P2(float &frame, float &time, bool &end);

	// ������ ���������
	sf::Sprite hero;
private:
	// �������� ���������
	sf::Image image;
	// �������� ���������
	sf::Texture texture;
};
