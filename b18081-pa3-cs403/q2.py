import math
import mmh3
import random as rd
 
#reading datasets, & creating a stream of data
def data_receiver(file):
    with open("tst.txt", 'r') as f:
        content = f.readlines()
    d=[x.strip() for x in content] 
    tt=[]
    for x in d:
        y=(list(x.split()))
        for z in y:
            tt.append(z)
    return tt
        
def hash_count_receiver(m, n):
        '''
        Returns the hash function(k) to be used using the
        following formula
        k = (m/n) * lg(2)
        m : int size of bit array
        n : int number of items expected to be stored in filter
        '''
        k=(m/n) * math.log(2)
        return int(k)
    
def split_dt(l):
    sz=len(l)
    tds=int(0.05*sz)
    tsd=l[0:tds]
    trd=l[tds:]
    return trd, tsd

def add(item, m, k, btst):
        #Add an item in the filter
        for i in range(k):
            # create bitset for given item.
            # i work as seed to mmh3.hash() function
            # With different seed, bitset created is different
            bst=mmh3.hash(item, i) % m
            # set the bit True in bit_array
            btst[bst]=True
 
def check(item,m,k,btst):
    #Check for existence of an item in filter
    for i in range(k):
        bst=mmh3.hash(item, i) % m
        if btst[bst]==False:
                # if any of bit is False then,it's not present in filter
                # else there is probability that it exist
                return False
        return True

def function1(m, file):
    tt=data_receiver(file)
    n=len(list(set(tt)))
    k=hash_count_receiver(m, n)
    print("Total number of elements: ",n)
    btst=[0 for i in range(m)]
    tr,ts=split_dt(tt)
    n=len(tr)
    for x in tr:
        add(x,m,k,btst)
    truep,falsep,truen,falsen=0,0,0,0
    for x in ts:
        truep+=1
        if check(x,m,k,btst): falsep+=1
        else: falsen+=1
    print("True positives count: ",truep)
    print("False positives count: ",falsep)
    print("True negatives count: ",truen)
    print("False negatives count: ",falsen)
    print('\n\n\n')
    
    ts2=[]
    for i in range(len(ts)):
        x=rd.randint(int(max(tt)), int(100*int(max(tt))))
        ts2.append(bytes(x))
        
    truep,falsep,truen,falsen=0,0,0,0
    for x in ts2:
        truep+=1
        if check(x, m, k, btst): falsep+=1
        else: falsen+=1
    print("True positives count: ",truep)
    print("False positives count: ",falsep)
    print("True negatives count: ",truen)
    print("False negatives count: ",falsen)

def data_function(file):
    mm=[50, 70]
    for m in mm:
        function1(m, file)
    
complete_dataset=['tst.txt','dt1.txt','dt2.txt','dt3.txt']

for i in range(1):
    data_function(complete_dataset[i]) 
