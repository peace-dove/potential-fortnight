clc
clear

% p=[74.3 78.8 68.8 78.0 70.4 80.5 80.5 69.7 71.2 73.5 ...
%    79.5 75.6 75.0 78.8 72.0 72.0 72.0 74.3 71.2 72.0 ...
%    75.0 73.5 78.8 74.3 75.8 65.0 74.3 71.2 69.7 68.0 ...
%    73.5 75.0 72.0 64.3 75.8 80.3 69.7 74.3 73.5 73.5 ...
%    75.8 75.8 68.8 76.5 70.4 71.2 81.2 75.0 70.4 68.0]
% Mean=mean(p)
% Variance=var(p)
% StdDeviation=std(p)
% Range=range(p)
% 
% s=StdDeviation/Mean
% pian_du=skewness(p)
% feng_du=kurtosis(p)

% x= [140, 137, 136, 140, 145, 148, 140, 135, 144, 141]
% y =[135, 118, 115, 140, 128, 131, 130, 115, 131, 125]
p=[220 188 162 230 145 160 238 188 247 113 ...
126 245 164 231 256 183 190 158 224 175]
Mean=mean(p)
StdDeviation=std(p)
t=(Mean-225)/(StdDeviation/sqrt(20))