#include "State.h"

void State::SetFinishStatus(bool status) { finishStatus = status; }
bool State::IsFinished() const { return finishStatus; }