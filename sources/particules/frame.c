/*
** EPITECH PROJECT, 2021
** PARTICULES
** File description:
** frame
*/

#include "struct.h"
#include "define.h"
#include "function.h"

frame_t *frame_create(unsigned int width, unsigned int height)
{
    frame_t *frame = malloc(sizeof(*frame));

    frame->width = width;
    frame->height = height;
    frame->pixels = malloc((W_BPP / 4) * width * height);
    return frame;
}

void frame_clear(frame_t *frame, sfColor color)
{
    for (unsigned int row = 0 ; row < frame->height ; row++)
        for (unsigned int col = 0 ; col < frame->width ; col++)
            my_put_pixel(frame, col, row, color);
}

void frame_destroy(frame_t *frame)
{
    free(frame->pixels);
    free(frame);
}

void my_put_pixel(frame_t *frame, unsigned int x, unsigned int y,
                    sfColor color)
{
    unsigned int pos = ((y * frame->width + x) * 4);

    if (pos > (frame->width * frame->height * 4))
        return;
    frame->pixels[pos] = color.r;
    frame->pixels[pos + 1] = color.g;
    frame->pixels[pos + 2] = color.b;
    frame->pixels[pos + 3] = color.a;
}

void draw_line(frame_t *frame, sfVector2f point_a,
                sfVector2f point_b, sfColor color)
{
    int dx = point_b.x - point_a.x;
    int dy = point_b.y - point_a.y;
    float x = point_a.x;
    float y = point_a.y;
    unsigned int steps = (abs(dx) > abs(dy)) ? abs(dx) : abs(dy);

    for (unsigned int i = 0; i < steps + 1; i++) {
        my_put_pixel(frame, x, y, color);
        x = x + (dx / (float)steps);
        y = y + (dy / (float)steps);
    }
}