#define SFML_STATIC

#include "SFML/Graphics.hpp"
#include "primary_app.hpp"
#include "logger.hpp"
#include "prim_exception.hpp"

namespace prim
{
    struct PrimaryApp::PrimaryAppImpl
    {
        unPtr<sf::RenderWindow> window;
    };

    int PrimaryApp::run()
    {
        try
        {
            init();
            return mainLoop();
        }
        catch(prim::Exception ex)
        {
            Logger::logError(ex.what());
            return 1;
        }
        catch(std::exception ex)
        {
            Logger::logError(ex.what());
            return 1;
        }
        catch(...)
        {
            Logger::logError("Caught an unknown exception.");
            return 1;
        }
    }
    
    void PrimaryApp::init()
    {
        const char* windowName = "Dark Room";
        sf::Vector2u windowSize(600u, 600u);

        impl->window = std::make_unique<sf::RenderWindow>(sf::VideoMode(windowSize), windowName);
    }

    int PrimaryApp::mainLoop()
    {
        sf::CircleShape shape(100.0f);
        shape.setOrigin({50.0f, 50.0f});
        sf::Font font;
        if(!font.loadFromFile("res/fonts/Mantana-Regular.otf"))
            throw PRIM_EXCEPTION("Failed to load font");
        sf::Text text(font, "This is my new game");
        sf::Vector2u windowSize = impl->window->getSize();
        shape.setPosition(sf::Vector2f(windowSize / 2u));

        while(impl->window->isOpen())
        {
            sf::Event event;
            while(impl->window->pollEvent(event))
            {
                if(event.type == sf::Event::Closed)
                    impl->window->close();
            }

            impl->window->clear();
            impl->window->draw(shape);
            impl->window->draw(text);
            impl->window->display();
        }
    }
    
    PrimaryApp::PrimaryApp() : impl(new PrimaryAppImpl())
    {}

    PrimaryApp::~PrimaryApp() {}
}