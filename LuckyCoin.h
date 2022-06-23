#ifndef BRICKGAME_LUCKYCOIN_H
#define BRICKGAME_LUCKYCOIN_H


#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Sprite.hpp>

class LuckyCoin {
public:
    LuckyCoin();

    ~LuckyCoin();

    // Coin texture and sprite functions
    void setTexture();

    //Core
    void renderCoin(sf::RenderTarget &target) const;

    // Movimiento automatico de la moneda
    virtual void moveCoin1(sf::RenderWindow &render_window);
    virtual void moveCoin2(sf::RenderWindow &render_window);
    virtual void moveCoin3(sf::RenderWindow &render_window);
    virtual void moveCoin4(sf::RenderWindow &render_window);
    virtual void moveCoin5(sf::RenderWindow &render_window);

    sf::Texture coinTexture;
    sf::Sprite coinSprite1;
    sf::Sprite coinSprite2;
    sf::Sprite coinSprite3;
    sf::Sprite coinSprite4;
    sf::Sprite coinSprite5;



    void setRapidez(float rapidez);

private:
    //Movement
    float rapidez = 1.0f;

};


#endif //GAOLAND_S_ADVENTURES_LUCKYCOIN_H
