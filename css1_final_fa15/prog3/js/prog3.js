//Noe Lomeli
//December 17, 2015
//Prog 3

function cout(str){
	document.write(str);
}

function countdown(num){
	while(num > 0){
		cout(num + " days of Christmas");
		cout("<br>");
		num--;
	}
	cout("Christmas is here!!");
}

var days =12;
countdown(days);