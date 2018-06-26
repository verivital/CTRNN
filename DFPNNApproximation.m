clear
close all
format long;
%Weight Matrix for RNN
W1=[0.4684 -2.4995 0.4211 -0.2848 0.1995;...
    1.3615 0.0642 0.0413 -1.8925 -1.6608;...
    -0.8185 -0.9241 -0.0743 -0.1264 0.1484;...
    -0.3257 1.2319 -1.0997 0.2192 -0.8547;...
    -1.2444 0.4396 -0.5466 1.7342 -0.5953;];

gamma=[-0.0050; -0.2111; 0.1689; 0.0645; -0.0413];

%initial states of neuron inputs
x0=[-0.0097; -0.0065; 0.0171; -0.0097; 0.0025];

%initial time
tinit=0;
tf=20;

%Euler Simulation
N=4000;
h1=(tf-tinit)/N;
t1(1)=tinit;
xnot(1)=x0(1);
uinput(1)=NNinput(1,1,t1(1));
gs{1}=x0;
x1(1)=0;
x2(1)=0;
figure(1);
figure(2);
figure(3);

for i=1:N
    t1(i+1)=t1(i)+h1;
    uinput(i)=NNinput(1,1,t1(i));
    gs{i+1}=gs{i}+h1*NNDerivInput(gs{i},W1,gamma,uinput(i));
    xnot(i+1)=gs{i+1}(1);
    [x1dot,x2dot]=slman( x1(i),x2(i),uinput(i));
    x1(i+1)=x1(i)+h1*x1dot;
    x2(i+1)=x2(i)+h1*x2dot;
end
uinput(length(t1))=NNinput(1,1,t1(length(t1)));
figure(1);
plot(t1,xnot,'--r','LineWidth', 2');
hold on;
plot(t1,x1,'-b','LineWidth', 0.6');
ylabel('$\theta(t)$','Interpreter','latex') % x-axis label
xlabel('t') % y-axis label
title('Network and Plant output for $u(t)=\frac{\pi}{2}sin(\frac{2\pi t}{2.5})+\frac{\pi}{2}sin(\frac{2\pi t}{5.0})$ Euler','Interpreter','latex' )
legend('CTRNN','DFP')


%Simulation of CTRNN and DFP (Damped Forced Pendulum) for various driving
%functions
tinit=0;
tf=20;
N=4000;
h1=(tf-tinit)/N;
t1(1)=tinit;
xnot(1)=x0(1);
uinput(1)=NNinput(0,1,t1(1));
gs{1}=x0;
x1(1)=0;
x2(1)=0;


for i=1:N
    t1(i+1)=t1(i)+h1;
    uinput(i)=NNinput(0,1,t1(i));
    gs{i+1}=gs{i}+h1*NNDerivInput(gs{i},W1,gamma,uinput(i));
    xnot(i+1)=gs{i+1}(1);
    [x1dot,x2dot]=slman( x1(i),x2(i),uinput(i));
    x1(i+1)=x1(i)+h1*x1dot;
    x2(i+1)=x2(i)+h1*x2dot;
end
uinput(length(t1))=NNinput(0,1,t1(length(t1)));

figure(2);
plot(t1,xnot,'--r','LineWidth', 2');
hold on;
plot(t1,x1,'-b','LineWidth', 0.6');
legend('CTRNN','DFP')
ylabel('$\theta(t)$','Interpreter','latex') % x-axis label
xlabel('t') % y-axis label
title('Network and Plant output for $u(t)=\frac{\pi}{2}sin(\frac{2\pi t}{5.0})$ RK4','Interpreter','latex' )




tinit=0;
tf=20;

N=4000;
h1=(tf-tinit)/N;
t1(1)=tinit;
xnot(1)=x0(1);
uinput(1)=NNinput(1,0,t1(1));
gs{1}=x0;
x1(1)=0;
x2(1)=0;

for i=1:N
    t1(i+1)=t1(i)+h1;
    uinput(i)=NNinput(1,0,t1(i));
    gs{i+1}=gs{i}+h1*NNDerivInput(gs{i},W1,gamma,uinput(i));
    xnot(i+1)=gs{i+1}(1);
    [x1dot,x2dot]=slman( x1(i),x2(i),uinput(i));
    x1(i+1)=x1(i)+h1*x1dot;
    x2(i+1)=x2(i)+h1*x2dot;
end
figure(3);
plot(t1,xnot,'--r','LineWidth', 2');
hold on;
plot(t1,x1,'-b','LineWidth', 0.6');
uinput(length(t1))=NNinput(1,0,t1(length(t1)));
ylabel('$\theta(t)$','Interpreter','latex') % x-axis label
xlabel('t') % y-axis label
title('Network and Plant output for $u(t)=\frac{\pi}{2}sin(\frac{2\pi t}{2.5})$','Interpreter','latex' )
legend('CTRNN','DFP')
errArr=xnot-x1;

%various input constants for testing
c1=[1 0 1 0.7 0.5 -1 -0.5 -0.7 -1 0];
c2=[1 1 0 0.7 0.5 -1 -0.5 -0.7 0 -1];
%errorGauge
errDFP=0;
num=1;
figure(5);
for i1=1:length(c1)
        tinit=0;
        tf=20;
        N=40000;
        h1=(tf-tinit)/N;
        t1(1)=tinit;
        xnot(1)=x0(1);
        uinput(1)=NNinput(c1(i1),c2(i1),t1(1));
        gs{1}=x0;
        x1(1)=0;
        x2(1)=0;
        for i=1:N
            t1(i+1)=t1(i)+h1;
            uinput(i)=NNinput(c1(i1),c2(i1),t1(i));
            gs{i+1}=gs{i}+h1*NNDerivInput(gs{i},W1,gamma,uinput(i));
            xnot(i+1)=gs{i+1}(1);
            [x1dot,x2dot]=slman( x1(i),x2(i),uinput(i));
            x1(i+1)=x1(i)+h1*x1dot;
            x2(i+1)=x2(i)+h1*x2dot;
        end
        uinput(length(t1))=NNinput(c1(i1),c2(i1),t1(length(t1)));
        figure(4);
        hold on;
        xlim([0 4])
        plot(t1,xnot,':','LineWidth', 1.5');
        p1=plot(t1,x1,'-','LineWidth', 2');
        num=num+1;
        err=max(abs(xnot-x1));
        
        figure(5);
        plot(t1,abs(xnot-x1),'-','LineWidth', 1.5')
        hold on;
        
        
        if(err>errDFP)
            errDFP=err;
        end
        
        
end
figure(4);
title('Network and Plant output for $u(t)=c_1(\frac{\pi}{2})sin(\frac{2\pi t}{2.5})+c_2(\frac{\pi}{2})sin(\frac{2\pi t}{5.0})$','Interpreter','latex' )
ylabel('$\theta(t)$','Interpreter','latex') % x-axis label
xlabel('t') % y-axis label
%axis([0,20,-0.9,0.9])

figure(5);
title('Plot of DFP CTRNN Simulation Error ','Interpreter','latex' )
xlabel('t','Interpreter','latex') % y-axis label
ylabel('$|y_{nn}(t)-y_{dfp}(t)|$','Interpreter','latex') % x-axis label




