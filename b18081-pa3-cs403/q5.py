import math
import mmh3
import matplotlib.pyplot as plt

#reading datasets, & creating a stream of data
def data_receiver(file):
    tt=[]
    with open(file, 'r') as f:
        content=f.readlines()
    d=[x.strip() for x in content] 
    
    for x in d:
        y=(list(x.split()))
        for z in y:
            tt.append(z)
    return tt


def f2_norm(lt):
    ct=0;
    dlt=list(set(lt))
    for x in dlt:
        ct+=math.pow(lt.count(x), 2)
    return ct

def clc(lt):
    ct=0;
    dlt=list(set(lt))
    tfq=[[lt.count(x), x] for x in dlt]
    for i in range(len(tfq)):
        ch=mmh3.hash(tfq[i][1], i) % 2
        if ch==0: ct-=(tfq[i][0])
        else: ct+=(tfq[i][0])
    return ct*ct

def mean_calculator(lt):
    return sum(lt) / len(lt)

def median_calculator(lt):
    lt.sort()
    mid = len(lt) // 2
    res = (lt[mid] + lt[~mid]) / 2
    return res

complete_values=[[10,5],[3,7]]

y_ori,y_pred=[],[]

def function1(file,k,t):
    tt=data_receiver(file)
    kobs=[[clc(tt) for i in range(k)] for i in range(t)]
    kobs=[mean_calculator(lt) for lt in kobs]
    ov=f2_norm(tt)
    ev=median_calculator(kobs)
    print("Original F_2 norm: ",ov)
    print("Estimated F_2 norm: ",ev)
    y_ori.append(ov)
    y_pred.append(ev)
    
def data_function(file):
    y_ori.clear()
    y_pred.clear()
    for v in complete_values:
        function1(file, v[1], v[0])
    plt.bar([str(complete_values[i]) for i in range(len(complete_values))],[abs(y_pred[i]-y_ori[i]) for i in range(len(complete_values))],width=0.35)
    plt.show()

complete_dataset=['tst.txt', 'dt1.txt', 'dt2.txt', 'dt3.txt']

for i in range(1):
    data_function(complete_dataset[i])

