void IState::SetFinishStatus(bool status) { finishStatus = status; }
bool IState::IsFinished() { return finishStatus; }