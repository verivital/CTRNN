function y = Ntanh( x )
%NTANH Exponential representation of hyperbolic tangent
a=exp(-2*x);
b=1.-a;
c=1.+a;
y=b./c;
end

