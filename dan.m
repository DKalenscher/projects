%CURRENT ISSUES:  IF 2 VALUES ON Z ARE THE SAME I GET AN ERROR
%                   VALUES AREN'T UPDATING INSIDE THE LOOP

%Assign values to A,b,P and build the Table to be prepared for ljx
prompt = 'Please enter initial values of A in array format: ';
A = input(prompt);

prompt = 'Please enter intial values of b in array format: ';
b = input(prompt);


prompt = 'Please enter initial values of P in array format: ';
P = input(prompt);

% ACCEPT A RANGE OF VARIABLES FOR A,b,P

prompt='Which constraint will be changing for Sensitivity Analysis? (A,b,P) or press any other key to continue: ';
selection = input(prompt,'s');

if selection== 'A';

    disp('Current value of A is: ');
    A
    
    prompt='What is the row of the variable to be changed? ';
    rowpos=input(prompt);
    
    prompt='What is the column of the variable to be changed? ';
    colpos=input(prompt);
    
    prompt='What is the minimum value of the constraint? ';
    minval=input(prompt);

    prompt='What is the maximum value of the constraint? ';
    maxval=input(prompt);

    prompt='How many increments will there be between min and max? ';
    inc=input(prompt);
    
    increment=(maxval-minval)/inc;

    

elseif selection == 'b';
    
    disp('Current value of b is: ');
    b
    
    prompt='What is the row of the variable to be changed? ';
    rowpos=input(prompt);
    
    prompt='What is the column of the variable to be changed? ';
    colpos=input(prompt);
    
    prompt='What is the minimum value of the constraint? ';
    minval=input(prompt);

    prompt='What is the maximum value of the constraint? ';
    maxval=input(prompt);

    prompt='How many increments will there be between min and max? ';
    inc=input(prompt);
    
    increment=(maxval-minval)/inc;

    

elseif selection == 'P';
    
    disp('Current value of P is: ');
    P
    
    prompt='What is the row of the variable to be changed? ';
    rowpos=input(prompt);
    
    prompt='What is the column of the variable to be changed? ';
    colpos=input(prompt);
    
    prompt='What is the minimum value of the constraint? ';
    minval=input(prompt);

    prompt='What is the maximum value of the constraint? ';
    maxval=input(prompt);

    prompt='How many increments will there be between min and max? ';
    inc=input(prompt);
    
    increment=(maxval-minval)/inc;

    
else
       
end








%startvar = minval;
%for i=startvar:increment:maxval  COULD PROBABLY JUST USE INC DIRECTLY
    
for i=1:1:inc   
    
A(rowpos,colpos)=minval;
b(rowpos,colpos)=minval;
P(rowpos,colpos)=minval;


%Need a for loop. For(locationvar=minval; location variable
%=<maxvalue;locationvar+=increment)


% we now need to use locationvariable to be input into A,b,P instead of the
% standard inputs.  





T=totbl(A,b,P);





%=================================LJX METHOD=============================%
%Find which row and column needs to be the focus of the ljx

%Assign values to z1-zn in order to figure out which column to use for ljx

colnum=size(T.val,2); % counts the number of columns in the T matrix and assigns that to colnum
rownum=size(T.val,1); % counts the number of columns in the T matrix and assigns that to colnum



while true 

Tcolumns=size(T.val,2);  % gives the number of columns in T

i = 1;  %init zcounter
while i <= Tcolumns,
  
  z(i) = T.val(4,i);   % creates an array for z so we can then check the location of the minimum
    
    i = i+1;
end



[r,c]=find(z(1:colnum-1)==min(min(z(1:colnum-1))));  % finds the row(r) and column(c) of the minimum value for the array of z we created



%Next I need to find the location of the row that has the lowest ratio for
%this column

%c is the value of the column with the lowest number, need to take the full
%value of that column

Lowcol=T.val(:,c);   % puts the values of column c into lowcol

colnum=size(T.val,2); % counts the number of columns in the T matrix and assigns that to colnum
rownum=size(T.val,1); % counts the number of columns in the T matrix and assigns that to colnum

Lastcol=T.val(:,colnum); % puts the values of the last column into Lastcol

ratio=Lastcol./Lowcol; % divides the last col by the lowest col  WE NEED TO GET THE LARGEST NEGATIVE NUMBER NOW

[C,I]=max(ratio(ratio<0));%WE NEED TO GET THE LARGEST NEGATIVE NUMBER NOW
% max(ratio(ratio(1:rownum-1) < 0))  WOULD BE A BETTER SOLUTION TO THE
% ABOVE NEED TO TEST SYNTAX LATER

%%[C,I]=min(ratio(1:rownum-1));% finds the minimum value of the ratio between positions 1 and the second to last value and assigns the positon to I

%FOR LJX LOWEST COLUMN IS c
%FOR LJX LOWEST ROW IS I

T=ljx(T,I,c)

w = 1; %resets the counter back to 1
while w <= Tcolumns,
  
  Zresult(w) = T.val(4,w);   % UPDATE LOOP CONTROL VARIABLE
    
    w = w+1;
end

if all(Zresult(1:colnum-1) >= 0);   % BREAK STATEMENT  FOR WHILE LOOP
    break;
end

end

disp('MINIMIZATION ITERATION IS COMPLETE');
A
b
P
%NEED TO ALLOW USERS TO ENTER A RANGE OF VALUES FOR A,b,P AND RUN EACH
%ITERATION.

% NEED TO SET VALUES FOR X1, X2, Z for each loop run so we can plot a
% table.
end  % END FOR LOOP

