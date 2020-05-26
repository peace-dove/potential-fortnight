%% 数据来源 https://archive.ics.uci.edu/ml/datasets/wine+quality 数据集

%% 清空环境变量
clear
clc

%% 对每一个物理化学属性进行对比，一个做代表，其余注释，便于逐项比较
%% 比较时可以手工将该段代码取消注释，再将其他所有部分注释
%% fixed acidity
t1=xlsread('red.xlsx','Sheet 1','B2:B1600');
%t2=xlsread('white.xlsx','Sheet 1','B2:B4899');
t2=xlsread('white.xlsx','Sheet 1','B2:B1600'); % 对同一数据量的分布比较
subplot(1,2,1);
hist(t1,20);
title('the fixed acidity of red wine');
subplot(1,2,2);
hist(t2,20);
title('the fixed acidity of white wine');
%% volatile acidity
% t1=xlsread('red.xlsx','Sheet 1','C2:C1600');
% t2=xlsread('white.xlsx','Sheet 1','C2:C4899');
% subplot(1,2,1);
% hist(t1,20);
% title('the volatile acidity of red wine');
% subplot(1,2,2);
% hist(t2,20);
% title('the volatile acidity of white wine');
%% citric acid
% t1=xlsread('red.xlsx','Sheet 1','D2:D1600');
% t2=xlsread('white.xlsx','Sheet 1','D2:D4899');
% subplot(1,2,1);
% hist(t1,20);
% title('the citric acid of red wine');
% subplot(1,2,2);
% hist(t2,20);
% title('the citric acid of white wine');
%% residual sugar
% t1=xlsread('red.xlsx','Sheet 1','E2:E1600');
% t2=xlsread('white.xlsx','Sheet 1','E2:E4899');
% subplot(1,2,1);
% hist(t1,20);
% title('the residual sugar of red wine');
% subplot(1,2,2);
% hist(t2,20);
% title('the residual sugar of white wine');
%% chlorides
% t1=xlsread('red.xlsx','Sheet 1','F2:F1600');
% t2=xlsread('white.xlsx','Sheet 1','F2:F4899');
% subplot(1,2,1);
% hist(t1,10);
% title('the chlorides of red wine');
% subplot(1,2,2);
% hist(t2,10);
% title('the chlorides of white wine');
%% free sulfur dioxide
% t1=xlsread('red.xlsx','Sheet 1','G2:G1600');
% t2=xlsread('white.xlsx','Sheet 1','G2:G4899');
% subplot(1,2,1);
% hist(t1,20);
% title('the free sulfur dioxide of red wine');
% subplot(1,2,2);
% hist(t2,20);
% title('the free sulfur dioxide of white wine');
%% total sulfur dioxide
% t1=xlsread('red.xlsx','Sheet 1','H2:H1600');
% t2=xlsread('white.xlsx','Sheet 1','H2:H4899');
% subplot(1,2,1);
% hist(t1,20);
% title('the total sulfur dioxide of red wine');
% subplot(1,2,2);
% hist(t2,20);
% title('the total sulfur dioxide of white wine');
%% density
% t1=xlsread('red.xlsx','Sheet 1','I2:I1600');
% t2=xlsread('white.xlsx','Sheet 1','I2:I4899');
% subplot(1,2,1);
% hist(t1,20);
% title('the density of red wine');
% subplot(1,2,2);
% hist(t2,20);
% title('the density of white wine');
%% pH
% t1=xlsread('red.xlsx','Sheet 1','J2:J1600');
% t2=xlsread('white.xlsx','Sheet 1','J2:J4899');
% subplot(1,2,1);
% hist(t1,20);
% title('the pH of red wine');
% subplot(1,2,2);
% hist(t2,20);
% title('the pH of white wine');
%% sulphates
% t1=xlsread('red.xlsx','Sheet 1','K2:K1600');
% t2=xlsread('white.xlsx','Sheet 1','K2:K4899');
% subplot(1,2,1);
% hist(t1,20);
% title('the sulphates of red wine');
% subplot(1,2,2);
% hist(t2,20);
% title('the sulphates of white wine');
%% alcohol
% t1=xlsread('red.xlsx','Sheet 1','L2:L1600');
% t2=xlsread('white.xlsx','Sheet 1','L2:L4899');
% subplot(1,2,1);
% hist(t1,20);
% title('the alcohol of red wine');
% subplot(1,2,2);
% hist(t2,20);
% title('the alcohol of white wine');
%% quality
% t1=xlsread('red.xlsx','Sheet 1','M2:M1600');
% t2=xlsread('white.xlsx','Sheet 1','M2:M4899');
% subplot(1,2,1);
% hist(t1,6);
% title('the quality of red wine');
% subplot(1,2,2);
% hist(t2,6);
% title('the quality of white wine');
%% 数据相关性分析
%% 数据导入
t1=xlsread('red.xlsx','Sheet 1','C2:C1000');
t2=xlsread('red.xlsx','Sheet 1','D2:D1000');
t3=xlsread('red.xlsx','Sheet 1','E2:E1000');
t4=xlsread('red.xlsx','Sheet 1','H2:H1000');
t5=xlsread('red.xlsx','Sheet 1','K2:K1000');
t6=xlsread('red.xlsx','Sheet 1','L2:L1000');

tt1=xlsread('white.xlsx','Sheet 1','C2:C1000');
tt2=xlsread('white.xlsx','Sheet 1','D2:D1000');
tt3=xlsread('white.xlsx','Sheet 1','E2:E1000');
tt4=xlsread('white.xlsx','Sheet 1','H2:H1000');
tt5=xlsread('white.xlsx','Sheet 1','K2:K1000');
tt6=xlsread('white.xlsx','Sheet 1','L2:L1000');

input=[[t1' tt1'];[t2' tt2'];[t3' tt3'];[t4' tt4'];[t5' tt5'];[t6' tt6']];

output1=xlsread('red.xlsx','Sheet 1','A2:A1000');
output2=xlsread('white.xlsx','Sheet 1','A2:A1000');
output=[output1' output2'];

d=[input;output];
c=cov(d);%会得到协方差矩阵和相关系数矩阵
r=corrcoef(d);%矩阵非常大，只是举个例子
