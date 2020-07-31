clear; clc; 
x0 = [762, 1, 0]; 
tspan = [0, 100]; 
[T, X] = ode45(@f, tspan, x0); 

figure; 
subplot(3, 1, 1) 
plot(T, X(:, 1)) 
ylabel('X_1'); 

subplot(3, 1, 2) 
plot(T, X(:, 2)) 
ylabel('X_2'); 

subplot(3, 1, 3) 
plot(T, X(:, 3)) 
ylabel('X_3'); 
xlabel('Time'); 

function fx = f(t, x) %# ok 
% ��ʼ��fx����ҪΪ������ 
fx = zeros(3, 1); % ����΢�ַ����� 
fx(1) = -0.00218.* x(1)*x(2); 
fx(2) = 0.00218*x(1)*x(2)-0.44*x(2);
fx(3) = 0.44*x(2);
end



