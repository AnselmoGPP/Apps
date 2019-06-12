# Compute change

Input: 
Price and the payment amount, separated by a semicolon and a whitespace. 

Output: 
Must be a list of the names of the coins you have to return as change, alphabetically ordered and commma separated (except the last coin name).

If Price == Payment, return ZERO. 
If Payment << Price, return ERROR.

Example of input (Price; Payment):	15.94; 16.00

Example of output:

'PENNY': .01,
'NICKEL': .05,
'DIME': .10,
'QUARTER': .25,
'HALF DOLLAR': .50,
'ONE': 1.00,
'TWO': 2.00,
'FIVE': 5.00,
'TEN': 10.00,
'TWENTY': 20.00,
'FIFTY': 50.00,
'ONE HUNDRED': 100.00
