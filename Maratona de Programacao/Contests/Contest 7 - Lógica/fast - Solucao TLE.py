t = int(raw_input())
while(t>0):
	l1,l2 = raw_input().split()
	l1 = int(l1)
	l2 = int(l2)
	l3 = (l1+l2)*(l1+l2)
	l3 = l3/4
	l4 = (l1-l2)*(l1-l2)
	l4 = l4/4
	print (l3-l4)
	t=t-1;
