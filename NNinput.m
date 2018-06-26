function [ut] = NNinput(c1,c2, t )
%Sinusoidal driving function for CTRNN
ut=c1*((pi/2)*sin((2*pi.*t)/2.5))+c2*((pi/2)*sin((2*pi.*t)/5.0));
end

