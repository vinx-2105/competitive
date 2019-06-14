MOD = 1000000007

t = int(input())
while(t>0):
    n, k = input().split()
    n, k = [int(n), int(k)]
    d = n-1#difference of AP
    a = (k-1)%d#first term of AP
    l = k-1#last term of AP
    m = ((l-a)//d)+1;#number of terms in AP

    temp = a+l#(a+l.;p54r;)

    sum = (m*temp)//2#n*(a+l)/2

    print (int(sum%MOD))
    t=t-1