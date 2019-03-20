#pragma once
#include <SFML/Graphics.hpp>

// Игрок
class Player
{
public:
	// Инициализация игроков
	void init(char who);

	// Анимация и движение 1 игрока вправо
	void moveRight_P1(float &frame, float &time);
	// Анимация и движение 1 игрока влево
	void moveLeft_P1(float &frame, float &time);
	// Анимация 1 игрока в состоянии бездействия
	void moveOnPlace_P1(float &frame, float &time);
	// Анимация атаки рукой 1 игрока
	void handAttack_P1(float &frame, float &time);
	// Анимация укуса 1 игрока
	void biteAttack_P1(float &frame, float &time);
	// Анимация и прыжок 1 игрока
	void jump_P1(float &frame, float &time, bool &fullJump);
	// Анимация смерти 1 игрока
	void die_P1(float &frame, float &time, bool &end);

	// Анимация 2 игрока в состоянии бездействия
	void moveOnPlace_P2(float &frame, float &time);
	// Анимация и движение 2 игрока влево
	void moveLeft_P2(float &frame, float &time);
	// Анимация и движение 2 игрока вправо
	void moveRight_P2(float &frame, float &time);
	// Анимация атаки рукой 2 игрока
	void handAttack_P2(float &frame, float &time);
	// Анимация стрельбы 2 игрока
	void shootingAttack_P2(float &frame, float &time);
	// Анимация прыжка 2 игрока
	void jump_P2(float &frame, float &time, bool &fullJump);
	// Анимация смерти 2 игрока
	void die_P2(float &frame, float &time, bool &end);

	// Спрайт персонажа
	sf::Sprite hero;
private:
	// Картинка персонажа
	sf::Image image;
	// Текстура персонажа
	sf::Texture texture;
};
