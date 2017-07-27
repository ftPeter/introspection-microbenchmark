#!/Users/peter/anaconda/bin/python
i=0

"""
while i < 128:
    print "sum+=p[%d]+p[%d];sum+=p[%d]+p[%d];sum+=p[%d]+p[%d];" % ( i, i+1, i+2, i+3, i+4, i+5 )
    i = i + 6

while i < 128:
    print "sum+=p[%d]+p[%d]+p[%d];" % ( i, i+1, i+2)
    i = i + 3
while i < 128:
    print "sum+=p[%d];sum+=p[%d];" % (i, i+1),
    print "sum+=p[%d];sum+=p[%d];" % (i+2, i+3)
    i = i + 4
while i < 128:
    print "sum+=p[%d];sum+=p[%d];" % (i, i+1),
    print "temp_reg+=2.5;",
    print "sum+=p[%d];sum+=p[%d];" % (i+2, i+3),
    print "temp_reg+=2.5;"
    i = i + 4
while i < 128:
    print "sum+=p[%d];sum+=p[%d];sum+=p[%d];sum+=p[%d];" % ( i, i+1, i+2,i+3),
    print "temp_reg+=2.5;",
    print "temp_reg+=2.5;"
    i = i + 4
while i < 128:
    print "sum+=p[%d];sum+=p[%d];sum+=p[%d];sum+=p[%d];" % ( i, i+1, i+2,i+3),
    i = i + 4
    print "sum+=2.5;",
    print "sum+=p[%d];sum+=p[%d];sum+=p[%d];sum+=p[%d];" % ( i, i+1, i+2,i+3),
    i = i + 4
    print "sum+=2.5;"
"""
while i < 128:
    print "sum=sum^p[%d];sum=sum^p[%d];sum=sum^p[%d];sum=sum^p[%d];" % ( i, i+1, i+2, i+3 )
    i=i+4

