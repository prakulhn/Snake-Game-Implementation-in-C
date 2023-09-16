// C program to build the snake game

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>  // Include conio.h for kbhit() and getch() on Windows
#include <windows.h> // Include windows.h for Sleep() on Windows
#include <unistd.h> // Include unistd.h for usleep() on Unix-like systems

int i, j, width = 25, height = 25;
int gameover, score;
int x, y, fruitx, fruity, flag;

// Function to generate fruit within the boundary
void setup()
{
    gameover = 0;
    x = height / 2;
    y = width / 2;
label1:
    fruitx = rand() % 25;
    if (fruitx == 0)
        goto label1;
label2:
    fruity = rand() % 25;
    if (fruity == 0)
        goto label2;
    score = 0;
}

// Function to draw boundaries
void draw()
{
    system("cls");
    for (i = 0; i < height; i++)
    {
        for (j = 0; j < width; j++)
        {
            if (i == 0 || i == height - 1 || j == 0 || j == width - 1)
            {
                printf("#");
            }
            else
            {
                if (i == x && j == y)
                    printf("0");
                else if (i == fruitx && j == fruity)
                    printf("*");
                else
                    printf(" ");
            }
        }
        printf("\n");
    }

    // Prints the score after the game ends
    printf("score=%d", score);
    printf("\n");
    printf("Enter X to quit the game");
}

void input()
{
    if (kbhit())
    {
        switch (getch())
        {
        case 'a':
            flag = 1;
            break;
        case 's':
            flag = 2;
            break;
        case 'd':
            flag = 3;
            break;
        case 'w':
            flag = 4;
            break;
        case 'x':
            gameover = 1;
            break;
        }
    }
}

// Function for the logic behind each movement
void logic()
{
#ifdef _WIN32
    Sleep(10); // Sleep for 10 milliseconds (Windows)
#else
    usleep(10000); // Sleep for 10 milliseconds (Unix-like systems)
#endif

    switch (flag)
    {
    case 1:
        y--;
        break;
    case 2:
        x++;
        break;
    case 3:
        y++;
        break;
    case 4:
        x--;
        break;
    default:
        break;
    }

    // If the game is over
    if (x < 0 || x >= height || y < 0 || y >= width)
        gameover = 1;

    // If the snake reaches the fruit
    // Then update the score and generate new fruit
    if (x == fruitx && y == fruity)
    {
    label3:
        fruitx = rand() % 25;
        if (fruitx == 0)
            goto label3;
    label4:
        fruity = rand() % 25;
        if (fruity == 0)
            goto label4;
        score += 10;
    }
}

// Driver code
int main()
{
    int m, n;

    // Generate boundary
    setup();

    // Until the game is over
    while (!gameover)
    {
        // Function Call
        draw();
        input();
        logic();
    }

    return 0;
}
