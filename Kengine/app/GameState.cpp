#include "GameState.h"

void  kengine::GameState::changeState(kengine::Game* game, kengine::GameState* state)
{
	game->changeState(state);
}
