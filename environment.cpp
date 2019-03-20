#include "environment.h"
#include <SFML/Graphics.hpp>

void Environment::initLocation()
{
	image.loadFromFile("image/Mall.png");
	texture.loadFromImage(image);
	location.setTexture(texture);
	location.setTextureRect(sf::IntRect(10, 1040, 765, 465));
	location.scale(2.5, 2.1);
	location.setPosition(0, 0);
}

void Environment::initHP()
{
	HP_P1.setFillColor(sf::Color::Red);
	HP_P1.setPosition(10, 15);
	sf::Vector2f rectSize1;
	rectSize1.x = 800;
	rectSize1.y = 40;
	HP_P1.setSize(rectSize1);
	HP_P1.setOutlineThickness(5);
	HP_P1.setOutlineColor(sf::Color::Black);

	NegHP_P1.setFillColor(sf::Color::White);
	NegHP_P1.setPosition(810, 15);
	sf::Vector2f rectSize1_1;
	rectSize1_1.x = 0;
	rectSize1_1.y = 40;
	NegHP_P1.setSize(rectSize1_1);
	NegHP_P1.setOrigin(0, 0);
	NegHP_P1.setOutlineThickness(0);
	NegHP_P1.setOutlineColor(sf::Color::Black);
	damageLevel_P1 = 0;


	HP_P2.setFillColor(sf::Color::Red);
	HP_P2.setPosition(1100, 15);
	sf::Vector2f rectSize2;
	rectSize2.x = 800;
	rectSize2.y = 40;
	HP_P2.setSize(rectSize2);
	HP_P2.setOutlineThickness(5);
	HP_P2.setOutlineColor(sf::Color::Black);

	NegHP_P2.setFillColor(sf::Color::White);
	NegHP_P2.setPosition(1100, 15);
	sf::Vector2f rectSize2_1;
	rectSize2_1.x = 0;
	rectSize2_1.y = 40;
	NegHP_P2.setSize(rectSize2_1);
	NegHP_P2.setOutlineThickness(0);
	NegHP_P2.setOutlineColor(sf::Color::Black);
	damageLevel_P2 = 0;

}

void Environment::initNames()
{
	if (!fontNameP1.loadFromFile("fonts/venom2.ttf"))
	{
		throw std::invalid_argument("Font is not load!");
	}
	name_P1.setFont(fontNameP1);
	name_P1.setString("Venom");
	name_P1.setCharacterSize(75);
	name_P1.setFillColor(sf::Color::Black);
	name_P1.setPosition(10, 55);

	if (!fontNameP2.loadFromFile("fonts/dead.ttf"))
	{
		throw std::invalid_argument("Font is not load!");
	}
	name_P2.setFont(fontNameP2);
	name_P2.setString("Deadpool");
	name_P2.setCharacterSize(75);
	name_P2.setFillColor(sf::Color::Black);
	name_P2.setPosition(1675, 55);
}

void Environment::getDamage(char hero, char attack, bool &P_Win)
{
	sf::Vector2f rectSize;
	if (hero == 'v')
	{
		if (attack == 'h')
		{
			damageLevel_P1 += 2;
		}
		if (attack == 's')
		{
			damageLevel_P1 += 1;
		}
		if (damageLevel_P1 > 800)
		{
			damageLevel_P1 = 800;
			P_Win = true;
		}
		rectSize.x = damageLevel_P1;
		rectSize.y = 40;
		NegHP_P1.setSize(rectSize);
		NegHP_P1.setOrigin(rectSize.x, 0);
		NegHP_P1.setOutlineThickness(5);
	}

	if (hero == 'd')
	{
		if (attack == 'h')
		{
			damageLevel_P2 += 2;
		}
		if (attack == 'b')
		{
			damageLevel_P2 += 2;
		}
		if (damageLevel_P2 > 800)
		{
			damageLevel_P2 = 800;
			P_Win = true;
		}
		rectSize.x = damageLevel_P2;
		rectSize.y = 40;
		NegHP_P2.setSize(rectSize);
		NegHP_P2.setOutlineThickness(5);
	}

	if (hero != 'd' && hero != 'v')
	{
		throw std::invalid_argument("Argument must be v(Venom) of d(Deadpool)");
	}
}

void Environment::setFinish(int winner)
{
	if (!finalFont.loadFromFile("fonts/fight2.otf"))
	{
		throw std::invalid_argument("Font is not load!");
	}
	if (winner != 1 && winner != 2)
	{
		throw std::invalid_argument("Number of winners should be 1 or 2");
	}
	finalWords_lay1.setFont(finalFont);
	if (winner == 1)
	{
		finalWords_lay1.setString("K.O.");
	}
	else
	{
		finalWords_lay1.setString("Losers");
	}
	finalWords_lay1.setCharacterSize(400);
	finalWords_lay2 = finalWords_lay1;
	finalWords_lay1.setPosition(700, 300);
	finalWords_lay2.setPosition(695, 295);
	finalWords_lay1.setFillColor(sf::Color::Red);
	finalWords_lay2.setFillColor(sf::Color::Black);
}

void Environment::setStart()
{
	if (!startFont.loadFromFile("fonts/fight2.otf"))
	{
		throw std::invalid_argument("Font is not load!");
	}
	startWords_lay1.setFont(startFont);
	
	startWords_lay1.setString("Fight");
	startWords_lay1.setCharacterSize(400);
	startWords_lay2 = startWords_lay1;
	startWords_lay1.setPosition(700, 300);
	startWords_lay2.setPosition(695, 295);
	startWords_lay1.setFillColor(sf::Color::Red);
	startWords_lay2.setFillColor(sf::Color::Black);
}

void Environment::initSoundsFinal()
{
	
	if (!finalWords_version1.openFromFile("sounds/K.O.ogg"))
	{
		throw std::invalid_argument("File is incorrect!");
	}
	
	if (!finalWords_version2.openFromFile("sounds/losers.ogg"))
	{
		throw std::invalid_argument("File is incorrect!");
	}

	if (!finalWord2.openFromFile("sounds/fatality.ogg"))
	{
		throw std::invalid_argument("File is incorrect!");
	}
}

void Environment::initSoundStart()
{
	if (!startWords.openFromFile("sounds/fight.ogg"))
	{
		throw std::invalid_argument("File is incorrect!");
	}
}

void Environment::initMainMusic()
{
	if (!mainMusic.openFromFile("sounds/Mortal Kombat – Main Theme.ogg"))
	{
		throw std::invalid_argument("File is incorrect!");
	}
	mainMusic.setLoop(true);
	mainMusic.setVolume(25);
}
