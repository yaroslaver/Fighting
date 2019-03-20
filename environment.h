#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

// ��������� ����
class Environment
{
public:
	// ������������� ����
	void initLocation();
	// ������������� ������ ����������
	void initHP();
	// ������������� ���� ����������
	void initNames();
	// ��������� ����� ����������
	void getDamage(char hero, char attack, bool &P_Win);
	// ������������� ����� ���������� ���
	void setFinish(int winner);
	// ������������� ����� ������ ���
	void setStart();
	// �������������� ������� ���� ������ ���
	void initSoundStart();
	// �������������� ������� ���� ����� ���
	void initSoundsFinal();
	// �������������� ������
	void initMainMusic();

	// �����
	sf::RectangleShape HP_P1, HP_P2, NegHP_P1, NegHP_P2;
	// ����� ������, �������� � ����� ����������
	sf::Text startWords_lay1, startWords_lay2, name_P1, name_P2, finalWords_lay1, finalWords_lay2;
	// ������ ����
	sf::Sprite location;
	// ������� ���� ������ � ����� ���, ������
	sf::Music startWords, finalWords_version1, finalWords_version2, finalWord2, mainMusic;

private:
	// �������� ����
	sf::Image image;
	// �������� ����
	sf::Texture texture;
	// ����� ����� 1 ������
	sf::Font fontNameP1;
	// ����� ����� 2 ������
	sf::Font fontNameP2;
	// ����� �������� ����
	sf::Font finalFont;
	// ����� ��������� ����
	sf::Font startFont;
	// ������� ����������� ����� 1 ������
	int damageLevel_P1;
	// ������� ����������� ����� 2 ������
	int damageLevel_P2;
};
