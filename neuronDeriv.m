function sdot = neuronDeriv(s,W)
tau1=10^6;
sdot=((-1/tau1).*s)+W*(Ntanh(s));%(W*sigmf(s,[1,0]));
end

