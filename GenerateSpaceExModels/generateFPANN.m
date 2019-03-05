%Vanderbilt University
%Generate Hybrid Automaton of Fixed Point Attractor
%-------------------
clear
clc;
close all

%import data structures in Hyst
javaaddpath(['/home/musaup/Documents/Tools/hyst', filesep, 'lib', filesep, 'Hyst.jar'])
import de.uni_freiburg.informatik.swt.spaceexboogieprinter.*;
import com.verivital.hyst.automaton.*;
import com.verivital.hyst.grammar.antlr.*;
import com.verivital.hyst.grammar.formula.*;
import com.verivital.hyst.importer.*;
import com.verivital.hyst.ir.*;
import com.verivital.hyst.junit.*;
import com.verivital.hyst.util.*;
import com.verivital.hyst.main.*;
import com.verivital.hyst.passes.*;
import com.verivital.hyst.printers.*;
import com.verivital.hyst.simulation.*;
import de.uni_freiburg.informatik.swt.sxhybridautomaton.*;
import de.uni_freiburg.informatik.swt.spaceexxmlprinter.*;
import de.uni_freiburg.informatik.swt.spaxeexxmlreader.*;

run generateNNSymbolicODEs.m
% generate base component
ha = com.verivital.hyst.ir.base.BaseComponent;
numLoc = 1;
numTran = 0;
var = {'x1';'x2';'x3';'x4';'x5'};
numVar = length(var);


initConditionStr=strcat(var{1}," ",'==',num2str(s1(1)));
for j=2:length(var)
    initConditionStr=strcat(initConditionStr,' & '," ",var{j},'==',num2str(s1(j)));
end
flowstr=ODEs{1};
for i=2:(length(ODEs))
    flowstr=strcat(flowstr," ",'&'," ",ODEs{i});
end
% add invariants and flows for the single mode
flow={
    flowstr;
};

invariant={""};
%add variables to hybrid automaton
for i_var = 1:numVar
    ha.variables.add(java.lang.String(var(i_var)));
end

locName ={'CTmode1'};
for i_loc = 1:numLoc
    loc = ha.createMode(locName{i_loc},invariant{i_loc},flow{i_loc});
    locations(i_loc) = loc;
end


initialLoc='CTmode1';
initialExpression =initConditionStr;

%generate configuration
config = com.verivital.hyst.ir.Configuration(ha);
config.init.put(initialLoc,com.verivital.hyst.grammar.formula.FormulaParser.parseInitialForbidden(initialExpression));

configValues = de.uni_freiburg.informatik.swt.sxhybridautomaton.SpaceExConfigValues;
configValues.scenario = 'supp';
configValues.outputFormat = 'GEN';

vars = ha.variables.toArray();
if numVar > 1
      jsa = javaArray('java.lang.String', numVar);
    for i = 1: ha.variables.size()
          jsa(i) = java.lang.String(vars(i));
    end 
end 

file_name ='FPACTRNN';
config.settings.plotVariableNames = jsa;
config.settings.spaceExConfig = configValues;
printer = com.verivital.hyst.printers.SpaceExPrinter;
printer.setBaseName(file_name);
printer.setConfig(config);
printer.setBaseComponent(ha);
config.DO_VALIDATION = false;
doc = printer.convert(ha);


% Save the SpaceEx document and the configuration file 
xml_printer = de.uni_freiburg.informatik.swt.spaceexxmlprinter.SpaceExXMLPrinter(doc);
xml_printer.getCFGString(false);
fileID = fopen([file_name,'.cfg'],'w');
fprintf(fileID,char(xml_printer.getCFGString(false)));
fclose(fileID);

fileID = fopen([file_name,'.xml'],'w');
fprintf(fileID,char(xml_printer.stringXML()));
fclose(fileID);
