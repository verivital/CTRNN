function xn=NNDerivInput(x0,W,gamma,u)
%CTRNN ODE for Damped Forced Pendulum
xn=-x0+W*Ntanh(x0)+gamma.*u;
end

