#include <string>
#include <iostream>

#include "gamemanager.h"
#include "game.h"
#include "simpleboard.h"
#include "uiplayer.h"
#include "uigame.h"

IGame* GameManager::createGame(const std::string &name, std::size_t dim) const
{
    IGame* game = nullptr;
    if (name == "UI_game")
    {
        IBoard* board = new SimpleBoard(dim);
        game = static_cast<IGame*>(new UIGame(board));
    }
    // if name == "console_game"
    // if name == "net_game"
    // ...

    return game;
}
