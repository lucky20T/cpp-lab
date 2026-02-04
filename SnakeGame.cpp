#include <conio.h>
#include <cctype>
#include <deque>
#include <iostream>
#include <random>
#include <string>
#include <windows.h>

struct Point {
    int x;
    int y;
    bool operator==(const Point& other) const { return x == other.x && y == other.y; }
};

enum class Direction { Up, Down, Left, Right };

static void HideCursor() {
    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO info{};
    info.dwSize = 1;
    info.bVisible = FALSE;
    SetConsoleCursorInfo(h, &info);
}

static void MoveCursorHome() {
    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD c{0, 0};
    SetConsoleCursorPosition(h, c);
}

static Point RandomFood(int width, int height, const std::deque<Point>& snake, std::mt19937& rng) {
    std::uniform_int_distribution<int> dx(1, width - 2);
    std::uniform_int_distribution<int> dy(1, height - 2);
    Point p{};
    bool ok = false;
    while (!ok) {
        p = {dx(rng), dy(rng)};
        ok = true;
        for (const auto& s : snake) {
            if (s == p) {
                ok = false;
                break;
            }
        }
    }
    return p;
}

static void Draw(int width, int height, const std::deque<Point>& snake, const Point& food, int score) {
    std::string out;
    out.reserve((width + 1) * height + 32);
    for (int y = 0; y < height; ++y) {
        for (int x = 0; x < width; ++x) {
            if (y == 0 || y == height - 1 || x == 0 || x == width - 1) {
                out += '#';
                continue;
            }

            if (food.x == x && food.y == y) {
                out += '*';
                continue;
            }

            bool drawn = false;
            for (size_t i = 0; i < snake.size(); ++i) {
                if (snake[i].x == x && snake[i].y == y) {
                    out += (i == 0 ? 'O' : 'o');
                    drawn = true;
                    break;
                }
            }
            out += drawn ? "" : " ";
        }
        out += "\n";
    }
    out += "Score: " + std::to_string(score) + "\n";

    MoveCursorHome();
    std::cout << out << std::flush;
}

static Direction ApplyInput(Direction current) {
    if (!_kbhit()) return current;

    int ch = _getch();
    if (ch == 0 || ch == 224) {
        int key = _getch();
        if (key == 72 && current != Direction::Down) return Direction::Up;
        if (key == 80 && current != Direction::Up) return Direction::Down;
        if (key == 75 && current != Direction::Right) return Direction::Left;
        if (key == 77 && current != Direction::Left) return Direction::Right;
        return current;
    }

    ch = std::tolower(ch);
    if (ch == 'w' && current != Direction::Down) return Direction::Up;
    if (ch == 's' && current != Direction::Up) return Direction::Down;
    if (ch == 'a' && current != Direction::Right) return Direction::Left;
    if (ch == 'd' && current != Direction::Left) return Direction::Right;
    return current;
}

int main() {
    const int width = 32;
    const int height = 18;
    const int frame_ms = 90;

    HideCursor();
    std::deque<Point> snake = {{width / 2, height / 2}, {width / 2 - 1, height / 2}};
    Direction dir = Direction::Right;
    int score = 0;

    std::random_device rd;
    std::mt19937 rng(rd());
    Point food = RandomFood(width, height, snake, rng);

    bool alive = true;
    while (alive) {
        dir = ApplyInput(dir);

        Point head = snake.front();
        Point next = head;
        if (dir == Direction::Up) next.y -= 1;
        if (dir == Direction::Down) next.y += 1;
        if (dir == Direction::Left) next.x -= 1;
        if (dir == Direction::Right) next.x += 1;

        if (next.x <= 0 || next.x >= width - 1 || next.y <= 0 || next.y >= height - 1) {
            alive = false;
        } else {
            for (const auto& s : snake) {
                if (s == next) {
                    alive = false;
                    break;
                }
            }
        }

        if (!alive) break;

        snake.push_front(next);
        if (next == food) {
            score += 10;
            food = RandomFood(width, height, snake, rng);
        } else {
            snake.pop_back();
        }

        Draw(width, height, snake, food, score);
        Sleep(frame_ms);
    }

    MoveCursorHome();
    std::cout << "Game Over! Final score: " << score << "\n";
    std::cout << "Press any key to exit...\n";
    _getch();
    return 0;
}
