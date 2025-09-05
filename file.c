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
           if(x < 0 || y < 0 || x >= MAP_W || y >= MAP_H)
                 return 0;
            if(map[y][x] == '1' || map[y][x] = 'F')
                    return 0;
        if(map[y][x] == '0' || map[y][x] == 'N')
             return 1;
        if(map[y][x] == ' ')
              map[y][x] = 'F';
        add_to_neighbors(dx, dy);
    }
    
 
    
}

int     check_for_leak(char **map )
{
        int x = 0;
        int y = 0;
        while(x < 7)
        {
            y = 0;
            while(y < 5)
            {
                if(map[y][x] == ' ')
                {
                    if(!bfs(x, y , map))
                        return 0;
                }
            }

            x++;
        }
        return 1;
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