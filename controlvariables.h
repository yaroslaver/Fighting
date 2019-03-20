#pragma once

// �������������� ����������
class ControlVariables
{
public:
	// ����������� ������ � �������������� ���� ����������
	ControlVariables();
	// ����� �������� � ������
	void resetHitMove();


	// �����, ���������� �� ��������� ���������� � ����
	float frame_P1, frameMove_P1, frame_P2, frameMove_P2;
	// ����� ���� �� ��������, �������� �� ������, ��� �� ����� ������, ��� �� ���� ��� 1 ������
	bool wasMove_P1, fullJump_P1, firstJump_P1, wasHit_P1;
	// ����� ���� �� ��������, �������� �� ������, ��� �� ����� ������, ��� �� ���� ��� 2 ������
	bool wasMove_P2, fullJump_P2, firstJump_P2, wasHit_P2;
	// �������� �� ��� Y 1 � 2 ���������
	int yPos_P1, yPos_P2;
	// ����� ������� �� 1, ������� �� 2, ���������� �� ���, ������� �� ���
	bool P1_Win, P2_Win, end, start;
	// ������� �� ������
	unsigned int start_count;
};
