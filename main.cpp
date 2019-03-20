#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "Player.h"
#include "controlvariables.h"
#include "environment.h"


int main()
{

	sf::RenderWindow window(sf::VideoMode(1920, 1080), "Fighting!");


	Environment environment;
	environment.initLocation();
	
	Player venom, deadpool;
	venom.init('v');
	deadpool.init('d');
	environment.initSoundStart();
	environment.initSoundsFinal();
	environment.initMainMusic();
	

	sf::Clock clock;

	ControlVariables controlVar;

	environment.initHP();
	environment.initNames();

	environment.mainMusic.play();

	while (window.isOpen())
	{
		if (!controlVar.start)
		{
			environment.startWords.play();
		}
		if (controlVar.end)
		{
			if (controlVar.P1_Win && controlVar.P2_Win)
			{
				environment.finalWords_version2.play();
			}
			else
			{
				environment.finalWords_version1.play();
			}
		}

		// Получаем время и сбрасываем часы
		float time = clock.getElapsedTime().asMicroseconds();
		clock.restart();
		time /= 3000;

		// Обнуляем кадры
		controlVar.resetHitMove();

		// Устанавливаем слова начала поединка
		environment.setStart();

		// Закрытие окна по ESC или крестику на окне
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed || sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
			{
				window.close();
			}
		}

		// Если игрок 1 выиграл или бой не начался
		if (!controlVar.P2_Win || !controlVar.start)
		{
			// Состояние бездействия Венома
			venom.moveOnPlace_P1(controlVar.frame_P1, time);
		}

		// Если игрок 2 выиграл или бой не начался
		if (!controlVar.P1_Win || !controlVar.start)
		{
			// Состояние бездействия Дедпула
			deadpool.moveOnPlace_P2(controlVar.frame_P2, time);
		}
		
		// Нажатие на кнопки возможно только если оба игрока не выиграли и бой уже в процессе
		if (!controlVar.P1_Win && !controlVar.P2_Win && controlVar.start)
		{
			// Нельзя бить во время прыжка, т.к. кадры накладываются
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::F) && controlVar.firstJump_P1)
			{
				venom.handAttack_P1(controlVar.frame_P1, time);

				// Если удар попадает в противника, то у второго отнимаются жизни
				if (venom.hero.getGlobalBounds().left + venom.hero.getGlobalBounds().width
					>= deadpool.hero.getGlobalBounds().left)
				{
					environment.getDamage('d', 'h', controlVar.P1_Win);
					controlVar.wasHit_P1 = true;
				}
				// Движение совершено
				controlVar.wasMove_P1 = true;
			}

			// Нельзя бить во время прыжка, т.к. кадры накладываются
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::R) && controlVar.firstJump_P1)
			{
				venom.biteAttack_P1(controlVar.frame_P1, time);

				// Если удар попадает в противника, то у второго отнимаются жизни
				if (venom.hero.getGlobalBounds().left + venom.hero.getGlobalBounds().width
					>= deadpool.hero.getGlobalBounds().left)
				{
					environment.getDamage('d', 'b', controlVar.P1_Win);
					controlVar.wasHit_P1 = true;
				}
				// Движение совершено
				controlVar.wasMove_P1 = true;
			}

			// Нельзя бить во время прыжка, т.к. кадры накладываются
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::K) && controlVar.firstJump_P2)
			{
				deadpool.handAttack_P2(controlVar.frame_P2, time);
				// Если удар попадает в противника, то у второго отнимаются жизни
				if (deadpool.hero.getGlobalBounds().left <= venom.hero.getGlobalBounds().left
					+ venom.hero.getGlobalBounds().width)
				{
					environment.getDamage('v', 'h', controlVar.P2_Win);
					controlVar.wasHit_P2 = true;
				}
				// Движение совершено
				controlVar.wasMove_P2 = true;
			}
			
			// Стрельба появляется у 2 игрока только когда его жизни будут составлять 25 процентов и ниже
			if (environment.NegHP_P2.getSize().x >= 600)
			{
				// Нельзя бить во время прыжка, т.к. кадры накладываются
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::L) && controlVar.firstJump_P2)
				{
					deadpool.shootingAttack_P2(controlVar.frame_P2, time);
					// Если удар попадает в противника, то у второго отнимаются жизни
					if (deadpool.hero.getGlobalBounds().top + (deadpool.hero.getGlobalBounds().height / 4.0)
						<= (venom.hero.getGlobalBounds().top + venom.hero.getGlobalBounds().height))
					{
						environment.getDamage('v', 's', controlVar.P2_Win);
						controlVar.wasHit_P2 = true;
					}
					// Движение совершено
					controlVar.wasMove_P2 = true;
				}
			}


			// Нельзя бить, пока идешь влево
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) && !controlVar.wasHit_P1)
			{
				venom.moveLeft_P1(controlVar.frameMove_P1, time);
				// Проверка выхода за левую границу
				if (venom.hero.getGlobalBounds().left < 0.0)
				{
					sf::Vector2f pos = venom.hero.getPosition();
					venom.hero.setPosition(0, pos.y);
				}
				// Движение совершено
				controlVar.wasMove_P1 = true;
			}

			// Нельзя бить, пока идешь вправо
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) && !controlVar.wasHit_P1)
			{
				venom.moveRight_P1(controlVar.frameMove_P1, time);
				// Проверка на пересечение персонажей, разрешено только бить
				if ((venom.hero.getGlobalBounds().left + venom.hero.getGlobalBounds().width >
					deadpool.hero.getGlobalBounds().left) && !controlVar.wasHit_P1)
				{
					sf::Vector2f pos = venom.hero.getPosition();
					venom.hero.setPosition(deadpool.hero.getGlobalBounds().left -
						venom.hero.getGlobalBounds().width, pos.y);
				}
				// Движение совершено
				controlVar.wasMove_P1 = true;
			}

			// Нельзя бить, пока идешь влево
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && !controlVar.wasHit_P2)
			{
				deadpool.moveLeft_P2(controlVar.frameMove_P2, time);
				// Проверка на пересечение персонажей, разрешено только бить
				if ((deadpool.hero.getGlobalBounds().left < venom.hero.getGlobalBounds().left +
					venom.hero.getGlobalBounds().width) && !controlVar.wasHit_P2)
				{
					sf::Vector2f pos = deadpool.hero.getPosition();
					deadpool.hero.setPosition(venom.hero.getGlobalBounds().left +
						venom.hero.getGlobalBounds().width, pos.y);
				}
				// Движение совершено
				controlVar.wasMove_P2 = true;
			}

			// Нельзя бить, пока идешь вправо
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && !controlVar.wasHit_P2)
			{
				deadpool.moveRight_P2(controlVar.frameMove_P2, time);
				// Проверка выхода за правую границу
				if (deadpool.hero.getGlobalBounds().left + deadpool.hero.getGlobalBounds().width > 1920)
				{
					sf::Vector2f pos = deadpool.hero.getPosition();
					deadpool.hero.setPosition(1920 - deadpool.hero.getGlobalBounds().width, pos.y);
				}
				// Движение совершено
				controlVar.wasMove_P2 = true;
			}

			// Пока прыжок не прорисовал все кадры, завершить его нельзя
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) || !controlVar.fullJump_P1)
			{
				// Если рисуется первый кадры прыжка, то сохраняем позицию по Y, чтобы потом вернуть
				if (controlVar.firstJump_P1)
				{
					sf::Vector2f position;
					position = venom.hero.getPosition();
					controlVar.yPos_P1 = position.y;
					controlVar.firstJump_P1 = false;
				}

				// Установка кадра прыжка
				venom.jump_P1(controlVar.frame_P1, time, controlVar.fullJump_P1);

				// Если был установлен послежний кадр прыжка, то возвращем Y и проэкцию на X
				if (controlVar.fullJump_P1)
				{
					sf::Vector2f position2;
					position2 = venom.hero.getPosition();
					venom.hero.setPosition(position2.x, controlVar.yPos_P1);
					controlVar.firstJump_P1 = true;
				}
			}

			// Пока прыжок не прорисовал все кадры, завершить его нельзя
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) || !controlVar.fullJump_P2)
			{
				// Если рисуется первый кадры прыжка, то сохраняем позицию по Y, чтобы потом вернуть
				if (controlVar.firstJump_P2)
				{
					sf::Vector2f position;
					position = deadpool.hero.getPosition();
					controlVar.yPos_P2 = position.y;
					controlVar.firstJump_P2 = false;
				}

				// Установка кадра прыжка
				deadpool.jump_P2(controlVar.frame_P2, time, controlVar.fullJump_P2);

				// Если был установлен послежний кадр прыжка, то возвращем Y и проэкцию на X
				if (controlVar.fullJump_P2)
				{
					sf::Vector2f position2;
					position2 = deadpool.hero.getPosition();
					deadpool.hero.setPosition(position2.x, controlVar.yPos_P2);
					controlVar.firstJump_P2 = true;
				}
			}

			// Все движения начинаются с первого кадра, поэтому обнуляем
			if (!controlVar.wasMove_P1)
			{
				controlVar.frameMove_P1 = 0.0;
			}

			// Все движения начинаются с первого кадра, поэтому обнуляем
			if (!controlVar.wasMove_P2)
			{
				controlVar.frameMove_P2 = 0.0;
			}

		}

		// Если кто-то выиграл
		if (controlVar.P1_Win || controlVar.P2_Win)
		{
			// Если выиграли оба, то устанавливается фраза 2 иначе 1
			if (controlVar.P1_Win && controlVar.P2_Win)
			{
				environment.setFinish(2);
			}
			else
			{
				environment.setFinish(1);
			}
		}

		// Отчищается окно и рисуются остальные объекты
		window.clear();
		window.draw(environment.location);
		window.draw(venom.hero);
		window.draw(deadpool.hero);
		window.draw(environment.HP_P1);
		window.draw(environment.NegHP_P1);
		window.draw(environment.HP_P2);
		window.draw(environment.NegHP_P2);
		window.draw(environment.name_P1);
		window.draw(environment.name_P2);

		// Рисуем начальные слова, пока переменная не накопит 200 единиц
		if (controlVar.start_count <= 200)
		{
			window.draw(environment.startWords_lay1);
			window.draw(environment.startWords_lay2);
			controlVar.start_count += 1;
			// Если накопила, то устанавливаем начало боя
			if (controlVar.start_count == 200)
			{
				controlVar.start = true;
			}
		}

		// Если выиграл 1 игрок, то 2 умирает
		if (controlVar.P1_Win && !controlVar.end)
		{
			deadpool.die_P2(controlVar.frameMove_P2, time, controlVar.end);
		}

		// Если выиграл 2 игрок, то 1 умирает
		if (controlVar.P2_Win && !controlVar.end)
		{
			venom.die_P1(controlVar.frameMove_P1, time, controlVar.end);
		}

		// Вывод слов конца поединка в 2 слоя
		if (controlVar.end)
		{
			window.draw(environment.finalWords_lay1);
			window.draw(environment.finalWords_lay2);
		}

		// Отображение изменений
		window.display();
		
		// Ставим на паузу первую фразу, если бой не начался,
		// чтобы подолжить воспроизведение в начале следующего цикла
		if (!controlVar.start)
		{
			environment.startWords.pause();
		}

		// Если поединок закончился
		if (controlVar.end)
		{
			// Ставятся на паузу слова, заверщающие бой, если выиграли оба
			// иначе если выиграл кто-то один
			if (controlVar.P1_Win && controlVar.P2_Win)
			{
				environment.finalWords_version2.pause();
			}
			else
			{
				environment.finalWords_version1.pause();
			}
		}
	}
	return 0;
}
