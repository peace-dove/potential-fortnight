clear
clc

tic
hold on
axis([0 1 0 1]);
grid
A=[0,0];
B=[0,1];
C=[1,1];
D=[1,0];
d=norm(A-B);
k=0;t=0;s=0;
v=1;dt=0.001;K=1;
while k<1000
k=k+1;t=t+dt;s=s+dt*v;
plot(A(1),A(2),'b.','markersize',15);
plot(B(1),B(2),'b.','markersize',15);
plot(C(1),C(2),'b.','markersize',15);
plot(D(1),D(2),'b.','markersize',15);
e1=B-A;d=norm(e1);e2=C-B;e3=D-C;e4=A-D;
fprintf('k=%.0f d=%.3f t=%.3f s=%.4f\n',k,d,t,s)
if d<=0.0001
break;
end;
e1=e1/d;e2=e2/d;e3=e3/d;e4=e4/d;
A=A+K*v*dt*e1;
B=B+K*v*dt*e2;
C=C+K*v*dt*e3;
D=D+K*v*dt*e4;
pause(0.0001)
end
toc
