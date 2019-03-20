#include "Player.h"

void Player::init(char who)
{

	switch (who)
	{
	case 'v':image.loadFromFile("image/Venom.png");
		break;
	case 'd':image.loadFromFile("image/Deadpool.png");
		break;
	default:throw std::invalid_argument("Argument must be v(Venom) of d(Deadpool)");
	}

	texture.loadFromImage(image);
	hero.setTexture(texture);
	if (who == 'v')
	{
		hero.setTextureRect(sf::IntRect(0, 2900, 165, 130));
		hero.scale(2.0, 2.0);
		hero.setPosition(10, 650);
	}
	else
	{
		hero.setTextureRect(sf::IntRect(1300, 10, 100, 110));
		hero.scale(2.5, 2.5);
		hero.setPosition(1650, 650);
	}
	
}

void Player::moveRight_P1(float &frame, float &time)
{
	hero.move(2.5 * time, 0);
	frame += 0.04 * time;
	if (frame > 10.0)
	{
		frame -= 10.0;
	}
	int k = 0;
	int j = 2900;
	int width = 0;
	switch (int(frame))
	{
	case 0: k = 0, width = 165;
		break;
	case 1: k = 165, width = 165;
		break;
	case 2: k = 330, width = 145;
		break;
	case 3: k = 475, width = 125;
		break;
	case 4: k = 600, width = 150;
		break;
	case 5: k = 750, width = 180;
		break;
	case 6: k = 930, width = 150;
		break;
	case 7: k = 1080, width = 115;
		break;
	case 8: k = 0, width = 115, j = 3038;
		break;
	case 9: k = 140, width = 136, j = 3038;
		break;
	}
	hero.setTextureRect(sf::IntRect(k, j, width, 130));
}

void Player::moveOnPlace_P1(float &frame, float &time)
{
	frame += 0.05 * time;
	if (frame > 13.0)
	{
		frame -= 13.0;
	}
	int k = 0;
	int j = 515;
	int width = 0;
	switch (int(frame))
	{
	case 0: k = 0, width = 140;
		break;
	case 1: k = 145, width = 150;
		break;
	case 2: k = 308, width = 160;
		break;
	case 3: k = 488, width = 160;
		break;
	case 4: k = 670, width = 165;
		break;
	case 5: k = 853, width = 162;
		break;
	case 6: k = 1038, width = 149;
		break;
	case 7: k = 0, width = 154, j = 652;
		break;
	case 8: k = 168, width = 152, j = 652;
		break;
	case 9: k = 336, width = 147, j = 652;
		break;
	case 10: k = 516, width = 154, j = 652;
		break;
	case 11: k = 693, width = 165, j = 652;
		break;
	case 12: k = 873, width = 158, j = 652;
		break;
	}
	hero.setTextureRect(sf::IntRect(k, j - 9, width, 134));
}

void Player::moveLeft_P1(float &frame, float &time)
{
	hero.move(-2.5 * time, 0);
	frame += 0.04 * time;
	if (frame > 10.0)
	{
		frame -= 10.0;
	}
	int k = 0;
	int j = 3242;
	int width = 0;
	switch (int(frame))
	{
	case 0: k = 0, width = 135;
		break;
	case 1: k = 160, width = 118;
		break;
	case 2: k = 300, width = 113;
		break;
	case 3: k = 436, width = 131;
		break;
	case 4: k = 593, width = 143;
		break;
	case 5: k = 756, width = 127;
		break;
	case 6: k = 909, width = 100;
		break;
	case 7: k = 1028, width = 126;
		break;
	case 8: k = 0, width = 143, j = 3382;
		break;
	case 9: k = 160, width = 146, j = 3382;
		break;
	}
	hero.setTextureRect(sf::IntRect(k, j, width, 134));
}

void Player::handAttack_P1(float &frame, float &time)
{
	frame += 0.00005 * time;
	if (frame > 3.0)
	{
		frame -= 3.0;
	}
	int k = 0;
	int width = 0;
	switch (int(frame))
	{
	case 0: k = 0, width = 138;
		break;
	case 1: k = 165, width = 220;
		break;
	case 2: k = 407, width = 152;
		break;
	}
	hero.setTextureRect(sf::IntRect(k, 803, width, 134));
}

