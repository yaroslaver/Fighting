#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

// Окружение игры
class Environment
{
public:
	// Инициализация фона
	void initLocation();
	// Инициализация жизней персонажей
	void initHP();
	// Инициализация имен персонажей
	void initNames();
	// Получение урона персонажем
	void getDamage(char hero, char attack, bool &P_Win);
	// Устанавливает слова завершения боя
	void setFinish(int winner);
	// Устанавливает слова начала боя
	void setStart();
	// Инициализирует озвучку слов начала боя
	void initSoundStart();
	// Инициализирует озвучку слов конца боя
	void initSoundsFinal();
	// Инициализирует музыку
	void initMainMusic();

	// Жизни
	sf::RectangleShape HP_P1, HP_P2, NegHP_P1, NegHP_P2;
	// Слова начала, концовки и имена персонажей
	sf::Text startWords_lay1, startWords_lay2, name_P1, name_P2, finalWords_lay1, finalWords_lay2;
	// Спрайт фона
	sf::Sprite location;
	// Озвучка слов начала и конца боя, музыка
	sf::Music startWords, finalWords_version1, finalWords_version2, finalWord2, mainMusic;

private:
	// Картинка фона
	sf::Image image;
	// Текстура фона
	sf::Texture texture;
	// Шрифт имени 1 игрока
	sf::Font fontNameP1;
	// Шрифт имени 2 игрока
	sf::Font fontNameP2;
	// Шрифт финальны слов
	sf::Font finalFont;
	// Шрифт стартовых слов
	sf::Font startFont;
	// Уровень нанесенного урока 1 игрока
	int damageLevel_P1;
	// Уровень нанесенного урока 2 игрока
	int damageLevel_P2;
};
