#include <SFML/Graphics.hpp>
#include <bits/stdc++.h>

// 葉子大小參數
const float leafWidth = 100.0f;
const float leafHeight = 200.0f;

// 計算葉子點的位置
sf::Vector2f getLeafPointPosition(float x, float y) {
    float xPos = x * leafWidth / 2.0f * (1.0f - y / leafHeight);
    return sf::Vector2f(xPos, y);
}

int main() {
    // 隨機數種子
    std::srand(static_cast<unsigned int>(std::time(nullptr)));

    // 創建視窗
    sf::RenderWindow window(sf::VideoMode(800, 600), "Leaf Generator");

    // 創建畫布
    sf::RenderTexture renderTexture;
    renderTexture.create(800, 600);
    renderTexture.clear(sf::Color::White);

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        // 繪製葉子點
        for (int i = 0; i < 1000; ++i) {
            float x = static_cast<float>(std::rand()) / RAND_MAX;
            float y = static_cast<float>(std::rand()) / RAND_MAX * leafHeight;

            sf::CircleShape point(1);
            point.setFillColor(sf::Color::Green);
            sf::Vector2f leftPos = getLeafPointPosition(-x, y);
            sf::Vector2f rightPos = getLeafPointPosition(x, y);
            point.setPosition(leftPos + sf::Vector2f(400.0f - leafWidth / 2.0f, 200.0f));
            renderTexture.draw(point);
            point.setPosition(rightPos + sf::Vector2f(400.0f - leafWidth / 2.0f, 200.0f));
            renderTexture.draw(point);
        }

        // 顯示圖像
        renderTexture.display();
        window.clear(sf::Color::White);
        sf::Sprite sprite(renderTexture.getTexture());
        window.draw(sprite);
        window.display();
    }

    return 0;
}
