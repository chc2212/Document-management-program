
import random
count_up, count_down,count_enter,count_arr=0,0,0,0
word=["that", "com","windows","year","send","time","home","mom","tion","week","hour","thousand","suddenly","little","wit","then","data","before","only","hh","as","gift","look","respond","thata","afford","it","was","no","well","fix","cnask","nuy","ahead","thanks","leave","hello","greenly","mouth","bed","wow","dad","lid","wrong","true","embarrassed","planet","really","suffer","wet"]
count=0

    
while count < 30:
    count=count+1

    if exists("1340531067611.png"):
        count_arr=count_arr+1
        k=random.randint(1,3)#문자열 종류 결정
        k1=random.randint(1,5)#폴더경로형 문자열 샘플
        k2=random.randint(1,6)#파일경로형 문자열 샘플
        k3=random.randint(0,49)#단어 샘플
    
        if k==1:
            
            if k1==1:
                type("c:/program files")
                type(Key.ENTER)
            if k1==2:
                type("c:/test1")
                type(Key.ENTER)
            if k1==3:
                type("c:/test2")
                type(Key.ENTER)
            if k1==4:
                type("c:/test3")
                type(Key.ENTER)
                
        if k==2:
            
            if k2==1:
                type("c:/log.txt")
                type(Key.ENTER)
            if k2==2:
                type("c:/test1/test.txt")
                type(Key.ENTER)
            if k2==3:
                type("c:/test2/test.txt")
                type(Key.ENTER)
            if k2==4:
                type("c:/test3/test2.txt")
                type(Key.ENTER)
            if k2==5:
                type("c:/java.txt")
                type(Key.ENTER)
            if k2==6:
                type("c:/test4/pro.txt")
                type(Key.ENTER)


        if k==3:
            type(word[k3])
            type(Key.ENTER)  
      
    elif exists("CU-3.png"):
         
        i=random.randint(1,100)
        #print i
        if i<=10:
            type(Key.UP)
            count_up=count_up+1
                
        if i>10 and i<=70:
            type(Key.DOWN)
            count_down=count_down+1
              
        if i>70 and i<=100:
            #print "test"
            type(Key.ENTER)
            count_enter=count_enter+1
    
            
      
    
        

print count_up
print count_down
print count_enter
print count_arr

        
        
       
    