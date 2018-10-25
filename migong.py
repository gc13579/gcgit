f=open('c:/Users/gc/Desktop/gc.txt', 'r')
maze1=list(f.read())
y=0
w=len(maze1)
while(y<w):#除去txt文件中的'\n'
	if(maze1[y]=='\n'):
		maze1.pop(y)
		w=len(maze1)
		y=0
	if(maze1[y]!='\n'):
		y=y+1


maze=[[]for i in range(10)]#将一维转化为二维保存
j=0
i=0
while(j<100):
	maze[i].append(maze1[j])
	j=j+1
	if(j%10==0):
		i=i+1

for r in range(10):#将list中str元素变为整形
	for t in range(10):
		maze[r][t]=int(maze[r][t])
		
for r in range(10):#输出迷宫
	for t in range(10):
		print(maze[r][t],end='')
	print()

def search():#走迷宫
	x=y=i=j=di=k=top=0
	l=[[]]
	maze[i][j] == 1
	l2=[(0,0)]
	print(l2[-1])
	while(top>=0):
		i=x
		j=y
		while(di==0):
			if(y<=9):
				i=x
				j=y+1
				if(i<=9 and j<=9):#移动后防止下标越界
					break
				else:#越界则不按照当前方向移动，朝下一方向移动:di=di+1
					j=y-1
					di=di+1
		while(di==1):
			if(x<=9):
				i=x+1
				j=y
				if (i<=9 and j<=9):
					break
				else:
					i = x-1
					di = di+1
		while(di==2):
			if(x>0):
				i=x-1
				j=y
				if (i<=9 and j<=9):
					break
				else:
					i = x+1
					di = di+1
		while(di==3):
			if(y>0):
				i=x
				j=y-1
				if (i<=9 and j<=9):
					break
				else:
					j = y+1
					di = di+1
		if(0 == maze[i][j]):
			l.insert(top,(i,j))
			x=i
			y=j
			top=top+1
			maze[i][j]=1
			di=0
			if (i == 9 and j == 9):
				while (k < top):
					print(l[k])
					k = k + 1
				break
		else:
			di=di+1
	top=top-1
search()
f.close()