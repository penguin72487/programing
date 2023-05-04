#include <SFML/Graphics.hpp>
#include <cmath>
#include <random>

int main()
{
    // 创建窗口
    sf::RenderWindow window(sf::VideoMode(800, 600), "Fern");

    // 创建形状（鐵線蕨）
    sf::ConvexShape fern;
    fern.setPointCount(4); // 鐵線蕨由4个点组成
    fern.setPoint(0, sf::Vector2f(0, 0));
    fern.setPoint(1, sf::Vector2f(5, 0));
    fern.setPoint(2, sf::Vector2f(5, 20));
    fern.setPoint(3, sf::Vector2f(0, 20));

    // 设置颜色和外观
    fern.setFillColor(sf::Color(34, 139, 34)); // 森林绿
    fern.setOutlineThickness(1); // 边框厚度为1
    fern.setOutlineColor(sf::Color(0, 100, 0)); // 暗绿色

    // 设置变换矩阵
    sf::Transform transform;
    float angle = 0.0f; // 初始角度
    float scale = 1.0f; // 初始缩放
    float tx = 400.0f; // 初始x轴平移
    float ty = 550.0f; // 初始y轴平移
    transform.rotate(angle); // 旋转
    transform.scale(scale, scale); // 缩放
    transform.translate(tx, ty); // 平移

    // 随机数生成器
    std::default_random_engine generator;
    std::uniform_real_distribution<float> distribution(0.0f, 1.0f);

    // 渲染循环
    while (window.isOpen())
    {
        // 处理窗口事件
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        // 清除屏幕
        window.clear(sf::Color::White);

        // 绘制多个鐵線蕨
        for (int i = 0; i < 10000; i++) {
            // 随机选择一个变换
            float r = distribution(generator);
            if (r < 0.01f) {
                transform = sf::Transform::Identity;
                transform.translate(0, 0.16f * ty);
                transform.rotate(-9.0f);
                transform.scale(0.02f, 0.02f);
            }
            else if (r < 0.86f) {
                transform.rotate(0.0f);
                transform.scale(0.85f, 0.85f);
                transform.translate(0, 0.08f * ty);
            }
            else if (r < 0.93f) {
                transform.rotate(90.0f);
                transform.scale(0.2f, 0.2f);
                transform.translate(0, 0.08f * ty);
            }
            else {
                transform.rotate(-90.0f);
                transform.scale(0.2f, 0.2f);
                transform.translate(0, 0.08f);
            }
        }
                // 应用变换并绘制
        window.clear(sf::Color::White);
        window.draw(fern, transform);
        window.display();
    }

}


