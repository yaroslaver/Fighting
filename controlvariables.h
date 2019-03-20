#pragma once

// Контролирующие переменные
class ControlVariables
{
public:
	// Конструктор класса с инициализацией всех переменных
	ControlVariables();
	// Сброс движений и ударов
	void resetHitMove();


	// Кадры, отвечающие за отрисовку персонажей в игре
	float frame_P1, frameMove_P1, frame_P2, frameMove_P2;
	// Флаги было ли движение, завершен ли прыжок, был ли начат прыжок, был ли удар для 1 игрока
	bool wasMove_P1, fullJump_P1, firstJump_P1, wasHit_P1;
	// Флаги было ли движение, завершен ли прыжок, был ли начат прыжок, был ли удар для 2 игрока
	bool wasMove_P2, fullJump_P2, firstJump_P2, wasHit_P2;
	// Проекция на ось Y 1 и 2 персонажа
	int yPos_P1, yPos_P2;
	// Флаги выиграл ли 1, выиграл ли 2, закончился ли бой, начался ли бой
	bool P1_Win, P2_Win, end, start;
	// Счетчик до начала
	unsigned int start_count;
};
