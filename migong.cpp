#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#define N 10
//int maze[N][N];

/*typedef struct
{
int x1,y1;
}direction;
direction move[4]={{0,1},{1,0},{0,-1},{-1,0}};*/

typedef struct box
{
	int x, y;
}box;
typedef struct sequenstack
{
	box data[100];
	int top;
}sst;
/*void init_maze()
{
int i, j, r;
srand(time(NULL));
for(i = 0; i < N; i++)
{
for(j = 0; j < N; j++)
{
r = rand() % 2;
if (!r)
{
r = rand() % 2;
}
maze[i][j] = r;
}
}
printf("迷宫初始化完成\n");
}*/
int maze[N][N] =
{
	0,0,1,1,1,1,1,1,1,1 ,
	1,0,0,0,0,0,1,1,0,1 ,
	1,1,0,1,0,0,0,1,0,1,
	1,0,0,0,0,1,1,0,0,1 ,
	1,0,1,1,0,0,1,0,0,1 ,
	1,0,0,0,1,0,1,0,0,1 ,
	1,0,1,0,0,0,1,0,0,1 ,
	1,0,1,1,1,0,1,1,0,1 ,
	1,1,0,0,0,0,0,0,0,0 ,
	1,1,1,1,1,1,1,1,0,0 
};

void print_maze()
{
	int i, j;
	for (i = 0; i < N; i++)
	{
		for (j = 0; j < N; j++)
		{
			printf("%2d", maze[i][j]);
		}
		printf("\n");
	}
	printf("0 -- 表示通 1 -- 表示不通\n从左下角走进去，从右上角走出来\n");
}



void search_maze()
{
	int i, j, di, k=1;
	sst st;
	st.top = -1;
	st.top++;
	st.data[st.top].x = 0;
	st.data[st.top].y = 0;
	maze[0][0] = 1;
	while (st.top>-1)
	{
		i = st.data[st.top].x;
		j = st.data[st.top].y;
		di = 0;
		while (di<4)
		{
			switch (di)
			{
			case 0:
				if (st.data[st.top].y + 1 < N)
				{
					i = st.data[st.top].x;
					j = st.data[st.top].y + 1;
					break;
				}
			case 1:
				if (st.data[st.top].x + 1 < N)
				{
					i = st.data[st.top].x + 1;
					j = st.data[st.top].y;
					break;
				}
			case 2:
				if (st.data[st.top].y - 1 >= 0)
				{
					i = st.data[st.top].x;
					j = st.data[st.top].y - 1;
					break;
				}
			case 3:
				if (st.data[st.top].x - 1 >= 0)
				{
					i = st.data[st.top].x - 1;
					j = st.data[st.top].y;
					break;
				}
			}
			if (maze[i][j] == 0)
			{
				if (i == 9 && j == 9)
				{
					for (k = 0; k <= st.top; k++)
					{
						printf("\t(%d,%d)", st.data[k].x, st.data[k].y);
						printf("\n");
					}
					printf("\t(9,9)");
					return;
				}
				st.top++;
				st.data[st.top].x = i;
				st.data[st.top].y = j;
				maze[i][j] = 1;
				di = 0;
			}
			else
			{
				di++;
			}
		}
		st.top--;
		// 在此函数中补充代码
	}
}

int main()
{
	//init_maze();
	print_maze();
	search_maze();
	system("pause");
	return 0;
}