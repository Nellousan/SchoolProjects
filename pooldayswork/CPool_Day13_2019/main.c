/*
** EPITECH PROJECT, 2019
** window test
** File description:
** 
*/

#include <stdlib.h>
#include <SFML/Graphics.h>

typedef struct framebuffer
{
    sfUint8 *pixarray;
    int width;
    int height;
} framebuffer_t;

framebuffer_t *framebuffer_create(unsigned int width, unsigned int height)
{
    framebuffer_t *framebuffer = malloc(sizeof(framebuffer_t));
    framebuffer->pixarray = malloc(sizeof(sfUint8) * width * height * 4);
    framebuffer->width = width;
    framebuffer->height = height;
    return framebuffer;
}

void my_putpixel(framebuffer_t *framebuffer, int w, int h, sfColor color)
{
    framebuffer->pixarray[(h * framebuffer->width + w) * 4] = color.r;
    framebuffer->pixarray[(h * framebuffer->width + w) * 4 + 1] = color.g;
    framebuffer->pixarray[(h * framebuffer->width + w) * 4 + 2] = color.b;
    framebuffer->pixarray[(h * framebuffer->width + w) * 4 + 3] = color.a;
}

void draw_square(framebuffer_t *framebuffer, sfVector2u position, unsigned int size, sfColor color)
{
    int square_corner = position.y * framebuffer->width + position.x;
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            int current_array_pos = (square_corner + i * framebuffer->width + j) * 4;
            framebuffer->pixarray[current_array_pos] = color.r;
            framebuffer->pixarray[current_array_pos + 1] = color.g;
            framebuffer->pixarray[current_array_pos + 2] = color.b;
            framebuffer->pixarray[current_array_pos + 3] = color.a;
        }
    }
}

int main(int argc, char **argv)
{
    sfVideoMode mode = {800, 600, 32};
    sfRenderWindow *window;
    sfEvent event;
    sfSprite *sprite, *sprite2;
    sfTexture *texture, *texture2;
    sfVector2u position = {100, 100};
    framebuffer_t *framebuffer = framebuffer_create(800, 600);
    my_putpixel(framebuffer, 10, 10, sfRed);
    my_putpixel(framebuffer, 100, 100, sfRed);
    my_putpixel(framebuffer, 250, 400, sfRed);
    draw_square(framebuffer, position, 10, sfRed);
    texture = sfTexture_create(800,  600);
    sfTexture_updateFromPixels(texture, framebuffer->pixarray, 800, 600, 0, 0);
    sprite = sfSprite_create();
    sfSprite_setTexture(sprite, texture, sfTrue);
    texture2 = sfTexture_createFromFile("lucina_sprite.png", NULL);
    sprite2 = sfSprite_create();
    sfSprite_setTexture(sprite2, texture2, sfTrue);
    window = sfRenderWindow_create(mode, "SFML window", sfResize | sfClose, NULL);
    while (sfRenderWindow_isOpen(window)) {
        while (sfRenderWindow_pollEvent(window, &event)) {
            if (event.type == sfEvtClosed)
                sfRenderWindow_close(window);
        }
        sfRenderWindow_clear(window, sfBlack);
        sfRenderWindow_drawSprite(window, sprite, NULL);
        sfRenderWindow_drawSprite(window, sprite2, NULL);
        sfRenderWindow_display(window);
    }
    return 0;
}
