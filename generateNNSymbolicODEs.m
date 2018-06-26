clear
close all

%File that generates the ODEs for the NN
format long
A=[-1.20327 -0.07202 -0.93635; 1.18810 -1.50015 0.93519];
B=[1.21464 -0.10502; 0.12023 0.19387; -1.36695 0.12201];
theta=[-7.5649*(10^-5); 1.34708*(10^-4); -6.24925*(10^-6)];
tau=10^6;
tau1=-(1/tau);
W=[[zeros(2),A]; [zeros(3,2),B*A]];

%setting up initial conditions

syms x1 x2 x3 x4 x5 x0 y0 u



%ODEs for Fixed Point Attractor
q0=[x0;y0];
q1=[0.5;0.8];
s01=(B*q0)+theta;
s02=(B*q1)+theta;
%initial condition for attractor pendulum
s0=[q0; s01];
s1=[q1;s02];
%arbitrary symbolic vector
s=[x1;x2;x3;x4;x5];
sdots=[strcat("",char(x1));strcat("",char(x2));strcat("",char(x3));strcat("",char(x4));strcat("",char(x5))];
sdot=((-1/tau).*s)+W*(Ntanh(s));
ODEs={};
for i=1:length(sdot)
    dot=char(sdots(i));
    eq=' = ';
    eqn=char(sdot(i));
    ODEs{i}=strcat(dot,eq,eqn);
end

%ODEs for Forced Damped Pendulum
W1=[0.4684 -2.4995 0.4211 -0.2848 0.1995;...
    1.3615 0.0642 0.0413 -1.8925 -1.6608;...
    -0.8185 -0.9241 -0.0743 -0.1264 0.1484;...
    -0.3257 1.2319 -1.0997 0.2192 -0.8547;...
    -1.2444 0.4396 -0.5466 1.7342 -0.5953;];
gamma=[-0.0050; -0.2111; 0.1689; 0.0645; -0.0413];

%initial states of neuron inputs
x0=[-0.0097; -0.0065; 0.0171; -0.0097; 0.0025];
xnot=[x1; x2; x3; x4; x5];
sdot1=-xnot+W1*Ntanh(xnot)+gamma.*u;

%Strings of ODEs
for i=1:length(sdot)
    dot=char(sdots(i));
    eq='=';
    eqn=char(sdot1(i));
    ODEs1{i}=strcat(" ",dot," ",eq," ",eqn);
end