void Player::biteAttack_P1(float &frame, float &time)
{
	frame += 0.00005 * time;
	if (frame > 8.0)
	{
		frame -= 8.0;
	}
	int k = 0;
	int j = 0;
	int width = 0;
	int height = 0;
	switch (int(frame))
	{
	case 0: k = 0, width = 141, j = 1265, height = 144;
		break;
	case 1: k = 151, width = 159, j = 1265, height = 144;
		break;
	case 2: k = 331, width = 277, j = 1265, height = 144;
		break;
	case 3: k = 647, width = 323, j = 1265, height = 144;
		break;
	case 4: k = 0, width = 290, j = 1427, height = 136;
		break;
	case 5: k = 329, width = 217, j = 1427, height = 136;
		break;
	case 6: k = 570, width = 133, j = 1427, height = 136;
		break;
	case 7: k = 730, width = 148, j = 1427, height = 136;
		break;
	}
	hero.setTextureRect(sf::IntRect(k, j, width, height));
}

void Player::jump_P1(float &frame, float &time, bool &fullJump)
{
		frame += 0.004 * time;
		if (frame >= 10.0)
		{
			frame -= 10.0;
		}
		int k = 0;
		int width = 0;
		int j = 5476;
		int height = 94;
		switch (int(frame))
		{
		case 0: k = 0, width = 137, hero.move(0, -4.5), fullJump = false;
			break;
		case 1: k = 202, width = 140, j = 5398, height = 171, hero.move(0, -4.5), fullJump = false;
			break;
		case 2: k = 350, width = 145, j = 5398, height = 171, hero.move(0, -4.5), fullJump = false;
			break;
		case 3: k = 553, width = 162, j = 5398, height = 171, hero.move(0, -4.5), fullJump = false;
			break;
		case 4: k = 720, width = 140, j = 5398, height = 171, hero.move(0, -4.5), fullJump = false;
			break;
		case 5: k = 872, width = 122, j = 5398, height = 171, hero.move(0, -4.5), fullJump = false;
			break;
		case 6: k = 1008, width = 138, j = 5398, height = 171, hero.move(0, 6.25), fullJump = false;
			break;
		case 7: k = 0, width = 136, j = 5583, height = 171, hero.move(0, 6.25), fullJump = false;
			break;
		case 8: k = 145, width = 136, j = 5583, height = 171, hero.move(0, 6.25), fullJump = false;
			break;
		case 9: k = 438, width = 137, j = 5583, height = 171, hero.move(0, 6.25), fullJump = true;
			break;
		}
		
		hero.setTextureRect(sf::IntRect(k, j, width, height));
}

void Player::moveOnPlace_P2(float &frame, float &time)
{
	frame += 0.015 * time;
	if (frame > 3.0)
	{
		frame -= 3.0;
	}
	int k = 0;
	int j = 7;
	int width = 0;
	int height = 122;
	switch (int(frame))
	{
	case 0: k = 1300, width = 93;
		break;
	case 1: k = 195, width = 98;
		break;
	case 2: k = 1296, width = 96, j = 611, height = 115;
		break;
	}
	hero.setTextureRect(sf::IntRect(k, j, width, height));
}

void Player::moveLeft_P2(float &frame, float &time)
{
	hero.move(-2.5 * time, 0);
	frame += 0.04 * time;
	if (frame > 6.0)
	{
		frame -= 6.0;
	}
	int k = 0;
	int j = 0;
	int width = 0;
	int height = 0;
	switch (int(frame))
	{
	case 0: k = 1326, width = 80, j = 417, height = 109;
		break;
	case 1: k = 1240, width = 72, j = 417, height = 109;
		break;
	case 2: k = 1103, width = 66, j = 417, height = 109;
		break;
	case 3: k = 974, width = 59, j = 423, height = 104;
		break;
	case 4: k = 872, width = 95, j = 419, height = 111;
		break;
	case 5: k = 808, width = 63, j = 418, height = 108;
		break;
	}
	hero.setTextureRect(sf::IntRect(k, j, width, height));
}

void Player::moveRight_P2(float &frame, float &time)
{
	hero.move(2.5 * time, 0);
	frame += 0.04 * time;
	if (frame > 6.0)
	{
		frame -= 6.0;
	}
	int k = 0;
	int j = 0;
	int width = 0;
	int height = 0;
	switch (int(frame))
	{
	case 0: k = 808, width = 63, j = 418, height = 108;
		break;
	case 1: k = 872, width = 95, j = 419, height = 111;
		break;
	case 2: k = 974, width = 59, j = 423, height = 104;
		break;
	case 3: k = 1103, width = 66, j = 417, height = 109;
		break;
	case 4: k = 1240, width = 72, j = 417, height = 109;
		break;
	case 5: k = 1326, width = 80, j = 417, height = 109;
		break;
	}
	hero.setTextureRect(sf::IntRect(k, j, width, height));
}

