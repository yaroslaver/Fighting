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

		// �������� ����� � ���������� ����
		float time = clock.getElapsedTime().asMicroseconds();
		clock.restart();
		time /= 3000;

		// �������� �����
		controlVar.resetHitMove();

		// ������������� ����� ������ ��������
		environment.setStart();

		// �������� ���� �� ESC ��� �������� �� ����
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed || sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
			{
				window.close();
			}
		}

		// ���� ����� 1 ������� ��� ��� �� �������
		if (!controlVar.P2_Win || !controlVar.start)
		{
			// ��������� ����������� ������
			venom.moveOnPlace_P1(controlVar.frame_P1, time);
		}

		// ���� ����� 2 ������� ��� ��� �� �������
		if (!controlVar.P1_Win || !controlVar.start)
		{
			// ��������� ����������� �������
			deadpool.moveOnPlace_P2(controlVar.frame_P2, time);
		}
		
		// ������� �� ������ �������� ������ ���� ��� ������ �� �������� � ��� ��� � ��������
		if (!controlVar.P1_Win && !controlVar.P2_Win && controlVar.start)
		{
			// ������ ���� �� ����� ������, �.�. ����� �������������
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::F) && controlVar.firstJump_P1)
			{
				venom.handAttack_P1(controlVar.frame_P1, time);

				// ���� ���� �������� � ����������, �� � ������� ���������� �����
				if (venom.hero.getGlobalBounds().left + venom.hero.getGlobalBounds().width
					>= deadpool.hero.getGlobalBounds().left)
				{
					environment.getDamage('d', 'h', controlVar.P1_Win);
					controlVar.wasHit_P1 = true;
				}
				// �������� ���������
				controlVar.wasMove_P1 = true;
			}

			// ������ ���� �� ����� ������, �.�. ����� �������������
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::R) && controlVar.firstJump_P1)
			{
				venom.biteAttack_P1(controlVar.frame_P1, time);

				// ���� ���� �������� � ����������, �� � ������� ���������� �����
				if (venom.hero.getGlobalBounds().left + venom.hero.getGlobalBounds().width
					>= deadpool.hero.getGlobalBounds().left)
				{
					environment.getDamage('d', 'b', controlVar.P1_Win);
					controlVar.wasHit_P1 = true;
				}
				// �������� ���������
				controlVar.wasMove_P1 = true;
			}

			// ������ ���� �� ����� ������, �.�. ����� �������������
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::K) && controlVar.firstJump_P2)
			{
				deadpool.handAttack_P2(controlVar.frame_P2, time);
				// ���� ���� �������� � ����������, �� � ������� ���������� �����
				if (deadpool.hero.getGlobalBounds().left <= venom.hero.getGlobalBounds().left
					+ venom.hero.getGlobalBounds().width)
				{
					environment.getDamage('v', 'h', controlVar.P2_Win);
					controlVar.wasHit_P2 = true;
				}
				// �������� ���������
				controlVar.wasMove_P2 = true;
			}
			
			// �������� ���������� � 2 ������ ������ ����� ��� ����� ����� ���������� 25 ��������� � ����
			if (environment.NegHP_P2.getSize().x >= 600)
			{
				// ������ ���� �� ����� ������, �.�. ����� �������������
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::L) && controlVar.firstJump_P2)
				{
					deadpool.shootingAttack_P2(controlVar.frame_P2, time);
					// ���� ���� �������� � ����������, �� � ������� ���������� �����
					if (deadpool.hero.getGlobalBounds().top + (deadpool.hero.getGlobalBounds().height / 4.0)
						<= (venom.hero.getGlobalBounds().top + venom.hero.getGlobalBounds().height))
					{
						environment.getDamage('v', 's', controlVar.P2_Win);
						controlVar.wasHit_P2 = true;
					}
					// �������� ���������
					controlVar.wasMove_P2 = true;
				}
			}


			// ������ ����, ���� ����� �����
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) && !controlVar.wasHit_P1)
			{
				venom.moveLeft_P1(controlVar.frameMove_P1, time);
				// �������� ������ �� ����� �������
				if (venom.hero.getGlobalBounds().left < 0.0)
				{
					sf::Vector2f pos = venom.hero.getPosition();
					venom.hero.setPosition(0, pos.y);
				}
				// �������� ���������
				controlVar.wasMove_P1 = true;
			}

			// ������ ����, ���� ����� ������
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) && !controlVar.wasHit_P1)
			{
				venom.moveRight_P1(controlVar.frameMove_P1, time);
				// �������� �� ����������� ����������, ��������� ������ ����
				if ((venom.hero.getGlobalBounds().left + venom.hero.getGlobalBounds().width >
					deadpool.hero.getGlobalBounds().left) && !controlVar.wasHit_P1)
				{
					sf::Vector2f pos = venom.hero.getPosition();
					venom.hero.setPosition(deadpool.hero.getGlobalBounds().left -
						venom.hero.getGlobalBounds().width, pos.y);
				}
				// �������� ���������
				controlVar.wasMove_P1 = true;
			}

			// ������ ����, ���� ����� �����
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && !controlVar.wasHit_P2)
			{
				deadpool.moveLeft_P2(controlVar.frameMove_P2, time);
				// �������� �� ����������� ����������, ��������� ������ ����
				if ((deadpool.hero.getGlobalBounds().left < venom.hero.getGlobalBounds().left +
					venom.hero.getGlobalBounds().width) && !controlVar.wasHit_P2)
				{
					sf::Vector2f pos = deadpool.hero.getPosition();
					deadpool.hero.setPosition(venom.hero.getGlobalBounds().left +
						venom.hero.getGlobalBounds().width, pos.y);
				}
				// �������� ���������
				controlVar.wasMove_P2 = true;
			}

			// ������ ����, ���� ����� ������
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && !controlVar.wasHit_P2)
			{
				deadpool.moveRight_P2(controlVar.frameMove_P2, time);
				// �������� ������ �� ������ �������
				if (deadpool.hero.getGlobalBounds().left + deadpool.hero.getGlobalBounds().width > 1920)
				{
					sf::Vector2f pos = deadpool.hero.getPosition();
					deadpool.hero.setPosition(1920 - deadpool.hero.getGlobalBounds().width, pos.y);
				}
				// �������� ���������
				controlVar.wasMove_P2 = true;
			}

			// ���� ������ �� ���������� ��� �����, ��������� ��� ������
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) || !controlVar.fullJump_P1)
			{
				// ���� �������� ������ ����� ������, �� ��������� ������� �� Y, ����� ����� �������
				if (controlVar.firstJump_P1)
				{
					sf::Vector2f position;
					position = venom.hero.getPosition();
					controlVar.yPos_P1 = position.y;
					controlVar.firstJump_P1 = false;
				}

				// ��������� ����� ������
				venom.jump_P1(controlVar.frame_P1, time, controlVar.fullJump_P1);

				// ���� ��� ���������� ��������� ���� ������, �� ��������� Y � �������� �� X
				if (controlVar.fullJump_P1)
				{
					sf::Vector2f position2;
					position2 = venom.hero.getPosition();
					venom.hero.setPosition(position2.x, controlVar.yPos_P1);
					controlVar.firstJump_P1 = true;
				}
			}

			// ���� ������ �� ���������� ��� �����, ��������� ��� ������
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) || !controlVar.fullJump_P2)
			{
				// ���� �������� ������ ����� ������, �� ��������� ������� �� Y, ����� ����� �������
				if (controlVar.firstJump_P2)
				{
					sf::Vector2f position;
					position = deadpool.hero.getPosition();
					controlVar.yPos_P2 = position.y;
					controlVar.firstJump_P2 = false;
				}

				// ��������� ����� ������
				deadpool.jump_P2(controlVar.frame_P2, time, controlVar.fullJump_P2);

				// ���� ��� ���������� ��������� ���� ������, �� ��������� Y � �������� �� X
				if (controlVar.fullJump_P2)
				{
					sf::Vector2f position2;
					position2 = deadpool.hero.getPosition();
					deadpool.hero.setPosition(position2.x, controlVar.yPos_P2);
					controlVar.firstJump_P2 = true;
				}
			}

			// ��� �������� ���������� � ������� �����, ������� ��������
			if (!controlVar.wasMove_P1)
			{
				controlVar.frameMove_P1 = 0.0;
			}

			// ��� �������� ���������� � ������� �����, ������� ��������
			if (!controlVar.wasMove_P2)
			{
				controlVar.frameMove_P2 = 0.0;
			}

		}

		// ���� ���-�� �������
		if (controlVar.P1_Win || controlVar.P2_Win)
		{
			// ���� �������� ���, �� ��������������� ����� 2 ����� 1
			if (controlVar.P1_Win && controlVar.P2_Win)
			{
				environment.setFinish(2);
			}
			else
			{
				environment.setFinish(1);
			}
		}

		// ���������� ���� � �������� ��������� �������
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

		// ������ ��������� �����, ���� ���������� �� ������� 200 ������
		if (controlVar.start_count <= 200)
		{
			window.draw(environment.startWords_lay1);
			window.draw(environment.startWords_lay2);
			controlVar.start_count += 1;
			// ���� ��������, �� ������������� ������ ���
			if (controlVar.start_count == 200)
			{
				controlVar.start = true;
			}
		}

		// ���� ������� 1 �����, �� 2 �������
		if (controlVar.P1_Win && !controlVar.end)
		{
			deadpool.die_P2(controlVar.frameMove_P2, time, controlVar.end);
		}

		// ���� ������� 2 �����, �� 1 �������
		if (controlVar.P2_Win && !controlVar.end)
		{
			venom.die_P1(controlVar.frameMove_P1, time, controlVar.end);
		}

		// ����� ���� ����� �������� � 2 ����
		if (controlVar.end)
		{
			window.draw(environment.finalWords_lay1);
			window.draw(environment.finalWords_lay2);
		}

		// ����������� ���������
		window.display();
		
		// ������ �� ����� ������ �����, ���� ��� �� �������,
		// ����� ��������� ��������������� � ������ ���������� �����
		if (!controlVar.start)
		{
			environment.startWords.pause();
		}

		// ���� �������� ����������
		if (controlVar.end)
		{
			// �������� �� ����� �����, ����������� ���, ���� �������� ���
			// ����� ���� ������� ���-�� ����
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
