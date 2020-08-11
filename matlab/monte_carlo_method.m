%% learn from other people
%% 清空环境变量
clc
clear
%% Monte Carlo方法计算π
r=1;
center_x=1;
center_y=1;
num=100000;%随机样本数
s=rng;
rng(s);
sample_point=2*rand(2,num);
total_in=0;
for i=1:num
    distance=sqrt((sample_point(1,i)-1)^2+(sample_point(2,i)-1)^2);
    if distance<1
        total_in=total_in+1;
    end
end
my_pi=total_in/num*4;
fprintf('Result:\nπ=%.4f\n',my_pi);
error=abs((pi-my_pi)/pi);
fprintf('Error：%.4f\n',error);
