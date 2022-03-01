var readline = require('readline-sync');

var term1 = parseInt(readline.question("1st Number: "));
var term2 = parseInt(readline.question("2nd Number: "));
var term3 = parseInt(readline.question("3rd Number: "));
var term4 = parseInt(readline.question("4th Number: "));

var fac1 = term1 - 1;
var facAnswer = term1;
while(fac1 > 0){
    facAnswer = fac1 * facAnswer;
    fac1--;
}

console.log("Factorial of the 1st number is = " + facAnswer);

var sum = 0;
for(let i = 0; i < term2.toString().length; i++){
    sum = sum + parseInt(term2.toString().charAt(i));
}

console.log("Sum of all the digits of the 2nd number is = " + sum);

var reverse = "";
for(let i = term3.toString().length; i > -1; i--){
    reverse = reverse + term3.toString().charAt(i);
}

console.log("The reverse of the third number is = " + reverse);

var palindrome = term4.toString().length - 1;
var isPal = 1;

for(let i = 0; i < term4.toString().length; i++){
    if(term4.toString().charAt(i) != term4.toString().charAt(palindrome)){
        isPal = 0;
    }
    palindrome--;
}


if(isPal == 1){
    console.log("Is the 4th number a palindrome (True/ False)? = True");
}

if(isPal == 0){
    console.log("Is the 4th number a palindrome (True/ False)? = False");
}
