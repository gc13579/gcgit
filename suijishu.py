import random
a1=10
b1=10
id2=0
l=[]
N=400
class mul(object):
	def __init__(self,a2,b2):
		self.a=a2
		self.b=b2
		self.id=id2

while(a1<99):
	while(b1<99):
		l.insert(id2,mul(a1,b1))#在list第id2个元素处添加mul的对象
		b1=b1+1
		id2=id2+1
	b1=10
	a1=a1+1#顺序生成10*10~99*99

random.shuffle(l)#打乱
id2=0
i=0
while(id2<N):
	print(('%d*%d='%(l[id2].a,l[id2].b)),end='  ')
	i=i+1
	if(i%10==0):
		print()
	id2=id2+1
id2=0
i=0
while(id2<N):
	print( ('%d*%d=%d'%(l[id2].a,l[id2].b,l[id2].a*l[id2].b)),end='  ' )
	i=i+1
	if(i%10==0):
		print()
	id2=id2+1
	
	




	


		




		
		
	

