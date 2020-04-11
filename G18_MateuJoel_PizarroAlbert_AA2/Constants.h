#pragma once

const int NUM_OF_PLAYERS = 2;



enum class Cell { NONE = ' ', WALL = '*', BLOCK = 'X', PLAYER1 = '1', PLAYER2 = '2' };

enum class GameState { INIT, PLAY, PAUSE, GAME_OVER };