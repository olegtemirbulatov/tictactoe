#include <string>
#include <iostream>

#include "gamemanager.h"
#include "game.h"
#include "simpleboard.h"
#include "consoleplayer.h"
#include "consolegame.h"

IGame* GameManager::createGame(const std::string &name) const
{
    IGame* game = nullptr;
    if (name == "UI_game")
    {
        IBoard* board = new SimpleBoard<3>();
        game = static_cast<IGame*>(new ConsoleGame("UI_game", board));
    }

    return game;
}
