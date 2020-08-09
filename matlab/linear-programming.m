clc
clear

c=[400;100];
a=[8 10;2 6;1 0];
b=[80;36;6];
intcon=[1,2]
[x,y]=intlinprog(-c,intcon,a,b,[],[],zeros(2,1));
x
y
