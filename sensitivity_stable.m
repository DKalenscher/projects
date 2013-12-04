%Daniel Kalenscher
%Last Updated- 12/4/2013
% NEED TO TAKE INTO ACCOUNT FREE VARIABLES

% ONLY RUNS PHASE II, NEED TO ADD PHASE I CONVERSION

% add option to determine minimum or maximum
%Should add in error checking loops on input values


%SHADOW PROFIT = profit(b1 +1) - profit.  Its the difference between the profit of the altered vs how it would have been originally for each. Can be negaive or positive)                   

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
    disp('Running Single Min/Max Algorithm');
    inc=1;
    increment=0;
end

%===================Only changes the matrics of A,b,P for the selected
%value.=====================
    if selection== 'A';
        A(rowpos,colpos)=minval;

    elseif selection == 'b';
        b(rowpos,colpos)=minval;

    elseif selection == 'P';

        P(rowpos,colpos)=minval;

    else
        
    end



%startvar = minval;
%for i=startvar:increment:maxval  COULD PROBABLY JUST USE INC DIRECTLY

count=1;  %  counters for populating end result arrays, needs to initialize outside of For loop
changeval=1;

for i=1:1:inc   

    


%Need a for loop. For(locationvar=minval; location variable
%=<maxvalue;locationvar+=increment)


% we now need to use locationvariable to be input into A,b,P instead of the
% standard inputs.  





T=totbl(A,b,P)





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
r=r(1,1);   % We reset the values of R and C to only take the first value of the minimum locations incase there are 2 or more equal numbers
c=c(1,1);

        
        
%Next I need to find the location of the row that has the lowest ratio for
%this column

%c is the value of the column with the lowest number, need to take the full
%value of that column

Lowcol=T.val(:,c);  % puts the values of column c into lowcol

colnum=size(T.val,2); % counts the number of columns in the T matrix and assigns that to colnum
rownum=size(T.val,1); % counts the number of columns in the T matrix and assigns that to colnum

Lastcol=T.val(:,colnum); % puts the values of the last column into Lastcol

ratio=Lastcol./Lowcol % divides the last col by the lowest col  WE NEED TO GET THE LARGEST NEGATIVE NUMBER NOW



%[C,I]=max(ratio(ratio<0)) %WE NEED TO GET THE LARGEST NEGATIVE NUMBER NOW

ratio(~isfinite(ratio))=0  % replaces Inf values with 0 so they don't get counted in.
ratio_max = max(ratio(ratio(1:rownum-1) < 0));

I = find(ratio==ratio_max);
I = I(1,1);  % Sets I equal to the first value of I in case there are 2 or more equal ratio values.

%[C,I]= max(ratio(ratio(1:rownum-1) < 0))  WOULD BE A BETTER SOLUTION TO THE

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

%NEED TO ALLOW USERS TO ENTER A RANGE OF VALUES FOR A,b,P AND RUN EACH
%ITERATION.

% NEED TO SET VALUES FOR X1, X2, Z for each loop run so we can plot a
% table.


%===================Only INCREMENTS the matrics of A,b,P for the selected
%value.=====================
    if selection== 'A';
        A(rowpos,colpos)=(minval+increment); 
        minval=(minval+increment);
   
    elseif selection == 'b';
        b(rowpos,colpos)=(minval+increment);
        minval=(minval+increment);
   
    elseif selection == 'P';
        P(rowpos,colpos)=(minval+increment);
        minval=(minval+increment);
   
    end
A
b
P
%==========Dynamically creates/populates X(n) values as well as
%Z=============%



Zvalues(count) = abs(T.val(rownum,colnum));


for i=1:1:colnum-1     %Loop to determine number of X values needed

    if ( all(z(1:colnum-1)) ); %If all Z values are nonzero (and therefore > 0)
        x_var_row=find(ismember(T.bas,['x', num2str(i)])); % see if X(n) value is on side or top of table
          
        if (isempty(x_var_row));   %if not on the side, it is on top and therefore 0 since Z values are > 0.
            eval(['x' num2str(i) '(' num2str(count) ') = ' num2str(0)]);
        else
            eval(['x' num2str(i) '(' num2str(count) ') = ' num2str((T.val(x_var_row,colnum)))]);  % otherwise put the number in the last col of the table directly into X(n)
        end
    end
end





%========================Original Statically created X(n) variables======
%if ( all(z(1:colnum-1)) );  % if all values in Z are above zero, there are no free variables so values for x1/x2 can be set directly
 %   x1row=find(ismember(T.bas,'x1'));
        
  %  if (isempty(x1row));  %checks to see if variable is on left side or top of matrix if on top, then x1 is 0 because all Zs are positive
 %       x1(count) = 0;  % if x1 is on top then it is 0 because we have already checked that the Z values are not 0
   % else
    %x1(count) = (T.val(x1row,colnum)); 
   % end

 %   x2row=find(ismember(T.bas,'x2'))
    
  %  if (isempty(x2row));  %checks to see if variable is on left side or top of matrix if on top, then x2 is 0 because all Zs are positive
   %     x2(count) = 0;  % if x1 is on top then it is 0 because we have already checked that the Z values are not 0
   % else
  %  x2(count) = (T.val(x2row,colnum));
   % end

%end

change_val(count) = minval;


count = count+1;

end  % END FOR LOOP
Zvalues
x1
x2

% Only necessary if there are 2 X(n) values
plot3(x1,x2,change_val)
