#include <stdio.h>
#include <stdlib.h>
#include <stdlib.h>

#define MAP_H 5
#define MAP_W 7     

struct t_queue{
    int front;
    int back;
    int qx[MAP_H * MAP_W];
    int qy[MAP_H * MAP_W];
};

int     bfs(int x, int y, char **map)
{
    int dx[4] = {1,-1, 0, 0};
    int dy[4]= {0,0,1,-1};

    struct t_queue q = {0, 0};

    q.qx[q.back] = x;
    q.qy[q.back] = y;
    q.back++;

    while (q.front < q.back)
    {
        int cx = q.qx[q.front];
        int cy = q.qy[q.front];
        q.front++;

        if(cx < 0 || cy < 0 || cx >= MAP_W || cy >= MAP_H)
                return 0;
        if(map[cy][cx] == '1' || map[cy][cx] == 'F')
            continue;
        if(map[cy][cx] == '0' || map[cy][cx] == 'N')
             return 0;
        if(map[cy][cx] == ' ')
              map[cy][cx] = 'F';
        for(int i = 0; i < 4 ; i++)
        {
            int nx = cx + dx[i];
            int ny = cy + dy[i];

            q.qx[q.back] = nx;
            q.qy[q.back] = ny;
            q.back++;
        }
    }
    return 1;
    
 
    
}

int     check_for_leak(char **map )
{
        int x = 0;
        int y = 0;
        while(x < 7)
        {
            y = -1;
            while(++y < 5)
            {
                if(map[y][x] == ' ')
                {
                    if(!bfs(x, y , map))
                        return 1;
                }
            }
            x++;
        }
        return 0;
}

int main()
{
        char *grid[] = {  // 7 columns to include null terminator
        "111111",
        "1N0  1",
        "100001",
        "1   01",
        "111111"
    };

    if(check_for_leak(grid))
        printf("there is a leak in the map\n");
    else 
        printf("the map is correct\n");
}