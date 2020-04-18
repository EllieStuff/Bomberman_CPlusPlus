#pragma once

const int NUM_OF_PLAYERS = 2;
const int PLAY_TIME = 61000;
const int BOMB_RANGE = 2;
const int BOMB_TIMER = 2000;

enum class Cell { NONE = ' ', WALL = '*', BLOCK = 'X', PLAYER1 = '1', PLAYER2 = '2', BOMB = 'O', EXPLOSION = 'E' };

enum class GameState { INIT, PLAY, PAUSE, GAME_OVER };