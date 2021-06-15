import random as rd

#reading datasets, & creating a stream of data
def data_receiver(file):
    with open(file, 'r') as f:
        content=f.readlines()
    d=[x.strip() for x in content] 
    tt=[]
    for x in d:
        y=(list(x.split()))
        for z in y:
            tt.append(int(z))
    return tt

#splitting data in required proportion
def test_data_receiver(tt):
    ln=int(0.05*len(tt))
    lts=tt[0:ln]
    for i in range(ln):
        lts.append(rd.randint(min(tt),max(tt)))
    return lts
     
   
def S(n,tt):
    return set(tt)

# utility function to return a prime number close to m
def primo(m,c):
    c=list(set(c))
    for x in range(1,max(c)**2):
        if x>1: 
            for i in range(2,x):
                if(x%i)==0:break
            else:
                if x>max(c):
                    return x

def a_b(p):
	l=[x for x in range(p)]
	f=rd.sample(l,2)
	return f[0], f[1]

def hash(a,b,p,m):
	return lambda k : ((a*k+b)%p)%m

def iscorrect1(c,n):
	x=[]
	for i in range(n):
		x.append(c[i]**2)
	s=sum(x)
	if s<4*n:
		return True
	return False

def search(x,h,p,t):
    i=h(x)
    try:
        a=t[i]['a']
        b=t[i]['b']
        m=t[i]['m']
        hi=hash(a,b,p,m)
        k=hi(x)
        if t[i]['S'][k]==x:
            return 2
        elif t[i]['S'][k]==-1:return 1
    except KeyError:
        return 0

def data_function(file):
    tt=data_receiver(file)
    tstd=test_data_receiver(tt)
    n=len(tt)
    m=n
    conjunto=S(n, tt) #getting all distinct values from dataset
    p=primo(m,conjunto)   #Finding a mod prime value, close to m
    table=[{} for x in range(m)]  #Allocating memory for hash table.
    m_i=[]    #Final list of length of all m slots.
    #Temporary dictionary to simulate the n-slots
    sub_conj={i:[] for i in range(m)}
    
    #determining first-level hash-function h, until it becomes 'perfect'
    while 1:
        #Using Universal Hash Family,h=((a*x+b)%p)%m
    	a,b=a_b(p)
    	c=[0 for i in range(m)]
    	m_i=[]
    	for k in conjunto:
    		h=hash(a,b,p,m)
    		i=h(k)
    		c[i]=c[i] + 1
    		sub_conj[i].append(k)
            
    	if iscorrect1(c, n):
    		for i in c:
    			m_i.append(i**2)
    		break
    
    #removing 0-length slots
    for i in range(n):
    	if len(sub_conj[i])==0:
    		del(sub_conj[i])
    
    #Table initialization
    for i in range(n):
    	if m_i[i] != 0:
    		table[i]['m']=m_i[i]
    		table[i]['S']=[-1 for i in range(m_i[i])]
    
    ci=[] 
    
    #determiner h_j hash function for second level table
    for i in sub_conj:
        #Infinite loop will run until there is even-one collision in any slot
    	while 1:
    		a,b=a_b(p)
    		m=table[i]['m']   # m - length of this ith slot.
    		ci=[0 for x in range(m)]
    		hi=hash(a,b,p,m)
    		for k in sub_conj[i]:
    			j=hi(k)
    			table[i]['S'][j]=k
    			if ci[j] == 0:
    				ci[j] = 1
    			elif ci[j] >= 1:
    				ci[j] = -1
    		if -1 not in ci:
    			table[i]['a']=a
    			table[i]['b']=b
    			break
            #On finding a correct hash function for ith slot, we break.
   
    truep,falsep,truen,falsen=0,0,0,0
    for x in tstd:
        flag=search(x,h,p,table)
        if flag==2:
            truep+=1
        elif flag==-1:
            falsep+=1
        else:
            falsen+=1
    print("True positives count: ",truenp)
    print("False positives count: ",falsep)
    print("True negatives count: ",truen)
    print("False negatives count: ",falsen)
    
    conf_matrix=[[truep,falsep],[truen,falsen]]
    print('Confusion-matrix: ',conf_matrix)

complete_dataset=['tst.txt', 'dt1.txt', 'dt2.txt', 'dt3.txt']

for i in range(2):
    data_function(complete_dataset[i])  