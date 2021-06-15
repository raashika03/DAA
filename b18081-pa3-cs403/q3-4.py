import math
import random as rd
import numpy as np
import matplotlib.pyplot as plt

#reading datasets, & creating a stream of data
def data_receiver(file):
    with open(file,'r') as f:
        content=f.readlines()
    d=[x.strip() for x in content] 
    tt=[]
    for x in d:
        y=(list(x.split()))
        for z in y:
            tt.append(int(z))
    return tt
        
m,n=0,0

#utility function to split data in required proportion
def split_data(l):
    sizee=len(l)
    tds=int(0.05*sizee)
    tsd=l[0:tds]
    trd=l[tds:]
    return trd, tsd

def f1_norm(lt):
    ct=0;
    dlt=list(set(lt))
    for x in dlt:
        ct+=math.pow(lt.count(x), 1)
    return ct   

#utility function to return a prime number close to m,
def primo(m,c):
    c=list(set(c))
    for x in range(1,max(c)**2):
        if x>1: 
            for i in range(2,x):
                if (x%i)==0:break
            else:
                if x>max(c):
                    return x

def a_b(p):
	l=[x for x in range(p)]
	f=rd.sample(l,2)
	return f[0], f[1]

def hash(a,b,p,m):
	return lambda k : ((a*k+b)%p)%m

def calc1(dt,k,t,p):
    cms=[0 for i in range(k)]
    a,b=a_b(p)
    hf=hash(a, b, p, k)
    for x in dt:
        ind=hf(x)
        cms[ind]+=1
    return cms, hf

def est_num1(cmst,x,t):
    mf=1000000
    for i in range(t):
        ind=cmst[i][1](x)
        mf=min(mf,cmst[i][0][ind])
    return mf

def calc2(dt,k,t,p):
    cms=[0 for i in range(k)]
    a, b=a_b(p)
    hf1=hash(a, b, p, k)
    a,b=a_b(p)
    hf2=hash(a, b, p, k)
    for x in dt:
        ind1,ind2=hf1(x), hf2(x)%2
        if ind2==0: ind2=-1
        cms[ind1]+=ind2
    return cms, hf1, hf2

def median_calculator(lt):
    if(len(lt)==0):return 0
    lt.sort()
    mid=len(lt) // 2
    res=(lt[mid] + lt[~mid]) / 2
    return res

def est_num2(cmt,x,t):
    lt=[]
    for i in range(t):
        ind1,ind2=cmt[i][1](x), cmt[i][2](x)
        if ind2==0: ind2=-1
        lt.append(cmt[i][0][ind1]*ind2)
    return median_calculator(lt)



def function1(k,t, tt, tsd):
    p=primo(k,tt)
    
    cmst=[calc1(tt,k,t,p) for i in range(t)]
    y_act,y_pred=[], []
    for x in tsd:
        c1=tt.count(x)
        c2=est_num1(cmst,x,t)
        y_act.append(c1)
        y_pred.append(c2)
    
    MSE=np.square(np.subtract(y_act,y_pred)).mean()
    RMSE=math.sqrt(MSE)
    print("Root Mean Square Error for CMS:\n", RMSE)
    cms_rmse.append(RMSE)
    
    cmt=[calc2(tt, k, t, p) for i in range(t)]
    y_act,y_pred=[],[]
    for x in tsd:
        c1=tt.count(x)
        c2=est_num2(cmt,x,t)
        y_act.append(c1)
        y_pred.append(c2)
    
    MSE=np.square(np.subtract(y_act,y_pred)).mean()
    RMSE=math.sqrt(MSE)
    print("Root Mean Square Error for CS:\n", RMSE)
    cm_rmse.append(RMSE)

all_values=[[50,50],[25,100],[250,10],[500,5]]
cms_rmse,cm_rmse=[],[]


def data_function(dataset):
    tt=data_receiver(dataset)
    trd,tsd=split_data(tt)
    for v in all_values:
        function1(v[1],v[0],tt,tsd)
    fig=plt.figure()
    plt.bar([str(all_values[i]) for i in range(4)],cms_rmse,width=0.35)
    plt.show()
    plt.bar([str(all_values[i]) for i in range(4)],cm_rmse,width=0.35)
    plt.show()
    
    fig1=plt.figure()
    ax=fig1.add_subplot(111)
    
    ind=[i for i in range(len(all_values))]
    ax.bar(ind,cms_rmse,width=0.35)
    ax.bar([i+0.35 for i in ind],cm_rmse,width=0.35)
    ax.set_ylabel('RMSE')
    ax.set_title('RMSE by CMS and CS')
    ax.set_xticks([d + 0.35 / 2 for d in ind])
    ax.set_xticklabels([str(all_values[i]) for i in range(4)])
    plt.show()

complete_dataset=['tst.txt','dt1.txt','dt2.txt','dt3.txt']

for i in range(2):
    cms_rmse.clear()
    cm_rmse.clear()
    data_function(complete_dataset[i])
