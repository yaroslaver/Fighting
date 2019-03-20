#include "controlvariables.h"

ControlVariables::ControlVariables() :
	frame_P1(0.0),
	frameMove_P1(0.0),
	frame_P2(0.0),
	frameMove_P2(0.0),
	wasMove_P1(false),
	fullJump_P1(true),
	firstJump_P1(true),
	wasHit_P1(false),
	wasMove_P2(false),
	fullJump_P2(true),
	firstJump_P2(true),
	wasHit_P2(false),
	yPos_P1(0),
	yPos_P2(0),
	P1_Win(false),
	P2_Win(false),
	end(false),
	start(false),
	start_count(0)
{
}

void ControlVariables::resetHitMove()
{
	wasMove_P1 = false;
	wasHit_P1 = false;
	wasMove_P2 = false;
	wasHit_P2 = false;
}
