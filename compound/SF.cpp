#include <SFML/Graphics.hpp>
#include <vector>
#include <iostream>

// Function to calculate APR
long double total_APR(long double S0, long double ratio, long double Fee, long double slip, int total_seconds, long double A) {
    long double r = ratio; // second ratio
    long double time = total_seconds;
    long double p = S0;
    if (A / (p * r) > time) {
        return -1.0 * A / (p * r);
    }
    while (time >= A / (p * r)) {
        time -= A / (p * r);
        p = p + A - Fee - slip * p; // Added slip as a loss on p
    }
    return p + p * r * time;
}

int main() {
    const int window_width = 800;
    const int window_height = 600;
    sf::RenderWindow window(sf::VideoMode(window_width, window_height), "APR Graph");

    // Define the parameters
    long double S0 = 2539.84;
    long double ratio = 60.0 / 100.0 / (365 * 24 * 60 * 60);
    long double Fee = 0.04;
    long double slip = 0.3 / 100;
    int total_seconds = 365 * 24 * 60 * 60;

    // Calculate values for different A
    std::vector<sf::Vector2f> points;
    for (long double A = 0.0; A <= 20.0; A += 0.1) {
        long double result = total_APR(S0, ratio, Fee, slip, total_seconds, A);
        if (result > 0) {
            // Scale and translate the points to fit them in the window
            float x = (A / 20.0) * window_width;
            float y = window_height - (result / 3000.0) * window_height; // Scale based on expected result range
            points.push_back(sf::Vector2f(x, y));
        }
    }

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear(sf::Color::Black);
        
        // Draw lines between points
        for (size_t i = 1; i < points.size(); i++) {
            sf::Vertex line[] =
            {
                sf::Vertex(points[i - 1], sf::Color::Red),
                sf::Vertex(points[i], sf::Color::Red)
            };
            window.draw(line, 2, sf::Lines);
        }

        window.display();
    }

    return 0;
}
