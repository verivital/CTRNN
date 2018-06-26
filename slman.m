function [ x1dot,x2dot ] = slman( x1,x2,u )
%SLMAN Summary of this function goes here
%   Detailed explanation goes here
x1dot=x2;
x2dot=-9.8*sin(x1)-0.5*x2+0.5*u;
end

