//
// Created by shello on 05-12-22.
//

#include "revolverGame.h"


revolverGame::revolverGame() {
    const int width = 1500;
    const int height = 1000;
    const int mid_x = width/2;
    const int mid_y = height/2;
    const float speed = 0.040;

    int radius = 200;
    int num_of_vert = 3;
    Font font;
    Text text;
    if (!font.loadFromFile("fonts/CENTAUR.TTF")) cout<<"<error"<<endl;
    text.setFont(font);
    string tab;
    text.setFillColor(sf::Color::Black);
    RenderWindow window(VideoMode(width, height, 32), "Diagonals");
    window.setFramerateLimit(240);
    Transform transform;
    while (window.isOpen()){
        int len = num_of_vert+num_of_vert*num_of_vert*2;
        VertexArray point(LinesStrip, len);
        float angle = 360.0/num_of_vert;
        for (int i = 0; i < len; i=i+2*num_of_vert+1) {
            float t_angle = 360.0/num_of_vert;
            point[i].position = Vector2f(mid_x+radius*cos(angle*PI/180), mid_y+radius*sin(angle*PI/180));
            point[i].color = Color::Black;
            for(int j = i+1; j<=i+num_of_vert*2; j+=2){
                point[j].position = Vector2f(mid_x+radius*cos(t_angle*PI/180), mid_y+radius*sin(t_angle*PI/180));
                point[j].color = Color::Black;
                point[j+1].position = Vector2f(mid_x+radius*cos(angle*PI/180), mid_y+radius*sin(angle*PI/180));
                point[j+1].color = Color::Black;
                t_angle = t_angle + 360.0/num_of_vert;
            }
            angle = angle + 360.0/num_of_vert;
        }
        transform.rotate(speed, Vector2f(mid_x, mid_y));
        tab = "Preguntas de Filosofía: "+to_string(num_of_vert)+"\n"+"Radius(pronto vertices): "+to_string(radius);
        text.setString(tab);
        Event Event;
        while (window.pollEvent(Event)){
            switch (Event.type){
                case (Event::Closed):
                    window.close();
                    break;
                case Event::KeyPressed:
                    if (Event.key.code == Keyboard::Up) num_of_vert++;
                    if (Event.key.code == Keyboard::Down&&num_of_vert>3) num_of_vert--;
                    if (Event.key.code == Keyboard::Right && radius<height/2) radius++;
                    if (Event.key.code == Keyboard::Left && radius>0) radius--;
                default:
                    break;
            }
        }
        window.clear(Color::White);
        window.draw(text);
        window.draw(point,transform);
        window.display();
    }
};