void Player::handAttack_P2(float &frame, float &time)
{
	frame += 0.005 * time;
	if (frame > 3.0)
	{
		frame -= 3.0;
	}
	int k = 0;
	int width = 0;
	int j = 0;
	int height = 0;
	switch (int(frame))
	{
	case 0: k = 433, width = 84, j = 812, height = 128;
		break;
	case 1: k = 331, width = 99, j = 812, height = 128;
		break;
	case 2: k = 165, width = 166, j = 812, height = 128;
		break;
	}
	hero.setTextureRect(sf::IntRect(k, j, width, height));
}

void Player::shootingAttack_P2(float &frame, float &time)
{
	frame += 0.005 * time;
	if (frame > 2.0)
	{
		frame -= 2.0;
	}
	int k = 0;
	int j = 0;
	int width = 0;
	int height = 0;
	switch (int(frame))
	{
	case 0: k = 1057, width = 137, j = 770, height = 114;
		break;
	case 1: k = 770, width = 132, j = 799, height = 114;
		break;
	}
	hero.setTextureRect(sf::IntRect(k, j, width, height));
}

void Player::jump_P2(float &frame, float &time, bool &fullJump)
{
	frame += 0.004 * time;
	if (frame >= 3.0)
	{
		frame -= 3.0;
	}
	int k = 0;
	int width = 0;
	int j = 0;
	int height = 0;
	switch (int(frame))
	{
	case 0: k = 695, width = 68, j = 806, height = 128, hero.move(0, -4.5), fullJump = false;
		break;
	case 1: k = 612, width = 80, j = 806, height = 115, hero.move(0, -4.5), fullJump = false;
		break;
	case 2: k = 195, width = 98, j = 7, height = 122, hero.move(0, -4.5), fullJump = true;
		break;
	}

	hero.setTextureRect(sf::IntRect(k, j, width, height));
}

void Player::die_P2(float &frame, float &time, bool &end)
{
	frame += 0.005 * time;
	int k = 0;
	int width = 0;
	int j = 0;
	int height = 0;
	switch (int(frame))
	{
	case 0: k = 582, width = 139, j = 941, height = 39, hero.move(0, 1.5);
		break;
	case 1: k = 723, width = 146, j = 941, height = 39;
		break;
	case 2: k = 869, width = 156, j = 941, height = 39, end = true;
		break;
	}
	hero.setTextureRect(sf::IntRect(k, j, width, height));
}

void Player::die_P1(float &frame, float &time, bool &end)
{
	frame += 0.02 * time;
	int k = 0;
	int width = 0;
	int j = 0;
	int height = 0;
	switch (int(frame))
	{
	case 0: k = 0, width = 149, j = 2106, height = 191, hero.move(0, -1.5);
		break;
	case 1: k = 172, width = 160, j = 2106, height = 191;
		break;
	case 2: k = 349, width = 156, j = 2106, height = 191;
		break;
	case 3: k = 516, width = 209, j = 2106, height = 191;
		break;
	case 4: k = 746, width = 219, j = 2106, height = 191;
		break;
	case 5: k = 987, width = 209, j = 2106, height = 191;
		break;
	case 6: k = 0, width = 218, j = 2320, height = 178, hero.move(0, 0.5);
		break;
	case 7: k = 239, width = 241, j = 2320, height = 178;
		break;
	case 8: k = 507, width = 252, j = 2320, height = 178;
		break;
	case 9: k = 782, width = 257, j = 2320, height = 178;
		break;
	case 10: k = 0, width = 254, j = 2509, height = 167, hero.move(0, 0.25);
		break;
	case 11: k = 264, width = 249, j = 2509, height = 167;
		break;
	case 12: k = 522, width = 208, j = 2509, height = 167;
		break;
	case 13: k = 741, width = 207, j = 2509, height = 167;
		break;
	case 14: k = 963, width = 205, j = 2509, height = 167;
		break;
	case 15: k = 0, width = 163, j = 2697, height = 132, hero.move(0, 0.75);
		break;
	case 16: k = 176, width = 144, j = 2697, height = 132, hero.move(30, -25);
		break;
	case 17: k = 339, width = 147, j = 2697, height = 132, end = true;
		break;
	}
	hero.setTextureRect(sf::IntRect(k, j, width, height));
}
