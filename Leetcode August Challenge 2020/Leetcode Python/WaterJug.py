x = int(input("Enter initial capacity of jug 1: "))
y = int(input("Enter initial capacity of jug 2: "))
T = int(input("Enter Target capacity: "))
while True:
    r = int(input("Enter Rule Number to apply: "))
    if(r==1):
        if x<4:
            x=4
    if(r==2):
        if y<3:
            y=3
    if(r==5):
        if x>0:
            x=0
    if(r==6):
        if y>0:
            y=0
    if(r==7):
        if x+y>=4 and y>0:
            x,y = 4, y - (4-x)
    if(r==8):
        if x+y>=3 and x>0:
            x,y = x-(3-y), 3
    if(r==9):
        if x+y<=4 and y>0:
            x,y = x+y, 0
    if(r==10):
        if x+y<=3 and x>0:
            x,y = 0, x+y
    if(r==11):
        if y>=2:
            x,y = x+2, y-2
    if(r==12):
        if x>=2:
            x,y = x-2, y+2

    print("X: ", x)
    print("Y: ", y)
    if x==T or y==T:
        print(T," liters water obtained.")
        break

