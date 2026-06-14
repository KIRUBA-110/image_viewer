#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <stdio.h>

int main(int args, char *argv[])
{
    if(args != 2)
    {
        printf("Usage: %s image.jpg\n", argv[0]);
        return 1;
    }

    if(SDL_Init(SDL_INIT_VIDEO) != 0)
    {
        printf("SDL init failed\n");
        return 1;
    }

    if(!(IMG_Init(IMG_INIT_JPG) & IMG_INIT_JPG))
    {
        printf("SDL_image init failed\n");
        SDL_Quit();
        return 1;
    }

    SDL_Surface *img = IMG_Load(argv[1]);

    if(!img)
    {
        printf("Image load failed\n");
        IMG_Quit();
        SDL_Quit();
        return 1;
    }

    SDL_Window *window =
        SDL_CreateWindow(
            "Image Viewer",
            SDL_WINDOWPOS_CENTERED,
            SDL_WINDOWPOS_CENTERED,
            img->w,
            img->h,
            0
        );

    if(!window)
    {
        printf("Window creation failed\n");
        SDL_FreeSurface(img);
        IMG_Quit();
        SDL_Quit();
        return 1;
    }

    SDL_Renderer *render =
        SDL_CreateRenderer(
            window,
            -1,
            SDL_RENDERER_ACCELERATED
        );

    if(!render)
    {
        printf("Renderer creation failed\n");
        SDL_DestroyWindow(window);
        SDL_FreeSurface(img);
        IMG_Quit();
        SDL_Quit();
        return 1;
    }

    SDL_Texture *texture =
        SDL_CreateTextureFromSurface(
            render,
            img
        );

    SDL_FreeSurface(img);

    int running = 1;
    SDL_Event event;

    while(running)
    {
        while(SDL_PollEvent(&event))
        {
            if(event.type == SDL_QUIT)
            {
                running = 0;
            }
        }

        SDL_RenderClear(render);

        SDL_RenderCopy(
            render,
            texture,
            NULL,
            NULL
        );

        SDL_RenderPresent(render);

        SDL_Delay(10);
    }

    SDL_DestroyTexture(texture);
    SDL_DestroyRenderer(render);
    SDL_DestroyWindow(window);

    IMG_Quit();
    SDL_Quit();

    return 0;
}
