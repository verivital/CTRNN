clear
close all
format long

%File that generates CTRNN model of Fixed Point Attractor

%Neural Network Weight Matrices
A=[-1.20327 -0.07202 -0.93635; 1.18810 -1.50015 0.93519];
B=[1.21464 -0.10502; 0.12023 0.19387; -1.36695 0.12201];
theta=[-7.5649*(10^-5); 1.34708*(10^-4); -6.24925*(10^-6)];
tau=10^6;
product=B*A;   
W=[[zeros(2),A]; [zeros(3,2),B*A]];

%Initial conditions for fixed point attractor and CTRNN
q0=[0.5;0.8];
s01=(B*q0)+theta;
s0=[q0; s01];
tau1=-(1/tau); %time constant for neurons
sdot=tau1*s0+W*sigmf(s0,[1,0]);
outputs=[sdot(1); sdot(2)];

%Matlab Plots
figure(1);
figure(2);
figure(3);
figure(4);

%initial set to test generalization of CTRNN
qxinitial=[-1 1];
qyinitial=[-1 1];

%discretize the grid using 10 steps in each dimension
numpts=10;
incrx=(qxinitial(2)-qxinitial(1))/numpts;
incry=(qyinitial(2)-qyinitial(1))/numpts;
qxinit=[qxinitial(1):incrx:qxinitial(2)];
qyinit=[qyinitial(1):incry:qyinitial(2)];

time1=0;  %initial time
time2=40; %final time 
N=400;    %number of steps used in Euler Simulation
h1=(time2-time1)/N;
tim(1)=time1;
errorGauge=0; %error evaluation for all trajectories 
for k=1:numpts+1
    for j=1:numpts+1
        %select point from initial set and simulate the trajectory
        point1=qxinit(k); 
        point2=qyinit(j);
        xpoint(1)=point1;
        ypoint(1)=point2;
        qinit=[point1;point2];
        sinit1=(B*qinit)+theta;
        sinit=[qinit;sinit1];
        
       %select the fixed point to be at the origin
        p1=0;
        p2=0;   
        %constants for fixed point attractor
        at=-0.2;
        bt=-0.3;
        for i=1:N
             [xintc,yintc]=attractor(at,bt,xpoint(i),ypoint(i),p1,p2);
             xpoint(i+1)=xpoint(i)+h1*xintc;
             ypoint(i+1)=ypoint(i)+h1*yintc;
        end
        figure(1);
        plot(xpoint,ypoint,'-.','LineWidth', 4)
        hold on;
        
        
        %Plot neuron activations to show convergence
        xsnot=sinit(1);
        ysnot=sinit(2);
        n1snot(1)=sinit(3);
        n2snot(1)=sinit(4);
        n3snot(1)=sinit(5);
        rnnx(1)=xsnot;
        rnny(1)=ysnot;
        rnns{1}=sinit;
        for i=1:N
            tim(i+1)=tim(i)+h1;
            rnns{i+1}=rnns{i}+h1*neuronDeriv(rnns{i},W);
            rnnx(i+1)=rnns{i+1}(1);
            rnny(i+1)=rnns{i+1}(2);
            n1snot(i+1)=rnns{i+1}(3);
            n2snot(i+1)=rnns{i+1}(4);
            n2snot(i+1)=rnns{i+1}(5);
        end
        
        xx1=rnnx-xpoint;
        yy1=rnny-ypoint;
        norm=sqrt(xx1.^2+yy1.^2);
        err=max(norm);
        if err>errorGauge
            errorGauge=err;
        end
        figure(4);
        plot(tim,norm,'-','LineWidth', 1.0');
        hold on;
        figure(1);
        plot(rnnx,rnny,'.k')
        figure(2);
        plot(tim,rnnx,'-');
        hold on;
        plot(tim,rnny,'-');
        plot(tim,n1snot,'-');
        plot(tim,n2snot,'-');
        plot(tim,n3snot,'-');
    end
end


%Plot single trajectory for fixed point attractor and CTRNN
figure(1);
title('CTRNN approximation of Fixed Point Attractor','Interpreter','latex' )
xlabel('$x$','Interpreter','latex');
ylabel('$y$','Interpreter','latex');
a2=0;
b2=40;
N=400;
h1=(b2-a2)/N;
t2(1)=a2;
x0=q0(1);
y0=q0(2);
bx(1)=x0;
by(1)=y0;
p1=0;
p2=0;
at=-0.2;
bt=-0.3;
for i=1:N
    t2(i+1)=t2(i)+h1;
    [xint,yint]=attractor(at,bt,bx(i),by(i),p1,p2);
    bx(i+1)=bx(i)+h1*xint;
    by(i+1)=by(i)+h1*yint;
end
figure(3);
plot(bx,by,'or')
hold on;
title('CTRNN approximation of Fixed Point Attractor from (0.5,-0.8)','Interpreter','latex' )
xlabel('$x$','Interpreter','latex');
ylabel('$y$','Interpreter','latex');
figure(2);
title('Neuron Trajectory for Multiple Trajectories','Interpreter','latex' )
xlabel('$Time(s)$','Interpreter','latex');
ylabel('Neuron Output','Interpreter','latex');

N=400;
h1=(b2-a2)/N;
t3(1)=a2;
x0=s0(1);
y0=s0(2);
gx(1)=x0;
gy(1)=y0;
gs{1}=s0;
for i=1:N
    t3(i+1)=t3(i)+h1;
    gs{i+1}=gs{i}+h1*neuronDeriv(gs{i},W);
    gx(i+1)=gs{i+1}(1);
    gy(i+1)=gs{i+1}(2);
end
figure(3);
plot(gx,gy,'-k','LineWidth', 2)
legend('FPA','CTRNN')

figure(4);
title('Plot of FPA CTRNN Simulation Error ','Interpreter','latex' )
xlabel('t','Interpreter','latex') % y-axis label
ylabel('$||y_{nn}(t)-y_{dfp}(t)||_2$','Interpreter','latex') % x-axis label
xlim([0 40])
