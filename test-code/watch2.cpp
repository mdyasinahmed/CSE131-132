#include <SDL.h>
#include <cmath>
#include <ctime>

#define S_N_L (radius - 10)      // Second Needle Length
#define S_N_C 0xFF0000            // Second needle Color (Red)
#define M_N_L (radius - 20)      // Minute Needle Length
#define M_N_C 0xFFA500            // Minute needle Color (Orange)
#define H_N_L (radius - (radius / 2))  // Hour Needle Length
#define H_N_C 0x00FFFF            // Hour needle Color (Cyan)

const int width = 640;
const int height = 480;
const int radius = 100;

void drawClockFace(SDL_Renderer* renderer) {
    int centerX = width / 2;
    int centerY = height / 2;
    int theta = 0;

    // Draw Clock Border
    for (int i = 0; i < 9; ++i) {
        SDL_SetRenderDrawColor(renderer, 165, 42, 42, 255); // Brown
        SDL_RenderDrawLine(renderer, centerX + (radius + 13 + i) * cos(theta * M_PI / 180),
                           centerY + (radius + 13 + i) * sin(theta * M_PI / 180),
                           centerX + (radius + 14 + i) * cos(theta * M_PI / 180),
                           centerY + (radius + 14 + i) * sin(theta * M_PI / 180));
        theta += 30;
    }

    // Draw Numeric Points
    theta = 0;
    for (int i = 0; i < 12; ++i) {
        int x = centerX + radius * cos(theta * M_PI / 180);
        int y = centerY + radius * sin(theta * M_PI / 180);
        SDL_RenderDrawPoint(renderer, x, y);
        theta += 30;
    }

    // Drawing Clock Center
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255); // White
    SDL_RenderDrawPoint(renderer, centerX, centerY);
}

void drawNeedle(SDL_Renderer* renderer, int cx, int cy, float length, float angle, Uint32 color) {
    SDL_SetRenderDrawColor(renderer, color >> 16, (color >> 8) & 0xFF, color & 0xFF, 255);
    SDL_RenderDrawLine(renderer, cx, cy, cx + length * cos(angle), cy + length * sin(angle));
}

int main() {
    SDL_Window* window;
    SDL_Renderer* renderer;

    SDL_Init(SDL_INIT_VIDEO);

    SDL_CreateWindowAndRenderer(width, height, 0, &window, &renderer);

    bool quit = false;
    int hour, minute, second;

    while (!quit) {
        SDL_Event event;
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                quit = true;
            }
        }

        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255); // Clear screen
        SDL_RenderClear(renderer);

        drawClockFace(renderer);

        time_t rawtime;
        struct tm* t;
        time(&rawtime);
        t = localtime(&rawtime);

        hour = t->tm_hour;
        minute = t->tm_min;
        second = t->tm_sec;

        drawNeedle(renderer, width / 2, height / 2, S_N_L, -90 + second * 6 * (M_PI / 180), S_N_C);
        drawNeedle(renderer, width / 2, height / 2, M_N_L, -90 + minute * 6 * (M_PI / 180), M_N_C);
        drawNeedle(renderer, width / 2, height / 2, H_N_L, -90 + (hour % 12) * 30 * (M_PI / 180) + minute * 0.5 * (M_PI / 180), H_N_C);

        SDL_RenderPresent(renderer);
        SDL_Delay(100);
    }

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}
