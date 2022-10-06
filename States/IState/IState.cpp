#include "State.h"

State::State(RenderHelper& _renderHelper) : renderHelper(_renderHelper) {}
void State::SetFinishStatus(bool status) { finishStatus = status; }
bool State::IsFinished() const { return finishStatus; }
RenderHelper& State::GetRednderHelper() const { return renderHelper; }