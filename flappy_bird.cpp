#include <iostream>
#include <vector>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <SFML/Graphics.hpp>

// Game constants
const int WINDOW_WIDTH = 800;
const int WINDOW_HEIGHT = 600;
const float GRAVITY = 0.5f;
const float JUMP_VELOCITY = -12.0f;
const float PIPE_SPEED = 5.0f;
const int PIPE_GAP = 150;
const int PIPE_WIDTH = 80;

// Bird structure
struct Bird {
    float x, y;
    float velocity;
    float radius;
    
    Bird() : x(100), y(WINDOW_HEIGHT / 2), velocity(0), radius(15) {}
    
    void update() {
        velocity += GRAVITY;
        y += velocity;
    }
    
    void jump() {
        velocity = JUMP_VELOCITY;
    }
    
    sf::CircleShape getShape() {
        sf::CircleShape shape(radius);
        shape.setPosition(x - radius, y - radius);
        shape.setFillColor(sf::Color::Yellow);
        return shape;
    }
};

// Pipe structure
struct Pipe {
    float x;
    int gap_y;
    bool scored;
    
    Pipe(float start_x) : x(start_x), gap_y(100 + rand() % 300), scored(false) {}
    
    void update() {
        x -= PIPE_SPEED;
    }
    
    bool isOffScreen() {
        return x < -PIPE_WIDTH;
    }
    
    void draw(sf::RenderWindow& window) {
        // Top pipe
        sf::RectangleShape top_pipe(sf::Vector2f(PIPE_WIDTH, gap_y));
        top_pipe.setPosition(x, 0);
        top_pipe.setFillColor(sf::Color::Green);
        window.draw(top_pipe);
        
        // Bottom pipe
        sf::RectangleShape bottom_pipe(sf::Vector2f(PIPE_WIDTH, WINDOW_HEIGHT - gap_y - PIPE_GAP));
        bottom_pipe.setPosition(x, gap_y + PIPE_GAP);
        bottom_pipe.setFillColor(sf::Color::Green);
        window.draw(bottom_pipe);
    }
};

// Collision detection
bool checkCollision(const Bird& bird, const Pipe& pipe) {
    // Check if bird hits the screen boundaries
    if (bird.y - bird.radius < 0 || bird.y + bird.radius > WINDOW_HEIGHT) {
        return true;
    }
    
    // Check if bird is in horizontal range of pipe
    if (bird.x + bird.radius > pipe.x && bird.x - bird.radius < pipe.x + PIPE_WIDTH) {
        // Check if bird hits top or bottom pipe
        if (bird.y - bird.radius < pipe.gap_y || 
            bird.y + bird.radius > pipe.gap_y + PIPE_GAP) {
            return true;
        }
    }
    
    return false;
}

int main() {
    // Initialize window
    sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Flappy Bird");
    window.setFramerateLimit(60);
    
    // Seed random
    srand(static_cast<unsigned>(time(0)));
    
    // Game state
    Bird bird;
    std::vector<Pipe> pipes;
    int score = 0;
    bool game_over = false;
    int pipe_spawn_timer = 0;
    
    // Font setup (fallback if font not found)
    sf::Font font;
    font.loadFromFile("C:\\Windows\\Fonts\\arial.ttf"); // Default Windows font
    
    // Main game loop
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
            
            if (event.type == sf::Event::KeyPressed) {
                if (event.key.code == sf::Keyboard::Space && !game_over) {
                    bird.jump();
                }
                if (game_over && event.key.code == sf::Keyboard::R) {
                    // Reset game
                    bird = Bird();
                    pipes.clear();
                    score = 0;
                    game_over = false;
                    pipe_spawn_timer = 0;
                }
            }
            
            if (event.type == sf::Event::MouseButtonPressed && !game_over) {
                bird.jump();
            }
            
            if (game_over && event.type == sf::Event::MouseButtonPressed) {
                // Reset game
                bird = Bird();
                pipes.clear();
                score = 0;
                game_over = false;
                pipe_spawn_timer = 0;
            }
        }
        
        if (!game_over) {
            // Update bird
            bird.update();
            
            // Spawn pipes
            pipe_spawn_timer++;
            if (pipe_spawn_timer > 90) {
                pipes.push_back(Pipe(WINDOW_WIDTH));
                pipe_spawn_timer = 0;
            }
            
            // Update and check pipes
            for (auto it = pipes.begin(); it != pipes.end();) {
                it->update();
                
                // Check collision
                if (checkCollision(bird, *it)) {
                    game_over = true;
                }
                
                // Score point when passing pipe
                if (!it->scored && bird.x > it->x + PIPE_WIDTH) {
                    it->scored = true;
                    score++;
                }
                
                // Remove off-screen pipes
                if (it->isOffScreen()) {
                    it = pipes.erase(it);
                } else {
                    ++it;
                }
            }
        }
        
        // Clear window
        window.clear(sf::Color::Cyan);
        
        // Draw pipes
        for (auto& pipe : pipes) {
            pipe.draw(window);
        }
        
        // Draw bird
        window.draw(bird.getShape());
        
        // Draw score
        sf::Text scoreText;
        scoreText.setFont(font);
        scoreText.setString("Score: " + std::to_string(score));
        scoreText.setCharacterSize(30);
        scoreText.setFillColor(sf::Color::Black);
        scoreText.setPosition(10, 10);
        window.draw(scoreText);
        
        // Draw game over screen
        if (game_over) {
            // Semi-transparent overlay
            sf::RectangleShape overlay(sf::Vector2f(WINDOW_WIDTH, WINDOW_HEIGHT));
            overlay.setFillColor(sf::Color(0, 0, 0, 100));
            window.draw(overlay);
            
            // Game over text
            sf::Text gameOverText;
            gameOverText.setFont(font);
            gameOverText.setString("GAME OVER");
            gameOverText.setCharacterSize(50);
            gameOverText.setFillColor(sf::Color::Red);
            gameOverText.setPosition(WINDOW_WIDTH / 2 - 140, WINDOW_HEIGHT / 2 - 80);
            window.draw(gameOverText);
            
            // Final score
            sf::Text finalScoreText;
            finalScoreText.setFont(font);
            finalScoreText.setString("Final Score: " + std::to_string(score));
            finalScoreText.setCharacterSize(30);
            finalScoreText.setFillColor(sf::Color::White);
            finalScoreText.setPosition(WINDOW_WIDTH / 2 - 120, WINDOW_HEIGHT / 2);
            window.draw(finalScoreText);
            
            // Restart instruction
            sf::Text restartText;
            restartText.setFont(font);
            restartText.setString("Press R or Click to Restart");
            restartText.setCharacterSize(20);
            restartText.setFillColor(sf::Color::White);
            restartText.setPosition(WINDOW_WIDTH / 2 - 150, WINDOW_HEIGHT / 2 + 80);
            window.draw(restartText);
        }
        
        // Display window
        window.display();
    }
    
    return 0;
}
