%% ��ջ�������
clear
clc

%% ѵ����
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

%% ���ݹ�һ��
[inputn,inputnps]=mapminmax(input,0,1);
[outputn,outputnps]=mapminmax(output,0,1);
%% ѵ��������
net=feedforwardnet(10);
% net=feedforwardnet(15);
% net=feedforwardnet(5);

% net=newff(input,output,[5],{'tansig','purelin'},'trainlm'); 
% net.trainParam.epochs=500;
% net.trainParam.goal=0.01;
% net.trainParam.lr=0.02;

tic
net=train(net,inputn,outputn);
time=toc;
disp(['the time is',num2str(time),'s']);

%% ����ṹ
% view(net);
% y = net(input);
% perf = perform(net,y,output)

%% ��������
% tt1=xlsread('red.xlsx','Sheet 1','B1400:B1500');
% tt2=xlsread('red.xlsx','Sheet 1','C1400:C1500');
% tt3=xlsread('red.xlsx','Sheet 1','D1400:D1500');
% tt4=xlsread('white.xlsx','Sheet 1','B1400:B1500');
% tt5=xlsread('white.xlsx','Sheet 1','C1400:C1500');
% tt6=xlsread('white.xlsx','Sheet 1','D1400:D1500');

tr1=xlsread('red.xlsx','Sheet 1','C1200:C1250');
tr2=xlsread('red.xlsx','Sheet 1','D1200:D1250');
tr3=xlsread('red.xlsx','Sheet 1','E1200:E1250');
tr4=xlsread('red.xlsx','Sheet 1','H1200:H1250');
tr5=xlsread('red.xlsx','Sheet 1','K1200:K1250');
tr6=xlsread('red.xlsx','Sheet 1','L1200:L1250');

tw1=xlsread('white.xlsx','Sheet 1','C1200:C1250');
tw2=xlsread('white.xlsx','Sheet 1','D1200:D1250');
tw3=xlsread('white.xlsx','Sheet 1','E1200:E1250');
tw4=xlsread('white.xlsx','Sheet 1','H1200:H1250');
tw5=xlsread('white.xlsx','Sheet 1','K1200:K1250');
tw6=xlsread('white.xlsx','Sheet 1','L1200:L1250');

testinput=[[tr1' tw1'];[tr2' tw2'];[tr3' tw3'];[tr4' tw4'];[tr5' tw5'];[tr6' tw6']];
[testinputn,testinputnps]=mapminmax(testinput,0,1);
ty=round(sim(net,testinputn));
%% �������ݷ���
out1=xlsread('red.xlsx','Sheet 1','A1200:A1250');
out2=xlsread('white.xlsx','Sheet 1','A1200:A1250');
outputt=[out1' out2'];
%mse=std(ty-outputt);
y=net(testinputn);
perf=perform(net,y,outputt);%������ʵû�й�һ���ٱȽϴ���
%% ���ݵķ���һ��
yy=mapminmax('reverse',y,outputnps);
perf2=perform(net,yy,outputt);