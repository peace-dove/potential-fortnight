function flag=mag(n)
a=magic(n);
suml=0;
sumr=0;
sum=0;
flag=1;tmp=0;
for i=1:n
    suml=suml+a(i,i);
end
for i=1:n
    sumr=sumr+a(i,n-i+1);
end

if suml~=sumr
    flag=0;
else
    sum=suml;
end

for i=1:n
    tmp=0;
    for j=1:n
       tmp=tmp+a(i,j);
    end
    if tmp~=sum
        flag=0;
    end
end
for i=1:n
    tmp=0;
    for j=1:n
       tmp=tmp+a(j,i);
    end
    if tmp~=sum
        flag=0;
    end
end
end
