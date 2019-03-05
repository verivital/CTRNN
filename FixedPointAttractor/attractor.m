function [xo,yo] = attractor( a,b,x,y,p1,p2)
%Fixed point attractor ODE
xo=a*(x-p1);
yo=b*(y-p2);
end

