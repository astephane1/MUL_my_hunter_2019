/*
** EPITECH PROJECT, 2019
** My Hunter
** File description:
** play the game
*/

#include <SFML/Audio.h>
#include <SFML/Graphics.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>

void play(void)
{
    sfVideoMode mode = {800, 600, 32};
    sfRenderWindow *window;
    sfTexture *bird;
    sfTexture *texture;
    sfSprite *sprite;
    sfSprite *sprite_bird;
    sfEvent event;
    sfIntRect rect;
    sfClock *clock = sfClock_create();
    sfTime time;
    sfVector2i position_mouse;
    sfVector2f position_bird;
    float seconds;
    int score = 0;
    int i = 0;
    int z = 1;
    float speed_bird = 1;
    int lost = 0;

    rect.top = 0;
    rect.left = 0;
    rect.width = 110;
    rect.height = 110;

    position_bird.x = 0;
    position_bird.y = 0;
    window = sfRenderWindow_create(mode, "Angry bird's", sfResize | sfClose, NULL);
    texture = sfTexture_createFromFile("image/paris.jpeg", NULL);
    bird = sfTexture_createFromFile("image/spritesheet.png", NULL);
    sprite = sfSprite_create();
    sprite_bird = sfSprite_create();
    sfSprite_setTexture(sprite, texture, sfTrue);
    sfSprite_setTexture(sprite_bird, bird, sfTrue);
    sfRenderWindow_setFramerateLimit(window, 30);
    while (sfRenderWindow_isOpen(window)) {
        if (position_bird.x == 690) {
            z = - 1;
        }
        position_bird.x = position_bird.x + (speed_bird * z);
        if (position_bird.x == 0) {
            z = 1;
        }
        time = sfClock_getElapsedTime(clock);
        seconds = time.microseconds / 1000000.0;
        if (seconds > 0.5) {
            i++;
            rect.left = rect.left + 110;
            if (i == 3) {
                rect.left = 0;
                i = 0;
            }
            sfSprite_setTextureRect(sprite_bird, rect);
            sfClock_restart(clock);
        }
        while (sfRenderWindow_pollEvent(window, &event)) {
            if (event.type == sfEvtMouseButtonPressed) {
                position_mouse = sfMouse_getPosition(window);
                if (position_mouse.x > position_bird.x && position_mouse.x < position_bird.x + 110 && position_mouse.y > position_bird.y && position_mouse.y < position_bird.y + 110) {
                    position_bird.y = rand() % 500;
                    position_bird.x = 0;
                    z = 1;

                    score++;
                    if (speed_bird < 10) {
                        speed_bird = speed_bird + 1;
                    }
                    my_printf("score = %d, lost = %d\n", score, lost);
                } else {
                    lost++;
                    my_printf("score = %d, lost = %d\n", score, lost);
                }
            }
            if (event.type == sfEvtClosed || lost >= 3) {
                sfRenderWindow_close(window);
                my_putstr("You are lost\n");
            }
        }
        sfSprite_setPosition(sprite_bird, position_bird);
        sfRenderWindow_clear(window, sfBlack);
        sfRenderWindow_drawSprite(window, sprite, NULL);
        sfRenderWindow_drawSprite(window, sprite_bird, NULL);
        sfRenderWindow_display(window);
    }
    sfSprite_destroy(sprite);
    sfRenderWindow_destroy(window);
}
