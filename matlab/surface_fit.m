%% Copyright 2020 Dc.SZL. All Rights Reserved. 
%%
clear
clc
%% using point to do surface fit
x=-5:1:5;
y=-5:1:5;
[xb,yb]=meshgrid(x,y);
zb=[13.6,-8.2,-14.8, -6.6,1.4,0,-3.8,1.4,13.6,16.8,0;
-8.2,-15.8,-7.9,2.2,3.8,0,0.6,7.3,10.1,0,-16.8;
-14.8,-7.9,2.5,5.8,2.3,0,2.7,5.1,0,- 10.1,-13.7;
-6.6,2.2,5.9,3.0,-0.3,0,1.9,0,-5.1,-7.3,-1.4;
1.4,3.8,2.3,0.3,0.9,0,0,-1.7,-2.7,-0.6,3.8;
0,0,0,0,0,0,0,0,0,0,0;
-3.8,0.6,2.7,1.7,0,0,0.9,0.3,-2.3,-3.8,-1.4;
1.4,7.3,5.1,0,-1.7,0,0.3,-3.1,-5.8,-2.2,6.6;
13.6,10.1,0,-5.1,-2.7,0,-2.3,5.8,-2.5,7.9,14.8;
16.8,0,-10.1,-7.3,-0.6,0,-3.8,-2.2,7.9,15.8,8.2; 
0,16.3,-13.6,-1.4,3.8,0,-1.4,6.6,14.8,8.2,-13.6];
subplot(1,2,1)
surf(xb,yb,zb)
%% fit surface
xc=-5:0.25:5;
yc=-5:0.25:5;
[xcb,ycb]=meshgrid(xc,yc);
zcb=interp2(xb,yb,zb,xcb,ycb,'spline');
subplot(1,2,2)
surf(xcb,ycb,zcb)
%% 
d=0.25;
[Fx,Fy]=gradient(zcb,d,d);
p=1;
q=1;
ss=0;
while q<10/d+1
while p<10/d+1
s=sqrt(1+Fx(p,q)^2+Fy(p,q)^2)*d*d;
ss=s+ss;
p=p+1;
end
p=1;
q=q+1;
end
ss